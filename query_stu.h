#ifndef QUERY_STU_H
#define QUERY_STU_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


#include <QDebug>


namespace Ui {
class query_stu;
}

class query_stu : public QDialog
{
    Q_OBJECT

public:
    enum STU_QUERY_WEY
    {
        QUERY_NAME,
        QUERY_ID,
        QUERY_COLLEGE
    };

    explicit query_stu(QWidget *parent = 0);
    ~query_stu();
    int ReadStuInformation();
    void DoQuery(int query_way_index,QString content);
    void DisplayQueryResult(QStringList stu_info_split);



private slots:
    void on_btn_search_clicked();

private:
    Ui::query_stu *ui;
    QList<QString> stu_info;
};

#endif // QUERY_STU_H
