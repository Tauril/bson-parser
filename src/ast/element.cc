#include "ast/element.hh"

namespace Ast
{

  template <typename T>
  Element<T>::Element(ElementAttribute::Type type, const EName& name, T attr)
    : type_(type)
    , name_(name)
    , attr_(attr)
  {}

} // namespace Ast
