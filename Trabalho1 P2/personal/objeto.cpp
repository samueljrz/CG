#include "objeto.h"

Objeto::Objeto () {}

void Objeto::desenha() {

    if ( originD ) {
        glTranslatef(t.x,t.y,t.z);
        glRotatef(a.z,0,0,1);
        glRotatef(a.y,0,1,0);
        glRotatef(a.x,1,0,0);
        GUI::drawOrigin(1);
        glScalef(s.x,s.y,s.z);
    }else {
        glTranslatef(t.x,t.y,t.z);
        glRotatef(a.z,0,0,1);
        glRotatef(a.y,0,1,0);
        glRotatef(a.x,1,0,0);
        glScalef(s.x,s.y,s.z);
    }
}

string Objeto::getName() {

    return "Objeto";
}
