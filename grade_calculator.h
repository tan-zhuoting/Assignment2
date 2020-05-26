#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class grade_calculator; }
QT_END_NAMESPACE

struct CourseData
{
    int hw1 = 0;
    int hw2 = 0;
    int hw3 = 0;
    int hw4 = 0;
    int hw5 = 0;
    int hw6 = 0;
    int hw7 = 0;
    int hw8 = 0;
    int midterm1 = 0;
    int midterm2 = 0;
    int finalexam = 0;
    int schema = 1;
    double overall = 0.0;
};

class grade_calculator : public QMainWindow
{
    Q_OBJECT

public:
    grade_calculator(QWidget *parent = nullptr);
    ~grade_calculator();

private slots:
    void on_course_comboBox_activated(int index);

private:
    Ui::grade_calculator *ui;

    QVector<CourseData> course_datas;
};
#endif // GRADE_CALCULATOR_H
