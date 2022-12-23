/************************************************************

	GUI���i��`�悷�邽�߂̊֐�

************************************************************/
#include <windows.h>
#include "graphics.h"

/// <summary>�W���I�ȃ{�^����`�悷��</summary>
/// <param name="hdc">�`��Ώۂ�DC</param>
/// <param name="x">����[��X���W</param>
/// <param name="y">����[��Y���W</param>
/// <param name="w">��</param>
/// <param name="h">����</param>
/// <param name="enabled">true�Ȃ牟����/false�Ȃ牟���Ȃ�</param>
/// <param name="pressed">true�Ȃ牟����Ă���/false�Ȃ牟����Ă��Ȃ�</param>
void  graphics::PaintStandardButton( HDC hdc, int x, int y, int w, int h, bool enabled, bool pressed )
{
	/* �y����u���V��p�ӂ��� */

 	HPEN hpen_normal    = ::CreatePen( PS_SOLID, 1, RGB(0x00,0x00,0x00) ); 
 	HPEN hpen_pressed   = ::CreatePen( PS_SOLID, 1, RGB(0x00,0x00,0x00) ); 
	HPEN hpen_disabled  = ::CreatePen( PS_SOLID, 1, RGB(0x66,0x66,0x66) ); 

	HBRUSH hbrush_normal    = ::CreateSolidBrush( RGB(0xff,0xff,0xff) );
	HBRUSH hbrush_pressed   = ::CreateSolidBrush( RGB(0xff,0xcc,0x00) );
	HBRUSH hbrush_disablede = ::CreateSolidBrush( RGB(0x99,0x99,0x99) );


	/* ���X�̃y����u���V��ϐ��ɓ���Ďc���Ă��� */

	HPEN   hpen_previous   = (HPEN  )::SelectObject( hdc, hpen_normal ); 
	HBRUSH hbrush_previous = (HBRUSH)::SelectObject( hdc, hbrush_normal );


	/* �����ɍ��킹�ă{�^���̊G��`�� */

	if( enabled == false )
	{
		::SelectObject( hdc, hpen_disabled );
		::SelectObject( hdc, hbrush_disablede );

		::Rectangle( hdc, x, y, x + w, y + h );
	}
	else if( pressed == true )
	{
		::SelectObject( hdc, hpen_pressed );
		::SelectObject( hdc, hbrush_pressed );

		::Rectangle( hdc, x, y, x + w, y + h );
	}
	else
	{
		::Rectangle( hdc, x, y, x + w, y + h );
	}


	/* ���X�̃y����u���V�ɖ߂� */

	::SelectObject( hdc, hpen_previous );
	::SelectObject( hdc, hbrush_previous );


	/* �����ō�����y����u���V���폜���� */

	::DeleteObject( hpen_normal );
	::DeleteObject( hpen_pressed );
	::DeleteObject( hpen_disabled );
	::DeleteObject( hbrush_normal );
	::DeleteObject( hbrush_pressed );
	::DeleteObject( hbrush_disablede );
}

