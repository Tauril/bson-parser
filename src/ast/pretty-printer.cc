#include "ast/binary.hh"
#include "ast/boolean.hh"
#include "ast/code-ws.hh"
#include "ast/db-pointer.hh"
#include "ast/document.hh"
#include "ast/element.hh"
#include "ast/string.hh"
#include "ast/object-id.hh"
#include "ast/regex.hh"

#include "ast/pretty-printer.hh"

namespace Ast
{

  std::ostream& operator<<(std::ostream& ostr, const Document* doc)
  {
    ostr << '{';

    size_t size = doc->elist_get().size();
    for (size_t i = 0; i < size; i++)
    {
      ostr << doc->elist_get()[i];

      if (i < size - 1)
        std::cout << ", ";
    }

    ostr << '}';

    return ostr;
  }

  template <typename T>
  std::ostream& operator<<(std::ostream& ostr, const Element<T>* elt)
  {
    return ostr << '"' << elt->name_get() << '"' << ": " << elt->attr_get();
  }

  std::ostream& operator<<(std::ostream& ostr, Binary* bin)
  {
    return ostr << '"' << bin->bytes_get() << '"';
  }

  std::ostream& operator<<(std::ostream& ostr, const Boolean* status)
  {
    return ostr << status->bool_str();
  }
  /*std::ostream& operator<<(std::ostream& ostr, CodeWS* str)
  std::ostream& operator<<(std::ostream& ostr, DBPointer* str)*/
  std::ostream& operator<<(std::ostream& ostr, const ObjectId* obj)
  {
    return ostr << "ObjectId(\"" << obj->bytes_get() << "\")";
  }
  /*std::ostream& operator<<(std::ostream& ostr, Regex* str)*/

  std::ostream& operator<<(std::ostream& ostr, const String* str)
  {
    return ostr << '"' << str->bytes_get() << '"';
  }

  template <typename T>
  std::enable_if_t<std::is_null_pointer<T>::value, std::ostream&>
  operator<<(std::ostream& ostr, T)
  {
    return ostr;
  }

} // namespace Ast
