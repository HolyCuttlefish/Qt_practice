#include "Window.h"

Window::Window() : layout(new QBoxLayout(QBoxLayout::Down)), but_login_server(new QPushButton("Логин сервера")), but_exit_server(new QPushButton("Выход из сервера")),
    but_login(new QPushButton("Вход")), line_host_server(new QLineEdit()), line_login_server(new QLineEdit()),
    line_password_server(new QLineEdit()), line_login(new QLineEdit()), line_password(new QLineEdit()), query(nullptr), chatWindow(nullptr)
{
    setWindowTitle("Авторизация");
    setFixedSize(500, 400);
    setLayout(layout);

    line_host_server->setPlaceholderText("Хост");
    line_login_server->setPlaceholderText("Логин");
    line_password_server->setPlaceholderText("Пароль сервера");

    line_login->setPlaceholderText("Логин");
    line_password->setPlaceholderText("Пароль");

    line_login->setEnabled(false);
    line_password->setEnabled(false);

    but_login->setEnabled(false);

    but_exit_server->setEnabled(false);

    line_password_server->setEchoMode(QLineEdit::EchoMode::Password);
    line_password->setEchoMode(QLineEdit::EchoMode::Password);

    layout->addWidget(line_host_server);
    layout->addWidget(line_login_server);
    layout->addWidget(line_password_server);

    layout->addWidget(but_login_server);
    layout->addWidget(but_exit_server);

    layout->addWidget(line_login);
    layout->addWidget(line_password);

    layout->addWidget(but_login);

    QObject::connect(but_login_server, SIGNAL(clicked()), this, SLOT(click_login_server()));
    QObject::connect(but_exit_server, SIGNAL(clicked()), this, SLOT(click_exit_server()));
    QObject::connect(but_login, SIGNAL(clicked()), this, SLOT(click_login()));
}

Window::~Window()
{
    delete but_login;

    delete but_login_server;
    delete but_exit_server;

    delete line_host_server;
    delete line_login_server;
    delete line_password_server;

    delete line_login;
    delete line_password;

    delete layout;

    if(query){ delete query; }

}

void Window::click_login_server()
{
    db = QSqlDatabase::addDatabase("QMYSQL", "conn");

    db.setHostName(line_host_server->text());
    db.setUserName(line_login_server->text());
    db.setPassword(line_password_server->text());
    db.setDatabaseName("Chat_Inform");

    if(db.open())
    {
        QMessageBox::warning(this, "Message", "Успех)");

        but_exit_server->setEnabled(true);

        but_login_server->setEnabled(false);

        but_login->setEnabled(true);

        line_login->setEnabled(true);
        line_password->setEnabled(true);

        line_host_server->setEnabled(false);
        line_login_server->setEnabled(false);
        line_password_server->setEnabled(false);

        query = new QSqlQuery(db);
    }
    else
    {
        db.close();

        QMessageBox::warning(this, "Message", "Неудача(");

        QSqlDatabase::removeDatabase("conn");
    }
}

void Window::click_exit_server()
{
    if(query)
    {
       delete query;
       query = nullptr;
    }

    db.close();

    QSqlDatabase::removeDatabase("conn");

    but_exit_server->setEnabled(false);
    but_login_server->setEnabled(true);

    but_login->setEnabled(false);

    line_login->setEnabled(false);
    line_password->setEnabled(false);

    line_host_server->setEnabled(true);
    line_login_server->setEnabled(true);
    line_password_server->setEnabled(true);
}

void Window::click_login()
{
    query->exec("select id from Accounts where user_name='" + line_login->text() + "' and password='" + line_password->text() + "'");

    if(query->next())
    {
        QMessageBox::warning(this, "Message", "Успех)");

        chatWindow = new Window_Chat_Problem(line_login->text());

        chatWindow->show();

        close();

        return;
    }
    else
    {
        QMessageBox::warning(this, "Message", "Неудача(");
    }

}
