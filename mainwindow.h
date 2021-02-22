#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainwindow_password.h>
#include <mainwindow_new.h>
#include <QLabel>
#include <QPushButton>
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
    MainWindow_Password *pWindow;
    MainWindow_New *nWindow;
    QLineEdit *Login;
    QLineEdit *Email;
    QLineEdit *Password;
    QPushButton *btnCreate;
    QPushButton *btnEnter;
    QMenuBar *menubar;
    QMenu *aboutMenu;
    QMenu *helpMenu;
    QAction *programDeveloperAction;
    QAction *programVersionAction;
    QAction *programHelpAction;
    QAction *programExitAction;
    void createMenu();
    void createActions();

    void aboutDeveloper();
    void aboutProgramVersion();
    void Help();
    void Exit();

private slots:
    void Create();
    void Enter();
};
#endif // MAINWINDOW_H
