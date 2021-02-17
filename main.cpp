#include "UVsim.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std;

void outputIntroduction() {

	cout << "*** Welcome to UVSim! ***\n";
	cout << "*** Please enter your program one instruction ***\n";
	cout << "*** ( or data word ) at a time into the input ***\n";
	cout << "*** text field. I will display the location   ***\n";
	cout << "*** number and a question mark (?). You then  ***\n";
	cout << "*** type the word for that location. Enter    ***\n";
	cout << "*** -99999 to stop entering your program.     ***\n";

}

int main() {

	// debugging. Comment out these lines when not debugging
	// -----------------------------------------------------
	ifstream debugFile;
	debugFile.open("debugInput.txt");
	cin.rdbuf(debugFile.rdbuf());
#define UVSIM_DEBUGGING
	// -----------------------------------------------------

	// program variables
	UVSim machine;
	string inputBuffer;
	int memoryInsertIndex = 0;
	int inputNum = 0;

	outputIntroduction();

	while (true) {

		// input
		printf("%02d ? ", memoryInsertIndex); // prints the prompt with memory location number and '?' before the input
		bool inputFailed = !(cin >> inputNum);

		// lets you see the file input as if it were input normally while debugging
#ifdef UVSIM_DEBUGGING
		cout << inputNum << '\n';
#endif


		if (inputFailed)
		{
			cout << "*** Please input a valid number between -9999 and +9999 ***\n";
			cout << "*** Enter -99999 to exit                                ***\n";
			cin.clear();
		}
		//
		// exit condition
		else if (inputNum == -99999)
		{
			break;
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
		else if (machine.insertInstruction(memoryInsertIndex, inputNum) == false)
		{
			cout << "Error: Inserting instruction into UVSim failed\n";
			return -1;
		}
		//
		// Increment insertion index. Start executing if all memory taken
		else
		{
			memoryInsertIndex++;

			if (memoryInsertIndex == MAIN_MEMORY_SIZE) {
				cout << "*** All memory locations used ***\n";
				break;
			}
		}
	}

	cout << "*** Program loading completed ***\n";
	cout << "*** Program execution begins  ***\n";

	machine.execute();

	machine.dumpMemory();

	return 0;
}
