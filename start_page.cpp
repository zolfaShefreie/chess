#include "start_page.h"
#include "ui_start_page.h"

start_page::start_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start_page)
{
    ui->setupUi(this);
}

start_page::~start_page()
{
    delete ui;
}

void start_page::on_white_button_clicked()
{
    ui->lbl1->setText("YOU WILL PLAY AS WHITE");
    ui->lbl2->setText("YOU WILL PLAY AS BLACK");
}

void start_page::on_black_button_clicked()
{
    ui->lbl2->setText("YOU WILL PLAY AS WHITE");
    ui->lbl1->setText("YOU WILL PLAY AS BLACK");
}

void start_page::on_pushButton_clicked()
{
    QString st1=ui->lineEdit->text();
    int cn1;
    if(ui->lbl1->text()=="YOU WILL PLAY AS WHITE") cn1=0;
    else cn1=1;
    emit pass_data1(st1,cn1);
}

void start_page::on_pushButton_2_clicked()
{
    QString st2=ui->lineEdit_2->text();
    int cn2;
    if(ui->lbl2->text()=="YOU WILL PLAY AS WHITE") cn2=0;
    else cn2=1;
    emit pass_data2(st2,cn2);
}

void start_page::on_pushButton_3_clicked()
{
    QString st3="QUIT THE GAME";
    emit pass_message(st3);
    this->close();
}
