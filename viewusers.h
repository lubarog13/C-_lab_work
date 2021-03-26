#ifndef VIEWUSERS_H
#define VIEWUSERS_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QtSql>
#include <QTableView>
#include <QPushButton>
#include <QLabel>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <adduser.h>

namespace Ui {
class viewUsers;
}

class viewUsers : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewUsers(QWidget *parent = nullptr);
    ~viewUsers();
signals:
    void regwindow();

private:
    Ui::viewUsers *ui;
    QLabel *label;
    QPushButton *btnBack;
    QPushButton *btnUpdate;
    AddUser *aWindow;
    QPushButton *btnChange;
    void Change();
private slots:
    void Back();
    void Update();
};

#endif // VIEWUSERS_H
