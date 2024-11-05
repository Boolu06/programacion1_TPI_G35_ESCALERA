#include<iostream>
#include<ctime>
#include "rlutil.h"
#include "menu.h"
#include "juego.h"

using namespace std;



int main(){
    srand(time(0)); // Establece la semilla para numeros random
    rlutil::setColor(rlutil::LIGHTGREEN);
    int opcion;

    do{
        cout<<"===JUEGO DE LA ESCALERA==="<<endl;
        cout<<"1. Jugar"<<endl;
        cout<<"2. Puntuacion Maxima"<<endl;
        cout<<"0. Salir del juego"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                ModoJuego();
                //Funcion ronda
            break;

            case 0:
                system("cls");
                cout<<"Gracias por jugar!"<<endl;
                system("pause");
                return 0;
            break;

            default:
                system("cls");
                cout<<"Ingrese una opcion valida"<<endl;
            break;
        }
    }
    while(opcion!=0);

    return 0;
}

