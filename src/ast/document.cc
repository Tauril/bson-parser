#include "ast/document.hh"

namespace Ast
{

  Document::Document(Int32 size, const EList& e_list)
    : size_(size)
    , e_list_(e_list)
  {}

  void
  Document::Dump() const
  {
  }

} // namespace Ast
