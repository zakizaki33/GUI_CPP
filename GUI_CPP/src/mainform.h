/************************************************************

	���C����ʂ𑀍삷�邽�߂̊֐�

************************************************************/
#ifndef INCLUDE_MAIN_FORM_H
#define ICNLUDE_MAIN_FORM_H

#include <windows.h>

namespace mainform
{
	/// <summary>�S�Ă�GUI���i��`�悷��</summary>
	void  PaintAllItems( HDC hdc );

	/// <summary>�w��ʒu�̃{�^��������</summary>
	/// <remarks>��ԕω����̍ĕ`��ƃ{�^����������邱�Ƃɂ��@�\�̎��s���܂�</remarks>
	void  PressButtonAt( int x, int y );

	/// <summary>�S�Ẵ{�^����������Ă��Ȃ���Ԃɖ߂�</summary>
	void  ReleaseButtons( void );

	void MoveActiveTextBoxCareTo(int position);

	void MoveActiveTextBoxCareBy(int position);

	void SelectNextTextBox(void);

	void InsertCharacter(char c);

	void BackSpace(void);



}

#endif
