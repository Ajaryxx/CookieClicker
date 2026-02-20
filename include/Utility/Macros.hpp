#pragma once

#if defined(__DEBUG)
	#define CCLOG(message, ...) std::println(message __VA_OPT__(,) __VA_ARGS__)
#else
	#define CCLOG(message, ...) do { } while(0)
#endif


#define MESSAGE_BOX(window, message, title, style) MessageBoxA(window, message, title, style)

#define CCASSERT(cond, message) assert(cond && message)

#define BASEOF_REQUIRED(Parent, Child, message) static_assert(std::is_base_of<Child, Parent>::value, message)

#define BIND_EVENT_FUNCTION(Class, Func) std::bind(&Class::Func, this, std::placeholders::_1)

#define BIND_CUSTOM_EVENT_FUNCTION(Class, Func) std::bind(&Class::Func, this)

