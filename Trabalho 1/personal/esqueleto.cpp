#include "esqueleto.h"

Esqueleto::Esqueleto()
{
    model = new Model3DS("../3DS/esqueleto.3DS");

}

void Esqueleto::desenha() {

    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            glEnable(GL_CULL_FACE);
            GUI::drawBox(-1,-0.5,-1, 1,2,1, true);
        }

        glScalef(1,1,1.2); /* Ajuste final da escala, podendo ser não-uniforme, independente para cada eixo */
        glRotatef(-90,1,0,0); /* Alinhar o objeto 3ds com os eixos, deixando ele para cima de acordo com o eixo Y */
        glRotatef(-90,0,0,1);
        glTranslatef(0,0,0); /* Trazer objeto 3ds para origem */

        glScalef(0.025,0.025,0.025); /* Apenas para conseguir enxergar o objeto 3ds */

        model->draw();

    glPopMatrix();
}

string Esqueleto::getName() {
    return "Esqueleto";
}
