//============================================================================
// Name        : sort_algorithms.cpp
// Author      : Thomas Ruess
// Version     : 0.1
// Copyright   : GNU General Public License
//============================================================================

#include <iostream>
#include <chrono>
#include <random>
#include <limits>

#include "Sorting.h"

template<typename T>
std::vector<T> createRandomVector(unsigned int size, T from =
    std::numeric_limits<T>::min(), T to = std::numeric_limits<T>::max());

int main()
{

  std::vector<double> a = createRandomVector<double>(30, -3, 1);

  Sorting::Algorithms::selection_sort(a);

  std::cout << std::endl << "after:" << std::endl;
  for (auto& elem : a)
    std::cout << elem << std::endl;

}

template<typename T>
std::vector<T> createRandomVector(unsigned int size, T from, T to)
{

  std::cout << "create random vector[" << size << "]" << std::endl;
  std::cout << "from: " << from << std::endl;
  std::cout << "to:   " << to << std::endl;

  std::vector<T> random_vector(size);

  double range = to - from;
  double steps = range / (double) RAND_MAX;

  for (unsigned int i = 0; i < size; i++)
  {
    T random_value = from + (steps * rand());
    random_vector[i] = random_value;
  }

  return random_vector;
}
