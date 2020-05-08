#include "threshold.h"
#include <QDebug>
Threshold::Threshold(QWidget *parent) :
    QMainWindow(parent)
{
    base_threshold = "NULL";
    LookFor_threshold = "NULL";
    auto_threshold = "NULL";
    min_a = 0;
    max_b = 255;
    threvshsv = false;
}

cv::Mat Threshold::Mythreshold(cv::Mat& frame_threshold)
{
    cv::Mat binary,gray;
    cv::Scalar color = cv::Scalar(0,0,255);
    cv::cvtColor(frame_threshold,gray,cv::COLOR_BGR2GRAY);
    threvshsv = false;
    if (strcmp(base_threshold.c_str(),"NULL") != 0 &&
        strcmp(LookFor_threshold.c_str(),"NULL") != 0)
    {
        if (strcmp(LookFor_threshold.c_str(),"THRESH_OTSU") == 0)
        {
            if(strcmp(base_threshold.c_str(),"THRESH_BINARY") == 0)
                cv::threshold(gray,binary,0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);
            else if(strcmp(base_threshold.c_str(),"THRESH_BINARY_INV") == 0)
                cv::threshold(gray,binary,0,255,cv::THRESH_BINARY_INV | cv::THRESH_OTSU);
            else if(strcmp(base_threshold.c_str(),"THRESH_TRUNC") == 0)
                cv::threshold(gray,binary,0,255,cv::THRESH_TRUNC | cv::THRESH_OTSU);
            else if(strcmp(base_threshold.c_str(),"THRESH_TOZERO") == 0)
                cv::threshold(gray,binary,0,255,cv::THRESH_TOZERO | cv::THRESH_OTSU);
            else if(strcmp(base_threshold.c_str(),"THRESH_TOZERO_INV") == 0)
                cv::threshold(gray,binary,0,255,cv::THRESH_TOZERO_INV | cv::THRESH_OTSU);
        }
        /*
        else
        {
            if(strcmp(base_threshold.str(),"THRESH_BINARY") == 0)
                cv::threshold(a,a,min_a,255,cv::THRESH_BINARY | cv::THRESH_TRIANGLE);
            else if(strcmp(base_threshold.str(),"THRESH_BINARY_INV") == 0)
                cv::threshold(a,a,min_a,255,cv::THRESH_BINARY_INV | cv::THRESH_TRIANGLE);
            else if(strcmp(base_threshold.str(),"THRESH_TRUNC") == 0)
                cv::threshold(a,a,min_a,255,cv::THRESH_TRUNC | cv::THRESH_TRIANGLE);
            else if(strcmp(base_threshold.str(),"THRESH_TOZERO") == 0)
                cv::threshold(a,a,min_a,255,cv::THRESH_TOZERO | cv::THRESH_TRIANGLE);
            else if(strcmp(base_threshold.str(),"THRESH_TOZERO_INV") == 0)
                cv::threshold(a,a,min_a,255,cv::THRESH_TOZERO_INV | cv::THRESH_TRIANGLE);
        }
        */
        cv::putText(frame_threshold,"base & looking for",
        cv::Point(10,10),cv::FONT_HERSHEY_PLAIN,1,color,1,1,0);
        threvshsv = true;

    }
    else if(strcmp(base_threshold.c_str(),"NULL") != 0)
    {
        if(strcmp(base_threshold.c_str(),"THRESH_BINARY") == 0)
            cv::threshold(gray,binary,min_a,max_b,cv::THRESH_BINARY);
        else if(strcmp(base_threshold.c_str(),"THRESH_BINARY_INV") == 0)
            cv::threshold(gray,binary,min_a,max_b,cv::THRESH_BINARY_INV);
        else if(strcmp(base_threshold.c_str(),"THRESH_TRUNC") == 0)
            cv::threshold(gray,binary,min_a,max_b,cv::THRESH_TRUNC);
        else if(strcmp(base_threshold.c_str(),"THRESH_TOZERO") == 0)
            cv::threshold(gray,binary,min_a,max_b,cv::THRESH_TOZERO);
        else if(strcmp(base_threshold.c_str(),"THRESH_TOZERO_INV") == 0)
            cv::threshold(gray,binary,min_a,max_b,cv::THRESH_TOZERO_INV);
        cv::putText(frame_threshold,"base",
        cv::Point(10,10),cv::FONT_HERSHEY_PLAIN,1,color,1,1,0);
        threvshsv = true;
    }
    else if(strcmp(LookFor_threshold.c_str(),"NULL") != 0)
    {
        if(strcmp(LookFor_threshold.c_str(),"THRESH_OTSU") == 0)
            cv::threshold(gray,binary,0,255,cv::THRESH_OTSU);
        cv::putText(frame_threshold,"looking for",
        cv::Point(10,10),cv::FONT_HERSHEY_PLAIN,1,color,1,1,0);
        threvshsv = true;
    }
    else if(strcmp(auto_threshold.c_str(),"NULL") != 0)
    {
        if(strcmp(auto_threshold.c_str(),"GAUSSIAN_C") == 0)
        {
            adaptiveThreshold(gray,binary,255,cv::ADAPTIVE_THRESH_GAUSSIAN_C,
                              cv::THRESH_BINARY,25,10);
        }
        else if(strcmp(auto_threshold.c_str(),"MEAN_C") == 0)
        {
            adaptiveThreshold(gray,binary,255,cv::ADAPTIVE_THRESH_MEAN_C,
                              cv::THRESH_BINARY,25,10);
        }
        cv::putText(frame_threshold,"auto",
        cv::Point(10,10),cv::FONT_HERSHEY_PLAIN,1,color,1,1,0);
        threvshsv = true;
    }
    return binary;
}

void Threshold::drawpoint(cv::Mat& frame_draw,cv::Mat frame_binary)
{
    for (int i = 0; i < frame_draw.rows; i++)
    {
        uchar* draw = frame_binary.ptr<uchar>(i);
        for (int j = 0; j < frame_draw.cols; j++)
        {
            if (draw[j] > 0)
            {
                uchar* data = frame_draw.ptr<uchar>(i,j);
                data[0] = 255;
                data[1] = 0;
                data[2] = 0;
            }
        }
    }
}
