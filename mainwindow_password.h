#ifndef MAINWINDOW_PASSWORD_H
#define MAINWINDOW_PASSWORD_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QtSql>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_Password; }
QT_END_NAMESPACE

class MainWindow_Password : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_Password(QWidget *parent =nullptr);
    ~MainWindow_Password();

signals:
    void regwindow();

private:
    Ui::MainWindow_Password *ui;

    QLineEdit *EmailorL;
    QLineEdit *Code;
    QPushButton *btn_EnterP;
    QPushButton *btn_Back;
private slots:
    void Enter();
    void Back();
};

#endif // MAINWINDOW_PASSWORD_H
