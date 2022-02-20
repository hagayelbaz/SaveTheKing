#include "GiftTime.h"

int GiftTime::getRandTime()
{
	return std::rand() % MAX + MIN;
}
