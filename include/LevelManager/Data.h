#pragma once

#include <fstream>
#include <ostream>

//this class saving game data 
//witch level closed / opened
class Data
{
public:
	//all
	static int getLevels();
	//unlock
	static int getDoneLevels();
	//locked
	static int getLockLevels();

	//open next level
	static void setOpen();

private:
	static Data getData();

    Data();
	void load();
	static int m_levels, m_doneLevels;
};