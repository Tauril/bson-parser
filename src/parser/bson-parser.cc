#include <stdexcept>
#include <unordered_map>

#include "parser/bson-parser.hh"

namespace Parser
{

  BsonParser::BsonParser(const std::vector<char>& buffer)
    : buffer_(buffer)
  {}

  Node<Ast::Document>
  BsonParser::read_document()
  {
    Ast::Int32 size = read_size();

    auto elist = read_elist();

    if (!(i_ == buffer_.size() - 1 && buffer_[i_] == '\x00'))
      throw std::runtime_error("Invalid file format.");

    return std::make_shared<Ast::Document>(size, elist);
  }

  Ast::EList
  BsonParser::read_elist()
  {
    Ast::EList elist;

    while (i_ < buffer_.size() && buffer_[i_] != '\x00')
      elist.emplace_back(read_element());

    return elist;
  }

  template <typename T>
  Node<Ast::Element<T>>
  BsonParser::read_element()
  {
    /*static const std::unordered_map<char, > type_attr =
    {
      {'\x01', }, {'\x02', }, {'\x03', },
      {'\x04', }, {'\x05', }, {'\x06', },
      {'\x07', }, {'\x08', }, {'\x09', },
      {'\x0A', }, {'\x0B', }, {'\x0C', },
      {'\x0D', }, {'\x0E', }, {'\x0F', },
      {'\x10', }, {'\x11', }, {'\x12', },
      {'\x13', }, {'\xFF', }, {'\x7F', }
    };*/

    auto type = buffer_[i_++];

    if (i_ == buffer_.size())
      throw std::runtime_error("Invalid file format.");

    auto ename = read_ename();

    // FIXME: Create element.
  }

  Ast::EName
  BsonParser::read_ename()
  {
    return read_cstring();
  }

  Node<Ast::String>
  BsonParser::read_string()
  {
    Ast::Int32 size = read_size();

    // read size - 1 bytes to eat the '\x00' here for error handling.
    Ast::Bytes bytes = read_sized_bytes(size - 1);

    if (buffer_[i_] != '\x00')
      throw std::runtime_error("Invalid file format.");

    // Eat the '\x00'
    bytes.push_back(buffer_[i_++]);

    return std::make_shared<Ast::String>(size, bytes);
  }

  Ast::CString
  BsonParser::read_cstring()
  {
    Ast::CString cstring;
    while (i_ < buffer_.size() && buffer_[i_] != '\x00')
      cstring.push_back(buffer_[i_++]);

    // i.e. we didn't reach the '\x00'.
    if (i_ == buffer_.size())
      throw std::runtime_error("Invalid file format.");

    // Eat the '\x00'
    cstring.push_back(buffer_[i_++]);

    return cstring;
  }

  Node<Ast::Binary>
  BsonParser::read_binary()
  {
    Ast::Int32 size = read_size();

    static const std::unordered_map<char, Ast::Binary::Subtype> c_subtype =
    {
      {'\x00', Ast::Binary::Subtype::generic},
      {'\x01', Ast::Binary::Subtype::function},
      {'\x02', Ast::Binary::Subtype::binary_d},
      {'\x03', Ast::Binary::Subtype::uuid_d},
      {'\x04', Ast::Binary::Subtype::uuid},
      {'\x05', Ast::Binary::Subtype::md5},
      {'\x80', Ast::Binary::Subtype::user}
    };

    auto subtype_it = c_subtype.find(buffer_[i_++]);
    if (subtype_it == c_subtype.end())
      throw std::runtime_error("Invalid file format.");

    Ast::Binary::Subtype subtype = subtype_it->second;

    Ast::Bytes bytes = read_sized_bytes(size);

    return std::make_shared<Ast::Binary>(size, subtype, bytes);
  }

  Node<Ast::CodeWS>
  BsonParser::read_codews()
  {
    auto size = read_size();
    auto str = read_string();
    auto doc = read_document();

    return std::make_shared<Ast::CodeWS>(size, str, doc);
  }

  Ast::Int32
  BsonParser::read_size()
  {
    Ast::Int32 size = 0;
    size_t j = 0; // Goes up to 4 to only get 4 elements => 4 bytes.
    while (i_ < buffer_.size() && j < 4
           && buffer_[i_] >= '0'
           && buffer_[i_] <= '9')
    {
      size *= 10;
      size += buffer_[i_] - '0';
      i_++;
      j++;
    }

    // I guess it would make more sense to check for invalid
    // format in the calling method.
    // However, putting it here gives so much refactoring that
    // it makes it worth it.
    if (i_ == buffer_.size() || j != 4)
      throw std::runtime_error("Invalid file format.");

    return size;
  }

  Ast::Bytes
  BsonParser::read_sized_bytes(Ast::Int32 size)
  {
    Ast::Bytes bytes;
    bytes.reserve(size);

    while (i_ < buffer_.size() && size >= 0)
    {
      bytes.push_back(buffer_[i_++]);
      size--;
    }

    if (i_ == buffer_.size())
      throw std::runtime_error("Invalid file format.");

    return bytes;
  }

} // naemspace Parser
