//DequeSim.h
#pragma once
#include "Simulador.h"
#include <deque>

namespace SIM {
	class DequeSim : public Simulador {

	private:
		std::deque<int> _deque;

	public:

		///////////////////////////////
		DequeSim() = default;
		virtual ~DequeSim() = default;
		///////////////////////////////



		///////////////////////////////
		DequeSim(const DequeSim&) = delete;
		DequeSim operator=(const DequeSim&) = delete;
		///////////////////////////////



		///////////////////////////////
		void mostrar_menu() const noexcept override;
		bool ejecutar_opcion(int opcion) override;
		inline constexpr int get_maximo_numero_de_opciones() const noexcept override { return 5; };
		///////////////////////////////

	private:

		////////////////////////////////
		void deque_agregar_numero();
		void deque_eliminar_numero();
		void deque_mostrar_numero() const noexcept;
		void deque_mostrar_todos_los_numeros() const noexcept;
		////////////////////////////////


		bool deque_comprobar_si_esta_vacio() const noexcept;
		bool deque_pedir_lado() const noexcept;
	};
}