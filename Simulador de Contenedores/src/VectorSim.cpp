//VectorSim.cpp
#include "VectorSim.h"
#include <iostream>
#include "Utils.h"

void SIM::VectorSim::mostrar_menu() const noexcept {
	std::cout << "---Vector Sim---\n1.Agregar numero.\n2.Eliminar ultimo numero\n3.Mostrar todos los numeros\n4.Acceder por indice.\n5.Salir\n";
}

bool SIM::VectorSim::ejecutar_opcion(int opcion) {
	/*Limpia la pantalla aqui, para que borre todo lo anterior que se mostro y tener el
	  espacio libre.
	*/
	ut::limpiarPantalla();

	switch (opcion) {
	case 1:
		vector_agregar_numero();
		break;
	case 2:
		vector_eliminar_ultimo_numero();
		break;
	case 3:
		vector_mostrar_todos_los_numeros();
		break;
	case 4:
		vector_acceder_por_indice();
		break;
	case 5:
		return false;
	}
	std::cout << "\n";
	return true;
}
/// /////////////////////////////////
/// FUNCIONES PUBLICAS DE VECTOR SIM
/// /////////////////////////////////

void SIM::VectorSim::vector_agregar_numero() {

	std::cout << "Digite el numero a anadir: \n";
	this->vector.push_back(ut::entradaDeNumero("Error, vuelve a digitar"));

	ut::limpiarPantalla();
	std::cout << "numero añadido correctamente\n";
}

void SIM::VectorSim::vector_eliminar_ultimo_numero() {

	if (vector_comprobar_si_esta_vacio()) return;


	this->vector.pop_back();
	std::cout << "Numero eliminado correctamente\n";
}

void SIM::VectorSim::vector_mostrar_todos_los_numeros() const noexcept {

	if (vector_comprobar_si_esta_vacio()) return;


	std::cout << "| ";
	for (int n : this->vector) {
		std::cout << n << " | ";
	}
	std::cout << "\nNumeros en pantalla.\n";
}

void SIM::VectorSim::vector_acceder_por_indice() const noexcept {

	if (vector_comprobar_si_esta_vacio()) return;


	std::cout << "Escriba el numero de indice en el que accedera:\n";
	int x = ut::entradaDeNumero(0, (int) vector.size(), "Error, vuelve a digitar");

	ut::limpiarPantalla();
	std::cout << "El numero del indice " << x << " es: " << this->vector.at(x) << std::endl;
}

/// /////////////////////////////////			///////////
/// FUNCIONES PUBLICAS DE VECTOR SIM				END
/// /////////////////////////////////			///////////

bool SIM::VectorSim::vector_comprobar_si_esta_vacio() const noexcept {
	bool estaVacio = this->vector.empty();
	if (estaVacio) {
		std::cout << "El vector esta vacio\n";
	}
	return estaVacio;
}