#include "ast/string.hh"

namespace Ast
{

  String::String(Int32 size, const Bytes& bytes)
    : size_(size)
    , bytes_(bytes)
  {}

} // namespace Ast
