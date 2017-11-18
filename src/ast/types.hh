#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  template <unsigned N>
  struct Types;

  template <>
  struct Types<0>
  {
    typedef std::nullptr_t type;
  };

  template <>
  struct Types<1>
  {
    typedef Double type;
  };

  template <>
  struct Types<2>
  {
    typedef Int32 type;
  };

  template <>
  struct Types<3>
  {
    typedef Int64 type;
  };

  template <>
  struct Types<4>
  {
    typedef Uint64 type;
  };

  template <>
  struct Types<5>
  {
    typedef Decimal128 type;
  };

  template <>
  struct Types<6>
  {
    typedef Node<String> type;
  };

  template <>
  struct Types<7>
  {
    typedef Node<Document> type;
  };

  template <>
  struct Types<8>
  {
    typedef Node<Binary> type;
  };

  template <>
  struct Types<9>
  {
    typedef Node<ObjectId> type;
  };

  template <>
  struct Types<10>
  {
    typedef Node<Boolean> type;
  };

  template <>
  struct Types<11>
  {
    typedef Node<Regex> type;
  };

  template <>
  struct Types<12>
  {
    typedef Node<DBPointer> type;
  };

  template <>
  struct Types<13>
  {
    typedef Node<CodeWS> type;
  };

  template <>
  struct Types<14>
  {
    typedef Node<Date> type;
  };

} // namespace Ast
