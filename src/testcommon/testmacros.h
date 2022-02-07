#pragma once

#include <exception>
#include <tuple>
#include <stdarg.h>
#include <string>

#define REGISTERTESTCASE(FN, ...) std::cout << std::endl << "< TEST CASE : " << #FN << " >" << std::endl; \
try { FN(##__VA_ARGS__);  } \
catch (std::exception & e) { std::cout << "Exception : " << e.what() <<std::endl; } \
catch (...) { std::cout << "Exception : Unexpected" << std::endl; }

#define REGISTERTESTSUITE(NS, ...)\
std::cout << std::endl <<  "======== TEST SUITE : " << #NS << " ========" << std::endl; \
__PARAMETEREXPANDER(##__VA_ARGS__);\
NS::TestSuite(##__VA_ARGS__);


template<typename Head, typename... Args>
void __PARAMETEREXPANDER_IMPL(std::size_t N, const Head& head, const Args&... args);

template<typename Head>
void __PARAMETEREXPANDER_IMPL(std::size_t N, const Head& head);

template<typename... Args>
void __PARAMETEREXPANDER(const Args&... args)
{
	const std::size_t N = sizeof...(args);
	__PARAMETEREXPANDER_IMPL(N, args...);
}

template<typename Head>
void __PARAMETEREXPANDER_IMPL(std::size_t N, const Head& head)
{
	std::cout << "Param " << N << ": " << head << std::endl;
}

template<typename Head, typename... Args>
void __PARAMETEREXPANDER_IMPL(std::size_t N, const Head& head, const Args&... args)
{
	const std::size_t M = sizeof...(args);
	std::cout << "Param " << N - M << ": " << head << std::endl;
	__PARAMETEREXPANDER_IMPL(N, args...);
}