void  graphics::PaintStandardTextBox(HDC hdc, int x, int y, int w, int h, const char* textbool, bool enabled, bool focused, int caret_pos)
{
	/* �y����u���V��p�ӂ��� */
	HPEN hpen_normal = ::CreatePen(PS_SOLID, 1, RGB(0x00, 0xff, 0x00));
	HPEN hpen_pressed = ::CreatePen(PS_DASHDOT, 1, RGB(0x00, 0x00, 0x00));
	HPEN hpen_disabled = ::CreatePen(PS_DASHDOT, 1, RGB(0x66, 0x66, 0x66));
	HBRUSH hbrush_normal = ::CreateSolidBrush(RGB(0xff, 0xff, 0xff));
	HBRUSH hbrush_pressed = ::CreateSolidBrush(RGB(0xff, 0xcc, 0x00));
	HBRUSH hbrush_disablede = ::CreateSolidBrush(RGB(0x99, 0x99, 0x99));

	/* ���X�̃y����u���V��ϐ��ɓ���Ďc���Ă��� */
	HPEN   hpen_previous = (HPEN)::SelectObject(hdc, hpen_normal);
	HBRUSH hbrush_previous = (HBRUSH)::SelectObject(hdc, hbrush_normal);

	/* �����ɍ��킹�ă{�^���̊G��`�� */
	if (enabled == false)
	{
		::SelectObject(hdc, hpen_disabled);
		::SelectObject(hdc, hbrush_disablede);

		::Rectangle(hdc, x, y, x + w, y + h);
	}
	else if (focused == true)
	{
		::SelectObject(hdc, hpen_pressed);
		::SelectObject(hdc, hbrush_pressed);

		::Rectangle(hdc, x, y, x + w, y + h);
	}
	else
	{
		::Rectangle(hdc, x, y, x + w, y + h);
	}

	int font_width = 12;
	int font_height=font_width*2 ;

	// ���������̂�textbool�ō����Ă���H
	DrawCustumizedText(hdc, x, y , w ,h,textbool,font_height);

	// ���̉��ŃL�����b�g��`�悷���Ƃ����� ������
	::SelectObject(hdc, ::CreatePen(PS_SOLID, 1, RGB(0xff, 0xff, 0x00))); //�F�ύX
	{
		RECT rc = { 0,0,0,0 };
		// DrawTextA�Ƀt�H���g�̏���n��
		// MS�S�V�b�N�̐ݒ���ēx�w������
		// TODO 44��ځA47��ڂ����蕜�K

		/* �t�H���g�f�[�^��p�ӂ��� */
		HFONT hfont_normal = ::CreateFont(
			font_height,					// �����̍���[�_���P��]
			0,					// �����̕��i0���w�肷��ƕ����̍�������ɂ��Ď������肳���j
			0,					// �������������X���̊p�x[0.1���P��]
			0,					// �x�[�X���C����X���̊p�x[0.1���P��]
			FW_NORMAL,				// ���̑���
			0,					// 0:�W�� / 1:�Α�
			0,					// 0:�W�� / 1:�����t��
			0,					// 0:�W�� / 1:�ł��������t��
			DEFAULT_CHARSET,			// �����Z�b�g
			OUT_DEFAULT_PRECIS,			// �o�͐��x
			CLIP_DEFAULT_PRECIS,			// �N���b�s���O���x
			DEFAULT_QUALITY,			// �o�͕i��
			DEFAULT_PITCH | FF_DONTCARE,	// �s�b�`�ƃt�H���g�t�@�~��
			"�l�r �S�V�b�N"			// �t�H���g��
			//"�g�f�o�n�p�p�߯�ߑ�"
		);

		HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);

		/* �F��ς��� */
		COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));

		/* ������`���Ƃ��w�i������h��Ԃ��Ȃ��悤�ɂ��� */
		int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

		//�@������ł��Ȃ�΁A�t�H���g�̎�ނ�ݒ肷��̂��L�q����
		DrawTextA(hdc, textbool,caret_pos, &rc, DT_LEFT | DT_SINGLELINE | DT_VCENTER | DT_CALCRECT);
		
		//  �t�H���g�����Ƃɖ߂��@
		/* ���̐ݒ�ɖ߂� */
		::SelectObject(hdc, hfont_previous);
		::SetTextColor(hdc, color_previous);
		::SetBkMode(hdc, bkmode_previous);

		/* �����ō�����t�H���g�f�[�^���폜���� */
		::DeleteObject(hfont_normal);

		int text_width = rc.right - rc.left;
		// Rectangle�ōג�����`��`���ăL�����b�g��͕킷��@������
		::Rectangle(hdc, x + 0 + text_width, y + 4, x + 0 + 2 + text_width, (y + 4) + (h-8));
	}
	
	/* ���X�̃y����u���V�ɖ߂� */
	::SelectObject(hdc, hpen_previous);
	::SelectObject(hdc, hbrush_previous);

	/* �����ō�����y����u���V���폜���� */
	::DeleteObject(hpen_normal);
	::DeleteObject(hpen_pressed);
	::DeleteObject(hpen_disabled);
	::DeleteObject(hbrush_normal);
	::DeleteObject(hbrush_pressed);
	::DeleteObject(hbrush_disablede);
}

