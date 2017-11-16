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
    DBPointer(Node<String> str, const std::array<Byte, 12>& bytes);

    // Public accessors.
    const String* str_get() const;
    const std::array<Byte, 12>& bytes_get() const;

  private:
    Node<String> str_;
    std::array<Byte, 12> bytes_;
  };

} // namespace Ast

#include "ast/db-pointer.hxx"
