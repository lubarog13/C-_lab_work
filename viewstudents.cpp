#include "viewstudents.h"
#include "ui_viewstudents.h"

viewStudents::viewStudents(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewStudents)
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
    cWindow = new class changeStudent();
    connect(cWindow, &changeStudent::regwindow, this, &changeStudent::show);
    this->setWindowTitle("Список студентов");
    this->setWindowIcon(QIcon(":/images/main.png"));
    btnBack = ui->btnBack;
    btnUpdate = ui->btnUpdate;
    btnChange=ui->btnChange;
    Update();
    connect(btnBack, &QPushButton::clicked, this, &viewStudents::Back);
    connect(btnUpdate, &QPushButton::clicked, this, &viewStudents::Update);
    connect(btnChange, &QPushButton::clicked, this, &viewStudents::Change);
}

viewStudents::~viewStudents()
{
    delete ui;
}
void viewStudents::Update(){
            QSqlQueryModel model;
            model.setQuery("SELECT * FROM students_new_tab");
            QString text1 = "ID\n";
            QString text2 ="Name\n";
            QString text3="Surname\n";
            QString text = "Second name\n";
            QString text4 = "Birth Date\n";
            QString text5 = "Group\n";
            for (int i = 0; i < model.rowCount(); ++i) {
                    text1 += model.record(i).value("student_id").toString() + "\n";
                    text2+= model.record(i).value("student_name").toString() + "\n";
                    text3+= model.record(i).value("student_surname").toString() + "\n";
                    text+= model.record(i).value("student_second_name").toString() + "\n";
                    int date_birth = model.record(i).value("student_date_birth").toInt();
                    text5+= model.record(i).value("student_group").toString() + "\n";
                    QDateTime valid = QDateTime::fromSecsSinceEpoch(date_birth);
                    text4+=valid.toString("dd-MM-yyyy") + "\n";

        }
            ui->label->setText(text1);
            ui->label_2->setText(text2);
            ui->label_3->setText(text3);
            ui->label_4->setText(text);
            ui->label_5->setText(text4);
            ui->label_6->setText(text5);

}
void viewStudents::Back(){
    this->close();
    emit regwindow();
}
void viewStudents::Change(){
    cWindow->show();
}
