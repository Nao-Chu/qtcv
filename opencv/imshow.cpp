#include "imshow.h"
#include "hsvsegmentation.h"
#include "morph.h"
#include "ui_imshow.h"
#include <QImage>
#include <QDebug>
#include <QFileDialog>
#include <QKeyEvent>

Imshow::Imshow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Imshow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    hsv = new HsvSegmentation;
    morph = new Morph;
    thresh = new Threshold;
    bluer = new Blue;
    tcpsocket = new QTcpSocket(this);
    hsv_model = false;
    click = false;
    hsvvalue = false;
    open_rect = false;
    draw_maxRectangle = false;
    draw_minRectangle = false;
    draw_center = false;
    draw_ellipse = false;
    draw_convexHull = false;
    houghmodel = 0;
    basize = 0;
    imshow();
    hsvSegmentation();
    automatic_threshold();
    morph_oper();
    threshold_oper();
    blue_oper();
    hough_oper();
}

Imshow::~Imshow()
{
    delete ui;
    timer->stop();
    capture.release();
}

void Imshow::debug(int value)
{
    qDebug("a",value);
}

/*
 * **************** *
 *                  *
 *  imshow connect  *
 *                  *
 * **************** *
 */
void Imshow::imshow()
{
    capture.open(0);
    timer->start(1);
    connect(ui->Open_Creame,SIGNAL(triggered()),this,SLOT(OpenCreame()));
    connect(ui->Open_Video,SIGNAL(triggered()),this,SLOT(OpenVideo()));
    connect(ui->Open_Photo,SIGNAL(triggered()),this,SLOT(OpenPhoto()));
    connect(ui->Format,SIGNAL(clicked()),this,SLOT(TransformFormat()));
    connect(timer,SIGNAL(timeout()),this,SLOT(importFrame()));
    connect(ui->actionRectangle,SIGNAL(triggered()),this,SLOT(maxRectangle()));
    connect(ui->actionMin_rectangle,SIGNAL(triggered()),this,SLOT(minRectangle()));
    connect(ui->actionCenter,SIGNAL(triggered()),this,SLOT(Center()));
    connect(ui->actionEllipse,SIGNAL(triggered()),this,SLOT(Ellipse()));
    connect(ui->actionConvexHull,SIGNAL(triggered()),this,SLOT(ConvexHull()));
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(closeRect()));
    connect(tcpsocket,&QTcpSocket::connected,
            [=]()
            {
                ui->connect->setStyleSheet("background-color: rgb(175,238,238)");
                connect(tcpsocket,&QTcpSocket::readyRead,[=]()
                {ReadMyData();});
            });

}

void Imshow::importFrame()
{
    if (capture.isOpened())
    {
        capture >> frame;
    }
    if (frame.data)
    {
        frame_format(model);
        if (click)
            circle(frame_clone,Point(20,20),8,Scalar(255,0,0),-1);
        bluer->blue_operation(frame_clone);
        acquire_point_hsv(frame_clone);
        auto_acquire_hsv_value(hsvvalue,frame_clone);
        hsv_model_operation(hsv_model,frame_clone); 
        srcQImage = srcQImage.scaled(ui->label->width(),ui->label->height());
        ui->label->setPixmap(QPixmap::fromImage(srcQImage));
        ui->label->show();
    }
}

void Imshow::OpenCreame()
{
    capture.open(0);
    qDebug("reading Creame");
    timer->start(1);
}

void Imshow::OpenVideo()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../",
                          "video(*.avi);;all(*.*)");
    capture.open(path.toLatin1().data());
    qDebug("reading Video");
    timer->start(1);
}

void Imshow::OpenPhoto()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../",
                          ".jpg(*.jpg*);;.png(*.png*);;all(*.*)");
    qDebug() << path;
    frame = cv::imread(path.toLatin1().data());
    qDebug("reading Photo");
}

/*
 * change qmage format
 * rgb or bgr
 */
