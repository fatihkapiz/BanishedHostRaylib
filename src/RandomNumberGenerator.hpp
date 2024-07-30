#pragma once
#include <random>

class RandomGenerator {
public:
  static RandomGenerator &getInstance() {
    static RandomGenerator instance;
    return instance;
  }

  // Function to generate a random integer between min and max (inclusive)
  int getRandomInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
  }

  // Function to generate a random float between min and max
  float getRandomFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(rng);
  }

private:
  RandomGenerator() {
    std::random_device rd; // Obtain a random number from hardware
    rng.seed(rd());        // Seed the generator
  }

  RandomGenerator(const RandomGenerator &) = delete;
  RandomGenerator &operator=(const RandomGenerator &) = delete;

  std::mt19937 rng; // Mersenne Twister RNG
};
