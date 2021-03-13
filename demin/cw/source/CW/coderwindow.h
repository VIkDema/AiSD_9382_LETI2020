#ifndef CODERWINDOW_H
#define CODERWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include "ICoder.h"
#include "printer.h"

namespace Ui {
class coderWindow;
}

class coderWindow : public QWidget
{
    Q_OBJECT

public:
    explicit coderWindow(QWidget *parent = nullptr,ICoder* coder=nullptr);
    ~coderWindow();
    string coder_by_text(string& str_before);

signals:
    void mainWind();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    ICoder* coder;
    QFile* file;
    Ui::coderWindow *ui;
    QString path;
};

#endif // CODERWINDOW_H
