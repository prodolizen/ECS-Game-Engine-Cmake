#pragma once
#include "Component.h"
#include "AL/al.h"
#include "AL/alc.h"
#include <vector>
#include <string>

namespace zengine
{
	struct Audio : Component
	{
		void onInitialize();
		void onTick();
		void playSound(const std::string& _path, bool loop);

	private:
		ALCdevice* device;
		ALCcontext* context;
		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq);
	};
}