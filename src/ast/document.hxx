#pragma once

namespace Ast
{

  inline void
  Document::add(Node<Element> element)
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

  inline EList
  Document::e_list_get() const
  {
    return e_list_;
  }

} // namespace Ast
