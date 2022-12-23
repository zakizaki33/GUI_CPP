/************************************************************

	GUI部品を描画するための関数

************************************************************/
#include <windows.h>
#include "graphics.h"

/// <summary>標準的なボタンを描画する</summary>
/// <param name="hdc">描画対象のDC</param>
/// <param name="x">左上端のX座標</param>
/// <param name="y">左上端のY座標</param>
/// <param name="w">幅</param>
/// <param name="h">高さ</param>
/// <param name="enabled">trueなら押せる/falseなら押せない</param>
/// <param name="pressed">trueなら押されている/falseなら押されていない</param>
void  graphics::PaintStandardButton( HDC hdc, int x, int y, int w, int h, bool enabled, bool pressed )
{
	/* ペンやブラシを用意する */

 	HPEN hpen_normal    = ::CreatePen( PS_SOLID, 1, RGB(0x00,0x00,0x00) ); 
 	HPEN hpen_pressed   = ::CreatePen( PS_SOLID, 1, RGB(0x00,0x00,0x00) ); 
	HPEN hpen_disabled  = ::CreatePen( PS_SOLID, 1, RGB(0x66,0x66,0x66) ); 

	HBRUSH hbrush_normal    = ::CreateSolidBrush( RGB(0xff,0xff,0xff) );
	HBRUSH hbrush_pressed   = ::CreateSolidBrush( RGB(0xff,0xcc,0x00) );
	HBRUSH hbrush_disablede = ::CreateSolidBrush( RGB(0x99,0x99,0x99) );


	/* 元々のペンやブラシを変数に入れて残しておく */

	HPEN   hpen_previous   = (HPEN  )::SelectObject( hdc, hpen_normal ); 
	HBRUSH hbrush_previous = (HBRUSH)::SelectObject( hdc, hbrush_normal );


	/* 条件に合わせてボタンの絵を描く */

	if( enabled == false )
	{
		::SelectObject( hdc, hpen_disabled );
		::SelectObject( hdc, hbrush_disablede );

		::Rectangle( hdc, x, y, x + w, y + h );
	}
	else if( pressed == true )
	{
		::SelectObject( hdc, hpen_pressed );
		::SelectObject( hdc, hbrush_pressed );

		::Rectangle( hdc, x, y, x + w, y + h );
	}
	else
	{
		::Rectangle( hdc, x, y, x + w, y + h );
	}


	/* 元々のペンやブラシに戻す */

	::SelectObject( hdc, hpen_previous );
	::SelectObject( hdc, hbrush_previous );


	/* 自分で作ったペンやブラシを削除する */

	::DeleteObject( hpen_normal );
	::DeleteObject( hpen_pressed );
	::DeleteObject( hpen_disabled );
	::DeleteObject( hbrush_normal );
	::DeleteObject( hbrush_pressed );
	::DeleteObject( hbrush_disablede );
}

