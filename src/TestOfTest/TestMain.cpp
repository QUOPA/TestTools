
#include "TestSuites.h"

int main()
{
	REGISTERTESTSUITE(showsomewords, "ABCABC")
	REGISTERTESTSUITE(binaryOperations, 3, 4)


	char Buff[256];
	std::cin.getline(Buff, 256);
	return 0;
}