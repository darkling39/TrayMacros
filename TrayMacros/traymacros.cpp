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

    //speaker
    speaker = new QTextToSpeech();
    speaker->setLocale(QLocale(QLocale::English));
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

    //default hotkeys
    RegisterHotKey((HWND)TrayMacros::winId(), 10, MOD_CONTROL, 'P');
    RegisterHotKey((HWND)TrayMacros::winId(), 20, MOD_CONTROL, 'B');
    RegisterHotKey((HWND)TrayMacros::winId(), 30, MOD_CONTROL, 'S');
    RegisterHotKey((HWND)TrayMacros::winId(), 40, MOD_CONTROL, 'E');
    RegisterHotKey((HWND)TrayMacros::winId(), 50, MOD_CONTROL, 'T');

    //label change
    connect(ui->rb_alt, &QRadioButton::toggled, this, &TrayMacros::setLabel);
    connect(ui->rb_ctrl, &QRadioButton::toggled, this, &TrayMacros::setLabel);
    connect(ui->rb_shift, &QRadioButton::toggled, this, &TrayMacros::setLabel);

    //change hotkey
    connect(ui->b_confirm, &QPushButton::clicked, this, &TrayMacros::regKey);

}

TrayMacros::~TrayMacros()
{
    delete ui;
}


bool TrayMacros::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType)
    Q_UNUSED(result)
    MSG* msg = reinterpret_cast<MSG*>(message);

    if(msg->message == WM_HOTKEY)
    {
        if(msg->wParam == 10)
        {
            player();
            return true;
        }
        if(msg->wParam == 20)
        {
            browser();
            return true;
        }
        if(msg->wParam == 30)
        {
            search();
            return true;
        }
        if(msg->wParam == 40)
        {
            explorer();
            return true;
        }
        if(msg->wParam == 50)
        {
            speach();
            return true;
        }
    }
    return false;
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
void TrayMacros::setLabel()
{
    QRadioButton *button = (QRadioButton*)sender();
    ui->l_skreen->setText(button->text() + "+");
}
void TrayMacros::closeEvent(QCloseEvent *e)
{
    QAction *closeEve = (QAction*)sender();
    if(closeEve == Close)
    {
        e->accept();
    }
    else
    {
        e->ignore();
        TrayMacros::hide();
    }
}

void TrayMacros::regKey()
{
    QString str = ui->l_skreen->text();
    int pos = str.lastIndexOf("+")+1;
    QChar ch = str.operator[](pos);
    ch = ch.toUpper();
    int d = ch.toLatin1();
    qDebug() << ch << " | " << d;


    if(ui->rb_player->isChecked() == true)
    {
        UnregisterHotKey((HWND)TrayMacros::winId(), 10);
        if(ui->rb_alt->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(),10, MOD_ALT, d);
        }
        else if(ui->rb_ctrl->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 10, MOD_CONTROL, d);
        }
        else if(ui->rb_shift->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 10, MOD_SHIFT, d);
        }
    }

    else if(ui->rb_browser->isChecked() == true)
    {
        UnregisterHotKey((HWND)TrayMacros::winId(), 20);
        if(ui->rb_alt->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 20, MOD_ALT, d);
        }
        else if(ui->rb_ctrl->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 20, MOD_CONTROL, d);
        }
        else if(ui->rb_shift->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 20, MOD_SHIFT, d);
        }
    }

    else if(ui->rb_search->isChecked() == true)
    {
        UnregisterHotKey((HWND)TrayMacros::winId(), 30);
        if(ui->rb_alt->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(),30, MOD_ALT, d);
        }
        else if(ui->rb_ctrl->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 30, MOD_CONTROL, d);
        }
        else if(ui->rb_shift->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 30, MOD_SHIFT, d);
        }
    }

    else if(ui->rb_explorer->isChecked() == true)
    {
        UnregisterHotKey((HWND)TrayMacros::winId(), 40);
        if(ui->rb_alt->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 40, MOD_ALT, d);
        }
        else if(ui->rb_ctrl->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 40, MOD_CONTROL, d);
        }
        else if(ui->rb_shift->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 40, MOD_SHIFT, d);
        }
    }
    else if(ui->rb_speaker->isChecked() == true)
    {
        UnregisterHotKey((HWND)TrayMacros::winId(), 50);
        if(ui->rb_alt->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 50, MOD_ALT, d);
        }
        else if(ui->rb_ctrl->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 50, MOD_CONTROL, d);
        }
        else if(ui->rb_shift->isChecked() == true)
        {
            RegisterHotKey((HWND)TrayMacros::winId(), 50, MOD_SHIFT, d);
        }
    }
}
