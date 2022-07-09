#include "traymacros.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrayMacros w;
    w.show();
    return a.exec();
}
