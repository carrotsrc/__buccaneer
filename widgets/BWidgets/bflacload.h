#ifndef BFLACLOAD_H
#define BFLACLOAD_H
#include "units/RuFlacLoad.h"

class BFlacLoad : public RuFlacLoad
{
protected:
	int super;
public:
	BFlacLoad();
	int getValue();
	void initExtension();

	std::stringxpsGetFileName();
};

#endif // BFLACLOAD_H
