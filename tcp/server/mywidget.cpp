#include "mywidget.h"
#include "ui_mywidget.h"
#include <QBuffer>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    //tcpServer->listen(QHostAddress::Any,8888);
    if(!tcpServer->listen(QHostAddress::Any,8888))
    {
        close();
        return;
    }
    cap.open(0);
    connect(tcpServer, &QTcpServer::newConnection, [=](){sendData();});

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::sendData()
{
    tcpSocket = tcpServer->nextPendingConnection();
    cv::Mat frame;
    //cap >> frame;
    frame = cv::imread("/home/nao-chu/Desktop/11.jpg");
    cvtColor(frame,frame,cv::COLOR_RGB2BGR);
    QByteArray byte;
    QBuffer buf(&byte);
    QImage image((unsigned const char*)frame.data,
           frame.cols,frame.rows,QImage::Format_RGB888);
    image.save(&buf,"JPEG");
    QByteArray ss=qCompress(byte,1);
    QByteArray vv=ss.toBase64();

    QByteArray ba;
    QDataStream out(&ba,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out<<(quint64)0;
    out<<vv;
    out.device()->seek(0);
    out<<(quint64)(ba.size()-sizeof(quint64));
    tcpSocket->write(ba);
}
