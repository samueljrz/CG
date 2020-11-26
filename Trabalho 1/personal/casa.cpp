#include "casa.h"

Casa::Casa () {}

void Casa::casa() {

    /* Inferior */
    glBegin(GL_QUADS);
        glNormal3f(0,-1,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,0,1);
        glVertex3f(0,0,1);
    glEnd();

    /* Frente */
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(0,0,1);
        glVertex3f(1,0,1);
        glVertex3f(1,1,1);
        glVertex3f(0.5,1.5,1);
        glVertex3f(0,1,1);
    glEnd();

    /* Traseira */
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0.5,1.5,0);
        glVertex3f(1,1,0);
    glEnd();

    /* Lateral Direita */
    glBegin(GL_QUADS);
        glNormal3f(0,0,1);
        glVertex3f(1,0,1);
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(1,1,1);
    glEnd();

    /* Lateral Esquerda */
    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,1);
        glVertex3f(0,1,1);
        glVertex3f(0,1,0);
    glEnd();

    /* Teto */

    /* Teto Direito Externo */
    glBegin(GL_QUADS);
        glNormal3f(1,1,0);
        glVertex3f(1.5,0.5,1);
        glVertex3f(1.5,0.5,0);
        glVertex3f(0.5,1.5,0);
        glVertex3f(0.5,1.5,1);

    glEnd();

    /* Teto Direito Interno */
    glBegin(GL_QUADS);
        glNormal3f(-1,-1,0);
        glVertex3f(1.5,0.5,0);
        glVertex3f(1.5,0.5,1);
        glVertex3f(0.5,1.5,1);
        glVertex3f(0.5,1.5,0);
    glEnd();

    /* Teto Esquerda Externo */
    glBegin(GL_QUADS);
        glNormal3f(-1,1,0);
        glVertex3f(-0.5,0.5,0);
        glVertex3f(-0.5,0.5,1);
        glVertex3f(0.5,1.5,1);
        glVertex3f(0.5,1.5,0);
    glEnd();

    /* Teto Esquerda Interno */
    glBegin(GL_QUADS);
        glNormal3f(1,-1,0);
        glVertex3f(-0.5,0.5,1);
        glVertex3f(-0.5,0.5,0);
        glVertex3f(0.5,1.5,0);
        glVertex3f(0.5,1.5,1);
    glEnd();

    /* Janela */
    glBegin(GL_QUADS);
        GUI::setColor(255,255,255);
        glNormal3f(0,0,-1);
        glVertex3f(0.7,0.3,-0.01);
        glVertex3f(0.3,0.3,-0.01);
        glVertex3f(0.3,0.7,-0.01);
        glVertex3f(0.7,0.7,-0.01);
    glEnd();

    /* Porta */
    glBegin(GL_QUADS);
        GUI::setColor(255,255,255);
        glNormal3f(0,0,1);
        glVertex3f(0.3,0.01,1.01);
        glVertex3f(0.7,0.01,1.01);
        glVertex3f(0.7,0.6,1.01);
        glVertex3f(0.3,0.6,1.01);
    glEnd();
}

void Casa::desenha() {

    glPushMatrix();
    Objeto::desenha(); // T.Rz.Ry.Rx.S. p

    if ( selecionado ) {
        GUI::setColor(1,0,0);
    } else {
        GUI::setColor(1,1,0);
    }

    casa();

    glPopMatrix();

}

string Casa::getName() {
    return "Casa";
}
