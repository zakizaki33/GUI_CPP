#ifndef INCLUDE_WIN32UTILITY_H
#define INCLUDE_WIN32UTILITY_H

#include <stdio.h>
#include <windows.h>

namespace win32utl 
{
	/// <summary>�W���o�͗p�̃R���\�[�����N������</summary>
	void  ShowDebugConsole( void );

	/// <summary>�W���o�͗p�̃R���\�[��������</summary>
	void  HideDebugConsole( void );

	/// <summary>�L�[�C�x���g���b�Z�[�W���牼�z�L�[�R�[�h���擾����</summary>
	int  GetKeyCode(WPARAM wp, LPARAM lp);

	/// <summary>�������̓C�x���g���b�Z�[�W���當�����擾����</summary>
	char GetCharCode(WPARAM wp, LPARAM lp);

	/// <summary>�}�E�X�C�x���g���b�Z�[�W����}�E�X�̍��W���擾����</summary>
	int  GetMouseX(WPARAM wp, LPARAM lp);
	int  GetMouseY(WPARAM wp, LPARAM lp);
}
#endif
