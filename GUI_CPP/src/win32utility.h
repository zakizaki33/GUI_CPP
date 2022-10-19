#ifndef INCLUDE_WIN32UTILITY_H
#define INCLUDE_WIN32UTILITY_H

#include <stdio.h>
#include <windows.h>

namespace win32utl 
{
	/// <summary>標準出力用のコンソールを起動する</summary>
	void  ShowDebugConsole( void );

	/// <summary>標準出力用のコンソールを消す</summary>
	void  HideDebugConsole( void );

	/// <summary>キーイベントメッセージから仮想キーコードを取得する</summary>
	int  GetKeyCode(WPARAM wp, LPARAM lp);

	/// <summary>文字入力イベントメッセージから文字を取得する</summary>
	char GetCharCode(WPARAM wp, LPARAM lp);

	/// <summary>マウスイベントメッセージからマウスの座標を取得する</summary>
	int  GetMouseX(WPARAM wp, LPARAM lp);
	int  GetMouseY(WPARAM wp, LPARAM lp);
}
#endif
