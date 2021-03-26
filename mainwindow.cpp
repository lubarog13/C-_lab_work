#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    QSqlQuery l_query;
    l_query.exec("CREATE TABLE IF NOT EXISTS users_new ("
               "user_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "user_login TEXT NOT NULL UNIQUE, "
               "user_email TEXT NOT NULL, "
               "user_password CHARACTER(64) NOT NULL)");
    l_query.exec("SELECT COUNT(*) FROM users WHERE user_login = hello");
    l_query.next();
    if (l_query.value(0).toInt() == 0) {
        l_query.exec(QStringLiteral("INSERT INTO users_new (user_login, user_email, user_password) VALUES ('hello', 'email@mail.com', '1234')"));
    }
    bool b = l_query.exec("CREATE TABLE IF NOT EXISTS students_new_tab ("
               "student_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "student_name TEXT NOT NULL, "
               "student_surname TEXT NOT NULL, "
                "student_second_name TEXT, "
                "student_date_birth INTEGER NOT NULL, "
               "student_group TEXT NOT NULL)");
    if (!b) {
    qDebug() << "Вроде не удается создать таблицу, провертье карманы!";
    }
    pWindow = new MainWindow_Password();
    nWindow = new MainWindow_New();
    connect(pWindow, &MainWindow_Password::regwindow,this, &MainWindow::show);
    connect(nWindow, &MainWindow_New::regwindow,this, &MainWindow::show);
    this->setWindowTitle("Registration");
    this->setWindowIcon(QIcon(":/images/main.png"));
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
    bool enter = false;
    QString password = Password->text();
    if(login.length()>0&&email.length()>0 && password.length()>0){
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
                if(login==db_login&&email==db_email&&password==db_password) enter=true;
                qDebug() <<db_id<<" "<<db_login<<" "<<db_email<<" "<<db_password;

            }

         if(enter){
             nWindow->show();
             this->close();
         }
         else QMessageBox::critical(this, "Ошибка", "Введёно что-то неверно");
    }
    else QMessageBox::warning(this, "Предупреждение", "Некоторые поля не заполнены");
}
void MainWindow::Create(){
    pWindow->show();
    this->close();

}


