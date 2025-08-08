#include <iostream>

#include "SimuladorManager.h"
#include "Simulador.h"
#include "Utils.h"

#include "VectorSim.h"
#include "DequeSim.h"


int main() {
	SIM::SimuladorManager simulManager;
	SIM::Simulador* simuladores[2] = {
		new SIM::VectorSim(),
		new SIM::DequeSim()
	};

	bool running = true;
	while (running) {

		std::cout << "\t\t---SIMULADOR DE CONTENEDORES---\n1.VectorSim\n2.DequeSim\n3.Salir\n";
		short opcionDeSimulador = (short) ut::entradaDeNumero(1, 3, "Error, vuelve a digitar");

		if (opcionDeSimulador == 3) running = false;
		else {
			simulManager.setSimulador(simuladores[opcionDeSimulador - 1]);

			ut::limpiarPantalla();
			simulManager.run();
		}
	}
	return 0;
}