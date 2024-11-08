#include<iostream>
#include"rlutil.h"
#include"juego.h"
#include"menu.h"
#include"dados.h"

using namespace std;

//Funcion para ingresar los nombres de los jugadores.
void ImprimirMenuNombre(int opcion){
    if(opcion == 1 || opcion == 2){
        system("cls");
        rlutil::saveDefaultColor();
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate(50,11);cout<<"===Ingrese el nombre del jugador 1==="<<endl;
        rlutil::resetColor();
    }
}

int SalirJuego(){
    system("cls");
    cout<<"Gracias por jugar!"<<endl;
    system("pause");
    return 0;
}
//Funcion para mostrar el modo de juego
void ModoJuego(int& puntajeMaximo, string& nombrePuntajeMaximo){
    system("cls");
    int opcionModo;
    rlutil::saveDefaultColor();

    do{
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate(53,11);cout<<"===Elija el modo de juego==="<<endl;
        rlutil::resetColor();
        rlutil::locate(54,12);cout<<"1. Un solo jugador"<<endl;
      //  rlutil::locate(54,13);cout<<"2. Modo Simulado"<<endl;
        rlutil::locate(54,14);cin>>opcionModo;

        switch(opcionModo){
            case 1:
                system("cls");
                ImprimirMenuNombre(opcionModo);
                Jugar(nombrePuntajeMaximo, false,puntajeMaximo);
            break;

           /* case 2:
                system("cls");
                ImprimirMenuNombre(opcionModo);
                Jugar(nombrePuntajeMaximo, true,puntajeMaximo);
            break;
            */

            default:
                system("cls");
                cout<<"Ingrese una opcion valida"<<endl;
            break;
        }
    }
    while(opcionModo!=1 && opcionModo!=2);
}
