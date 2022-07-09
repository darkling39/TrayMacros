#include "traymacros.h"
#include "ui_traymacros.h"

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

