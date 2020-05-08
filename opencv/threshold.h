#ifndef THRESHOLD_H
#define THRESHOLD_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>

class Threshold : public QMainWindow
{
    Q_OBJECT
public:
    explicit Threshold(QWidget *parent = 0);
    friend class Imshow;
    
private:
    std::string base_threshold;
    std::string LookFor_threshold;
    std::string auto_threshold;
    cv::Mat Mythreshold(cv::Mat& frame_threshold);
    void drawpoint(cv::Mat& frame_draw,cv::Mat frame_binary);
    int min_a;
    int max_b;
    bool threvshsv;

signals:
    
public slots:
    
};

#endif // THRESHOLD_H
