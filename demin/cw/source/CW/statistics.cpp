#include "statistics.h"
#include "ui_statistics.h"



std::vector<std::string> split_string(const std::string &s) {
    std::vector<std::string> elems;
    string str;
    int i=0;
    for(int j=0;j<4;j++){
        while(s[i]!=' '&&s[i]!='\n'){
            str+=s[i];
            i++;
        }
        i++;
        elems.push_back(str);
        str="";
    }
    return elems;
}


Statistics::Statistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);
    QString str="Собрано данных("+QDate::currentDate().toString()+"-"+QTime::currentTime().toString()+" )";
    ui->data->setText(str);
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::on_pushButton_clicked()
{
    this->close();
    emit mainWind();
}

void Statistics::on_pushButton_3_clicked()
{
    QProgressDialog win;
    win.setWindowTitle("Ожидайте!");
    win.show();
    Tester a;
    a.startTest(ui->spinBox->value());
    win.close();
    QString str="Собрано данных("+QDate::currentDate().toString()+"-"+QTime::currentTime().toString()+" )";
    ui->data->setText(str);
}
void Statistics::clearFile(){
    FileLog* dsh=new FileLog("decodersh.txt");
    FileLog* csh=new FileLog("codersh.txt");
    FileLog* ddh=new FileLog("decoderdh.txt");
    FileLog* cdh=new FileLog("coderdh.txt");
    dsh->clear();
    csh->clear();
    ddh->clear();
    cdh->clear();
    delete dsh;
    delete ddh;
    delete csh;
    delete cdh;

}


void Statistics::on_pushButton_4_clicked()
{
    clearFile();
}
void Statistics::update(){
    FileLog* csh=new FileLog("codersh.txt");
    string str;
    QVector<double> size_before;
    QVector<double> size_after;
    QVector<double> size_al;
    QVector<double> time;
    str=csh->read();
    while(!str.empty()){
        str=csh->read();
        if(str.empty()){
            break;
        }
        try{
            vector<string> a = split_string(str);
            if(a.size()==4){
                int f=stoi(a[0])/8;
                int b=stoi(a[1])/8;
                int c=stoi(a[2]);
                int d=stoi(a[3]);
                size_before.push_back(f);
                size_after.push_back(b);
                size_al.push_back(c);
                time.push_back(d);
            }}
        catch(...){
            break;
        }
    }
    FileLog* cdh=new FileLog("coderdh.txt");
     str="";
    QVector<double> size_before2;
    QVector<double> size_after2;
    QVector<double> size_al2;
    QVector<double> time2;
    str=cdh->read();
    while(!str.empty()){
        str=cdh->read();
        if(str.empty()){
            break;
        }
        try{
            vector<string> a = split_string(str);
            if(a.size()==4){
                int f=stoi(a[0])/8;
                int b=stoi(a[1])/8;
                int c=stoi(a[2]);
                int d=stoi(a[3]);
                size_before2.push_back(f);
                size_after2.push_back(b);
                size_al2.push_back(c);
                time2.push_back(d);
            }}
        catch(...){
            break;
        }
    }

    FileLog* dsh=new FileLog("decodersh.txt");
     str="";
    QVector<double> size_before3;
    QVector<double> size_after3;
    QVector<double> size_al3;
    QVector<double> time3;
    str=dsh->read();
    while(!str.empty()){
        str=dsh->read();
        if(str.empty()){
            break;
        }
        try{
            vector<string> a = split_string(str);
            if(a.size()==4){
                int f=stoi(a[0])/8;
                int b=stoi(a[1]);
                int c=stoi(a[2]);
                int d=stoi(a[3]);
                size_before3.push_back(f);
                size_after3.push_back(b);
                size_al3.push_back(c);
                time3.push_back(d);
            }}
        catch(...){
            break;
        }
    }

    FileLog* ddh=new FileLog("decoderdh.txt");
    QVector<double> size_before4;
    QVector<double> size_after4;
    QVector<double> size_al4;
    QVector<double> time4;
    str=ddh->read();
    while(!str.empty()){
        str=ddh->read();
        if(str.empty()){
            break;
        }
        try{
            vector<string> a = split_string(str);
            if(a.size()==4){
                int f=stoi(a[0])/8;
                int b=stoi(a[1]);
                int c=stoi(a[2]);
                int d=stoi(a[3]);
                size_before4.push_back(f);
                size_after4.push_back(b);
                size_al4.push_back(c);
                time4.push_back(d);
            }}
        catch(...){
            break;
        }
    }

    {
    ui->widget->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->widget->graph(0)->setData(size_before,time);
    ui->widget->graph(1)->setData(size_before2,time2);
    ui->widget->graph(1)->setPen(QColor(Qt::red));
    ui->widget->graph(2)->setData(size_before3,time2);
      ui->widget->graph(2)->setPen(QColor(Qt::green));
    ui->widget->graph(3)->setData(size_before3,time2);
      ui->widget->graph(3)->setPen(QColor(Qt::yellow));



    ui->widget->xAxis->setLabel("Количество символов");
    ui->widget->yAxis->setLabel("Время кодирования в миллисекундах");



    double minY =0, maxY = time[0];
        for (int i=1; i<time.size(); i++)
        {
            if (time2[i]>maxY) maxY = time2[i];
            if (time3[i]>maxY) maxY = time3[i];
            if (time4[i]>maxY) maxY = time4[i];
        }
        double minX = 0, maxX = size_before[0];
            for (int i=1; i<size_before.size(); i++)
            {
                if (size_before[i]>maxX) maxX = size_before[i];
            }
     ui->widget->yAxis->setRange(minY, maxY);
     ui->widget->xAxis->setRange(minX, maxX);
     ui->widget->replot();
}
QVector<double> k1;
QVector<double> k2;
for(int i =0;i<size_before.size()&&i<size_before.size();i++){
    k1.push_back((size_after[i]/size_before[i]));
    k2.push_back(size_after2[i]/(size_before2[i]));
}
ui->widget_2->clearGraphs();//Если нужно, но очищаем все графики
//Добавляем один график в widget
ui->widget_2->addGraph();
ui->widget_2->addGraph();

//Говорим, что отрисовать нужно график по нашим двум массивам x и y
ui->widget_2->graph(0)->setData(size_before,k1);
ui->widget_2->graph(1)->setData(size_before2,k2);
ui->widget_2->graph(1)->setPen(QColor(Qt::red));

ui->widget_2->xAxis->setLabel("Количество символов");
ui->widget_2->yAxis->setLabel("Эффективность сжатия");

double minY =0, maxY = k1[0];
    for (int i=1; i<k1.size(); i++)
    {
        if (k1[i]>maxY) maxY = k1[i];
        if (k2[i]>maxY) maxY = k2[i];

    }
double minX = 0, maxX = size_before[0];
    for (int i=1; i<size_before2.size(); i++)
    {
        if (size_before2[i]>maxX) maxX = size_before2[i];
        if (size_before[i]>maxX) maxX = size_before[i];
    }
 ui->widget_2->yAxis->setRange(minY, maxY);
 ui->widget_2->xAxis->setRange(minX, maxX);
 ui->widget_2->replot();
    delete csh;
}


void Statistics::on_pushButton_2_clicked()
{
    update();
}
