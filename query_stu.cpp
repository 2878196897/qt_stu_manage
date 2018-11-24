#include "query_stu.h"
#include "ui_query_stu.h"

query_stu::query_stu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::query_stu)
{
    ui->setupUi(this);
    if(ReadStuInformation()==-1)
    {
        QMessageBox::critical(this,"","文件打开失败，请重试！");
        close();
    }
}

query_stu::~query_stu()
{
    delete ui;
}

int query_stu::ReadStuInformation()
{
    QFile file("StuInfo.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        stu_info.append(line);
    }
    return 0;
}

void query_stu::DoQuery(int query_way_index,QString content)
{
    for(int i=0;i<stu_info.count();i++)
    {
        QStringList stu_info_split = stu_info.at(i).split(' ');
        switch(query_way_index)
        {
        case QUERY_NAME:
            if(stu_info_split.at(QUERY_NAME)==content)
                DisplayQueryResult(stu_info_split);
                break;
        case QUERY_ID:
            if(stu_info_split.at(QUERY_ID)==content)
                DisplayQueryResult(stu_info_split);
            break;
        case QUERY_COLLEGE:
            if(stu_info_split.at(QUERY_COLLEGE)==content)
                DisplayQueryResult(stu_info_split);
            break;
        default:
            break;
        }
    }
}

void query_stu::DisplayQueryResult(QStringList stu_info_split)
{
    //ui->tableView_show_stu_info->;
    qDebug() << stu_info_split;
}


//槽函数
void query_stu::on_btn_search_clicked()
{
    int query_way_index = ui->cbb_query_way->currentIndex();
    QString query_content = ui->lineEdit_query_content->text();
    DoQuery(query_way_index,query_content);
}

