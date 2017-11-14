#pragma once

#include "ast/object-id.hh"

namespace Ast
{

  inline Int32
  ObjectId::secs_get() const
  {
    return secs_;
  }

  inline Int32
  ObjectId::mid_get() const
  {
    return mid_;
  }

  inline unsigned short
  ObjectId::pid_get() const
  {
    return pid_;
  }

  inline Int32
  ObjectId::counter_get() const
  {
    return counter_;
  }

} // namespace Ast
