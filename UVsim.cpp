#include <UVsim.h>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

UVSim::UVSim()
{
	//Constructor crap
}

UVSim::~UVSim()
{
	//Deconstructor crap
}

bool UVSim::read(int index)
{
	//std::string input;
	//std::cin >> input;
	//return mainMemory[index].writeWord(stoi(input));

	while (true) {

		int inputNum = 0;
		bool inputFailed = !(std::cin >> inputNum);

		// lets you see the file input as if it were input normally while debugging

		if (inputFailed)
		{
			cout << "*** Please input a valid number between -9999 and +9999 ***\n";
			cout << "*** Enter -99999 to exit                                ***\n";
			cin.clear();
		}
		//
		// bounds checking on input
		else if (inputNum > MAX_WORD_VALUE || inputNum < MIN_WORD_VALUE)
		{
			cout << "*** Please input a valid number between -9999 and +9999 ***\n";
			cout << "*** Enter -99999 to exit                                ***\n";
		}
		//
		// Insertion of data. Crash if fail
		else if (this->insertInstruction(index, inputNum) == true)
		{

			return true;
		}
		else {

			cout << "Error: Integer did not read correctly\n";

		}

	}
}


bool UVSim::write(int index)
{
	cout << "Outputted number is :" << mainMemory[index].readWord() << '\n';
	return false;
}

void UVSim::load(int value)
{
	accumulator.writeWord(mainMemory[value].readWord());
}

void UVSim::store(int value)
{
	int valueToWrite = accumulator.readWord();
	mainMemory[value].writeWord(valueToWrite);
}

bool UVSim::branch(int jump)
{
    pc.writeWord(jump);
	return true;
}

bool UVSim::branchNeg(int jump)
{
    if (accumulator.readWord() < 0)
        {
            pc.writeWord(jump);
			return true;
        }
	else
	{
		return false;
	}
}

bool UVSim::branchZero(int jump)
{
	if(accumulator.readWord()==0)
	{
		pc.writeWord(jump);
		return true;
	}
	else {
		return false;
	}
}

void UVSim::dumpStateInfo()
{
    cout << "REGISTERS:"																<< endl; 
    cout << "Accumulator:            "		<< accumulator.readWord()					<< endl;
    cout << "InstructionCounter:        "	<< pc.readWord()							<< endl;
    cout << "InstructionRegister:    "		<< mainMemory[pc.readWord()].readWord()		<< endl;
    cout << "OperationCode:             "	<< mainMemory[pc.readWord()].getOpCode()	<< endl;
    cout << "Operand:                   "	<< mainMemory[pc.readWord()].getOperand()	<< endl << endl;
    dumpMemory();
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

		word instruction = this->mainMemory[pc.readWord()];

		switch (instruction.getOpCode()) {

		// IO
		case READ:
		{
			this->read(instruction.getOperand());
			pc.increment();
			break;
		}

		case WRITE: 
		{
			this->write(instruction.getOperand());
			pc.increment();
			break;
		}

		// Load/Store
		case LOAD: 
		{
			this->load(instruction.getOperand());
			pc.increment();
			break;
		}

		case STORE:
		{
			this->store(instruction.getOperand());
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
			this->branch(instruction.getOperand());
			break;
		}

		case BRANCHNEG: 
		{
			if (this->branchNeg(instruction.getOperand()) == false)
			{
				// increment pc only if the branch condition is not met
				pc.increment();
			}
			break;
		}

		case BRANCHZERO: 
		{
			if (this->branchZero(instruction.getOperand()) == false)
			{
				// increment pc only if the branch condition is not met
				pc.increment();
			}
			break;
		}

		case HALT: 
		{
			this->dumpStateInfo();
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
	static const int numColumns = 10;
	static const int numRows = 10;
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
