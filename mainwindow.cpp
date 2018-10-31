
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s=new start_page();
    s->show();
    db=new infobase();



    list_of_position=new QList<QToolButton*>;
    //braye enkeh dasresi hengameh bazgasht be aghab dashteh bashim
    list_of_position->push_back(ui->a1_black);
    list_of_position->push_back(ui->b1_white);
    list_of_position->push_back(ui->c1_black);
    list_of_position->push_back(ui->d1_white);
    list_of_position->push_back(ui->e1_black);
    list_of_position->push_back(ui->f1_white);
    list_of_position->push_back(ui->g1_black);
    list_of_position->push_back(ui->h1_white);

    list_of_position->push_back(ui->a2_white);
    list_of_position->push_back(ui->b2_black);
    list_of_position->push_back(ui->c2_white);
    list_of_position->push_back(ui->d2_black);
    list_of_position->push_back(ui->e2_white);
    list_of_position->push_back(ui->f2_black);
    list_of_position->push_back(ui->g2_white);
    list_of_position->push_back(ui->h2_black);

    list_of_position->push_back(ui->a3_black);
    list_of_position->push_back(ui->b3_white);
    list_of_position->push_back(ui->c3_black);
    list_of_position->push_back(ui->d3_white);
    list_of_position->push_back(ui->e3_black);
    list_of_position->push_back(ui->f3_white);
    list_of_position->push_back(ui->g3_black);
    list_of_position->push_back(ui->h3_white);

    list_of_position->push_back(ui->a4_white);
    list_of_position->push_back(ui->b4_black);
    list_of_position->push_back(ui->c4_white);
    list_of_position->push_back(ui->d4_black);
    list_of_position->push_back(ui->e4_white);
    list_of_position->push_back(ui->f4_black);
    list_of_position->push_back(ui->g4_white);
    list_of_position->push_back(ui->h4_black);

    list_of_position->push_back(ui->a5_black);
    list_of_position->push_back(ui->b5_white);
    list_of_position->push_back(ui->c5_black);
    list_of_position->push_back(ui->d5_white);
    list_of_position->push_back(ui->e5_black);
    list_of_position->push_back(ui->f5_white);
    list_of_position->push_back(ui->g5_black);
    list_of_position->push_back(ui->h5_white);

    list_of_position->push_back(ui->a6_white);
    list_of_position->push_back(ui->b6_black);
    list_of_position->push_back(ui->c6_white);
    list_of_position->push_back(ui->d6_black);
    list_of_position->push_back(ui->e6_white);
    list_of_position->push_back(ui->f6_black);
    list_of_position->push_back(ui->g6_white);
    list_of_position->push_back(ui->h6_black);

    list_of_position->push_back(ui->a7_black);
    list_of_position->push_back(ui->b7_white);
    list_of_position->push_back(ui->c7_black);
    list_of_position->push_back(ui->d7_white);
    list_of_position->push_back(ui->e7_black);
    list_of_position->push_back(ui->f7_white);
    list_of_position->push_back(ui->g7_black);
    list_of_position->push_back(ui->h7_white);

    list_of_position->push_back(ui->a8_white);
    list_of_position->push_back(ui->b8_black);
    list_of_position->push_back(ui->c8_white);
    list_of_position->push_back(ui->d8_black);
    list_of_position->push_back(ui->e8_white);
    list_of_position->push_back(ui->f8_black);
    list_of_position->push_back(ui->g8_white);
    list_of_position->push_back(ui->h8_black);
//



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::EndGame(int bOrW)
{
    QMessageBox* eg = new QMessageBox ();

    if(bOrW == 0)
    {
       QString player1 = ui->player1->text();
         eg->setText(player1+"Winned");
    }
    else
    {
        QString player2 = ui->player2->text();
          eg->setText(player2+"Winned");
    }

    eg->show();
    this->close();
}

void MainWindow::checkChess(int borw)
{
    //agar shah kish shod rang kaneh shah taghir konad va agar user tavajohi be kish shodan shah nakonad payan bazi e'lam shavad

    if(db->threat_king(borw)== true)
    {
        check_count+=1;

        if(check_count == 2)
        {
            EndGame(borw);
        }

       QMessageBox* qm= new QMessageBox();

       qm->setText("Your King has been threated!");
       qm->show();


    }
}

