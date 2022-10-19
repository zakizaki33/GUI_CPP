#include <stdio.h>
#include <windows.h>
#include "callback.h"
#include "win32utility.h"
// #include "graphics.h"
#include "mainform.h"

namespace app {
	// 第8回参照
	static void OnPaint(HWND hwnd);
	//static void OnMouse(void);
	static void OnMouse(int x, int y, bool pressed);
	static void OnKey(int key);
}

// static 関数の頭につける　この関数は　callback.cppのみで使う場合に書く
// Headerfileには書かない（お品書きに乗せない。周りから見えなくする）
// 
// <summary>再描画イベントに対するコールバック関数</summary>
static void app::OnPaint( HWND hwnd )
{
	
	// 図形を書く場合はウインドウとは限らない。ほかにプリンターの場合もある。
	HDC hdc_of_wnd = ::GetDC(hwnd);     //Globalの関数。名前関数に存在していないものが相手。 
	                                    // ::無しでもビルドは通る。
	
	mainform::PaintAllItems(hdc_of_wnd);
										
										//	graphics::PaintStandardButton(hdc_of_wnd, 300, 150, 80, 60, true, false);
	//	graphics::PaintStandardButton(hdc_of_wnd, 400, 250, 80, 60, true, true);
	//	graphics::PaintStandardButton(hdc_of_wnd, 100, 200, 80, 60, false, true);

	//{ //変数のコントロール範囲を有効活用させる意外に、中括弧で見やすくする

	//  /* ①ペンやブラシを用意する */
	//	// 引数。ペンの種類、幅、色
	//	HPEN hpen_blue = ::CreatePen(PS_DASHDOT, 1, RGB(0x00, 0x00, 0xff));
	//	HPEN hpen_gray = ::CreatePen(PS_SOLID, 3, RGB(0x66, 0x66, 0x66));
	//	HPEN hpen_red = ::CreatePen(PS_SOLID, 1, RGB(0xff, 0x00, 0x00));
	//	// 引数。塗りつぶしの色
	//	HBRUSH hbrush_sky_blue = ::CreateSolidBrush(RGB(0x00, 0xcc, 0xff));
	//	//HBRUSH hbrush_light_gray = ::CreateSolidBrush(RGB(0xcc, 0xcc, 0xcc));
	//	HBRUSH hbrush_light_gray = ::CreateSolidBrush(RGB(0xee, 0xee, 0xcc));
	//	HBRUSH hbrush_white = ::CreateSolidBrush(RGB(0xff, 0xff, 0xff));


	//	/* ②デバイスコンテキストにペンやブラシを適用する */
	//	/* ③元々のペンやブラシを変数に入れて残しておく   */
	//	// 引数。デバイスコンテキスト、ペン
	//	HPEN   hpen_previous = (HPEN)::SelectObject(hdc_of_wnd, hpen_blue);
	//	HBRUSH hbrush_previous = (HBRUSH)::SelectObject(hdc_of_wnd, hbrush_sky_blue);

	//
	//  
	//  /* 長方形を描く */

	//	::Rectangle(hdc_of_wnd, 10, 10, 120, 25);

	//	::Rectangle(hdc_of_wnd, 20, 75, 220, 150);

	//	/* 角が丸い長方形を描く */
	//	/* 最後二つはxyで半径を指定する */

	//	::SelectObject(hdc_of_wnd, hbrush_light_gray);
	//	::RoundRect(hdc_of_wnd, 10, 200, 150, 350, 45, 45);

	//	::SelectObject(hdc_of_wnd, hpen_gray);
	//	::SelectObject(hdc_of_wnd, hbrush_white);

	//	::RoundRect(hdc_of_wnd, 30, 220, 130, 330, 10, 10);


	//	/* 直線を描く */

	//	::MoveToEx(hdc_of_wnd, 20, 30, NULL); /*スタート設定. 最後は基本はNULL*/

	//	::LineTo(hdc_of_wnd, 200, 250);
	//	::SelectObject(hdc_of_wnd, hpen_red);
	//	::LineTo(hdc_of_wnd, 200, 200);

	//	::LineTo(hdc_of_wnd, 350, 250);

	//	/* 点を描く */

	//	for (int i = 0; i < 100; i++)

	//	{

	//		int x = 400;

	//		int y = 30 + 2 * i;

	//		//::SetPixelV(hdc_of_wnd, x, y, RGB(0xff, 0x00, 0x00));
	//		::SetPixelV(hdc_of_wnd, x, y, RGB(255, 0, 0));

	//		/* RGBでカラーコードしている。ここではdefineマクロ*/

	//	}
	//	/* ④元々のペンやブラシに戻す */

	//	::SelectObject(hdc_of_wnd, hpen_previous);
	//	::SelectObject(hdc_of_wnd, hbrush_previous);


	//	/* ⑤自分で作ったペンやブラシを削除する */

	//	::DeleteObject(hpen_blue);
	//	::DeleteObject(hpen_gray);
	//	::DeleteObject(hpen_red);

	//	::DeleteObject(hbrush_sky_blue);
	//	::DeleteObject(hbrush_light_gray);
	//	::DeleteObject(hbrush_white);
	//}

	// ::ReleaseDC ::は特定の名前空間に属していないことを示す（グローバル的意味）
	::ReleaseDC(hwnd, hdc_of_wnd);  // 返却する

	::ValidateRect(hwnd, NULL);     //画面書き直し


}


/// <summary>マウス入力イベントに対するコールバック関数</summary>
static void app::OnMouse(int x, int y , bool pressed)
{
	// printf( "Hello.\n" );
	printf("X 座標　＝ %d ", x);
	printf("Y 座標　＝ %d \n", y);

	if (pressed==true){
		mainform::PressButtonAt(x,y);
	}
	else {
		mainform::ReleaseButtons();
	}
}


/// <summary>キーボード入力イベントに対するコールバック関数</summary>
static void app::OnKey( int key )
{
	printf("OnKeyが呼ばれました\n");
	printf("%c ( %d )\n",key,key);

	mainform::MoveActiveTextBoxCareTo(4);
}



/// <summary>イベントプロシージャ</summary>
LRESULT CALLBACK app::Procedure( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp )
{	
	// printf("*");  // Procedure関数が呼ばれ続けていることを確認するためのコード
	switch( msg )
	{
		//　ここでは同じグループのメンバー同士なのでつけなくても動く
		case WM_PAINT :
			app::OnPaint(hwnd);
			break;

		case WM_LBUTTONDOWN :
		{   // case 文では変数が生き残るので、スコープをはっきりさせて、変数の有効範囲を決める
			// app::OnMouse();
			// app::OnMouse(
			// 	win32utl::GetMouseX(wp, lp),
			// 	win32utl::GetMouseY(wp, lp)
			// );

			int x = win32utl::GetMouseX(wp, lp);
			int y = win32utl::GetMouseY(wp, lp);
			app::OnMouse(x, y, true);
			break;
		}


		case WM_LBUTTONUP:
		{   
			int x = win32utl::GetMouseX(wp, lp);
			int y = win32utl::GetMouseY(wp, lp);
			app::OnMouse(x, y, false);
			break;
		}
		
		case WM_KEYDOWN :
		{
			// app::OnKey( (int)wp);
			// app::OnKey(win32utl::GetKeyCode(wp, lp));
			int keycode = win32utl::GetKeyCode(wp, lp);
			app::OnKey(keycode);
			break;
		}
		case WM_DESTROY :
			//メンバーに所属していないグローバルを読み出す意味
			::PostQuitMessage( 0 );
			break;
	}

	return DefWindowProc( hwnd, msg, wp, lp );
}
