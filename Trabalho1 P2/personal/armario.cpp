#include "armario.h"

Armario::Armario() { }

void Armario::armario () {

    /* Armario */

    // Porta Frontal Esquerda Externa
    glBegin(GL_QUADS);
        //GUI::setColor(139,69,19);
        glNormal3f(0,0,1);
        glVertex3f(0,0,0.5);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0.5);
        glVertex3f(0,1,0.5);
    glEnd();
    // Porta Frontal Esquerda Interna
    glBegin(GL_QUADS);
        //GUI::setColor(139,69,19);
        glNormal3f(0,0,-1);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0,0,0.5);
        glVertex3f(0,1,0.5);
        glVertex3f(0.5,1,0.5);
    glEnd();
    // Porta Frontal Direita Externa
    glBegin(GL_POLYGON);
        glNormal3f(1,0,1);
        glVertex3f(0.7,0,0.8);
        glVertex3f(1,0,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(0.7,1,0.8);
    glEnd();
    // Porta Frontal Direita Interna
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,-1);
        glVertex3f(1,0,0.5);
        glVertex3f(0.7,0,0.8);
        glVertex3f(0.7,1,0.8);
        glVertex3f(1,1,0.5);
    glEnd();
    // Face lateral Direita Externa
    glBegin(GL_QUADS);
        glNormal3f(1,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,0,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,1,0);
    glEnd();
    // Face lateral Direita Interna
    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(1,0,0.5);
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
    glEnd();
    // Face lateral Esquerda Externa
    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,0.5);
        glVertex3f(0,1,0.5);
        glVertex3f(0,1,0);
    glEnd();
    // Face lateral Esquerda Interna
    glBegin(GL_QUADS);
        glNormal3f(1,0,0);
        glVertex3f(0,0,0.5);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,0.5);
    // Face Traseira Externa
    glBegin(GL_QUADS);
        glNormal3f(0,0,-1);
        glVertex3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(1,1,0);
    glEnd();
    // Face Traseira Interna
    glBegin(GL_QUADS);
        glNormal3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(0,1,0);
    glEnd();
    // Face Superior Externa
    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glVertex3f(1,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,0.5);
        glVertex3f(1,1,0.5);
    glEnd();
    // Face Superior Interna
    glBegin(GL_QUADS);
        glNormal3f(0,-1,0);
        glVertex3f(0,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
        glVertex3f(0,1,0.5);
    glEnd();
    // Face Inferior Externa
    glBegin(GL_QUADS);
        glNormal3f(0,-1,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,0,0.5);
        glVertex3f(0,0,0.5);
    glEnd();
    // Face Inferior Interna
    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glVertex3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,0.5);
        glVertex3f(1,0,0.5);
    glEnd();

    // Maçaneta Esquerda
    glBegin(GL_QUADS);
        glNormal3f(0,0,1);
        GUI::setColor(17,114,212,0.7);
        glVertex3f(0.2,0.4,0.502);
        glVertex3f(0.35,0.4,0.502);
        glVertex3f(0.35,0.62,0.502);
        glVertex3f(0.2,0.62,0.502);
    glEnd();

    // Maçaneta Direita
    glBegin(GL_POLYGON);
        GUI::setColor(17,114,212,0.7);
        glNormal3f(1,0,1);
        glVertex3f(0.801,0.4,0.701);
        glVertex3f(0.901,0.4,0.601);
        glVertex3f(0.901,0.6,0.601);
        glVertex3f(0.801,0.6,0.701);
    glEnd();
    // Plateneira 1
    // Superior
    glBegin(GL_QUADS);
        GUI::setColor(0,0,0);
        glNormal3f(0,1,0);
        glVertex3f(1,0.7,0);
        glVertex3f(0,0.7,0);
        glVertex3f(0, 0.7,0.5);
        glVertex3f(1,0.7,0.5);
    glEnd();
    // Inferior
    glBegin(GL_QUADS);
        GUI::setColor(0,0,0);
        glNormal3f(0,-1,0);
        glVertex3f(0,0.7,0);
        glVertex3f(1,0.7,0);
        glVertex3f(1,0.7,0.5);
        glVertex3f(0, 0.7,0.5);
    glEnd();
    // Plateneira 2
    // Superior
    glBegin(GL_QUADS);
        GUI::setColor(0,0,0);
        glNormal3f(0,1,0);
        glVertex3f(1,0.4,0);
        glVertex3f(0,0.4,0);
        glVertex3f(0, 0.4,0.5);
        glVertex3f(1,0.4,0.5);
    glEnd();
    // Inferior
    glBegin(GL_QUADS);
        GUI::setColor(0,0,0);
        glNormal3f(0,-1,0);
        glVertex3f(0,0.4,0);
        glVertex3f(1,0.4,0);
        glVertex3f(1,0.4,0.5);
        glVertex3f(0,0.4,0.5);
    glEnd();

}

void Armario::desenha() {

    glPushMatrix();
    Objeto::desenha(); // T.Rz.Ry.Rx.S. p

    if ( selecionado ) {
        GUI::setColor(1,0,0);
    } else {
        GUI::setColor(1,1,0);
    }

    armario();

    glPopMatrix();

}

string Armario::getName(){
    return "Armario";
}

