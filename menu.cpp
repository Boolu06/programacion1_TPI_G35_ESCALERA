#include<iostream>
#include"rlutil.h"
#include"juego.h"
#include"menu.h"
#include"dados.h"

using namespace std;

int SalirJuego(){
    for(int x=50;x<=90;x++){
        rlutil::locate(x,12);
        cout<<(char)205;
    }
    rlutil::locate(61,14);cout<<"Gracias por jugar!"<<endl;
    for(int x2=50;x2<=90;x2++){
        rlutil::locate(x2,16);
        cout<<(char)205;
    }
    rlutil::locate(53,17);system("pause");
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
        rlutil::locate(53,11);cout<<"===ELIJA EL MODO DE JUEGO==="<<endl;
        rlutil::resetColor();
        rlutil::locate(54,12);cout<<"1. Un jugador"<<endl;
        rlutil::locate(54,13);cout<<"2. Dos jugadores"<<endl;
        rlutil::locate(54,14);cout<<"3. Modo Simulado un jugador"<<endl;
        rlutil::locate(54,15);cout<<"4. Modo Simulado dos jugadores"<<endl;
        rlutil::locate(54,16);cout<<"5. Volver al menu principal"<<endl;
        rlutil::locate(54,17);cin>>opcionModo;

        switch(opcionModo){
            case 1:
                system("cls");
                Jugar(nombrePuntajeMaximo,opcionModo, false,puntajeMaximo);
            break;

           case 2:
                system("cls");
                Jugar(nombrePuntajeMaximo,opcionModo, false,puntajeMaximo);
            break;

            case 3:
                system("cls");
                Jugar(nombrePuntajeMaximo,opcionModo, true,puntajeMaximo);
            break;

            case 4:
                system("cls");
                Jugar(nombrePuntajeMaximo,opcionModo, true,puntajeMaximo);
            break;

            case 5:
                system("cls");
                rlutil::locate(58,13);cout<<"Volviendo..."<<endl;
                rlutil::msleep(500);
                system("cls");

            break;

            default:
                system("cls");
                rlutil::locate(54,18);
                rlutil::setColor(rlutil::RED);cout<<"Ingrese una opcion valida"<<endl;
            break;
        }
    }
    while(opcionModo!=1 && opcionModo!=2 && opcionModo!=3 && opcionModo !=4 && opcionModo!=5);
}
