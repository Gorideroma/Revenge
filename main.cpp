#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#include "funciones.h"
#include "menu.h"
#include "rlutil.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Spanish");
    const int maxTamanioNombre = 20;
    char jugador1[maxTamanioNombre], jugador2[maxTamanioNombre];
    int puntajej1=0, puntajej2=0;
    bool exit = false, chau = false, mostrarPuntaje = false, mismosJugadores = false;
    char si_no;


    rlutil::hidecursor();
    srand(time(NULL));
    rlutil::setBackgroundColor(rlutil::COLOR::RED);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(25, 8); cout<<"########  ######## ##     ## ######## ##    ##  ######   ######## ####"<<endl;
    rlutil::locate(25, 9); cout<<"##     ## ##       ##     ## ##       ###   ## ##    ##  ##       ####"<<endl;
    rlutil::locate(25, 10);cout<<"##     ## ##       ##     ## ##       ####  ## ##        ##       ####"<<endl;
    rlutil::locate(25, 11);cout<<"########  ######   ##     ## ######   ## ## ## ##   #### ######    ## "<<endl;
    rlutil::locate(25, 12);cout<<"##   ##   ##        ##   ##  ##       ##  #### ##    ##  ##           "<<endl;
    rlutil::locate(25, 13);cout<<"##    ##  ##         ## ##   ##       ##   ### ##    ##  ##       ####"<<endl;
    rlutil::locate(25, 14);cout<<"##     ## ########    ###    ######## ##    ##  ######   ######## ####"<<endl<<endl;;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(41, 30);
    system("pause");
    rlutil::cls();

    while(exit == false){
       switch(menu()){
        case Jugar:
            inicio(jugador1, jugador2, mostrarPuntaje, mismosJugadores);
            juego(jugador1, jugador2, puntajej1, puntajej2, mostrarPuntaje, mismosJugadores);
            rlutil::cls();
            break;

        case Estadisticas:
            if(mostrarPuntaje==true)
            {
                estadisticas(jugador1, jugador2, puntajej1, puntajej2, mostrarPuntaje);
            } else {
                rlutil::cls();
                cout<<"Todavia no hay puntajes para mostrar"<<endl;
                rlutil::locate(41, 30);
                system("pause");
            }
            rlutil::cls();
            break;

        case Creditos:
            creditos();
            rlutil::cls();
            break;

        case Salir:
            rlutil::cls();
                cout << "¿Seguro que queres salir? (y/n): ";
                while(chau == false){
                    si_no = getch();
                    if(si_no == 'y'){
                        chau = true;
                        exit = true;
                    }else if(si_no == 'n'){
                        chau = true;
                        rlutil::cls();
                    }
                }
                chau = false;
            break;

        default:
            break;
       }
    }
    return 0;
}

