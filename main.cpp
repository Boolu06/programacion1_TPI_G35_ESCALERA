#include<iostream>
#include<ctime>
#include"rlutil.h"

using namespace std;

/* Dado representado graficamente a lo cavernicola
cout << " ------- \n";
cout << "| o   o |\n";
cout << "| o   o |\n";
cout << "| o   o |\n";
cout << " -------  \n";
*/

//Funcion de tirada de dado
int tiradaDado(){
    return rand() % 6 + 1;
}

//Funcion + vector - tirar 6 dados
void SeisDados(){
    int i;
    const int TAM=6; // Constante que se usa en el for
    int vDado[TAM];

    for(i=0;i<TAM;i++){
        vDado[i]=tiradaDado(); // Vector de 6(TAM) componentes que contienen numeros random del 1 al 6
    }
}

//Funcion sumar? vector de 6 dados 3 veces (3 turnos)


//Funcion de ronda
//int Ronda()

//Funcion para ingresar los nombres de los jugadores.
void nombreJugador(int opcion){
    string nombreJugador1;
    string nombreJugador2;

    if(opcion == 1){
        system("cls");
        cout<<"Ingrese el nombre del jugador 1"<<endl;
        cin>>nombreJugador1;
    }

    else if(opcion == 2){
        system("cls");
        cout<<"Ingrese el nombre del jugador 1"<<endl;
        cin>>nombreJugador1;
        system("cls");
        cout<<"Ingrese el nombre del jugador 2"<<endl;
        cin>>nombreJugador2;
    }
}

//Funcion para mostrar el modo de juego

void ModoJuego(){
    system("cls");
    int opcionModo;
    cout<<"===Elija el modo de juego==="<<endl;
    cout<<"1. Un solo jugador"<<endl;
    cout<<"2. Dos jugadores"<<endl;
    //cout<<"3. MODO SIMULACION"<<endl;
    cin>>opcionModo;

    switch(opcionModo){
        case 1:
            nombreJugador(opcionModo);
            //Funcion de ronda
        break;

        case 2:
            nombreJugador(opcionModo);
        break;


        default:
            cout<<"Ingrese una opcion valida"<<endl;
        break;
    }
}

int main(){
    srand(time(0)); // Establece la semilla para numeros random
    rlutil::setColor(rlutil::WHITE);
    int opcion;

    do{
        system("cls");
        cout<<"===JUEGO DE LA ESCALERA==="<<endl;
        cout<<"1. Jugar"<<endl;
        cout<<"2. Puntuacion Maxima"<<endl;
        cout<<"0. Salir del juego"<<endl;
        cin>>opcion;

    switch(opcion){
        case 1:
            ModoJuego();
        break;

        case 0:
            system("cls");
            cout<<"Gracias por jugar!"<<endl;
            system("pause");
            return 0;
        break;
    }
    }while(opcion!=0);
}
