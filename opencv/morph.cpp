#include "morph.h"
#include <QDebug>

enum
{
    Reset,
    dilate,
    erode,
    open,
    colse,
    tophat,
    blackhat
};

Morph::Morph(QWidget *parent) :
    QMainWindow(parent)
{
    MorphFormat = 0;
    size_a = 1;
    size_b = 1;
    openMorph = true;
}

void Morph::morph_operation(int MorphFormat,cv::Mat init_hsv_frame)
{
    cv::Mat se = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(size_a,size_b),cv::Point(0,0));
    openMorph = false;
    switch(MorphFormat)
    {
        case Reset:
            openMorph = true;
            morph_frame = init_hsv_frame.clone();
            break;

        case dilate:
            cv::dilate(morph_frame,morph_frame,se,cv::Point(-1,-1),1,0);
            break;

        case erode:
            cv::erode(morph_frame,morph_frame,se,cv::Point(-1,-1),1,0);
            break;

        case open:
            cv::morphologyEx(morph_frame,morph_frame,cv::MORPH_OPEN,se);
            break;

        case colse:
            cv::morphologyEx(morph_frame,morph_frame,cv::MORPH_CLOSE,se);
            break;

        case tophat:
            cv::morphologyEx(morph_frame,morph_frame,cv::MORPH_TOPHAT,se);
            break;

        case blackhat:
            cv::morphologyEx(morph_frame,morph_frame,cv::MORPH_BLACKHAT,se);
            break;

        default:
            openMorph = true;
            morph_frame = init_hsv_frame.clone();
            break;
    }
}
