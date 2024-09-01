#ifndef MAIN_HPP
#define MAIN_HPP

#ifdef STD
namespace __lib__ = std;
#else
#define FT
namespace ft
{
};
namespace __lib__ = ft;
#endif

void unit_test_vector_constructor();

#endif