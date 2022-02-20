#include "ResourcesFont.h"

namespace Resources
{
	//=====================================		CONSTRUCOR/PRIVATE		==================================

	RscFont::RscFont()
	{
		loadFonts();
	}
	
	//=====================================		PRIVATE		==================================

	void RscFont::loadFonts()
	{
		sf::Font resArial = sf::Font();
		resArial.loadFromFile("arial.ttf");
		m_res.insert({ FontName::Arial, resArial });

		sf::Font resSpecial = sf::Font();
		resSpecial.loadFromFile("special.ttf");
		m_res.insert({ FontName::Special, resSpecial });
	}

	//=====================================		PUBLIC		==================================

	sf::Font& RscFont::getFont(const FontName font)
	{
		static RscFont resources = RscFont();
		return resources.m_res.at(font);
	}
}