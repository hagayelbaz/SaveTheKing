#pragma once

#include "GiftTime.h"

class GiftTimeDecrease : public GiftTime
{
public:
	using GiftTime::GiftTime;

	int take() override;
};