#include <bits/stdc++.h>

using namespace std;

#include <vector>

#include <casa.h>
#include <img.h>
#include <carro.h>
#include <esqueleto.h>
#include <mfalcon.h>

vector<Objeto*> objetos; // VETOR DE OBJETOS
int posSelecionado = -1; // ARMAZENA POS SELECIONADA

/* Shadows */
bool drawShadow = false;
bool drawPlane = false;
bool pontualLight = true;

/* Plans */
float inferior = -0.001;
float lateral = -10;
float inclinado = 0;
float offset = 0.01;

void desenha() {
    GUI::displayInit();

    GUI::setLight(0,0,4,0,true,false);
    GUI::setLight(2,-1.5,0.5,-1,true,false);

    GUI::drawOrigin(1);

    GUI::setColor(1,0,0);
    //GUI::drawFloor();

    /* Floor */
        glPushMatrix();
        glTranslated(0,inferior-offset,0);
        GUI::drawFloor(20, 20);
    glPopMatrix();

    /* inclined side */
    glPushMatrix();
        glTranslated(15,5,0.01);
        glRotatef(45,0,0,1);
        GUI::drawFloor(20, 20);
    glPopMatrix();

    /* left side */
    glPushMatrix();
        glTranslated(lateral-offset,5,0);
        glRotatef(-90,0,0,1);
        GUI::drawFloor(10, 20);
    glPopMatrix();

    /* show */
    for (int i = 0; i < (int)objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    /* Shadow */

    float lightPos[4] = {-1+glutGUI::lx,2+glutGUI::ly,1+glutGUI::lz,pontualLight};

    GLfloat plano0[4] = {0,1,0,-inferior};
    GLfloat plano1[4] = {1,0,0,-lateral};
    GLfloat plano2[4] = {-1,1,0,9.9}; //

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

                for (int j = 0; j < (int)objetos.size(); ++j) {
                        glPushMatrix();
                            objetos[j]->desenha();
                        glPopMatrix();
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

    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;

    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'O':
        incluirObjeto = !incluirObjeto;
        break;

    case '1':
        if ( incluirObjeto ) {
            objetos.push_back( new Carro() );
        }
        break;

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
            objetos.push_back( new Img() );
        }
        break;

    case '5':
        if ( incluirObjeto ) {
            objetos.push_back( new MFalcon() );
        }
        break;

    case 'S': {

        ofstream arquivo;
        arquivo.open("../text.txt");

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
                }else if ( objetos[i]->getName() == "Robo" ) {
                    arquivo << objetos[i]->t.x << " " << objetos[i]->t.y << " " << objetos[i]->t.z << " " << objetos[i]->a.x << " " << objetos[i]->a.y << " "
                    << objetos[i]->a.z << " " << objetos[i]->s.x << " " << objetos[i]->s.y << " " << objetos[i]->s.z << " " << "Robo" << " " << "\n";
                }else if ( objetos[i]->getName() == "MFalcon" ) {
                    arquivo << objetos[i]->t.x << " " << objetos[i]->t.y << " " << objetos[i]->t.z << " " << objetos[i]->a.x << " " << objetos[i]->a.y << " "
                    << objetos[i]->a.z << " " << objetos[i]->s.x << " " << objetos[i]->s.y << " " << objetos[i]->s.z << " " << "MFalcon" << " " << "\n";
                }
            }

        }

        arquivo.close();
      }
      break;

    case 'R': {

        ifstream arquivo;
        float t_x, t_y, t_z;
        float a_x, a_y, a_z;
        float s_x, s_y, s_z;
        string name;

        objetos.clear();
        arquivo.open("../text.txt");

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
                }else if ( name == "Robo" ) {
                    Objeto *robo = new Img ();
                    robo->selecionado = false;
                    robo->t.setVetor3D( t_x, t_y, t_z );
                    robo->a.setVetor3D( a_x, a_y, a_z );
                    robo->s.setVetor3D( s_x, s_y, s_z );

                    objetos.push_back( robo );
                }else if ( name == "MFalcon" ) {
                    Objeto *mfalcon = new MFalcon ();
                    mfalcon->selecionado = false;
                    mfalcon->t.setVetor3D( t_x, t_y, t_z );
                    mfalcon->a.setVetor3D( a_x, a_y, a_z );
                    mfalcon->s.setVetor3D( s_x, s_y, s_z );

                    objetos.push_back( mfalcon );
                }
            }
        }
        posSelecionado = -1;
        arquivo.close();
    }
    break;

    case 'd':
        objetos[posSelecionado]->originD = !objetos[posSelecionado]->originD;
        break;

    case 'I':
        if (posSelecionado >= 0 and posSelecionado < (int)objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;
        posSelecionado = posSelecionado%objetos.size();
        if (posSelecionado >= 0 and posSelecionado < (int)objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    case 'Q':
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

    case 'E':
        excluirObjeto = !excluirObjeto;
        break;

    case 'p':
        objetos.pop_back();
        break;

    case 'P':
        if ( excluirObjeto && objetos[posSelecionado]->selecionado ) {
            objetos.erase(objetos.begin()+posSelecionado);
        }
        break;

    case 'D':
        objetos[posSelecionado]->selecionado = !objetos[posSelecionado]->selecionado;
        break;

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

    case ',':
        glutGUI::projection = (glutGUI::projection+1) % 3;
        break;

    case '.':
        pontualLight = !pontualLight;
        break;

    case ';':
        drawShadow = !drawShadow;
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

