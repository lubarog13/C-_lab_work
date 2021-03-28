#ifndef CHANGESTUDENT_H
#define CHANGESTUDENT_H

#include <QMainWindow>
#include <QLabel>
#include <QtSql>
#include <QPushButton>
#include <QLineEdit>


namespace Ui {
class changeStudent;
}

class changeStudent : public QMainWindow
{
    Q_OBJECT

public:
    explicit changeStudent(QWidget *parent = nullptr);
    ~changeStudent();
signals:
    void regwindow();

private:
    Ui::changeStudent *ui;
    QPushButton *btnAdd;
    QPushButton *btnBack;
    QPushButton *btnDelete;
    QLineEdit *id;
    QLineEdit *name;
    QLineEdit *surname;
    QLineEdit *second_name;
    QLineEdit *date_birth;
    QLineEdit *group;
private slots:
    void Change();
    void Back();
    void Delete();
};

#endif // CHANGESTUDENT_H
