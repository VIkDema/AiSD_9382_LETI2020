#ifndef STRINGGENERATOR_H
#define STRINGGENERATOR_H

#include <QWidget>
#include <generator.h>

namespace Ui {
class stringGenerator;
}

class stringGenerator : public QWidget
{
    Q_OBJECT

public:
    explicit stringGenerator(QWidget *parent = nullptr);
    ~stringGenerator();
signals:
    void mainWind();

private slots:
    void on_pushButton_7_clicked();



    void on_pushButton_4_clicked();

private:
    Ui::stringGenerator *ui;
    generator* gen;
};

#endif // STRINGGENERATOR_H
