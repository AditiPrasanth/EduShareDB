#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::add(float maths, float bio , float phy, float chem, float eng, float com)
{
    float sum = maths + bio + phy + chem + eng + com;
    return sum;
}

float MainWindow::cgpa()
{
    float maths =ui->doubleSpinBox->value();
    float bio =ui->doubleSpinBox_2->value();
    float phy =ui->doubleSpinBox_3->value();
    float chem =ui->doubleSpinBox_4->value();
    float eng =ui->doubleSpinBox_5->value();
    float com = ui->doubleSpinBox_6->value();
    float suma = add(maths , bio , phy , chem , eng , com);
    float gpa = (suma/6);

    qDebug()<< "GPA" << gpa ;
    return gpa;
}

void MainWindow::on_pushButton_clicked()
{
    float final = cgpa();
    QString stringgpa=QString::number(final);
    ui->lineEdit_3->setText(stringgpa);

}

void MainWindow::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit->text();
    QString regno = ui->lineEdit_2->text();
    QString dept = ui->comboBox->currentText();
    int age = ui->spinBox->value();
    QFile file("/Users/aditiprasanth/Downloads/Student_Details/details_db.txt");
    file.open(QIODevice::Append|QIODevice::Text);
    QTextStream out (&file);
    out<<"Name:"<<name<<"\n";
    out<<"Regno:"<<regno<<"\n";
    out<<"Department:"<<dept<<"\n";
    out<<"Age:"<<age<<"\n";
    float final = cgpa();
    out<<"cgpa:"<<final<<"\n";
    out<<"--------------------------------------------------------------------------------\n";
    ui->lineEdit_5->setText("successfully saved");
    file.close();

}

