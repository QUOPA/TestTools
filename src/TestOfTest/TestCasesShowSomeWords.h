#pragma once

#include <iostream>

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