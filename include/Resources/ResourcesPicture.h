#pragma once

#include "Resources.h"

namespace Resources
{
	class RscPic
	{
	public:
		RscPic(const RscPic&) = delete;
		static sf::Texture& getPicture(const PictureName picture);
	private:
		void loadImages();
		std::map<PictureName, sf::Texture> m_res;
		RscPic();
	};
}