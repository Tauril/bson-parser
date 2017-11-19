#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  // Type name
  enum class ElementType
  {
    _nullptr,
    _double,
    _int32,
    _int64,
    _uint64,
    _decimal128,
    _string,
    _document,
    _binary,
    _objectid,
    _boolean,
    _regex,
    _dbpointer,
    _codews,
    _date
  };

  template <ElementType N>
  struct Types;

  template <>
  struct Types<ElementType::_nullptr>
  {
    typedef std::nullptr_t type;
  };

  template <>
  struct Types<ElementType::_double>
  {
    typedef Double type;
  };

  template <>
  struct Types<ElementType::_int32>
  {
    typedef Int32 type;
  };

  template <>
  struct Types<ElementType::_int64>
  {
    typedef Int64 type;
  };

  template <>
  struct Types<ElementType::_uint64>
  {
    typedef Uint64 type;
  };

  template <>
  struct Types<ElementType::_decimal128>
  {
    typedef Decimal128 type;
  };

  template <>
  struct Types<ElementType::_string>
  {
    typedef Node<String> type;
  };

  template <>
  struct Types<ElementType::_document>
  {
    typedef Node<Document> type;
  };

  template <>
  struct Types<ElementType::_binary>
  {
    typedef Node<Binary> type;
  };

  template <>
  struct Types<ElementType::_objectid>
  {
    typedef Node<ObjectId> type;
  };

  template <>
  struct Types<ElementType::_boolean>
  {
    typedef Node<Boolean> type;
  };

  template <>
  struct Types<ElementType::_regex>
  {
    typedef Node<Regex> type;
  };

  template <>
  struct Types<ElementType::_dbpointer>
  {
    typedef Node<DBPointer> type;
  };

  template <>
  struct Types<ElementType::_codews>
  {
    typedef Node<CodeWS> type;
  };

  template <>
  struct Types<ElementType::_date>
  {
    typedef Node<Date> type;
  };

} // namespace Ast