void  graphics::DrawStandardLine(HDC hdc, int x, int y, int w, int h) {
	/* �y����u���V��p�ӂ��� */
	HPEN hpen_normal = ::CreatePen(PS_DASHDOT, 1, RGB(0xff, 0x00, 0x00));
	HBRUSH hbrush_normal = ::CreateSolidBrush(RGB(0xff, 0xff, 0xff));

	/* ���X�̃y����u���V��ϐ��ɓ���Ďc���Ă��� */
	HPEN   hpen_previous = (HPEN)::SelectObject(hdc, hpen_normal);
	HBRUSH hbrush_previous = (HBRUSH)::SelectObject(hdc, hbrush_normal);

	/* �����ɍ��킹�ă{�^���̊G��`�� */

		::Rectangle(hdc, x, y, x + w, y + h);
		::MoveToEx(hdc, 100, 400, NULL);
		::LineTo(hdc, 100+x*10, 400+y*10);


	/* ���X�̃y����u���V�ɖ߂� */

	::SelectObject(hdc, hpen_previous);
	::SelectObject(hdc, hbrush_previous);


	/* �����ō�����y����u���V���폜���� */

	::DeleteObject(hpen_normal);
	::DeleteObject(hbrush_normal);
}

void  graphics::PaintBitmapFromFile(HDC hdc, int x, int y, int w, int h, const char* path)
{
	// 2022_02_22�ǉ���
	/* �t�@�C������摜�f�[�^����荞�� */

	// �������LoadImageA
	HBITMAP hbmp_sample = (HBITMAP)::LoadImageA(NULL, path,
	IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);

	/* �o�͐�ƌ݊����̂���DC�������P�p�ӂ��ĉ摜�f�[�^�ƕR�Â��� */
	//�@DC���m�Ńf�[�^�̂��������Ȃ��Ƃ��߂��ۂ��H

	HDC hdc_image = ::CreateCompatibleDC(hdc);
	HBITMAP hbmp_previous = (HBITMAP)::SelectObject(hdc_image, hbmp_sample);

	/* DC�Ԃŉ摜�f�[�^��]�ʂ��� */

	::BitBlt(hdc, x, y, w, h, hdc_image, 0, 0, SRCCOPY); // 120, 120���摜�ɍ��킹��

	/* DC���폜���� */

	::SelectObject(hdc_image, hbmp_previous);
	::DeleteDC(hdc_image);

	/* �摜�f�[�^���폜���� */

	::DeleteObject(hbmp_sample);

}

void  graphics::PaintBitmapFromFile(HDC hdc, int x, int y, int w, int h, const wchar_t* path)
{
	// �������LoadImageW
	HBITMAP hbmp_sample = (HBITMAP)::LoadImageW(NULL, path,
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);

	/* �o�͐�ƌ݊����̂���DC�������P�p�ӂ��ĉ摜�f�[�^�ƕR�Â��� */
	//�@DC���m�Ńf�[�^�̂��������Ȃ��Ƃ��߂��ۂ��H

	HDC hdc_image = ::CreateCompatibleDC(hdc);
	HBITMAP hbmp_previous = (HBITMAP)::SelectObject(hdc_image, hbmp_sample);

	/* DC�Ԃŉ摜�f�[�^��]�ʂ��� */

	::BitBlt(hdc, x, y, w, h, hdc_image, 0, 0, SRCCOPY); // 120, 120���摜�ɍ��킹��

	/* DC���폜���� */

	::SelectObject(hdc_image, hbmp_previous);
	::DeleteDC(hdc_image);

	/* �摜�f�[�^���폜���� */

	::DeleteObject(hbmp_sample);
}

