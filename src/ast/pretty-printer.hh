#pragma once

#include <type_traits>

#include "ast/fwd.hh"

namespace Ast
{

  std::ostream& operator<<(std::ostream& ostr, const Document* doc);

  template <typename T>
  std::ostream& operator<<(std::ostream& ostr, const Element<T>* elt);

/*  std::ostream& operator<<(std::ostream& ostr, const Binary* str);*/
  std::ostream& operator<<(std::ostream& ostr, const Boolean* status);
  /*std::ostream& operator<<(std::ostream& ostr, const CodeWS* str);
  std::ostream& operator<<(std::ostream& ostr, const DBPointer* str);*/
  std::ostream& operator<<(std::ostream& ostr, const ObjectId* obj);
/*  std::ostream& operator<<(std::ostream& ostr, const Regex* str);*/
  std::ostream& operator<<(std::ostream& ostr, const String* str);

  template <typename T>
  std::enable_if_t<std::is_null_pointer<T>::value, std::ostream&>
  operator<<(std::ostream& ostr, T);

} // namespace Ast
