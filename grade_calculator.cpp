#include <QString>
#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::grade_calculator)
{
    ui->setupUi(this);
    course_datas.resize(3);
    QObject::connect(this, SIGNAL(compute_overall()), this, SLOT(update_overall()));
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::update_overall()
{
    CourseData& data = course_datas[ui->course_comboBox->currentIndex()];
    data.overall = 0.0;
    double min_grade = data.hw[0];

    for (int i = 0; i < 8; i++) {
        if (data.hw[i] < min_grade) {
            min_grade = data.hw[i];
        }
        data.overall += data.hw[i];
    }
    data.overall -= min_grade;
    data.overall /= 7;
    data.overall *= 0.25;
    if (data.schema == 1) {
        data.overall += 0.2 * data.midterm1;
        data.overall += 0.2 * data.midterm2;
        data.overall += 0.35 * data.finalexam;
    } else {
        data.overall += 0.3 * (data.midterm1 > data.midterm2 ? data.midterm1 : data.midterm2);
        data.overall += 0.44 * data.finalexam;
    }
    ui->label_14->setText(QString::number(data.overall, 'g', 3));
}


void grade_calculator::on_course_comboBox_activated(int index)
{
   ui->horizontalSlider->setValue(course_datas[index].hw[0]);
   ui->spinBox->setValue(course_datas[index].hw[0]);
   ui->horizontalSlider_2->setValue(course_datas[index].hw[1]);
   ui->spinBox_2->setValue(course_datas[index].hw[1]);
   ui->horizontalSlider_3->setValue(course_datas[index].hw[2]);
   ui->spinBox_3->setValue(course_datas[index].hw[2]);
   ui->horizontalSlider_4->setValue(course_datas[index].hw[3]);
   ui->spinBox_4->setValue(course_datas[index].hw[3]);
   ui->horizontalSlider_5->setValue(course_datas[index].hw[4]);
   ui->spinBox_5->setValue(course_datas[index].hw[4]);
   ui->horizontalSlider_6->setValue(course_datas[index].hw[5]);
   ui->spinBox_6->setValue(course_datas[index].hw[5]);
   ui->horizontalSlider_7->setValue(course_datas[index].hw[6]);
   ui->spinBox_7->setValue(course_datas[index].hw[6]);
   ui->horizontalSlider_8->setValue(course_datas[index].hw[7]);
   ui->spinBox_8->setValue(course_datas[index].hw[7]);
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

void grade_calculator::on_horizontalSlider_sliderMoved(int position)
{
    ui->spinBox->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].hw[0] = position;
    emit compute_overall();
}

void grade_calculator::on_horizontalSlider_2_sliderMoved(int position)
{
    ui->spinBox_2->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].hw[1] = position;
    emit compute_overall();
}

void grade_calculator::on_horizontalSlider_3_sliderMoved(int position)
{
    ui->spinBox_3->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].hw[2] = position;
    emit compute_overall();
}

void grade_calculator::on_horizontalSlider_4_sliderMoved(int position)
{
    ui->spinBox_4->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].hw[3] = position;
    emit compute_overall();
}

void grade_calculator::on_horizontalSlider_5_sliderMoved(int position)
{
    ui->spinBox_5->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].hw[4] = position;
    emit compute_overall();
}

void grade_calculator::on_horizontalSlider_6_sliderMoved(int position)
{
    ui->spinBox_6->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].hw[5] = position;
    emit compute_overall();
}

void grade_calculator::on_horizontalSlider_7_sliderMoved(int position)
{
    ui->spinBox_7->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].hw[6] = position;
    emit compute_overall();
}

void grade_calculator::on_horizontalSlider_8_sliderMoved(int position)
{
    ui->spinBox_8->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].hw[7] = position;
    emit compute_overall();
}

void grade_calculator::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].hw[0] = arg1;
    emit compute_overall();
}

void grade_calculator::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].hw[1] = arg1;
    emit compute_overall();
}

void grade_calculator::on_spinBox_3_valueChanged(int arg1)
{
    ui->horizontalSlider_3->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].hw[2] = arg1;
    emit compute_overall();
}

void grade_calculator::on_spinBox_4_valueChanged(int arg1)
{
    ui->horizontalSlider_4->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].hw[3] = arg1;
    emit compute_overall();
}

void grade_calculator::on_spinBox_5_valueChanged(int arg1)
{
    ui->horizontalSlider_5->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].hw[4] = arg1;
    emit compute_overall();
}

void grade_calculator::on_spinBox_6_valueChanged(int arg1)
{
    ui->horizontalSlider_6->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].hw[5] = arg1;
    emit compute_overall();
}

void grade_calculator::on_spinBox_7_valueChanged(int arg1)
{
    ui->horizontalSlider_7->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].hw[6] = arg1;
    emit compute_overall();
}

void grade_calculator::on_spinBox_8_valueChanged(int arg1)
{
    ui->horizontalSlider_8->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].hw[7] = arg1;
    emit compute_overall();
}

void grade_calculator::on_horizontalSlider_9_sliderMoved(int position)
{
    ui->spinBox_9->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].midterm1 = position;
    emit compute_overall();
}


void grade_calculator::on_horizontalSlider_10_sliderMoved(int position)
{
    ui->spinBox_10->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].midterm2 = position;
    emit compute_overall();
}

void grade_calculator::on_horizontalSlider_11_sliderMoved(int position)
{
    ui->spinBox_11->setValue(position);
    course_datas[ui->course_comboBox->currentIndex()].finalexam = position;
    emit compute_overall();
}

void grade_calculator::on_spinBox_9_valueChanged(int arg1)
{
    ui->horizontalSlider_9->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].midterm1 = arg1;
    emit compute_overall();
}

void grade_calculator::on_spinBox_10_valueChanged(int arg1)
{
    ui->horizontalSlider_10->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].midterm2 = arg1;
    emit compute_overall();
}

void grade_calculator::on_spinBox_11_valueChanged(int arg1)
{
    ui->horizontalSlider_11->setValue(arg1);
    course_datas[ui->course_comboBox->currentIndex()].finalexam = arg1;
    emit compute_overall();
}

void grade_calculator::on_radioButton_toggled(bool checked)
{
    if (checked) {
        course_datas[ui->course_comboBox->currentIndex()].schema = 1;
        emit compute_overall();
    }
}

void grade_calculator::on_radioButton_2_toggled(bool checked)
{
    if (checked) {
        course_datas[ui->course_comboBox->currentIndex()].schema = 2;
        emit compute_overall();
    }
}
