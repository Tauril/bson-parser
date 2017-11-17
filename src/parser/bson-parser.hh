#pragma once

#include <vector>

#include "ast/binary.hh"
#include "ast/code-ws.hh"
#include "ast/document.hh"
#include "ast/element.hh"
#include "ast/string.hh"
#include "ast/fwd.hh"
#include "ast/types.hh"

namespace Parser
{

  template <typename T>
  using Node = Ast::Node<T>;

  class BsonParser
  {
  public:

    // Parse buffer and store the result inside doc.
    BsonParser(const std::vector<Ast::Byte>& buffer);

    // Main parsing routines.
    Node<Ast::Document> read_document(); // document
  private:
    Ast::EList read_elist(); // e_list (and element)

    // Attribute types for Element.
    Ast::EName read_ename(); // e_name
    Node<Ast::String> read_string(); // string
    Ast::CString read_cstring(); // cstring
    Node<Ast::Binary> read_binary(); // binary
    Node<Ast::CodeWS> read_codews(); // code_w_s

    // Helper parsing routines.
    template <typename Int>
    Int read_size();
    Ast::Bytes read_sized_bytes(Ast::Int32 size);

    std::vector<Ast::Byte> buffer_; // Content of the input file.

    // ith char in the buffer.
    // Manipulated through each read_* method.
    size_t i_;
  };

} // namespace Parser
