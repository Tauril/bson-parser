#pragma once

#include "ast/element.hh"

namespace Ast
{

  template <typename T>
  Element<T>::Element(ElementAttribute::InputType type, const EName& name,
                      T attr)
    : type_(type)
    , name_(name)
    , attr_(attr)
  {}

  template <typename T>
  inline ElementAttribute::InputType
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
