#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    pWindow = new MainWindow_Password();
    nWindow = new MainWindow_New();
    connect(pWindow, &MainWindow_Password::regwindow,this, &MainWindow::show);
    connect(nWindow, &MainWindow_New::regwindow,this, &MainWindow::show);
    this->setWindowTitle("Registration");
    this->setWindowIcon(QIcon(":/images/registration.png"));
    QPixmap regIcon(":/images/reg.png");
    int w = 100;
    int h = 100;
    ui->label_2->setPixmap(regIcon.scaled(w, h, Qt::KeepAspectRatio));
    btnCreate = ui->btnCreate;
    btnEnter=ui->btnEnter;
    Login=ui->Login;
    Email = ui->Email;
    Password = ui->Password;
    connect(btnCreate, &QPushButton::clicked, this, &MainWindow::Create);
    connect(btnEnter, &QPushButton::clicked, this, &MainWindow::Enter);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Enter(){
    QString login = Login->text();
    QString email = Email->text();
    int dog = 0;
    QString password = Password->text();
    if(login.length()>0&&email.length()>0 && password.length()>0){
        for(int i=0; i<email.length(); i++){
            if(email[i]=='@'){
                dog += 1;
            }
        }
         if(dog==1){
             nWindow->show();
             this->close();
         }
         else QMessageBox::critical(this, "Ошибка", "Введён неверный email");
    }
    else QMessageBox::warning(this, "Предупреждение", "Некоторые поля не заполнены");
}
void MainWindow::Create(){
    pWindow->show();
    this->close();

}


