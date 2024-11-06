#pragma once

int tiradaDado();
int calcPuntaje(int vDado[],int TAM);
void ImprimirTurnos(int Ronda, std::string &nombreJugador1, int puntaje);
void Jugar(std::string& nombreJugador, bool modoSimulado = false);
void ImprimirPuntaje(int puntaje);
void mostrarVector(int vDado[], int TAM);
void dadoManual(int vDado[], int TAM);
