#include <QString>
#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::grade_calculator)
{
    ui->setupUi(this);
    course_datas.resize(3);
}

grade_calculator::~grade_calculator()
{
    delete ui;
}


void grade_calculator::on_course_comboBox_activated(int index)
{
   ui->horizontalSlider->setValue(course_datas[index].hw1);
   ui->spinBox->setValue(course_datas[index].hw1);
   ui->horizontalSlider_2->setValue(course_datas[index].hw2);
   ui->spinBox_2->setValue(course_datas[index].hw2);
   ui->horizontalSlider_3->setValue(course_datas[index].hw3);
   ui->spinBox_3->setValue(course_datas[index].hw3);
   ui->horizontalSlider_4->setValue(course_datas[index].hw4);
   ui->spinBox_4->setValue(course_datas[index].hw4);
   ui->horizontalSlider_5->setValue(course_datas[index].hw5);
   ui->spinBox_5->setValue(course_datas[index].hw5);
   ui->horizontalSlider_6->setValue(course_datas[index].hw6);
   ui->spinBox_6->setValue(course_datas[index].hw6);
   ui->horizontalSlider_7->setValue(course_datas[index].hw7);
   ui->spinBox_7->setValue(course_datas[index].hw7);
   ui->horizontalSlider_8->setValue(course_datas[index].hw8);
   ui->spinBox_8->setValue(course_datas[index].hw8);
   ui->horizontalSlider_9->setValue(course_datas[index].midterm1);
   ui->spinBox_9->setValue(course_datas[index].midterm1);
   ui->horizontalSlider_10->setValue(course_datas[index].midterm2);
   ui->spinBox_10->setValue(course_datas[index].midterm2);
   ui->horizontalSlider_11->setValue(course_datas[index].finalexam);
   ui->spinBox_11->setValue(course_datas[index].finalexam);
   if (course_datas[index].schema == 1) {
       ui->radioButton->toggle();
   } else {
       ui->radioButton_2->toggle();
   }
   ui->label_14->setText(QString::number(course_datas[index].overall, 'g', 3));
}
