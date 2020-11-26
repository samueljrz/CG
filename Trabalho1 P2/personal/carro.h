#ifndef CARRO_H
#define CARRO_H

#include <objeto.h>

class Carro : public Objeto {
    public:
        Model3DS* model;
    public:
        Carro();
        void desenha();
        string getName();
};

#endif // CARRO_H