void Imshow::qmage_format(Mat frame,int model)
{
    switch(model)
    {
        case 0:
            cvtColor(frame,frame,COLOR_RGB2BGR);
            srcQImage = QImage((uchar*)(frame.data),
                    frame.cols,frame.rows,QImage::Format_RGB888);
            break;

        case 1:
            cvtColor(frame,frame,COLOR_RGB2BGR);
            srcQImage = QImage((uchar*)(frame.data),
                    frame.cols,frame.rows,QImage::Format_RGB888);
            break;

        case 2:
            srcQImage = QImage((uchar*)(frame.data),
                    frame.cols,frame.rows,QImage::Format_RGB888);
            srcQImage = srcQImage.rgbSwapped();
            break;

        case 3:
            srcQImage = QImage((uchar*)(frame.data),
                    frame.cols,frame.rows,QImage::Format_RGB888);
            srcQImage = srcQImage.rgbSwapped();
            break;

        default:
            break;
    }

}

/*
 * change frame format
 * rgb 0 and 180
 * bgr 0 and 180
 */
void Imshow::frame_format(int model)
{
    switch(model)
    {
        case 0:
            frame_clone = frame.clone();
            break;

        case 1:
            po = Point2f(frame.cols/2,frame.rows/2);
            rot_mat = getRotationMatrix2D(po,180,1.0);
            warpAffine(frame,frame_clone,rot_mat,frame.size());
            break;

        case 2:
            cvtColor(frame,frame_clone,COLOR_BGR2RGB);
            break;

        case 3:
            po = Point2f(frame.cols/2,frame.rows/2);
            rot_mat = getRotationMatrix2D(po,180,1.0);
            warpAffine(frame,frame_clone,rot_mat,frame.size());
            cvtColor(frame_clone,frame_clone,COLOR_BGR2RGB);
            break;

        default:
            break;
    }
}

/*
 * if open hsv_model
 * will draw blue point
 * however open hsv model
 * will run qmage_format(frame,model)
 * and if open morph_operation
 * hsv_frame will changed
 */
