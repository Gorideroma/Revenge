#include <iostream>
#include <time.h>
#include <cstdlib>


#include "rlutil.h"

using namespace std;

void marcador(const char* text, int posx, int posy, bool seleccionado){
    if(seleccionado){
        rlutil::setBackgroundColor(rlutil::COLOR::MAGENTA);
    } else {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }

    rlutil::locate(posx, posy);
    cout<< text <<endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

int main()
{
    //Menu principal
    int op = 1, y = 0;
    rlutil::hidecursor();

    do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        marcador("JUGAR" ,55 ,10 , y == 0);
        marcador("ESTADISTICAS" ,55 ,11 , y == 1);
        marcador("CREDITOS" ,55 ,12 , y == 2);
        marcador("SALIR" ,55 ,13 , y == 3);

        rlutil::locate(53,10 + y);
        cout << (char)62<<endl;

        switch(rlutil::getkey()){

        case 14:
            rlutil::locate(53,10 + y);
            cout << " "<<endl;
            y--;
            if(y<0){
                y = 3;
            }
            break;
        case 15:
            rlutil::locate(53,10 + y);
            cout << " "<<endl;
            y++;
            if(y>3){
                y=0;
            }
            break;
        case 1:
            switch(y){

                case 3:
                    op = 0;

                default:
                    break;

                break;
            }
        default:
            break;
        }
    } while(op != 0);
        //JUGAR
            //SOLICITA NOMBRE DE JUGADORES
            //SE DEBE MOSTRAR INFO RELATIVA AL JUEGO
        //ESTADISTICAS
            //NOMBRE DEL JUGADOR CON MEJOR PUNTAJE Y EL PUNTAJE
        //CREDITOS
            //NOMBRE, APELLIDO Y LEGAJO DE INTEGRANTES DEL EQUIPO
        //SALIR
            //SALIR DEL JUEGO PREVIA CONFIRMACION
    /**************************************************************************/
    //COMIENZA EL JUEGO
    /**************************************************************************/

    //CADA UNO TIRA DADO PARA ELEGIR QUIEN EMPIEZA
        //LA TIRADA MAYOR COMIENZA
        //EN CASO DE EMPATE SE REPITE
    //TIRAR DADOS
        //PRIMERO LOS DOS DE 12 CARAS
        //LUEGO LOS DE 6 CARAS(DADOS STOCK)




    return 0;
}
