#include "objeto.h"

Objeto::Objeto () {}

void Objeto::desenha() {

    if ( originD ) {
        glTranslatef(t.x,t.y,t.z); /* Transformacao (matriz) mais a esquerda (mais global) */
        glRotatef(a.z,0,0,1);
        glRotatef(a.y,0,1,0);
        glRotatef(a.x,1,0,0);
        GUI::drawOrigin(1);
        glScalef(s.x,s.y,s.z); /* Transformacao (matriz) mais a direita (mais local)  */
    }else {
        glTranslatef(t.x,t.y,t.z); /* Transformacao (matriz) mais a esquerda (mais global) */
        glRotatef(a.z,0,0,1);
        glRotatef(a.y,0,1,0);
        glRotatef(a.x,1,0,0);
        glScalef(s.x,s.y,s.z); /* Transformacao (matriz) mais a direita (mais local)  */
    }
}

string Objeto::getName() {

    return "Objeto";
}
