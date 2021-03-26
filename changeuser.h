#ifndef CHANGEUSER_H
#define CHANGEUSER_H

#include <QMainWindow>
#include <QMainWindow>
#include <QLabel>
#include <QtSql>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class changeUser;
}

class changeUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit changeUser(QWidget *parent = nullptr);
    ~changeUser();
signals:
    void regwindow();
private:
    Ui::changeUser *ui;
    QPushButton *btnOk;
    QPushButton *btnBack;
    QPushButton *btnDelete;
    QLineEdit *id;
    QLineEdit *login;
    QLineEdit *email;
    QLineEdit *password;
private slots:
    void Change();
    void Delete();
    void Back();
};

#endif // CHANGEUSER_H
