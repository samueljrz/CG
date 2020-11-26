#ifndef ESQUELETO_H
#define ESQUELETO_H

#include <objeto.h>

class Esqueleto : public Objeto {
    public:
        Model3DS* model;
    public:
        Esqueleto();
        void desenha();
        string getName();
};

#endif // ESQUELETO_H
