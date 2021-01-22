#include "Window_chat_problem.h"

Window_Chat_Problem::Window_Chat_Problem(QString name) : label(new QLabel(name)), layout(new QBoxLayout(QBoxLayout::Down))
{
    setLayout(layout);

    layout->addWidget(label);
}

Window_Chat_Problem::~Window_Chat_Problem()
{
    delete label;

    delete layout;
}

void Window_Chat_Problem::But_exit_chat_problem()
{

}
