#pragma once

#include "ast/element.hh"
#include "ast/fwd.hh"

namespace Ast
{

  class Document
  {
  public:
    Document(Int32 size, const EList& elist);

    Int32 size_get() const;
    // Accessor to all the elements inside the document.
    const EList& elist_get() const;
  private:
    // PArsed values.
    Int32 size_;
    EList elist_;
  };

} // namespace Ast

#include "ast/document.hxx"
