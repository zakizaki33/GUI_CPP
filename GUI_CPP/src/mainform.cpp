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
#include <iostream>

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
		{ IDC_BTN_XXX, 100, 100, 60, 40, true, false, "File読み込みダイアログ表示" },
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
		bool caret_SW;
	};
	static TEXTBOX_DATA textbox_data_table[] = {
		{ IDC_TXT_AAA, 400,   0, 200,  40, true, true,  "3", 10, true },
		{ IDC_TXT_BBB, 400,  50, 200,  40, true, false, "4", 5, true },
		{ IDC_TXT_CCC, 400, 100, 300, 400, true, false, "lensdata\nlensdata\n", 0, true },
	};

	/*** アプリケーション固有の機能 ***/
	static void FunctionXXX(void);
	static void FunctionYYY(void);
	static void FunctionZZZ(void);
}

/// <summary>全てのGUI部品を描画する</summary>
void  mainform::PaintAllItems( HDC hdc )
{
	// 画面を白く塗りつぶす
	BitBlt(hdc, 0, 0, 1200, 1000, NULL, 0, 0, WHITENESS);
	
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
		::DrawText( hdc, "abc \nABC 1234567890", -1, &text_area, DT_LEFT | DT_WORDBREAK );
		// // １行で表示される（垂直方向の位置揃えの指定はこの場合にのみ有効）
		::DrawText( hdc, "abc \nABC 1234567890", -1, &text_area, DT_LEFT | DT_VCENTER | DT_SINGLELINE );
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
			textbox_data_table[i].caret_position,
			textbox_data_table[i].caret_SW
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

	graphics::PaintStandardTextBox(hdc, 150, 320, 200, 30,"ABCDEFGHIJK" ,true, false, -1, true);

	// mainform内に画像を表示させる
	graphics::PaintBitmapFromFile(hdc, 240, 180, 120, 120, "C:\\Users\\13273_Yamazaki\\source\\repos\\GUI_CPP\\GUI_CPP\\src\\Default.bmp");

	// mainform内に線を表示させる
	graphics::DrawStandardLine(hdc, 200, 400, 200, 50);
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

void mainform::MoveActiveTextBoxCareBy(int position) {

	int selected_textbox_index = -1;
	int textbox_count = 3;

	// 今選択されているテキストボックスを探す
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			textbox_data_table[i].caret_position += position;
			break;
		}
	}
	app::RepaintWindow();
}

/// <summary>カーソルを次のテキストボックスへ移動する</summary>
void  mainform::SelectNextTextBox(void)
{
	int selected_textbox_index = -1;
	int textbox_count = 3;

	// 今選択されているテキストボックスを探す
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			selected_textbox_index = i;
			break;
		}
	}

	// 次に選択するテキストボックスを決める
	selected_textbox_index = (selected_textbox_index + 1) % textbox_count;

	// 各テキストボックスの選択状態を再設定する
	for (int i = 0; i < textbox_count; i++)
	{
		if (i == selected_textbox_index)
		{
			textbox_data_table[i].pressed = true;
		}
		else
		{
			textbox_data_table[i].pressed = false;
		}
	}

	app::RepaintWindow();
}


