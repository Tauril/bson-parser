#pragma once

#include "ast/binary.hh"

namespace Ast
{

  inline Int32
  size_get() const
  {
    return size_;
  }

  inline Binary::Subtype
  subtype_get() const
  {
    return subtype_;
  }

  inline const Bytes&
  bytes_get() const
  {
    return bytes_;
  }

} // namespace Ast
