#include <stdio.h>
#include <string.h>
#include "appmain.h"
#include "file.h"
#include "samplefunction.h"
#include <iostream>

static int s_input_x = 0;
static int s_input_y = 0;
static int s_output_average = 0;

std::string str_samplefunc;

/// <summary>ファイルから１組分のデータを読み込む</summary>
static bool read_one_data( FILE *fp, char *buffer, int max_length )
{
	// 読み込めた文字数
	int count = 0;

	for( ; ; )
	{
		char c;

		// 文字ずつ読み込む（戻り値は読み込めた個数）
		// 失敗した場合にはファイルの末尾に達したものとみなして中断する
		if( fread( &c, 1, 1, fp ) <= 0 )
		{
			buffer[count] = '\0';
			break;
		}

		// 読み込んだのがスペースだった場合にはデータの区切りとみなして中断する
		if( c == ' ' )
		{
			buffer[count] = '\0';
			break;
		}

		// 読み込んだのがタブだった場合にはデータの区切りとみなして中断する
		if( c == '\t' )
		{
			buffer[count] = '\0';
			break;
		}

		// 読み込んだのが改行文字だった場合にはデータの区切りとみなして中断する
		if( c == '\n' )
		{
			buffer[count] = '\0';
			break;
		}

		// 上記以外の文字を読み込んだ場合にはバッファに追加する
		// 上限文字数に達しているのにまだ続きがある場合には失敗扱いとする
		if( max_length <= count )
		{
			buffer[max_length] = '\0';
			return false;
		}

		buffer[count] = c;
		count++;
	}

	// 結果的に１文字も読み込めなかった場合には失敗扱いとする
	if( count == 0 )
	{
		return false;
	}
	else
	{
		return true;
	}
}

/// <summary>ファイルからデータを読み込んで画面に表示する一連の処理</summary>
void SampleFunction( void )
{
	HWND  hwnd = app::GetWindowHandle();
	
	CFile file = { "*.txt" };
	FILE* fp = NULL;


	/*** インプットファイルを選択する ***/

	if( file.SelectOpenFile( hwnd, "テキストファイル\0*.txt\0全てのファイル\0*.*\0" ) == FALSE )
	{
		return;		// ファイルの選択をキャンセルした場合には終了する
	}


	/*** インプットファイルを開く ***/

	if( fopen_s( &fp, file.GetPath(), "r" ) != 0 )
	{
		return;		// ファイルが開けなかった場合には終了する
	}


	/*** インプットファイルから読み込む ***/

	int x = 0;
	int y = 0;

	for( ; ; )
	{
		char buffer[100 + 1];

		if( read_one_data( fp, buffer, 100 ) == false )
		{
			break;
		}
		
		// 2023-02-15　追記　ファイルの中身を表示
		std::cout << buffer << std::endl; 
		str_samplefunc += buffer;
		strcat_s(buffer2, buffer);


		// 
		// mainform::textbox_data_table[2].caption;

		// 読み込んだ文字列が"x="で始まっていたらそれに続く数字をｘに取り込む
		if( strstr( buffer, "x=" ) == buffer )
		{
			x = atoi( &(buffer[2]) );
		}

		// 読み込んだ文字列が"y="で始まっていたらそれに続く数字をｘに取り込む
		if( strstr( buffer, "y=" ) == buffer )
		{
			y = atoi( &(buffer[2]) );
		}
	}

	/*** ファイルを閉じる ***/
	if (fp != NULL) {
		fclose(fp);
	}


	/*** 読み込んだデータを処理する ***/

	s_input_x = x;
	s_input_y = y;
	s_output_average = (x + y) / 2;

	printf( "file : %s\n", file.GetPath() );
	printf( "x    : %d\n", s_input_x );
	printf( "y    : %d\n", s_input_y );
	printf( "ave  : %d\n", s_output_average );


	/*** ウィンドウの表示を更新する ***/

	app::RepaintWindow();
}

/// <summary>現在のデータを取得する</summary>
int GetCurrentX( void )
{
	return s_input_x;
}

/// <summary>現在のデータを取得する</summary>
int GetCurrentY( void )
{
	return s_input_y;
}

/// <summary>現在のデータを取得する</summary>
int GetCurrentAverage( void )
{
	return s_output_average;
}
