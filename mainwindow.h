#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"infobase.h"
#include <QMainWindow>
#include<QList>
#include<QToolButton>
#include<QMessageBox>
#include<QIcon>
#include"start_page.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    start_page *s;
    infobase * db;
    int turn=0;  //0=white   1=black
    int count_click=0;//0=the peice want to move   1=where
    //postion kelid aval ke count_click==0
    int row=-1;
    int column=-1;
    //
    QList<QToolButton*>* list_of_position;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int check_count_b=0;
    int check_count_w=0;

    void EndGame(int bOrW);

    void checkChess(int);

    void what_to_do(int,int);

    bool win();

private slots:
    void get_name_player1(QString name,int borw);

    void get_name_player2(QString name,int borw);

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

    void on_Back_clicked();

    void change_label_color();

    void on_b5_white_clicked();

    void on_c5_black_clicked();

    void on_d5_white_clicked();

    void on_e5_black_clicked();

    void on_f5_white_clicked();

    void on_g5_black_clicked();

    void on_h5_white_clicked();

    void on_a6_white_clicked();

    void on_b6_black_clicked();

    void on_c6_white_clicked();

    void on_d6_black_clicked();

    void on_e6_white_clicked();

    void on_f6_black_clicked();

    void on_g6_white_clicked();

    void on_h6_black_clicked();

    void on_a7_black_clicked();

    void on_b7_white_clicked();

    void on_c7_black_clicked();

    void on_d7_white_clicked();

    void on_e7_black_clicked();

    void on_f7_white_clicked();

    void on_g7_black_clicked();

    void on_h7_white_clicked();

    void on_a8_white_clicked();

    void on_b8_black_clicked();

    void on_c8_white_clicked();

    void on_d8_black_clicked();

    void on_e8_white_clicked();

    void on_f8_black_clicked();

    void on_g8_white_clicked();

    void on_h8_black_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
