#pragma once

#include "Gift.h"


class GiftTime : public Gift
{
public:
	using Gift::Gift;
	virtual int take() = 0;

protected:
	const int MIN = 10;
	const int MAX = 60;
	virtual int getRandTime();
};