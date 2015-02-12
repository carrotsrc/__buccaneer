#include "bflacload.h"
using namespace RackoonIO;
BFlacLoad::BFlacLoad()
{
}

int BFlacLoad::getValue() {
	return value;
}

void BFlacLoad::initExtension() {
	super = 0x23;
}

std::string BFlacLoad::xpsGetFileName() {
	return filename;
}
