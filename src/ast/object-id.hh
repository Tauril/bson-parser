#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  class ObjectId
  {
  public:
    // Construction of an ObjectId node.
    ObjectId(const Bytes& bytes);

    // Public accessors.
    const Bytes& bytes_get() const;

  private:
    Bytes bytes_;
  };

} // namespace Ast

#include "ast/object-id.hxx"
