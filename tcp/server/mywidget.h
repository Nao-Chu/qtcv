#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <opencv2/opencv.hpp>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    
private:
    Ui::MyWidget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    cv::VideoCapture cap;
    void sendData();
};

#endif // MYWIDGET_H
