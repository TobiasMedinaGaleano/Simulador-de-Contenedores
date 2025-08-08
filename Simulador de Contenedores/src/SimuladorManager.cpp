//SimuladorManager.cpp
#include "SimuladorManager.h"
#include <assert.h>
#include "Utils.h"
#include <iostream>

namespace SIM {

	SimuladorManager::SimuladorManager() {
		this->simulador = nullptr;
		this->simulador_numero_de_opciones = 0;
	}

	SimuladorManager::SimuladorManager(Simulador* simulador) {
		this->simulador = simulador;
		this->simulador_numero_de_opciones = this->simulador->get_maximo_numero_de_opciones();
	}

	void SimuladorManager::run() {
		assert(simulador_numero_de_opciones && "Error. No hay un simulador en ((this)) para continuar la operacion");

		int numeroDeOperacion = 0;
		bool runningSimulador = true;
		while (runningSimulador) {

			this->simulador->mostrar_menu();
			numeroDeOperacion = obtenerNumeroDeOperacion();

			runningSimulador = this->simulador->ejecutar_opcion(numeroDeOperacion);
		}
	}

	void SimuladorManager::setSimulador(Simulador* simulador) {
		this->simulador = simulador;
		this->simulador_numero_de_opciones = simulador->get_maximo_numero_de_opciones();
	}

	int SimuladorManager::obtenerNumeroDeOperacion() const {
		return ut::entradaDeNumero(1, this->simulador_numero_de_opciones, "Error en la operacion, vuelva a digitar.");
	}
}