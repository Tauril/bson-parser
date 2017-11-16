#include "ast/code-ws.hh"

namespace Ast
{

  CodeWS::CodeWS(Int32 size, Node<String> str, Node<Document> doc)
    : size_(size)
    , str_(str)
    , doc_(doc)
  {}

} // namespace Ast
