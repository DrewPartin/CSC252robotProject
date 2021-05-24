#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
using namespace std;

char board[10][10];

class Robot
{
private:
	int xLocation;
	int yLocation;
	bool cargoBed;
	char load;
public:
	Robot(int xLocation, int yLocation, bool cargoBed, char load);
	void setxLocation(int xLocation);
	int getxLocation();
	void setyLocation(int yLocation);
	int getyLocation();
	void setCargoBed(bool cargoBed);
	bool getCargoBed();
	void setLoad(char load);
	char getLoad();
	bool moveTo(int lx, int ly);
	bool pickUp(int lx, int ly);
	bool dropOff(int lx, int ly);
	friend ostream& operator<<(ostream& out, const Robot& temp);
};
#endif
