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


//Add a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator)
void UVSim::add(int value)
{
	//Write to accumlator the word read from mainMemory plus the word read from accumulator
	accumulator.writeWord(mainMemory[value].readWord() + accumulator.readWord());
}

//Subtract a word from a specific location in memory from the word in the accumulator (leave the result in the accumulator)
void UVSim::subtract(int value)
{
	//Write to accumlator the word read from mainMemory minus the word read from accumulator
	accumulator.writeWord(mainMemory[value].readWord() - accumulator.readWord());
}

//Divide the word in the accumulator by a word from a specific location in memory (leave the result in the accumulator).
void UVSim::divide(int value)
{
	//Write to accumlator the word read from mainMemory divided by the word read from accumulator
	accumulator.writeWord(mainMemory[value].readWord() / accumulator.readWord());
}

//multiply a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator).
void UVSim::multiply(int value)
{
	//Write to accumlator the word read from mainMemory multiplied by the word read from accumulator
	accumulator.writeWord(mainMemory[value].readWord() * accumulator.readWord());
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
