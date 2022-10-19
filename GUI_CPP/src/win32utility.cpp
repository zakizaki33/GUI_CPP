#include <stdio.h>
#include <windows.h>
#include "win32utility.h"
#include <windowsx.h>


/// <summary>�W���o�͗p�̃R���\�[�����N������</summary>
void  win32utl::ShowDebugConsole( void )
{
	if( AllocConsole() )
	{
		FILE *fp;
		freopen_s( &fp, "CONOUT$", "w", stdout );
	}
}

/// <summary>�W���o�͗p�̃R���\�[��������</summary>
void  win32utl::HideDebugConsole( void )
{
	FreeConsole();
}


/// <summary>�L�[�C�x���g���b�Z�[�W����L�[�R�[�h���擾����</summary>
int  win32utl::GetKeyCode(WPARAM wp, LPARAM lp)
{
	return (int)wp;
}

/// <summary>�������̓C�x���g���b�Z�[�W���當�����擾����</summary>
char  win32utl::GetCharCode(WPARAM wp, LPARAM lp)
{
	return (char)wp;
}

/// <summary>�}�E�X�C�x���g���b�Z�[�W����}�E�X�̍��W���擾����</summary>
int  win32utl::GetMouseX(WPARAM wp, LPARAM lp)
{
	return GET_X_LPARAM(lp);
}

/// <summary>�}�E�X�C�x���g���b�Z�[�W����}�E�X�̍��W���擾����</summary>
int  win32utl::GetMouseY(WPARAM wp, LPARAM lp)
{
	return GET_Y_LPARAM(lp);
}

