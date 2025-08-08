//Simulador.h
#pragma once
/*
Cada simulador debe tener heredada esta clase en publico
* (METODOS)
* mostrar menu. 
* ejecutar opcion(int op).
	ejecuta la funcion segun el numero
* maximo numero de opciones() 
	devuelve el maximo numero de opciones del simulador
*/
class Simulador {
public:
	virtual void mostrar_menu() const noexcept = 0;
	virtual bool ejecutar_opcion(int opcion) = 0;
	virtual inline constexpr int get_maximo_numero_de_opciones() const noexcept = 0;
};