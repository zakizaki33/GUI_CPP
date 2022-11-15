/************************************************************

	GUI���i��`�悷�邽�߂̊֐�

************************************************************/


//	1. �C���N���[�h�K�[�h�������B
#ifndef INCLUDE_GRAPHICS_H
#define INCLUDE_GRAPHICS_H

#include <Windows.h>

//	2. �֐��̐錾�������B
namespace graphics
{
	void  PaintStandardButton(HDC hdc, int x, int y, int w, int h, bool enabled, bool pressed);
	void  PaintStandardTextBox(HDC hdc, int x, int y, int w, int h, const char* text, bool enabled, bool focused, int caret_pos);

	// �ȒP�Ȑ���\������
	void  DrawStandardLine(HDC hdc, int x, int y, int w, int h);

	// �t�@�C������摜�f�[�^��ǂݍ���ŕ\������
	void  PaintBitmapFromFile(HDC hdc, int x, int y, int w, int h, const char* path);
	void  PaintBitmapFromFile(HDC hdc, int x, int y, int w, int h, const wchar_t* path);

	/// <summary>�W���I�ȏ����ŕ������`�悷��</summary>
	void  DrawStandardText(HDC hdc, int x, int y, int w, int h, const char* text);
	void  DrawStandardText(HDC hdc, int x, int y, int w, int h, const wchar_t* text);

	/// <summary>�J�X�^�}�C�Y���������ŕ������`�悷��</summary>
	void  DrawCustumizedText(HDC hdc, int x, int y, int w, int h, const char* text, int font_height);
	void  DrawCustumizedText(HDC hdc, int x, int y, int w, int h, const wchar_t* text, int font_height);
}
/*
	3. ���̃w�b�_�t�@�C���Ɉˑ�����ꍇ�ɂ�include���������B
	   �������HDC���g���̂ŁAwindows.h���C���N���[�h����K�v������B
*/


#endif

#ifndef INCLUDE_GRAPHICS_H  // �C���N���[�h�K�[�h����Ă���̂ł���ȍ~�̓O���[�A�E�g�����i�R�[�h�����j
#define INCLUDE_GRAPHICS_H

#include <Windows.h>

//	2. �֐��̐錾�������B
namespace graphics
{
	void  PaintStandardButton(HDC hdc, int x, int y, int w, int h, bool enabled, bool pressed);
}
/*
	3. ���̃w�b�_�t�@�C���Ɉˑ�����ꍇ�ɂ�include���������B
	   �������HDC���g���̂ŁAwindows.h���C���N���[�h����K�v������B
*/


#endif

/*
// �ȉ��������Ƃ̗��K
#ifndef ABC //�����ł͂܂���`����Ă��Ȃ����獕��
#define ABC�@//�@�����Œ�`�����

#endif

#ifndef ABC�@//���łɒ�`����Ă��邩�率�i���P�ɍs���Ȃ��j�B�����#endif�i���Q�j�Ƀ��[�v
#define ABC�@//�@���P

#endif // ���Q
*/

