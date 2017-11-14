#pragma once

#include "ast/binary.hh"

namespace Ast
{

  inline Int32
  Binary::size_get() const
  {
    return size_;
  }

  inline Binary::Subtype
  Binary::subtype_get() const
  {
    return subtype_;
  }

  inline const Bytes&
  Binary::bytes_get() const
  {
    return bytes_;
  }

} // namespace Ast
