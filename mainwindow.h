#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QWidget>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QIODevice>
#include <cmath>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class details;
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    float add(float maths, float bio , float phy, float chem, float eng, float com);
    float cgpa();
    void load();

};
#endif // MAINWINDOW_H
