#ifndef WINDOW_H
#define	WINDOW_H
#include <Windows.h>
class Window
{
public:
	Window(HINSTANCE instance,const char* windowName,int width,int height);
	~Window(void);
	static HWND handle;
	
	static HGLRC OGLcontext;
	static HDC hdc;
	static LRESULT CALLBACK wEventsProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam);

	
};


#endif