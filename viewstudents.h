#ifndef VIEWSTUDENTS_H
#define VIEWSTUDENTS_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QtSql>
#include <QTableView>
#include <QPushButton>
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
    QPushButton *btnBack;
    QPushButton *btnUpdate;
private slots:
    void Back();
    void Update();
};

#endif // VIEWSTUDENTS_H
