#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  class ObjectId
  {
  public:
    // Construction of an ObjectId node.
    // secs: seconds since Unix epoch
    // mid: machine id
    // pid: process id
    // counter: start by a random value
    ObjectId(Int32 secs, Int32 mid, unsigned short pid, Int32 counter);

    // Public accessors.
    Int32 secs_get() const;
    Int32 mid_get() const;
    unsigned short pid_get() const;
    Int32 counter_get() const;

  private:
    Int32 secs_;
    Int32 mid_;
    unsigned short pid_;
    Int32 counter_;
  };

} // namespace Ast

#include "ast/object-id.hxx"
