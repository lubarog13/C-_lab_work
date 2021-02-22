#include "mainwindow_password.h"
#include "ui_mainwindow_password.h"
#include <QMessageBox>
#include <QDebug>

MainWindow_Password::MainWindow_Password(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Password)
{
    ui->setupUi(this);
    this->setWindowTitle("Восстановить пароль");
    this->setWindowIcon(QIcon(":/images/registration.png"));
    QPixmap forgetIcon(":/images/confusuon.png");
    int w = 100;
    int h = 100;
    ui->label_2->setPixmap(forgetIcon.scaled(w, h, Qt::KeepAspectRatio));
    btn_EnterP=ui->btn_EnterP;
    btn_Back=ui->btn_Back;
    EmailorL=ui->EmailorL;
    Code = ui->Code;
    connect(btn_EnterP, &QPushButton::clicked, this, &MainWindow_Password::Enter);
    connect(btn_Back, &QPushButton::clicked, this, &MainWindow_Password::Back);
}

MainWindow_Password::~MainWindow_Password()
{
    delete ui;
}
void MainWindow_Password::Enter(){
    QString email = EmailorL->text();
    QString code = Code->text();
    int dog = 0;
    if(email.length()>0&& code.length()>0){
        for(int i=0; i<email.length(); i++){
            if(email[i]=='@'){
                dog += 1;
            }
        }
         if(dog<=1){
            QMessageBox::information(this, "Успешно", "Ваш новый пароль: 12fgh67");
         }
         else QMessageBox::critical(this, "Ошибка", "Введён неверный email или логин");
    }
    else QMessageBox::warning(this, "Предупреждение", "Некоторые поля не заполнены");
}
void MainWindow_Password::Back(){
    this->close();
    emit regwindow();
}
