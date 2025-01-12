#include "Audio.h"
#include <stdexcept>

#include "stb_vorbis.c"

namespace zengine
{
	void Audio::onInitialize()
	{
		device = alcOpenDevice(NULL);

		if (!device)
		{
			throw std::runtime_error("Failed to open audio device");
		}

		context = alcCreateContext(device, NULL);

		if (!context)
		{
			alcCloseDevice(device);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::runtime_error("Failed to make context current");
		}

		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		//alListener3f(AL_VELOCITY, 0.0f, 0.0f, 0.0f);
	}
	void Audio::onTick()
	{

	}
	void Audio::playSound(const std::string& _path, bool loop)
	{
		ALenum format = 0; 
		ALsizei freq = 0; 
		std::vector<unsigned char> bufferData;
		load_ogg(_path, bufferData, format, freq);

		ALuint bufferId = 0;
		alGenBuffers(1, &bufferId);

		alBufferData(bufferId, format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), freq);

		ALuint sourceId = 0;
		alGenSources(1, &sourceId);

		alSourcei(sourceId, AL_BUFFER, bufferId);
		alSourcei(sourceId, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);

		alSourcePlay(sourceId);
	}
	void Audio::load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(_path.c_str(),
			&channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::runtime_error("Failed to open file '" + _path + "' for decoding");
		}

		// Record the format required by OpenAL
		if (channels < 2)
		{
			_format = AL_FORMAT_MONO16;
		}
		else
		{
			_format = AL_FORMAT_STEREO16;
		}

		// Copy (# samples) * (1 or 2 channels) * (16 bits == 2 bytes == short)
		_buffer.resize(samples * channels * sizeof(short));
		memcpy(&_buffer.at(0), output, _buffer.size());

		// Record the sample rate required by OpenAL
		_freq = sampleRate;

		// Clean up the read data
		free(output);
	}
}