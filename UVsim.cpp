#include <UVsim.h>
#include <iostream>


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
		case READ:
		{
			// TODO call read function
			// read(pc.getOperand())
			break;
		}

		case WRITE: 
		{
			// TODO call write function
			// write(pc.getOperand())
			break;
		}

		// Load/Store
		case LOAD: 
		{
			// TODO call load function
			// load(pc.getOperand())
			break;
		}

		case STORE:
		{
			// TODO call store function
			// store(pc.getOperand())
			break;
		}


		// Arithmetic
		case ADD: 
		{
			// TODO call add function
			// add(pc.getOperand())
			break;
		}

		case SUBTRACT: 
		{
			// TODO call subtract function
			// subtract(pc.getOperand())
			break;
		}

		case DIVIDE: 
		{
			// TODO call divide function
			// divide(pc.getOperand())
			break;
		}

		case MULTIPLY: 
		{
			// TODO call multiply function
			// multiply(pc.getOperand())
			break;
		}


		// Control Operations
		case BRANCH: 
		{
			// TODO call branch function
			// branch(pc.getOperand())
			break;
		}

		case BRANCHNEG: 
		{
			// TODO call branchNeg function
			// branchNeg(pc.getOperand())
			break;
		}

		case BRANCHZERO: 
		{
			// TODO call branchZero function
			// branchZero(pc.getOperand())
			break;
		}

		case HALT: 
		{
			stillRunning = false;
			break;
		}

		default:
		{
			std::cerr << "Error: Improper or unimplemented opcode [" << pc.getOpCode() << "] found\n";
			return -1;
		}
		}
	}


	return 0;
}
