#include <stdexcept>
#include <unordered_map>

#include "parser/bson-parser.hh"

namespace Parser
{

  BsonParser::BsonParser(const std::vector<Ast::Byte>& buffer)
    : buffer_(buffer)
    , i_(0)
  {}

  Node<Ast::Document>
  BsonParser::read_document()
  {
    Ast::Int32 size = read_size<Ast::Int32>();

    auto elist = read_elist();

    if (!(i_ == buffer_.size() - 1 && buffer_[i_] == '\x00'))
      throw std::runtime_error("Invalid file format.");

    return std::make_shared<Ast::Document>(size, elist);
  }

  Ast::EList
  BsonParser::read_elist()
  {
    Ast::EList elist;

    // Holy crap that's ugly!
    // The alternative would be to instantiate some kind of
    // Attribute abstract class all the attributes would
    // derive from and simply call read_element();
    auto add_element =
      [this, &elist](Ast::ElementAttribute::Type type, Ast::EName ename)
      {
        // Indice of the soon-to-be-parsed attribute type.
        auto id = Ast::ElementAttribute::type_val.at(type);

        switch (id)
        {
        case 0:
          {
            using attr_type = Ast::Element<Ast::Types<0>::type>;
            elist.emplace_back(std::make_shared<attr_type>(type, ename, nullptr));
            break;
          }
        case 1:
          {
            using attr_type = Ast::Element<Ast::Types<1>::type>;
            auto attr = read_size<Ast::Types<1>::type>();
            elist.emplace_back(std::make_shared<attr_type>(type, ename, attr));
            break;
          }
        case 2:
          {
            using attr_type = Ast::Element<Ast::Types<2>::type>;
            auto attr = read_size<Ast::Types<2>::type>();
            elist.emplace_back(std::make_shared<attr_type>(type, ename, attr));
            break;
          }
        case 3:
          {
            using attr_type = Ast::Element<Ast::Types<3>::type>;
            auto attr = read_size<Ast::Types<3>::type>();
            elist.emplace_back(std::make_shared<attr_type>(type, ename, attr));
            break;
          }
        case 4:
          {
            using attr_type = Ast::Element<Ast::Types<4>::type>;
            auto attr = read_size<Ast::Types<4>::type>();
            elist.emplace_back(std::make_shared<attr_type>(type, ename, attr));
            break;
          }
        case 5:
          {
            using attr_type = Ast::Element<Ast::Types<5>::type>;
            auto attr = read_size<Ast::Types<5>::type>();
            elist.emplace_back(std::make_shared<attr_type>(type, ename, attr));
            break;
          }
        case 6:
          {
            using attr_type = Ast::Element<Ast::Types<6>::type>;
            auto attr = read_string();
            elist.emplace_back(std::make_shared<attr_type>(type, ename, attr));
            break;
          }
        case 7:
          {
            using attr_type = Ast::Element<Ast::Types<7>::type>;
            auto attr = read_document();
            elist.emplace_back(std::make_shared<attr_type>(type, ename, attr));
            break;
          }
        case 8:
          {
            using attr_type = Ast::Element<Ast::Types<8>::type>;
            auto attr = read_binary();
            elist.emplace_back(std::make_shared<attr_type>(type, ename, attr));
            break;
          }
        /*case 9:
          elist.emplace_back(read_element<Ast::Types<9>::type>(type));
        case 10:
          elist.emplace_back(read_element<Ast::Types<10>::type>(type));
        case 11:
          elist.emplace_back(read_element<Ast::Types<11>::type>(type));
        case 12:
          elist.emplace_back(read_element<Ast::Types<12>::type>(type));
        case 13:
          elist.emplace_back(read_element<Ast::Types<13>::type>(type));*/
          // This can't happen because the value is checked before.
        default:
          throw std::runtime_error("Invalid file format.");
        }

      };

    while (i_ < buffer_.size() && buffer_[i_] != '\x00')
    {
      // Pretty ugly to handle the type and ename of the element inside
      // the read_elist method but this is needed to avoid to have to
      // specialize each method that would read the element.
      auto type_it = Ast::ElementAttribute::type_attr.find(buffer_[i_++]);
      if (type_it == Ast::ElementAttribute::type_attr.end())
        throw std::runtime_error("Invalid file format.");

      auto type = type_it->second;

      if (i_ == buffer_.size())
        throw std::runtime_error("Invalid file format.");

      auto ename = read_ename();

      // Read element's attribute and add the constructed element inside
      // elist.
      add_element(type, ename);
    }

    return elist;
  }

  Ast::EName
  BsonParser::read_ename()
  {
    return read_cstring();
  }

  Node<Ast::String>
  BsonParser::read_string()
  {
    auto size = read_size<Ast::Int32>();

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
    auto size = read_size<Ast::Int32>();

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
    auto size = read_size<Ast::Int32>();
    auto str = read_string();
    auto doc = read_document();

    return std::make_shared<Ast::CodeWS>(size, str, doc);
  }

  template <typename Int>
  Int
  BsonParser::read_size()
  {
    Int size = 0;
    size_t j = 0; // Goes up to sizeof(Int) to only get sizeof(Int) bytes.
    while (i_ < buffer_.size() && j < sizeof(Int)
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
