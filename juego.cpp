#include<iostream>
#include "rlutil.h"
#include "juego.h"
#include "menu.h"
#include "dados.h"

using namespace std;

//Funcion jugar

void Jugar(string& nombrePuntajeMaximo, int opcionModo, bool modoSimulado, int& puntajeMaximo){
    int RondaCont=1;
    int LanzamientoCont=0;
    int LanzamientoContJugador1=0;
    int LanzamientoContJugador2=0;
    int PuntajeMaximoRonda=0;
    int PuntajeTotalJugador1=0;
    int PuntajeTotalJugador2=0;
    int valorTirada=0;
    const int TAM=6;
    int vDado[TAM]={};
    bool juegoTerminado = false;
    bool TurnoJugador = true;
    bool llegoacien = false;
    string nombreJugador1;
    string nombreJugador2;

    switch(opcionModo){
        case 1:
            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLACK);
            cin.ignore();
            rlutil::locate(50,11);cout<<"===Ingrese el nombre del jugador 1==="<<endl;
            rlutil::resetColor();
            rlutil::locate(54,12);getline(cin, nombreJugador1);
        break;

        case 2:
            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLACK);
            cin.ignore();
            rlutil::locate(50,11);cout<<"===Ingrese el nombre del jugador 1==="<<endl;
            rlutil::resetColor();
            rlutil::locate(54,12);getline(cin, nombreJugador1);

            system("cls");
            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLACK);
            rlutil::locate(50,11);cout<<"===Ingrese el nombre del jugador 2==="<<endl;
            rlutil::resetColor();
            rlutil::locate(54,12);getline(cin, nombreJugador2);
        break;

        case 3:
            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLACK);
            cin.ignore();
            rlutil::locate(50,11);cout<<"===Ingrese el nombre del jugador 1==="<<endl;
            rlutil::resetColor();
            rlutil::locate(54,12);getline(cin, nombreJugador1);
        break;
    }

    do{
        if(opcionModo==1 && opcionModo==3){
            system("cls");
            rlutil::resetColor();

            if(LanzamientoCont == 3){
                system("cls");
                LanzamientoCont=0;
                PuntajeMaximoRonda=0;
                ImprimirTurnos(RondaCont,nombreJugador1,PuntajeTotalJugador1);
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

            valorTirada = calcPuntaje(vDado, TAM); // asigna el return de la funcion de puntaje a la variable valorTirada
            if(valorTirada==0){  //Si (puntaje) valorTirada == 0 (sexteto), entonces resetea el puntaje total.
                PuntajeTotalJugador1=0;
            }

            if(valorTirada>PuntajeMaximoRonda){
                PuntajeMaximoRonda = valorTirada;
            }

            //Imprime por pantalla la interfaz de la ronda
            rlutil::hidecursor();

            rlutil::locate(50,11);cout<<"TURNO DE "<<nombreJugador1;
            cout<<" | RONDA NUMERO "<<RondaCont;
            cout<<" | PUNTAJE TOTAL: "<<PuntajeTotalJugador1<<endl;
            rlutil::locate(51,12);cout<<"------------------------------------------------"<<endl;
            rlutil::locate(50,13);cout<<"MAXIMO PUNTAJE DE LA RONDA: " << PuntajeMaximoRonda <<endl;
            rlutil::locate(50,14);cout<<"LANZAMIENTO NUMERO: "<<LanzamientoContJugador1+1<<endl;
            rlutil::locate(51,15);cout<<"------------------------------------------------"<<endl;
            rlutil::locate(50,16);cout<<" "<<endl;

            //Mesa de timba
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

            mostrarDado(vDado,TAM);
            rlutil::resetColor();

            juegoTerminado = NombreJugada(valorTirada, TurnoJugador);

            if(PuntajeTotalJugador1 >= 100){
                rlutil::locate(62,16);cout<<"LLEGASTE A LOS 100 PUNTOS"<<endl;
                juegoTerminado=true;
            }

            LanzamientoCont++;

            if(PuntajeMaximoRonda>=valorTirada && LanzamientoCont==3){ // Tiene que acumular el lanzamiento mas alto de las 3 tiradas
                PuntajeTotalJugador1 += PuntajeMaximoRonda;
            }

            cout<<endl;
            rlutil::locate(51,17);cout<<"------------------------------------------------"<<endl;
            rlutil::locate(50,18);system("pause");
        }

        else{
            // Entra el modo 2 jugadores
            system("cls");
            rlutil::resetColor();

            if(LanzamientoCont == 3){
                system("cls");
                LanzamientoCont=0;
                PuntajeMaximoRonda=0;

                if(TurnoJugador == true){
                    system("cls");
                    ImprimirTurnos2Jugadores(RondaCont,nombreJugador1, nombreJugador2,PuntajeTotalJugador1, PuntajeTotalJugador2, TurnoJugador);
                    TurnoJugador=false;
                    rlutil::anykey();
                    system("cls");
                }
                else{
                    system("cls");
                    ImprimirTurnos2Jugadores(RondaCont,nombreJugador1, nombreJugador2,PuntajeTotalJugador1, PuntajeTotalJugador2, TurnoJugador);
                    TurnoJugador=true;
                    RondaCont++;
                    rlutil::anykey();
                    system("cls");
                }
            }

            for(int i=0;i<TAM;i++){
                vDado[i]=tiradaDado(); // Vector de 6(TAM) componentes que contienen numeros random del 1 al 6
            }

            valorTirada = calcPuntaje(vDado, TAM);
            if(valorTirada==0){
                if(TurnoJugador==true){
                    PuntajeTotalJugador1=0;
                }
                else{
                    PuntajeTotalJugador2=0;
                }
            }

            if(valorTirada>PuntajeMaximoRonda){
                PuntajeMaximoRonda = valorTirada;
            }

            //Imprime por pantalla la interfaz de la ronda
            rlutil::hidecursor();

            if(TurnoJugador == true){
                rlutil::locate(50,11);cout<<"TURNO DE "<<nombreJugador1;
                cout<<" | RONDA NUMERO "<<RondaCont;
                cout<<" | PUNTAJE TOTAL: "<<PuntajeTotalJugador1<<endl;
            }
            else{
                rlutil::locate(50,11);cout<<"TURNO DE "<<nombreJugador2;
                cout<<" | RONDA NUMERO "<<RondaCont;
                cout<<" | PUNTAJE TOTAL: "<<PuntajeTotalJugador2<<endl;
            }

            rlutil::locate(51,12);cout<<"------------------------------------------------"<<endl;
            rlutil::locate(50,13);cout<<"MAXIMO PUNTAJE DE LA RONDA: " << PuntajeMaximoRonda <<endl;
            rlutil::locate(50,14);cout<<"LANZAMIENTO NUMERO: "<<LanzamientoCont+1<<endl;
            rlutil::locate(51,15);cout<<"------------------------------------------------"<<endl;
            rlutil::locate(50,16);cout<<" "<<endl;

            //Mesa de timba
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

            mostrarDado(vDado,TAM);
            rlutil::resetColor();

            juegoTerminado = NombreJugada(valorTirada, TurnoJugador);

            LanzamientoCont++;

            if(PuntajeMaximoRonda>=valorTirada && LanzamientoCont==3){
                if(TurnoJugador==true){
                    PuntajeTotalJugador1 += PuntajeMaximoRonda;
                }
                else{
                    PuntajeTotalJugador2 += PuntajeMaximoRonda;
                }
            }

            /*if(PuntajeTotalJugador1>=100 && PuntajeTotalJugador2 < 100){
                rlutil::locate(62,16);cout<<"LLEGASTE A LOS 100 PUNTOS"<<endl;
                juegoTerminado=false;
            }
            else if(PuntajeTotalJugador2 >= 100 && PuntajeTotalJugador1 < 100){
                rlutil::locate(62,16);cout<<"LLEGASTE A LOS 100 PUNTOS"<<endl;
                juegoTerminado=true;
            }
            */

            if(PuntajeTotalJugador1 >= 100 && PuntajeTotalJugador2 >= 100){ //TODO
              llegoacien = true;
            }
            if(llegoacien == true){
              juegoTerminado = true;
            }

            cout<<endl;
            rlutil::locate(51,17);cout<<"------------------------------------------------"<<endl;
            rlutil::locate(50,18);system("pause");
        }
    } while(juegoTerminado==false);

    system("cls");
    if(PuntajeTotalJugador1 > PuntajeTotalJugador2 || valorTirada == -1){
        rlutil::locate(50,13);cout<<"------------------------------------------------"<<endl;
        rlutil::locate(62,14);cout<<nombreJugador1<<" GANO EN "<<RondaCont<<" RONDAS"<<endl;
        rlutil::locate(50,15);cout<<"------------------------------------------------"<<endl;
    }
    else if (PuntajeTotalJugador2 > PuntajeTotalJugador1 || valorTirada == -1){
        rlutil::locate(50,13);cout<<"------------------------------------------------"<<endl;
        rlutil::locate(62,14);cout<<nombreJugador2<<" GANO EN "<<RondaCont<<" RONDAS"<<endl;
        rlutil::locate(50,15);cout<<"------------------------------------------------"<<endl;
    }
    rlutil::locate(51,16);system("pause");
    system("cls");

    if(PuntajeTotalJugador1 > puntajeMaximo){
        puntajeMaximo = PuntajeTotalJugador1;
        nombrePuntajeMaximo = nombreJugador1;
        ImprimirPuntuacionMaxima(puntajeMaximo,nombrePuntajeMaximo);
    }

    if(PuntajeTotalJugador2 > puntajeMaximo){
        puntajeMaximo = PuntajeTotalJugador2;
        nombrePuntajeMaximo = nombreJugador2;
        ImprimirPuntuacionMaxima(puntajeMaximo,nombrePuntajeMaximo);
    }

    system("cls");
}

