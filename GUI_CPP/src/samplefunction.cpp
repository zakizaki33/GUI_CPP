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

/// <summary>�t�@�C������P�g���̃f�[�^��ǂݍ���</summary>
static bool read_one_data( FILE *fp, char *buffer, int max_length )
{
	// �ǂݍ��߂�������
	int count = 0;

	for( ; ; )
	{
		char c;

		// �������ǂݍ��ށi�߂�l�͓ǂݍ��߂����j
		// ���s�����ꍇ�ɂ̓t�@�C���̖����ɒB�������̂Ƃ݂Ȃ��Ē��f����
		if( fread( &c, 1, 1, fp ) <= 0 )
		{
			buffer[count] = '\0';
			break;
		}

		// �ǂݍ��񂾂̂��X�y�[�X�������ꍇ�ɂ̓f�[�^�̋�؂�Ƃ݂Ȃ��Ē��f����
		if( c == ' ' )
		{
			buffer[count] = '\0';
			break;
		}

		// �ǂݍ��񂾂̂��^�u�������ꍇ�ɂ̓f�[�^�̋�؂�Ƃ݂Ȃ��Ē��f����
		if( c == '\t' )
		{
			buffer[count] = '\0';
			break;
		}

		// �ǂݍ��񂾂̂����s�����������ꍇ�ɂ̓f�[�^�̋�؂�Ƃ݂Ȃ��Ē��f����
		if( c == '\n' )
		{
			buffer[count] = '\0';
			break;
		}

		// ��L�ȊO�̕�����ǂݍ��񂾏ꍇ�ɂ̓o�b�t�@�ɒǉ�����
		// ����������ɒB���Ă���̂ɂ܂�����������ꍇ�ɂ͎��s�����Ƃ���
		if( max_length <= count )
		{
			buffer[max_length] = '\0';
			return false;
		}

		buffer[count] = c;
		count++;
	}

	// ���ʓI�ɂP�������ǂݍ��߂Ȃ������ꍇ�ɂ͎��s�����Ƃ���
	if( count == 0 )
	{
		return false;
	}
	else
	{
		return true;
	}
}

/// <summary>�t�@�C������f�[�^��ǂݍ���ŉ�ʂɕ\�������A�̏���</summary>
void SampleFunction( void )
{
	HWND  hwnd = app::GetWindowHandle();
	
	CFile file = { "*.txt" };
	FILE* fp = NULL;


	/*** �C���v�b�g�t�@�C����I������ ***/

	if( file.SelectOpenFile( hwnd, "�e�L�X�g�t�@�C��\0*.txt\0�S�Ẵt�@�C��\0*.*\0" ) == FALSE )
	{
		return;		// �t�@�C���̑I�����L�����Z�������ꍇ�ɂ͏I������
	}


	/*** �C���v�b�g�t�@�C�����J�� ***/

	if( fopen_s( &fp, file.GetPath(), "r" ) != 0 )
	{
		return;		// �t�@�C�����J���Ȃ������ꍇ�ɂ͏I������
	}


	/*** �C���v�b�g�t�@�C������ǂݍ��� ***/

	int x = 0;
	int y = 0;

	for( ; ; )
	{
		char buffer[100 + 1];

		if( read_one_data( fp, buffer, 100 ) == false )
		{
			break;
		}
		
		// 2023-02-15�@�ǋL�@�t�@�C���̒��g��\��
		std::cout << buffer << std::endl; 
		str_samplefunc += buffer;
		strcat_s(buffer2, buffer);


		// 
		// mainform::textbox_data_table[2].caption;

		// �ǂݍ��񂾕�����"x="�Ŏn�܂��Ă����炻��ɑ������������Ɏ�荞��
		if( strstr( buffer, "x=" ) == buffer )
		{
			x = atoi( &(buffer[2]) );
		}

		// �ǂݍ��񂾕�����"y="�Ŏn�܂��Ă����炻��ɑ������������Ɏ�荞��
		if( strstr( buffer, "y=" ) == buffer )
		{
			y = atoi( &(buffer[2]) );
		}
	}

	/*** �t�@�C������� ***/
	if (fp != NULL) {
		fclose(fp);
	}


	/*** �ǂݍ��񂾃f�[�^���������� ***/

	s_input_x = x;
	s_input_y = y;
	s_output_average = (x + y) / 2;

	printf( "file : %s\n", file.GetPath() );
	printf( "x    : %d\n", s_input_x );
	printf( "y    : %d\n", s_input_y );
	printf( "ave  : %d\n", s_output_average );


	/*** �E�B���h�E�̕\�����X�V���� ***/

	app::RepaintWindow();
}

/// <summary>���݂̃f�[�^���擾����</summary>
int GetCurrentX( void )
{
	return s_input_x;
}

/// <summary>���݂̃f�[�^���擾����</summary>
int GetCurrentY( void )
{
	return s_input_y;
}

/// <summary>���݂̃f�[�^���擾����</summary>
int GetCurrentAverage( void )
{
	return s_output_average;
}
