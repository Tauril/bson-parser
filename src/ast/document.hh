#pragma once

#include "ast/element.hh"
#include "ast/fwd.hh"

namespace Ast
{

  class Document
  {
  public:
    Document() = default;
    Document(Int32 size);

    // Print the content of the document in a human readble form.
    void Dump() const;

    // Add new element to the document.
    template <typename T>
    void add(Node<Element<T>> element);

    // Notably useful for the first Document.
    void size_set(Int32 size);

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
