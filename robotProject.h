#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
using namespace std;

// 10x10 grid(board)
char board[10][10];

// define a Robot class with data members listed in the assignment
class Robot
{
private:
	int xLocation;
	int yLocation;
	bool cargoBed;
	char load;
public:
	// constructor with parameters
	Robot(int xLocation, int yLocation, bool cargoBed, char load);
	// get/set functions for private data mambers
	void setxLocation(int xLocation);
	int getxLocation();
	void setyLocation(int yLocation);
	int getyLocation();
	void setCargoBed(bool cargoBed);
	bool getCargoBed();
	void setLoad(char load);
	char getLoad();
	// moveTo, pickUp, and dropOff functions
	bool moveTo(int lx, int ly);
	bool pickUp(int lx, int ly);
	bool dropOff(int lx, int ly);
	// overload operator << function set as friend
	friend ostream& operator<<(ostream& out, const Robot& temp);
};
#endif
