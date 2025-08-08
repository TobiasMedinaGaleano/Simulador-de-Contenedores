//VectorSim.cpp
#include "VectorSim.h"
#include <iostream>
#include "Utils.h"

void SIM::VectorSim::mostrar_menu() const noexcept {
	std::cout << "---Vector Sim---\n1.Agregar numero.\n2.Eliminar ultimo numero\n3.Mostrar todos los elementos\n4.Acceder por indice.\n5.Salir\n";
}

/*
Ejecuta opciones/funciones.


RETORNA:
un boleano que da a entender si el simulador continua
si es es false, significa que la opcion digitada es la de salir
del simulador.
*/
bool SIM::VectorSim::ejecutar_opcion(int opcion) {
	/*Limpia la pantalla aqui, para que borre todo lo anterior que se mostro y tener el
	  espacio libre.
	*/
	ut::limpiarPantalla();
	
	switch (opcion) {
	case 1:
		vector_agregar_numero();
		std::cout << "\n";
		return true;
	case 2:
		vector_eliminar_ultimo_numero();
		std::cout << "\n";
		return true;
	case 3:
		vector_mostrar_todos_los_elementos();
		std::cout << "\n";
		return true;
	case 4:
		vector_acceder_por_indice();
		std::cout << "\n";
		return true;
	}

	return false;
}

//Evita que se opere con vectores vacios
bool SIM::VectorSim::vector_comprobar_si_esta_vacio() const noexcept {
	bool vacio = this->vector.empty();
	if (vacio) {
		std::cout << "El vector esta vacio\n";
	}
	return vacio;
}


void SIM::VectorSim::vector_agregar_numero() {
	std::cout << "Digite el elemento a anadir: \n";
	this->vector.push_back(ut::entradaDeNumero("Error, vuelve a digitar"));

	ut::limpiarPantalla();
	std::cout << "Elemento añadido correctamente\n";
}

void SIM::VectorSim::vector_eliminar_ultimo_numero() {
	//Esto para evitar excepciones de eliminar elementos inexistentes
	if (vector_comprobar_si_esta_vacio()) return;


	this->vector.pop_back();
	std::cout << "Elemento eliminado correctamente\n";
}

void SIM::VectorSim::vector_mostrar_todos_los_elementos() const noexcept {
	
	if (vector_comprobar_si_esta_vacio()) return;

	for (int n : this->vector) {
		std::cout << n << " | ";
	}
	std::cout << "\nElementos en pantalla.\n";
}

void SIM::VectorSim::vector_acceder_por_indice() const noexcept {

	if (vector_comprobar_si_esta_vacio()) return;

	std::cout << "Escriba el numero de indice en el que accedera:\n";
	int x = ut::entradaDeNumero(0, (int) vector.size(), "Error, vuelve a digitar");

	ut::limpiarPantalla();
	std::cout << "El elemento del indice " << x << " es: " << this->vector.at(x) << std::endl;
}