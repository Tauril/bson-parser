#pragma once

#include "ast/fwd.hh"

namespace Ast
{

  class Binary
  {
  public:
    enum class Subtype
    {
      generic,  // '\x00'
      function, // '\x01'
      binary_d, // '\x02' deprecated
      uuid_d,   // '\x03' deprecated
      uuid,     // '\x04'
      md5,      // '\x05'
      user,     // '\x80'
    };

    // Construction of a Binary node.
    Binary(Int32 size, Binary::Subtype subtype, const Bytes& bytes);

    // Public accessors.
    Int32 size_get() const;
    Binary::Subtype subtype_get() const;
    const Bytes& bytes_get() const;

  private:
    Int32 size_;
    Binary::Subtype subtype_;
    Bytes bytes_;
  };

} // namespace Ast

#include "ast/binary.hxx"
