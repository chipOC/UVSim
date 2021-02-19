#include "dataType.h"

static const int MAIN_MEMORY_SIZE = 100;

class UVSim
{
    public:
        UVSim();
        ~UVSim();

        //METHODS

        int execute();
        bool insertInstruction(int index, int data); // inserts integer into memory index
        void dumpMemory(); // dumps all mainMemory as int for debugging

        //Load a word from a specific location in memory into the accumulator
        void load(int value)
        {
            accumulator.writeWord(mainMemory[value].readWord());
        }

        //Store a word from the accumulator into a specific location in memory
        void store(int value)
        {
            int valueToWrite = accumulator.readWord();
            mainMemory[value].writeWord(valueToWrite);
        }

        //Add a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator)
        void add(int value);

        //Subtract a word from a specific location in memory from the word in the accumulator (leave the result in the accumulator)
        void subtract(int value);

        //Divide the word in the accumulator by a word from a specific location in memory (leave the result in the accumulator).
        void divide(int value);

        //multiply a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator).

        void multiply(int value);
    
        //Branch to a specific location in memory
        void branch(int jump)
        {
            pc.writeWord(jump);
        }
        //Branch to a specific location in memory if the accumulator is negative.
        void branchNeg(int jump)
        {
            if (accumulator.readWord() < 0)
            {
                pc.writeWord(jump);
            }
        }

  

        //Main execute command that will start the main memory
        int execute();

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
};
