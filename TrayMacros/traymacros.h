#ifndef TRAYMACROS_H
#define TRAYMACROS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TrayMacros; }
QT_END_NAMESPACE

class TrayMacros : public QMainWindow
{
    Q_OBJECT

public:
    TrayMacros(QWidget *parent = nullptr);
    ~TrayMacros();

private:
    Ui::TrayMacros *ui;
};
#endif // TRAYMACROS_H
