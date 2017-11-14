#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  class String
  {
  public:
    // Construction of a String node.
    String(Int32 size, const Bytes& bytes);

    // Public accessors.
    Int32 size_get() const;
    const Bytes& bytes_get() const;

  private:
    Int32 size_;
    Bytes bytes_;
  };

} // namespace Ast

#include "ast/string.hxx"
