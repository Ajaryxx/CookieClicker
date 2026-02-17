#pragma once

#if defined(__DEBUG)
	#define CCLOG(message, ...) std::println(message __VA_OPT__(,) __VA_ARGS__)
#else
	#define CCLOG(message, ...) do { } while(0)
#endif

#if defined(_WIN32) && defined(__DEBUG)
	#define ShowMBox(window, message, caption, utype) ShowMessageBox(window, message, caption, utype)

#else
	//Linux dummy macro
	#define ShowMBox(window, message, caption, utype) do { } while(0)

#endif

#if defined(_WIN32)
//WINDOWS ONLY
//returns the result which button was pressed
inline int ShowMessageBox(HWND window, LPCSTR message, LPCSTR caption, UINT utype)
{
	return MessageBoxA(window, message, caption, utype);
}
#endif


#define CCASSERT(cond, message) assert(cond && message)

#define BASEOF_REQUIRED(Parent, Child, message) static_assert(std::is_base_of<Child, Parent>::value, message)

#define BIND_EVENT_FUNCTION(Class, Func) std::bind(&Class::Func, this, std::placeholders::_1)

#define BIND_CUSTOM_EVENT_FUNCTION(Class, Func) std::bind(&Class::Func, this)

