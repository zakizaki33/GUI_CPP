/************************************************************

	���C����ʂ𑀍삷�邽�߂̊֐�

************************************************************/
#include <stdio.h>
#include "appmain.h"
#include "mainform.h"
#include "graphics.h"
#include <string.h>
#include <windows.h>
#include "samplefunction.h"
#include <iostream>

namespace mainform
{
	/*** GUI�̍\�����i ***/

	/// <summary>GUI���i�̎���ID</summary>
	enum ID_CONTROL
	{
		IDC_BTN_XXX,
		IDC_BTN_YYY,
		IDC_BTN_ZZZ,

		IDC_TXT_AAA,
		IDC_TXT_BBB,
		IDC_TXT_CCC,
	};

	/// <summary>�{�^���̃f�[�^</summary>
	struct BUTTON_DATA
	{
		ID_CONTROL id;
		int x;
		int y;
		int w;
		int h;
		bool enabled;
		bool pressed;
		char caption[100]; //�I�[�����܂߂�100����
	};
	static BUTTON_DATA button_data_table[] = {
		{ IDC_BTN_XXX, 100, 100, 60, 40, true, false, "File�ǂݍ��݃_�C�A���O�\��" },
		{ IDC_BTN_YYY, 200, 100, 60, 40, true, false, "Func ��" },
		{ IDC_BTN_ZZZ, 300, 100, 60, 40, true, false, "Func ��" },
	};

	/// <summary>�e�L�X�g�{�b�N�X�̃f�[�^</summary>
	struct TEXTBOX_DATA
	{
		ID_CONTROL id;
		int x;
		int y;
		int w;
		int h;
		bool enabled;
		bool pressed;
		char caption[100];
		int caret_position;
		bool caret_SW;
	};
	static TEXTBOX_DATA textbox_data_table[] = {
		{ IDC_TXT_AAA, 400,   0, 200,  40, true, true,  "3", 10, true },
		{ IDC_TXT_BBB, 400,  50, 200,  40, true, false, "4", 5, true },
		{ IDC_TXT_CCC, 400, 100, 300, 400, true, false, "lensdata\nlensdata\n", 0, true },
	};

	/*** �A�v���P�[�V�����ŗL�̋@�\ ***/
	static void FunctionXXX(void);
	static void FunctionYYY(void);
	static void FunctionZZZ(void);
}

/// <summary>�S�Ă�GUI���i��`�悷��</summary>
void  mainform::PaintAllItems( HDC hdc )
{
	// ��ʂ𔒂��h��Ԃ�
	BitBlt(hdc, 0, 0, 1200, 1000, NULL, 0, 0, WHITENESS);
	
	for( int i = 0; i < 3; i++ )
	{
		graphics::PaintStandardButton(
			hdc,
			button_data_table[i].x,
			button_data_table[i].y,
			button_data_table[i].w,
			button_data_table[i].h,
			button_data_table[i].enabled,
			button_data_table[i].pressed
		);
		
		graphics::DrawStandardText(
			hdc,
			button_data_table[i].x,
			button_data_table[i].y,
			button_data_table[i].w,
			button_data_table[i].h,
			// "�����t�H���gabc \nABC 1234567890"
			button_data_table[i].caption
		);

/*
		int padding = 3;
		RECT text_area = {
			button_data_table[i].x + padding,
			button_data_table[i].y + padding,
			button_data_table[i].x + button_data_table[i].w - padding,
			button_data_table[i].y + button_data_table[i].h - padding
		};
		// ���s����"\n"�̂Ƃ���ŉ��s�����
		::DrawText(hdc, "abc \nABC 1234567890", -1, &text_area, DT_LEFT);
		// // ���ɍ��킹�Ď����I�ɉ��s�����
		::DrawText( hdc, "abc \nABC 1234567890", -1, &text_area, DT_LEFT | DT_WORDBREAK );
		// // �P�s�ŕ\�������i���������̈ʒu�����̎w��͂��̏ꍇ�ɂ̂ݗL���j
		::DrawText( hdc, "abc \nABC 1234567890", -1, &text_area, DT_LEFT | DT_VCENTER | DT_SINGLELINE );
*/
	}

	for (int i = 0; i < 3; i++)
	{
		graphics::PaintStandardTextBox(
			hdc,
			textbox_data_table[i].x,
			textbox_data_table[i].y,
			textbox_data_table[i].w,
			textbox_data_table[i].h,
			textbox_data_table[i].caption,
			textbox_data_table[i].enabled,
			textbox_data_table[i].pressed,
			textbox_data_table[i].caret_position,
			textbox_data_table[i].caret_SW
		);
	}
	char text_x[20];
	char text_y[20];
	char text_ave[20];

	sprintf_s(text_x, "      x : %d", GetCurrentX());
	sprintf_s(text_y, "      y : %d", GetCurrentY());
	sprintf_s(text_ave, "average : %d", GetCurrentAverage());

	graphics::DrawStandardText(hdc, 100, 200, 200, 40, text_x);
	graphics::DrawStandardText(hdc, 100, 240, 200, 40, text_y);
	graphics::DrawStandardText(hdc, 100, 280, 200, 40, text_ave);

	graphics::PaintStandardTextBox(hdc, 150, 320, 200, 30,"ABCDEFGHIJK" ,true, false, -1, true);

	// mainform���ɉ摜��\��������
	graphics::PaintBitmapFromFile(hdc, 240, 180, 120, 120, "C:\\Users\\13273_Yamazaki\\source\\repos\\GUI_CPP\\GUI_CPP\\src\\Default.bmp");

	// mainform���ɐ���\��������
	graphics::DrawStandardLine(hdc, 200, 400, 200, 50);
}

