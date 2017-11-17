#pragma once

#include "ast/object-id.hh"

namespace Ast
{

  inline const Bytes&
  ObjectId::bytes_get() const
  {
    return bytes_;
  }

} // namespace Ast
