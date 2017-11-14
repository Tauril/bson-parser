#pragma once

#include "ast/db-pointer.hh"

namespace Ast
{

  inline const String&
  DBPointer::str_get() const
  {
    return str_;
  }

  inline const std::array<Byte, 12>&
  DBPointer::bytes_get() const
  {
    return bytes_;
  }

} // namespace Ast
