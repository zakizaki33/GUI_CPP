#ifndef INCLUDE_CALLBACK_H
#define INCLUDE_CALLBACK_H

#include <stdio.h>
#include <windows.h>

namespace app
{
	/// <summary>�C�x���g�v���V�[�W��</summary>
	LRESULT CALLBACK Procedure( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp );
}


#endif
