#pragma once

#define COOKIE_API __declspec(dllexport)

// Options
#define COOKIE_OPT_OPENGL 		(1 << 0)
#define COOKIE_OPT_D3D11		(1 << 1)
#define COOKIE_OPT_FULLSCREEN 	(1 << 2)
#define COOKIE_OPT_RESIZEABLE 	(1 << 3)
#define COOKIE_OPT_CENTERED 	(1 << 4)
#define COOKIE_OPT_HIDDEN  		(1 << 5)
#define COOKIE_OPT_IMGUI 		(1 << 6)

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

		COOKIE_API void info(const char* message, ...);
		COOKIE_API void warn(const char* message, ...);
		COOKIE_API void error(const char* message, ...);
	}
}

// Numeric Types
#include <stdint.h>    // for integer types
#include <stddef.h>    // for size_t type
#include <utility> // for std::move and std::size_t
namespace Cookie
{
	// Numeric Types
	using i8 = int8_t;
	using i16 = int16_t;
	using i32 = int32_t;
	using i64 = int64_t;
	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;
	using f32 = float;
	using f64 = double;
	using size_t = std::size_t;
	using uint = unsigned int;
	using ushort = unsigned short;
}

// Functional
#include <functional>
namespace Cookie
{
	template<class Ret, class...Args> using Func = std::function<Ret(Args...)>;
}

// Initializer list, required for Vector/StackVector
#include <initializer_list>
namespace Cookie
{
	template<typename T> using InitializerList = std::initializer_list<T>;
}

// Ref Counter, for Graphics & Input Resources
#include <memory>
namespace Cookie
{
	template<typename T> using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> create_ref(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}