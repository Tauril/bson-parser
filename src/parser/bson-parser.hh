#pragma once

#include <vector>

#include "ast/binary.hh"
#include "ast/binder.hh"
#include "ast/boolean.hh"
#include "ast/code-ws.hh"
#include "ast/db-pointer.hh"
#include "ast/document.hh"
#include "ast/element.hh"
#include "ast/string.hh"
#include "ast/fwd.hh"
#include "ast/object-id.hh"
#include "ast/regex.hh"
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

    // Main parsing routine.
    Node<Ast::Binder> read();
  private:
    Node<Ast::Document> read_document(); // document
    Ast::EList read_elist(); // e_list (and element)
    Ast::EName read_ename(); // e_name

    // Attribute types for Element.
    Node<Ast::String> read_string(); // string
    Ast::CString read_cstring(); // cstring
    Node<Ast::Binary> read_binary(); // binary
    Node<Ast::CodeWS> read_codews(); // code_w_s
    Node<Ast::ObjectId> read_objectid(); // object_id
    Node<Ast::Boolean> read_boolean(); // boolean
    Node<Ast::Regex> read_regex(); // regex
    Node<Ast::DBPointer> read_dbpointer(); // db_pointer

    // Helper parsing routines.
    template <typename Int>
    Int read_size();
    Ast::Double read_size();
    Ast::Bytes read_fixed_bytes(Ast::Int32 size);

    std::vector<Ast::Byte> buffer_; // Content of the input file.

    // ith char in the buffer.
    // Manipulated through each read_* method.
    size_t i_;
  };

} // namespace Parser