/// <summary>�W���I�ȏ����ŕ������`�悷��</summary>
void  graphics::DrawStandardText(HDC hdc, int x, int y, int w, int h, const char* text)
{
	/* �t�H���g�f�[�^��p�ӂ��� */

	HFONT hfont_normal = ::CreateFont(
		16,					// �����̍���[�_���P��]
		0,					// �����̕��i0���w�肷��ƕ����̍�������ɂ��Ď������肳���j
		0,					// �������������X���̊p�x[0.1���P��]
		0,					// �x�[�X���C����X���̊p�x[0.1���P��]
		FW_NORMAL,				// ���̑���
		0,					// 0:�W�� / 1:�Α�
		0,					// 0:�W�� / 1:�����t��
		0,					// 0:�W�� / 1:�ł��������t��
		DEFAULT_CHARSET,			// �����Z�b�g
		OUT_DEFAULT_PRECIS,			// �o�͐��x
		CLIP_DEFAULT_PRECIS,			// �N���b�s���O���x
		DEFAULT_QUALITY,			// �o�͕i��
		DEFAULT_PITCH | FF_DONTCARE,	// �s�b�`�ƃt�H���g�t�@�~��
		"�l�r �S�V�b�N"			// �t�H���g��
	);

	HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);


	/* �F��ς��� */

	COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));
	
	/* ������`���Ƃ��w�i������h��Ԃ��Ȃ��悤�ɂ��� */

	int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

	/* ���������� */

	RECT text_area = { x, y, x + w, y + h };
	::DrawTextA(hdc, text, -1, &text_area, DT_LEFT);	// ���s����"\n"�̂Ƃ���ŉ��s�����


	/* ���̐ݒ�ɖ߂� */

	::SelectObject(hdc, hfont_previous);
	::SetTextColor(hdc, color_previous);
	::SetBkMode(hdc, bkmode_previous);

	/* �����ō�����t�H���g�f�[�^���폜���� */

	::DeleteObject(hfont_normal);
}

void  graphics::DrawStandardText(HDC hdc, int x, int y, int w, int h, const wchar_t* text)
{
	/* �t�H���g�f�[�^��p�ӂ��� */

	HFONT hfont_normal = ::CreateFont(
		16,					// �����̍���[�_���P��]
		0,					// �����̕��i0���w�肷��ƕ����̍�������ɂ��Ď������肳���j
		0,					// �������������X���̊p�x[0.1���P��]
		0,					// �x�[�X���C����X���̊p�x[0.1���P��]
		FW_NORMAL,				// ���̑���
		0,					// 0:�W�� / 1:�Α�
		0,					// 0:�W�� / 1:�����t��
		0,					// 0:�W�� / 1:�ł��������t��
		DEFAULT_CHARSET,			// �����Z�b�g
		OUT_DEFAULT_PRECIS,			// �o�͐��x
		CLIP_DEFAULT_PRECIS,			// �N���b�s���O���x
		DEFAULT_QUALITY,			// �o�͕i��
		DEFAULT_PITCH | FF_DONTCARE,	// �s�b�`�ƃt�H���g�t�@�~��
		"�l�r �S�V�b�N"			// �t�H���g��
	    //"�g�f�o�n�p�p�߯�ߑ�"
		);

	HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);


	/* �F��ς��� */

	COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));

	/* ������`���Ƃ��w�i������h��Ԃ��Ȃ��悤�ɂ��� */

	int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

	/* ���������� */

	RECT text_area = { x, y, x + w, y + h };
	::DrawTextW(hdc, text, -1, &text_area, DT_LEFT);	// ���s����"\n"�̂Ƃ���ŉ��s�����


	/* ���̐ݒ�ɖ߂� */

	::SelectObject(hdc, hfont_previous);
	::SetTextColor(hdc, color_previous);
	::SetBkMode(hdc, bkmode_previous);

	/* �����ō�����t�H���g�f�[�^���폜���� */

	::DeleteObject(hfont_normal);
}

