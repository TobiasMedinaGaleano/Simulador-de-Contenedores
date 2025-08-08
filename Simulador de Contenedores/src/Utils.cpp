//Utils.cpp
#include "Utils.h"
#define NOMINMAX
#include <Windows.h>
#include <iostream>

int ut::entradaDeNumero(const int& minimoValor, const int& maximoValor, const char* salidaDeError) {
	int num;
	bool seCompruebaSiEstaFueraDeRango = minimoValor != maximoValor;
	/////////////////////////
	bool cinfail;
	bool losNumerosEstanFueraDeRango;
	while (true) {
		
		std::cin >> num;
		
		cinfail = std::cin.fail();
		losNumerosEstanFueraDeRango = num < minimoValor || num > maximoValor;

		bool entradaIncorrecta = false;
		if (seCompruebaSiEstaFueraDeRango) entradaIncorrecta = cinfail || losNumerosEstanFueraDeRango;
		else entradaIncorrecta = cinfail;

		if (entradaIncorrecta) {
			if (cinfail) std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << salidaDeError << std::endl;
		}
		else break;
	}

	return num;
}

int ut::entradaDeNumero(const char* salidaDeError) {
	return entradaDeNumero(0, 0, salidaDeError);

}

void ut::limpiarPantalla() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) return;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD cCharsWritten, dwConSize;

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputCharacter(hConsole, ' ', dwConSize, { 0, 0 }, &cCharsWritten);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, { 0, 0 }, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, { 0, 0 });
}
