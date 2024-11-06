#include<iostream>
#include<ctime>
#include "rlutil.h"
#include "juego.h"
#include "menu.h"

using namespace std;

//Funcion de tirada de dado
int tiradaDado(){
    return rand() % 6 + 1;
}

//Funcion imprimir cuadrado
void dibujarCuadrado(int posx,int posy){
    for(int x=posx;x<=posx+6;x++){
        rlutil::setColor(rlutil::WHITE);
        for(int y=posy;y<=posy+2;y++){
            rlutil::locate(x,y);
            rlutil::setColor(rlutil::WHITE);
            cout<<(char) 219;
        }
    }
}

//Funcion sombra de dado
void dibujarSombra(int posy, int posx){
    for(int y=posy; y<=posy+2; y++){
        rlutil::locate(posx+7,y);
        rlutil::setColor(rlutil::GREY);
        cout<<(char) 219;
    }
}

//Funcion Imprimir numero de dado
void dibujarDado(int numero, int posx, int posy){
    dibujarCuadrado(posx,posy);

    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

    switch(numero){
        case 1:
            rlutil::locate(posx+3,posy+1);
            cout<<(char) 254;
        break;
        case 2:
            rlutil::locate(posx+1,posy);
            cout<<(char) 220;
            rlutil::locate(posx+5,posy+2);
            cout<<(char) 223;
        break;
        case 3:
            rlutil::locate(posx+3,posy+1);
            cout<<(char) 254;
            rlutil::locate(posx+1,posy);
            cout<<(char) 220;
            rlutil::locate(posx+5,posy+2);
            cout<<(char) 223;
        break;
        case 4:
            rlutil::locate(posx+1,posy);
            cout<<(char) 220;
            rlutil::locate(posx+5,posy);
            cout<<(char) 220;
            rlutil::locate(posx+5,posy+2);
            cout<<(char) 223;
            rlutil::locate(posx+1,posy+2);
            cout<<(char) 223;
        break;
        case 5:
            rlutil::locate(posx+1,posy);
            cout<<(char) 220;
            rlutil::locate(posx+5,posy);
            cout<<(char) 220;
            rlutil::locate(posx+3,posy+1);
            cout<<(char) 254;
            rlutil::locate(posx+5,posy+2);
            cout<<(char) 223;
            rlutil::locate(posx+1,posy+2);
            cout<<(char) 223;
        break;
        case 6:
            rlutil::locate(posx+1,posy);
            cout<<(char) 220;
            rlutil::locate(posx+5,posy);
            cout<<(char) 220;
            rlutil::locate(posx+3,posy);
            cout<<(char) 220;
            rlutil::locate(posx+5,posy+2);
            cout<<(char) 223;
            rlutil::locate(posx+1,posy+2);
            cout<<(char) 223;
            rlutil::locate(posx+3,posy+2);
            cout<<(char) 223;
        break;
    }
    dibujarSombra(posy, posx);
}

//Funcion para mostrar el dado
void mostrarDado(int vDado[], int TAM){
    int i;
    for(i=1;i<=TAM;i++){
        dibujarDado(vDado[i-1],rand()%10+1,i*4);
    }
}
