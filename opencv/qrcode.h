#ifndef QRCODE_H
#define QRCODE_H

#include <QWidget>
#include <opencv2/opencv.hpp>

using namespace cv;

class QrCode : public QWidget
{
    Q_OBJECT
public:
    explicit QrCode(QWidget *parent = 0);

public:
    virtual void ScanQrCode(Mat &img) = 0;
    std::vector<cv::Point> m_lineList;
    String m_scanResult;

protected:
    void resizeImg(Mat &img);
    int nCols;
    int nRows;

signals:
    
public slots:
    
};

class ScanResult : public QrCode
{
public:
    ScanResult();

private:
    virtual void ScanQrCode(Mat &img);

private:
    Mat grayImg;
    Mat res;
    QRCodeDetector QRdetector;
    std::vector<cv::Point> lineList;
    String scanResult;
};

class DrawQrCode : public QrCode
{
public:
    DrawQrCode(std::vector<Point> list);

private:
    virtual void ScanQrCode(Mat &img);

private:
    Scalar lineColor;
    std::vector<Point> m_list;
};

#endif // QRCODE_H
