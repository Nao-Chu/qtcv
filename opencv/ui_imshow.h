/********************************************************************************
** Form generated from reading UI file 'imshow.ui'
**
** Created: Fri May 8 23:09:37 2020
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMSHOW_H
#define UI_IMSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Imshow
{
public:
    QAction *Open_Creame;
    QAction *Open_Video;
    QAction *Open_Photo;
    QAction *actionRGB;
    QAction *actionGRB;
    QAction *actionHSV;
    QAction *actionGRAY;
    QAction *actionRectangle;
    QAction *actionMin_rectangle;
    QAction *actionCenter;
    QAction *actionClose;
    QAction *actionEllipse;
    QAction *actionConvexHull;
    QAction *actionBINARY;
    QAction *actionBINARY_INV;
    QAction *actionTRUNC;
    QAction *actionTOZERO;
    QAction *actionTOZERO_INV;
    QAction *actionOTSU;
    QAction *actionTRIANGLE;
    QAction *actionGAUSSIAN_C;
    QAction *actionMEAN_C;
    QAction *actionBlur;
    QAction *actionGaussian;
    QAction *actionMedian;
    QAction *actionMeanShift;
    QAction *actionEdgePreservingFilter;
    QAction *actionBilateral;
    QAction *actionLines;
    QAction *actionLinesp;
    QAction *actionCircles;
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *Format;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSlider *h_max;
    QLabel *label_3;
    QSlider *s_min;
    QSlider *s_max;
    QLabel *label_4;
    QSlider *v_min;
    QSlider *v_max;
    QSlider *h_min;
    QPushButton *switch_hsv;
    QCheckBox *coordinates_show;
    QSplitter *splitter;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QSpinBox *hmin;
    QLabel *label_8;
    QSpinBox *hmax;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_7;
    QSpinBox *smin;
    QLabel *label_9;
    QSpinBox *smax;
    QSpinBox *vmin;
    QSpinBox *vmax;
    QLabel *label_5;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QPushButton *automatic_threshold;
    QLabel *label_11;
    QSpinBox *x_point;
    QLabel *label_12;
    QSpinBox *y_point;
    QFrame *frame_4;
    QGridLayout *gridLayout_3;
    QLabel *h_name;
    QLabel *h_value;
    QLabel *s_name;
    QLabel *s_value;
    QLabel *v_name;
    QLabel *v_value;
    QFrame *frame_5;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit;
    QPushButton *reset;
    QPushButton *dilate;
    QPushButton *erode;
    QPushButton *open;
    QPushButton *close;
    QPushButton *tophat;
    QPushButton *blackhat;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QSpinBox *a;
    QLabel *X;
    QSpinBox *b;
    QPushButton *Canny;
    QFrame *frame_6;
    QGridLayout *gridLayout_7;
    QLabel *label_16;
    QSpinBox *blue_size;
    QLabel *label_17;
    QSpinBox *Gaussian_x;
    QSpinBox *Gaussian_y;
    QFrame *frame_7;
    QGridLayout *gridLayout_8;
    QSpinBox *threshold_a;
    QLabel *label_13;
    QSpinBox *threshold_b;
    QLabel *label_14;
    QSlider *Slider_thresha;
    QLabel *label_15;
    QSlider *Slider_threshb;
    QFrame *frame_8;
    QGridLayout *gridLayout_6;
    QLabel *label_18;
    QLineEdit *lineEditIp;
    QPushButton *connect;
    QPushButton *resultQrcode;
    QPushButton *drawQrcode;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *Rect;
    QMenu *menuThreshold;
    QMenu *menuBlur;
    QMenu *menuHough;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Imshow)
    {
        if (Imshow->objectName().isEmpty())
            Imshow->setObjectName(QStringLiteral("Imshow"));
        Imshow->resize(843, 627);
        Imshow->setMaximumSize(QSize(1000, 1000));
        Open_Creame = new QAction(Imshow);
        Open_Creame->setObjectName(QStringLiteral("Open_Creame"));
        Open_Video = new QAction(Imshow);
        Open_Video->setObjectName(QStringLiteral("Open_Video"));
        Open_Photo = new QAction(Imshow);
        Open_Photo->setObjectName(QStringLiteral("Open_Photo"));
        actionRGB = new QAction(Imshow);
        actionRGB->setObjectName(QStringLiteral("actionRGB"));
        actionGRB = new QAction(Imshow);
        actionGRB->setObjectName(QStringLiteral("actionGRB"));
        actionHSV = new QAction(Imshow);
        actionHSV->setObjectName(QStringLiteral("actionHSV"));
        actionGRAY = new QAction(Imshow);
        actionGRAY->setObjectName(QStringLiteral("actionGRAY"));
        actionRectangle = new QAction(Imshow);
        actionRectangle->setObjectName(QStringLiteral("actionRectangle"));
        actionMin_rectangle = new QAction(Imshow);
        actionMin_rectangle->setObjectName(QStringLiteral("actionMin_rectangle"));
        actionCenter = new QAction(Imshow);
        actionCenter->setObjectName(QStringLiteral("actionCenter"));
        actionClose = new QAction(Imshow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionEllipse = new QAction(Imshow);
        actionEllipse->setObjectName(QStringLiteral("actionEllipse"));
        actionConvexHull = new QAction(Imshow);
        actionConvexHull->setObjectName(QStringLiteral("actionConvexHull"));
        actionBINARY = new QAction(Imshow);
        actionBINARY->setObjectName(QStringLiteral("actionBINARY"));
        actionBINARY_INV = new QAction(Imshow);
        actionBINARY_INV->setObjectName(QStringLiteral("actionBINARY_INV"));
        actionTRUNC = new QAction(Imshow);
        actionTRUNC->setObjectName(QStringLiteral("actionTRUNC"));
        actionTOZERO = new QAction(Imshow);
        actionTOZERO->setObjectName(QStringLiteral("actionTOZERO"));
        actionTOZERO_INV = new QAction(Imshow);
        actionTOZERO_INV->setObjectName(QStringLiteral("actionTOZERO_INV"));
        actionOTSU = new QAction(Imshow);
        actionOTSU->setObjectName(QStringLiteral("actionOTSU"));
        actionTRIANGLE = new QAction(Imshow);
        actionTRIANGLE->setObjectName(QStringLiteral("actionTRIANGLE"));
        actionGAUSSIAN_C = new QAction(Imshow);
        actionGAUSSIAN_C->setObjectName(QStringLiteral("actionGAUSSIAN_C"));
        actionMEAN_C = new QAction(Imshow);
        actionMEAN_C->setObjectName(QStringLiteral("actionMEAN_C"));
        actionBlur = new QAction(Imshow);
        actionBlur->setObjectName(QStringLiteral("actionBlur"));
        actionGaussian = new QAction(Imshow);
        actionGaussian->setObjectName(QStringLiteral("actionGaussian"));
        actionMedian = new QAction(Imshow);
        actionMedian->setObjectName(QStringLiteral("actionMedian"));
        actionMeanShift = new QAction(Imshow);
        actionMeanShift->setObjectName(QStringLiteral("actionMeanShift"));
        actionEdgePreservingFilter = new QAction(Imshow);
        actionEdgePreservingFilter->setObjectName(QStringLiteral("actionEdgePreservingFilter"));
        actionBilateral = new QAction(Imshow);
        actionBilateral->setObjectName(QStringLiteral("actionBilateral"));
        actionLines = new QAction(Imshow);
        actionLines->setObjectName(QStringLiteral("actionLines"));
        actionLinesp = new QAction(Imshow);
        actionLinesp->setObjectName(QStringLiteral("actionLinesp"));
        actionCircles = new QAction(Imshow);
        actionCircles->setObjectName(QStringLiteral("actionCircles"));
        centralWidget = new QWidget(Imshow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -10, 381, 421));
        label->setMaximumSize(QSize(1000, 1000));
        Format = new QPushButton(centralWidget);
        Format->setObjectName(QStringLiteral("Format"));
        Format->setGeometry(QRect(420, 40, 99, 27));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(420, 80, 221, 224));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        h_max = new QSlider(frame);
        h_max->setObjectName(QStringLiteral("h_max"));
        h_max->setMaximum(180);
        h_max->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, h_max);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        s_min = new QSlider(frame);
        s_min->setObjectName(QStringLiteral("s_min"));
        s_min->setMaximum(255);
        s_min->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, s_min);

        s_max = new QSlider(frame);
        s_max->setObjectName(QStringLiteral("s_max"));
        s_max->setMaximum(255);
        s_max->setOrientation(Qt::Horizontal);

        formLayout->setWidget(3, QFormLayout::FieldRole, s_max);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        v_min = new QSlider(frame);
        v_min->setObjectName(QStringLiteral("v_min"));
        v_min->setMaximum(255);
        v_min->setOrientation(Qt::Horizontal);

        formLayout->setWidget(4, QFormLayout::FieldRole, v_min);

        v_max = new QSlider(frame);
        v_max->setObjectName(QStringLiteral("v_max"));
        v_max->setMaximum(255);
        v_max->setOrientation(Qt::Horizontal);

        formLayout->setWidget(5, QFormLayout::FieldRole, v_max);

        h_min = new QSlider(frame);
        h_min->setObjectName(QStringLiteral("h_min"));
        h_min->setMaximum(180);
        h_min->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, h_min);

        switch_hsv = new QPushButton(centralWidget);
        switch_hsv->setObjectName(QStringLiteral("switch_hsv"));
        switch_hsv->setGeometry(QRect(540, 40, 99, 27));
        coordinates_show = new QCheckBox(centralWidget);
        coordinates_show->setObjectName(QStringLiteral("coordinates_show"));
        coordinates_show->setGeometry(QRect(420, 10, 111, 16));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 440, 399, 113));
        splitter->setOrientation(Qt::Horizontal);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hmin = new QSpinBox(frame_2);
        hmin->setObjectName(QStringLiteral("hmin"));
        hmin->setMaximum(180);

        gridLayout->addWidget(hmin, 0, 1, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 2, 1, 1);

        hmax = new QSpinBox(frame_2);
        hmax->setObjectName(QStringLiteral("hmax"));
        hmax->setMaximum(180);

        gridLayout->addWidget(hmax, 0, 3, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 1, 2, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        smin = new QSpinBox(frame_2);
        smin->setObjectName(QStringLiteral("smin"));
        smin->setMaximum(255);

        gridLayout->addWidget(smin, 1, 1, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 2, 2, 1, 1);

        smax = new QSpinBox(frame_2);
        smax->setObjectName(QStringLiteral("smax"));
        smax->setMaximum(255);

        gridLayout->addWidget(smax, 1, 3, 1, 1);

        vmin = new QSpinBox(frame_2);
        vmin->setObjectName(QStringLiteral("vmin"));
        vmin->setMaximum(255);

        gridLayout->addWidget(vmin, 2, 1, 1, 1);

        vmax = new QSpinBox(frame_2);
        vmax->setObjectName(QStringLiteral("vmax"));
        vmax->setMaximum(255);

        gridLayout->addWidget(vmax, 2, 3, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        splitter->addWidget(frame_2);
        frame_3 = new QFrame(splitter);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        automatic_threshold = new QPushButton(frame_3);
        automatic_threshold->setObjectName(QStringLiteral("automatic_threshold"));

        gridLayout_2->addWidget(automatic_threshold, 0, 0, 1, 2);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);

        x_point = new QSpinBox(frame_3);
        x_point->setObjectName(QStringLiteral("x_point"));
        x_point->setMaximum(381);

        gridLayout_2->addWidget(x_point, 1, 1, 1, 1);

        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 2, 0, 1, 1);

        y_point = new QSpinBox(frame_3);
        y_point->setObjectName(QStringLiteral("y_point"));
        y_point->setMaximum(420);

        gridLayout_2->addWidget(y_point, 2, 1, 1, 1);

        splitter->addWidget(frame_3);
        frame_4 = new QFrame(splitter);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        h_name = new QLabel(frame_4);
        h_name->setObjectName(QStringLiteral("h_name"));

        gridLayout_3->addWidget(h_name, 0, 0, 1, 1);

        h_value = new QLabel(frame_4);
        h_value->setObjectName(QStringLiteral("h_value"));

        gridLayout_3->addWidget(h_value, 0, 1, 1, 1);

        s_name = new QLabel(frame_4);
        s_name->setObjectName(QStringLiteral("s_name"));

        gridLayout_3->addWidget(s_name, 1, 0, 1, 1);

        s_value = new QLabel(frame_4);
        s_value->setObjectName(QStringLiteral("s_value"));

        gridLayout_3->addWidget(s_value, 1, 1, 1, 1);

        v_name = new QLabel(frame_4);
        v_name->setObjectName(QStringLiteral("v_name"));

        gridLayout_3->addWidget(v_name, 2, 0, 1, 1);

        v_value = new QLabel(frame_4);
        v_value->setObjectName(QStringLiteral("v_value"));

        gridLayout_3->addWidget(v_value, 2, 1, 1, 1);

        splitter->addWidget(frame_4);
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(420, 320, 221, 230));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        lineEdit = new QLineEdit(frame_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout_5->addWidget(lineEdit, 0, 0, 1, 2);

        reset = new QPushButton(frame_5);
        reset->setObjectName(QStringLiteral("reset"));

        gridLayout_5->addWidget(reset, 2, 0, 1, 2);

        dilate = new QPushButton(frame_5);
        dilate->setObjectName(QStringLiteral("dilate"));

        gridLayout_5->addWidget(dilate, 3, 0, 1, 1);

        erode = new QPushButton(frame_5);
        erode->setObjectName(QStringLiteral("erode"));

        gridLayout_5->addWidget(erode, 3, 1, 1, 1);

        open = new QPushButton(frame_5);
        open->setObjectName(QStringLiteral("open"));

        gridLayout_5->addWidget(open, 4, 0, 1, 1);

        close = new QPushButton(frame_5);
        close->setObjectName(QStringLiteral("close"));

        gridLayout_5->addWidget(close, 4, 1, 1, 1);

        tophat = new QPushButton(frame_5);
        tophat->setObjectName(QStringLiteral("tophat"));

        gridLayout_5->addWidget(tophat, 5, 0, 1, 1);

        blackhat = new QPushButton(frame_5);
        blackhat->setObjectName(QStringLiteral("blackhat"));

        gridLayout_5->addWidget(blackhat, 5, 1, 1, 1);

        widget = new QWidget(frame_5);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        a = new QSpinBox(widget);
        a->setObjectName(QStringLiteral("a"));
        a->setMinimum(1);
        a->setMaximum(50);
        a->setValue(1);

        gridLayout_4->addWidget(a, 0, 0, 1, 1);

        X = new QLabel(widget);
        X->setObjectName(QStringLiteral("X"));

        gridLayout_4->addWidget(X, 0, 1, 1, 1);

        b = new QSpinBox(widget);
        b->setObjectName(QStringLiteral("b"));
        b->setMinimum(1);
        b->setMaximum(50);
        b->setValue(1);

        gridLayout_4->addWidget(b, 0, 2, 1, 1);


        gridLayout_5->addWidget(widget, 1, 0, 1, 2);

        Canny = new QPushButton(centralWidget);
        Canny->setObjectName(QStringLiteral("Canny"));
        Canny->setGeometry(QRect(540, 10, 99, 27));
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(650, 140, 151, 103));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_6);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_16 = new QLabel(frame_6);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_7->addWidget(label_16, 0, 0, 1, 1);

        blue_size = new QSpinBox(frame_6);
        blue_size->setObjectName(QStringLiteral("blue_size"));
        blue_size->setMinimum(1);
        blue_size->setValue(15);

        gridLayout_7->addWidget(blue_size, 0, 1, 1, 2);

        label_17 = new QLabel(frame_6);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_7->addWidget(label_17, 1, 0, 1, 2);

        Gaussian_x = new QSpinBox(frame_6);
        Gaussian_x->setObjectName(QStringLiteral("Gaussian_x"));
        Gaussian_x->setValue(15);

        gridLayout_7->addWidget(Gaussian_x, 2, 0, 1, 1);

        Gaussian_y = new QSpinBox(frame_6);
        Gaussian_y->setObjectName(QStringLiteral("Gaussian_y"));

        gridLayout_7->addWidget(Gaussian_y, 2, 2, 1, 1);

        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setGeometry(QRect(650, 10, 171, 117));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_7);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        threshold_a = new QSpinBox(frame_7);
        threshold_a->setObjectName(QStringLiteral("threshold_a"));
        threshold_a->setMaximum(255);

        gridLayout_8->addWidget(threshold_a, 0, 0, 1, 2);

        label_13 = new QLabel(frame_7);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_8->addWidget(label_13, 0, 2, 1, 1);

        threshold_b = new QSpinBox(frame_7);
        threshold_b->setObjectName(QStringLiteral("threshold_b"));
        threshold_b->setMaximum(255);
        threshold_b->setValue(255);

        gridLayout_8->addWidget(threshold_b, 0, 3, 1, 1);

        label_14 = new QLabel(frame_7);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_8->addWidget(label_14, 1, 0, 1, 1);

        Slider_thresha = new QSlider(frame_7);
        Slider_thresha->setObjectName(QStringLiteral("Slider_thresha"));
        Slider_thresha->setMaximum(255);
        Slider_thresha->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(Slider_thresha, 1, 1, 1, 3);

        label_15 = new QLabel(frame_7);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_8->addWidget(label_15, 2, 0, 1, 2);

        Slider_threshb = new QSlider(frame_7);
        Slider_threshb->setObjectName(QStringLiteral("Slider_threshb"));
        Slider_threshb->setMaximum(255);
        Slider_threshb->setValue(255);
        Slider_threshb->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(Slider_threshb, 2, 2, 1, 2);

        frame_8 = new QFrame(centralWidget);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setGeometry(QRect(650, 260, 171, 80));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_8);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_18 = new QLabel(frame_8);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_6->addWidget(label_18, 0, 0, 1, 1);

        lineEditIp = new QLineEdit(frame_8);
        lineEditIp->setObjectName(QStringLiteral("lineEditIp"));

        gridLayout_6->addWidget(lineEditIp, 0, 1, 1, 1);

        connect = new QPushButton(frame_8);
        connect->setObjectName(QStringLiteral("connect"));

        gridLayout_6->addWidget(connect, 1, 0, 1, 2);

        resultQrcode = new QPushButton(centralWidget);
        resultQrcode->setObjectName(QStringLiteral("resultQrcode"));
        resultQrcode->setGeometry(QRect(660, 350, 151, 27));
        drawQrcode = new QPushButton(centralWidget);
        drawQrcode->setObjectName(QStringLiteral("drawQrcode"));
        drawQrcode->setGeometry(QRect(660, 380, 151, 27));
        Imshow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Imshow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Imshow->setStatusBar(statusBar);
        menuBar = new QMenuBar(Imshow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 843, 25));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        Rect = new QMenu(menuBar);
        Rect->setObjectName(QStringLiteral("Rect"));
        menuThreshold = new QMenu(menuBar);
        menuThreshold->setObjectName(QStringLiteral("menuThreshold"));
        menuBlur = new QMenu(menuBar);
        menuBlur->setObjectName(QStringLiteral("menuBlur"));
        menuHough = new QMenu(menuBar);
        menuHough->setObjectName(QStringLiteral("menuHough"));
        Imshow->setMenuBar(menuBar);
        toolBar = new QToolBar(Imshow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Imshow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(Rect->menuAction());
        menuBar->addAction(menuThreshold->menuAction());
        menuBar->addAction(menuBlur->menuAction());
        menuBar->addAction(menuHough->menuAction());
        menuOpen->addSeparator();
        menuOpen->addAction(Open_Creame);
        menuOpen->addAction(Open_Video);
        menuOpen->addAction(Open_Photo);
        Rect->addAction(actionRectangle);
        Rect->addAction(actionMin_rectangle);
        Rect->addAction(actionCenter);
        Rect->addAction(actionEllipse);
        Rect->addAction(actionConvexHull);
        Rect->addAction(actionClose);
        menuThreshold->addAction(actionBINARY);
        menuThreshold->addAction(actionBINARY_INV);
        menuThreshold->addAction(actionTRUNC);
        menuThreshold->addAction(actionTOZERO);
        menuThreshold->addAction(actionTOZERO_INV);
        menuThreshold->addSeparator();
        menuThreshold->addAction(actionOTSU);
        menuThreshold->addAction(actionTRIANGLE);
        menuThreshold->addSeparator();
        menuThreshold->addAction(actionGAUSSIAN_C);
        menuThreshold->addAction(actionMEAN_C);
        menuBlur->addAction(actionBlur);
        menuBlur->addAction(actionGaussian);
        menuBlur->addAction(actionMedian);
        menuBlur->addAction(actionBilateral);
        menuBlur->addAction(actionMeanShift);
        menuBlur->addAction(actionEdgePreservingFilter);
        menuHough->addAction(actionLines);
        menuHough->addAction(actionLinesp);
        menuHough->addAction(actionCircles);

        retranslateUi(Imshow);

        QMetaObject::connectSlotsByName(Imshow);
    } // setupUi

    void retranslateUi(QMainWindow *Imshow)
    {
        Imshow->setWindowTitle(QApplication::translate("Imshow", "Imshow", 0));
        Open_Creame->setText(QApplication::translate("Imshow", "Open Creame", 0));
        Open_Video->setText(QApplication::translate("Imshow", "Open Video", 0));
        Open_Photo->setText(QApplication::translate("Imshow", "Open Photo", 0));
        actionRGB->setText(QApplication::translate("Imshow", "RGB", 0));
        actionGRB->setText(QApplication::translate("Imshow", "GRB", 0));
        actionHSV->setText(QApplication::translate("Imshow", "HSV", 0));
        actionGRAY->setText(QApplication::translate("Imshow", "GRAY", 0));
        actionRectangle->setText(QApplication::translate("Imshow", "max_rectangle", 0));
        actionMin_rectangle->setText(QApplication::translate("Imshow", "min_rectangle", 0));
        actionCenter->setText(QApplication::translate("Imshow", "center", 0));
        actionClose->setText(QApplication::translate("Imshow", "close", 0));
        actionEllipse->setText(QApplication::translate("Imshow", "ellipse", 0));
        actionConvexHull->setText(QApplication::translate("Imshow", "convexHull", 0));
        actionBINARY->setText(QApplication::translate("Imshow", "BINARY", 0));
        actionBINARY_INV->setText(QApplication::translate("Imshow", "BINARY_INV", 0));
        actionTRUNC->setText(QApplication::translate("Imshow", "TRUNC", 0));
        actionTOZERO->setText(QApplication::translate("Imshow", "TOZERO", 0));
        actionTOZERO_INV->setText(QApplication::translate("Imshow", "TOZERO_INV", 0));
        actionOTSU->setText(QApplication::translate("Imshow", "OTSU", 0));
        actionTRIANGLE->setText(QApplication::translate("Imshow", "TRIANGLE", 0));
        actionGAUSSIAN_C->setText(QApplication::translate("Imshow", "GAUSSIAN_C", 0));
        actionMEAN_C->setText(QApplication::translate("Imshow", "MEAN_C", 0));
        actionBlur->setText(QApplication::translate("Imshow", "blur", 0));
        actionGaussian->setText(QApplication::translate("Imshow", "gaussian", 0));
        actionMedian->setText(QApplication::translate("Imshow", "median", 0));
        actionMeanShift->setText(QApplication::translate("Imshow", "meanShift", 0));
        actionEdgePreservingFilter->setText(QApplication::translate("Imshow", "edgePreservingFilter", 0));
        actionBilateral->setText(QApplication::translate("Imshow", "bilateral", 0));
        actionLines->setText(QApplication::translate("Imshow", "lines", 0));
        actionLinesp->setText(QApplication::translate("Imshow", "linesp", 0));
        actionCircles->setText(QApplication::translate("Imshow", "circles", 0));
        label->setText(QApplication::translate("Imshow", "                                               Loading...", 0));
        Format->setText(QApplication::translate("Imshow", "format", 0));
        label_2->setText(QApplication::translate("Imshow", "H:", 0));
        label_3->setText(QApplication::translate("Imshow", "S:", 0));
        label_4->setText(QApplication::translate("Imshow", "V:", 0));
        switch_hsv->setText(QApplication::translate("Imshow", "HSV", 0));
        coordinates_show->setText(QApplication::translate("Imshow", "Coordinates", 0));
        label_8->setText(QApplication::translate("Imshow", "~", 0));
        label_6->setText(QApplication::translate("Imshow", "S:", 0));
        label_10->setText(QApplication::translate("Imshow", "~", 0));
        label_7->setText(QApplication::translate("Imshow", "V:", 0));
        label_9->setText(QApplication::translate("Imshow", "~", 0));
        label_5->setText(QApplication::translate("Imshow", "H:", 0));
        automatic_threshold->setText(QApplication::translate("Imshow", "Automatic", 0));
        label_11->setText(QApplication::translate("Imshow", "X:", 0));
        label_12->setText(QApplication::translate("Imshow", "Y:", 0));
        h_name->setText(QApplication::translate("Imshow", "h:", 0));
        h_value->setText(QApplication::translate("Imshow", "0", 0));
        s_name->setText(QApplication::translate("Imshow", "s:", 0));
        s_value->setText(QApplication::translate("Imshow", "0", 0));
        v_name->setText(QApplication::translate("Imshow", "v:", 0));
        v_value->setText(QApplication::translate("Imshow", "0", 0));
        lineEdit->setText(QApplication::translate("Imshow", "      Morphological operation", 0));
        reset->setText(QApplication::translate("Imshow", "reset", 0));
        dilate->setText(QApplication::translate("Imshow", "dilate", 0));
        erode->setText(QApplication::translate("Imshow", "erode", 0));
        open->setText(QApplication::translate("Imshow", "open", 0));
        close->setText(QApplication::translate("Imshow", "close", 0));
        tophat->setText(QApplication::translate("Imshow", "tophat", 0));
        blackhat->setText(QApplication::translate("Imshow", "blackhat", 0));
        X->setText(QApplication::translate("Imshow", "     X", 0));
        Canny->setText(QApplication::translate("Imshow", "canny", 0));
        label_16->setText(QApplication::translate("Imshow", "blur:", 0));
        label_17->setText(QApplication::translate("Imshow", "hough:", 0));
        label_13->setText(QApplication::translate("Imshow", " X", 0));
        label_14->setText(QApplication::translate("Imshow", "thresh_a", 0));
        label_15->setText(QApplication::translate("Imshow", "thresh_b", 0));
        label_18->setText(QApplication::translate("Imshow", "ip :", 0));
        lineEditIp->setText(QApplication::translate("Imshow", "192.168.1.1", 0));
        connect->setText(QApplication::translate("Imshow", "connect", 0));
        resultQrcode->setText(QApplication::translate("Imshow", "resultQrCode", 0));
        drawQrcode->setText(QApplication::translate("Imshow", "drawQrCode", 0));
        menuOpen->setTitle(QApplication::translate("Imshow", "open", 0));
        Rect->setTitle(QApplication::translate("Imshow", "drawtarget", 0));
        menuThreshold->setTitle(QApplication::translate("Imshow", "threshold", 0));
        menuBlur->setTitle(QApplication::translate("Imshow", "blur", 0));
        menuHough->setTitle(QApplication::translate("Imshow", "hough", 0));
        toolBar->setWindowTitle(QApplication::translate("Imshow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class Imshow: public Ui_Imshow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMSHOW_H
