#include "mainwindow_password.h"
#include "ui_mainwindow_password.h"
#include <QMessageBox>
#include <QDebug>

MainWindow_Password::MainWindow_Password(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Password)
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
    this->setWindowTitle("Восстановить пароль");
    this->setWindowIcon(QIcon(":/images/main.png"));
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
    bool enter=false;
    if(email.length()>0&& code.length()>0){
        QSqlQuery a_query;
            // DDL query
            //.....
            if (!a_query.exec("SELECT * FROM users_new")) {
                qDebug() << "Даже селект не получается, я пас.";
            }
            QSqlRecord rec = a_query.record();
            int db_id=0;
            QString db_login = "", db_email="", db_password="";

            while (a_query.next()) {
                db_id = a_query.value(rec.indexOf("user_id")).toInt();
                db_login = a_query.value(rec.indexOf("user_login")).toString();
                db_email = a_query.value(rec.indexOf("user_email")).toString();
                db_password= a_query.value(rec.indexOf("user_password")).toString();
                if((email==db_login||email==db_email)&&code=="Xorpass"){
                    enter=true;
                    QMessageBox::information(this, "Восстановление пароля", "Ваш пароль:" + db_password);
                qDebug() <<db_id<<" "<<db_login<<" "<<db_email<<" "<<db_password;

            }
            }
            if(!enter) QMessageBox::warning(this, "Предупреждение", "Что-то заполнено неверно");
     }
    else QMessageBox::warning(this, "Предупреждение", "Некоторые поля не заполнены");
}
void MainWindow_Password::Back(){
    this->close();
    emit regwindow();
}
