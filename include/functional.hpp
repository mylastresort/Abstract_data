#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

namespace ft
{

template <class T> struct greater
{
	bool operator()(const T& first, const T& second) const
	{
		return first > second;
	}

	template <class U> bool operator()(const T& first, const U& second) const
	{
		return first > second;
	}
};

} // namespace ft

#endif