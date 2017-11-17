#pragma once

#include <array>

#include "ast/string.hh"
#include "ast/fwd.hh"

namespace Ast
{

  class DBPointer
  {
  public:
    // Construction of a DBPointer node.
    DBPointer(Node<String> str, const Bytes& bytes);

    // Public accessors.
    const String* str_get() const;
    const Bytes& bytes_get() const;

  private:
    Node<String> str_;
    Bytes bytes_;
  };

} // namespace Ast

#include "ast/db-pointer.hxx"
