#ifndef MORPH_H
#define MORPH_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>

class Morph : public QMainWindow
{
    Q_OBJECT
public:
    explicit Morph(QWidget *parent = 0);
    friend class Imshow;
    friend class Threshold;
    
private:
    int MorphFormat;
    int size_a;
    int size_b;
    bool openMorph;
    void morph_operation(int MorphFormat,cv::Mat init_hsv_frame);
    cv::Mat morph_frame;

signals:
    
public slots:
    
};

#endif // MORPH_H
