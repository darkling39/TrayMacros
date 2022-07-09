#ifndef TRAYMACROS_H
#define TRAYMACROS_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include "windows.h"
#include <QTextToSpeech>

QT_BEGIN_NAMESPACE
namespace Ui { class TrayMacros; }
QT_END_NAMESPACE

class TrayMacros : public QMainWindow
{
    Q_OBJECT

public:
    TrayMacros(QWidget *parent = nullptr);
    ~TrayMacros();

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private slots:
    void browser();
    void player();
    void search();
    void speach();
    void explorer();
    void setLabel();
    void closeEvent(QCloseEvent *e);
private:
    Ui::TrayMacros *ui;
    QSystemTrayIcon *trayIcon;
    QMenu *menu;
    QAction *Close;
    QAction *Show;
    QTextToSpeech *speaker;
};
#endif // TRAYMACROS_H
