#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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
    // Код для первой кнопки
    qDebug() << "Первая кнопка была нажата!";
}

void MainWindow::on_pushButton1_clicked()
{
    // Код для второй кнопки
    qDebug() << "Вторая кнопка была нажата!";
}

void MainWindow::on_pushButton2_clicked()
{
    // Код для третьей кнопки
    qDebug() << "Третья кнопка была нажата!";
}
