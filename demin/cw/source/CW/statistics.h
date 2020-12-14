#ifndef STATISTICS_H
#define STATISTICS_H

#include <QWidget>
#include <QDate>
#include <QTime>
#include <iostream>
#include "tester.h"
#include <QProgressDialog>
#include <QDebug>
using namespace std;

namespace Ui {
class Statistics;
}

class Statistics : public QWidget
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();
signals:
    void mainWind();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    void update();
    void clearFile();
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
