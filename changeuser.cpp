#include "changeuser.h"
#include "ui_changeuser.h"

changeUser::changeUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::changeUser)
{
    ui->setupUi(this);
    btnBack = ui->btnBack;
    btnOk = ui->btnOk;
    btnDelete=ui->btnDelete;
    id = ui->id;
    login = ui->login;
    email = ui->email;
    password = ui->password;


}

changeUser::~changeUser()
{
    delete ui;
}
void changeUser::Change(){}
void changeUser::Delete(){}
void changeUser::Back(){}
