#include <iostream>
#include "VectorSim.h"
#include "SimuladorManager.h"

int main() {
	SIM::VectorSim vecSsim;

	SIM::SimuladorManager simulManager;
	simulManager.setSimulador(&vecSsim);
	simulManager.run();


	return 0;
}