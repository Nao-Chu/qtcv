#include "hsvsegmentation.h"
#include <QDebug>
#include <QKeyEvent>
#include <iostream>

enum
{
    RED_ONE = 1,
    ORANGE,
    YELLOW,
    GREEN,
    CYAN,
    BLUE,
    PURPLE,
    RED_TWO
};

HsvSegmentation::HsvSegmentation(QWidget *parent) :
    QMainWindow(parent)
{
    for (int i = 0; i < 6; i++)
        hsv[i] = 0;
    hsv_red_one[0] = 0;    hsv_red_one[1] = 10;
    hsv_orange [0] = 11;   hsv_orange [1] = 25;
    hsv_yellow [0] = 26;   hsv_yellow [1] = 34;
    hsv_green  [0] = 35;   hsv_green  [1] = 77;
    hsv_cyan   [0] = 78;   hsv_cyan   [1] = 99;
    hsv_blue   [0] = 100;  hsv_blue   [1] = 124;
    hsv_purple [0] = 125;  hsv_purple [1] = 155;
    hsv_red_two[0] = 156;  hsv_red_two[1] = 180;
    storage[0] = 43; storage[1] = 255;
    storage[2] = 46; storage[3] = 255;
    for (int i = 2; i < 6; i++)
    {
        hsv_red_one[i] = storage[i-2];
        hsv_orange [i] = storage[i-2];
        hsv_yellow [i] = storage[i-2];
        hsv_green  [i] = storage[i-2];
        hsv_cyan   [i] = storage[i-2];
        hsv_blue   [i] = storage[i-2];
        hsv_purple [i] = storage[i-2];
        hsv_red_two[i] = storage[i-2];
    }
    targetpoint = cv::Point2f(0,0);
    lis = cv::Point2f(0,0);
}

void HsvSegmentation::acquire_hmin(int value)
{
    hsv[0] = value;
}

void HsvSegmentation::acquire_hmax(int value)
{
    hsv[1] = value;
}

void HsvSegmentation::acquire_smin(int value)
{
    hsv[2] = value;
}

void HsvSegmentation::acquire_smax(int value)
{
    hsv[3] = value;
}

void HsvSegmentation::acquire_vmin(int value)
{
    hsv[4] = value;
}

void HsvSegmentation::acquire_vmax(int value)
{
    hsv[5] = value;
}

void HsvSegmentation::spinbox_hmin(int value)
{
    hsv[0] = value;
}

void HsvSegmentation::spinbox_hmax(int value)
{
    hsv[1] = value;
}

void HsvSegmentation::spinbox_smin(int value)
{
    hsv[2] = value;
}

void HsvSegmentation::spinbox_smax(int value)
{
    hsv[3] = value;
}

void HsvSegmentation::spinbox_vmin(int value)
{
    hsv[4] = value;
}

void HsvSegmentation::spinbox_vmax(int value)
{
    hsv[5] = value;
}

int HsvSegmentation::judge_color(int h)
{
    if (h >= 0 && h <= 10)
        return RED_ONE;
    else if (h >= 11 && h <= 25)
        return ORANGE;
    else if (h >= 26 && h <= 34)
        return YELLOW;
    else if (h >= 35 && h <= 77)
        return GREEN;
    else if (h >= 78 && h <= 99)
        return CYAN;
    else if (h >= 100 && h <= 124)
        return BLUE;
    else if (h >= 125 && h <= 155)
        return PURPLE;
    else
        return RED_TWO;
}

cv::Mat HsvSegmentation::inrange_class(cv::Mat frame_hsv,int color_label)
{
    cv::Mat red;
    cv::Mat aim;
    switch(color_label)
    {
        case RED_ONE:
            cv::inRange(frame_hsv,cv::Scalar(hsv_red_one[0],hsv_red_one[2],hsv_red_one[4]),
                cv::Scalar(hsv_red_one[1],hsv_red_one[3],hsv_red_one[5]),aim);
            cv::inRange(frame_hsv,cv::Scalar(hsv_red_two[0],hsv_red_two[2],hsv_red_two[4]),
                cv::Scalar(hsv_red_two[1],hsv_red_two[3],hsv_red_two[5]),red);
            addWeighted(aim,1.0,red,1.0,0,aim);
            break;

        case ORANGE:
            cv::inRange(frame_hsv,cv::Scalar(hsv_orange[0],hsv_orange[2],hsv_orange[4]),
                cv::Scalar(hsv_orange[1],hsv_orange[3],hsv_orange[5]),aim);
            break;

        case YELLOW:
            cv::inRange(frame_hsv,cv::Scalar(hsv_yellow[0],hsv_yellow[2],hsv_yellow[4]),
                cv::Scalar(hsv_yellow[1],hsv_yellow[3],hsv_yellow[5]),aim);
            break;

        case GREEN:
            cv::inRange(frame_hsv,cv::Scalar(hsv_green[0],hsv_green[2],hsv_green[4]),
                cv::Scalar(hsv_green[1],hsv_green[3],hsv_green[5]),aim);
            break;

        case CYAN:
            cv::inRange(frame_hsv,cv::Scalar(hsv_cyan[0],hsv_cyan[2],hsv_cyan[4]),
                cv::Scalar(hsv_cyan[1],hsv_cyan[3],hsv_cyan[5]),aim);
            break;

        case BLUE:
            cv::inRange(frame_hsv,cv::Scalar(hsv_blue[0],hsv_blue[2],hsv_blue[4]),
                cv::Scalar(hsv_blue[1],hsv_blue[3],hsv_blue[5]),aim);
            break;

        case PURPLE:
            cv::inRange(frame_hsv,cv::Scalar(hsv_purple[0],hsv_purple[2],hsv_purple[4]),
                cv::Scalar(hsv_purple[1],hsv_purple[3],hsv_purple[5]),aim);
            break;

        case RED_TWO:
            cv::inRange(frame_hsv,cv::Scalar(hsv_red_one[0],hsv_red_one[2],hsv_red_one[4]),
                cv::Scalar(hsv_red_one[1],hsv_red_one[3],hsv_red_one[5]),aim);
            cv::inRange(frame_hsv,cv::Scalar(hsv_red_two[0],hsv_red_two[2],hsv_red_two[4]),
                cv::Scalar(hsv_red_two[1],hsv_red_two[3],hsv_red_two[5]),red);
            addWeighted(aim,1.0,red,1.0,0,aim);
            break;
    }
    return aim;
}

