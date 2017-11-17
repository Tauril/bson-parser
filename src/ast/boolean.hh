#pragma once

#include <string>

#include "ast/fwd.hh"

namespace Ast
{

  class Boolean
  {
  public:
    // Construction of a Boolean node.
    Boolean(bool status);

    // Public accessors.
    bool status_get() const;

    std::string bool_str() const;

  private:
    bool status_;
  };

} // namespace Ast

#include "ast/boolean.hxx"
