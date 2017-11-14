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
    DBPointer(const String& str, const std::array<Byte, 12>& bytes);

    // Public accessors.
    const String& str_get() const;
    const std::array<Byte, 12>& bytes_get() const;

  private:
    String str_;
    std::array<Byte, 12> bytes_;
  };

} // namespace Ast

#include "ast/db-pointer.hxx"
