#include <iomanip>

#include "ast/object-id.hh"

namespace Ast
{

  ObjectId::ObjectId(const Bytes& bytes)
  {
    // Pretty ugly way to transform bytes to hex representation.
    // TODO: Find a better way.
    for (auto byte : bytes)
    {
      int byte_int = byte;
      std::ostringstream ss;
      ss << std::setfill('0') << std::setw(2) << std::hex << byte_int;

      // If the decimal representation is negative, we just want to keep
      // the last two chars of the hexa representation, otherwise take the
      // whole things (also two chars).
      auto byte_hex = ss.str();

      if (byte_int < 0)
        bytes_ += byte_hex.substr(byte_hex.size() - 2);
      else
        bytes_ += byte_hex;
    }
  }

} // namespace Ast
