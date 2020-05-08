#ifndef HSVSEGMENTATION_H
#define HSVSEGMENTATION_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
class HsvSegmentation : public QMainWindow
{
    Q_OBJECT
public:
    explicit HsvSegmentation(QWidget *parent = 0);
    friend class Imshow;


signals:
    
private:
    int hsv[6];
    int hsv_red_one[6];
    int hsv_orange[6];
    int hsv_yellow[6];
    int hsv_green[6];
    int hsv_cyan[6];
    int hsv_blue[6];
    int hsv_purple[6];
    int hsv_red_two[6];
    int storage[6];

    vector<vector<cv::Point> > contours;
    vector<cv::Point2f> white_point;
    vector<cv::Point2f> contours_point;
    vector<int> h;
    vector<int> s;
    vector<int> v;
    cv::Point2f targetpoint;
    cv::Point2f lis;

public slots:

private slots:
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

    void acquire_threshlod(cv::Mat frame,int col,int row);
    int  judge_color(int h);
    cv::Mat inrange_class(cv::Mat frame_hsv,int model); 
    int  min_average(vector<int> min);
    int  max_average(vector<int> max);

};

#endif // HSVSEGMENTATION_H
