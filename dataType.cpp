#include "dataType.h"

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


int word::getOpCode() {
	// use integer division to get the high 2 digits of the 4 digit number
	return data / 100;
}

int word::getOperand() {
	// use modulus division to get the low 2 digits of the 4 digit number
	return data % 100;
}

bool word::increment() {
	return writeWord(this->readWord() + 1);
}
