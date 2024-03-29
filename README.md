# Common Environment
Includes common directory configurations and test tools

# Install
Download and include ["testmacros.h"](https://github.com/QUOPA/TestTools/blob/main/src/testcommon/testmacros.h) file.

# Terms & Rules
* Test Case
  * A Test Case is a minimal test unit, and written in a function with/without parameter(s)
  * A Test Case MUST be enveloped by namespace representing Test Suite
* Test Suite
  * A Test Suite is a collection of Test Cases, and represented by namespace. 
  * The namespace specifying Test Suite MUST have function named 'TestSuite' with/without parameter(s)
  * The function 'TestSuite' register Test Cases by **REGISTERTESTCASE**(TestCaseFnName, Parameters...) macro.

# Examples
## Writing TestCases
The example on [TestCasesShowSomeWords.h](https://github.com/QUOPA/TestTools/blob/main/src/TestOfTest/TestCasesShowSomeWords.h) shows that all Test Case functions are defined in the namespace of 'showsomewords', which represents a Test Suite
```c++
...
namespace showsomewords
{
	void showAnyString()
	{
		std::cout << "Hello Hello ~" << std::endl;
	}

	void throwexcepttest()
	{
		throw std::exception("thrown for showing");
	}

	void showAnyStringAppend(const std::string & strAppendix)
	{
		std::cout << "Hello Hello ~" << strAppendix << std::endl;
	}

	void showAnyStringPreppend(const std::string& strPrefix)
	{
		std::cout << strPrefix << "Hello Hello ~" << std::endl;
	}
}
```
## Registerring Test Cases to Test Suite
The Test Suite example in [TestSuite.h](https://github.com/QUOPA/TestTools/blob/main/src/TestOfTest/TestSuites.h) shows Test Suites 'showsomewords' and 'binaryOperations' and their registered Test Cases.
```c++
#pragma once
#include "TestCasesBinaryOperations.h"
#include "TestCasesShowSomeWords.h"
#include "testcommon/testmacros.h"

namespace showsomewords 
{void TestSuite(const std::string & strIn)
{
	REGISTERTESTCASE(showAnyString)
	REGISTERTESTCASE(throwexcepttest)
	REGISTERTESTCASE(showAnyStringAppend, strIn)
	REGISTERTESTCASE(showAnyStringPreppend, strIn)
}}

namespace binaryOperations
{void TestSuite(int a, int b)
{
	REGISTERTESTCASE(amulb, a, b)
	REGISTERTESTCASE(aplusb, a, b)
}}
```
## Registerring Test Suite to Running Code
The registration of Test Suites example is in [TestMain.cpp](https://github.com/QUOPA/TestTools/blob/main/src/TestOfTest/TestMain.cpp). Test Suites are registered by REGISTERTESTSUITE([NameSpace],[parameters...]).
```c++
#include "TestSuites.h"
int main()
{
	REGISTERTESTSUITE(showsomewords, "ABCABC")
	REGISTERTESTSUITE(binaryOperations, 3, 4)
  ...
}
```
## Execution Result
The execution result is as follow
```
======== TEST SUITE : showsomewords ========
Param 1: ABCABC

< TEST CASE : showAnyString >
Hello Hello ~
>> Elepsed Time: 256 [us]

< TEST CASE : throwexcepttest >
Exception : thrown for showing
>> Elepsed Time: 1053 [us]

< TEST CASE : showAnyStringAppend >
Hello Hello ~ABCABC
>> Elepsed Time: 270 [us]

< TEST CASE : showAnyStringPreppend >
ABCABCHello Hello ~
>> Elepsed Time: 215 [us]

======== TEST SUITE : binaryOperations ========
Param 1: 3
Param 2: 4

< TEST CASE : amulb >
12
>> Elepsed Time: 152 [us]

< TEST CASE : aplusb >
7
>> Elepsed Time: 149 [us]
```

# Known Error
1. **REGISTERTESTSUITE** cannot be used with std::cout-non-compatible types.
Using std::cout-non-compatible types such as std::wstring, codes do not build.
```c++
...
std::wstring  AA = L"ABCABC"
REGISTERTESTSUITE(showsomewords, AA) // compile error
```
Below code does build and there is no runtime error, but the parameter show is wierd.
```c++
...
REGISTERTESTSUITE(showsomewords, L"ABCABC") // no compile error, no runtime error but parameter list show seems wierd.
```


