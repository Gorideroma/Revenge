#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>

#include "funciones.h"
#include "menu.h"
#include "rlutil.h"

using namespace std;


void marcador(const char* text, int posx, int posy, bool seleccionado)
{
    if(seleccionado)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }

    rlutil::locate(posx, posy);
    cout<< text <<endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void lanzarDados(int v[],int cant, int cantCaras, int cantDados)
{
    for(int i=0; i<cantDados && i<cant; i++)
    {
        v[i] = 1 + rand() % cantCaras;

    }
}

void mostrarDados(int v[],int cant, int cantDados)
{
    for (int i = 0; i < cantDados && v[i] != 0; i++)
    {
        cout << "|" << v[i] << "| ";
    }

}

void resetDados(int v[], int cant, int cantCaras)
{
    for(int i = 0; i < cant; i++)
    {
        v[i] = 0;
    }
}

int sumarDados(int v[], int cant)
{
    int suma = 0;
    for (int i=0 ; i<cant ; i++)
    {
        suma += v[i];
    }
    return suma;
}

void instruccionesJuego()
{
    rlutil::setBackgroundColor(rlutil::COLOR::RED);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    cout << "*****************************************************************************************************************" << endl;
    cout << "* Revenge es un juego de dados de dos jugadores en el que interviene el azar y las matemáticas.                 *" << endl;
    cout << "* El objetivo general del juego es sumar la mayor cantidad de puntos en un total de 5 rondas.                   *" << endl;
    cout << "* El juego se juega con seis dados de seis caras por cada jugador más dos dados de doce caras,                  *" << endl;
    cout << "* que se comparten entre los dos contrincantes entre ronda y ronda.                                             *" << endl;
    cout << "* Primero se lanzara un dado por jugador para determinar quien comienza la ronda.                               *" << endl;
    cout << "* Luego cada jugador a su turno, luego de lanzar sus seis dados, seleccionara los dados que crea necesarios     *" << endl;
    cout << "* para alcanzar el numero objetivo, que se compondra de la suma de los dos dados compartidos de doce caras.     *" << endl;
    cout << "* Atencion! Una vez seleccionado un dado NO hay vuleta atras!                                                   *" << endl;
    cout << "* En caso de no alcanzar el numero objetivo seleccionando todos los dados disponibles, o pasarse de ese numero, *" << endl;
    cout << "* se pierde la ronda y nuestro contrincante nos pasara un dado de su stock, si es que le quedan mas de uno.     *" << endl;
    cout << "* Si logramos una tirada exitosa, es decir, alcanzamos el numero objetivo, sumaremos la cantidad de puntos      *" << endl;
    cout << "* equivalentes a la suma del valor de los dados selecionados multiplicado por la cantidad de los mismos.        *" << endl;
    cout << "* Si ocurriera que en esa misma tirada usaramos todos los dados disponibles, ganariamos automaticamente         *" << endl;
    cout << "* y sumariamos diezmil puntos.                                                                                  *" << endl;
    cout << "*                                                                                                               *" << endl;
    cout << "*BUENA SUERTE!                                                                                                  *" << endl;
    cout << "*****************************************************************************************************************" << endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(41, 30);
    system("pause");
}

