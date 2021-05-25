#include "robotProject.h"

// initialize Robot parameters
Robot::Robot(int xLocation, int yLocation, bool cargoBed, char load)
{
	this->xLocation = xLocation;
	this->yLocation = yLocation;
	this->cargoBed = cargoBed;
	this->load = load;
}

// get/set functions for private data members
void Robot::setxLocation(int xLocation)
{
	this->xLocation = xLocation;
}

int Robot::getxLocation()
{
	return this->xLocation;
}

void Robot::setyLocation(int yLocation)
{
	this->yLocation = yLocation;
}

int Robot::getyLocation()
{
	return this->yLocation;
}

void Robot::setCargoBed(bool cargoBed)
{
	this->cargoBed = cargoBed;
}

bool Robot::getCargoBed()
{
	return this->cargoBed;
}

void Robot::setLoad(char load)
{
	this->load = load;
}

char Robot::getLoad()
{
	return this->load;
}

// moveTo function confirms that the coordinate is within the 10x10 board
// and if so, moves the Robot to the coordinate 1 space at a time using a while loop
bool Robot::moveTo(int lx, int ly)
{
	if (lx < 0 || ly < 0 || lx > 9 || ly > 9)
	{
		return false;
	}
	if (this->xLocation < lx)
	{
		while (lx != this->xLocation)
		{
			this->xLocation++;
		}
	}
	if (this->xLocation > lx)
	{
		while (lx != this->xLocation)
		{
			this->xLocation--;
		}
	}
	if (this->yLocation < ly)
	{
		while (ly != this->yLocation)
		{
			this->yLocation++;
		}
	}
	if (this->yLocation > ly)
	{
		while (ly != this->yLocation)
		{
			this->yLocation--;
		}
	}
	return true;
}

// pickUp function first invokes the moveTo function and then determines if the Robot has cargo already
// if not, it determines if there is a character to pick up at that location
// if there is a character to pick up, the character becomes the Robot's load and the location becomes a '.'
// Robot's cargoBed becomes true
bool Robot::pickUp(int lx, int ly)
{
	moveTo(lx, ly);

	if (cargoBed)
	{
		return false;
	}
	if (board[xLocation][yLocation] == '.')
	{
		return false;
	}
	if (board[xLocation][yLocation] != '.')
	{
		load = board[xLocation][yLocation];
	}	
	board[xLocation][yLocation] = '.';
	cargoBed = true;
	return true;
}

// dropOff function first invokes the moveTo function, then determines if there is already a 
// character at the new location. If not, the location becomes the Robot's load and the 
// Robot's load becomes a '.' and the cargoBed is changed to false
bool Robot::dropOff(int lx, int ly)
{
	moveTo(lx, ly);

	if (board[xLocation][yLocation] != '.')
	{
		return false;
	}
	board[xLocation][yLocation] = load;
	load = '.';
	cargoBed = false;
	return true;
}

// overloaded << operator shows the Robot's grid coordinate and its current load
ostream& operator<<(ostream& out, const Robot& temp)
{
	out << "(" << temp.xLocation << "," << temp.yLocation << "):" << temp.load << endl;
	return out;
}

// prints the board using a for loop
void print2D(char array[10][10])
{
	cout << "Board:" << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// clears the board using a for loop that includes creating a Robot called clearBot with no load at any
// board location that does not contain a '.' and has it pickUp the character. pickUp function also replaces
// the picked up character with a '.' and then the clearBot is deleted leaving only the empty board
void clear(char board[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] != '.')
			{
				Robot* clearBot = new Robot(i, j, false, '.');
				clearBot->pickUp(i, j);
				delete clearBot;
			}
		}
	}
}

int main()
{
	// generates a 10x10 board of '.'s
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = '.';
		}
	}

	// set locations (3,8) and (2,6) to 'B' ad 'C' respectively
	board[3][8] = 'B';
	board[2][6] = 'C';

	// print the board
	print2D(board);

	// I liked the idea of using the system pause we saw in class in order to make the program
	// easier to follow step by step rather than having one long printout of boards
	system("pause");

	// create 2 Robot objects at random locations with empty cargoBeds
	Robot r1(9, 6, false, '.');
	Robot r2(4, 2, false, '.');

	// print the Robot's locations
	cout << "\nRobot 1: " << r1;
	cout << "Robot 2: " << r2 << endl;

	system("pause");

	// move the Robots to (9,2) and (3,4)
	r1.moveTo(9, 2);
	r2.moveTo(3, 4);

	// print the Robots' new locations as well as the board
	cout << "\nRobot 1: " << r1;
	cout << "Robot 2: " << r2 << endl;

	print2D(board);

	system("pause");

	// Robot 1 pickUp the character at (3,8), print the board
	r1.pickUp(3, 8);
	cout << "\nRobot 1: " << r1 << endl;
	print2D(board);

	system("pause");

	// Robot 1 dropOff the character at (9,9), print the board
	r1.dropOff(9, 9);
	cout << "\nRobot 1: " << r1 << endl;
	print2D(board);

	system("pause");

	// Robot 2 pickUp the character at (2,6), print the board
	r2.pickUp(2, 6);
	cout << "\nRobot 2: " << r2 << endl;
	print2D(board);

	system("pause");

	// Robot 2 dropOff the character at (0,0), print the board
	r2.dropOff(0, 0);
	cout << "\nRobot 2: " << r2 << endl;
	print2D(board);

	system("pause");

	// clear the board and print it
	clear(board);
	cout << "\n\"Clear Board\"" << endl << endl;
	print2D(board);

	return 0;
}