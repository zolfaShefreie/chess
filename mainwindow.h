#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"infobase.h"
#include <QMainWindow>
#include<QList>
#include<QToolButton>
#include<QMessageBox>
#include<QIcon>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    infobase * db;
    int turn=0;//0=white   1=black
    int count_click=0;//0=the peice want to move   1=where
    //postion kelid aval ke count_click==0
    int row;
    int column;
    //
    QList<QToolButton*>* first_click;//mohre e ke enekhab shode harikat kuneh ro zakhireh mikuneh
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_a1_black_clicked();

    void on_b1_white_clicked();

    void on_c1_black_clicked();

    void on_d1_white_clicked();

    void on_e1_black_clicked();

    void on_f1_white_clicked();

    void on_g1_black_clicked();

    void on_h1_white_clicked();

    void on_a2_white_clicked();

    void on_b2_black_clicked();

    void on_c2_white_clicked();

    void on_d2_black_clicked();

    void on_e2_white_clicked();

    void on_f2_black_clicked();

    void on_g2_white_clicked();

    void on_h2_black_clicked();

    void on_a3_black_clicked();

    void on_b3_white_clicked();

    void on_c3_black_clicked();

    void on_d3_white_clicked();

    void on_e3_black_clicked();

    void on_f3_white_clicked();

    void on_g3_black_clicked();

    void on_h3_white_clicked();

    void on_a4_white_clicked();

    void on_b4_black_clicked();

    void on_c4_white_clicked();

    void on_d4_black_clicked();

    void on_e4_white_clicked();

    void on_f4_black_clicked();

    void on_g4_white_clicked();

    void on_h4_black_clicked();

    void on_a5_black_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
