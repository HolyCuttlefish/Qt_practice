#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QLineEdit>
#include <QBoxLayout>
#include <QMessageBox>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QDebug>

#include "Window_chat_problem.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
   ~Window();

private:
    QBoxLayout *layout;

    QPushButton *but_login_server;
    QPushButton *but_exit_server;
    QPushButton *but_login;

    QLineEdit *line_host_server;
    QLineEdit *line_login_server;
    QLineEdit *line_password_server;
    QLineEdit *line_login;
    QLineEdit *line_password;

    QSqlDatabase db;
    QSqlQuery *query;

    Window_Chat_Problem *chatWindow;

public slots:
    void click_login_server();
    void click_exit_server();
    void click_login();

};

#endif // WINDOW_H
