#pragma once

#include "GiftTime.h"

class GiftTimeAdd : public GiftTime
{
public:
	using GiftTime::GiftTime;

	int take() override;
};