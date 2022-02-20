#include "Data.h"
#include <string>

//=====================================		CONSTRUCOR/PRIVATE		==================================

Data::Data()
{
	load();
}

//=====================================		SINGLETON		==================================

Data Data::getData()
{
	static Data data = Data();
	return data;
}

//=====================================		PUBLIC		==================================

int Data::getLevels()
{
	return getData().m_levels;
}

int Data::getDoneLevels()
{
	return getData().m_doneLevels;
}

int Data::getLockLevels()
{
	return getData().m_levels - getData().m_doneLevels;
}

void Data::setOpen()
{
	if (Data::getData().m_doneLevels >= m_levels)
		return;//don't open
	std::string str = std::to_string(Data::getData().m_doneLevels + 1)
		+ " " + std::to_string(Data::getData().m_levels);

	auto data = std::ofstream("data.txt");
	data << str;

	data.close();	

	m_doneLevels++;//add static
}

//=====================================		PRIVATE		==================================

void Data::load()
{
	auto data = std::ifstream("data.txt");

	int unlock, all,lock;
	data >> m_doneLevels;
	data >> m_levels;

	data.close();
}
int Data::m_doneLevels = 0;
int Data::m_levels = 0;
