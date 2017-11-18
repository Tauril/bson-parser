#include "ast/binder.hh"
#include "ast/pretty-printer.hh"

namespace Ast
{

  void
  Binder::Dump() const
  {
    std::cout << this << '\n';
  }

} // namespace Ast
