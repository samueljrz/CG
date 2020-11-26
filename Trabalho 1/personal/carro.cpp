#include "carro.h"

Carro::Carro()
{
    model = new Model3DS("../3DS/cartest.3DS");

}

void Carro::desenha() {

    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            glEnable(GL_CULL_FACE);
            GUI::drawBox(-1,-0.5,-1, 1,1,1, true);
        }

        glScalef(1,1,1.2); //ajuste final da escala, podendo ser não-uniforme, independente para cada eixo
        glRotatef(-90,1,0,0); // alinhar o objeto 3ds com os eixos, deixando ele para cima de acordo com o eixo Y
        glTranslatef(0,0,0); //trazer objeto 3ds para origem

        glScalef(0.001,0.001,0.001); //apenas para conseguir enxergar o objeto 3ds

        model->draw();

    glPopMatrix();
}

string Carro::getName() {
    return "Carro";
}
