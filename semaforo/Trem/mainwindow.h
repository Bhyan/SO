#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateInterface(int,int,int);

private slots:
    void on_btn_comecar_clicked();

    void on_btn_parar_clicked();

    void on_controle_azul_sliderReleased();

    void on_controle_vermelho_sliderReleased();

    void on_controle_verde_sliderReleased();

    void on_controle_roxo_sliderReleased();

    void on_controle_laranja_sliderReleased();

private:
    Ui::MainWindow *ui;
    Trem *trem_azul;
    Trem *trem_vermelho;
    Trem *trem_verde;
    Trem *trem_roxo;
    Trem *trem_laranja;
};

#endif // MAINWINDOW_H