void Imshow::hsv_model_operation(bool ifhsv,Mat frame)
{
    Mat frame_clone = frame.clone();
    cv::resize(frame_clone,frame_clone,Size(320,240));
    Mat frame_draw;
    if(ifhsv)
    {
        Mat hsv_frame = frame_clone.clone();
        cvtColor(hsv_frame,hsv_frame,COLOR_BGR2HSV);
        inRange(hsv_frame,Scalar(hsv->hsv[0],hsv->hsv[2],hsv->hsv[4]),
                Scalar(hsv->hsv[1],hsv->hsv[3],hsv->hsv[5]),hsv_frame);
        if (morph->openMorph)
            morph->morph_operation(morph->MorphFormat,hsv_frame);
        frame_draw = morph->morph_frame.clone();
    }
    else if(bluer->ifcanny)
    {
        frame_draw = frame_clone.clone();
        bluer->canny_operation(frame_draw);
        morph->morph_frame = frame_draw.clone();
    }
    else
    {
        Mat binary_clone = thresh->Mythreshold(frame_clone);
        if (!binary_clone.empty())
        {
            if (morph->openMorph)
                morph->morph_operation(morph->MorphFormat,binary_clone);
            frame_draw = morph->morph_frame.clone();
        }
    }
    if (!frame_draw.empty())
    {
        for (int i = 0; i < frame_clone.rows; i++)
        {
            uchar* draw = frame_draw.ptr<uchar>(i);
            for (int j = 0; j < frame_clone.cols; j++)
            {
                if (draw[j] > 0)
                {
                    uchar* data = frame_clone.ptr<uchar>(i,j);
                    data[0] = 255;
                    data[1] = 0;
                    data[2] = 0;
                }
            }
        }
    }
    if (ifhough)
    {
        Mat frame_hough = morph->morph_frame.clone();
        vector<Vec2f> lines;
        vector<Vec4i> linesp;
        vector<Vec3f> circles;
        Scalar color = Scalar(0,0,255);
        size_t i;
        Point pt1,pt2,center;
        switch(houghmodel)
        {
        case 1:
            HoughLines(frame_hough,lines,1,CV_PI/180,100,0,0);
            for (i = 0; i < lines.size(); i++)
            {
                float rho = lines[i][0];
                float theta = lines[i][1];
                double a = cos(theta),b = sin(theta);
                double x0 = a*rho, y0 = b*rho;
                pt1.x = cvRound(x0 + 1000*(-b));
                pt1.y = cvRound(y0 + 1000*(a));
                pt2.x = cvRound(x0 - 1000*(-b));
                pt2.y = cvRound(y0 - 1000*(a));
                line(frame_clone,pt1,pt2,color,1,LINE_AA);
            }
            break;

        case 2:
            HoughLinesP(frame_hough,linesp,1,CV_PI/180,80,30,10);
            for (i = 0; i < linesp.size(); i++)
                line(frame_clone,Point(linesp[i][0],linesp[i][1]),
                     Point(linesp[i][2],linesp[i][3]),color,1,8);
            break;

        case 3:
            Mat frame_gray = frame_clone.clone();
            cvtColor(frame_gray,frame_gray,COLOR_BGR2GRAY);
            int dp = 2;
            int minDist = 10;
            int min_radius = 20;
            int max_radius = 100;
            HoughCircles(frame_gray,circles,HOUGH_GRADIENT,dp,minDist,
                         100,100,min_radius,max_radius);
            for(i = 0; i < circles.size(); i++)
            {
                int x = cvRound(circles[i][0]);
                int y = cvRound(circles[i][1]);
                center = Point(x,y);
                int radius = cvRound(circles[i][2]);
                circle(frame_clone,center,3,Scalar(0,255,0),-1,8,0);
                circle(frame_clone,center,radius,color,3,8,0);
            }
            break;
        }

    }
    rect(frame_clone);
    //cv::imshow("2",frame_clone);
    cv::waitKey(1);
    qmage_format(frame_clone,model);
}

/*
 *  model will for in [0,4)
 */
void Imshow::TransformFormat()
{
    model++;
    if (model == 4)
        model = 0;
    qDebug() << "model: " << model;
}

void Imshow::maxRectangle()
{
    open_rect = true;
    (draw_maxRectangle == false) ?
     draw_maxRectangle = true : draw_maxRectangle = false;
}

void Imshow::minRectangle()
{
    open_rect = true;
    (draw_minRectangle == false) ?
     draw_minRectangle = true : draw_minRectangle = false;
}

void Imshow::Center()
{
    open_rect = true;
    (draw_center == false) ? draw_center = true : draw_center = false;
}

void Imshow::Ellipse()
{
    open_rect = true;
    (draw_ellipse == false) ? draw_ellipse = true : draw_ellipse = false;
}

void Imshow::ConvexHull()
{
    open_rect = true;
    (draw_convexHull == false) ? draw_convexHull = true : draw_convexHull = false;
}

void Imshow::closeRect()
{
    open_rect = false;
    draw_maxRectangle = false;
    draw_minRectangle = false;
    draw_center = false;
    draw_ellipse = false;
    draw_convexHull = false;
}

