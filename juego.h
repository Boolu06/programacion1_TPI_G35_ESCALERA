#pragma once

int calcPuntaje(int vDado[],int TAM);
void ImprimirTurnos(int Ronda, std::string nombreJugador1, int PuntajeTotal);
void Jugar(std::string& nombrePuntajeMaximo, bool modoSimulado,int& puntajeMaximo);
bool ImprimirPuntaje(int puntaje, int PuntajeTotal, int vDados[]);
void ImprimirPuntuacionMaxima(int& puntajeMaximo,std::string& nombrePuntajeMaximo);