/// <summary>�J�X�^�}�C�Y���������ŕ������`�悷��</summary>
void  graphics::DrawCustumizedText(HDC hdc, int x, int y, int w, int h, const char* text, int font_height)
{
	/* �t�H���g�f�[�^��p�ӂ��� */
	HFONT hfont_normal = ::CreateFont(
		font_height,					// �����̍���[�_���P��]
		0,					// �����̕��i0���w�肷��ƕ����̍�������ɂ��Ď������肳���j
		0,					// �������������X���̊p�x[0.1���P��]
		0,					// �x�[�X���C����X���̊p�x[0.1���P��]
		FW_NORMAL,				// ���̑���
		0,					// 0:�W�� / 1:�Α�
		0,					// 0:�W�� / 1:�����t��
		0,					// 0:�W�� / 1:�ł��������t��
		DEFAULT_CHARSET,			// �����Z�b�g
		OUT_DEFAULT_PRECIS,			// �o�͐��x
		CLIP_DEFAULT_PRECIS,			// �N���b�s���O���x
		DEFAULT_QUALITY,			// �o�͕i��
		DEFAULT_PITCH | FF_DONTCARE,	// �s�b�`�ƃt�H���g�t�@�~��
		"�l�r �S�V�b�N"			// �t�H���g��
		//"�g�f�o�n�p�p�߯�ߑ�"
	);

	HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);

	/* �F��ς��� */
	COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));

	/* ������`���Ƃ��w�i������h��Ԃ��Ȃ��悤�ɂ��� */
	int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

	/* ���������� */
	int padding = 0;// �ʒu�𒲐����₷���悤�Ƀp�f�B���O�͂O�ɂ���

	RECT text_area = { 
		x + padding,
		y + padding,
		x + w - padding,
		y + h - padding 
	};

	// �ʒu�𒲐����₷���悤�ɏc���������������i���s�����͖����j
	::DrawTextA(hdc, text, -1, &text_area, DT_LEFT| DT_VCENTER | DT_SINGLELINE);	// ���s����"\n"�̂Ƃ���ŉ��s�����

	/* ���̐ݒ�ɖ߂� */
	::SelectObject(hdc, hfont_previous);
	::SetTextColor(hdc, color_previous);
	::SetBkMode(hdc, bkmode_previous);

	/* �����ō�����t�H���g�f�[�^���폜���� */
	::DeleteObject(hfont_normal);
}

void  graphics::DrawCustumizedText(HDC hdc, int x, int y, int w, int h, const wchar_t* text, int font_height)
{
	/* �t�H���g�f�[�^��p�ӂ��� */

	HFONT hfont_normal = ::CreateFont(
		16,					// �����̍���[�_���P��]
		0,					// �����̕��i0���w�肷��ƕ����̍�������ɂ��Ď������肳���j
		0,					// �������������X���̊p�x[0.1���P��]
		0,					// �x�[�X���C����X���̊p�x[0.1���P��]
		FW_NORMAL,				// ���̑���
		0,					// 0:�W�� / 1:�Α�
		0,					// 0:�W�� / 1:�����t��
		0,					// 0:�W�� / 1:�ł��������t��
		DEFAULT_CHARSET,			// �����Z�b�g
		OUT_DEFAULT_PRECIS,			// �o�͐��x
		CLIP_DEFAULT_PRECIS,			// �N���b�s���O���x
		DEFAULT_QUALITY,			// �o�͕i��
		DEFAULT_PITCH | FF_DONTCARE,	// �s�b�`�ƃt�H���g�t�@�~��
		//"�l�r �S�V�b�N"			// �t�H���g��
		"�g�f�o�n�p�p�߯�ߑ�"
	);

	HFONT hfont_previous = (HFONT)::SelectObject(hdc, hfont_normal);

	/* �F��ς��� */

	COLORREF color_previous = ::SetTextColor(hdc, RGB(0x00, 0x00, 0x80));

	/* ������`���Ƃ��w�i������h��Ԃ��Ȃ��悤�ɂ��� */

	int bkmode_previous = ::SetBkMode(hdc, TRANSPARENT);

	/* ���������� */

	RECT text_area = { x, y, x + w, y + h };
	::DrawTextW(hdc, text, -1, &text_area, DT_LEFT);	// ���s����"\n"�̂Ƃ���ŉ��s�����

	/* ���̐ݒ�ɖ߂� */

	::SelectObject(hdc, hfont_previous);
	::SetTextColor(hdc, color_previous);
	::SetBkMode(hdc, bkmode_previous);

	/* �����ō�����t�H���g�f�[�^���폜���� */

	::DeleteObject(hfont_normal);
}
