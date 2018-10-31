#ifndef START_PAGE_H
#define START_PAGE_H

#include <QWidget>

namespace Ui {
class start_page;
}

class start_page : public QWidget
{
    Q_OBJECT

public:
    explicit start_page(QWidget *parent = 0);
    ~start_page();

private slots:
    void on_white_button_clicked();

    void on_black_button_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

signals:
    void pass_data1(QString,int);
    void pass_data2(QString,int);
    void pass_message(QString);

private:
    Ui::start_page *ui;
};

#endif // START_PAGE_H
