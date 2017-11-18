#pragma once

#include "ast/date.hh"

namespace Ast
{

  inline Double
  Date::date_get() const
  {
    return date_;
  }

} // namespace Ast
