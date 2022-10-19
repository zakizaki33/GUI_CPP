
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <tchar.h>
#include <string.h>




void StringCopy( char *output, const char *input );
int  StringLength( const char *input );


int main( void )
{
	// マルチバイト文字とワイド文字の変換が発生する場合には
	// 適用する文字コードを指定しておく必要がある
	setlocale( LC_CTYPE, "" );

	/*-----------------------------------------------*
		char型を使ってマルチバイト文字列を扱う
	*-----------------------------------------------*/
	{
		char data1[20] = "abcあいうえお";

		int length = strlen( data1 );

		printf( "%s ... %2d文字 ", data1, length );

		for( int i = 0; i < length; i++ )
		{
			printf( "%04x ", (unsigned short)data1[i] );
		}

		printf( "\n" );		// 改行
	}

	/*-----------------------------------------------*
		wchar_t型を使ってワイド文字列を扱う
	*-----------------------------------------------*/
	{
		wchar_t data1[20] = L"abcあいうえお";

		int length = wcslen( data1 );

		wprintf( L"%s ... %2d文字 ", data1, length );

		for( int i = 0; i < length; i++ )
		{
			wprintf( L"%04x ", (unsigned short)data1[i] );
		}

		wprintf( L"\n" );		// 改行
	}

	/*-----------------------------------------------*
		TCHAR型を使って文字列を扱う
	*-----------------------------------------------*/
	{
		// 構成プロパティ⇒詳細⇒文字コード（マルチバイトかuniコードで切り替えができる）
		TCHAR data1[20] = _T("abcあいうえお");

		int length = _tcslen( data1 );

		_tprintf( _T("%s ... %2d文字 "), data1, length );

		for( int i = 0; i < length; i++ )
		{
			_tprintf( _T("%04x "), (unsigned short)data1[i] );
		}

		_tprintf( _T("\n") );		// 改行
	}

	system( "pause" );

	return 0;
}
