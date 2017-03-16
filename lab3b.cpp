#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

class student
{
	char fio[64];
	char sub_area[64];
	int size1 = 0;
	int size2 = 0;

public:
	student( char* fio, char* sub_area)
	{
		this->size1 = strlen(fio);
		this->size2 = strlen(sub_area);
		for( unsigned int i = 0; i < strlen(fio); ++i ) this->fio[i] = fio[i];
		for( unsigned int i = 0; i < strlen(sub_area); ++i ) this->sub_area[i] = sub_area[i];
	}
	
	virtual void print()
	{
		cout << endl;
		for( unsigned int i = 0; i < size1; ++i ) cout << fio[i];
		cout << " ";
		for( unsigned int i = 0; i < size2; ++i ) cout << sub_area[i];
	}
};

class tutor: public student
{
	char c_fio[64];
	int size3 = 0;

public: 
	
	tutor(char* fio, char* sub_area, char* c_fio):
	 student(fio, sub_area)
	{
		this->size3 = strlen(c_fio);
		for( unsigned int i = 0; i < size3; ++i ) this->c_fio[i] = c_fio[i];
	}

	void print()
	{
		student::print();
		cout << " Tutor: ";
		for( unsigned int i = 0; i < size3; ++i ) cout << c_fio[i];
		cout << endl;
	}
};

int main(void)
{
	int size = 0;
	char string1[64];
	char string2[64];
	char string3[64];
	student *ps;
	cout << " Choose the student and his subject area " << endl << " The number of students is: ";
	cin >> size;

	for ( unsigned int i = 0; i < size; ++i )
	{
		cout << endl << " Student " << i+1 << " ";
		fflush(stdin); 
		cin.getline(string1, 64); 
		cout << endl << " Subject area " << " ";
		fflush(stdin); 
		cin.getline(string2, 64);
		fflush(stdin); 
		student s(string1, string2);
		ps = &s;
		ps->print();
		cout << endl << endl << " Tutor " << " ";
		fflush(stdin); 
		cin.getline(string3, 64);
		tutor t(string1, string2, string3);
		ps = &t;
		ps->print();
	}
	

	delete [] ps;
	cout << endl << endl << "Press any button to exit the program" << endl;
	_getch();
	return 0;
}