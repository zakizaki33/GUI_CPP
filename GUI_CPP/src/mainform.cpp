/************************************************************

	メイン画面を操作するための関数

************************************************************/
#include <stdio.h>
#include "appmain.h"
#include "mainform.h"
#include "graphics.h"
#include <string.h>
#include <windows.h>
#include "samplefunction.h"

namespace mainform
{
	/*** GUIの構成部品 ***/

	/// <summary>GUI部品の識別ID</summary>
	enum ID_CONTROL
	{
		IDC_BTN_XXX,
		IDC_BTN_YYY,
		IDC_BTN_ZZZ,

		IDC_TXT_AAA,
		IDC_TXT_BBB,
		IDC_TXT_CCC,
	};

	/// <summary>ボタンのデータ</summary>
	struct BUTTON_DATA
	{
		ID_CONTROL id;
		int x;
		int y;
		int w;
		int h;
		bool enabled;
		bool pressed;
		char caption[100]; //終端文字含めて100文字
	};
	static BUTTON_DATA button_data_table[] = {
		{ IDC_BTN_XXX, 100, 100, 60, 40, true, false, "Func あ" },
		{ IDC_BTN_YYY, 200, 100, 60, 40, true, false, "Func い" },
		{ IDC_BTN_ZZZ, 300, 100, 60, 40, true, false, "Func う" },
	};

	/// <summary>テキストボックスのデータ</summary>
	struct TEXTBOX_DATA
	{
		ID_CONTROL id;
		int x;
		int y;
		int w;
		int h;
		bool enabled;
		bool pressed;
		char caption[100];
		int caret_position;
	};
	static TEXTBOX_DATA textbox_data_table[] = {
		{ IDC_TXT_AAA, 500, 200, 200, 40, true, true,  "12345_22-10-04", 10 },
		{ IDC_TXT_BBB, 500, 250, 200, 40, true, false, "abcde_22-10-04", 5 },
		{ IDC_TXT_CCC, 500, 300, 200, 40, true, false, "あいうえお_22-10-04", 0 },
	};

	/*** アプリケーション固有の機能 ***/

	static void FunctionXXX( void );
	static void FunctionYYY( void );
	static void FunctionZZZ( void );
}


/// <summary>全てのGUI部品を描画する</summary>
void  mainform::PaintAllItems( HDC hdc )
{
	// 画面を白く塗りつぶす
	BitBlt(hdc, 0, 0, 800, 600, NULL, 0, 0, WHITENESS);
	
	for( int i = 0; i < 3; i++ )
	{
		graphics::PaintStandardButton(
			hdc,
			button_data_table[i].x,
			button_data_table[i].y,
			button_data_table[i].w,
			button_data_table[i].h,
			button_data_table[i].enabled,
			button_data_table[i].pressed
		);
		
		graphics::DrawStandardText(
			hdc,
			button_data_table[i].x,
			button_data_table[i].y,
			button_data_table[i].w,
			button_data_table[i].h,
			// "漢字フォントabc \nABC 1234567890"
			button_data_table[i].caption
		);

/*
		int padding = 3;
		RECT text_area = {
			button_data_table[i].x + padding,
			button_data_table[i].y + padding,
			button_data_table[i].x + button_data_table[i].w - padding,
			button_data_table[i].y + button_data_table[i].h - padding
		};

		// 改行文字"\n"のところで改行される
		::DrawText(hdc, "abc \nABC 1234567890", -1, &text_area, DT_LEFT);

		// // 幅に合わせて自動的に改行される
		// ::DrawText( hdc, "abc \nABC 1234567890", -1, &text_area, DT_LEFT | DT_WORDBREAK );

		// // １行で表示される（垂直方向の位置揃えの指定はこの場合にのみ有効）
		// ::DrawText( hdc, "abc \nABC 1234567890", -1, &text_area, DT_LEFT | DT_VCENTER | DT_SINGLELINE );
*/
	}

	for (int i = 0; i < 3; i++)
	{
		graphics::PaintStandardTextBox(
			hdc,
			textbox_data_table[i].x,
			textbox_data_table[i].y,
			textbox_data_table[i].w,
			textbox_data_table[i].h,
			textbox_data_table[i].caption,
			textbox_data_table[i].enabled,
			textbox_data_table[i].pressed,
			textbox_data_table[i].caret_position
		);
	}
	char text_x[20];
	char text_y[20];
	char text_ave[20];

	sprintf_s(text_x, "      x : %d", GetCurrentX());
	sprintf_s(text_y, "      y : %d", GetCurrentY());
	sprintf_s(text_ave, "average : %d", GetCurrentAverage());

	graphics::DrawStandardText(hdc, 100, 200, 200, 40, text_x);
	graphics::DrawStandardText(hdc, 100, 240, 200, 40, text_y);
	graphics::DrawStandardText(hdc, 100, 280, 200, 40, text_ave);

	graphics::PaintStandardTextBox(hdc, 150, 320, 200, 30,"ABCDEFGHIJK" ,true, false, -1);


	// mainform内に画像を表示させる
	graphics::PaintBitmapFromFile(hdc, 240, 180, 120, 120, "C:\\Users\\13273_Yamazaki\\source\\repos\\GUI_CPP\\GUI_CPP\\src\\Default.bmp");

	// mainform内に線を表示させる
	graphics::DrawStandardLine(hdc, 10, 10, 100, 100);
}


/// <summary>指定位置のボタンを押す</summary>
/// <remarks>状態変化時の再描画とボタンが押されることによる機能の実行を含む</remarks>
void  mainform::PressButtonAt( int x, int y )
{
	for( int i = 0; i < 3; i++ )
	{
		if( x < button_data_table[i].x ){ continue; }
		if( y < button_data_table[i].y ){ continue; }
		if( button_data_table[i].x + button_data_table[i].w <= x ){ continue; }
		if( button_data_table[i].y + button_data_table[i].h <= y ){ continue; }

		// ボタンがOFFからONに変わったら……
		if( button_data_table[i].pressed == false )
		{
			button_data_table[i].pressed = true;

			app::RepaintWindow();

			switch( button_data_table[i].id )
			{
				case IDC_BTN_XXX : mainform::FunctionXXX(); break;
				case IDC_BTN_YYY : mainform::FunctionYYY(); break;
				case IDC_BTN_ZZZ : mainform::FunctionZZZ(); break;
				default : break;
			}
		}

		// 同時に複数のボタンが押されるのはおかしいので
		// １つでも該当するボタンが見つかって処理をした後はループを抜ける
		break;
	}
}


/// <summary>全てのボタンを押されていない状態に戻す</summary>
void  mainform::ReleaseButtons( void )
{
	bool  need_repaint = false;

	for( int i = 0; i < 3; i++ )
	{
		if( button_data_table[i].pressed == true )
		{
			button_data_table[i].pressed = false;
			need_repaint = true;
		}
	}

	if( need_repaint == true )
	{

		app::RepaintWindow();
	}
}

void mainform::MoveActiveTextBoxCareTo(int position){

	textbox_data_table[0].caret_position = position;

	app::RepaintWindow();

}


/// <summary>アプリケーション固有の機能</summary>
void  mainform::FunctionXXX( void )
{
	// printf( "〇〇機能！\n" );
	SampleFunction();
}

/// <summary>アプリケーション固有の機能</summary>
void  mainform::FunctionYYY( void )
{
	printf( "××機能！\n" );
}

/// <summary>アプリケーション固有の機能</summary>
void  mainform::FunctionZZZ( void )
{
	printf( "▲▲機能！\n" );
}