void HsvSegmentation::acquire_threshlod(cv::Mat frame,int col,int row)
{
    using namespace cv;
    Mat frame_clone = frame;
    cv::resize(frame_clone,frame_clone,Size(col,row));
    Mat frame_hsv = Mat::zeros(Size(col,row),CV_32FC3);
    Mat all_color_frame;
    cvtColor(frame_clone,frame_hsv,COLOR_BGR2HSV);
    int color_label = judge_color(static_cast<int>(frame_hsv.at<cv::Vec3b>(targetpoint.y,targetpoint.x)[0]));
    all_color_frame = inrange_class(frame_hsv,color_label);
    Mat element = getStructuringElement(MORPH_RECT,Size(5,5));
    morphologyEx(all_color_frame,all_color_frame,MORPH_OPEN,element);
    findContours(all_color_frame,contours,RETR_TREE,CHAIN_APPROX_SIMPLE);
    int contours_index = 10;
    for (size_t i = 0; i < contours.size(); i++)
    {
        if(pointPolygonTest(contours[i],Point2f(targetpoint.x,targetpoint.y),false) == 1)
        {
            contours_index = i;
            break;
        }
    }
    if ((contours_index != 10) && (targetpoint.x != lis.x) && (targetpoint.y != lis.y))
    {
        vector<cv::Point2f>().swap(white_point);
        vector<cv::Point2f>().swap(contours_point);
        for (int i = 0; i < frame_hsv.rows; i++)
        {
            uchar* ptr = frame_hsv.ptr<uchar>(i);
            for (int j = 0; j < frame_hsv.cols; j++)
            {
                if (ptr[j] > 0)
                    white_point.push_back(Point2f(j,i));
            }
        }
        for (size_t i = 0; i < white_point.size(); i++)
        {
            if (pointPolygonTest(contours[contours_index],Point2f(white_point[i].x,white_point[i].y),
                                 false) == 1)
            {
                contours_point.push_back(Point2f(white_point[i].x,white_point[i].y));
            }
        }
        if(contours_point.size() != 0)
        {
            vector<int>().swap(h); vector<int>().swap(s); vector<int>().swap(v);
            for (size_t i = 0; i < contours_point.size(); i++)
            {
                h.push_back(static_cast<int>(frame_hsv.at<Vec3b>(contours_point[i].y,
                                                                 contours_point[i].x)[0]));
                s.push_back(static_cast<int>(frame_hsv.at<Vec3b>(contours_point[i].y,
                                                                 contours_point[i].x)[1]));
                v.push_back(static_cast<int>(frame_hsv.at<Vec3b>(contours_point[i].y,
                                                                 contours_point[i].x)[2]));
            }
            sort(h.begin(),h.end()); sort(s.begin(),s.end()); sort(v.begin(),v.end());
            hsv[0] = min_average(h);    hsv[1] = max_average(h);
            hsv[2] = min_average(s);    hsv[3] = max_average(s);
            hsv[4] = min_average(v);    hsv[5] = max_average(v);
        }
    }
    lis.x = targetpoint.x;
    lis.y = targetpoint.y;
}

int HsvSegmentation::min_average(vector<int> min)
{
    int min_average = 0;
    size_t extremum = 10;
    if(min.size() > extremum)
    {
        for(int t = 0; t < (int)extremum; t++)
        {
            min_average += min[t];
        }
    }
    else
    {
        return *min_element(min.begin(),min.end());
    }
    return min_average / (int)extremum;
}

int HsvSegmentation::max_average(vector<int> max)
{
    int max_average = 0;
    size_t extremum = 10;
    if(max.size() > extremum)
    {
        for(int t = (int)max.size() - 1; t >= (int)max.size() - (int)extremum; t--)
        {
            max_average += max[t];
        }
    }
    else
    {
        return *max_element(max.begin(),max.end());
    }
    return max_average / (int)extremum;
}
