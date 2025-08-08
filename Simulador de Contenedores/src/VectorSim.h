//VectorSim.h
#pragma once
#include <vector>
#include "Simulador.h"
namespace SIM {
	/*
	* Simulador de vector que se encarga de simular las
	* operaciones y funciones de un vector con metodos
	* para que el usuario pueda simular un vector desde la consola
	*/
	class VectorSim : public Simulador {
	private:
		std::vector<int> vector;
	
	
	public:
		VectorSim() {};
		virtual ~VectorSim() {};
		
		
		//---------------------------------
		//|Metodos heredados de Simulador:|
		//---------------------------------
		void mostrar_menu() const noexcept override;
		bool ejecutar_opcion(int opcion) override;
		inline constexpr int get_maximo_numero_de_opciones() const noexcept override { return 5; };


	private:
		void vector_agregar_numero();
		void vector_eliminar_ultimo_numero();
		void vector_mostrar_todos_los_elementos() const noexcept;
		void vector_acceder_por_indice() const noexcept;
		bool vector_comprobar_si_esta_vacio() const noexcept;
	};
}