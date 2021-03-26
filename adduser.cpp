#include "adduser.h"
#include "ui_adduser.h"
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>


AddUser::AddUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddUser)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("users.db");
    if(!sdb.open()){
        qDebug() << sdb.lastError().text();
    }
    else{
        qDebug() <<"Success!";
    }
    ui->setupUi(this);
    this->setWindowTitle("Добавление пользователя");
    this->setWindowIcon(QIcon(":/images/main.png"));
    btnOk=ui->btnOk;
    btnBack=ui->btnBack;
    login=ui->login;
    email=ui->email;
    password=ui->password;
    password_new=ui->password_new;
    connect(btnOk, &QPushButton::clicked, this, &AddUser::Add);
    connect(btnBack, &QPushButton::clicked, this, &AddUser::Back);
}

AddUser::~AddUser()
{
    delete ui;
}
void AddUser::Add(){
    QSqlQuery a_query;
    QString Login = login->text();
    QString Email = email->text();
    QString Password = password->text();
    QString Pass_new = password_new->text();
    if(Login.length()>0&&Email.length()>0 && Password.length()>0 &&Password==Pass_new){
        QString str_insert = "INSERT INTO users_new (user_login, user_email, user_password) VALUES ('%1', '%2', '%3')";
        QString str = str_insert.arg(Login)
                .arg(Email)
                .arg(Password);
        bool b = a_query.exec(str);
        if (!b) {
        QMessageBox::warning(this, "Ошибка", "Ошибка!\nПроверьте поля");
        }
        else QMessageBox::information(this, "Успешно", "Успешно добавлено");

    }
    else QMessageBox::warning(this, "Предупреждение", "Некоторые поля не заполнены или пароль не верен");
}
void AddUser::Back(){
    this->close();
    emit regwindow();
}
