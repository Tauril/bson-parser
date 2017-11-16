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
  Document::e_list_get() const
  {
    return e_list_;
  }

} // namespace Ast
