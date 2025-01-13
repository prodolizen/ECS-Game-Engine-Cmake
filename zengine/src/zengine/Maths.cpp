#include "Maths.h"

namespace zengine
{
    float Maths::getRandomFloat(float min, float max)
    {
        // Create a random device
        std::random_device rd;

        // Seed the random number generator
        std::mt19937 generator(rd());

        // Define the range for the random number
        std::uniform_real_distribution<float> distribution(min, max);

        // Generate and return the random float
        return distribution(generator);
    }
}