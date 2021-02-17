constexpr int MAX_WORD_VALUE = 9999;
constexpr int MIN_WORD_VALUE = -9999;

struct word {
public:
	word() : data(0) {}
	word(int newData) : data(newData) {}
	~word() = default;
	
	bool writeWord(int data); // Changes the value of the word to data provided. Returns true if the written value was within bounds. Returns false if the written value was out of bounds, and sets the data to max (if over) or min (if under) value
	int readWord(); // Returns the integer value contained within word. Will be within the bounds of [MIN_WORD_VALUE, MAX_WORD_VALUE] inclusive

	int getOpCode(); // returns the OpCode of the data contained (high two digits in the 4 digit number. Thousand's and hundred's digits)
	int getOperand(); // returns the Operand of the data contained (low two digits in the 4 digit number. One's and ten's digits)

	bool increment(); // Increases the value within word by 1. Returns a bool in the exact same manner as writeWord

protected:
	int data;

	word& operator=(const int&) = delete; // Disables the assignment operator for int. Whenever assigning an int value to a word, do it through the writeWord() method
};
