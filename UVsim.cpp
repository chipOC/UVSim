#include <UVsim.h>;
#include <iostream>
#include <cstdio>


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

		word instruction = this->mainMemory[pc.readWord()];

		switch (instruction.getOpCode()) {

		// IO
		case READ:
		{
			// TODO call read function

			// read(instruction.getOperand())
			pc.increment();
			break;
		}

		case WRITE: 
		{
			// TODO call write function
			// write(instruction.getOperand())
			pc.increment();
			break;
		}

		// Load/Store
		case LOAD: 
		{
			// TODO call load function
			// load(instruction.getOperand())
			pc.increment();
			break;
		}

		case STORE:
		{
			// TODO call store function
			// store(instruction.getOperand())
			pc.increment();
			break;
		}


		// Arithmetic
		case ADD: 
		{
			this->add(instruction.getOperand());
			pc.increment();
			break;
		}

		case SUBTRACT: 
		{
			this->subtract(instruction.getOperand());
			pc.increment();
			break;
		}

		case DIVIDE: 
		{
			this->divide(instruction.getOperand());
			pc.increment();
			break;
		}

		case MULTIPLY: 
		{
			this->multiply(instruction.getOperand());
			pc.increment();
			break;
		}


		// Control Operations
		case BRANCH: 
		{
			// TODO call branch function
			// branch(instruction.getOperand())
			break;
		}

		case BRANCHNEG: 
		{
			// TODO call branchNeg function
			// branchNeg(instruction.getOperand())
			break;
		}

		case BRANCHZERO: 
		{
			// TODO call branchZero function
			// branchZero(instruction.getOperand())
			break;
		}

		case HALT: 
		{
			stillRunning = false;
			break;
		}

		default:
		{
			std::cerr << "Error: Improper or unimplemented opcode [" << instruction.getOpCode() << "] found. PC has a value of [" << pc.readWord() << "]\n";
			return -1;
		}
		}
	}


	return 0;
}

bool UVSim::insertInstruction(int index, int data)
{
	if (index >= MAIN_MEMORY_SIZE || index < 0)
		return false;

	return mainMemory[index].writeWord(data);
}

void UVSim::dumpMemory()
{
	static constexpr int numColumns = 10;
	static constexpr int numRows = 10;
	printf("\nMEMORY:\n");

	// top row with column numbers
	printf("  ");
	for (int i = 0; i < numColumns; i++)
		printf("%6d%01d", 0, i);
	printf("\n");


	// printing rows
	for (int i = 0; i < MAIN_MEMORY_SIZE; i += numColumns)
	{
		printf("%02d", i);

		for (int j = 0; j < numColumns; j++)
			printf("  %+05d", this->mainMemory[i + j].readWord());

		printf("\n");
	}

}
