#ifndef VIEWSTUDENTS_H
#define VIEWSTUDENTS_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QtSql>
#include <QTableView>
#include <QPushButton>

#include <changestudent.h>
#include <QLabel>

namespace Ui {
class viewStudents;
}

class viewStudents : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewStudents(QWidget *parent = nullptr);
    ~viewStudents();
signals:
    void regwindow();

private:
    Ui::viewStudents *ui;
    changeStudent *cWindow;
    QPushButton *btnBack;
    QPushButton *btnUpdate;
    QPushButton *btnChange;
private slots:
    void Change();
    void Back();
    void Update();
};

#endif // VIEWSTUDENTS_H