//Imprime el puntaje en la interfaz
bool NombreJugada(int puntaje, bool TurnoJugador){
    bool juegoTerminado=false;
    if(puntaje == -1){//Si el return(puntaje) es -1 seria escalera.
        rlutil::locate(62,16);cout<<"ESCALERA, GANASTE!"<<endl;
        rlutil::anykey();
        juegoTerminado = true;
    }
    else if (puntaje == 0){//Si el return(puntaje) es 0, es un sexteto de 6.
        rlutil::locate(62,16);cout<<"Sexteto de 6. Puntaje a 0"<<endl;
    }

    if(puntaje/10<=6 && puntaje/10>0){ //return(de puntaje) para saber el numero de dado.
        rlutil::locate(62,16);cout<<"Sexteto de "<< puntaje/10<<": "<< puntaje << " puntos"<<endl;
    }

    if(puntaje != -1 && puntaje != 0){
        cout<<endl;
        rlutil::locate(62,16);cout<<"Suma de dados: "<< puntaje << " puntos" <<endl;
    }
    return juegoTerminado;
}

//Funcion Turno
void ImprimirTurnos(int Ronda, string nombreJugador1, int PuntajeTotalJugador1){
    rlutil::hidecursor();

    for(int x=53;x<=83;x++){
        rlutil::locate(x,12);
        cout<<(char)205;
    }

    rlutil::locate(53,13);cout<<"RONDA NUMERO "<<Ronda;
    rlutil::locate(53,14);cout<<"PROXIMO TURNO: "<<nombreJugador1;
    rlutil::locate(53,15);cout<<"PUNTAJE DE "<<nombreJugador1<<" : "<< PuntajeTotalJugador1;

    for(int x2=53;x2<=83;x2++){
        rlutil::locate(x2,16);
        cout<<(char)205;
    }
}

