#include "decoderwindow.h"
#include "ui_decoderwindow.h"

decoderWindow::decoderWindow(QWidget *parent,IDecoder* decoder) :
    QWidget(parent),decoder(decoder),
    ui(new Ui::decoderWindow)
{
    ui->setupUi(this);
    file=nullptr;
    ui->radioButton->setChecked(true);
    if(!decoder->need_alphabet()){
        ui->label_5->hide();
        ui->get_alphabet->hide();
    }
}

decoderWindow::~decoderWindow()
{
    delete ui;
}

void decoderWindow::on_pushButton_2_clicked()
{
    this->close();
    emit mainWind();
}

void decoderWindow::on_pushButton_3_clicked()
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

void decoderWindow::on_pushButton_clicked()
{
    QString str;
    QString str_binary;
    QString str_al;
    string str_after;
    string str_before;
    vector<pair<char,string>> al;
    if(ui->radioButton->isChecked()&&file){
        str=QString(file->readAll());

    }else if(ui->radioButton_2->isChecked()){
        str=ui->textEdit->toPlainText();
    }else{
        return;
    }
    if(decoder->need_alphabet()){
        str_al=ui->get_alphabet->toPlainText();
        al=make_alphabet(str_al.toStdString());
        if(al.empty()){
            ui->strAfter->setText("Необходимо ввести алфавит для кодируемого текста");
            return;
        }
        qDebug()<<"Алфавит сформирован";
    }
    str_before=str.toStdString();
    if(str.isEmpty()){
        ui->strBefore->setText("Строка пустая");
        return;
    }

    str_after=decoder_by_text(str_before,al);
    qDebug()<<"Строка раскодирована";
    ui->strBefore->setText(str);
    ui->strAfter->setText(QString(str_after.c_str()));
    ui->alphabet->setText(QString(Printer::write(al).c_str()));
    ui->strBinary->setText(Printer::write_binary(QString(str_after.c_str())));
}

vector<pair<char,string>> decoderWindow::make_alphabet(string str){
    vector<pair<char,string>> al;
    char a=' ';
    string code;
    for(auto it = str.begin();it<str.end();it++){
        if(*it=='\n') {
            continue;
        }
        while(*it!='-'){
            a=*it;
            it++;
        }
           it++;
        while(*it=='0'||*it=='1'){
            code+=*it;
            it++;
        }
        it--;
        if(!code.empty()){
        al.emplace_back(make_pair(a,code));
        }
        code.clear();
    }
    return al;
};

string decoderWindow::decoder_by_text(string str,vector<pair<char,string>>& al){
    al=decoder->decoding(str,al);
    string str_after=decoder->get_code();

    return str_after;
};

