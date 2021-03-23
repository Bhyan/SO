#ifndef TREM_H
#define TREM_H

#include <QThread>

class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int, int, int, int);
    void run();
    void setVelocidade(int valor);

signals:
    void updateGUI(int, int, int);

private:
   int ID;
   int x;
   int y;
   float velocidade;
   int const TAMANHO_TRILHO = 245;
   int const VELOCIDADE_MINIMA = 5000;
};

#endif // TREM_H