void Imshow::rect(Mat& frame_clone)
{
    if (open_rect)
    {
        Mat src;
        if (morph->morph_frame.empty()) return;
        src = morph->morph_frame.clone();
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        cv::findContours(src,contours,hierarchy,RETR_EXTERNAL,
                         CHAIN_APPROX_SIMPLE,Point());
        for (size_t t = 0; t < contours.size(); t++)
        {
            double area = contourArea(contours[t]);
            if (area < 50 || area > 320*240) continue;
            Rect rect = boundingRect(contours[t]);
            RotatedRect rrt = minAreaRect(contours[t]);
            if(draw_maxRectangle)
                rectangle(frame_clone,rect,Scalar(0,0,255),1,8,0);
            if (draw_minRectangle)
            {
                Point2f pts[4];
                rrt.points(pts);
                for (int i = 0; i < 4; i++)
                {
                    line(frame_clone,pts[i%4],pts[(i+1)%4],Scalar(0,255,0),2,8,0);
                }
            }
            if (draw_center)
            {
                Point2f cpt = rrt.center;
                circle(frame_clone,cpt,2,Scalar(255,0,0),2,8,0);
            }
            if (draw_ellipse)
            {
                RotatedRect rrt1 = fitEllipse(contours[t]);
                ellipse(frame_clone,rrt1,Scalar(100,233,255),2,8);
            }
            if (draw_convexHull)
            {
                vector<Point> hull;
                convexHull(contours[t],hull);
                int len = hull.size();
                for (int i = 0; i < len; i++)
                {
                    line(frame_clone,hull[i%len],hull[(i+1)%len],
                            Scalar(140,160,177),2,8,0);
                }
            }
        }
    }
}
/*
 * ************************** *
 *                            *
 *  hsv Segmentation connect  *
 *                            *
 * ************************** *
 */
void Imshow::hsvSegmentation()
{
    connect(ui->switch_hsv,SIGNAL(clicked()),this,SLOT(switch_hsv()));
    connect(ui->h_min,SIGNAL(valueChanged(int)),this,SLOT(acquire_hmin(int)));
    connect(ui->h_max,SIGNAL(valueChanged(int)),this,SLOT(acquire_hmax(int)));
    connect(ui->s_min,SIGNAL(valueChanged(int)),this,SLOT(acquire_smin(int)));
    connect(ui->s_max,SIGNAL(valueChanged(int)),this,SLOT(acquire_smax(int)));
    connect(ui->v_min,SIGNAL(valueChanged(int)),this,SLOT(acquire_vmin(int)));
    connect(ui->v_max,SIGNAL(valueChanged(int)),this,SLOT(acquire_vmax(int)));

    connect(ui->hmin,SIGNAL(valueChanged(int)),this,SLOT(spinbox_hmin(int)));
    connect(ui->hmax,SIGNAL(valueChanged(int)),this,SLOT(spinbox_hmax(int)));
    connect(ui->smin,SIGNAL(valueChanged(int)),this,SLOT(spinbox_smin(int)));
    connect(ui->smax,SIGNAL(valueChanged(int)),this,SLOT(spinbox_smax(int)));
    connect(ui->vmin,SIGNAL(valueChanged(int)),this,SLOT(spinbox_vmin(int)));
    connect(ui->vmax,SIGNAL(valueChanged(int)),this,SLOT(spinbox_vmax(int)));

}


/*
 * open or close hsv_model;
 */
void Imshow::switch_hsv()
{
    (hsv_model == false) ? hsv_model = true : hsv_model = false;
    if (hsvvalue && hsv_model)
        hsvvalue = false;
}

/*
 * fill in
 */
void Imshow::acquire_hmin(int value)
{
    ui->hmin->setValue(value);
    hsv->acquire_hmin(value);
}

void Imshow::acquire_hmax(int value)
{
    ui->hmax->setValue(value);
    hsv->acquire_hmax(value);
}

void Imshow::acquire_smin(int value)
{
    ui->smin->setValue(value);
    hsv->acquire_smin(value);
}

void Imshow::acquire_smax(int value)
{
    ui->smax->setValue(value);
    hsv->acquire_smax(value);
}

void Imshow::acquire_vmin(int value)
{
    ui->vmin->setValue(value);
    hsv->acquire_vmin(value);
}

void Imshow::acquire_vmax(int value)
{
    ui->vmax->setValue(value);
    hsv->acquire_vmax(value);
}

/*
 * slide
 */
void Imshow::spinbox_hmin(int value)
{
    ui->h_min->setValue(value);
    hsv->spinbox_hmin(value);
}

