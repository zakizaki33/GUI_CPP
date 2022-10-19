
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int data[12] = { 15, 61, 29, 77, 50, 3, 19, 43, 35, 68 };
	int *pointer = data;

	/*-----------------------------------------------*
		ポインタに対しての加減算は
		どのような意味を持つか？
	*-----------------------------------------------*/

	printf( "pointer + 0 = %p \n", pointer + 0 );
	printf( "pointer + 1 = %p \n", pointer + 1 );
	printf( "pointer + 2 = %p \n", pointer + 2 );
	printf( "pointer + 3 = %p \n", pointer + 3 );
	printf( "\n" );

	/*-----------------------------------------------*
		ポインタの加減算で得られたアドレスにある
		変数の値を確認する（書き方その１）
	*-----------------------------------------------*/

	printf( "*(pointer + 0) = %d \n", *(pointer + 0) );
	printf( "*(pointer + 1) = %d \n", *(pointer + 1) );
	printf( "*(pointer + 2) = %d \n", *(pointer + 2) );
	printf( "*(pointer + 3) = %d \n", *(pointer + 3) );
	printf( "\n" );

	/*-----------------------------------------------*
		ポインタの加減算で得られたアドレスにある
		変数の値を確認する（書き方その２）
	*-----------------------------------------------*/

	printf( "pointer[0] = %d \n", pointer[0] );
	printf( "pointer[1] = %d \n", pointer[1] );
	printf( "pointer[2] = %d \n", pointer[2] );
	printf( "pointer[3] = %d \n", pointer[3] );
	printf( "\n" );


	system( "pause" );

	return 0;
}