void MainWindow::what_to_do(int r_positon, int  c_position)
{
    change_label_color();
    if(check_count==1&&db->threat_king(turn))
        checkChess(turn);
    else if(check_count==1&&!(db->threat_king(turn)))
        check_count=0;

    infobase::nameOfItem index=db->find(r_positon,c_position);
    if(index!=infobase::none_of_them)
    {
    if((turn!=0&&index>7)||(turn!=1&&index<8))
    {
        QMessageBox*message=new QMessageBox();
        message->setText("it isn't your turn");
        message->show();
    }
    else
    {

        if(count_click==0)
        {
           if(db->find(row,column)!=infobase::none_of_them)
           {
               //list_of_position->append(ui->a1_black);
               db->edit_list_to_go(r_positon,c_position);
               count_click=1;
               row=r_positon;
               column=c_position;

           }
        }
        else if(count_click==1)
        {
            int sil=db->search_in_list(row,column,r_positon,c_position);
            if(sil==1)
            {
                save s;
                s.present_position_r=row;
                s.present_position_c=column;
                s.prev_position_c=r_positon;
                s.prev_position_r=c_position;
                db->qs.push_back(s);

                QIcon c;
                list_of_position->at(row*8+column)->setIcon(c);
                ui->a1_black->setIcon(db->get_icon(r_positon,c_position));
                if(db->find(r_positon,c_position)!=infobase::none_of_them)
                {
                    db->delete_a_piece(r_positon,c_position);
                }

                count_click=0;

                if(turn==1) turn=0;
                else if(turn==0) turn=1;

                if(db->win(0)==true)
                    EndGame(0);
                else if(db->win(1)== true)
                    EndGame(1);
                if(db->threat_king(turn))
                    checkChess(turn);
            }
            else if(sil==0)
            {
                QMessageBox*message=new QMessageBox();
                message->setText("invalid button");
                message->show();
            }
            else if(sil==-1)
            {
                QMessageBox*message=new QMessageBox();
                message->setText(" mohreh  nemituneh harikat koneh mohre ye digiee ro entekhab konid ");
                message->show();
                count_click=0;
            }

        }
    }
    }

}

void MainWindow::on_a1_black_clicked()
{
    what_to_do(0,0);
}

void MainWindow::on_b1_white_clicked()
{
    what_to_do(0,1);
}

void MainWindow::on_c1_black_clicked()
{
    what_to_do(0,2);
}

void MainWindow::on_d1_white_clicked()
{
    what_to_do(0,3);
}

void MainWindow::on_e1_black_clicked()
{
    what_to_do(0,4);
}

void MainWindow::on_f1_white_clicked()
{
    what_to_do(0,5);
}

void MainWindow::on_g1_black_clicked()
{
    what_to_do(0,6);
}

void MainWindow::on_h1_white_clicked()
{
    what_to_do(0,7);
}

void MainWindow::on_a2_white_clicked()
{
    what_to_do(1,0);
}

void MainWindow::on_b2_black_clicked()
{
    what_to_do(1,1);
}

void MainWindow::on_c2_white_clicked()
{
    what_to_do(1,2);
}

void MainWindow::on_d2_black_clicked()
{
    what_to_do(1,3);
}

void MainWindow::on_e2_white_clicked()
{
    what_to_do(1,4);
}

void MainWindow::on_f2_black_clicked()
{
    what_to_do(1,5);
}

void MainWindow::on_g2_white_clicked()
{
    what_to_do(1,6);
}

void MainWindow::on_h2_black_clicked()
{
    what_to_do(1,7);
}

void MainWindow::on_a3_black_clicked()
{
    what_to_do(2,0);
}

void MainWindow::on_b3_white_clicked()
{
    what_to_do(2,1);
}

void MainWindow::on_c3_black_clicked()
{
    what_to_do(2,2);
}

void MainWindow::on_d3_white_clicked()
{
    what_to_do(2,3);
}

