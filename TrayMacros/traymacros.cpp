#include "traymacros.h"
#include "ui_traymacros.h"
#include <QIcon>
#include <QSystemTrayIcon>
#include <QMenu>
#include <windows.h>
#include <QtDebug>
#include <QCloseEvent>
#include <QLocale>

TrayMacros::TrayMacros(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TrayMacros)
{
    ui->setupUi(this);
    //Icon
    QIcon tray(":/icons_9618.png");
    trayIcon = new QSystemTrayIcon();
    menu = new QMenu();
    trayIcon->setIcon(tray);
    this->setWindowIcon(tray);
    trayIcon->show();

    //Tray-Menu
    Close = new QAction("Close");
    Show = new QAction("Show");
    menu->addAction(Close);
    menu->addAction(Show);
    trayIcon->setContextMenu(menu);

    connect(Close, &QAction::triggered, this, &TrayMacros::close);
    connect(Show, &QAction::triggered, this, &TrayMacros::show);
}

TrayMacros::~TrayMacros()
{
    delete ui;
}

void TrayMacros::player()
{
    system("start aimp");
}

void TrayMacros::browser()
{
    system("start opera");
}

void TrayMacros::search()
{
    system("start http://google.com");
}

void TrayMacros::speach()
{
    QString hello = "hello";
    speaker->say(hello);
}

void TrayMacros::explorer()
{
    system("start explorer");
}
