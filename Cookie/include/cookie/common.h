#pragma once

#define COOKIE_EXPORT __declspec(dllexport)

#define COOKIE_OPT_OPENGL 		(1 << 0)
#define COOKIE_OPT_FULLSCREEN 	(1 << 1)
#define COOKIE_OPT_RESIZEABLE 	(1 << 2)
#define COOKIE_OPT_CENTERED 	(1 << 3)
#define COOKIE_OPT_IMGUI 		(1 << 4)

// Asserts
#if defined(DEBUG) || defined(_DEBUG)
#	include<stdlib.h>
#	define COOKIE_ASSERT(condition, msg) \
	if (!(condition)) { Cookie::Log::error("%s\n\tin %s:%d", (msg), __FILE__, __LINE__); abort(); }
#else
#	define COOKIE_ASSERT(condition, msg) \
	if (!(condition)) { Cookie::Log::error("%s\n\tin %s:%d", (msg), __FILE__, __LINE__); }
#endif

// Logging
namespace Cookie
{
	namespace Log
	{
		enum class Category
		{
			Info,
			Warning,
			Error
		};

		constexpr int max_length = 1024;

		COOKIE_EXPORT void info(const char* message, ...);
		COOKIE_EXPORT void warn(const char* message, ...);
		COOKIE_EXPORT void error(const char* message, ...);
	}
}