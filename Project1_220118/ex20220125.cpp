
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void StringCopy( char *output, const char *input );
int  StringLength( const char *input );


int main( void )
{
	/*-----------------------------------------------*
		文字コードを指定し、対応する文字を表示する
	*-----------------------------------------------*/
	{
		const char data1[13] = { 72, 101, 108, 108, 111, 44, 32, 119, 111, 114, 108, 100, 33 };
		// char data1[13] = { 72, 101, 108, 108, 111, 44, 32, 119, 111, 114, 108, 100, 33 };

		for( int i = 0; i < 13; i++ )
		{
			printf( "%c", data1[i] );
		}

		printf( "\n" );		// 改行
	}

	/*-----------------------------------------------*
		具体的な文字コードの代わりに文字で書く
	*-----------------------------------------------*/
	{
		char data2[13] = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!' };

		for( int i = 0; i < 13; i++ )
		{
			printf( "%c", data2[i] );
		}

		printf( "\n" );		// 改行
	}

	/*-----------------------------------------------*
		終端文字の働きの確認（書き方その１）
	*-----------------------------------------------*/
	{
		char data3[14] = "Hello, world!"; // 終端文字分＋１必要

		printf( "%s\n", data3 );
	}

	/*-----------------------------------------------*
		終端文字の働きの確認（書き方その２）
	*-----------------------------------------------*/
	{
		// char data4[14] = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0' };
		// 130, 177 で”こ”
		// char data4[14] = { 130, 177,130, 241, 130, 201, 130, 191, 130, 205,0 };
		char data4[14] = { "こんにちは" };

		printf( "%s\n", data4 );
	}

	/*-----------------------------------------------*
		文字列を操作する関数
	*-----------------------------------------------*/
	{
		char input[14] = "Hello, world!";
		char output[20] = "*******************";

		//StringCopy( output, input );
		strcpy_s( output, input );

		printf( "%s\n", output );

		// printf( "文字数は %d です。\n", StringLength( input ) );
		printf( "文字数は %d です。\n", (int)strlen( input ) );
	}
	system( "pause" );

	return 0;
}



/// <summary>文字列をコピーする関数</summary>
void StringCopy( char *output, const char *input )
{
	for( int i=0; ; i++ )	// 無限ループ
	{
		output[i] = input[i];

		if( input[i] == '\0' )
		{
			return;
		}
	}
}


/// <summary>文字数を数える関数</summary>
int StringLength( const char *input )
{
	for (int i = 0; ; i++)	// 無限ループ
	{
		int count;
		count = i;

		if (input[i] == '\0')
		{
			return count;
		}
	}
}
