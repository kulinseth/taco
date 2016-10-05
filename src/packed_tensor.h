#ifndef TACIT_PACKED_TENSOR_H
#define TACIT_PACKED_TENSOR_H

#include <cstdlib>
#include <utility>
#include <vector>
#include <inttypes.h>
#include <ostream>

namespace tacit {

class PackedTensor {
public:
  // TODO: Change all these types to void pointers to support multiple
  //       index/value types
  typedef uint32_t                IndexType;
  typedef std::vector<IndexType>  IndexArray;
  typedef std::vector<IndexArray> Index;
  typedef std::vector<Index>      Indices;
  typedef std::vector<double>     Values;

  PackedTensor(const Values& values, const Indices& indices)
      : values(values), indices(indices) {}

  size_t getNnz() const {
    return getValues().size();
  }

  const Values& getValues() const {
    return values;
  }

  const Indices& getIndices() const {
    return indices;
  }

private:
  Values  values;
  Indices indices;
};

std::ostream& operator<<(std::ostream& os, const PackedTensor& tp);

}
#endif