void Imshow::spinbox_hmax(int value)
{
    ui->h_max->setValue(value);
    hsv->spinbox_hmax(value);
}

void Imshow::spinbox_smin(int value)
{
    ui->s_min->setValue(value);
    hsv->spinbox_smin(value);
}

void Imshow::spinbox_smax(int value)
{
    ui->s_max->setValue(value);
    hsv->spinbox_smax(value);
}

void Imshow::spinbox_vmin(int value)
{
    ui->v_min->setValue(value);
    hsv->spinbox_vmin(value);
}

void Imshow::spinbox_vmax(int value)
{
    ui->v_max->setValue(value);
    hsv->spinbox_vmax(value);
}

/*
 * ***************************** *
 *                               *
 *  automatic threshold connect  *
 *                               *
 * ***************************** *
 */
void Imshow::automatic_threshold()
{
    connect(ui->coordinates_show,SIGNAL(stateChanged(int)),this,SLOT(switch_value(int)));
    connect(ui->x_point,SIGNAL(valueChanged(int)),this,SLOT(set_pointx(int)));
    connect(ui->y_point,SIGNAL(valueChanged(int)),this,SLOT(set_pointy(int)));
    connect(ui->automatic_threshold,SIGNAL(clicked()),this,SLOT(switch_hsvvalue()));
}

void Imshow::switch_value(int value)
{
    value ? click = true : click = false;
}

void Imshow::mousePressEvent(QMouseEvent *ev)
{
    int col = ui->label->width();
    int row = ui->label->height();
    int i = ev->x();
    int j = ev->y();
    int error_x = -4;
    int error_y = 33;
    int x = i-error_x;
    int y = j-error_y;
    if (x > col) x = col - 1;
    if (y > row) y = row - 1;
    ui->x_point->setValue(x);
    ui->y_point->setValue(y);
}

void Imshow::set_pointx(int value)
{
    hsv->targetpoint.x = value;
    qDebug() << "x:" << hsv->targetpoint.x;
}

void Imshow::set_pointy(int value)
{
    hsv->targetpoint.y = value;
    qDebug() << "y:" << hsv->targetpoint.y;
}

/*
 * open or close hsvvalue;
 */
void Imshow::switch_hsvvalue()
{
    hsvvalue == false ? hsvvalue = true : hsvvalue = false;
    if (hsvvalue && hsv_model)
        hsv_model = false;
}

void Imshow::set_hsv_value()
{
    ui->hmin->setValue(hsv->hsv[0]);
    ui->hmax->setValue(hsv->hsv[1]);
    ui->smin->setValue(hsv->hsv[2]);
    ui->smax->setValue(hsv->hsv[3]);
    ui->vmin->setValue(hsv->hsv[4]);
    ui->vmax->setValue(hsv->hsv[5]);

    ui->h_min->setValue(hsv->hsv[0]);
    ui->h_max->setValue(hsv->hsv[1]);
    ui->s_min->setValue(hsv->hsv[2]);
    ui->s_max->setValue(hsv->hsv[3]);
    ui->v_min->setValue(hsv->hsv[4]);
    ui->v_max->setValue(hsv->hsv[5]);
}

void Imshow::auto_acquire_hsv_value(bool hsvvalue,Mat frame)
{
    if (hsvvalue)
    {
        hsv->acquire_threshlod(frame,ui->label->width(),ui->label->height());
        set_hsv_value();
    }
}

void Imshow::acquire_point_hsv(Mat frame)
{
    int col = ui->label->width();
    int row = ui->label->height();
    Mat frame_clone = frame;
    cv::resize(frame_clone,frame_clone,Size(col,row));
    Mat frame_point;
    int x = hsv->targetpoint.x;
    int y = hsv->targetpoint.y;
    cv::cvtColor(frame_clone,frame_point,COLOR_BGR2HSV);
    int h = static_cast<int>(frame_point.at<Vec3b>(y,x)[0]);
    int s = static_cast<int>(frame_point.at<Vec3b>(y,x)[1]);
    int v = static_cast<int>(frame_point.at<Vec3b>(y,x)[2]);
    ui->h_value->setText(QString("%1").arg(h));
    ui->s_value->setText(QString("%1").arg(s));
    ui->v_value->setText(QString("%1").arg(v));
}

