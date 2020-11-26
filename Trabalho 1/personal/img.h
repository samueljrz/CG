#ifndef IMG_H
#define IMG_H

#include <objeto.h>

class Img : public Objeto {
    public:
        Img();
        void desenha();
        void img();
        string getName();
};

#endif // IMG_H
