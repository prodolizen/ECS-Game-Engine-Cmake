#include "Maths.h"

namespace zengine
{
    float Maths::getRandomFloat(float min, float max)
    {
        std::random_device rd;

        std::mt19937 generator(rd());

        std::uniform_real_distribution<float> distribution(min, max);

        return distribution(generator);
    }
}