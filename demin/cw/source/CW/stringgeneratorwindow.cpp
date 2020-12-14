#include "stringgeneratorwindow.h"
#include "ui_stringgeneratorwindow.h"

stringGenerator::stringGenerator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stringGenerator)
{
    ui->setupUi(this);
    gen=new generator();
}

stringGenerator::~stringGenerator()
{
    delete ui;
}

void stringGenerator::on_pushButton_7_clicked()
{
    this->close();
    emit mainWind();
}

void stringGenerator::on_pushButton_4_clicked()
{
    string str= gen->generatorStr(gen->randnum(1,1000));
    ui->textEdit_8->setText(QString(str.c_str()));
}
