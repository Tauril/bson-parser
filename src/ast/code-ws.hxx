#pragma once

#include "ast/code-ws.hh"

namespace Ast
{

  inline Int32
  CodeWS::size_get() const
  {
    return size_;
  }

  inline const String&
  CodeWS::str_get() const
  {
    return str_;
  }

  inline const Document&
  CodeWS::doc_get() const
  {
    return doc_;
  }

} // namespace Ast