/// <summary>アプリケーション固有の機能</summary>
void  mainform::FunctionXXX( void )
{
	// printf( "〇〇機能！\n" );
	// fileダイアログを呼び出す関数 23-01-06
	SampleFunction();

	int n1 = atoi(textbox_data_table[0].caption);
	int n2 = atoi(textbox_data_table[1].caption);
	int n3 = atoi(textbox_data_table[2].caption);

	int n = n1 * n2 * n3;
	printf("%d\n", n);

	// samplefunction.h のstr_samplefuncを使ってみる

	std::cout << "str_samplefunc START" << std::endl;
	std::cout << "std::coutが使えない" << std::endl;
	std::cout << str_samplefunc << std::endl;
	std::cout << str_samplefunc.size() << std::endl;
	std::cout << "printfでやってみる" << std::endl;
	printf("%s\n", str_samplefunc.c_str());
	std::cout << "END" << std::endl;

	std::string temp_str = str_samplefunc;
	std::cout << temp_str << std::endl;

	printf("%s\n", buffer2);

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

/// <summary>選択されているテキストボックスへ文字を入力する</summary>
void  mainform::InsertCharacter(char c)
{
	int textbox_count = 3;

	// 今選択されているテキストボックスを探す
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			// キャレットの位置までの文字数
			int position = textbox_data_table[i].caret_position;

			// キャレットの位置を境として左側の部分文字列
			char text1[300];
			strncpy_s(
				text1,										// コピー先
				sizeof(text1),								// コピー先のサイズ（終端文字を含めて何文字までコピーできるか）
				textbox_data_table[i].caption,				// コピー元
				position 									// コピーしたい文字数 ★
			);

			// キャレットの位置を境として右側の部分文字列
			char text2[300];
			strncpy_s(
				text2,										// コピー先
				sizeof(text2),								// コピー先のサイズ（終端文字を含めて何文字までコピーできるか）
				textbox_data_table[i].caption + position,	// コピー元
				_TRUNCATE									// コピーしたい文字数（_TRUNCATEを指定したら残り全部）★
			);

			// 間に文字を追加して上書きする
			sprintf_s(textbox_data_table[i].caption, "%s%c%s", text1, c, text2);

			// キャレットの位置を進める
			textbox_data_table[i].caret_position++;

			break;
		}
	}
	app::RepaintWindow();
}

// 文字削除(BackSpace)
void mainform::BackSpace(void) {

	int textbox_count = 3;

	// 今選択されているテキストボックスを探す
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			// キャレットの位置までの文字数
			int position = textbox_data_table[i].caret_position;
			// 文字数の判断を実施
			if (1 <= position) {
				// キャレットの位置を境として左側の部分文字列
				char text1[300];
				strncpy_s(
					text1,										// コピー先
					sizeof(text1),								// コピー先のサイズ（終端文字を含めて何文字までコピーできるか）
					textbox_data_table[i].caption,				// コピー元
					position - static_cast<unsigned __int64>(1)	// コピーしたい文字数 ★ 1文字減らす
				);

				// キャレットの位置を境として右側の部分文字列
				char text2[300];
				strncpy_s(
					text2,										// コピー先
					sizeof(text2),								// コピー先のサイズ（終端文字を含めて何文字までコピーできるか）
					textbox_data_table[i].caption + position,	// コピー元
					_TRUNCATE									// コピーしたい文字数（_TRUNCATEを指定したら残り全部）★
				);

				// 間に文字を追加して上書きする
				sprintf_s(textbox_data_table[i].caption, "%s%s", text1, text2);

				// キャレットの位置を進める
				textbox_data_table[i].caret_position--; // 変更点2022-12-20
			}
		break;
		}
	}
	app::RepaintWindow();
}

// 文字削除(Delete)
void mainform::Delete(void) {

	int textbox_count = 3;

	// 今選択されているテキストボックスを探す
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			// キャレットの位置までの文字数
			int position = textbox_data_table[i].caret_position;
			// 文字数の判断を実施
			if(position <strlen(textbox_data_table[i].caption))
			{
				// キャレットの位置を境として左側の部分文字列
				char text1[300];
				strncpy_s(
					text1,										// コピー先
					sizeof(text1),								// コピー先のサイズ（終端文字を含めて何文字までコピーできるか）
					textbox_data_table[i].caption,				// コピー元
					position                                 	// コピーしたい文字数
				);

				// キャレットの位置を境として右側の部分文字列
				char text2[300];
				strncpy_s(
					text2,										// コピー先
					sizeof(text2),								// コピー先のサイズ（終端文字を含めて何文字までコピーできるか）
					textbox_data_table[i].caption + position + 1,	// コピー元  ★ 1文字ずれた位置から
					_TRUNCATE									// コピーしたい文字数（_TRUNCATEを指定したら残り全部）★
				);

				// 間に文字を追加して上書きする
				sprintf_s(textbox_data_table[i].caption, "%s%s", text1, text2);

				// キャレットの位置を進める
				// textbox_data_table[i].caret_position; // 変更点2022-12-20
			}
		break;
		}
	}
	app::RepaintWindow();
}