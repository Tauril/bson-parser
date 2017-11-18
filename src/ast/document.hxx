#pragma once

#include "ast/document.hh"

namespace Ast
{

  inline Int32
  Document::size_get() const
  {
    return size_;
  }

  inline const EList&
  Document::elist_get() const
  {
    return elist_;
  }

  inline bool
  Document::is_array_get() const
  {
    return is_array_;
  }

  inline void
  Document::is_array_set(bool is_array)
  {
    is_array_ = is_array;
  }

} // namespace Ast
