#pragma once

#include "ast/regex.hh"

namespace Ast
{

  inline const CString&
  Regex::pattern_get() const
  {
    return pattern_;
  }

  inline const CString&
  Regex::options_get() const
  {
    return options_;
  }

} // namespace Ast