void ImprimirTurnos2Jugadores(int Ronda, string nombreJugador1, string nombreJugador2, int PuntajeTotalJugador1, int PuntajeTotalJugador2, bool TurnoJugador){
    rlutil::hidecursor();

    for(int x=53;x<=83;x++){
        rlutil::locate(x,12);
        cout<<(char)205;
    }

    rlutil::locate(53,13);cout<<"RONDA NUMERO "<<Ronda;
    if(TurnoJugador==true){
        rlutil::locate(53,14);cout<<"PROXIMO TURNO: "<<nombreJugador2;
    }
    else{
        rlutil::locate(53,14);cout<<"PROXIMO TURNO: "<<nombreJugador1;
    }
    rlutil::locate(53,15);cout<<"PUNTAJE DE "<<nombreJugador1<<" : "<< PuntajeTotalJugador1;
    rlutil::locate(53,16);cout<<"PUNTAJE DE "<<nombreJugador2<<" : "<< PuntajeTotalJugador2;

    for(int x2=53;x2<=83;x2++){
        rlutil::locate(x2,17);
        cout<<(char)205;
    }
}

void ImprimirPuntuacionMaxima(int& puntajeMaximo, string& nombrePuntajeMaximo){
    rlutil::hidecursor();
    system("cls");

    for(int x=47;x<=83;x++){
        rlutil::locate(x,11);
        cout<<(char)205;
    }
     rlutil::locate(47,13);cout<<"Jugador con el mayor puntaje: "<<nombrePuntajeMaximo<<endl;
     rlutil::locate(47,14);cout<<"Puntaje maximo: "<<puntajeMaximo<<endl;

    for(int x2=47;x2<=83;x2++){
        rlutil::locate(x2,16);
        cout<<(char)205;
    }
    //
}

//Funcion calcular puntaje
int calcPuntaje(int vDado[],int TAM){
    int conteo[7]={0};
    int sumaTotal = 0; // acumulador
    int puntaje=0; // Return de la funcion
    int sexteto=0;

    //Recorre el vector y suma el total de sus valores [i]
    for(int i=0;i<TAM; i++){
        conteo[vDado[i]]++;
        sumaTotal += vDado[i];
    }



    //Comprueba si es sexteto(6 iguales)
    for(int i=0; i<=TAM; i++){
        if(conteo[i] == 6){
            if(i == 6){
                return puntaje=0;//si el sexteto son todos 6, devuelve 0
            }
            else{
                return puntaje=i*10;//El puntaje del sexteto dentro de la funcion imprimirPuntaje
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
