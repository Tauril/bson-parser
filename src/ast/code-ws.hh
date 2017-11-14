#pragma once

#include "ast/document.hh"
#include "ast/string.hh"
#include "ast/fwd.hh"

namespace Ast
{

  class CodeWS
  {
  public:
    // Construction of a CodeWS node.
    CodeWS(Int32 size, const String& str, const Document& doc);

    // Public accessors.
    Int32 size_get() const;
    const String& str_get() const;
    const Document& doc_get() const;

  private:
    Int32 size_;
    String str_;
    Document doc_;
  };

} // namespace Ast

#include "ast/code-ws.hxx"
