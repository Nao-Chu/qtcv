#include "blue.h"
#include <QDebug>

enum
{
    Bluer,
    Gaussian,
    Median,
    Bilateral,
    MeanShift,
    EdgePreservingFilter
};
Blue::Blue(QWidget *parent) :
    QMainWindow(parent)
{
    BlueFormat = -1;
    size_blue = 5;
    size_gaussian_x = 5;
    size_gaussian_y = 5;
    ifcanny = false;
}

void Blue::blue_operation(cv::Mat frame)
{
    cv::Size s = cv::Size(size_blue,size_blue);
    cv::Point po = cv::Point(-1,-1);
    cv::Point draw_po = cv::Point(30,30);
    cv::Scalar color = cv::Scalar(0,0,255);
    cv::Mat frame_blue = frame.clone();
    switch(BlueFormat)
    {
    case Bluer:
        cv::blur(frame_blue,frame,s,po,4);
        break;

    case Gaussian:
        cv::GaussianBlur(frame_blue,frame,s,size_gaussian_x,size_gaussian_y,4);
        break;

    case Median:
        cv::medianBlur(frame_blue,frame,size_blue);
        break;

    case Bilateral:
        cv::bilateralFilter(frame_blue,frame,0,100,10,4);
        break;

    case MeanShift:
        cv::pyrMeanShiftFiltering(frame_blue,frame
                                  ,15,50,1,cv::TermCriteria(
        cv::TermCriteria::COUNT + cv::TermCriteria::EPS,5,1));
        break;

    case EdgePreservingFilter:
        //cv::
        break;

    default:
        break;
    }
    if (BlueFormat != -1)
        cv::putText(frame_blue,"blue",draw_po,cv::FONT_HERSHEY_PLAIN,1,color,1,2,0);
}

void Blue::canny_operation(cv::Mat &frame_canny)
{
    cv::Mat img = frame_canny.clone();
    cv::Canny(img,frame_canny,50,50*3,3,false);
}