/*
 * *************** *
 *                 *
 *  Morph connect  *
 *                 *
 * *************** *
 */
void Imshow::morph_oper()
{
    connect(ui->reset,SIGNAL(clicked()),this,SLOT(switch_reset()));
    connect(ui->dilate,SIGNAL(clicked()),this,SLOT(switch_dilate()));
    connect(ui->erode,SIGNAL(clicked()),this,SLOT(switch_erode()));
    connect(ui->open,SIGNAL(clicked()),this,SLOT(switch_open()));
    connect(ui->close,SIGNAL(clicked()),this,SLOT(switch_close()));
    connect(ui->tophat,SIGNAL(clicked()),this,SLOT(switch_tophat()));
    connect(ui->blackhat,SIGNAL(clicked()),this,SLOT(switch_blackhat()));
    connect(ui->a,SIGNAL(valueChanged(int)),this,SLOT(acquire_sizea(int)));
    connect(ui->b,SIGNAL(valueChanged(int)),this,SLOT(acquire_sizeb(int)));
}

void Imshow::switch_reset()
{
    morph->openMorph = true;
    morph->MorphFormat = 0;
}

void Imshow::switch_dilate()
{
    morph->openMorph = true;
    morph->MorphFormat = 1;
}

void Imshow::switch_erode()
{
    morph->openMorph = true;
    morph->MorphFormat = 2;
}

void Imshow::switch_open()
{
    morph->openMorph = true;
    morph->MorphFormat = 3;
}

void Imshow::switch_close()
{
    morph->openMorph = true;
    morph->MorphFormat = 4;
}

void Imshow::switch_tophat()
{
    morph->openMorph = true;
    morph->MorphFormat = 5;
}

void Imshow::switch_blackhat()
{
    morph->openMorph = true;
    morph->MorphFormat = 6;
}

void Imshow::acquire_sizea(int value)
{
    morph->size_a = value;
}

void Imshow::acquire_sizeb(int value)
{
    morph->size_b = value;
}

/*
 * ******************* *
 *                     *
 *  Threshold connect  *
 *                     *
 * ******************* *
 */
void Imshow::threshold_oper()
{
    connect(ui->actionBINARY,SIGNAL(triggered()),this,SLOT(binary()));
    connect(ui->actionBINARY_INV,SIGNAL(triggered()),this,SLOT(binary_inv()));
    connect(ui->actionTRUNC,SIGNAL(triggered()),this,SLOT(truncs()));
    connect(ui->actionTOZERO,SIGNAL(triggered()),this,SLOT(tozero()));
    connect(ui->actionTOZERO_INV,SIGNAL(triggered()),this,SLOT(tozero_inv()));
    connect(ui->actionOTSU,SIGNAL(triggered()),this,SLOT(otsu()));
    connect(ui->actionTRIANGLE,SIGNAL(triggered()),this,SLOT(triangle()));
    connect(ui->actionGAUSSIAN_C,SIGNAL(triggered()),this,SLOT(gaussian_c()));
    connect(ui->actionMEAN_C,SIGNAL(triggered()),this,SLOT(mean_c()));
    connect(ui->threshold_a,SIGNAL(valueChanged(int)),this,SLOT(threshold_a(int)));
    connect(ui->threshold_b,SIGNAL(valueChanged(int)),this,SLOT(threshold_b(int)));
    connect(ui->Slider_thresha,SIGNAL(valueChanged(int)),this,SLOT(slider_thresha(int)));
    connect(ui->Slider_threshb,SIGNAL(valueChanged(int)),this,SLOT(slider_threshb(int)));
}

