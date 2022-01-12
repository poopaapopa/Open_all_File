#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;

#define MAX_PATH 260
#define NUM_COLS 18
#define NUM_ROWS 24

int main()
{
	char path[MAX_PATH];
	cout << "Inputh path to file: ";
	cin.getline(path, MAX_PATH);
	int counter = 0, i = 0, j = 0;
	char text[NUM_COLS];
	ifstream input(path, ios::in | ios::binary);
	if (!input)
	{
		cout << "Cann't open file for display!\n";
		return -83434756;
	}
	cout.setf(ios::uppercase);
	while (!input.eof())
	{
		for (int i = 0; i < NUM_COLS and !input.eof(); i++)
			input.get(text[i]);
		if (i < NUM_COLS)
			i--;
		for (j = 0; j < i; j++)
			if ((unsigned)text[j] < 0x10)
				cout << setw(2) << 0 << hex << (unsigned)text[j];
			else
				cout << setw(3) << 0 << hex << (unsigned)text[j];
		for (; j < NUM_COLS; j++)
			cout << "      ";
		cout << "\t";
		for (j = 0; j < i; j++)
			if (text[j] > 31 and text[j] <= 255)
				cout << text[j];
			else
				cout << ".";
		cout << "\n";
		if (++counter == NUM_COLS)
		{
			counter = 0;
			cout << "press any key to continue..." << flush;
			_getch();
			cout << "\n";
		}
	}
	input.close();
	return 0;
}