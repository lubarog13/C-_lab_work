#ifndef ADDUSER_H
#define ADDUSER_H

#include <QMainWindow>
#include <QLabel>
#include <QtSql>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class AddUser;
}

class AddUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = nullptr);
    ~AddUser();
signals:
    void regwindow();

private:
    Ui::AddUser *ui;
    QPushButton *btnOk;
    QPushButton *btnBack;
    QLineEdit *login;
    QLineEdit *email;
    QLineEdit *password;
    QLineEdit *password_new;
private slots:
    void Add();
    void Back();
};

#endif // ADDUSER_H
