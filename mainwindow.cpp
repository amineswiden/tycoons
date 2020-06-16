#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "dialog.h"
#include "login.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_27_clicked()
{
    login l(ui->lineEdit_nom_3->text(),ui->lineEdit_pwd->text().toInt());
     if(l.authent()){

   Dialog d;
   d.exec();
     }
     else{

          QMessageBox::warning(this, tr("ERROR"), tr("incorrect .\n"));
     }


}
