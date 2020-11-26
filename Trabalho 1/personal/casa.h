#ifndef CASA_H
#define CASA_H

#include <objeto.h>

class Casa : public Objeto {
    public:
        Casa();
        void desenha();
        void casa();
        string getName();
};

#endif // CASA_H
