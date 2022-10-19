#include <stdio.h>
#include <windows.h>
#include "win32utility.h"
#include <windowsx.h>


/// <summary>標準出力用のコンソールを起動する</summary>
void  win32utl::ShowDebugConsole( void )
{
	if( AllocConsole() )
	{
		FILE *fp;
		freopen_s( &fp, "CONOUT$", "w", stdout );
	}
}

/// <summary>標準出力用のコンソールを消す</summary>
void  win32utl::HideDebugConsole( void )
{
	FreeConsole();
}


/// <summary>キーイベントメッセージからキーコードを取得する</summary>
int  win32utl::GetKeyCode(WPARAM wp, LPARAM lp)
{
	return (int)wp;
}

/// <summary>文字入力イベントメッセージから文字を取得する</summary>
char  win32utl::GetCharCode(WPARAM wp, LPARAM lp)
{
	return (char)wp;
}

/// <summary>マウスイベントメッセージからマウスの座標を取得する</summary>
int  win32utl::GetMouseX(WPARAM wp, LPARAM lp)
{
	return GET_X_LPARAM(lp);
}

/// <summary>マウスイベントメッセージからマウスの座標を取得する</summary>
int  win32utl::GetMouseY(WPARAM wp, LPARAM lp)
{
	return GET_Y_LPARAM(lp);
}

