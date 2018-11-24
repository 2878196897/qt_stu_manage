#ifndef ADDSTU_H
#define ADDSTU_H

#include <QWidget>
#include <QButtonGroup>
#include <QList>
#include <QAbstractButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>


#include <QDebug>


namespace Ui {
class addstu;
}

class addstu : public QWidget
{
    Q_OBJECT

public:
    explicit addstu(QWidget *parent = 0);
    ~addstu();
    void ClearAddstdInterface();
    int SaveStuInfomation(QString save_content);

private slots:
    void on_btn_ok_clicked();
//    void reciveclicksex(int sex_id);
    void on_btn_cancel_clicked();
    void on_lineEdit_stu_num_textChanged(const QString &arg1);


private:
    Ui::addstu *ui;
    QButtonGroup *stu_sex;
    QButtonGroup *stu_ins;
};

#endif // ADDSTU_H
