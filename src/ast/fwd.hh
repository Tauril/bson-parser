#pragma once

#include <vector>

namespace Ast
{

  template <typename T>
  using Node = std::shared_ptr<T>;

  // Basic types.
  using Byte = char; // 1 byte
  using Int32 = int32_t; // signed 4 bytes
  using Int64 = int64_t; // signed 8 bytes
  using Uint64 = uint64_t; // unsigned 8 bytes
  using Double = double; // (for completness) 8 bytes floating point
  using Decimal128 = long double; // 16 bytes floating point

  using Bytes = std::vector<Byte>;
  using EList = std::vector<Node<Element>>;

} // namespace Ast
