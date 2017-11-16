#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  template <typename T>
  class Element
  {
  public:
    // Type of element.
    enum class Type
    {
      /* \x01 */ _double,
      /* \x02 */ _string,
      /* \x03 */ _embedded_doc,
      /* \x04 */ _array,
      /* \x05 */ _binary_data,
      /* \x06 */ _undefined, // Deprecated
      /* \x07 */ _objectid,
      /* \x08 */ _false,
      /* \x08 */ _true,
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

    Element(Element::Type type, const EName& name, T attr);

    Element::Type type_get() const;
    EName name_get() const;
    // TODO: SFINAE getter for smart pointer and for literal types
    T attr_get() const;
  private:
    // Type of element
    Element::Type type_;
    // Key name
    EName name_;
    // Attributes of the element.
    T attr_;
  };

} // namespace Ast

#include "ast/element.hxx"
