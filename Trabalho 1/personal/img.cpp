#include "img.h"

Img::Img () {}

void Img::img() {

    /* Inferior */
    glBegin(GL_QUADS);
        glNormal3f(0,-1,0);
        glVertex3f(0,0,0);
        glVertex3f(0.5,0,0);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0,0,0.5);
    glEnd();

    /* Tras */
    glBegin(GL_POLYGON);
        glNormal3f(1,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0.5,0);
        glVertex3f(0.5,0.5,0);
        glVertex3f(0.5,0,0);
    glEnd();

    /* Frente */
    glBegin(GL_POLYGON);
        glNormal3f(1,3,-1);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0,0.5,0.5);
        glVertex3f(0,0,0.5);
    glEnd();

    /* Lateral Direita */
    glBegin(GL_QUADS);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0.5,0);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,0,0);
    glEnd();

    /* Lateral Esquerda */
    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(0,0.5,0.5);
        glVertex3f(0,0.5,0);
        glVertex3f(0,0,.0);
        glVertex3f(0,0,0.5);
    glEnd();

    /* Teto */
    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glVertex3f(0,0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,0);
        glVertex3f(0,0.5,0);
    glEnd();

    /* Olho E */
    glBegin(GL_TRIANGLES);
        GUI::setColor(255,0,0);
        glNormal3f(0,0,1);
        glVertex3f(0.4,0.3,0.55);
        glVertex3f(0.35,0.4,0.55);
        glVertex3f(0.3,0.3,0.55);
    glEnd();

    /* Olho D */
    glBegin(GL_TRIANGLES);
        GUI::setColor(255,0,0);
        glNormal3f(0,0,1);
        glVertex3f(0.2,0.3,0.51);
        glVertex3f(0.15,0.4,0.51);
        glVertex3f(0.1,0.3,0.51);
    glEnd();

    /* Boca */
    glBegin(GL_QUADS);
        GUI::setColor(255,255,255);
        glNormal3f(0,0,1);
        glVertex3f(0.4,0.1,0.51);
        glVertex3f(0.4,0.18,0.51);
        glVertex3f(0.1,0.18,0.51);
        glVertex3f(0.1,0.1,0.51);
    glEnd();

    /* Nariz */
    glBegin(GL_QUADS);
        GUI::setColor(255,255,255);
        glNormal3f(0,0,1);
        glVertex3f(0.24,0.22,0.51);
        glVertex3f(0.24,0.26,0.51);
        glVertex3f(0.2,0.26,0.51);
        glVertex3f(0.2,0.22,0.51);

        glNormal3f(0,0,1);
        glVertex3f(0.3,0.22,0.51);
        glVertex3f(0.3,0.26,0.51);
        glVertex3f(0.26,0.26,0.51);
        glVertex3f(0.26,0.22,0.51);
    glEnd();

    /* Orelha E */
    glBegin(GL_QUADS);
        /* Frente */
        glNormal3f(0,0,1);
        glVertex3f(0.6,0.15,0.35);
        glVertex3f(0.6,0.35,0.35);
        glVertex3f(0.5,0.35,0.35);
        glVertex3f(0.5,0.15,0.35);

        /* Tras */
        glNormal3f(1,0,1);
        glVertex3f(0.5,0.15,0.15);
        glVertex3f(0.5,0.35,0.15);
        glVertex3f(0.6,0.35,0.15);
        glVertex3f(0.6,0.15,0.15);

        /* Direita */
        glNormal3f(1,0,0);
        glVertex3f(0.6,0.35,0.15);
        glVertex3f(0.6,0.35,0.35);
        glVertex3f(0.6,0.15,0.35);
        glVertex3f(0.6,0.15,0.15);

        /* cima */
        glNormal3f(0,1,0);
        glVertex3f(0.5,0.35,0.35);
        glVertex3f(0.6,0.35,0.35);
        glVertex3f(0.6,0.35,0.15);
        glVertex3f(0.5,0.35,0.15);

        /* Baixo */
        glNormal3f(0,1,0);
        glVertex3f(0.5,0.15,0.15);
        glVertex3f(0.6,0.15,0.15);
        glVertex3f(0.6,0.15,0.35);
        glVertex3f(0.5,0.15,0.35);
    glEnd();

    /* Orelha D */
    glBegin(GL_QUADS);
        /* Frente */
        glNormal3f(0,0,1);
        glVertex3f(0,0.15,0.35);
        glVertex3f(0,0.35,0.35);
        glVertex3f(-0.1,0.35,0.35);
        glVertex3f(-0.1,0.15,0.35);

        /* Tras */
        glNormal3f(1,0,1);
        glVertex3f(-0.1,0.15,0.15);
        glVertex3f(-0.1,0.35,0.15);
        glVertex3f(0,0.35,0.15);
        glVertex3f(0,0.15,0.15);

        /* Direita */
        glNormal3f(1,0,0);
        glVertex3f(-0.1,0.15,0.15);
        glVertex3f(-0.1,0.15,0.35);
        glVertex3f(-0.1,0.35,0.35);
        glVertex3f(-0.1,0.35,0.15);

        /* cima */
        glNormal3f(0,1,0);
        glVertex3f(0.0,0.35,0.15);
        glVertex3f(-0.1,0.35,0.15);
        glVertex3f(-0.1,0.35,0.35);
        glVertex3f(0.0,0.35,0.35);

        /* Baixo */
        glNormal3f(0,1,0);
        glVertex3f(0.0,0.15,0.35);
        glVertex3f(-0.1,0.15,0.35);
        glVertex3f(-0.1,0.15,0.15);
        glVertex3f(0.0,0.15,0.15);

    glEnd();

    /* ANTENA */
    glBegin(GL_LINES);
        GUI::setColor(255, 255, 255);
        glVertex3f(0.25,0.5,0.25);
        glVertex3f(0.25,0.75,0.25);
    glEnd();

    /*CHAO*/
    glBegin(GL_QUADS);
        GUI::setColor(255,0,0);
        glNormal3f(0,-1,0);
        glVertex3f(0.2,0.75,0.2);
        glVertex3f(0.3,0.75,0.2);
        glVertex3f(0.3,0.75,0.3);
        glVertex3f(0.2,0.75,0.3);
    glEnd();

    /*TRAS*/
    glBegin(GL_POLYGON);
        glNormal3f(1,3,1);
        glVertex3f(0.2,0.75,0.2);
        glVertex3f(0.2,0.85,0.2);
        glVertex3f(0.3,0.85,0.2);
        glVertex3f(0.3,0.75,0.2);
    glEnd();

    /* Frente */
    glBegin(GL_POLYGON);
        glNormal3f(1,3,-1);
        glVertex3f(0.3,0.75,0.3);
        glVertex3f(0.3,0.85,0.3);
        glVertex3f(0.2,0.85,0.3);
        glVertex3f(0.2,0.75,0.3);
    glEnd();

    /* Lateral Direita */
    glBegin(GL_QUADS);
        glNormal3f(1,0,0);
        glVertex3f(0.3,0.85,0.2);
        glVertex3f(0.3,0.85,0.3);
        glVertex3f(0.3,0.75,0.3);
        glVertex3f(0.3,0.75,0.2);
    glEnd();

    /* Lateral Esquerda */
    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(0.2,0.85,0.3);
        glVertex3f(0.2,0.85,0.2);
        glVertex3f(0.2,0.75,0.2);
        glVertex3f(0.2,0.75,0.3);
    glEnd();

    /* Teto */
    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glVertex3f(0.2,0.85,0.3);
        glVertex3f(0.3,0.85,0.3);
        glVertex3f(0.3,0.85,0.2);
        glVertex3f(0.2,0.85,0.2);
    glEnd();
}

void Img::desenha() {

    glPushMatrix();
    Objeto::desenha(); // T.Rz.Ry.Rx.S. p

    if ( selecionado ) {
        GUI::setColor(0,0,0);
    } else {
        GUI::setColor(128,128,128, 0.65);
    }

    img();

    glPopMatrix();

}

string Img::getName() {
    return "Robo";
}
