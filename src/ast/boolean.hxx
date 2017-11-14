#pragma once

#include "ast/boolean.hh"

namespace Ast
{

  inline bool
  Boolean::status_get() const
  {
    return status_;
  }

} // namespace Ast
