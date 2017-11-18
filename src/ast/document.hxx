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

} // namespace Ast
