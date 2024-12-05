#include<iostream>
#include<ctime>
#include"rlutil.h"
#include"menu.h"
#include"juego.h"
#include"dados.h"

using namespace std;

int main(){
    srand(time(0)); // Establece la semilla para numeros random
    int opcion;
    int puntajeMaximo = 0;
    bool root = true;
    string nombrePuntajeMaximo;

    do{
        rlutil::saveDefaultColor();
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::locate(54,11); cout<<"===JUEGO DE LA ESCALERA==="<<endl;
        rlutil::resetColor();
        rlutil::locate(54,12); cout<<"1. Jugar"<<endl;
        rlutil::locate(54,13); cout<<"2. Puntuacion Maxima"<<endl;
        rlutil::locate(54,14); cout<<"0. Salir del juego"<<endl;
        rlutil::locate(54,15); cin>>opcion;
        system("cls");

        switch(opcion){
            case 1:
                ModoJuego(puntajeMaximo, nombrePuntajeMaximo);
            break;

            case 2:
                ImprimirPuntuacionMaxima(puntajeMaximo, nombrePuntajeMaximo, root);
            break;

            case 0:
                SalirJuego();
            break;

            default:
                system("cls");
                rlutil::locate(54,16);cout<<"Ingrese una opcion valida"<<endl;
            break;
        }
    }
    while(opcion!=0);
    return 0;
}