void Imshow::binary()
{
    strcmp(thresh->base_threshold.c_str(),"THRESH_BINARY") == 0 ?
    thresh->base_threshold = "NULL" :
    thresh->base_threshold = "THRESH_BINARY";
    thresh->auto_threshold = "NULL";
}

void Imshow::binary_inv()
{
    strcmp(thresh->base_threshold.c_str(),"THRESH_BINARY_INV") == 0 ?
    thresh->base_threshold = "NULL" :
    thresh->base_threshold = "THRESH_BINARY_INV";
    thresh->auto_threshold = "NULL";
}

void Imshow::truncs()
{
    strcmp(thresh->base_threshold.c_str(),"THRESH_TRUNC") == 0 ?
    thresh->base_threshold = "NULL" :
    thresh->base_threshold = "THRESH_TRUNC";
    thresh->auto_threshold = "NULL";
}

void Imshow::tozero()
{
    strcmp(thresh->base_threshold.c_str(),"THRESH_TOZERO") == 0 ?
    thresh->base_threshold = "NULL" :
    thresh->base_threshold = "THRESH_TOZERO";
    thresh->auto_threshold = "NULL";
}

void Imshow::tozero_inv()
{
    strcmp(thresh->base_threshold.c_str(),"THRESH_TOZERO_INV") == 0 ?
    thresh->base_threshold = "NULL" :
    thresh->base_threshold = "THRESH_TOZERO_INV";
    thresh->auto_threshold = "NULL";
}

void Imshow::otsu()
{
    strcmp(thresh->LookFor_threshold.c_str(),"THRESH_OTSU") == 0 ?
    thresh->LookFor_threshold = "NULL" :
    thresh->LookFor_threshold = "THRESH_OTSU";
    thresh->auto_threshold = "NULL";
}

void Imshow::triangle()
{
    strcmp(thresh->LookFor_threshold.c_str(),"THRESH_TRIANGLE") == 0 ?
    thresh->LookFor_threshold = "NULL" :
    thresh->LookFor_threshold = "THRESH_TRIANGLE";
    thresh->auto_threshold = "NULL";
}

void Imshow::gaussian_c()
{
    strcmp(thresh->auto_threshold.c_str(),"GAUSSIAN_C") == 0 ?
    thresh->auto_threshold = "NULL" :
    thresh->auto_threshold = "GAUSSIAN_C";
    thresh->base_threshold = "NULL";
    thresh->LookFor_threshold = "NULL";
}

void Imshow::mean_c()
{
    strcmp(thresh->auto_threshold.c_str(),"MEAN_C") == 0 ?
    thresh->auto_threshold = "NULL" :
    thresh->auto_threshold = "MEAN_C";
    thresh->base_threshold = "NULL";
    thresh->LookFor_threshold = "NULL";
}

void Imshow::threshold_a(int value)
{
    ui->Slider_thresha->setValue(value);
    thresh->min_a = value;
}

void Imshow::threshold_b(int value)
{
    ui->Slider_threshb->setValue(value);
    thresh->max_b = value;
}

void Imshow::slider_thresha(int value)
{
    ui->threshold_a->setValue(value);
    thresh->min_a = value;
}

void Imshow::slider_threshb(int value)
{
    ui->threshold_b->setValue(value);
    thresh->max_b = value;
}

/*
 * ************** *
 *                *
 *  Blue connect  *
 *                *
 * ************** *
 */
void Imshow::blue_oper()
{
    connect(ui->actionBlur,SIGNAL(triggered()),this,SLOT(Blur()));
    connect(ui->actionGaussian,SIGNAL(triggered()),this,SLOT(Gaussian()));
    connect(ui->actionMedian,SIGNAL(triggered()),this,SLOT(Median()));
    connect(ui->actionBilateral,SIGNAL(triggered()),this,SLOT(Bilateral()));
    connect(ui->actionMeanShift,SIGNAL(triggered()),this,SLOT(Mean()));
    connect(ui->actionEdgePreservingFilter,SIGNAL(triggered()),this,SLOT(Edge()));
    connect(ui->blue_size,SIGNAL(valueChanged(int)),this,SLOT(acquire_bulesize(int)));
    connect(ui->Gaussian_x,SIGNAL(valueChanged(int)),this,SLOT(acquire_gausizex(int)));
    connect(ui->Gaussian_y,SIGNAL(valueChanged(int)),this,SLOT(acquire_gausizey(int)));
    connect(ui->Canny,SIGNAL(clicked()),this,SLOT(switch_canny()));
}

