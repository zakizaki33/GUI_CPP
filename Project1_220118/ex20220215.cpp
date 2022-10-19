
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
	// �}���`�o�C�g�����ƃ��C�h�����̕ϊ�����������ꍇ�ɂ�
	// �K�p���镶���R�[�h���w�肵�Ă����K�v������
	setlocale( LC_CTYPE, "" );

	/*-----------------------------------------------*
		char�^���g���ă}���`�o�C�g�����������
	*-----------------------------------------------*/
	{
		char data1[20] = "abc����������";

		int length = strlen( data1 );

		printf( "%s ... %2d���� ", data1, length );

		for( int i = 0; i < length; i++ )
		{
			printf( "%04x ", (unsigned short)data1[i] );
		}

		printf( "\n" );		// ���s
	}

	/*-----------------------------------------------*
		wchar_t�^���g���ă��C�h�����������
	*-----------------------------------------------*/
	{
		wchar_t data1[20] = L"abc����������";

		int length = wcslen( data1 );

		wprintf( L"%s ... %2d���� ", data1, length );

		for( int i = 0; i < length; i++ )
		{
			wprintf( L"%04x ", (unsigned short)data1[i] );
		}

		wprintf( L"\n" );		// ���s
	}

	/*-----------------------------------------------*
		TCHAR�^���g���ĕ����������
	*-----------------------------------------------*/
	{
		// �\���v���p�e�B�ˏڍׁ˕����R�[�h�i�}���`�o�C�g��uni�R�[�h�Ő؂�ւ����ł���j
		TCHAR data1[20] = _T("abc����������");

		int length = _tcslen( data1 );

		_tprintf( _T("%s ... %2d���� "), data1, length );

		for( int i = 0; i < length; i++ )
		{
			_tprintf( _T("%04x "), (unsigned short)data1[i] );
		}

		_tprintf( _T("\n") );		// ���s
	}

	system( "pause" );

	return 0;
}
