
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int data[12] = { 15, 61, 29, 77, 50, 3, 19, 43, 35, 68 };
	int *pointer = data;

	/*-----------------------------------------------*
		�|�C���^�ɑ΂��Ẳ����Z��
		�ǂ̂悤�ȈӖ��������H
	*-----------------------------------------------*/

	printf( "pointer + 0 = %p \n", pointer + 0 );
	printf( "pointer + 1 = %p \n", pointer + 1 );
	printf( "pointer + 2 = %p \n", pointer + 2 );
	printf( "pointer + 3 = %p \n", pointer + 3 );
	printf( "\n" );

	/*-----------------------------------------------*
		�|�C���^�̉����Z�œ���ꂽ�A�h���X�ɂ���
		�ϐ��̒l���m�F����i���������̂P�j
	*-----------------------------------------------*/

	printf( "*(pointer + 0) = %d \n", *(pointer + 0) );
	printf( "*(pointer + 1) = %d \n", *(pointer + 1) );
	printf( "*(pointer + 2) = %d \n", *(pointer + 2) );
	printf( "*(pointer + 3) = %d \n", *(pointer + 3) );
	printf( "\n" );

	/*-----------------------------------------------*
		�|�C���^�̉����Z�œ���ꂽ�A�h���X�ɂ���
		�ϐ��̒l���m�F����i���������̂Q�j
	*-----------------------------------------------*/

	printf( "pointer[0] = %d \n", pointer[0] );
	printf( "pointer[1] = %d \n", pointer[1] );
	printf( "pointer[2] = %d \n", pointer[2] );
	printf( "pointer[3] = %d \n", pointer[3] );
	printf( "\n" );


	system( "pause" );

	return 0;
}
