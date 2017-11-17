#pragma once

#include "ast/element.hh"

namespace Ast
{

  template <typename T>
  inline ElementAttribute::Type
  Element<T>::type_get() const
  {
    return type_;
  }

  template <typename T>
  inline EName
  Element<T>::name_get() const
  {
    return name_;
  }

  template <typename T>
  inline T
  Element<T>::attr_get() const
  {
    return attr_;
  }

} // namespace Ast
