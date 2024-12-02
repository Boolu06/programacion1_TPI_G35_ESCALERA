#pragma once

int calcPuntaje(int vDado[],int TAM, bool& juegoTerminado);
void ImprimirTurnos(int Ronda, std::string nombreJugador1, int PuntajeTotalJugador1);
void ImprimirTurnos2Jugadores(int Ronda, std::string nombreJugador1, std::string nombreJugador2, int PuntajeTotalJugador1, int PuntajeTotalJugador2, bool TurnoJugador);
void ImprimirPuntuacionMaxima(int& puntajeMaximo,std::string& nombrePuntajeMaximo, bool root);
void ImprimirPuntajeTotal(std::string nombreJugador1, std::string nombreJugador2, int PuntajeTotalJugador1, int PuntajeTotalJugador2, int opcionModo);
void NombreJugada(int puntaje, bool TurnoJugador);
void Jugar(std::string& nombrePuntajeMaximo, int opcionModo, bool modoSimulado,int& puntajeMaximo);
