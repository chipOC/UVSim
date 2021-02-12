constexpr int MAX_WORD_VALUE = 9999;
constexpr int MIN_WORD_VALUE = -9999;

struct word {
public:
	word() : data(0) {}
	word(int newData) : data(newData) {}
	~word() = default;
	

	bool writeWord(int data); // Changes the value of the word to data provided. Returns true if the written value was within bounds. Returns false if the written value was out of bounds, and sets the data to max (if over) or min (if under) value
	int readWord();

protected:
	int data;

	word& operator=(const int&) = delete; // Disables the assignment operator for int. Whenever assigning an int value to a word, do it through the writeWord() method
};


bool word::writeWord(int newData) {

	if (newData > MAX_WORD_VALUE) 
	{
		this->data = MAX_WORD_VALUE;
		return false;
	}
	else if (newData < MIN_WORD_VALUE) 
	{
		this->data = MIN_WORD_VALUE;
		return false;
	}

	this->data = newData;
	return true;
}

int word::readWord() {
	return this->data;
}