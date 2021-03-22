#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui -> setupUi(this);

    trem_azul = new Trem(1, 135, 20);
    trem_vermelho = new Trem(2, 380, 20);
    trem_verde = new Trem(3, 625, 20);
    trem_roxo = new Trem(4, 259, 264);
    trem_laranja = new Trem(5, 505, 264);

    connect(trem_azul, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem_vermelho, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem_verde, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem_roxo, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));
    connect(trem_laranja, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int,int,int)));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateInterface(int id, int x, int y) {
    switch(id){
    case 1:
        ui -> trem_azul -> setGeometry(x,y,50,50);
        break;
    case 2:
        ui -> trem_vermelho -> setGeometry(x,y,50,50);
        break;
    case 3:
        ui -> trem_verde -> setGeometry(x,y,50,50);
        break;
    case 4:
        ui -> trem_roxo -> setGeometry(x,y,50,50);
        break;
    case 5:
        ui -> trem_laranja -> setGeometry(x,y,50,50);
        break;
    default:
        break;
    }
}

void MainWindow::on_btn_comecar_clicked() {
    trem_azul -> start();
    trem_vermelho -> start();
    trem_verde -> start();
    trem_roxo -> start();
    trem_laranja -> start();
}

void MainWindow::on_btn_parar_clicked() {
    trem_azul -> terminate();
    trem_vermelho -> terminate();
    trem_verde -> terminate();
    trem_roxo -> terminate();
    trem_laranja -> terminate();
}

void MainWindow::on_controle_azul_sliderReleased() {
        trem_azul -> setVelocidade (ui -> controle_azul -> value());
}

void MainWindow::on_controle_vermelho_sliderReleased() {
        trem_vermelho -> setVelocidade(ui -> controle_vermelho -> value());
}

void MainWindow::on_controle_verde_sliderReleased() {
        trem_verde -> setVelocidade(ui -> controle_verde -> value());
}

void MainWindow::on_controle_roxo_sliderReleased() {
        trem_roxo -> setVelocidade(ui -> controle_roxo -> value());
}

void MainWindow::on_controle_laranja_sliderReleased() {
        trem_laranja -> setVelocidade(ui -> controle_laranja -> value());
}
