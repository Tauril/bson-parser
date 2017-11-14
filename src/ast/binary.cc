#include "ast/binary.hh"

namespace Ast
{

  Binary::Binary(Int32 size, Binary::Subtype subtype, const Bytes& bytes)
    : size_(size)
    , subtype_(subtype)
    , bytes_(bytes)
  {}

} // namespace Ast
