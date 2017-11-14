#include "bson-parser.hh"

namespace Parser
{

  BsonParser::BsonParser(const std::vector<char>& buffer, node_t doc)
    : buffer_(buffer)
  {
    doc = read_elist();
  }

  node_t
  BsonParser::read_elist()
  {
  }

  node_t
  BsonParser::read_element()
  {
  }

  node_t
  BsonParser::read_ename()
  {
  }

  node_t
  BsonParser::read_string()
  {
  }

  node_t
  BsonParser::read_cstring()
  {
  }

  node_t
  BsonParser::read_binary()
  {
  }

  node_t
  BsonParser::read_subtype()
  {
  }

  node_t
  BsonParser::read_codews()
  {
  }

} // naemspace Parser