void Imshow::Blur()
{
    bluer->BlueFormat == 0 ? bluer->BlueFormat = -1 : bluer->BlueFormat = 0;
}

void Imshow::Gaussian()
{
    bluer->BlueFormat == 1 ? bluer->BlueFormat = -1 : bluer->BlueFormat = 1;
}

void Imshow::Median()
{
    bluer->BlueFormat == 2 ? bluer->BlueFormat = -1 : bluer->BlueFormat = 2;
}

void Imshow::Bilateral()
{
    bluer->BlueFormat == 3 ? bluer->BlueFormat = -1 : bluer->BlueFormat = 3;
}

void Imshow::Mean()
{
    bluer->BlueFormat == 4 ? bluer->BlueFormat = -1 : bluer->BlueFormat = 4;
}

void Imshow::Edge()
{
    bluer->BlueFormat == 5 ? bluer->BlueFormat = -1 : bluer->BlueFormat = 5;
}

void Imshow::acquire_bulesize(int value)
{
    bluer->size_blue = value;
}

void Imshow::acquire_gausizex(int value)
{
    bluer->size_gaussian_x = value;
}

void Imshow::acquire_gausizey(int value)
{
    bluer->size_gaussian_y = value;
}

void Imshow::switch_canny()
{
    bluer->ifcanny ? bluer->ifcanny = false : bluer->ifcanny = true;
}

/*
 * *************** *
 *                 *
 *  Hough connect  *
 *                 *
 * *************** *
 */
void Imshow::hough_oper()
{
    connect(ui->actionLines,SIGNAL(triggered()),this,SLOT(lines()));
    connect(ui->actionLinesp,SIGNAL(triggered()),this,SLOT(linesp()));
    connect(ui->actionCircles,SIGNAL(triggered()),this,SLOT(circles()));
}

void Imshow::lines()
{
    ifhough = true;
    if (houghmodel == 1)
        ifhough = false;
    else
        houghmodel = 1;
}

void Imshow::linesp()
{
    ifhough = true;
    if (houghmodel == 2)
        ifhough = false;
    else
        houghmodel = 2;
}

void Imshow::circles()
{
    ifhough = true;
    if (houghmodel == 3)
        ifhough = false;
    else
        houghmodel = 3;
}

void Imshow::on_connect_clicked()
{
    QString ip = ui->lineEditIp->text();
    qint16 port = 8888;
    tcpsocket->abort();
    tcpsocket->connectToHost(QHostAddress(ip),port);
}

void Imshow::ReadMyData()
{
    QByteArray message;
    QDataStream in(tcpsocket);
    in.setVersion(QDataStream::Qt_5_0);
    if(basize == 0)
    {
        if(tcpsocket->bytesAvailable()<(int)sizeof(quint64))
        {
            return;
        }
        in >> basize;
    }
    if (tcpsocket->bytesAvailable()<basize)
    {
        return;
    }
    in >> message;
    acquireImage(message);
}

void Imshow::acquireImage(QByteArray ba)
{
    QString ss = QString::fromLatin1(ba.data(),ba.size());
    QByteArray rc;
    rc = QByteArray::fromBase64(ss.toLatin1());
    QByteArray rdc = qUncompress(rc);
    QImage image;
    image.loadFromData(rdc);
    image.Format_RGB888;
    Mat acimage = cv::Mat(image.height(), image.width(), CV_8UC4,
            (void*)image.constBits(), image.bytesPerLine());
    frame = acimage.clone();
}
