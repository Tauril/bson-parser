#include "ast/boolean.hh"

namespace Ast
{

  Boolean::Boolean(bool status)
    : status_(status)
  {}

  std::string
  Boolean::bool_str() const
  {
    if (status_)
      return "true";

    return "false";
  }

} // namespace Ast
