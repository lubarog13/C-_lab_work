#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QMainWindow>
#include <QLabel>
#include <QtSql>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class AddStudent;
}

class AddStudent : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr);
    ~AddStudent();
signals:
    void regwindow();
private:
    Ui::AddStudent *ui;
    QPushButton *btnAdd;
    QPushButton *btnBack;
    QLineEdit *name;
    QLineEdit *surname;
    QLineEdit *second_name;
    QLineEdit *date_birth;
    QLineEdit *group;
private slots:
    void Add();
    void Back();
};

#endif // ADDSTUDENT_H
