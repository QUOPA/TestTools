#pragma once

#include "TestCasesBinaryOperations.h"
#include "TestCasesShowSomeWords.h"
#include "testcommon/testmacros.h"

namespace showsomewords 
{

void TestSuite(const std::string & strIn)
{
	REGISTERTESTCASE(showAnyString)
	REGISTERTESTCASE(throwexcepttest)
	REGISTERTESTCASE(showAnyStringAppend, strIn)
	REGISTERTESTCASE(showAnyStringPreppend, strIn)

}

}

namespace binaryOperations
{

void TestSuite(int a, int b)
{
	REGISTERTESTCASE(amulb, a, b)
	REGISTERTESTCASE(aplusb, a, b)

}

}



