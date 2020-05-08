#ifndef BLUE_H
#define BLUE_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>

class Blue : public QMainWindow
{
    Q_OBJECT
public:
    explicit Blue(QWidget *parent = 0);
    friend class Imshow;
    
private:
    int BlueFormat;
    int size_blue;
    int size_gaussian_x;
    int size_gaussian_y;
    bool ifcanny;
    void blue_operation(cv::Mat frame_blue);
    void canny_operation(cv::Mat &frame_canny);

signals:
    
public slots:
    
};

#endif // BLUE_H
