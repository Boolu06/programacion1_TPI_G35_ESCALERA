#include<iostream>
#include<ctime>
#include "rlutil.h"
#include "juego.h"
#include "menu.h"
#include "dados.h"

using namespace std;

//Imprime el puntaje en la interfaz
bool ImprimirPuntaje(int puntaje, int PuntajeTotal, int vDados[]){
    bool juegoTerminado=false;

    if(puntaje == -1){//Si el return(puntaje) es -1 seria escalera.
        rlutil::locate(62,16);cout<<"ESCALERA, GANASTE!"<<endl;
        rlutil::anykey();
        return juegoTerminado = true;
    }
    else if (puntaje == 0){//Si el return(puntaje) es 0, es un sexteto de 6.
        rlutil::locate(62,16);cout<<"Sexteto de 6. Puntaje a 0"<<endl;
    }

    if(puntaje/10<=6 && puntaje/10>0 && puntaje != 0){//si el puntaje es multiplo de 10 y es distinto de 0
        PuntajeTotal=puntaje;
        rlutil::locate(62,16);cout<<"Sexteto de "<< puntaje<<": "<< PuntajeTotal << " puntos"<<endl;// puntaje/10 para calcular que numero salio para el sexteto
    }

    if(puntaje != -1 && puntaje != 0){
        cout<<endl;
        rlutil::locate(62,16);cout<<"Suma de dados: "<< puntaje << " puntos" <<endl;//Suma de dados
    }

    if(PuntajeTotal >= 100){
        rlutil::locate(62,16);cout<<"LLEGASTE A LOS 100 PUNTOS"<<endl;
        return juegoTerminado = true;
    }
    return juegoTerminado;
}

//Funcion Turno
void ImprimirTurnos(int Ronda, string nombreJugador1, int PuntajeTotal){
    rlutil::hidecursor();

    for(int x=50;x<=76;x++){
        rlutil::locate(x,10);
        cout<<(char)205;
    }

     rlutil::locate(50,11);cout<<"RONDA NUMERO "<<Ronda;
     rlutil::locate(50,12);cout<<"PROXIMO TURNO: "<<nombreJugador1;
     rlutil::locate(50,13);cout<<"PUNTAJE "<<nombreJugador1<<" : "<< PuntajeTotal;

    for(int x2=50;x2<=76;x2++){
        rlutil::locate(x2,14);
        cout<<(char)205;
    }
}

//Funcion jugar

void Jugar(string& nombreJugador1, bool modoSimulado){
    int RondaCont=1; //Contabilizar la ronda cuando se hayan realizado 3 lanzamientos, entraria la FUNCION DE TURNOS
    int LanzamientoCont=0;
    const int TAM=6;
    int vDado[TAM]={};
    int PuntajeTotal=0;
    int PuntajeMaximoRonda=0;
    bool juegoTerminado = false;
    int puntajeMaximo=0;

    do{
        system("cls");
        rlutil::resetColor();

        if(LanzamientoCont == 3){
            system("cls");
            LanzamientoCont=0;
            ImprimirTurnos(RondaCont,nombreJugador1,PuntajeTotal);
            RondaCont++;
            rlutil::anykey();
            system("cls");
        }

        if(modoSimulado){
            dadoManual(vDado, TAM);
        }else{
            for(int i=0;i<TAM;i++){
            vDado[i]=tiradaDado(); // Vector de 6(TAM) componentes que contienen numeros random del 1 al 6
            }
        }

        int sumaTotal = calcPuntaje(vDado, TAM); // asigna el return de la funcion de puntaje a la variable sumaTotal
        if(sumaTotal==0){  //Si (puntaje) sumaTotal == 0 (sexteto), entonces resetea el puntaje total.
            PuntajeTotal=0;
        }
        PuntajeTotal += sumaTotal; // Puntaje Total

        if(sumaTotal>PuntajeMaximoRonda){
            PuntajeMaximoRonda = sumaTotal; // Maximo puntaje de la ronda
        }

        //Imprime por pantalla la interfaz de la ronda
        rlutil::hidecursor();

        rlutil::locate(50,11);cout<<"TURNO DE "<<nombreJugador1;
        cout<<" | RONDA NUMERO "<<RondaCont;
        cout<<" | PUNTAJE TOTAL: "<<PuntajeTotal<<endl;
        rlutil::locate(51,12);cout<<"------------------------------------------------"<<endl;
        rlutil::locate(50,13);cout<<"MAXIMO PUNTAJE DE LA RONDA: " << PuntajeMaximoRonda <<endl;
        rlutil::locate(50,14);cout<<"LANZAMIENTO NUMERO: "<<LanzamientoCont+1<<endl;
        rlutil::locate(51,15);cout<<"------------------------------------------------"<<endl;
        rlutil::locate(50,16);cout<<" "<<endl;



        for(int y=0;y<30;y++){
            rlutil::saveDefaultColor();
            rlutil::setColor(rlutil::BROWN);
            rlutil::locate(31,y);
            cout<<(char)186;
            for(int x=1;x<31;x++){
                rlutil::locate(x,y);
                rlutil::setColor(rlutil::LIGHTGREEN);
                rlutil::setBackgroundColor(rlutil::BLACK);
                cout<<(char)177;
            }
        }

        mostrarDado(vDado,TAM); //Muestra los dados
        rlutil::resetColor();

        juegoTerminado = ImprimirPuntaje(sumaTotal,PuntajeTotal, vDado);

        LanzamientoCont++;

        cout<<endl;
        rlutil::locate(51,17);cout<<"------------------------------------------------"<<endl;
        rlutil::locate(50,18);system("pause");
    }
    while(juegoTerminado==false);

    if(PuntajeTotal > puntajeMaximo){
        puntajeMaximo += PuntajeTotal;
        cout<<"Puntaje maximo: "<< puntajeMaximo <<endl;
    }

    system("pause");
    system("cls");
}

//Funcion calcular puntaje
int calcPuntaje(int vDado[],int TAM){ //cuenta cada numero y calcula puntaje
    int conteo[7] = {0};//conteo 1 a 6
    int sumaTotal = 0; // acumulador
    int puntaje=0; // Return de la funcion
    int sexteto=0;

    //Recorre el vector y suma el total de sus valores [i]
    for(int i=0;i<TAM; i++){
        conteo[vDado[i]]++;
        sumaTotal += vDado[i];
    }

    //Comprueba si es sexteto(6 iguales)
    for(int i=1; i <= 6; i++){
        if(conteo[i] == 6){
            if(i == 6){
                return puntaje=0;//si el sexteto son todos 6, devuelve 0
            }
            else{
                return puntaje=i*10;//sino, multiplica x10 el puntaje del sexteto dentro de la funcion imprimirPuntaje
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
    system("cls");
}
