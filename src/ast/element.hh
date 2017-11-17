#pragma once

#include <map>
#include <unordered_map>

#include "ast/fwd.hh"

namespace Ast
{

  namespace ElementAttribute
  {

    // Type of an attribute
    enum class Type
    {
      /* \x01 */ _double,
      /* \x02 */ _string,
      /* \x03 */ _embedded_doc,
      /* \x04 */ _array,
      /* \x05 */ _binary_data,
      /* \x06 */ _undefined, // Deprecated
      /* \x07 */ _objectid,
      /* \x08 */ _boolean, // true or false
      /* \x09 */ _datetime,
      /* \x0A */ _null,
      /* \x0B */ _regex,
      /* \x0C */ _db_pointer,
      /* \x0D */ _js_code,
      /* \x0E */ _symbol, // Deprecated
      /* \x0F */ _js_code_ws,
      /* \x10 */ _int32,
      /* \x11 */ _uint64,
      /* \x12 */ _int64,
      /* \x13 */ _decimal128,
      /* \xFF */ _min_key,
      /* \x7F */ _max_key
    };

    static const std::unordered_map<char, Type>
      type_attr =
    {
      {'\x01', Type::_double},
      {'\x02', Type::_string},
      {'\x03', Type::_embedded_doc},
      {'\x04', Type::_array},
      {'\x05', Type::_binary_data},
      {'\x06', Type::_undefined},
      {'\x07', Type::_objectid},
      {'\x08', Type::_boolean},
      {'\x09', Type::_datetime},
      {'\x0A', Type::_null},
      {'\x0B', Type::_regex},
      {'\x0C', Type::_db_pointer},
      {'\x0D', Type::_js_code},
      {'\x0E', Type::_symbol},
      {'\x0F', Type::_js_code_ws},
      {'\x10', Type::_int32},
      {'\x11', Type::_uint64},
      {'\x12', Type::_int64},
      {'\x13', Type::_decimal128},
      {'\xFF', Type::_min_key},
      {'\x7F', Type::_max_key}
    };

    static const std::map<Type, unsigned>
      type_val =
    {
      {Type::_undefined,     0}, // std::nullptr_t
      {Type::_null,          0}, // std::nullptr_t
      {Type::_min_key,       0}, // std::nullptr_t
      {Type::_max_key,       0}, // std::nullptr_t
      {Type::_double,        1}, // Double
      {Type::_int32,         2}, // Int32
      {Type::_int64,         3}, // Int64
      {Type::_datetime,      3}, // Int64
      {Type::_uint64,        4}, // Uint64
      {Type::_decimal128,    5}, // Decimal128
      {Type::_string,        6}, // Node<String>
      {Type::_js_code,       6}, // Node<String>
      {Type::_symbol,        6}, // Node<String>
      {Type::_embedded_doc,  7}, // Node<Document>
      {Type::_array,         7}, // Node<Document>
      {Type::_binary_data,   8}, // Node<Binary>
      {Type::_objectid,      9}, // Node<ObjectId>
      {Type::_boolean,      10}, // Node<Boolean>
      {Type::_regex,        11}, // Node<Regex>
      {Type::_db_pointer,   12}, // Node<DBPointer>
      {Type::_js_code_ws,   13}  // Node<CodeWS>
    };

  } // namespace ElementAttribute

  template <typename T>
  class Element
  {
  public:
    Element(ElementAttribute::Type type, const EName& name, T attr);

    ElementAttribute::Type type_get() const;
    EName name_get() const;
    // TODO: SFINAE getter for smart pointer and for literal types
    T attr_get() const;
  private:
    // Type of element
    ElementAttribute::Type type_;
    // Key name
    EName name_;
    // Attributes of the element.
    T attr_;
  };

} // namespace Ast

#include "ast/element.hxx"
