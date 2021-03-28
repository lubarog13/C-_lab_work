#include "changeuser.h"
#include "ui_changeuser.h"

#include <QMessageBox>

changeUser::changeUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::changeUser)
{
    ui->setupUi(this);
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("users.db");
    if(!sdb.open()){
        qDebug() << sdb.lastError().text();
    }
    else{
        qDebug() <<"Success!";
    }
    ui->setupUi(this);
    this->setWindowTitle("Изменение пользователя");
    this->setWindowIcon(QIcon(":/images/main.png"));
    btnBack = ui->btnBack;
    btnOk = ui->btnOk;
    btnDelete=ui->btnDelete;
    id = ui->id;
    login = ui->login;
    email = ui->email;
    password = ui->password;
    connect(btnOk, &QPushButton::clicked, this, &changeUser::Change);
     connect(btnDelete, &QPushButton::clicked, this, &changeUser::Delete);
     connect(btnBack, &QPushButton::clicked, this, &changeUser::Back);

}

changeUser::~changeUser()
{
    delete ui;
}
void changeUser::Change(){
    QSqlQuery a_query;
    QString Id = id->text();
    QString Login = login->text();
    QString Email = email->text();
    QString Password = password->text();
    if(Id.length()>0&&Login.length()>0&&Email.length()>0&&Password.length()>0){

       QString str_update = "UPDATE users_new SET user_login = \"" + Login + "\", user_email = \"" + Email + "\", user_password = \"" + Password +"\" WHERE user_id = " + Id;
       bool b = a_query.exec(str_update);
        if(!b){
            QMessageBox::warning(this, "Ошибка", "Ошибка!\nЗаписи не существует");
        }
        else{
            QMessageBox::information(this, "Успешно", "Успешно изменено");
        }
    }
    else QMessageBox::warning(this, "Предупреждение", "Некоторые поля не заполнены");
}
void changeUser::Delete(){
    QSqlQuery a_query;
    QString Id = id->text();
    if(Id.length()>0){
        QString del_str= "DELETE FROM users_new WHERE user_id = " + Id;
        bool b = a_query.exec(del_str);
        if(!b) QMessageBox::warning(this, "Ошибка", "Ошибка!\nЗаписи не существует");
        else QMessageBox::information(this, "Успешно", "Успешно изменено");
    }
    else QMessageBox::warning(this, "Предупреждение", "id-то надо заполнить");
}
void changeUser::Back(){
    this->close();
    emit regwindow();
}
