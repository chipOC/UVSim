#include <UVsim.h>


UVSim::UVSim()
{
	//Constructor crap
}

UVSim::~UVSim()
{
	//Deconstructor crap
}

int UVSim::execute() {

	bool stillRunning = true;

	while (stillRunning) {

		switch (pc.getOpCode()) {

		// IO
		case READ: {
			// TODO call read function
			// read(pc.getOperand())
		}

		case WRITE: {
			// TODO call write function
			// write(pc.getOperand())
		}

		// Load/Store
		case LOAD: {
			// TODO call load function
			// load(pc.getOperand())
		}

		case STORE: {
			// TODO call store function
			// store(pc.getOperand())
		}


		// Arithmetic
		case ADD: {
			// TODO call add function
			// add(pc.getOperand())
		}

		case SUBTRACT: {
			// TODO call subtract function
			// subtract(pc.getOperand())
		}

		case DIVIDE: {
			// TODO call divide function
			// divide(pc.getOperand())
		}

		case MULTIPLY: {
			// TODO call multiply function
			// multiply(pc.getOperand())
		}


		// Control Operations
		case BRANCH: {
			// TODO call branch function
			// branch(pc.getOperand())
		}

		case BRANCHNEG: {
			// TODO call branchNeg function
			// branchNeg(pc.getOperand())
		}

		case BRANCHZERO: {
			// TODO call branchZero function
			// branchZero(pc.getOperand())
		}

		case HALT: {
			stillRunning = false;
		}

		default:
			std::cerr << "Error: improper or unimplemented opcode found\n";
			return -1;

		}


	}


	return 0;
}
