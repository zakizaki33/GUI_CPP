#ifndef INCLUDE_APPMAIN_H // ここから
#define INCLUDE_APPMAIN_H

#include <Windows.h>

namespace app
{
	/// <summary>ウィンドウのハンドルを取得する</summary>
	HWND  GetWindowHandle( void );

	/// <summary>ウィンドウを再描画する</summary>
	void  RepaintWindow( void );
}

#endif