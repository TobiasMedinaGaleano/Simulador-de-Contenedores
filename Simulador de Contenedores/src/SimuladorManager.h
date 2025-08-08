//SimuladorManager.h
#pragma once
#include "Simulador.h"
namespace SIM {
	class SimuladorManager {
	private:
		Simulador* simulador;
		int simulador_numero_de_opciones;

	public:
		SimuladorManager();
		SimuladorManager(Simulador* simulador);
		SimuladorManager(const SimuladorManager&) = delete;
		SimuladorManager operator=(const SimuladorManager&) = delete;

		void setSimulador(Simulador* simulador);
		void run();

	private:
		int obtenerNumeroDeOperacion() const;
	};
}
