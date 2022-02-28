#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#include "funciones.h"
#include "rlutil.h"
#include "menu.h"

using namespace std;

int menu(){
    const int flechaAbajo = 14, flechaArriba = 15, enter = 1;
    int op = 1, posy = 0;

    do{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        marcador("JUGAR" ,55 ,10 , posy == 0);
        marcador("ESTADISTICAS" ,55 ,11 , posy == 1);
        marcador("CREDITOS" ,55 ,12 , posy == 2);
        marcador("SALIR" ,55 ,13 , posy == 3);

        rlutil::locate(53,10 + posy);
        cout << (char)62<<endl;

        switch(rlutil::getkey()){

        case flechaAbajo:
            rlutil::locate(53,10 + posy);
            cout << " "<<endl;
            posy--;
            if(posy<0){
                posy = 3;
                }
            break;

        case flechaArriba:
            rlutil::locate(53,10 + posy);
            cout << " "<<endl;
            posy++;
            if(posy>3){
                posy=0;
                }
            break;

        case enter:
            switch(posy){

                case Jugar:
                    return Jugar;
                    break;
                case Estadisticas:
                    return Estadisticas;
                    break;
                case Creditos:
                    return Creditos;
                    break;
                case Salir:
                    return Salir;
                    break;

                default:
                    break;

                break;
            }
            break;
        default:
            break;
        }
    } while(op != 0);

    return true;
}

