#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

struct coord
{
	int x;
	int y;
	coord(int y, int x)
	{
		this->y = y;
		this->x = x;
	}
};

class Cell {
public:
	bool inversion;
	string direction;
	bool beer;
	char cellInfo;
	bool isVisited;
	
	Cell(char inputCell) {
		this->cellInfo = inputCell;
	}
	Cell()
	{
		this->cellInfo = ' ';
	};

	void saveState(bool inversion, string& direction, bool beer)
	{
		this->direction = direction;
		this->inversion = inversion;
		this->beer = beer;
		this->isVisited = true;
	}
};

int posX;
int posY;
bool curInversion = false;
bool curBeer = false;
string curDirection = "SOUTH";

int L;
int C;

coord teleport1(0,0);
coord teleport2(0,0);

Cell field[100][100];

string directions[4] = {"SOUTH", "EAST", "NORTH", "WEST"};
vector<string> ans = {};

void inputField(int k) {
	for (int y = 0; y < L; y++) {
		string s;
		getline(cin, s);
		for (int x = 0; x < C; x++) {
			char c = s[x];
			if (c == '@') {
				posX = x;
				posY = y;
				field[y][x] = Cell();
				field[y][x].beer = false;
				field[y][x].direction = "SOUTH";
				field[y][x].inversion = false;
				
			}
			else {
				if (c == 'T')
				{
					if(teleport1.x == 0)
					{
						teleport1.x = x;
						teleport1.y = y;
					}
					else
					{
						teleport2.x = x;
						teleport2.y = y;
					}
				}
				field[y][x] = Cell(c);
			}
		}
	}
}

void printField() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			cout << field[i][j].cellInfo;
		}
		cout << endl;
	}
}

bool obstacle(char c)
{
	return ((c == 'X' && !curBeer) || c == '#');
}

coord movement(string& dirToCheck)
{
	if(dirToCheck == "SOUTH") {
		return {posY+1, posX};
	}
	if (dirToCheck == "EAST") {
		return {posY, posX+1};
	}
	if (dirToCheck == "NORTH") {
		return {posY - 1, posX};
	}
	if (dirToCheck == "WEST") {
		return {posY, posX - 1};
	}
}

bool checkNextCellForObstacles(string& direction)
{
	coord to = movement(direction);
	return obstacle(field[to.y][to.x].cellInfo);
}

void turn()
{
	for(int i = 0; i < 4; i++)
	{
		if(!checkNextCellForObstacles(directions[i]))
		{
			curDirection = directions[i];
			return;
		}
	}
}

// ##########
// #@.!....B#
// ##########
//
// ##########
// #@       #
// ######## #
// # B      #
// #       B#
// ##########
// set<Mode> used_mods;

bool checkForLoop()
{
	return	 curBeer == field[posY][posX].beer &&
	    curDirection == field[posY][posX].direction &&
	    curInversion == field[posY][posX].inversion;
}

void clearTraces()
{
	for(int y = 0; y < L; y++)
	{
		for(int x = 0; x < C; x++)
		{
			field[y][x].isVisited = false;
		}
	}
}

//#########
//#@     B#
//# ##### #
//#       #
//#########

void Move()
{
	if(checkNextCellForObstacles(curDirection))
	{
		turn();
	}
	coord to = movement(curDirection);
	posX = to.x;
	posY = to.y;
	ans.push_back(curDirection);
	if(field[posY][posX].isVisited && checkForLoop())
	{
		cout << "LOOP" << endl;
		exit(0);
	}
	else if (field[posY][posX].cellInfo == 'X')
	{
		field[posY][posX].cellInfo = ' ';
		clearTraces();
	}
	field[posY][posX].saveState(curInversion, curDirection, curBeer);

}

/*void clearTraces()
{
	for(int y = 0; y < L; y++)
	{
		for(int x = 0; x < C; x++)
		{
			field[y][x].isVisited = false;
		}
	}
	field[posY][posX].isVisited = true;
}*/

void checkCellForModifier()
{
	char curInfo = field[posY][posX].cellInfo;
	if (posY == 6 && posX == 3)
	{
		cout << endl;
	}
	switch (curInfo)
	{
		case 'I':
			reverse(directions, directions + 4);
			curInversion = !curInversion;
			break;
		case 'T':
			if(teleport1.x == posX && teleport1.y == posY)
			{
				posX = teleport2.x;
				posY = teleport2.y;
			}
			else
			{
				posX = teleport1.x;
				posY = teleport1.y;
			}
			break;
		case 'B':
			curBeer = !curBeer;
			break;
		case 'S':
			curDirection = "SOUTH";
			break;
		case 'E':
			curDirection = "EAST";
			break;
		case 'N':
			curDirection = "NORTH";
			break;
		case 'W':
			curDirection = "WEST";
			break;
	}
}

int main()
{
	string _;
	cin >> L >> C;
	getline(cin, _);
	inputField(5);
	field[posY][posX].saveState(curInversion, curDirection, curBeer);
	while(field[posY][posX].cellInfo != '$')
	{
		checkCellForModifier();
		Move();
	}
	
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}