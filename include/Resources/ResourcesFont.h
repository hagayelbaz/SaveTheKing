#pragma once

#include "Resources.h"

namespace Resources
{
	class RscFont
	{
	public:
		RscFont(const RscFont&) = delete;
		static sf::Font& getFont(const FontName font);
	private:
		void loadFonts();
		std::map<FontName, sf::Font> m_res;
		RscFont();
	};
}