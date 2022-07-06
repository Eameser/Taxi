#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QDebug>
#include <QString>
#include <order.h>
#include <QLineEdit>
#include <QRegExp>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

//static pcl::num_list entries;

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

void MainWindow::on_orderButton_clicked()
{
    QString num = ui->lineEdit_number->text();

    QString place = ui->lineEdit_place->text();

    if ((num!="") || (place!="")){

       ui->tableWidget->insertRow(ui->tableWidget->rowCount());
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(num));
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(place));


       QMessageBox:: about(this, "новое окно", "Вы успешно заказали такси!");

}}

void MainWindow::on_pushButton_clicked()
{
    QString Number = ui->lineEdit_number->text();
    QString Place = ui->lineEdit_place->text();
    QString Automobile = ui->comboBox->currentText();

    if (Number.isEmpty() || Place.isEmpty() || Automobile.isEmpty())
    {
        QMessageBox:: about(this, "Ошибка!", "Заполните все поля о заказе!");
    }
    else
    {
    order *order1 = new order(Number,Place,Automobile);
    this->order_vector.push_back(order1);

    QString buffer;
    buffer.setNum(counter +1);
    rows.push_back(buffer);

    ui->tableWidget->insertRow(counter);
    ui->tableWidget->setVerticalHeaderLabels(rows);

    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(order_vector[static_cast<unsigned int>(counter)]->getNumber());
    ui->tableWidget->setItem(counter, 0 , item);

    QTableWidgetItem *item1 = new QTableWidgetItem();
    item1->setText(order_vector[static_cast<unsigned int>(counter)]->getPlace());
    ui->tableWidget->setItem(counter, 1 , item1);

    QTableWidgetItem *item2 = new QTableWidgetItem();
    item2->setText(order_vector[static_cast<unsigned int>(counter)]->getCar());
    ui->tableWidget->setItem(counter, 2 , item2);

    QMessageBox:: about(this, "Заказ", "Вы успешно заказали такси!");

    ui->lineEdit_place->clear();
    ui->lineEdit_number->clear();
    counter++;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton x = QMessageBox::question(this, "новое окно" ,"Вы действительно хотите отменить заказ?",
                          QMessageBox::Yes|QMessageBox::No);
    if (x == QMessageBox::No){

    } else {
        QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
           while (!selectedRows.empty()) {

               ui->tableWidget->removeRow(selectedRows[0].row());
               selectedRows = ui->tableWidget->selectionModel()->selectedRows();
           }
    }
}

//void MainWindow::on_pushButton_3_clicked()
//{
//    QMessageBox::StandardButton x = QMessageBox::question(this, "новое окно" ,"Вы действительно хотите отредактировать этот заказ?",
//                          QMessageBox::Yes|QMessageBox::No);
//    if (x == QMessageBox::No){

//    } else{
//    int selectedItemsCount = ui->tableWidget->selectedItems().count();
//        for(int itemNum = 0; itemNum < selectedItemsCount; itemNum++)
//        {
//            QTableWidgetItem *selectedItem = ui->tableWidget->selectedItems().at(itemNum);
//            selectedItem->setFlags(selectedItem->flags()^Qt::ItemIsEditable);
//        }}

//}

//void MainWindow::on_pushButton_4_clicked()
//{
//    QString search = ui->lineEdit_search->text();
//    if(ui->lineEdit_search->text()!=nullptr){
//            for(int i=0;i<=new QTableWidgetItem(num);i++){
//                for(int x=0;x<=new QTableWidgetItem(place);x++){
//                    QModelIndex ind = new QTableWidgetItem()->index(x,i);
//                    if(ind.data().toString()==str){
//                        ui->tableWidget->setItem(x,i)->setBackground(Qt::yellow);
//                    }
//                }
//            }
//        }
//}

//void MainWindow::on_loadButton_clicked()
//{
//// Получаем путь до выбранного файла в созданном диалоге.
//// тек. виджет заголовок дефолт. значение тип файлов
//QString file = QFileDialog::getOpenFileName(this, "Open file", "./entries.hex", "HEXDUMPED (*.hex)");

//// Класс записи/чтения, знаешь уже.
//pcl::streamer streamer(file);

//// Очищаем список.
//entries.clear();

//// Загружаем в общий список. Если удачно, тогда обнуляем аргумента поиска
//if (streamer.tryLoad(entries)) {
//// Вот тут, да.
//predicator.args = pcl::pl_args();

//// И опять, обновляем, сука, вид.
//update_view();
//}
//}

void MainWindow::on_pushButton_save_clicked()
{

    QString strFilter;
       QString str = QFileDialog ::getSaveFileName(0,tr("Save Your file"),"Name File","*.txt",&strFilter);
           QFile file2(str);
               if(file2.open(QIODevice::WriteOnly))
               {
                   QString StringItem;
                   QTextStream out (&file2);
                   for(int i=0;i<ui->tableWidget->rowCount();i++){
                       for(int j=0;j<ui->tableWidget->columnCount();j++){
                           QTableWidgetItem *pToltem;
                           pToltem=ui->tableWidget->item(i,j);
                           StringItem=pToltem->text();
                           qDebug()<<StringItem;
                        out<<  StringItem;
                       }
                   }
               }
    //арт

    ////////////////////////////////////////////////


//    QFile file("data.txt");//создаем файловую переменную
//        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//(!file.open-если не получилось открыть файл)(WriteOnly-только для записи)(текстовый файл)
//        {
//            ui->label->setText("Ошибка"); return;
//        }
//        else ui->label->setText("Данные сохранены");
//        QTextStream out(&file);
//        for(int  i=0;i<;i++)
//        {
//            //for(int o=0;o<j;o++)
//            //{
//                out<< ui->tableWidget->item(i, 0)->text()+' ';// считывание данных из ячейки
//            //}
//            out<<"\n";
//        }
//        file.close();
//}



//    QVector<order*> order_vector;
//    order_vector.resize(512);
//    //QString test;
//    QString Number = ui->lineEdit_number->text();
//    QString Place = ui->lineEdit_place->text();
//    QString Automobile = ui->comboBox->currentText();

//    QString inputfile = QFileDialog::getOpenFileName(
//                this,
//                tr("Open File"),
//                "D:/",
//                "All files (*.*)"
//                );

//    if(inputfile != ""){
//    QFile file(inputfile);


//    if(!file.open(QFile::ReadOnly)){
//       }
//    QTextStream in(&file);

//    order* buffer;
//    //QString buffer;
//    //buffer.setNum(counter +1);
//    //rows.push_back(buffer);

//        while(!file.atEnd()){
//            in.readLine();
//            for(int i=0; i<512; i++){
//                in >> buffer;
//                order_vector[i]+=buffer;
//            }
//        }

//    }
//        qDebug() << order_vector;
//     //ВЫВОД ФАЙЛА
//        QString filename = "D:/QtCreator/proj/kursach/data.txt";
//        QFile fileout(filename);
//        if (fileout.open(QFile::ReadWrite | QFile::Text)){
//         QTextStream out(&fileout);
//         for (QVector<order*>::iterator iter = order_vector.begin(); iter != order_vector.end(); iter++){
//             out << *iter;
//         }
//         fileout.close();
}

