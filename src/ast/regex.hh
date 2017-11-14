#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  class Regex
  {
  public:
    // Construction of a Regex node.
    Regex(const CString& pattern, const CString& options);

    // Public accessors.
    const CString& pattern_get() const;
    const CString& options_get() const;

  private:
    CString pattern_;
    CString options_;
  };

} // namespace Ast

#include "ast/regex.hxx"
