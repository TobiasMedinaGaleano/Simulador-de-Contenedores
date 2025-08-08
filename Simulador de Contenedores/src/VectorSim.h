//VectorSim.h
#pragma once
#include "Simulador.h"
#include <vector>

namespace SIM {
	class VectorSim : public Simulador {

	private:
		std::vector<int> vector;

	public:
		//////////////////////////////////
		VectorSim() = default;
		virtual ~VectorSim() = default;
		//////////////////////////////////



		//////////////////////////////////
		VectorSim operator=(const VectorSim&) = delete;
		VectorSim(const VectorSim&) = delete;
		//////////////////////////////////

	

		//////////////////////////////////
		void mostrar_menu() const noexcept override;
		bool ejecutar_opcion(int opcion) override;
		inline constexpr int get_maximo_numero_de_opciones() const noexcept override { return 5; };
		//////////////////////////////////

	private:

		//////////////////////////////////
		void vector_agregar_numero();
		void vector_eliminar_ultimo_numero();
		void vector_mostrar_todos_los_numeros() const noexcept;
		void vector_acceder_por_indice() const noexcept;
		//////////////////////////////////

		bool vector_comprobar_si_esta_vacio() const noexcept;
	};
}