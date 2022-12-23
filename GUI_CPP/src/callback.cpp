#include <stdio.h>
#include <windows.h>
#include "callback.h"
#include "win32utility.h"
#include "mainform.h"

namespace app {
	// ��8��Q��
	static void OnPaint(HWND hwnd);
	static void OnMouse(int x, int y, bool pressed);
	static void OnKey(int key);
	static void OnChar(char c);
}

// static �֐��̓��ɂ���@���̊֐��́@callback.cpp�݂̂Ŏg���ꍇ�ɏ���
// Headerfile�ɂ͏����Ȃ��i���i�����ɏ悹�Ȃ��B���肩�猩���Ȃ�����j
// 
// <summary>�ĕ`��C�x���g�ɑ΂���R�[���o�b�N�֐�</summary>
static void app::OnPaint( HWND hwnd )
{
	
	// �}�`�������ꍇ�̓E�C���h�E�Ƃ͌���Ȃ��B�ق��Ƀv�����^�[�̏ꍇ������B
	HDC hdc_of_wnd = ::GetDC(hwnd);     //Global�̊֐��B���O�֐��ɑ��݂��Ă��Ȃ����̂�����B 
	                                    // ::�����ł��r���h�͒ʂ�B
	
	mainform::PaintAllItems(hdc_of_wnd);
										
										//	graphics::PaintStandardButton(hdc_of_wnd, 300, 150, 80, 60, true, false);
	//	graphics::PaintStandardButton(hdc_of_wnd, 400, 250, 80, 60, true, true);
	//	graphics::PaintStandardButton(hdc_of_wnd, 100, 200, 80, 60, false, true);

	//{ //�ϐ��̃R���g���[���͈͂�L�����p������ӊO�ɁA�����ʂŌ��₷������

	//  /* �@�y����u���V��p�ӂ��� */
	//	// �����B�y���̎�ށA���A�F
	//	HPEN hpen_blue = ::CreatePen(PS_DASHDOT, 1, RGB(0x00, 0x00, 0xff));
	//	HPEN hpen_gray = ::CreatePen(PS_SOLID, 3, RGB(0x66, 0x66, 0x66));
	//	HPEN hpen_red = ::CreatePen(PS_SOLID, 1, RGB(0xff, 0x00, 0x00));
	//	// �����B�h��Ԃ��̐F
	//	HBRUSH hbrush_sky_blue = ::CreateSolidBrush(RGB(0x00, 0xcc, 0xff));
	//	//HBRUSH hbrush_light_gray = ::CreateSolidBrush(RGB(0xcc, 0xcc, 0xcc));
	//	HBRUSH hbrush_light_gray = ::CreateSolidBrush(RGB(0xee, 0xee, 0xcc));
	//	HBRUSH hbrush_white = ::CreateSolidBrush(RGB(0xff, 0xff, 0xff));


	//	/* �A�f�o�C�X�R���e�L�X�g�Ƀy����u���V��K�p���� */
	//	/* �B���X�̃y����u���V��ϐ��ɓ���Ďc���Ă���   */
	//	// �����B�f�o�C�X�R���e�L�X�g�A�y��
	//	HPEN   hpen_previous = (HPEN)::SelectObject(hdc_of_wnd, hpen_blue);
	//	HBRUSH hbrush_previous = (HBRUSH)::SelectObject(hdc_of_wnd, hbrush_sky_blue);

	//
	//  
	//  /* �����`��`�� */

	//	::Rectangle(hdc_of_wnd, 10, 10, 120, 25);

	//	::Rectangle(hdc_of_wnd, 20, 75, 220, 150);

	//	/* �p���ۂ������`��`�� */
	//	/* �Ō���xy�Ŕ��a���w�肷�� */

	//	::SelectObject(hdc_of_wnd, hbrush_light_gray);
	//	::RoundRect(hdc_of_wnd, 10, 200, 150, 350, 45, 45);

	//	::SelectObject(hdc_of_wnd, hpen_gray);
	//	::SelectObject(hdc_of_wnd, hbrush_white);

	//	::RoundRect(hdc_of_wnd, 30, 220, 130, 330, 10, 10);


	//	/* ������`�� */

	//	::MoveToEx(hdc_of_wnd, 20, 30, NULL); /*�X�^�[�g�ݒ�. �Ō�͊�{��NULL*/

	//	::LineTo(hdc_of_wnd, 200, 250);
	//	::SelectObject(hdc_of_wnd, hpen_red);
	//	::LineTo(hdc_of_wnd, 200, 200);

	//	::LineTo(hdc_of_wnd, 350, 250);

	//	/* �_��`�� */

	//	for (int i = 0; i < 100; i++)

	//	{

	//		int x = 400;

	//		int y = 30 + 2 * i;

	//		//::SetPixelV(hdc_of_wnd, x, y, RGB(0xff, 0x00, 0x00));
	//		::SetPixelV(hdc_of_wnd, x, y, RGB(255, 0, 0));

	//		/* RGB�ŃJ���[�R�[�h���Ă���B�����ł�define�}�N��*/

	//	}
	//	/* �C���X�̃y����u���V�ɖ߂� */

	//	::SelectObject(hdc_of_wnd, hpen_previous);
	//	::SelectObject(hdc_of_wnd, hbrush_previous);


	//	/* �D�����ō�����y����u���V���폜���� */

	//	::DeleteObject(hpen_blue);
	//	::DeleteObject(hpen_gray);
	//	::DeleteObject(hpen_red);

	//	::DeleteObject(hbrush_sky_blue);
	//	::DeleteObject(hbrush_light_gray);
	//	::DeleteObject(hbrush_white);
	//}

	// ::ReleaseDC ::�͓���̖��O��Ԃɑ����Ă��Ȃ����Ƃ������i�O���[�o���I�Ӗ��j
	::ReleaseDC(hwnd, hdc_of_wnd);  // �ԋp����

	::ValidateRect(hwnd, NULL);     //��ʏ�������
}