void  graphics::PaintStandardTextBox(HDC hdc, int x, int y, int w, int h, const char* textbool, bool enabled, bool focused, int caret_pos)
{
	/* ペンやブラシを用意する */
	HPEN hpen_normal = ::CreatePen(PS_SOLID, 1, RGB(0x00, 0xff, 0x00));
	HPEN hpen_pressed = ::CreatePen(PS_DASHDOT, 1, RGB(0x00, 0x00, 0x00));
	HPEN hpen_disabled = ::CreatePen(PS_DASHDOT, 1, RGB(0x66, 0x66, 0x66));
	HBRUSH hbrush_normal = ::CreateSolidBrush(RGB(0xff, 0xff, 0xff));
	HBRUSH hbrush_pressed = ::CreateSolidBrush(RGB(0xff, 0xcc, 0x00));
	HBRUSH hbrush_disablede = ::CreateSolidBrush(RGB(0x99, 0x99, 0x99));

	/* 元々のペンやブラシを変数に入れて残しておく */
	HPEN   hpen_previous = (HPEN)::SelectObject(hdc, hpen_normal);
	HBRUSH hbrush_previous = (HBRUSH)::SelectObject(hdc, hbrush_normal);

	/* 条件に合わせてボタンの絵を描く */
	if (enabled == false)
	{
		::SelectObject(hdc, hpen_disabled);
		::SelectObject(hdc, hbrush_disablede);

		::Rectangle(hdc, x, y, x + w, y + h);
	}
	else if (focused == true)
	{
		::SelectObject(hdc, hpen_pressed);
		::SelectObject(hdc, hbrush_pressed);

		::Rectangle(hdc, x, y, x + w, y + h);
	}
	else
	{
		::Rectangle(hdc, x, y, x + w, y + h);
	}

	int font_width = 12;
	int font_height=font_width*2 ;

	// 代入するものがtextboolで合っている？
	DrawCustumizedText(hdc, x, y , w ,h,textbool,font_height);

	// この下でキャレットを描画する作業をする ★☆★
	::SelectObject(hdc, ::CreatePen(PS_SOLID, 1, RGB(0xff, 0xff, 0x00))); //色変更
	{
		RECT rc = { 0,0,0,0 };
		// DrawTextAにフォントの情報を渡す
		// MSゴシックの設定を再度指示する
		// TODO 44回目、47回目あたり復習

		/* フォントデータを用意する */
		HFONT hfont_normal = ::CreateFont(
			font_height,					// 文字の高さ[論理単位]
			0,					// 文字の幅（0を指定すると文字の高さを基準にして自動決定される）
			0,					// 文字送り方向とX軸の角度[0.1°単位]
			0,					// ベースラインとX軸の角度[0.1°単位]
			FW_NORMAL,				// 線の太さ
			0,					// 0:標準 / 1:斜体
			0,					// 0:標準 / 1:下線付き
			0,					// 0:標準 / 1:打ち消し線付き
			DEFAULT_CHARSET,			// 文字セット
			OUT_DEFAULT_PRECIS,			// 出力精度
			CLIP_DEFAULT_PRECIS,			// クリッピング精度
			DEFAULT_QUALITY,			// 出力品質
			DEFAULT_PITCH | FF_DONTCARE,	// ピッチとフォントファミリ
			"ＭＳ ゴシック"			// フォント名
			//"ＨＧＰ創英角ﾎﾟｯﾌﾟ体"
		);

		HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);

		/* 色を変える */
		COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));

		/* 文字を描くとき背景部分を塗りつぶさないようにする */
		int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

		//　やっつけでやるならば、フォントの種類を設定するのを記述する
		DrawTextA(hdc, textbool,caret_pos, &rc, DT_LEFT | DT_SINGLELINE | DT_VCENTER | DT_CALCRECT);
		
		//  フォントをもとに戻す　
		/* 元の設定に戻す */
		::SelectObject(hdc, hfont_previous);
		::SetTextColor(hdc, color_previous);
		::SetBkMode(hdc, bkmode_previous);

		/* 自分で作ったフォントデータを削除する */
		::DeleteObject(hfont_normal);

		int text_width = rc.right - rc.left;
		// Rectangleで細長い矩形を描いてキャレットを模倣する　★☆★
		::Rectangle(hdc, x + 0 + text_width, y + 4, x + 0 + 2 + text_width, (y + 4) + (h-8));
	}
	
	/* 元々のペンやブラシに戻す */
	::SelectObject(hdc, hpen_previous);
	::SelectObject(hdc, hbrush_previous);

	/* 自分で作ったペンやブラシを削除する */
	::DeleteObject(hpen_normal);
	::DeleteObject(hpen_pressed);
	::DeleteObject(hpen_disabled);
	::DeleteObject(hbrush_normal);
	::DeleteObject(hbrush_pressed);
	::DeleteObject(hbrush_disablede);
}

void  graphics::DrawStandardLine(HDC hdc, int x, int y, int w, int h) {
	/* ペンやブラシを用意する */
	HPEN hpen_normal = ::CreatePen(PS_DASHDOT, 1, RGB(0xff, 0x00, 0x00));
	HBRUSH hbrush_normal = ::CreateSolidBrush(RGB(0xff, 0xff, 0xff));

	/* 元々のペンやブラシを変数に入れて残しておく */
	HPEN   hpen_previous = (HPEN)::SelectObject(hdc, hpen_normal);
	HBRUSH hbrush_previous = (HBRUSH)::SelectObject(hdc, hbrush_normal);

	/* 条件に合わせてボタンの絵を描く */

		::Rectangle(hdc, x, y, x + w, y + h);
		::MoveToEx(hdc, 100, 400, NULL);
		::LineTo(hdc, 100+x*10, 400+y*10);


	/* 元々のペンやブラシに戻す */

	::SelectObject(hdc, hpen_previous);
	::SelectObject(hdc, hbrush_previous);


	/* 自分で作ったペンやブラシを削除する */

	::DeleteObject(hpen_normal);
	::DeleteObject(hbrush_normal);
}

