#pragma once

#if defined(__DEBUG)
	#define CCLOG(message, ...) std::println(message __VA_OPT__(,) __VA_ARGS__)
#else
	#define CCLOG(message, ...) do { } while(0)
#endif

#if defined(_WIN32) && defined(__DEBUG)
	#define ShowMBox(window, message, caption, utype) ShowMessageBox(window, message, caption, utype)

#else
	//Linux
	#define ShowMBox(window, message, caption, utype) do { } while(0)

#endif


#if defined(_WIN32)
//WINDOWS ONLY
//returns the result which button was pressed
inline int ShowMessageBox(HWND window, LPCWSTR message, LPCWSTR caption, UINT utype)
{
	return MessageBoxW(window, message, caption, utype);
}
#endif