#include <iomanip>

#include "ast/binder.hh"
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

  namespace
  {

    inline long int& indent(std::ostream& ostr)
    {
      static const long int indent_index = std::ios::xalloc();
      return ostr.iword(indent_index);
    }

    // End of line -> set indentation
    std::ostream& iendl(std::ostream& ostr)
    {
      ostr << std::endl;
      char fill = ostr.fill(' ');
      return ostr << std::setw(indent(ostr))
                  << ""
                  << std::setfill(fill);
    }

    std::ostream& incendl(std::ostream& ostr)
    {
      indent(ostr) += 2;
      return ostr << iendl;
    }

    std::ostream& decendl(std::ostream& ostr)
    {
      indent(ostr) -= 2;
      return ostr << iendl;
    }

    // Ugly global variable for the Array type that is identical to a Document.
    // Since we can't overload operator<< with more than 2 parameters, and
    // I don't want to create a duplicate class to Document that would
    // represent the Array, I have not found a better way to do that..
    bool is_array = false;

  }

  std::ostream& operator<<(std::ostream& ostr, const Binder* binder)
  {
    ostr << '[' << incendl;

    size_t size = binder->docs_get().size();
    for (size_t i = 0; i < size; i++)
    {
      ostr << binder->docs_get()[i];

      if (i < size - 1)
        ostr << ',' << iendl;
    }

    return ostr << decendl << ']';
  }

  // Factorize with Binder's method?
  // Wouldn't this make it less clear and thus
  // not worth it?
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
