#include "imshow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Imshow w;
    w.show();
    
    return a.exec();
}
