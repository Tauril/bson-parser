#pragma once

#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <boost/variant.hpp>

namespace Ast
{

  template <typename T>
  class Element;
  class String;
  class Document;
  class Binary;
  class ObjectId;
  class Boolean;
  class Regex;
  class DBPointer;
  class CodeWS;
  class Date;

  template <typename T>
  using Node = std::shared_ptr<T>;

  // Basic types.
  using Byte = unsigned char; // 1 byte
  using Int32 = int32_t; // signed 4 bytes
  using Int64 = int64_t; // signed 8 bytes
  using Uint64 = uint64_t; // unsigned 8 bytes
  using Double = double; // (for completness) 8 bytes floating point
  using Decimal128 = long double; // 16 bytes floating point

  using Bytes = std::string;
  using CString = Bytes; // For convenience with the grammar
  using EName = CString; // For convenience with the grammar

  using ElementVariant =
    boost::variant<
      Node<Element<std::nullptr_t>>, // undefined, null, min_key, max_key
      Node<Element<Double>>,
      Node<Element<Int32>>,
      Node<Element<Int64>>,
      Node<Element<Uint64>>,
      Node<Element<Decimal128>>,
      Node<Element<Node<String>>>,
      Node<Element<Node<Document>>>,
      Node<Element<Node<Binary>>>,
      Node<Element<Node<ObjectId>>>,
      Node<Element<Node<Boolean>>>,
      Node<Element<Node<Regex>>>,
      Node<Element<Node<DBPointer>>>,
      Node<Element<Node<CodeWS>>>,
      Node<Element<Node<Date>>>
    >;

  using EList = std::vector<ElementVariant>;

} // namespace Ast
