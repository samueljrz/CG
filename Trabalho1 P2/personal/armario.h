#ifndef ARMARIO_H
#define ARMARIO_H

#include <objeto.h>

class Armario : public Objeto {
    public:
        Armario();
        void desenha();
        void armario();
        string getName();
};

#endif // ARMARIO_H
