#ifndef FORMAT_H
#define FORMAT_H

#include <QMainWindow>

class Format : public QMainWindow
{
    Q_OBJECT
public:
    explicit Format(QWidget *parent = 0);
    friend class Imshow;
private slots:
    void Transform_RGB();
    void Transform_BGR();
    void Transform_HSV();
    void Transform_GRAY();

signals:
    
public slots:
    
};

#endif // FORMAT_H
