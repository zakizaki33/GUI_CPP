
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void StringCopy( char *output, const char *input );
int  StringLength( const char *input );


int main( void )
{
	/*-----------------------------------------------*
		�����R�[�h���w�肵�A�Ή����镶����\������
	*-----------------------------------------------*/
	{
		const char data1[13] = { 72, 101, 108, 108, 111, 44, 32, 119, 111, 114, 108, 100, 33 };
		// char data1[13] = { 72, 101, 108, 108, 111, 44, 32, 119, 111, 114, 108, 100, 33 };

		for( int i = 0; i < 13; i++ )
		{
			printf( "%c", data1[i] );
		}

		printf( "\n" );		// ���s
	}

	/*-----------------------------------------------*
		��̓I�ȕ����R�[�h�̑���ɕ����ŏ���
	*-----------------------------------------------*/
	{
		char data2[13] = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!' };

		for( int i = 0; i < 13; i++ )
		{
			printf( "%c", data2[i] );
		}

		printf( "\n" );		// ���s
	}

	/*-----------------------------------------------*
		�I�[�����̓����̊m�F�i���������̂P�j
	*-----------------------------------------------*/
	{
		char data3[14] = "Hello, world!"; // �I�[�������{�P�K�v

		printf( "%s\n", data3 );
	}

	/*-----------------------------------------------*
		�I�[�����̓����̊m�F�i���������̂Q�j
	*-----------------------------------------------*/
	{
		// char data4[14] = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0' };
		// 130, 177 �Łh���h
		// char data4[14] = { 130, 177,130, 241, 130, 201, 130, 191, 130, 205,0 };
		char data4[14] = { "����ɂ���" };

		printf( "%s\n", data4 );
	}

	/*-----------------------------------------------*
		������𑀍삷��֐�
	*-----------------------------------------------*/
	{
		char input[14] = "Hello, world!";
		char output[20] = "*******************";

		//StringCopy( output, input );
		strcpy_s( output, input );

		printf( "%s\n", output );

		// printf( "�������� %d �ł��B\n", StringLength( input ) );
		printf( "�������� %d �ł��B\n", (int)strlen( input ) );
	}
	system( "pause" );

	return 0;
}



/// <summary>��������R�s�[����֐�</summary>
void StringCopy( char *output, const char *input )
{
	for( int i=0; ; i++ )	// �������[�v
	{
		output[i] = input[i];

		if( input[i] == '\0' )
		{
			return;
		}
	}
}


/// <summary>�������𐔂���֐�</summary>
int StringLength( const char *input )
{
	for (int i = 0; ; i++)	// �������[�v
	{
		int count;
		count = i;

		if (input[i] == '\0')
		{
			return count;
		}
	}
}
