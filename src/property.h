/*
Pour 'facilement' créer des property

Usage :

#include "property.h"

class Calc
{
public:

  float x;

	READONLY_PROPERTY(float, x2);
	GET(x2)
	{
		return x*x;
	}
};

int main()
{
	Calc calc;
	calc.x = 42;
	std::cout << "x2 = " << calc.x2;
	return 0;
}

*/

#ifndef _PROPERTIES_H
#define _PROPERTIES_H

#define PROPERTY(t,n)  __declspec( property
	( put = property__set_##n, get = property__get_##n ) ) t n;\
	typedef t property__tmp_type_##n
#define READONLY_PROPERTY(t,n) __declspec( property (get = property__get_##n) ) t n;\
	typedef t property__tmp_type_##n
#define WRITEONLY_PROPERTY(t,n) __declspec( property (put = property__set_##n) ) t n;\
	typedef t property__tmp_type_##n

#define GET(n) property__tmp_type_##n property__get_##n()
#define SET(n) void property__set_##n(const property__tmp_type_##n& value)

#endif /* _PROPERTIES_H */ 