void  graphics::PaintBitmapFromFile(HDC hdc, int x, int y, int w, int h, const char* path)
{
	// 2022_02_22追加分
	/* ファイルから画像データを取り込む */

	// こちらはLoadImageA
	HBITMAP hbmp_sample = (HBITMAP)::LoadImageA(NULL, path,
	IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);

	/* 出力先と互換性のあるDCをもう１つ用意して画像データと紐づける */
	//　DC同士でデータのやり取りをやらないとだめっぽい？

	HDC hdc_image = ::CreateCompatibleDC(hdc);
	HBITMAP hbmp_previous = (HBITMAP)::SelectObject(hdc_image, hbmp_sample);

	/* DC間で画像データを転写する */

	::BitBlt(hdc, x, y, w, h, hdc_image, 0, 0, SRCCOPY); // 120, 120を画像に合わせる

	/* DCを削除する */

	::SelectObject(hdc_image, hbmp_previous);
	::DeleteDC(hdc_image);

	/* 画像データを削除する */

	::DeleteObject(hbmp_sample);

}

void  graphics::PaintBitmapFromFile(HDC hdc, int x, int y, int w, int h, const wchar_t* path)
{
	// こちらはLoadImageW
	HBITMAP hbmp_sample = (HBITMAP)::LoadImageW(NULL, path,
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);

	/* 出力先と互換性のあるDCをもう１つ用意して画像データと紐づける */
	//　DC同士でデータのやり取りをやらないとだめっぽい？

	HDC hdc_image = ::CreateCompatibleDC(hdc);
	HBITMAP hbmp_previous = (HBITMAP)::SelectObject(hdc_image, hbmp_sample);

	/* DC間で画像データを転写する */

	::BitBlt(hdc, x, y, w, h, hdc_image, 0, 0, SRCCOPY); // 120, 120を画像に合わせる

	/* DCを削除する */

	::SelectObject(hdc_image, hbmp_previous);
	::DeleteDC(hdc_image);

	/* 画像データを削除する */

	::DeleteObject(hbmp_sample);
}

/// <summary>標準的な条件で文字列を描画する</summary>
void  graphics::DrawStandardText(HDC hdc, int x, int y, int w, int h, const char* text)
{
	/* フォントデータを用意する */

	HFONT hfont_normal = ::CreateFont(
		16,					// 文字の高さ[論理単位]
		0,					// 文字の幅（0を指定すると文字の高さを基準にして自動決定される）
		0,					// 文字送り方向とX軸の角度[0.1°単位]
		0,					// ベースラインとX軸の角度[0.1°単位]
		FW_NORMAL,				// 線の太さ
		0,					// 0:標準 / 1:斜体
		0,					// 0:標準 / 1:下線付き
		0,					// 0:標準 / 1:打ち消し線付き
		DEFAULT_CHARSET,			// 文字セット
		OUT_DEFAULT_PRECIS,			// 出力精度
		CLIP_DEFAULT_PRECIS,			// クリッピング精度
		DEFAULT_QUALITY,			// 出力品質
		DEFAULT_PITCH | FF_DONTCARE,	// ピッチとフォントファミリ
		"ＭＳ ゴシック"			// フォント名
	);

	HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);


	/* 色を変える */

	COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));
	
	/* 文字を描くとき背景部分を塗りつぶさないようにする */

	int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

	/* 文字を書く */

	RECT text_area = { x, y, x + w, y + h };
	::DrawTextA(hdc, text, -1, &text_area, DT_LEFT);	// 改行文字"\n"のところで改行される


	/* 元の設定に戻す */

	::SelectObject(hdc, hfont_previous);
	::SetTextColor(hdc, color_previous);
	::SetBkMode(hdc, bkmode_previous);

	/* 自分で作ったフォントデータを削除する */

	::DeleteObject(hfont_normal);
}

void  graphics::DrawStandardText(HDC hdc, int x, int y, int w, int h, const wchar_t* text)
{
	/* フォントデータを用意する */

	HFONT hfont_normal = ::CreateFont(
		16,					// 文字の高さ[論理単位]
		0,					// 文字の幅（0を指定すると文字の高さを基準にして自動決定される）
		0,					// 文字送り方向とX軸の角度[0.1°単位]
		0,					// ベースラインとX軸の角度[0.1°単位]
		FW_NORMAL,				// 線の太さ
		0,					// 0:標準 / 1:斜体
		0,					// 0:標準 / 1:下線付き
		0,					// 0:標準 / 1:打ち消し線付き
		DEFAULT_CHARSET,			// 文字セット
		OUT_DEFAULT_PRECIS,			// 出力精度
		CLIP_DEFAULT_PRECIS,			// クリッピング精度
		DEFAULT_QUALITY,			// 出力品質
		DEFAULT_PITCH | FF_DONTCARE,	// ピッチとフォントファミリ
		"ＭＳ ゴシック"			// フォント名
	    //"ＨＧＰ創英角ﾎﾟｯﾌﾟ体"
		);

	HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);


	/* 色を変える */

	COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));

	/* 文字を描くとき背景部分を塗りつぶさないようにする */

	int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

	/* 文字を書く */

	RECT text_area = { x, y, x + w, y + h };
	::DrawTextW(hdc, text, -1, &text_area, DT_LEFT);	// 改行文字"\n"のところで改行される


	/* 元の設定に戻す */

	::SelectObject(hdc, hfont_previous);
	::SetTextColor(hdc, color_previous);
	::SetBkMode(hdc, bkmode_previous);

	/* 自分で作ったフォントデータを削除する */

	::DeleteObject(hfont_normal);
}

