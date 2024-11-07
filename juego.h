#pragma once

int calcPuntaje(int vDado[],int TAM);
void ImprimirTurnos(int Ronda, std::string &nombreJugador1, int puntaje);
void Jugar(std::string& nombreJugador, bool modoSimulado = false);
int ImprimirPuntaje(int puntaje, int PuntajeTotal, int vDados[]);
void dadoManual(int vDado[], int TAM);

