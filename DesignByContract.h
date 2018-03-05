
#ifndef PROJECTSE_DESIGNBYCONTRACT_H
#define PROJECTSE_DESIGNBYCONTRACT_H

#include <cassert>

#define REQUIRE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__);

#define ENSURE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__);


#endif //PROJECTSE_DESIGNBYCONTRACT_H