/// <summary>�w��ʒu�̃{�^��������</summary>
/// <remarks>��ԕω����̍ĕ`��ƃ{�^����������邱�Ƃɂ��@�\�̎��s���܂�</remarks>
void  mainform::PressButtonAt( int x, int y )
{
	for( int i = 0; i < 3; i++ )
	{
		if( x < button_data_table[i].x ){ continue; }
		if( y < button_data_table[i].y ){ continue; }
		if( button_data_table[i].x + button_data_table[i].w <= x ){ continue; }
		if( button_data_table[i].y + button_data_table[i].h <= y ){ continue; }

		// �{�^����OFF����ON�ɕς������c�c
		if( button_data_table[i].pressed == false )
		{
			button_data_table[i].pressed = true;

			app::RepaintWindow();

			switch( button_data_table[i].id )
			{
				case IDC_BTN_XXX : mainform::FunctionXXX(); break;
				case IDC_BTN_YYY : mainform::FunctionYYY(); break;
				case IDC_BTN_ZZZ : mainform::FunctionZZZ(); break;
				default : break;
			}
		}

		// �����ɕ����̃{�^�����������̂͂��������̂�
		// �P�ł��Y������{�^�����������ď�����������̓��[�v�𔲂���
		break;
	}
}

/// <summary>�S�Ẵ{�^����������Ă��Ȃ���Ԃɖ߂�</summary>
void  mainform::ReleaseButtons( void )
{
	bool  need_repaint = false;

	for( int i = 0; i < 3; i++ )
	{
		if( button_data_table[i].pressed == true )
		{
			button_data_table[i].pressed = false;
			need_repaint = true;
		}
	}

	if( need_repaint == true )
	{

		app::RepaintWindow();
	}
}

void mainform::MoveActiveTextBoxCareTo(int position){

	textbox_data_table[0].caret_position = position;

	app::RepaintWindow();

}

void mainform::MoveActiveTextBoxCareBy(int position) {

	int selected_textbox_index = -1;
	int textbox_count = 3;

	// ���I������Ă���e�L�X�g�{�b�N�X��T��
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			textbox_data_table[i].caret_position += position;
			break;
		}
	}
	app::RepaintWindow();
}

/// <summary>�J�[�\�������̃e�L�X�g�{�b�N�X�ֈړ�����</summary>
void  mainform::SelectNextTextBox(void)
{
	int selected_textbox_index = -1;
	int textbox_count = 3;

	// ���I������Ă���e�L�X�g�{�b�N�X��T��
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			selected_textbox_index = i;
			break;
		}
	}

	// ���ɑI������e�L�X�g�{�b�N�X�����߂�
	selected_textbox_index = (selected_textbox_index + 1) % textbox_count;

	// �e�e�L�X�g�{�b�N�X�̑I����Ԃ��Đݒ肷��
	for (int i = 0; i < textbox_count; i++)
	{
		if (i == selected_textbox_index)
		{
			textbox_data_table[i].pressed = true;
		}
		else
		{
			textbox_data_table[i].pressed = false;
		}
	}

	app::RepaintWindow();
}


/// <summary>�A�v���P�[�V�����ŗL�̋@�\</summary>
void  mainform::FunctionXXX( void )
{
	// printf( "�Z�Z�@�\�I\n" );
	// file�_�C�A���O���Ăяo���֐� 23-01-06
	SampleFunction();

	int n1 = atoi(textbox_data_table[0].caption);
	int n2 = atoi(textbox_data_table[1].caption);
	int n3 = atoi(textbox_data_table[2].caption);

	int n = n1 * n2 * n3;
	printf("%d\n", n);

	// samplefunction.h ��str_samplefunc���g���Ă݂�

	std::cout << "str_samplefunc START" << std::endl;
	std::cout << "std::cout���g���Ȃ�" << std::endl;
	std::cout << str_samplefunc << std::endl;
	std::cout << str_samplefunc.size() << std::endl;
	std::cout << "printf�ł���Ă݂�" << std::endl;
	printf("%s\n", str_samplefunc.c_str());
	std::cout << "END" << std::endl;

	std::string temp_str = str_samplefunc;
	std::cout << temp_str << std::endl;

	printf("%s\n", buffer2);

}

/// <summary>�A�v���P�[�V�����ŗL�̋@�\</summary>
void  mainform::FunctionYYY( void )
{
	printf( "�~�~�@�\�I\n" );
}

/// <summary>�A�v���P�[�V�����ŗL�̋@�\</summary>
void  mainform::FunctionZZZ( void )
{
	printf( "�����@�\�I\n" );
}

