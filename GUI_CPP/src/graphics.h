/************************************************************

	GUI部品を描画するための関数

************************************************************/


//	1. インクルードガードを書く。
#ifndef INCLUDE_GRAPHICS_H
#define INCLUDE_GRAPHICS_H

#include <Windows.h>

//	2. 関数の宣言を書く。
namespace graphics
{
	void  PaintStandardButton(HDC hdc, int x, int y, int w, int h, bool enabled, bool pressed);
	void  PaintStandardTextBox(HDC hdc, int x, int y, int w, int h, const char* text, bool enabled, bool focused, int caret_pos);

	// 簡単な線を表示する
	void  DrawStandardLine(HDC hdc, int x, int y, int w, int h);

	// ファイルから画像データを読み込んで表示する
	void  PaintBitmapFromFile(HDC hdc, int x, int y, int w, int h, const char* path);
	void  PaintBitmapFromFile(HDC hdc, int x, int y, int w, int h, const wchar_t* path);

	/// <summary>標準的な条件で文字列を描画する</summary>
	void  DrawStandardText(HDC hdc, int x, int y, int w, int h, const char* text);
	void  DrawStandardText(HDC hdc, int x, int y, int w, int h, const wchar_t* text);

	/// <summary>カスタマイズした条件で文字列を描画する</summary>
	void  DrawCustumizedText(HDC hdc, int x, int y, int w, int h, const char* text, int font_height);
	void  DrawCustumizedText(HDC hdc, int x, int y, int w, int h, const wchar_t* text, int font_height);
}
/*
	3. 他のヘッダファイルに依存する場合にはinclude文を書く。
	   ↑今回はHDCを使うので、windows.hをインクルードする必要がある。
*/


#endif

#ifndef INCLUDE_GRAPHICS_H  // インクルードガードされているのでこれ以降はグレーアウトされる（コード無視）
#define INCLUDE_GRAPHICS_H

#include <Windows.h>

//	2. 関数の宣言を書く。
namespace graphics
{
	void  PaintStandardButton(HDC hdc, int x, int y, int w, int h, bool enabled, bool pressed);
}
/*
	3. 他のヘッダファイルに依存する場合にはinclude文を書く。
	   ↑今回はHDCを使うので、windows.hをインクルードする必要がある。
*/


#endif

/*
// 以下同じことの練習
#ifndef ABC //ここではまだ定義せれていないから黒い
#define ABC　//　ここで定義される

#endif

#ifndef ABC　//すでに定義されているから紫（※１に行けない）。よって#endif（※２）にワープ
#define ABC　//　※１

#endif // ※２
*/

