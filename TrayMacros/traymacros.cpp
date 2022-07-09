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

    QIcon tray(":/icons_9618.png");
    trayIcon = new QSystemTrayIcon();
    menu = new QMenu();
    trayIcon->setIcon(tray);
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

