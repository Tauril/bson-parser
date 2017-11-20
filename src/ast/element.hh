#pragma once

#include <map>
#include <unordered_map>

#include "ast/fwd.hh"
#include "ast/types.hh"

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

    static const std::map<InputType, ElementType>
      type_val =
    {
      {InputType::_undefined,     ElementType::_nullptr}, // std::nullptr_t
      {InputType::_null,          ElementType::_nullptr}, // std::nullptr_t
      {InputType::_min_key,       ElementType::_nullptr}, // std::nullptr_t
      {InputType::_max_key,       ElementType::_nullptr}, // std::nullptr_t
      {InputType::_double,        ElementType::_double}, // Double
      {InputType::_int32,         ElementType::_int32}, // Int32
      {InputType::_int64,         ElementType::_int64}, // Int64
      {InputType::_uint64,        ElementType::_uint64}, // Uint64
      {InputType::_decimal128,    ElementType::_decimal128}, // Decimal128
      {InputType::_string,        ElementType::_string}, // Node<String>
      {InputType::_js_code,       ElementType::_string}, // Node<String>
      {InputType::_symbol,        ElementType::_string}, // Node<String>
      {InputType::_embedded_doc,  ElementType::_document}, // Node<Document>
      {InputType::_array,         ElementType::_document}, // Node<Document>
      {InputType::_binary_data,   ElementType::_binary}, // Node<Binary>
      {InputType::_objectid,      ElementType::_objectid}, // Node<ObjectId>
      {InputType::_boolean,       ElementType::_boolean}, // Node<Boolean>
      {InputType::_regex,         ElementType::_regex}, // Node<Regex>
      {InputType::_db_pointer,    ElementType::_dbpointer}, // Node<DBPointer>
      {InputType::_js_code_ws,    ElementType::_codews}, // Node<CodeWS>
      {InputType::_datetime,      ElementType::_date}, // Node<Date>
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
