#ifndef IMSHOW_H
#define IMSHOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QTcpSocket>
#include <QTcpServer>
#include "hsvsegmentation.h"
#include "morph.h"
#include "threshold.h"
#include "blue.h"

using namespace cv;

namespace Ui {
class Imshow;
}

class Imshow : public QMainWindow
{
    Q_OBJECT
    
public:
//explicit Imshow(QWidget *parent = 0);
    Imshow(QWidget *parent = Q_NULLPTR);
    ~Imshow();
    
private:
    Ui::Imshow *ui;
    VideoCapture capture;
    QImage srcQImage;
    QTimer *timer;
    Mat frame;
    Mat frame_clone;
    Mat rot_mat;
    Point2f po;
    int model = 0;
    bool hsv_model;
    bool click;
    bool hsvvalue;
    HsvSegmentation *hsv;
    Morph *morph;
    Threshold *thresh;
    Blue *bluer;

    bool open_rect;
    bool draw_minRectangle;
    bool draw_maxRectangle;
    bool draw_center;
    bool draw_ellipse;
    bool draw_convexHull;

    bool ifhough;
    int houghmodel;

    QTcpSocket* tcpsocket;
    quint64 basize;
    void ReadMyData();
    void acquireImage(QByteArray ba);

private slots:
    void imshow();
    void debug(int value);
    void importFrame();
    void OpenCreame();   
    void OpenVideo();
    void OpenPhoto();
    void qmage_format(Mat frame,int model);
    void frame_format(int model);
    void TransformFormat();
    void hsv_model_operation(bool ifhsv,Mat frame);

    void hsvSegmentation();
    void switch_hsv();
    void acquire_hmin(int value);
    void acquire_hmax(int value);
    void acquire_smin(int value);
    void acquire_smax(int value);
    void acquire_vmin(int value);
    void acquire_vmax(int value);
    void spinbox_hmin(int value);
    void spinbox_hmax(int value);
    void spinbox_smin(int value);
    void spinbox_smax(int value);
    void spinbox_vmin(int value);
    void spinbox_vmax(int value);

    void maxRectangle();
    void minRectangle();
    void Center();
    void Ellipse();
    void ConvexHull();
    void closeRect();
    void rect(Mat& frame_clone);

    void automatic_threshold();
    void mousePressEvent(QMouseEvent *ev);
    void switch_value(int value);
    void set_pointx(int value);
    void set_pointy(int value);
    void switch_hsvvalue();
    void set_hsv_value();
    void auto_acquire_hsv_value(bool hsvvalue,Mat frame);
    void acquire_point_hsv(Mat frame);

    void morph_oper();
    void switch_reset();
    void switch_dilate();
    void switch_erode();
    void switch_open();
    void switch_close();
    void switch_tophat();
    void switch_blackhat();
    void acquire_sizea(int value);
    void acquire_sizeb(int value);

    void threshold_oper();
    void binary();
    void binary_inv();
    void truncs();
    void tozero();
    void tozero_inv();
    void otsu();
    void triangle();
    void gaussian_c();
    void mean_c();
    void threshold_a(int value);
    void threshold_b(int value);
    void slider_thresha(int value);
    void slider_threshb(int value);

    void blue_oper();
    void Blur();
    void Gaussian();
    void Median();
    void Bilateral();
    void Mean();
    void Edge();
    void acquire_bulesize(int value);
    void acquire_gausizex(int value);
    void acquire_gausizey(int value);
    void switch_canny();

    void hough_oper();
    void lines();
    void linesp();
    void circles();
    void on_connect_clicked();
};

#endif // IMSHOW_H
