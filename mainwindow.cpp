#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db=new infobase();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_a1_black_clicked()
{
    /* chizaie ke check nakardam:
       kish
        win
        dasrasi kilid haie ke mitunan as shah kish shode mohafezat kunan */
    infobase::nameOfItem index=db->find(0,0);
    if((turn!=0&&index>7)||(turn!=1&&index<8))
    {
        QMessageBox*message=new QMessageBox();
        message->setText("white");
        message->show();
    }
    else
    {

        if(count_click==0)
        {
           if(db->find(row,column)!=infobase::none_of_them)
           {
               first_click->append(ui->a1_black);
               db->edit_list_to_go(0,0);
               count_click=1;
               row=0;
               column=0;

           }
        }
        else if(count_click==1)
        {
            if(db->search_in_list(row,column,0,0))
            {
                save s;
                s.present_position_r=row;
                s.present_position_c=column;
                s.prev_position_c=0;
                s.prev_position_r=0;
                db->qs.push_back(s);

                QIcon c;
                first_click->at(0)->setIcon(c);
                ui->a1_black->setIcon(db->get_icon(0,0));

                count_click=0;
                turn=1;
            }
            else
            {
                QMessageBox*message=new QMessageBox();
                message->setText("invalid button");
                message->show();
            }

        }
    }


}

void MainWindow::on_b1_white_clicked()
{

}

void MainWindow::on_c1_black_clicked()
{

}

void MainWindow::on_d1_white_clicked()
{

}

void MainWindow::on_e1_black_clicked()
{

}

void MainWindow::on_f1_white_clicked()
{

}

void MainWindow::on_g1_black_clicked()
{

}

void MainWindow::on_h1_white_clicked()
{

}

void MainWindow::on_a2_white_clicked()
{

}

void MainWindow::on_b2_black_clicked()
{

}

void MainWindow::on_c2_white_clicked()
{

}

void MainWindow::on_d2_black_clicked()
{

}

void MainWindow::on_e2_white_clicked()
{

}

void MainWindow::on_f2_black_clicked()
{

}

void MainWindow::on_g2_white_clicked()
{

}

void MainWindow::on_h2_black_clicked()
{

}

void MainWindow::on_a3_black_clicked()
{

}

void MainWindow::on_b3_white_clicked()
{

}

void MainWindow::on_c3_black_clicked()
{

}

void MainWindow::on_d3_white_clicked()
{

}

void MainWindow::on_e3_black_clicked()
{

}

void MainWindow::on_f3_white_clicked()
{

}

void MainWindow::on_g3_black_clicked()
{

}

void MainWindow::on_h3_white_clicked()
{

}

void MainWindow::on_a4_white_clicked()
{

}

void MainWindow::on_b4_black_clicked()
{

}

void MainWindow::on_c4_white_clicked()
{

}

void MainWindow::on_d4_black_clicked()
{

}

void MainWindow::on_e4_white_clicked()
{

}

void MainWindow::on_f4_black_clicked()
{

}

void MainWindow::on_g4_white_clicked()
{

}

void MainWindow::on_h4_black_clicked()
{

}

void MainWindow::on_a5_black_clicked()
{

}
