#include "changestudent.h"
#include "ui_changestudent.h"

#include <qmessagebox.h>

changeStudent::changeStudent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::changeStudent)
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
    this->setWindowTitle("Изменение студента");
    this->setWindowIcon(QIcon(":/images/main.png"));
    btnAdd=ui->btnAdd;
    btnBack=ui->btnBack;
    btnDelete=ui->btnDelete;
    name = ui->name;
    id= ui->id;
    surname=ui->surname;
    second_name=ui->second_name;
    date_birth=ui->birth_date;
    group=ui->group;
    connect(btnAdd, &QPushButton::clicked, this, &changeStudent::Change);
    connect(btnBack, &QPushButton::clicked, this, &changeStudent::Back);
    connect(btnDelete, &QPushButton::clicked, this, &changeStudent::Delete);
}

changeStudent::~changeStudent()
{
    delete ui;
}
void changeStudent::Change(){
    QSqlQuery a_query;
    QString Id = id->text();
    QString Name = name->text();
    QString Surname = surname->text();
    QString Second_name = second_name->text();
    QString birth_date = date_birth->text();
    QString Group = group->text();
    QDateTime valid;

    QString format = "dd-MM-yyyy";
    valid = QDateTime::fromString(birth_date, format);
    qDebug()<<valid;
    if (valid.toSecsSinceEpoch()==-10800) {
        QMessageBox::warning(this, "Предупреждение", "Проверьте дату");
    }
    else if(Id.length() && Name.length()>0&&Surname.length()>0&&birth_date.length()>0&&Group.length()>0){

        QString str_update = "UPDATE students_new_tab SET student_name = \"" + Name + "\", student_surname = \""
        + Surname + "\", student_second_name = \"" + Second_name +"\", student_date_birth = " + QString::number(valid.toSecsSinceEpoch())+", student_group = \"" + Group + "\" WHERE student_id = " + Id;
        bool b = a_query.exec(str_update);
        if (!b) {
        QMessageBox::warning(this, "Ошибка", "Ошибка!\nПроверьте поля");
        }
        else QMessageBox::information(this, "Успешно", "Успешно изменено");
    }
    else QMessageBox::warning(this, "Предупреждение", "Некоторые поля не заполнены");
}
void changeStudent::Delete(){
    QSqlQuery a_query;
    QString Id = id->text();
    if(Id.length()>0){
        QString del_str= "DELETE FROM students_new_tab WHERE student_id = " + Id;
        bool b = a_query.exec(del_str);
        if(!b) QMessageBox::warning(this, "Ошибка", "Ошибка!\nЗаписи не существует");
        else QMessageBox::information(this, "Успешно", "Успешно изменено");
    }
    else QMessageBox::warning(this, "Предупреждение", "id-то надо заполнить");
}
void changeStudent::Back(){
    this->close();
    emit regwindow();
}
