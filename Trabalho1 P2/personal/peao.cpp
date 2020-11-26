#include "peao.h"

Peao::Peao() { }

void Peao::peao () {

    glTranslatef (0.0, 0.0, 0.0);
    glPushMatrix();
        glRotatef(-90,1,0,0);
        glutSolidCone(0.3, 0.75, 10, 8);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 0.75, 0.0);
        glScalef(0.2, 0.2, 0.2);
        glutSolidSphere(1, 40,20 );
    glPopMatrix();

}

void Peao::desenha() {

    glPushMatrix();
    Objeto::desenha(); // T.Rz.Ry.Rx.S. p

    if ( selecionado ) {
        GUI::setColor(1,0,0);
    } else {
        GUI::setColor(1,1,0);
    }

    peao();

    glPopMatrix();

}

string Peao::getName(){
    return "Peao";
}

