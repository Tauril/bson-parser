#include "ast/code-ws.hh"

namespace Ast
{

  CodeWS::CodeWS(Int32 size, const String& str, const Document& doc)
    : size_(size)
    , str_(str)
    , doc_(doc)
  {}

} // namespace Ast
