#pragma once

#include <SFML/Audio.hpp>
#include "Resources.h"

namespace Resources
{
	class RssSound
	{
	public:
		RssSound(const RssSound&) = delete;
		static sf::SoundBuffer& getSoundBuffer(const SoundName picture);
		static sf::Sound getSound(const SoundName picture);
	private:
		void loadSound();
		std::map<SoundName, sf::SoundBuffer> m_res;
		RssSound();
	};
}