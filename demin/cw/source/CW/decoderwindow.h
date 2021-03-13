#ifndef DECODERWINDOW_H
#define DECODERWINDOW_H

#include <QWidget>
#include <QFile>
#include "IDecoder.h"
#include <QFileDialog>
#include "printer.h"
#include <QDebug>

namespace Ui {
class decoderWindow;
}

class decoderWindow : public QWidget
{
    Q_OBJECT

public:
    explicit decoderWindow(QWidget *parent = nullptr,IDecoder* decoder=nullptr);
    ~decoderWindow();

signals:
    void mainWind();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    vector<pair<char,string>> make_alphabet(string str);
    string decoder_by_text(string str,vector<pair<char,string>>& al );
    IDecoder* decoder;
    QFile* file;
    QString path;
    Ui::decoderWindow *ui;
};

#endif // DECODERWINDOW_H
