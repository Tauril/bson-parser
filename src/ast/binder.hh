#pragma once

#include "ast/document.hh"
#include "ast/fwd.hh"

namespace Ast
{

  class Binder
  {
  public:
    using Documents = std::vector<Node<Document>>;
    // Print the content of the document in a human readble form.
    void Dump() const;

    void add(Node<Document> doc);
    const Documents& docs_get() const;
  private:
    // PArsed values.
    Documents docs_;
  };

} // namespace Ast

#include "ast/binder.hxx"
