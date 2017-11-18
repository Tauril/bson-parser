#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  class Date
  {
  public:
    // Construction of a Date node.
    Date(Double date);

    // Public accessors.
    Double date_get() const;

  private:
    Double date_;
  };

} // namespace Ast

#include "ast/date.hxx"