void MainWindow::on_e3_black_clicked()
{
    what_to_do(2,4);
}

void MainWindow::on_f3_white_clicked()
{
    what_to_do(2,5);
}

void MainWindow::on_g3_black_clicked()
{
    what_to_do(2,6);
}

void MainWindow::on_h3_white_clicked()
{
    what_to_do(2,7);
}

void MainWindow::on_a4_white_clicked()
{
    what_to_do(3,0);
}

void MainWindow::on_b4_black_clicked()
{
    what_to_do(3,1);
}

void MainWindow::on_c4_white_clicked()
{
    what_to_do(3,2);
}

void MainWindow::on_d4_black_clicked()
{
    what_to_do(3,3);
}

void MainWindow::on_e4_white_clicked()
{
    what_to_do(3,4);
}

void MainWindow::on_f4_black_clicked()
{
    what_to_do(3,5);
}

void MainWindow::on_g4_white_clicked()
{
    what_to_do(3,6);
}

void MainWindow::on_h4_black_clicked()
{
    what_to_do(3,7);
}

void MainWindow::on_a5_black_clicked()
{
    what_to_do(4,0);
}


void MainWindow::on_b5_white_clicked()
{
    what_to_do(4,1);
}

void MainWindow::on_c5_black_clicked()
{
    what_to_do(4,2);
}

void MainWindow::on_d5_white_clicked()
{
    what_to_do(4,3);
}

void MainWindow::on_e5_black_clicked()
{
    what_to_do(4,4);
}

void MainWindow::on_f5_white_clicked()
{
    what_to_do(4,5);
}

void MainWindow::on_g5_black_clicked()
{
    what_to_do(4,6);
}

void MainWindow::on_h5_white_clicked()
{
    what_to_do(4,7);
}

void MainWindow::on_a6_white_clicked()
{
    what_to_do(5,0);
}

void MainWindow::on_b6_black_clicked()
{
    what_to_do(5,1);
}

void MainWindow::on_c6_white_clicked()
{
    what_to_do(5,2);
}

void MainWindow::on_d6_black_clicked()
{
    what_to_do(5,3);
}

void MainWindow::on_e6_white_clicked()
{
    what_to_do(5,4);
}

void MainWindow::on_f6_black_clicked()
{
    what_to_do(5,5);
}

void MainWindow::on_g6_white_clicked()
{
    what_to_do(5,6);
}

void MainWindow::on_h6_black_clicked()
{
    what_to_do(5,7);
}

void MainWindow::on_a7_black_clicked()
{
    what_to_do(6,0);
}

void MainWindow::on_b7_white_clicked()
{
    what_to_do(6,1);
}

void MainWindow::on_c7_black_clicked()
{
    what_to_do(6,2);
}

void MainWindow::on_d7_white_clicked()
{
    what_to_do(6,3);
}

void MainWindow::on_e7_black_clicked()
{
    what_to_do(6,4);
}

void MainWindow::on_f7_white_clicked()
{
    what_to_do(6,5);
}

void MainWindow::on_g7_black_clicked()
{
    what_to_do(6,6);
}

void MainWindow::on_h7_white_clicked()
{
    what_to_do(6,7);
}

void MainWindow::on_a8_white_clicked()
{
    what_to_do(7,0);
}

void MainWindow::on_b8_black_clicked()
{
    what_to_do(7,1);
}

void MainWindow::on_c8_white_clicked()
{
    what_to_do(7,2);
}

void MainWindow::on_d8_black_clicked()
{
    what_to_do(7,3);
}

void MainWindow::on_e8_white_clicked()
{
    what_to_do(7,4);
}

void MainWindow::on_f8_black_clicked()
{
    what_to_do(7,5);
}

void MainWindow::on_g8_white_clicked()
{
    what_to_do(7,6);
}

void MainWindow::on_h8_black_clicked()
{
    what_to_do(7,7);
}
void MainWindow::on_Back_clicked()
{

}
void MainWindow::change_label_color()
{
    if(turn==0)
    {
        ui->player1->setStyleSheet("background-color:green");
    }
    else
    {
        ui->player2->setStyleSheet("background-color:green");
    }
}

