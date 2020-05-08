#include "mywindow.h"
#include "ui_mywindow.h"
#include <imshow.h>

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    imshow i;
}

MyWindow::~MyWindow()
{
    delete ui;
}
