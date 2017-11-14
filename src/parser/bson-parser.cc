#include "bson-parser.hh"

namespace Parser
{

  BsonParser::BsonParser(const std::string& in, node_t& doc)
  {
    doc = read_EList(in);

    in.close();
  }

  node_t
  BsonParser::read_elist(const std::ifstream& in)
  {
  }

  node_t
  BsonParser::read_element(const std::ifstream& in)
  {
  }

  node_t
  BsonParser::read_ename(const std::ifstream& in)
  {
  }

  node_t
  BsonParser::read_string(const std::ifstream& in)
  {
  }

  node_t
  BsonParser::read_cstring(const std::ifstream& in)
  {
  }

  node_t
  BsonParser::read_binary(const std::ifstream& in)
  {
  }

  node_t
  BsonParser::read_subtype(const std::ifstream& in)
  {
  }

  node_t
  BsonParser::read_codews(const std::ifstream& in)
  {
  }

} // naemspace Parser
