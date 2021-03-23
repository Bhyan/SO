#include "trem.h"
#include <QtCore>
#include <math.h>

Trem::Trem(int ID, int x, int y, int velocidade){
    this -> ID = ID;
    this -> x = x;
    this -> y = y;
    this -> velocidade = velocidade;
}

void Trem::setVelocidade(int valor){
    this -> velocidade = valor;
}

void Trem::run(){
    while(true){
        switch(ID){
        case 1:
            if (y == 20 && x < (135 + TAMANHO_TRILHO)) {
                x ++;
            }
            else if (x == (135 + TAMANHO_TRILHO) && y < (20 + TAMANHO_TRILHO)) {
                y ++;
            }
            else if (x > 135 && y == (20 + TAMANHO_TRILHO)) {
                x--;
            }
            else if (y > 20 && x == 135) {
                y --;
            }
            emit updateGUI(ID, x, y);
            usleep(velocidade);
            break;
        case 2:
            if (y == 20 && x < (380 + TAMANHO_TRILHO)) {
                x ++;
            }
            else if (x == (380 + TAMANHO_TRILHO) && y < (20 + TAMANHO_TRILHO)) {
                y ++;
            }
            else if (x > 380 && y == (20 + TAMANHO_TRILHO)) {
                x--;
            }
            else if (y > 20 && x == 380) {
                y --;
            }
            emit updateGUI(ID, x, y);
            usleep(velocidade);
            break;
        case 3:
            if (y == 20 && x < (625 + TAMANHO_TRILHO)) {
                x ++;
            }
            else if (x == (625 + TAMANHO_TRILHO) && y < (20 + TAMANHO_TRILHO)) {
                y ++;
            }
            else if (x > 625 && y == (20 + TAMANHO_TRILHO)) {
                x--;
            }
            else if (y > 20 && x == 625) {
                y --;
            }
            emit updateGUI(ID, x, y);
            usleep(velocidade);
            break;
        case 4:
            if (y == 264 && x < (259 + TAMANHO_TRILHO)) {
                x ++;
            }
            else if (x == (259 + TAMANHO_TRILHO) && y < (264 + TAMANHO_TRILHO)) {
                y ++;
            }
            else if (x > 259 && y == (264 + TAMANHO_TRILHO)) {
                x--;
            }
            else if (y > 264 && x == 259) {
                y --;
            }
            emit updateGUI(ID, x, y);
            usleep(velocidade);
            break;
        case 5:
            if (y == 264 && x < (505 + TAMANHO_TRILHO)) {
                x ++;
            }
            else if (x == (505 + TAMANHO_TRILHO) && y < (264 + TAMANHO_TRILHO)) {
                y ++;
            }
            else if (x > 505 && y == (264 + TAMANHO_TRILHO)) {
                x--;
            }
            else if (y > 264 && x == 505) {
                y --;
            }
            emit updateGUI(ID, x, y);
            usleep(velocidade);
            break;
        default:
            break;
        }
    }
}
