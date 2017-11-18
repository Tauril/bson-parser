#include "ast/binder.hh"
#include "ast/pretty-printer.hh"

namespace Ast
{

  void
  Binder::Dump() const
  {
    // TODO: Put it inside the pretty-printer.
    std::cout << '[';

    size_t size = docs_.size();
    for (size_t i = 0; i < size; i++)
    {
      // Go to the pretty-printer.
      std::cout << docs_[i];

      if (i < size - 1)
        std::cout << ", ";
    }

    std::cout << "]\n";
  }

} // namespace Ast
