#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  class Document
  {
  public:
    Document() = default;
    Document(Int32 size);
    void Dump() const;

    // Add new element to the document.
    void add(Node<Element> element);

    // Notably useful for the first Document.
    void size_set(Int32 size);

    // Accessor to all the elements inside the document.
    EList e_list_get() const;
  private:
    // PArsed values.
    EList e_list_;
  };

} // namespace Ast

#include "ast/document.hxx"
