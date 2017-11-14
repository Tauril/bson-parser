#include "ast/object-id.hh"

namespace Ast
{

  ObjectId::ObjectId(Int32 secs, Int32 mid, unsigned short pid, Int32 counter)
    : secs_(secs)
    , mid_(mid)
    , pid_(pid)
    , counter_(counter)
  {}

} // namespace Ast
