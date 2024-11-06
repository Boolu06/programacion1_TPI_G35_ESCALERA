#include<iostream>
#include<ctime>
#include "rlutil.h"
#include "juego.h"
#include "menu.h"
#include "dados.h"

using namespace std;

//Imprime el puntaje
void ImprimirPuntaje(int puntaje){
    if(puntaje == -1){//Si el return(puntaje) es -1 seria escalera.
    cout<<"Escalera"<<endl;
    }
    else if (puntaje == 0){//Si el return(puntaje) es 0, es un sexteto de 6.
    cout<<"sexteto de 6. Puntaje a 0"<<endl;
    }
    else if (puntaje % 10 == 0 && puntaje != 0 ){//si el puntaje es multiplo de 10 y es distinto de 0
        cout<<"sexteto de"<< puntaje/10<<":"<< puntaje << "puntos."<<endl;// puntaje/10 para calcular que numero salio para el sexteto
    }
    else{
        cout<<"suma de dados: "<< puntaje << "puntos" <<endl;//Suma de dados
    }
}

//Funcion Turno
void ImprimirTurnos(int Ronda, string nombreJugador1, int sumaTotal){
    rlutil::hidecursor();

    for(int x=1;x<=80;x++){
        rlutil::locate(x,1);
        cout<<(char)205;
    }

    cout<<"RONDA NUMERO "<<Ronda;
    cout<<"PROXIMO TURNO: "<<nombreJugador1;
    cout<<"PUNTAJE "<<nombreJugador1<<" : "<< sumaTotal;

    for(int x2=1;x2<=80;x2++){
        rlutil::locate(x2,10);
        cout<<(char)205;
    }
}

//Funcion jugar

void Jugar(string& nombreJugador1, bool modoSimulado){
    int RondaCont=1;
    int LanzamientoCont=1;
    const int TAM=6;
    int vDado[TAM]={};
    int PuntajeTotal=0;
    bool juegoTerminado = false;

    do{
        system("cls");
        rlutil::resetColor();

        if(modoSimulado){
            dadoManual(vDado, TAM);
        }else{
            for(int i=0;i<TAM;i++){
            vDado[i]=tiradaDado(); // Vector de 6(TAM) componentes que contienen numeros random del 1 al 6
            }
        }

        int sumaTotal = calcPuntaje(vDado, TAM);
        PuntajeTotal += sumaTotal;

        //Imprime por pantalla la interfaz de la ronda
        rlutil::hidecursor();

        cout<<"TURNO DE "<<nombreJugador1;
        cout<<"| RONDA NUMERO "<<RondaCont;
        cout<<"| PUNTAJE TOTAL: "<<PuntajeTotal<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<"MAXIMO PUNTAJE DE LA RONDA: " << sumaTotal <<endl;
        cout<<"LANZAMIENTO NUMERO: "<<LanzamientoCont<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<" "<<endl;

        mostrarDado(vDado,TAM); //Muestra los dados
        ImprimirPuntaje(sumaTotal);

        if(sumaTotal == -1){
            cout<<"escalera, termina"<<endl;
            juegoTerminado = true;
            break;
        }

            juegoTerminado = true;
        if(PuntajeTotal >= 100){
            break;
        }

        RondaCont++;
        LanzamientoCont++;

        cout<<endl;
        rlutil::anykey();
        rlutil::resetColor();
    }
    while(RondaCont <= 3 && !juegoTerminado);
    system("cls");
}

//Funcion calcular puntaje
int calcPuntaje(int vDado[],int TAM){ //cuenta cada numero y calcula puntaje
    int conteo[7] = {0};//conteo 1 a 6
    int sumaTotal = 0; // acumulador
    int puntaje=0; // Return de la funcion

    //Recorre el vector y suma el total de sus valores [i]
    for(int i=0;i<TAM; i++){
        conteo[vDado[i]]++;
        sumaTotal += vDado[i];
        }
    //comprobar sexteto(6 iguales)
    for(int i=1; i <= 6; i++){
        if(conteo[i] == 6){
            if(i == 6){
                return puntaje=0;//si el sexteto son todos 6, devuelve 0
            }else{
            return puntaje=i*10;//sino, multiplica x10 el puntaje del sexteto
            }
        }
    }
    //calcular escalera
    int numerosDif = 0;//contador para numeros diferentes
    for(int i = 1; i <= 6; i ++){//bucle de 6
        if(conteo[i] > 0){
            numerosDif++;//contar cuantos num son diferentes
        }
    }
    if(numerosDif == 6){//si 6 son diferentes, es escalera
        return puntaje =-1;//devulve escalera
    }
    return sumaTotal; //Si no se cumple ninguna de estas, devolver valor final
}

//funcion ingreso dado manual
void dadoManual (int vDado[], int TAM){
    cout<<"Ingrese los valores de los dados (1 - 6): "<< endl;
    for(int i=0; i < TAM; i++){
        cout<<"Dado: "<< i + 1 <<" : "<< endl;
        cin>> vDado[i];
    }
}
