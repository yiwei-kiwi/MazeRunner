#pragma once
#include <SFML\Graphics.hpp>
#include "Instance.h"
class DisplayInstance
{
public:
	DisplayInstance();
	~DisplayInstance();
	Instance game;
	
	
private:
	void displayLost();
	void displayVictory();
};

