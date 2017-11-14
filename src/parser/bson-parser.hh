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

    // Basic types.
    using byte = char; // 1 byte
    using int32 = int32_t; // signed 4 bytes
    using int64 = int64_t; // signed 8 bytes
    using uint64 = uint64_t; // unsigned 8 bytes
    // using double = double; // 8 bytes floating point (for completness)
    using decimal128 = long double; // 16 bytes floating point

    // Parse in and store the result inside doc.
    BsonParser(const std::vector<char>& buffer, node_t& doc);

  private:
    node_t read_elist(const std::ifstream& in); // e_list
    node_t read_element(const std::ifstream& in); // element
    node_t read_ename(const std::ifstream& in); // e_name
    node_t read_string(const std::ifstream& in); // string
    node_t read_cstring(const std::ifstream& in); // cstring
    node_t read_binary(const std::ifstream& in); // binary
    node_t read_subtype(const std::ifstream& in); // subtype
    node_t read_codews(const std::ifstream& in); // code_w_s
  };

} // namespace Parser
