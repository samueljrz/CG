#ifndef PEAO_H
#define PEAO_H

#include <objeto.h>

class Peao : public Objeto {
    public:
        Peao();
        void desenha();
        void peao();
        string getName();
};

#endif // PEAO_H
