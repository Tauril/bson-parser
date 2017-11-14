#pragma once

#include "ast/string.hh"

namespace Ast
{

  inline Int32
  String::size_get() const
  {
    return size_;
  }

  inline const Bytes&
  String::bytes_get() const
  {
    return bytes_;
  }

} // namespace Ast
