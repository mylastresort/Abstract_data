#ifndef TYPES_TRAITS_HPP
#define TYPES_TRAITS_HPP

#include "_phc.hpp"

namespace ft
{

template <bool B, class T = void> struct enable_if
{
};

template <class T> struct enable_if<true, T>
{
	typedef T type;
};

using std::numeric_limits;

} // namespace ft

#endif
