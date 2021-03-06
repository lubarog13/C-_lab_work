#ifndef MAINWINDOW_NEW_H
#define MAINWINDOW_NEW_H

#include <QMainWindow>
#include <addstudent.h>
#include <adduser.h>
#include <viewstudents.h>
#include <viewusers.h>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class MainWindow_New;
}

class MainWindow_New : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_New(QWidget *parent = nullptr);
    ~MainWindow_New();
signals:
    void regwindow();
private:
    Ui::MainWindow_New *ui;
    AddStudent *asWindow;
    AddUser *adWindow;
    viewStudents *vsWindow;
    viewUsers *vuWindow;
    QPushButton *btnStudents;
    QPushButton *btnUsers;
    QPushButton *btnExit;
    QPushButton *btnAddStudent;
    QPushButton *btnAddUser;
private slots:
    void Students();
    void Users();
    void Exit();
    void AddStudent();
    void AddUser();
};

#endif // MAINWINDOW_NEW_H
