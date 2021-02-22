#include "mainwindow_new.h"
#include "ui_mainwindow_new.h"

MainWindow_New::MainWindow_New(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_New)
{
    ui->setupUi(this);
    this->setWindowTitle("Учебное заведение");
    this->setWindowIcon(QIcon(":/images/registration.png"));
    btnStudents = ui->btnStudents;
    btnUsers = ui->btnUsers;
    btnExit = ui->btnExit;
    btnAddStudent = ui->btnAddStudent;
    btnAddUser = ui->btnAddUser;
    QPixmap welcomeIcon(":/images/welcome.png");
    int w = 100;
    int h = 100;
    ui->label_2->setPixmap(welcomeIcon.scaled(w, h, Qt::KeepAspectRatio));
    connect(btnStudents, &QPushButton::clicked, this, &MainWindow_New::Students);
    connect(btnUsers, &QPushButton::clicked, this, &MainWindow_New::Users);
    connect(btnExit, &QPushButton::clicked, this, &MainWindow_New::Exit);
    connect(btnAddStudent, &QPushButton::clicked, this, &MainWindow_New::AddStudent);
    connect(btnAddUser, &QPushButton::clicked, this, &MainWindow_New::AddUser);

}


MainWindow_New::~MainWindow_New()
{
    delete ui;
}
void MainWindow_New::Students(){

}
void MainWindow_New::Users(){

}
void MainWindow_New::AddStudent(){

}
void MainWindow_New::AddUser(){

}
void MainWindow_New::Exit(){
    this->close();
    emit regwindow();
}
