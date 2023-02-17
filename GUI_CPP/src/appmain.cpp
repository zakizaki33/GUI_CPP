#include <stdio.h>
#define OEMRESOURCE 
#include <windows.h>
#include "win32utility.h"
#include "callback.h"
#include "appmain.h"
#include "file.h"
#include "samplefunction.h"

// 起動時のウインドウの大きさ
#define INIT_WINDOW_X 100
#define INIT_WINDOW_Y 100
#define INIT_WINDOW_W 800 //500
#define INIT_WINDOW_H 600 //400

// int 型にPIXELというあだ名をつけるイメージ
typedef int PIXEL;
PIXEL a = (int)10.1; // PIXEL はintなので、小数点があると警告が出る
PIXEL b = 9;

static HWND s_main_window_handle;

// appmain.cpp内の関数なのでヘッダーファイルに書き込みの必要なし
void FileAccessSample(const char* path)
{
	FILE* fp = NULL;

	// ファイルを書き込み用に開く
	if (fopen_s(&fp, path, "w") == 0)
	{
		char input_data[] = "Hello, world!\n12345\ntesttest\n";

		// 文字列を書き込む
		if (fp != 0) {
			fwrite(input_data, 1, strlen(input_data), fp);
		}
		// ファイルを閉じる
		if (fp != 0) {
			fclose(fp);
		}
	}

	// ファイルを読み込み用に開く
	if (fopen_s(&fp, path, "r") == 0)
	{
		char data;

		for (; ; )
		{
			// １文字ずつ読み込む
			// 戻り値は読み込めた個数で、失敗した時点でループを抜ける
			if (fp != 0) {
				if (fread(&data, 1, 1, fp) < 1)
				{
					break;
				}
				printf("%c", data);
			}
		}

		// ファイルを閉じる
		if (fp != 0) {
			fclose(fp);
		}
	}
}

/// <summary>ウィンドウのハンドルを取得する</summary>
HWND  app::GetWindowHandle(void)
{
	return s_main_window_handle;
}

/// <summary>ウィンドウを再描画する</summary>
void  app::RepaintWindow(void)
{
	::InvalidateRect(s_main_window_handle, NULL, TRUE);
	::UpdateWindow(s_main_window_handle);
}

/// <summary>メイン関数</summary>
int WINAPI WinMain(
	_In_     HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_     LPSTR lpCmdLine,
	_In_     int nCmdShow
)
{
	CFile file("default.txt");
	
	// Debugウインドウの表示
	win32utl::ShowDebugConsole();

	/*
	CFile file1 = { "input.txt" }; //structの中に定義されている順番通りに値が入っていく

	if (file1.IsExist()) {
		printf("このファイルは存在します\n");
	}
	else
	{
		printf("このファイルは存在しません\n");
	}
	*/

	// 動作確認用のファイル読み出し関数
	FileAccessSample("C:\\Users\\13273_Yamazaki\\source\\repos\\GUI_CPP\\GUI_CPP\\src\\input.txt");
	
	char class_name[] = "my_standard_window"; 

	WNDCLASSEX  window_class_settings = {
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,	/* リサイズしたときに再描画させる */
		app::Procedure,
		0,
		0,
		hInstance,
		NULL,						/* アイコン     */
		NULL,						/* カーソル     */
		NULL,						/* 背景ブラシ   */
		NULL,						/* メニューバー */
		class_name,
		NULL,						/* アイコン(小) */
	};

	if( RegisterClassEx( &window_class_settings ) == 0 )
	{
		return 0;
	}

	// CreateWindow関数はそのウインドウのハンドル（名前札みたいなもの？）を返す
	HWND hwnd = CreateWindow(
		class_name,
		"ウインドウのバーに表示させたい文字はCreateWindowに記述",
		WS_OVERLAPPEDWINDOW,
		INIT_WINDOW_X,
		INIT_WINDOW_Y,
		INIT_WINDOW_W,			/* window width*/
		INIT_WINDOW_H,            /* window height*/
		NULL,			/* 親ウィンドウ */
		NULL,			/* メニューバー */
		hInstance,
		0				/* WM_CREATEのLPARAM */
	);

	if( hwnd == NULL )
	{
		return 0;
	}

	s_main_window_handle = hwnd;

	ShowWindow( hwnd, nCmdShow );

	
	// ファイルダイアログを表示させる(練習)
	{
		// CFile file = { "c:\\soft\\*.*" };  // 最初に開く場所
		CFile file = { "D:\\13273_Yamazaki\\Desktop\\*.*" };

		// if (file.SelectOpenFile(hwnd, "テキストファイル\0*.txt\0全てのファイル\0*.*\0"))
		if (file.SelectSaveFile(hwnd, "PDFfile\0*.pdf\0テキストファイル\0*.txt\0全てのファイル\0*.*\0")) //\0 終端文字
		{
			printf("ファイルが選択されました。\n");
			// printf("%s\n", file.m_path); // privateは触れない
		}
		else
		{
			printf("ファイルの選択は中断されました。\n");
		}
	}
	
	// samplefunction.h よりファイルダイアログが開く
	// SampleFunction();

	MSG msg;

	while( 0 < GetMessage( &msg, NULL, 0, 0 ) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	
	// Debugウインドウの非表示
	win32utl::HideDebugConsole();

	return 0;
}


