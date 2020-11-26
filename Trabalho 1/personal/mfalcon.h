#ifndef MFALCON_H
#define MFALCON_H

#include <objeto.h>

class MFalcon : public Objeto {
    public:
        Model3DS* model;
    public:
        MFalcon();
        void desenha();
        string getName();
};

#endif //MFALCON_H
