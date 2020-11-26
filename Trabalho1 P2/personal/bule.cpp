#include "bule.h"

Bule::Bule() { }

void Bule::desenha() {

    glPushMatrix();
    Objeto::desenha(); // T.Rz.Ry.Rx.S. p

    if ( selecionado ) {
        GUI::setColor(1,0,0);
    } else {
        GUI::setColor(1,1,0);
    }

    glTranslatef(0,0.42,0);
    glutSolidTeapot(0.5);

    glPopMatrix();

}

string Bule::getName(){
    return "Bule";
}
