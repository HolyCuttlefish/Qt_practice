#ifndef WINDOW_CHAT_PROBLEM_H
#define WINDOW_CHAT_PROBLEM_H

#include <QWidget>
#include <QPushButton>

#include <QLabel>
#include <QBoxLayout>

class Window_Chat_Problem : public QWidget
{
public:
    Window_Chat_Problem(QString);
    ~Window_Chat_Problem();

private:
    //QPushButton *but_exit_chat;

    QLabel *label;

    QBoxLayout *layout;

private slots:
    void But_exit_chat_problem();
};

#endif // WINDOW_CHAT_PROBLEM_H