/// <summary>�}�E�X���̓C�x���g�ɑ΂���R�[���o�b�N�֐�</summary>
static void app::OnMouse(int x, int y , bool pressed)
{
	// printf( "Hello.\n" );
	printf("X ���W�@�� %d ", x);
	printf("Y ���W�@�� %d \n", y);

	if (pressed==true){
		mainform::PressButtonAt(x,y);
	}
	else {
		mainform::ReleaseButtons();
	}
}


/// <summary>�L�[�{�[�h���̓C�x���g�ɑ΂���R�[���o�b�N�֐�</summary>
static void app::OnKey( int key )
{
	printf("OnKey���Ă΂�܂���\n");
	printf("%c ( %d )\n",key,key);
	switch (key)
	{
		case VK_RIGHT:mainform::MoveActiveTextBoxCareBy(+1); break;
		case VK_LEFT:mainform::MoveActiveTextBoxCareBy(-1); break;
		case VK_TAB:mainform::SelectNextTextBox(); break;
		case VK_BACK:mainform::BackSpace(); break;
		case VK_DELETE:mainform::Delete(); break;

	default: 
			/*
			if( ('0' <= key) && (key <= "9")){
				InsertCharacter((char)key);
			}
			*/
		break;
	}
	// mainform::MoveActiveTextBoxCareTo(14);
}

static void app::OnChar(char c)
{
	if (('0' <= c) && (c <= '9'))
	{
		mainform::InsertCharacter(c);
	}

	if (('a' <= c) && (c <= 'z'))
	{
		mainform::InsertCharacter(c);
	}

	if (('A' <= c) && (c <= 'Z'))
	{
		mainform::InsertCharacter(c);
	}
}

/// <summary>�C�x���g�v���V�[�W��</summary>
LRESULT CALLBACK app::Procedure( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp )
{	
	// printf("*");  // Procedure�֐����Ă΂ꑱ���Ă��邱�Ƃ��m�F���邽�߂̃R�[�h
	const UINT_PTR timer_id = 901;          // �^�C�}�[�̒ʂ��ԍ��ƂȂ�K���Ȑ���

	switch( msg )
	{
		case WM_CREATE:                   // WM_CREATE�C�x���g�̓E�B���h�E���\�������Ƃ��ɔ�������
			SetTimer(hwnd, timer_id, 1000, NULL); // 1000��1000msec
			break;

		case WM_TIMER:                    // SetTimer�̐ݒ�ɏ]���Ē���I��WM_TIMER����������
			printf("�^�C�}�[�����삵�܂���!!!\n");
			// graphics::PaintStandardTextBox ���Ăяo��???
			// ����Ȋ����H�H�H�@sw�����񏉊��������H
			/*
			boolean sw = true;
			if (sw == true) {
				/// ����
				sw = false;
			}
			else {
				/// ����
				sw = true;
			}
			*/

			break;
		
		//�@�����ł͓����O���[�v�̃����o�[���m�Ȃ̂ł��Ȃ��Ă�����
		case WM_PAINT :
			app::OnPaint(hwnd);
			break;

		case WM_LBUTTONDOWN :
		{   
			// case ���ł͕ϐ��������c��̂ŁA�X�R�[�v���͂����肳���āA�ϐ��̗L���͈͂����߂�
			int x = win32utl::GetMouseX(wp, lp);
			int y = win32utl::GetMouseY(wp, lp);
			app::OnMouse(x, y, true);
			break;
		}

		case WM_LBUTTONUP:
		{   
			int x = win32utl::GetMouseX(wp, lp);
			int y = win32utl::GetMouseY(wp, lp);
			app::OnMouse(x, y, false);
			break;
		}
		
		case WM_KEYDOWN :
		{
			int keycode = win32utl::GetKeyCode(wp, lp);
			app::OnKey(keycode);
			break;
		}

		case WM_CHAR:
		{
			char c = (char)win32utl::GetKeyCode(wp, lp);
			app::OnChar(c);
			break;
		}

		case WM_DESTROY :
			//�����o�[�ɏ������Ă��Ȃ��O���[�o����ǂݏo���Ӗ�
			::PostQuitMessage( 0 );
			break;
	}

	return DefWindowProc( hwnd, msg, wp, lp );
}
