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
      /*  0 */ _double,
      /*  1 */ _string,
      /*  2 */ _embedded_doc,
      /*  3 */ _array,
      /*  4 */ _binary_data,
      /*  5 */ _undefined, // Deprecated
      /*  6 */ _objectid,
      /*  7 */ _false,
      /*  8 */ _true,
      /*  9 */ _datetime,
      /* 10 */ _null,
      /* 11 */ _regex,
      /* 12 */ _db_pointer,
      /* 13 */ _js_code,
      /* 14 */ _symbol, // Deprecated
      /* 15 */ _js_code_ws,
      /* 16 */ _int32,
      /* 17 */ _uint64,
      /* 18 */ _int64,
      /* 19 */ _decimal128,
      /* 20 */ _min_key,
      /* 21 */ _max_key
    };

    Element(Element::Type type, const EName& name, T attr);

    Element::Type type_get() const;
    EName name_get() const;
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
