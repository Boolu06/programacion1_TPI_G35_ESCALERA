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

//Funcion sumar
int calcPuntaje(const int vDado[]){ //cuenta cada numero y calcula puntaje
    int conteo[7] = {0};//conteo 1 a 6
    int sumaTotal = 0; // acumulador

//cuenta cantidad x dado y suma al total
for(int i=0; i < 6; i++){
    conteo[vDado[i]]++;
    sumaTotal += vDado[i]
    }
//comprobar sexteto(6 iguales)
for(int i=1; i <= 6; i++){
    if(conteo[i] == 6)
        if(i == 6){
            return 0;//si el sexteto son todos 6, devuelve 0
        }else{
        return i*10;//sino, multiplica x10 el puntaje del sexteto
        }
    }

//calcular escalera
bool esEscalera = true;
    for(int i=1; i <= 6; i++){//bucle de 6
        if (conteo[i] != 1){//comprueba si el conteo es = 1, si no es igual a 1, no habria exactamente un dado de ese numero o hay varios, seria falso.
            esEscalera=false;
            break;
        }
    }
    if(esEscalera){
        return -1;//devulve escalera
    }

    //si no se cumple ninguna de estas, devolver valor final
    return sumaTotal;
}
//puntaje
int puntaje = calcPuntaje(vDado);

if(puntaje = -1){// si el return es -1 seria escalera
    cout<<"Escalera"<<endl;
}else if (puntaje = 0){//si el return es 0, es un sexteto de 6.
    cout<<"sexteto de 6. Puntaje a 0"<<endl;
}else if (puntaje % 10 == 0 && !=0 ){//si el puntaje es multiplo de 10 y es distinto de 0
    cout<<"sexteto de"<< puntaje/10<<":"<< puntaje << "puntos."<<endl;// puntaje/10 para calcular que numero salio para el sexteto
}else{
    cout<<"suma de dados: "<< puntaje << "puntos" <<endl;//suma de puntos default
}

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

