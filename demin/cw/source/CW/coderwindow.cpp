#include "coderwindow.h"

#include "ui_coderwindow.h"

coderWindow::coderWindow(QWidget *parent,ICoder* coder) :
    QWidget(parent),coder(coder),
    ui(new Ui::coderWindow)
{
    ui->setupUi(this);
    file=nullptr;
    ui->radioButton->setChecked(true);
}

coderWindow::~coderWindow()
{
    file->close();
    delete file;
    delete ui;
}

void coderWindow::on_pushButton_2_clicked()
{
    this->close();
    emit mainWind();
}

void coderWindow::on_pushButton_3_clicked()
{
    this->path = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    if(path!=""){
        delete this->file;
        this->file=new QFile(path);

        file->open(QIODevice::ReadOnly);

        if(file->isOpen()){
            ui->nameFile->setText("Файл выбран: "+path);
        }else{
            ui->nameFile->setText("Файл не открылся: "+path);
        }
    }
}

void coderWindow::on_pushButton_clicked()
{
    QString str;
    QString str_binary;
    string str_after;
    string str_before;
    if(ui->radioButton->isChecked()&&file){
        str=QString(file->readAll());
    }else if(ui->radioButton_2->isChecked()){
        str=ui->textEdit->toPlainText();
    }else{
        return;
    }
    str_before=str.toStdString();
    if(str.isEmpty()){
        ui->strBefore->setText("Строка пустая");
        return;
    }
    ui->strBefore->setText(str);

    str_after=coder_by_text(str_before);
    ui->strAfter->setText(QString(str_after.c_str()));

    ui->strBinary->setText(Printer::write_binary(str));
}

string coderWindow::coder_by_text(string& str_before){
    //засечь время и записать его
    vector<pair<char,string>> al;
    al=coder->coding(str_before);
    string str= coder->get_code();
    ui->alphabet->setText(QString(Printer::write(al).c_str()));
    return str;
};
