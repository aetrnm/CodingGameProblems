#include <iostream>
#include <map>
#include <string>

using namespace std;

class Cell {
	map<char, Cell*> childrenMap;

public:
	static int _amountOfChilren;

	void Add(string number)
	{
		Cell* currentCell = this;
		for (int i = 0; i < number.size(); i++)
		{
			char digit = number[i];
			Cell* cell = currentCell->childrenMap[digit];
			if (!cell)
			{
				cell = new Cell();
				currentCell->childrenMap[number[i]] = cell;
				Cell::_amountOfChilren++;
			}
			currentCell = cell;
		}
	}
};

int Cell::_amountOfChilren = 0;

int main()
{
	Cell* origin = new Cell();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		origin->Add(s);
	}

	cout << Cell::_amountOfChilren << endl;
}