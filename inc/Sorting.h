/*
 * Sorting.h
 *
 *  Created on: 24.10.2018
 *      Author: rh1n0
 */

#include <vector>

#ifndef SORTING_H_
#define SORTING_H_

namespace Sorting
{

  typedef unsigned int index;

  class Algorithms
  {
    public:
      /**
       *
       * @param vec
       * @param ascending
       * @return
       */
      template<typename T>
      static std::vector<index> simplesort(std::vector<T>& vec, bool ascending =
          true);

  };

}

/**
 *
 * @param vec
 * @param ascending
 * @return
 */
template<typename T>
inline std::vector<Sorting::index> Sorting::Algorithms::simplesort(
    std::vector<T>& vec, bool ascending)
{
  std::vector<index> indexes(vec.size());
  for(index i = 0; i < vec.size(); i++)
    indexes[i] = i;

  auto swap = [&] (index i, index j)
  {
    T tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;

    index tmp2 = indexes[i];
    indexes[i] = indexes[j];
    indexes[j] = tmp2;
  };

  for (index i = 0; i < vec.size(); i++)
  {
    for (index j = i + 1; j < vec.size(); j++)
    {
      if ((vec[i] > vec[j] && ascending) || (vec[i] < vec[j] && !ascending))
      {
        swap(i, j);
      }
    }
  }

  return std::vector<index>();
}

#endif /* SORTING_H_ */
