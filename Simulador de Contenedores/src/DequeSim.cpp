#include "DequeSim.h"
#include "Utils.h"
#include <iostream>

#define ADELANTE true

//////////////////////////////////////////////////
void SIM::DequeSim::mostrar_menu() const noexcept {
	std::cout << "---Deque Sim---\n1.Agregar un numero adelante/atras\n2.Eliminar un numero adelante/atras\n3.Mostrar un numero adelante/atras\n4.Mostrar todos los numeros\n5.salir\n";
}
bool SIM::DequeSim::ejecutar_opcion(int opcion) {

	ut::limpiarPantalla();

	switch (opcion) {
	case 1:
		deque_agregar_numero();
		break;
	case 2:
		deque_eliminar_numero();
		break;
	case 3:
		deque_mostrar_numero();
		break;
	case 4:
		deque_mostrar_todos_los_numeros();
		break;
	case 5:
		return false;
	}
	std::cout << "\n";
	return true;
}
///////////////////////////////////////////////////

/// ///////////////////////////////
/// Funciones publicas de dequeSim
/// ///////////////////////////////
void SIM::DequeSim::deque_agregar_numero() {

	const bool lado_a_añadir = deque_pedir_lado();

	//Numero a añadir
	std::cout << "Digite el numero a anadir:\n";
	int n = ut::entradaDeNumero("Error, vuelve a digitar");

	if (lado_a_añadir == ADELANTE) this->_deque.push_front(n);
	else this->_deque.push_back(n);

	//finalizando...
	ut::limpiarPantalla();
	std::cout << "Numero anadido correctamente\n";
}

void SIM::DequeSim::deque_eliminar_numero() {

	if (deque_comprobar_si_esta_vacio()) return;


	bool lado_a_eliminar = deque_pedir_lado();
	if (lado_a_eliminar == ADELANTE) this->_deque.pop_front();
	else this->_deque.pop_back();


	//finalizando...
	ut::limpiarPantalla();
	std::cout << "Numero eliminado correctamente\n";
}

void SIM::DequeSim::deque_mostrar_numero() const noexcept {

	if (deque_comprobar_si_esta_vacio()) return;


	bool lado_a_mostrar = deque_pedir_lado();

	ut::limpiarPantalla();
	if (lado_a_mostrar == ADELANTE) {
		std::cout << "El numero de adelante es " << this->_deque.front();
	}
	else { std::cout << "El numero de atras es " << this->_deque.back(); }
}

void SIM::DequeSim::deque_mostrar_todos_los_numeros() const noexcept {

	if (deque_comprobar_si_esta_vacio()) return;


	std::cout << "| ";
	for (int n : this->_deque) {
		std::cout << n << " | ";
	}
	std::cout << "\nNumeros en pantalla.\n";
}
/// ///////////////////////////////				///////////
/// Funciones publicas de dequeSim.					END
/// ///////////////////////////////				///////////


bool SIM::DequeSim::deque_comprobar_si_esta_vacio() const noexcept {

	bool estaVacio = this->_deque.empty();

	if (estaVacio) {
		std::cout << "El deque esta vacio\n";
	}
	return estaVacio;
}

bool SIM::DequeSim::deque_pedir_lado() const noexcept {

	std::cout << "Digite el lado:\n1.Adelante\n2.Atras\n";
	short lado = (short) ut::entradaDeNumero(1, 2, "Solo puede digitar 1 o 2");

	return lado == 1;
}
