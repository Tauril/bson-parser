#pragma once

#include "ast/element.hh"
#include "ast/fwd.hh"

namespace Ast
{

  class Document
  {
  public:
    Document(Int32 size, const EList& e_list);

    // Print the content of the document in a human readble form.
    void Dump() const;

    Int32 size_get() const;
    // Accessor to all the elements inside the document.
    const EList& e_list_get() const;
  private:
    // PArsed values.
    Int32 size_;
    EList e_list_;
  };

} // namespace Ast

#include "ast/document.hxx"
