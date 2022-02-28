#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

enum jugadas{pierdeRonda, ganaRonda, ganaJuego};

void marcador(const char* text, int posx, int posy, bool seleccionado);

int selectDados(int v[], int tam, int acuDados, int &contador, int numeroObjetivo, int &acuPuntos, bool &bonusMismaCara);

void juego(char jugador1[], char jugador2[], int &puntajej1, int &puntajej2, bool &mostrarPuntaje, bool &mismosJugadores);

int primeraTirada(int v1[], int dados1, int v2[], int dados2, char jugador1[], char jugador2[], int cantCaras, int dadoInicio);

void lanzarDados(int v[],int cant, int cantCaras, int cantDados);

void mostrarDados(int v[],int cant, int cantDados);

int sumarDados(int v[], int cant);

void instruccionesJuego();

void resetDados(int v[], int cant, int cantCaras);

void estadisticas(char jugador1[], char jugador2[], int puntajej1, int puntajej2, bool mostrarPuntaje);

void creditos();

void inicio(char jugador1[], char jugador2[], bool &mostrarPuntaje, bool &mismosJugadores);

#endif // FUNCIONES_H_INCLUDED
