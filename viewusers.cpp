#include "viewusers.h"
#include "ui_viewusers.h"
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
viewUsers::viewUsers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewUsers)
{
    ui->setupUi(this);
    aWindow = new class changeUser();
    connect(aWindow, &changeUser::regwindow, this, &changeUser::show);
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("users.db");
    if(!sdb.open()){
        qDebug() << sdb.lastError().text();
    }
    else{
        qDebug() <<"Success!";
    }
    this->setWindowTitle("Список пользователей");
    this->setWindowIcon(QIcon(":/images/main.png"));
    btnBack = ui->btnBack;
    btnChange=ui->btnChange;
    btnUpdate = ui->btnUpdate;
    Update();
    connect(btnChange, &QPushButton::clicked, this, &viewUsers::Change);
    connect(btnBack, &QPushButton::clicked, this, &viewUsers::Back);
    connect(btnUpdate, &QPushButton::clicked, this, &viewUsers::Update);

}
viewUsers::~viewUsers()
{
    delete ui;
}

void viewUsers::Back(){
    this->close();
    emit regwindow();
}
void viewUsers::Update(){
    QSqlQueryModel model;
    model.setQuery("SELECT * FROM users_new");
    label = ui->label_3;
    QString text1 = "ID\n";
    QString text2 ="Login\n";
    QString text3="Email\n";
    for (int i = 0; i < model.rowCount(); ++i) {
            text1+= model.record(i).value("user_id").toString() + "\n";
            text2+=model.record(i).value("user_login").toString() + "\n";
            text3+= model.record(i).value("user_email").toString() +"\n";
}
    label->setText(text2);
    ui->label_5->setText(text1);
    ui->label_4->setText(text3);

}

void viewUsers::Change(){
    aWindow->show();
}

