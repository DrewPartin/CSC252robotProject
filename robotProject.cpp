#include "robotProject.h"

Robot::Robot(int xLocation, int yLocation, bool cargoBed, char load)
{
	this->xLocation = xLocation;
	this->yLocation = yLocation;
	this->cargoBed = cargoBed;
	this->load = load;
}
