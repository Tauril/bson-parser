#pragma once

#include <memory>
#include <vector>

#include "ast/document.hh"

namespace Parser
{

  class BsonParser
  {
  public:
    using node_t = Ast::node_t;

    // Parse buffer and store the result inside doc.
    BsonParser(const std::vector<char>& buffer, node_t doc);

  private:
    node_t read_elist(); // e_list
    node_t read_element(); // element
    node_t read_ename(); // e_name
    node_t read_string(); // string
    node_t read_cstring(); // cstring
    node_t read_binary(); // binary
    node_t read_subtype(); // subtype
    node_t read_codews(); // code_w_s

    std::vector<char> buffer_;
  };

} // namespace Parser
