#pragma once

#include "ast/document.hh"

namespace Ast
{

  template <typename T>
  inline void
  Document::add(Node<Element<T>> element)
  {
    e_list_.emplace_back(element);
  }

  inline void
  Document::size_set(Int32 size)
  {
    size_ = size;
  }

  inline Int32
  Document::size_get() const
  {
    return size_;
  }

  inline const EList&
  Document::e_list_get() const
  {
    return e_list_;
  }

} // namespace Ast
