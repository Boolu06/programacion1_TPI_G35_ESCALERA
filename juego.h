#pragma once

int calcPuntaje(int vDado[],int TAM);
void ImprimirTurnos(int Ronda, std::string nombreJugador1, int PuntajeTotal);
void Jugar(std::string& nombreJugador1, bool modoSimulado,int& puntajeMaximo);
bool ImprimirPuntaje(int puntaje, int PuntajeTotal, int vDados[]);
void dadoManual(int vDado[], int TAM);

