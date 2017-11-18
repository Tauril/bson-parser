#include "ast/document.hh"

namespace Ast
{

  Document::Document(Int32 size, const EList& elist)
    : size_(size)
    , elist_(elist)
  {}

} // namespace Ast
