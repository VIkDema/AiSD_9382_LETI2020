#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    staticC=new coderWindow(nullptr,new CoderStaticHaffman());
    dynamicC=new coderWindow(nullptr,new CoderDynamicHuffman());
    connect(staticC,&coderWindow::mainWind,this,&MainWindow::show);
    connect(dynamicC,&coderWindow::mainWind,this,&MainWindow::show);
    staticD=new decoderWindow(nullptr,new DecoderStaticHuffman());
    dynamicD=new decoderWindow(nullptr,new DecoderDynamicHuffman());
    connect(staticD,&decoderWindow::mainWind,this,&MainWindow::show);
    connect(dynamicD,&decoderWindow::mainWind,this,&MainWindow::show);
    generatorWindow=new stringGenerator();
    connect(generatorWindow,&stringGenerator::mainWind,this,&MainWindow::show);
    stat = new Statistics();
    connect(stat,&Statistics::mainWind,this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    staticC->show();
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    dynamicC->show();
    this->close();
}

void MainWindow::on_pushButton_5_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    staticD->show();
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    dynamicD->show();
    this->close();
}

void MainWindow::on_pushButton_8_clicked()
{
   generatorWindow->show();
   this->close();
}

void MainWindow::on_pushButton_6_clicked()
{
    stat->show();
    this->close();
}
