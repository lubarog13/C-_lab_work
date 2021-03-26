#include "addstudent.h"
#include "ui_addstudent.h"
#include "time.h"
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>

AddStudent::AddStudent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddStudent)
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
    this->setWindowTitle("Добавление студента");
    this->setWindowIcon(QIcon(":/images/main.png"));
    btnAdd = ui->btnAdd;
    btnBack = ui->btnBack;
    name = ui->name;
    surname = ui->surname;
    second_name = ui->second_name;
    date_birth = ui->birth_date;
    group = ui->group;
    QPixmap addIcon(":/images/add.png");
    int w = 100;
    int h = 100;
    ui->label_7->setPixmap(addIcon.scaled(w, h, Qt::KeepAspectRatio));
    connect(btnAdd, &QPushButton::clicked, this, &AddStudent::Add);
    connect(btnBack, &QPushButton::clicked, this, &AddStudent::Back);
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::Add(){
    QSqlQuery a_query;
    QString Name = name->text();
    QString Surname = surname->text();
    QString Second_name = second_name->text();
    QString Birth_Date = date_birth->text();
    QString Group = group->text();
    QDateTime valid;

    QString format = "dd-MM-yyyy";
    valid = QDateTime::fromString(Birth_Date, format);
    if (valid.toSecsSinceEpoch()==-10800) {
        QMessageBox::warning(this, "Предупреждение", "Проверьте дату");
    }
    else if(Name.length()>0&&Surname.length()>0&&Birth_Date.length()>0&&Group.length()>0){
        QString str_insert = "INSERT INTO students_new_tab(student_name, student_surname, student_second_name, student_date_birth, student_group) "
        "VALUES ('%1', '%2', '%3', %4, '%5');";
        QString str = str_insert.arg(Name)
        .arg(Surname)
        .arg(Second_name)
        .arg(valid.toSecsSinceEpoch())
        .arg(Group);
        bool b = a_query.exec(str);
       qDebug()<<valid.toSecsSinceEpoch();
        if (!b) {
        QMessageBox::warning(this, "Ошибка", "Ошибка!\nПроверьте поля");
        }
        else QMessageBox::information(this, "Успешно", "Успешно добавлено");
    }
    else QMessageBox::warning(this, "Предупреждение", "Некоторые поля не заполнены");
}
void AddStudent::Back(){
    this->close();
    emit regwindow();
}
