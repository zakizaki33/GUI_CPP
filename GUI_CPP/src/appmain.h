#ifndef INCLUDE_APPMAIN_H // ��������
#define INCLUDE_APPMAIN_H

#include <Windows.h>

namespace app
{
	/// <summary>�E�B���h�E�̃n���h�����擾����</summary>
	HWND  GetWindowHandle( void );

	/// <summary>�E�B���h�E���ĕ`�悷��</summary>
	void  RepaintWindow( void );
}

#endif