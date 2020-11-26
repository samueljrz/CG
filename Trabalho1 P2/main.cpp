#include <bits/stdc++.h>

using namespace std;

#include <vector>

#include <casa.h>
#include <carro.h>
#include <esqueleto.h>
#include <bule.h>
#include <peao.h>
#include <armario.h>

vector<Objeto*> objetos;
int posSelecionado = -1;

/* ------------------- Sombra ------------------- */
bool drawShadow = false;
bool drawPlane = false;
bool pontual = true;

/* ------------------- Planos ------------------- */

float inferior = -0.001;
float lateral = -10;
float inclinado = 0;
float offset = 0.01;

void desenha() {
    GUI::displayInit();

    GUI::setLight(0,0,5,0,true,false,false,false,pontual);

    GUI::drawOrigin(1);

    GUI::setColor(1,0,0);

    /* Inferior */
        glPushMatrix();
        glTranslated(0,inferior-offset,0);
        GUI::drawFloor(20, 20);
    glPopMatrix();

    /* Lado esquerdo */
    glPushMatrix();
        glTranslated(lateral-offset,5,0);
        glRotatef(-90,0,0,1);
        GUI::drawFloor(10, 20);
    glPopMatrix();

    /* Face inclinada */
    glPushMatrix();
        glTranslated(15,5,0.01);
        glRotatef(45,0,0,1);
        GUI::drawFloor(20, 20);
    glPopMatrix();

    /* Imprimir os elementos */
    for (int i = 0; i < (int)objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    /* ------------------- Sombra ------------------- */

    /* Definindo a luz que sera usada para gerar a sombra */
    float lightPos[4] = {-1+glutGUI::lx,2+glutGUI::ly,1+glutGUI::lz,pontual};

    /* Planos onde seram projetados as sombras */
    GLfloat plano0[4] = {0,1,0,-inferior}; // Inferior
    GLfloat plano1[4] = {1,0,0,-lateral}; // Lateral Esquerdo
    GLfloat plano2[4] = {-1,1,0,9.9}; // Face inclinada

    vector<GLfloat*> vecPlanos;
    vecPlanos.push_back(plano0);
    vecPlanos.push_back(plano1);
    vecPlanos.push_back(plano2);

    glDisable(GL_LIGHTING);
    glColor3d(0.0,0.0,0.0);

    for(int i=0; i < (int)vecPlanos.size() ;i++){

        glPushMatrix();
            GLfloat sombra[4][4];

            GUI::shadowMatrix(sombra,vecPlanos[i],lightPos);
            glMultTransposeMatrixf((GLfloat*)sombra );

            if(drawShadow) {

                bool aux = glutGUI::draw_eixos;
                glutGUI::draw_eixos = false;

                /* Imprimir os elementos */
                for (int j = 0; j < (int)objetos.size(); ++j) {
                    //if(objetos[j]->draw_shadow) {
                        glPushMatrix();
                            objetos[j]->desenha();
                        glPopMatrix();
                    //}
                }
                glutGUI::draw_eixos = aux;
            }
         glPopMatrix();
    }
    glEnable(GL_LIGHTING);

    if (posSelecionado >= 0 and posSelecionado < (int)objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }

    GUI::displayEnd();
}

bool incluirObjeto = false;
bool excluirObjeto = false;

void teclado( unsigned char key, int x, int y ) {

    GUI::keyInit(key,x,y);

    switch (key) {

    /* Habilita/Desabilita a flag de translação */
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;

    /* Habilita/Desabilita a flag de translação da luz */
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    /* Adiciona um objeto do tipo carro */
    case '1':
        if ( incluirObjeto ) {
            objetos.push_back( new Carro() );
        }
        break;

    /* Adiciona uma objeto do tipo casa */
    case '2':
        if ( incluirObjeto ) {
            objetos.push_back( new Casa() );
        }
        break;
    case '3':
        if ( incluirObjeto ) {
            objetos.push_back( new Esqueleto() );
        }
        break;
    case '4':
        if ( incluirObjeto ) {
            objetos.push_back( new Bule() );
        }
        break;
    case '5':
        if ( incluirObjeto ) {
            objetos.push_back( new Peao() );
        }
        break;

    case '6':
        if ( incluirObjeto ) {
            objetos.push_back( new Armario() );
        }
        break;
    case 'D':
        objetos[posSelecionado]->selecionado = !objetos[posSelecionado]->selecionado;
        break;

    /* Salva as coordenadas dos objeto do cenário */
    case 'S': {

        ofstream arquivo;
        arquivo.open("../local.txt");

        if ( arquivo.is_open() ) {

            for ( int i = 0 ; i < (int)objetos.size() ; i++ ) {

                if ( objetos[i]->getName() == "Casa" ) {
                    arquivo << objetos[i]->t.x << " " << objetos[i]->t.y << " " << objetos[i]->t.z << " " << objetos[i]->a.x << " " << objetos[i]->a.y << " "
                    << objetos[i]->a.z << " " << objetos[i]->s.x << " " << objetos[i]->s.y << " " << objetos[i]->s.z << " " << "Casa" << " " << "\n";
                }else if ( objetos[i]->getName() == "Carro" ) {
                    arquivo << objetos[i]->t.x << " " << objetos[i]->t.y << " " << objetos[i]->t.z << " " << objetos[i]->a.x << " " << objetos[i]->a.y << " "
                    << objetos[i]->a.z << " " << objetos[i]->s.x << " " << objetos[i]->s.y << " " << objetos[i]->s.z << " " << "Carro" << " " << "\n";
                }else if ( objetos[i]->getName() == "Esqueleto" ) {
                    arquivo << objetos[i]->t.x << " " << objetos[i]->t.y << " " << objetos[i]->t.z << " " << objetos[i]->a.x << " " << objetos[i]->a.y << " "
                    << objetos[i]->a.z << " " << objetos[i]->s.x << " " << objetos[i]->s.y << " " << objetos[i]->s.z << " " << "Esqueleto" << " " << "\n";
                }else if ( objetos[i]->getName() == "Bule" ) {
                    arquivo << objetos[i]->t.x << " " << objetos[i]->t.y << " " << objetos[i]->t.z << " " << objetos[i]->a.x << " " << objetos[i]->a.y << " "
                    << objetos[i]->a.z << " " << objetos[i]->s.x << " " << objetos[i]->s.y << " " << objetos[i]->s.z << " " << "Bule" << " " << "\n";
                }else if ( objetos[i]->getName() == "Peao" ) {
                    arquivo << objetos[i]->t.x << " " << objetos[i]->t.y << " " << objetos[i]->t.z << " " << objetos[i]->a.x << " " << objetos[i]->a.y << " "
                    << objetos[i]->a.z << " " << objetos[i]->s.x << " " << objetos[i]->s.y << " " << objetos[i]->s.z << " " << "Peao" << " " << "\n";
                }else if ( objetos[i]->getName() == "Armario" ) {
                    arquivo << objetos[i]->t.x << " " << objetos[i]->t.y << " " << objetos[i]->t.z << " " << objetos[i]->a.x << " " << objetos[i]->a.y << " "
                    << objetos[i]->a.z << " " << objetos[i]->s.x << " " << objetos[i]->s.y << " " << objetos[i]->s.z << " " << "Armario" << " " << "\n";
                }
            }

        }

        arquivo.close();
      }
      break;

    /* Restaura os objetos que foram previamente salvos */
    case 'R': {

        ifstream arquivo;
        float t_x, t_y, t_z;
        float a_x, a_y, a_z;
        float s_x, s_y, s_z;
        string name;

        objetos.clear();
        arquivo.open("../local.txt");

        if ( arquivo.is_open() ) {

            while ( arquivo >> t_x >>  t_y >> t_z >> a_x >> a_y >> a_z >> s_x >> s_y >> s_z >> name ) {
                if ( name == "Casa" ) {
                    Objeto *casa = new Casa ();
                    casa->selecionado = false;
                    casa->t.setVetor3D( t_x, t_y, t_z );
                    casa->a.setVetor3D( a_x, a_y, a_z );
                    casa->s.setVetor3D( s_x, s_y, s_z );

                    objetos.push_back( casa );
                }else if ( name == "Carro" ) {
                    Objeto *carro = new Carro ();
                    carro->selecionado = false;
                    carro->t.setVetor3D( t_x, t_y, t_z );
                    carro->a.setVetor3D( a_x, a_y, a_z );
                    carro->s.setVetor3D( s_x, s_y, s_z );

                    objetos.push_back( carro );
                }else if ( name == "Esqueleto" ) {
                    Objeto *esqueleto = new Esqueleto ();
                    esqueleto->selecionado = false;
                    esqueleto->t.setVetor3D( t_x, t_y, t_z );
                    esqueleto->a.setVetor3D( a_x, a_y, a_z );
                    esqueleto->s.setVetor3D( s_x, s_y, s_z );

                    objetos.push_back( esqueleto );
                }else if ( name == "Bule" ) {
                    Objeto *bule = new Bule ();
                    bule->selecionado = false;
                    bule->t.setVetor3D( t_x, t_y, t_z );
                    bule->a.setVetor3D( a_x, a_y, a_z );
                    bule->s.setVetor3D( s_x, s_y, s_z );

                    objetos.push_back( bule );
                }else if ( name == "Peao" ) {
                    Objeto *peao = new Peao ();
                    peao->selecionado = false;
                    peao->t.setVetor3D( t_x, t_y, t_z );
                    peao->a.setVetor3D( a_x, a_y, a_z );
                    peao->s.setVetor3D( s_x, s_y, s_z );

                    objetos.push_back( peao );
                }else if ( name == "Armario" ) {
                    Objeto *armario = new Armario ();
                    armario->selecionado = false;
                    armario->t.setVetor3D( t_x, t_y, t_z );
                    armario->a.setVetor3D( a_x, a_y, a_z );
                    armario->s.setVetor3D( s_x, s_y, s_z );

                    objetos.push_back( armario );
                }

            }
        }
        posSelecionado = -1;
        arquivo.close();
    }

    /* Incrementar selecionado */
    case 'N':
        if (posSelecionado >= 0 and posSelecionado < (int)objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;
        posSelecionado = posSelecionado%objetos.size();
        if (posSelecionado >= 0 and posSelecionado < (int)objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    /* Decrementar selecionado */
    case 'B':
        if (posSelecionado >= 0 and posSelecionado < (int)objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado--;
        if (posSelecionado < 0) {
            posSelecionado = objetos.size()-1;
        }
        if (posSelecionado >= 0 and posSelecionado < (int)objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    /* Habilita flag de exclusão de elemento */
    case 'E':
        excluirObjeto = !excluirObjeto;
        break;

    /* Exclui o ultimo elemento do vetor de objetos */
    case 'g':
        objetos.pop_back();
        break;

    /* Exclui o elemento selecionado */
    case 'G':
        if ( excluirObjeto && objetos[posSelecionado]->selecionado ) {
            objetos.erase(objetos.begin()+posSelecionado);
        }
        break;

    /* Desabilita as coordenadas locais do objeto selecionado */
    case 'd':
        objetos[posSelecionado]->originD = !objetos[posSelecionado]->originD;
        break;

    /* Habilita a inclusão de objetos */
    case 'O':
        incluirObjeto = !incluirObjeto;
        break;

    /* Alinha o objeto selecionado na origem */
    case 'r':
        if (posSelecionado >= 0 and posSelecionado < (int)objetos.size()) {
            objetos[posSelecionado]->t.x = 0.0;
            objetos[posSelecionado]->t.y = 0.0;
            objetos[posSelecionado]->t.z = 0.0;

            objetos[posSelecionado]->a.x = 0;
            objetos[posSelecionado]->a.y = 0;
            objetos[posSelecionado]->a.z = 0;

            objetos[posSelecionado]->s.x = 1;
            objetos[posSelecionado]->s.y = 1;
            objetos[posSelecionado]->s.z = 1;
        }
        break;
    case 's':
        drawShadow =  !drawShadow;
        break;

    case 'p':
        glutGUI::projection = (glutGUI::projection+1) % 3;
        break;
    case 'P':
        pontual = !pontual;
        break;
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}

