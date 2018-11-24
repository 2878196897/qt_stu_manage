#include "addstu.h"
#include "ui_addstu.h"


addstu::addstu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addstu)
{
    ui->setupUi(this);
    //性别按钮分组
    stu_sex = new QButtonGroup(this);
    stu_sex->addButton(ui->rbt_male,0);
    stu_sex->addButton(ui->rbt_female,1);
    //connect(stu_sex,SIGNAL(buttonClicked(int)),this,SLOT(reciveclicksex(int)));
    //兴趣按钮分组
    stu_ins = new QButtonGroup(this);
    stu_ins->addButton(ui->cb_soccer,0);
    stu_ins->addButton(ui->cb_table_tennis,1);
    stu_ins->addButton(ui->cb_basket,2);
    stu_ins->addButton(ui->cb_badminton,3);
    stu_ins->setExclusive(false);

}

addstu::~addstu()
{
    delete stu_sex;
    delete stu_ins;
    delete ui;
}

void addstu::on_btn_ok_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString id = ui->lineEdit_stu_num->text();
    QString sex = stu_sex->checkedButton()->text();
    QString ins;
    QList<QAbstractButton *> ins_list = stu_ins->buttons();

    for(int i=0;i < ins_list.length();i++)
    {
        QAbstractButton * cur_ins = ins_list.at(i);
        if(cur_ins->isChecked())
        {
            ins+=cur_ins->text()+" ";
        }
    }
    ins.chop(1);
    QString age = ui->cbb_age->currentText();
    QString college = ui->cbb_college->currentText();
    QString display_content = name + "\n" + id + "\n" + sex + "\n" + age + "\n" + college + "\n" + ins;
    QString save_content = name + " " + id + " " + sex + " " + age + " " + college + " " + ins + "\n";

    if(name.length()<1)
    {
       QMessageBox::critical(this,"信息错误","姓名未填写","确定");
    }
    else if(id.length()<10)
    {
        QMessageBox::critical(this,"信息错误","学号小于10位","确定");
    }
    else
    {
        int ret = QMessageBox::question(this,"是否保存",display_content,"确定","取消");
        if(ret==0)
        {
            ClearAddstdInterface();
            if(SaveStuInfomation(save_content)==-1)
                QMessageBox::critical(this,"错误","保存失败，请重试！");
        }
    }
//    qDebug() << name << id << sex;
}


//void addstu::reciveclicksex(int sex_id)
//{
//   qDebug()<<"reciveclicksex()";
//}

void addstu::ClearAddstdInterface()
{
   ui->lineEdit_name->clear();
   ui->lineEdit_stu_num->clear();
   ui->rbt_male->setChecked(true);
   ui->cbb_age->setCurrentIndex(0);
   ui->cbb_college->setCurrentIndex(0);
   QList<QAbstractButton *> ins_list = stu_ins->buttons();
   for(int i=0;i<ins_list.length();i++)
   {
       ins_list.at(i)->setChecked(false);
   }
   ui->label_id_format_tips->setText("");
   ui->lineEdit_name->setFocus();
}

int addstu::SaveStuInfomation(QString save_content)
{
    QFile file("StuInfo.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        return -1;
    }
    QTextStream out(&file);
    out << save_content;
    file.close();
    return 0;
}


void addstu::on_btn_cancel_clicked()
{
    close();
}

void addstu::on_lineEdit_stu_num_textChanged(const QString &arg1)
{
    if(ui->lineEdit_stu_num->text().length()<10)
    {
        ui->label_id_format_tips->setText("学号小于10位！");
        ui->label_id_format_tips->setStyleSheet("color:rgb(255,0,0)");
    }
    else
    {
        ui->label_id_format_tips->setText("格式正确");
        ui->label_id_format_tips->setStyleSheet("color:rgb(0,170,0)");
    }
}

