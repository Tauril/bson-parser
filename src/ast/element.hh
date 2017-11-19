#pragma once

#include <map>
#include <unordered_map>

#include "ast/fwd.hh"

namespace Ast
{

  namespace ElementAttribute
  {

    // Type of an attribute
    enum class InputType
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

    static const std::unordered_map<char, InputType>
      type_attr =
    {
      {'\x01', InputType::_double},
      {'\x02', InputType::_string},
      {'\x03', InputType::_embedded_doc},
      {'\x04', InputType::_array},
      {'\x05', InputType::_binary_data},
      {'\x06', InputType::_undefined},
      {'\x07', InputType::_objectid},
      {'\x08', InputType::_boolean},
      {'\x09', InputType::_datetime},
      {'\x0A', InputType::_null},
      {'\x0B', InputType::_regex},
      {'\x0C', InputType::_db_pointer},
      {'\x0D', InputType::_js_code},
      {'\x0E', InputType::_symbol},
      {'\x0F', InputType::_js_code_ws},
      {'\x10', InputType::_int32},
      {'\x11', InputType::_uint64},
      {'\x12', InputType::_int64},
      {'\x13', InputType::_decimal128},
      {'\xFF', InputType::_min_key},
      {'\x7F', InputType::_max_key}
    };

    static const std::map<InputType, unsigned>
      type_val =
    {
      {InputType::_undefined,     0}, // std::nullptr_t
      {InputType::_null,          0}, // std::nullptr_t
      {InputType::_min_key,       0}, // std::nullptr_t
      {InputType::_max_key,       0}, // std::nullptr_t
      {InputType::_double,        1}, // Double
      {InputType::_int32,         2}, // Int32
      {InputType::_int64,         3}, // Int64
      {InputType::_uint64,        4}, // Uint64
      {InputType::_decimal128,    5}, // Decimal128
      {InputType::_string,        6}, // Node<String>
      {InputType::_js_code,       6}, // Node<String>
      {InputType::_symbol,        6}, // Node<String>
      {InputType::_embedded_doc,  7}, // Node<Document>
      {InputType::_array,         7}, // Node<Document>
      {InputType::_binary_data,   8}, // Node<Binary>
      {InputType::_objectid,      9}, // Node<ObjectId>
      {InputType::_boolean,      10}, // Node<Boolean>
      {InputType::_regex,        11}, // Node<Regex>
      {InputType::_db_pointer,   12}, // Node<DBPointer>
      {InputType::_js_code_ws,   13}, // Node<CodeWS>
      {InputType::_datetime,     14}, // Node<Date>
    };

  } // namespace ElementAttribute

  template <typename T>
  class Element
  {
  public:
    Element(ElementAttribute::InputType type, const EName& name, T attr);

    ElementAttribute::InputType type_get() const;
    EName name_get() const;
    T attr_get() const;
  private:
    // Type of element
    ElementAttribute::InputType type_;
    // Key name
    EName name_;
    // Attributes of the element.
    T attr_;
  };

} // namespace Ast

#include "ast/element.hxx"
