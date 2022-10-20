#include "mainwindow.h"
 #include "xlsxdocument.h"
#include"ui_mainwindow.h"
#include<QFileDialog>
#include<QDebug>
#include<QTableWidgetItem>
#include<QMessageBox>
#include<Qstring>
#include<QWidget>
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


void MainWindow::on_pushButton_clicked()
{

    QString strFile = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));
      if (strFile.isEmpty()){
          return;
      }
      else
      {
          ui->table->setColumnCount(4);//必须设定列数，不然没法显
          QVector<QString> arr;	//存储每一行数据
          QVector<QVector<QString>> array;	//将每行数据汇总，类似于二维数组，但不需要手动定义空间大小，造成内存浪费
          for (int row = 1; row <= 4; row++)
                  {
              int rowCount = ui->table->rowCount();
                      ui->table->insertRow(rowCount);
                      for (int col = 1; col <= 4; col++)
                      {

                          Document xlsxR(strFile);

                          QStringList sheetlist=xlsxR.sheetNames();
                          if(sheetlist.size()>0)
                          {
                              QString item=xlsxR.read(row,col).toString();
                              QTableWidgetItem * itemdata = new QTableWidgetItem(item);


                                ui->table->setItem(row-1,col-1,itemdata);


                              qDebug()<<item;

                          }
                          else
                          {
                              qDebug() << "[" << __FUNCTION__ <<__LINE__ << "] : read error!" ;

                          }
                      }

          }
          return ;


      }





}

