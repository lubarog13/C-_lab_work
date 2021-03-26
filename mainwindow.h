#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainwindow_password.h>
#include <mainwindow_new.h>

#include <QLabel>
#include <QPushButton>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QLineEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlDatabase users;
    MainWindow_Password *pWindow;
    MainWindow_New *nWindow;
    QLineEdit *Login;
    QLineEdit *Email;
    QLineEdit *Password;
    QPushButton *btnCreate;
    QPushButton *btnEnter;


private slots:
    void Create();
    void Enter();
};
#endif // MAINWINDOW_H
