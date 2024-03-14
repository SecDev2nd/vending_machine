#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

#define COFFEE 100
#define TEA 500
#define TANG 1000

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    checkEnalbe();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::checkEnalbe(){
    ui->pbReset->setEnabled(money>0);
    ui->pbTang->setEnabled(money >= TANG );
    ui->pbTea->setEnabled(money >= TEA);
    ui->pbCoffee->setEnabled(money >= COFFEE);
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    checkEnalbe();
}

void calcChange(){

}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);

}


void Widget::on_pbTea_clicked()
{
    changeMoney(-500);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-1000);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int won[4] = {500,100,50,10};
    int changeCnt[4] = {0,0,0,0};
    int tmp = money;
    for(int i=0; i<4; i++){
        changeCnt[i] = tmp/won[i];
        tmp %= won[i];
    }

    // 결과를 메시지 박스에 표시
    QString result = QString("500원: %1개\n100원: %2개\n50원: %3개\n10원: %4개")
                         .arg(changeCnt[0])
                         .arg(changeCnt[1])
                         .arg(changeCnt[2])
                         .arg(changeCnt[3]);

    mb.information(nullptr, "title", result);

    changeMoney(-money);
}

