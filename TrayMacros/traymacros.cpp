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
}

TrayMacros::~TrayMacros()
{
    delete ui;
}

