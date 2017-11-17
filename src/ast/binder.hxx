#pragma once

#include "ast/binder.hh"

namespace Ast
{

  inline void
  Binder::add(Node<Document> doc)
  {
    docs_.emplace_back(doc);
  }

  inline const Binder::Documents&
  Binder::docs_get() const
  {
    return docs_;
  }

} // namespace Ast
