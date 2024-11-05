#include<iostream>
#include"rlutil.h"
#include"juego.h"
#include"menu.h"

using namespace std;

//1. Menu principal que permita iniciar un juego nuevo para un jugador, un juego nuevo para dos jugadores,
//mostrar la puntuacion mas alta y la opcion salir del juego. (switch).

//2. DADOS: tirada de seis dados

//3. RONDAS: Una ronda esta compuesta por 3 lanzamientos de dados.
    //3.1: Para el caso de la opcion para 2 jugadores, cada jugador debe completar una ronda (3 lanzamientos) alternativamente.

//4. PUNTAJE: El puntaje de la ronda sera el valor maximo de los puntos obtenidos en los 3 lanzamientos
    //4.1: Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento.
    //4.2: Si en un lanzamiento se obtiene una combinacion de 6 dados con valor 6, el puntaje total de la persona se reseta a 0

//5. INTERFAZ

//Funcion para ingresar los nombres de los jugadores.
string nombreJugador(int opcion){
    string vNombre[2];
    string nombreJugador1;
    string nombreJugador2;

    if(opcion == 1){
        system("cls");
        cout<<"Ingrese el nombre del jugador 1"<<endl;
        cin>>nombreJugador1;
        vNombre[0]={nombreJugador1};
        return vNombre[1];
    }

    else if(opcion == 2){
        system("cls");
        cout<<"Ingrese el nombre del jugador 1"<<endl;
        cin>>nombreJugador1;
        vNombre[0]={nombreJugador1};
        system("cls");
        cout<<"Ingrese el nombre del jugador 2"<<endl;
        cin>>nombreJugador2;
        vNombre[1]={nombreJugador2};
        return vNombre[1,2];
    }
}

//Funcion para mostrar el modo de juego
void ModoJuego(){
    system("cls");
    int opcionModo;
    do{
        cout<<"===Elija el modo de juego==="<<endl;
        cout<<"1. Un solo jugador"<<endl;
        cout<<"2. Dos jugadores"<<endl;
        //cout<<"3. MODO SIMULACION"<<endl;

        cin>>opcionModo;

        switch(opcionModo){
            case 1:
                nombreJugador(opcionModo);
                // Aca deberia ir la funcion Jugar(vNombre) pero no funciona.
            break;

            default:
                system("cls");
                cout<<"Ingrese una opcion valida"<<endl;
            break;
        }
    }
    while(opcionModo!=1 && opcionModo!=2);
}