int primeraTirada(int v1[], int dados1, int v2[], int dados2, char jugador1[], char jugador2[], int cantCaras, int dadoInicio)
{
    const int primerJugador = 1, segundoJugador = 2;
    int resultado = 0;
    do
    {
        cout << "Primera tirada de un solo dado para definir que jugador comienza la ronda" << endl;
        rlutil::locate(41, 30);
        system("pause");
        rlutil::cls();
        cout << "Tira el jugador: " << jugador1 << " = ";
        lanzarDados(v1, dados1 = 1, cantCaras, dadoInicio);
        mostrarDados(v1, dados1, dadoInicio);
        cout << endl << endl;
        cout << "Tira el jugador: " << jugador2 << " = ";
        lanzarDados(v2, dados2 = 1, cantCaras, dadoInicio);
        mostrarDados(v2, dados2, dadoInicio);
        cout << endl;
        cout << endl;
        if(v1[0] > v2[0])
        {
            return primerJugador;
        }
        else if(v2[0] > v1[0])
        {
            return segundoJugador;
        }
        else
        {
            cout << "Empate!" << endl;
            rlutil::locate(41, 30);
            system("pause");
            rlutil::cls();
        }
    }
    while (resultado == 0);

}
void estadisticas(char jugador1[], char jugador2[], int puntajej1, int puntajej2, bool mostrarPuntaje)
{
    //Mostrar los puntajes acumulados por los jugadores
    rlutil::cls();
    if(puntajej1>puntajej2){
        cout << jugador1 << " tiene: " << puntajej1 << " puntos"<<endl;
        cout << jugador2 << " tiene: " << puntajej2 << " puntos"<<endl;
        rlutil::locate(41, 30);
        system("pause");
    } else {
        cout << jugador2 << " tiene: " << puntajej2 << " puntos"<<endl;
        cout << jugador1 << " tiene: " << puntajej1 << " puntos"<<endl;
        rlutil::locate(41, 30);
        system("pause");
    }

}
void creditos()
{
    //Info sobre mi.
    rlutil::setBackgroundColor(rlutil::COLOR::RED);
    rlutil::setColor(rlutil::COLOR::YELLOW);
    rlutil::locate(25, 8); cout<<"######################################################################"<<endl;
    rlutil::locate(25, 9); cout<<"##                                                                  ##"<<endl;
    rlutil::locate(25, 10);cout<<"##                        AUTOR: Daniel Romani                      ##"<<endl;
    rlutil::locate(25, 11);cout<<"##                           LEGAJO: 25596                          ##"<<endl;
    rlutil::locate(25, 12);cout<<"##                             febrero/22                           ##"<<endl;
    rlutil::locate(25, 13);cout<<"##                                                                  ##"<<endl;
    rlutil::locate(25, 14);cout<<"######################################################################"<<endl<<endl;;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(41, 30);
    system("pause");
    rlutil::cls();
}
void juego(char jugador1[], char jugador2[], int &puntajej1, int &puntajej2, bool &mostrarPuntaje, bool &mismosJugadores)
{
    const int dados1 = 12, dados2 = 12, dadosEsp = 2, dadoInicio = 1, primerJugador = 1, segundoJugador = 2, cantRondas = 5;
    const int carasDadosEsp = 12, dadosStockInicial = 6, carasDadosComunes = 6;
    int sumaSeleccionada = 0, numeroObjetivo = 0, cantCaras = carasDadosComunes;
    int vDados1[dados1] = {}, vDados2[dados2] = {}, vDadosEsp[dadosEsp];
    int cantDados1 = dadosStockInicial, cantDados2 = dadosStockInicial, contador = 0;
    int acuDados = 0, resultado = 0, acuPuntos = 0;
    int comienza = 0, ganador = 0, puntajeTempJ1, puntajeTempJ2;
    bool bonusMismaCara = true;
    rlutil::cls();
    if(mismosJugadores == false){
        puntajej1 = 0;
        puntajej2 = 0;
    }
    comienza = primeraTirada(vDados1, dados1, vDados2, dados2, jugador1, jugador2, cantCaras, dadoInicio);
    if(comienza == primerJugador)
    {
        cout << "El jugador: " << jugador1 << " Empieza la ronda!" << endl;
    }
    else if(comienza == segundoJugador)
    {
        cout << "El jugador: " << jugador2 << " Empieza la ronda!" << endl;
    }
    rlutil::locate(41, 30);
    system("pause");
    rlutil::cls();
    puntajeTempJ1 = 0;
    puntajeTempJ2 = 0;
    for(int i=0 ; i<cantRondas ; i++)
    {
        lanzarDados(vDadosEsp, dadosEsp, cantCaras = carasDadosEsp, dadosEsp);
        numeroObjetivo = sumarDados(vDadosEsp, dadosEsp);

        if(comienza == primerJugador)
        {
            cout << "Dados compartidos: ";
            mostrarDados(vDadosEsp, dadosEsp, dadosEsp);
            cout << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            cout << "Puntaje de " << jugador1 << ": [" << puntajeTempJ1 << "] - Puntaje de " << jugador2 << ": [" << puntajeTempJ2 << "]" <<endl;
            cout << "Dados stock de " << jugador1 << ": [" << cantDados1 << "] - Dados stock de " << jugador2 << ": [" << cantDados2 << "]" <<endl;
            rlutil::setBackgroundColor(rlutil::COLOR::CYAN);cout << "El numero objetivo sera: " << numeroObjetivo; rlutil::setBackgroundColor(rlutil::COLOR::BLACK); cout << " [numero de ronda: " << i+1 << "]" << "[Es el turno de: " << jugador1 << "]"<<endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            lanzarDados(vDados1, dados1, cantCaras = carasDadosComunes, cantDados1);
            mostrarDados(vDados1, dados1, cantDados1);
            resultado = selectDados(vDados1, cantDados1, acuDados, contador=0, numeroObjetivo, acuPuntos, bonusMismaCara);
            switch(resultado)
            {
                case pierdeRonda: //jugador 1 pierde, recibe 1 dados de jugador 2
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    cout << "Perdiste"<<endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    if(cantDados2>1){
                    cantDados1++;
                    cantDados2--;
                    cout << "Recibis 1 dado de tu contrincante" << endl;
                    } else {
                    cout << "Recibis 0 dado de tu contrincante" << endl;
                    }
                    break;
                case ganaRonda: //jugador 1 gana la ronda, le pasa sus dados a jugador 2
                    rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                    cout << "Tirada exitosa!" << endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    cantDados2 += contador;
                    cantDados1 -= contador;
                    puntajeTempJ1 += acuPuntos;
                    cout << "Acumulaste " << acuPuntos << " puntos" << endl;
                    cout << "Tu contrincante recibe " << contador << " dados" << endl;
                    break;
                case ganaJuego: //jugador 1 gana el juego
                    mostrarPuntaje = true;
                    if(bonusMismaCara == true){
                        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                        cout << "**********************************************" << endl;
                        cout << "** Tirada exitosa y usaste todos los dados. **" << endl;
                        cout << "**          Sumaste 20.000 puntos!          **" << endl;
                        cout << "**********************************************" << endl;
                        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    } else {
                        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                        cout << "**********************************************" << endl;
                        cout << "** Tirada exitosa y usaste todos los dados. **" << endl;
                        cout << "**          Sumaste 10.000 puntos!          **" << endl;
                        cout << "**********************************************" << endl;
                        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    }
                    break;
            }
            if(resultado==ganaJuego){
                ganador = primerJugador;
                puntajeTempJ1 += acuPuntos;
                break;
            }
            acuPuntos=0;
            resetDados(vDados1, dados1, cantCaras);
            rlutil::locate(41, 30);
            system("pause");
            rlutil::cls();
            cout << "Dados compartidos: ";
            mostrarDados(vDadosEsp, dadosEsp, dadosEsp);
            cout << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            cout << "Puntaje de " << jugador1 << ": [" << puntajeTempJ1 << "] - Puntaje de " << jugador2 << ": [" << puntajeTempJ2 << "]" <<endl;
            cout << "Dados stock de " << jugador1 << ": [" << cantDados1 << "] - Dados stock de " << jugador2 << ": [" << cantDados2 << "]" <<endl;
            rlutil::setBackgroundColor(rlutil::COLOR::CYAN);cout << "El numero objetivo sera: " << numeroObjetivo; rlutil::setBackgroundColor(rlutil::COLOR::BLACK); cout << " [numero de ronda: " << i+1 << "]" << "[Es el turno de: " << jugador2 << "]"<<endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            lanzarDados(vDados2, dados2, cantCaras, cantDados2);
            mostrarDados(vDados2, dados2, cantDados2);
            resultado = selectDados(vDados2, cantDados2, acuDados, contador=0, numeroObjetivo, acuPuntos, bonusMismaCara);
            switch(resultado)
            {
                case pierdeRonda: //jugador 2 pierde, recibe 1 dados de jugador 1
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    cout << "Perdiste"<<endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    if(cantDados1>1){
                    cantDados2++;
                    cantDados1--;
                    cout << "Recibis 1 dado de tu contrincante" << endl;
                    } else {
                    cout << "Recibis 0 dado de tu contrincante" << endl;
                    }
                    break;
                case ganaRonda: //jugador 2 gana la ronda, le pasa sus dados a jugador 1
                    rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                    cout << "Tirada exitosa!" << endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    cantDados1 += contador;
                    cantDados2 -= contador;
                    puntajeTempJ2 += acuPuntos;
                    cout << "Acumulaste " << acuPuntos << " puntos" << endl;
                    cout << "Tu contrincante recibe " << contador << " dados" << endl;
                    break;
                case ganaJuego: //jugador 2 gana el juego
                    mostrarPuntaje=true;
                    if(bonusMismaCara == true){
                        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                        cout << "**********************************************" << endl;
                        cout << "** Tirada exitosa y usaste todos los dados. **" << endl;
                        cout << "**          Sumaste 20.000 puntos!          **" << endl;
                        cout << "**********************************************" << endl;
                        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    } else {
                        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                        cout << "**********************************************" << endl;
                        cout << "** Tirada exitosa y usaste todos los dados. **" << endl;
                        cout << "**          Sumaste 10.000 puntos!          **" << endl;
                        cout << "**********************************************" << endl;
                        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    }
                    break;
            }
            if(resultado==ganaJuego){
                ganador = segundoJugador;
                puntajeTempJ2 += acuPuntos;
                break;
            }
            acuPuntos=0;
            resetDados(vDados2, dados2, cantCaras);
            rlutil::locate(41, 30);
            system("pause");
            rlutil::cls();

        } else if(comienza == segundoJugador)
        {
            cout << "Dados compartidos: ";
            mostrarDados(vDadosEsp, dadosEsp, dadosEsp);
            cout << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            cout << "Puntaje de " << jugador1 << ": [" << puntajeTempJ1 << "] - Puntaje de " << jugador2 << ": [" << puntajeTempJ2 << "]" <<endl;
            cout << "Dados stock de " << jugador1 << ": [" << cantDados1 << "] - Dados stock de " << jugador2 << ": [" << cantDados2 << "]" <<endl;
            rlutil::setBackgroundColor(rlutil::COLOR::CYAN);cout << "El numero objetivo sera: " << numeroObjetivo; rlutil::setBackgroundColor(rlutil::COLOR::BLACK); cout << " [numero de ronda: " << i+1 << "]" << "[Es el turno de: " << jugador2 << "]"<<endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            lanzarDados(vDados2, dados2, cantCaras = carasDadosComunes, cantDados2);
            mostrarDados(vDados2, dados2, cantDados2);
            resultado = selectDados(vDados2, cantDados2, acuDados, contador=0, numeroObjetivo, acuPuntos, bonusMismaCara);
            switch(resultado)
            {
                case pierdeRonda: //jugador 2 pierde la ronda, recibe 1 dados de jugador 1
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    cout << "Perdiste"<<endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    if(cantDados1>1){
                    cantDados2++;
                    cantDados1--;
                    cout << "Recibis 1 dado de tu contrincante" << endl;
                    } else {
                    cout << "Recibis 0 dado de tu contrincante" << endl;
                    }
                    break;
                case ganaRonda: //jugador 2 gana la ronda, le pasa sus dados a jugador 1
                    rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                    cout << "Tirada exitosa" << endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    cantDados1 += contador;
                    cantDados2 -= contador;
                    puntajeTempJ2 += acuPuntos;
                    cout << "Acumulaste " << acuPuntos << " puntos" << endl;
                    cout << "Tu contrincante recibe " << contador << " dados" << endl;
                    break;
                case ganaJuego: //jugador 2 gana el juego
                    mostrarPuntaje=true;
                    if(bonusMismaCara == true){
                        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                        cout << "**********************************************" << endl;
                        cout << "** Tirada exitosa y usaste todos los dados. **" << endl;
                        cout << "**          Sumaste 20.000 puntos!          **" << endl;
                        cout << "**********************************************" << endl;
                        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    } else {
                        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                        cout << "**********************************************" << endl;
                        cout << "** Tirada exitosa y usaste todos los dados. **" << endl;
                        cout << "**          Sumaste 10.000 puntos!          **" << endl;
                        cout << "**********************************************" << endl;
                        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    }
                    break;
            }
            if(resultado==ganaJuego){
                ganador = segundoJugador;
                puntajeTempJ2 += acuPuntos;
                break;
            }
            acuPuntos=0;
            resetDados(vDados2, dados2, cantCaras);
            rlutil::locate(41, 30);
            system("pause");
            rlutil::cls();
            cout << "Dados compartidos: ";
            mostrarDados(vDadosEsp, dadosEsp, dadosEsp);
            cout << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            cout << "Puntaje de " << jugador1 << ": [" << puntajeTempJ1 << "] - Puntaje de " << jugador2 << ": [" << puntajeTempJ2 << "]" <<endl;
            cout << "Dados stock de " << jugador1 << ": [" << cantDados1 << "] - Dados stock de " << jugador2 << ": [" << cantDados2 << "]" <<endl;
            rlutil::setBackgroundColor(rlutil::COLOR::CYAN);cout << "El numero objetivo sera: " << numeroObjetivo; rlutil::setBackgroundColor(rlutil::COLOR::BLACK); cout << " [numero de ronda: " << i+1 << "]" << "[Es el turno de: " << jugador1 << "]"<<endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            lanzarDados(vDados1, dados1, cantCaras, cantDados1);
            mostrarDados(vDados1, dados1, cantDados1);
            resultado = selectDados(vDados1, cantDados1, acuDados, contador=0, numeroObjetivo, acuPuntos, bonusMismaCara);
            switch(resultado)
            {
                case pierdeRonda: //jugador 1 pierde la ronda, recibe 1 dados de jugador 2
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    cout << "Perdiste"<<endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    if(cantDados2>1){
                    cantDados1++;
                    cantDados2--;
                    cout << "Recibis 1 dado de tu contrincante" << endl;
                    } else {
                    cout << "Recibis 0 dado de tu contrincante" << endl;
                    }
                    break;
                case ganaRonda: //jugador 1 gana la ronda, le pasa sus dados a jugador 2
                    rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                    cout << "Tirada exitosa!" << endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    cantDados2 += contador;
                    cantDados1 -= contador;
                    puntajeTempJ1 += acuPuntos;
                    cout << "Acumulaste " << acuPuntos << " puntos" << endl;
                    cout << "Tu contrincante recibe " << contador << " dados" << endl;
                    break;
                case ganaJuego: //jugador 1 gana el juego
                    mostrarPuntaje=true;
                    if(bonusMismaCara == true){
                        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                        cout << "**********************************************" << endl;
                        cout << "** Tirada exitosa y usaste todos los dados. **" << endl;
                        cout << "**          Sumaste 20.000 puntos!          **" << endl;
                        cout << "**********************************************" << endl;
                        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    } else {
                        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                        cout << "**********************************************" << endl;
                        cout << "** Tirada exitosa y usaste todos los dados. **" << endl;
                        cout << "**          Sumaste 10.000 puntos!          **" << endl;
                        cout << "**********************************************" << endl;
                        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    }
                    break;
            }
            if(resultado==ganaJuego){
                ganador = primerJugador;
                puntajeTempJ1 += acuPuntos;
                break;
            }
            acuPuntos=0;
            resetDados(vDados1, dados1, cantCaras);
            rlutil::locate(41, 30);
            system("pause");
            rlutil::cls();
        }
    }
    puntajej1 += puntajeTempJ1;
    puntajej2 += puntajeTempJ2;
    mostrarPuntaje=true; //Habilita las estadisticas
    if (ganador == primerJugador || puntajeTempJ1>puntajeTempJ2){
        cout << "El jugador " << jugador1 << " gana el juego!" << endl;
        rlutil::locate(41, 30);
        system("pause");
    }
    else if(ganador == segundoJugador|| puntajeTempJ2>puntajeTempJ1){
        cout << "El jugador " << jugador2 << " gana el juego!" << endl;
        rlutil::locate(41, 30);
        system("pause");
    } else {
        cout << "Empate!" << endl;
        rlutil::locate(41, 30);
        system("pause");
    }
}
void inicio(char jugador1[], char jugador2[], bool &mostrarPuntaje, bool &mismosJugadores)
{
    char instrucciones, repetirJugadores;
    bool verificar = false;
    rlutil::cls();
    cout << "############################" << endl;
    cout << "## Bienvenidos a REVENGE! ##" << endl;
    cout << "############################" << endl << endl;
    cout << "¿Desea conocer las instrucciones del juego? (y/n)" << endl << endl;
    while (verificar == false){
        instrucciones = getch();
        if(instrucciones == 'y'){
            instruccionesJuego();
            verificar = true;
        }else if(instrucciones == 'n'){
            cout << "En ese caso, A JUGAR!" << endl;
            rlutil::locate(41, 30);
            system("pause");
            verificar = true;
        }
    }
    verificar = false;
    rlutil::cls();
    if(mostrarPuntaje == true){
        cout << "¿Usar los mismos jugaodres? (y/n)" << endl;
        while (verificar == false) {
            repetirJugadores = getch();
            if(repetirJugadores == 'y'){
                mismosJugadores = true;
                verificar = true;
            } else if(repetirJugadores == 'n'){
                rlutil::cls();
                cout << "Ingrese el nombre de los nuevos jugadores" << endl;
                mismosJugadores = false;
                verificar = true;
            }
          }
    } else {
        cout << "Para comenzar ingrese el nombre de los jugadores" << endl;
    }
    verificar = false;
    if(mismosJugadores == false){
    rlutil::locate(1, 3);
    cout << "Jugador Numero 1: ";
    do
    {
        cin.getline(jugador1, 20, '\n');
    }
    while(strlen(jugador1) == 0);
    cout << "Jugador Numero 2: ";
    do
    {
        cin.getline(jugador2, 20, '\n');
    }
    while(strlen(jugador2) == 0);
    }
}
int selectDados(int v[], int tam, int acuDados, int &contador, int numeroObjetivo, int &acuPuntos, bool &bonusMismaCara)
{
    const int intervaloOpciones = 4, flechaIzquierda = 16, flechaDerecha = 17, enter = 1;
    int posx = 0, salir = 1, pos, compareBonus = 0;
    bool cancel[tam] = {}, banderaBonus = false, verifBonus = true;

    do
    {
        rlutil::locate(2 + posx, 9);
        cout << (char)94<<endl;
        //calculo posición en el vector de dados según x
        pos = posx/intervaloOpciones;
        switch(rlutil::getkey())
        {
        case flechaIzquierda:
            if(pos>0 && v[pos-1] != 0) //si hay dado a la izq y no estoy en borde...
            {
                rlutil::locate(2 + posx, 9);
                cout << " " <<endl;
                posx-=intervaloOpciones;
            }
            if(posx<0)
                posx=0;
            break;

        case flechaDerecha:
            if(pos<tam && v[pos+1] != 0) //si no estoy en última pos y además hay dado a la derecha...
            {
                rlutil::locate(2 + posx, 9);
                cout << " " <<endl;
                posx+=intervaloOpciones;
            }
            break;

        case enter:
            if(cancel[pos] == false)
            {
                rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
                rlutil::locate(1+posx, 7);
                cout << "|" << v[pos] << "|";
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                //rlutil::setChar('x');
                contador++;
                acuDados += v[pos];
                if(banderaBonus == false){
                    compareBonus = v[pos];
                    //cout << "verif: " << verificarBonus << endl;
                    //system("pause");
                    banderaBonus = true;
                }
                if(compareBonus != v[pos]){
                    verifBonus = false;
                }
                rlutil::locate(1, 10);
                cout << "suma: " << acuDados << endl;
                cout << "cantidad de dados: " << contador<<endl;
                cancel[pos] = true;

            }
            if(acuDados == numeroObjetivo)
            {
                if(contador >= tam){
                    if(verifBonus == true && contador > 1){
                        cout << "--------------" << endl;
                        cout << "doble puntaje!" << endl;
                        cout << "--------------" << endl;
                        acuPuntos+=20000;
                        bonusMismaCara = verifBonus;
                    } else {
                        acuPuntos+=10000;
                        bonusMismaCara = verifBonus;
                    }
                    return ganaJuego;//ganoJuego;
                } // se eligieron todos los dados e igualò el objetivo, ganò
                acuPuntos += acuDados*contador;
                if(verifBonus == true && contador > 1){
                    cout << "--------------" << endl;
                    cout << "doble puntaje!" << endl;
                    cout << "--------------" << endl;
                    acuPuntos*=2;
                    bonusMismaCara = verifBonus;
                }
                salir = 0;
                return ganaRonda;
            }
            else if(acuDados > numeroObjetivo)
            {
                salir = 0;
                return pierdeRonda;
            }
            // chequear si se eligieron todos los dados disponibles
            else if (contador >= tam)
            {
                salir = 0;
                return pierdeRonda;
            }
            break;

        default:
            break;
        }
    }
    while(salir != 0);
    rlutil::locate(41, 30);
    system("pause");
}
