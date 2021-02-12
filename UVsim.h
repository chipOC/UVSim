#include "dataType.h"

class UVSim
{
    public:
        UVSim() = default;
        ~UVSim() = default;

        //METHODS

    protected:
        //Initialize the operations
        //Memory allocation of 100 all initialized to 0
        word mainMemory[100] = { };

        //program counter
        word pc = word(0);       //Holds the index for the next instruction to be executed from mainMemory

        //accumulator
        word accumulator = word(0);        //This will hold data that will be used in some way

        //Vocam Definitions with values
            //i/o
        const int READ = 10;        //Read a word from the keyboard into a specific location in memory.
        const int WRITE = 11;       //Write a word from a specific location in memory to screen.
            //Load/Store
        const int LOAD = 20;        //Load a word from a specific location in memory into the accumulator. 
        const int STORE = 21;       //Store a word from the accumulator into a specific location in memory. 
            //Arithmetic
        const int ADD = 30;         //Add a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator) 
        const int SUBTRACT = 31;    //Subtract a word from a specific location in memory from the word in the accumulator (leave the result in the accumulator)
        const int DIVIDE = 32;      //Divide the word in the accumulator by a word from a specific location in memory (leave the result in the accumulator).
        const int MULTIPLY = 33;    //multiply a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator).
            //Control Operations
        const int BRANCH = 40;      //Branch to a specific location in memory
        const int BRANCHNEG = 41;   //Branch to a specific location in memory if the accumulator is negative.
        const int BRANCHZERO = 42;  //Branch to a specific location in memory if the accumulator is zero.
        const int HALT = 43;        //Pause the program
};