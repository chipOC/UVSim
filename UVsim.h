#ifndef UVSIM_UVSIM_H
#define UVSIM_UVSIM_H

#include "dataType.h"

using namespace std;

static const int MAIN_MEMORY_SIZE = 100;

class UVSim
{
    public:
        UVSim();
        ~UVSim();

        //METHODS

        //Main execute command that will start the main memory
        int execute();

        // inserts integer into memory index
        bool insertInstruction(int index, int data);

        // Reads a word from the keyboard into a specific memory location
        bool read(int index);

        // Writes a word from a specific memory location to the screen
        bool write(int index);

        //Load a word from a specific location in memory into the accumulator
        void load(int value);

        //Store a word from the accumulator into a specific location in memory
        void store(int value);

        //Add a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator)
        void add(int value);

        //Subtract a word from a specific location in memory from the word in the accumulator (leave the result in the accumulator)
        void subtract(int value);

        //Divide the word in the accumulator by a word from a specific location in memory (leave the result in the accumulator).
        void divide(int value);

        //multiply a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator).

        void multiply(int value);
    
        //Branch to a specific location in memory
        bool branch(int jump);

        //Branch to a specific location in memory if the accumulator is negative.
        bool branchNeg(int jump);

        //Branch to a specific location in memory if the accumulator is zero
        bool branchZero(int jump);

        //provides information on the registers and memory
        void dumpStateInfo();   

        // dumps all mainMemory as int for debugging. Is called by dumpStateInfo
        void dumpMemory();

    protected:
        //Initialize the operations
        //Memory allocation of 100 all initialized to 0
        word mainMemory[MAIN_MEMORY_SIZE] = { };

        //program counter
        word pc = word(0);       //Holds the index for the next instruction to be executed from mainMemory

        //accumulator
        word accumulator = word(0);        //This will hold data that will be used in some way

        //Vocam Definitions with values
            //i/o
        static const int READ = 10;        //Read a word from the keyboard into a specific location in memory.
        static const int WRITE = 11;       //Write a word from a specific location in memory to screen.
            //Load/Store
        static const int LOAD = 20;        //Load a word from a specific location in memory into the accumulator. 
        static const int STORE = 21;       //Store a word from the accumulator into a specific location in memory. 
            //Arithmetic
        static const int ADD = 30;         //Add a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator) 
        static const int SUBTRACT = 31;    //Subtract a word from a specific location in memory from the word in the accumulator (leave the result in the accumulator)
        static const int DIVIDE = 32;      //Divide the word in the accumulator by a word from a specific location in memory (leave the result in the accumulator).
        static const int MULTIPLY = 33;    //multiply a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator).
            //Control Operations
        static const int BRANCH = 40;      //Branch to a specific location in memory
        static const int BRANCHNEG = 41;   //Branch to a specific location in memory if the accumulator is negative.
        static const int BRANCHZERO = 42;  //Branch to a specific location in memory if the accumulator is zero.
        static const int HALT = 43;        //Pause the program

        friend class MainWindow;
};

#endif
