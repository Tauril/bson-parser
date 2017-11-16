#include "ast/db-pointer.hh"

namespace Ast
{

  DBPointer::DBPointer(Node<String> str, const std::array<Byte, 12>& bytes)
    : str_(str)
    , bytes_(bytes)
  {}

} // namespace Ast
