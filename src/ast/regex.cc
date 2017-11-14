#include "ast/regex.hh"

namespace Ast
{

  Regex::Regex(const CString& pattern, const CString& options)
    : pattern_(pattern)
    , options_(options)
  {}

} // namespace Ast
