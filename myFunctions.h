#pragma once

class MyString {
	size_t _length = 0;
	size_t _capacity = 16;
	char* _text = nullptr;

	void setText(const char* text);
public:
	MyString() {
		if (_text == nullptr)
			_text = new char[_capacity];
	}
	MyString(const char* text);
	MyString(const MyString& data);

	char& front();
	char& back();

	char* print() const { return _text; }

	char& at(size_t index);
	bool empty() const;
	int compare(const MyString right);
	size_t size() const;
	size_t find(char chr) const;
	size_t rfind(char chr) const;
	void clear();
	void lower();
	void upper();
	void capitalize();

};

void MyString::setText(const char* text) {

	_length = strlen(text) + 1;
	if (_length > _capacity)
	{
		while (_length > _capacity)
			_capacity += 16;
		_text = new char[_capacity];
	}

	for (size_t i = 0; i < _length; i++)
		_text[i] = text[i];

	_text[_length] = '\0';
}


MyString::MyString(const char* text) :MyString()
{
	setText(text);
}


MyString::MyString(const MyString& data)
{
	setText(data.print());
	_capacity = data._capacity;
	_length = data._length;
}

char& MyString::front() {
	char index = this->_text[0];
	return index;
}



char& MyString::back() {
	int len = strlen(this->_text);
	char index = this->_text[len - 1];
	return index;
}

char& MyString::at(size_t index) {
	if (this->_text == nullptr)
		assert(!"THIS STRING IS EMPTY");
	char* text = this->print();
	int len = strlen(this->_text);
	char found;
	if (index > len)
		assert(!"INDEX INVALID!");


	found = text[index];
	return found;

}


bool MyString::empty() const {
	int len = strlen(this->_text);
	if (len == 0)return false;
	else return true;
}

size_t MyString::size() const {
	int len = strlen(this->_text);
	return len;
}


int MyString::compare(const MyString right) {
	int lenLeft = strlen(this->_text);
	int lenRight = strlen(right._text);
	if (lenLeft == lenRight) return 0;
	else if (lenLeft < lenRight)return -1;
	else return 1;
}


size_t MyString::find(char chr) const {
	for (size_t i = 0; i < this->_length; i++)
	{
		if (this->_text[i] == chr)return i;
	}
	return -1;
}


size_t MyString::rfind(char chr) const {
	for (size_t i = this->_length; i > 0; i--)
	{
		if (this->_text[i] == chr)return i;
	}
	return -1;
}


void MyString::clear() {
	if (this->_text == nullptr)
		assert(!"THIS STRING IS ALREADY CLEAR!");
	delete this->_text;
	this->_text = nullptr;
}

void MyString::lower() {
	if (_text == nullptr)
		cout << "THIS STRING IS EMPTY!" << endl;

	for (size_t i = 0; i < _length; i++)
	{
		if (int(_text[i]) > 96 && int(_text[i]) < 123)
			_text[i] = int(_text[i]) - 32;
	}

}

void MyString::upper() {
	if (_text == nullptr)
		cout << "THIS STRING IS EMPTY!" << endl;

	for (size_t i = 0; i < _length; i++)
	{
		if (int(_text[i]) > 64 && int(_text[i]) < 91)
			_text[i] = int(_text[i]) + 32;
	}

}

void MyString::capitalize()  {//needs update!
	if (_text == nullptr)
		cout << "THIS STRING IS EMPTY!" << endl;

	for (size_t i = 0; i < _length; i++)
	{
		if (i == 0 && (int(_text[i]) > 64 && int(_text[i]) < 91))
			_text[i] = int(_text[i]) + 32;
	}
}