/// <summary>�I������Ă���e�L�X�g�{�b�N�X�֕�������͂���</summary>
void  mainform::InsertCharacter(char c)
{
	int textbox_count = 3;

	// ���I������Ă���e�L�X�g�{�b�N�X��T��
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			// �L�����b�g�̈ʒu�܂ł̕�����
			int position = textbox_data_table[i].caret_position;

			// �L�����b�g�̈ʒu�����Ƃ��č����̕���������
			char text1[300];
			strncpy_s(
				text1,										// �R�s�[��
				sizeof(text1),								// �R�s�[��̃T�C�Y�i�I�[�������܂߂ĉ������܂ŃR�s�[�ł��邩�j
				textbox_data_table[i].caption,				// �R�s�[��
				position 									// �R�s�[������������ ��
			);

			// �L�����b�g�̈ʒu�����Ƃ��ĉE���̕���������
			char text2[300];
			strncpy_s(
				text2,										// �R�s�[��
				sizeof(text2),								// �R�s�[��̃T�C�Y�i�I�[�������܂߂ĉ������܂ŃR�s�[�ł��邩�j
				textbox_data_table[i].caption + position,	// �R�s�[��
				_TRUNCATE									// �R�s�[�������������i_TRUNCATE���w�肵����c��S���j��
			);

			// �Ԃɕ�����ǉ����ď㏑������
			sprintf_s(textbox_data_table[i].caption, "%s%c%s", text1, c, text2);

			// �L�����b�g�̈ʒu��i�߂�
			textbox_data_table[i].caret_position++;

			break;
		}
	}
	app::RepaintWindow();
}

// �����폜(BackSpace)
void mainform::BackSpace(void) {

	int textbox_count = 3;

	// ���I������Ă���e�L�X�g�{�b�N�X��T��
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			// �L�����b�g�̈ʒu�܂ł̕�����
			int position = textbox_data_table[i].caret_position;
			// �������̔��f�����{
			if (1 <= position) {
				// �L�����b�g�̈ʒu�����Ƃ��č����̕���������
				char text1[300];
				strncpy_s(
					text1,										// �R�s�[��
					sizeof(text1),								// �R�s�[��̃T�C�Y�i�I�[�������܂߂ĉ������܂ŃR�s�[�ł��邩�j
					textbox_data_table[i].caption,				// �R�s�[��
					position - static_cast<unsigned __int64>(1)	// �R�s�[������������ �� 1�������炷
				);

				// �L�����b�g�̈ʒu�����Ƃ��ĉE���̕���������
				char text2[300];
				strncpy_s(
					text2,										// �R�s�[��
					sizeof(text2),								// �R�s�[��̃T�C�Y�i�I�[�������܂߂ĉ������܂ŃR�s�[�ł��邩�j
					textbox_data_table[i].caption + position,	// �R�s�[��
					_TRUNCATE									// �R�s�[�������������i_TRUNCATE���w�肵����c��S���j��
				);

				// �Ԃɕ�����ǉ����ď㏑������
				sprintf_s(textbox_data_table[i].caption, "%s%s", text1, text2);

				// �L�����b�g�̈ʒu��i�߂�
				textbox_data_table[i].caret_position--; // �ύX�_2022-12-20
			}
		break;
		}
	}
	app::RepaintWindow();
}

// �����폜(Delete)
void mainform::Delete(void) {

	int textbox_count = 3;

	// ���I������Ă���e�L�X�g�{�b�N�X��T��
	for (int i = 0; i < textbox_count; i++)
	{
		if (textbox_data_table[i].pressed)
		{
			// �L�����b�g�̈ʒu�܂ł̕�����
			int position = textbox_data_table[i].caret_position;
			// �������̔��f�����{
			if(position <strlen(textbox_data_table[i].caption))
			{
				// �L�����b�g�̈ʒu�����Ƃ��č����̕���������
				char text1[300];
				strncpy_s(
					text1,										// �R�s�[��
					sizeof(text1),								// �R�s�[��̃T�C�Y�i�I�[�������܂߂ĉ������܂ŃR�s�[�ł��邩�j
					textbox_data_table[i].caption,				// �R�s�[��
					position                                 	// �R�s�[������������
				);

				// �L�����b�g�̈ʒu�����Ƃ��ĉE���̕���������
				char text2[300];
				strncpy_s(
					text2,										// �R�s�[��
					sizeof(text2),								// �R�s�[��̃T�C�Y�i�I�[�������܂߂ĉ������܂ŃR�s�[�ł��邩�j
					textbox_data_table[i].caption + position + 1,	// �R�s�[��  �� 1�������ꂽ�ʒu����
					_TRUNCATE									// �R�s�[�������������i_TRUNCATE���w�肵����c��S���j��
				);

				// �Ԃɕ�����ǉ����ď㏑������
				sprintf_s(textbox_data_table[i].caption, "%s%s", text1, text2);

				// �L�����b�g�̈ʒu��i�߂�
				// textbox_data_table[i].caret_position; // �ύX�_2022-12-20
			}
		break;
		}
	}
	app::RepaintWindow();
}