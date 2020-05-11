#include "qrcode.h"
#include <QDebug>

QrCode::QrCode(QWidget *parent) :
    QWidget(parent)
{
    nCols = 1280;
}

void QrCode::resizeImg(Mat &img)
{
    nRows = img.rows*1280/img.cols;
    nRows = nRows < 960 ? 960 : nRows;
    cv::resize(img,img,Size(nCols,nRows));
}

ScanResult::ScanResult()
{

}

void ScanResult::ScanQrCode(Mat &img)
{
    Mat img_clone = img.clone();
    resizeImg(img_clone);
    cvtColor(img_clone,grayImg,COLOR_BGR2GRAY);
    GaussianBlur(grayImg,grayImg,Size(3,3),1.5);
    scanResult = QRdetector.detectAndDecode(grayImg,lineList,res);
    m_scanResult = scanResult;
    m_lineList = lineList;
}



DrawQrCode::DrawQrCode(std::vector<Point> list)
{
    lineColor = Scalar(0,255,0);
    this->m_list = list;
}

void DrawQrCode::ScanQrCode(Mat &img)
{
    Mat resimg = img.clone();
    resizeImg(resimg);
    for(int j = 0; j < m_list.size(); j++)
    {
        if(j == 3)
        {
            line(resimg,m_list[j],m_list[0],lineColor,2);
        }
        else
        {
            line(resimg,m_list[j],m_list[j + 1],lineColor,2);
        }
    }
    cv::resize(resimg,resimg,Size(img.cols,img.rows));
    img = resimg.clone();
}
