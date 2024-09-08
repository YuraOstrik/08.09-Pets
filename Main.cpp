#include<iostream>
#include<Windows.h>
using namespace std;

class Pets {
protected: 
	char* name;
	char* character;
public:
	Pets() = default;
	Pets(const char* n, const char* c)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		character = new char[strlen(c) + 1];
		strcpy_s(character, strlen(c) + 1, c);
	}

	void Print() const 
	{
		cout << "Out Print---/ \n";
		cout << "Name > " << name << endl
			<< "Character > " << character << endl;
	}

	void Input() {
		cout << "Enter the name -> ";
		char bit[20];
		cin.getline(bit, 20);

		if (name != nullptr) {
			delete[] name;
		}
		name = new char[strlen(bit) + 1];
		strcpy_s(name, strlen(bit) + 1, bit);

		cout << "Enter the character -> ";
		cin.getline(bit, 20);
		if (character != nullptr) {
			delete[] character;
		}
		character = new char[strlen(bit) + 1];
		strcpy_s(character, strlen(bit) + 1, bit);
	}

	~Pets() 
	{
		if (name != nullptr || character != nullptr) {
			delete[] name;
			delete[] character;
		}
		cout << "Destructor --Pets--\n";
	}
};


class Dog : public Pets 
{
public:
	Dog(const char* name) : Pets(name, "Curious") {};

	void Print()
	{
		cout << " - Dog - " << endl;
		Pets::Print();
	}
};

class Cat : public Pets
{
public:
	Cat(const char* name) : Pets(name, "Smart") {};

	void Print()
	{
		cout << " - Cat - " << endl;
		Pets::Print();
	}
};

class Parrot : public Pets
{
public:
	Parrot(const char* name) : Pets(name, "Clever") {};

	void Print()
	{
		cout << " - Parrot - " << endl;
		Pets::Print();
	}
};



int main() {

	Dog dog("Rick");

	dog.Print();
	dog.Input();
	dog.Print();
}