/// <summary>カスタマイズした条件で文字列を描画する</summary>
void  graphics::DrawCustumizedText(HDC hdc, int x, int y, int w, int h, const char* text, int font_height)
{
	/* フォントデータを用意する */
	HFONT hfont_normal = ::CreateFont(
		font_height,					// 文字の高さ[論理単位]
		0,					// 文字の幅（0を指定すると文字の高さを基準にして自動決定される）
		0,					// 文字送り方向とX軸の角度[0.1°単位]
		0,					// ベースラインとX軸の角度[0.1°単位]
		FW_NORMAL,				// 線の太さ
		0,					// 0:標準 / 1:斜体
		0,					// 0:標準 / 1:下線付き
		0,					// 0:標準 / 1:打ち消し線付き
		DEFAULT_CHARSET,			// 文字セット
		OUT_DEFAULT_PRECIS,			// 出力精度
		CLIP_DEFAULT_PRECIS,			// クリッピング精度
		DEFAULT_QUALITY,			// 出力品質
		DEFAULT_PITCH | FF_DONTCARE,	// ピッチとフォントファミリ
		"ＭＳ ゴシック"			// フォント名
		//"ＨＧＰ創英角ﾎﾟｯﾌﾟ体"
	);

	HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);

	/* 色を変える */
	COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));

	/* 文字を描くとき背景部分を塗りつぶさないようにする */
	int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

	/* 文字を書く */
	int padding = 0;// 位置を調整しやすいようにパディングは０にする

	RECT text_area = { 
		x + padding,
		y + padding,
		x + w - padding,
		y + h - padding 
	};

	// 位置を調整しやすいように縦方向も中央揃え（改行文字は無効）
	::DrawTextA(hdc, text, -1, &text_area, DT_LEFT| DT_VCENTER | DT_SINGLELINE);	// 改行文字"\n"のところで改行される

	/* 元の設定に戻す */
	::SelectObject(hdc, hfont_previous);
	::SetTextColor(hdc, color_previous);
	::SetBkMode(hdc, bkmode_previous);

	/* 自分で作ったフォントデータを削除する */
	::DeleteObject(hfont_normal);
}

void  graphics::DrawCustumizedText(HDC hdc, int x, int y, int w, int h, const wchar_t* text, int font_height)
{
	/* フォントデータを用意する */

	HFONT hfont_normal = ::CreateFont(
		16,					// 文字の高さ[論理単位]
		0,					// 文字の幅（0を指定すると文字の高さを基準にして自動決定される）
		0,					// 文字送り方向とX軸の角度[0.1°単位]
		0,					// ベースラインとX軸の角度[0.1°単位]
		FW_NORMAL,				// 線の太さ
		0,					// 0:標準 / 1:斜体
		0,					// 0:標準 / 1:下線付き
		0,					// 0:標準 / 1:打ち消し線付き
		DEFAULT_CHARSET,			// 文字セット
		OUT_DEFAULT_PRECIS,			// 出力精度
		CLIP_DEFAULT_PRECIS,			// クリッピング精度
		DEFAULT_QUALITY,			// 出力品質
		DEFAULT_PITCH | FF_DONTCARE,	// ピッチとフォントファミリ
		//"ＭＳ ゴシック"			// フォント名
		"ＨＧＰ創英角ﾎﾟｯﾌﾟ体"
	);

	HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);

	/* 色を変える */

	COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));

	/* 文字を描くとき背景部分を塗りつぶさないようにする */

	int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

	/* 文字を書く */

	RECT text_area = { x, y, x + w, y + h };
	::DrawTextW(hdc, text, -1, &text_area, DT_LEFT);	// 改行文字"\n"のところで改行される

	/* 元の設定に戻す */

	::SelectObject(hdc, hfont_previous);
	::SetTextColor(hdc, color_previous);
	::SetBkMode(hdc, bkmode_previous);

	/* 自分で作ったフォントデータを削除する */

	::DeleteObject(hfont_normal);
}
