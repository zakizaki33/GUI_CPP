#include <stdio.h>
#define OEMRESOURCE 
#include <windows.h>
#include "win32utility.h"
#include "callback.h"
#include "appmain.h"
#include "file.h"
#include "samplefunction.h"

// �N�����̃E�C���h�E�̑傫��
#define INIT_WINDOW_X 100
#define INIT_WINDOW_Y 100
#define INIT_WINDOW_W 800 //500
#define INIT_WINDOW_H 600 //400

// int �^��PIXEL�Ƃ���������������C���[�W
typedef int PIXEL;
PIXEL a = (int)10.1; // PIXEL ��int�Ȃ̂ŁA�����_������ƌx�����o��
PIXEL b = 9;

static HWND s_main_window_handle;

// appmain.cpp���̊֐��Ȃ̂Ńw�b�_�[�t�@�C���ɏ������݂̕K�v�Ȃ�
void FileAccessSample(const char* path)
{
	FILE* fp = NULL;

	// �t�@�C�����������ݗp�ɊJ��
	if (fopen_s(&fp, path, "w") == 0)
	{
		char input_data[] = "Hello, world!\n12345\ntesttest\n";

		// ���������������
		if (fp != 0) {
			fwrite(input_data, 1, strlen(input_data), fp);
		}
		// �t�@�C�������
		if (fp != 0) {
			fclose(fp);
		}
	}

	// �t�@�C����ǂݍ��ݗp�ɊJ��
	if (fopen_s(&fp, path, "r") == 0)
	{
		char data;

		for (; ; )
		{
			// �P�������ǂݍ���
			// �߂�l�͓ǂݍ��߂����ŁA���s�������_�Ń��[�v�𔲂���
			if (fp != 0) {
				if (fread(&data, 1, 1, fp) < 1)
				{
					break;
				}
				printf("%c", data);
			}
		}

		// �t�@�C�������
		if (fp != 0) {
			fclose(fp);
		}
	}
}

/// <summary>�E�B���h�E�̃n���h�����擾����</summary>
HWND  app::GetWindowHandle(void)
{
	return s_main_window_handle;
}

/// <summary>�E�B���h�E���ĕ`�悷��</summary>
void  app::RepaintWindow(void)
{
	::InvalidateRect(s_main_window_handle, NULL, TRUE);
	::UpdateWindow(s_main_window_handle);
}

/// <summary>���C���֐�</summary>
int WINAPI WinMain(
	_In_     HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_     LPSTR lpCmdLine,
	_In_     int nCmdShow
)
{
	CFile file("default.txt");
	
	// Debug�E�C���h�E�̕\��
	win32utl::ShowDebugConsole();

	/*
	CFile file1 = { "input.txt" }; //struct�̒��ɒ�`����Ă��鏇�Ԓʂ�ɒl�������Ă���

	if (file1.IsExist()) {
		printf("���̃t�@�C���͑��݂��܂�\n");
	}
	else
	{
		printf("���̃t�@�C���͑��݂��܂���\n");
	}
	*/

	// ����m�F�p�̃t�@�C���ǂݏo���֐�
	FileAccessSample("C:\\Users\\13273_Yamazaki\\source\\repos\\GUI_CPP\\GUI_CPP\\src\\input.txt");
	
	char class_name[] = "my_standard_window"; 

	WNDCLASSEX  window_class_settings = {
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,	/* ���T�C�Y�����Ƃ��ɍĕ`�悳���� */
		app::Procedure,
		0,
		0,
		hInstance,
		NULL,						/* �A�C�R��     */
		NULL,						/* �J�[�\��     */
		NULL,						/* �w�i�u���V   */
		NULL,						/* ���j���[�o�[ */
		class_name,
		NULL,						/* �A�C�R��(��) */
	};

	if( RegisterClassEx( &window_class_settings ) == 0 )
	{
		return 0;
	}

	// CreateWindow�֐��͂��̃E�C���h�E�̃n���h���i���O�D�݂����Ȃ��́H�j��Ԃ�
	HWND hwnd = CreateWindow(
		class_name,
		"�E�C���h�E�̃o�[�ɕ\����������������CreateWindow�ɋL�q",
		WS_OVERLAPPEDWINDOW,
		INIT_WINDOW_X,
		INIT_WINDOW_Y,
		INIT_WINDOW_W,			/* window width*/
		INIT_WINDOW_H,            /* window height*/
		NULL,			/* �e�E�B���h�E */
		NULL,			/* ���j���[�o�[ */
		hInstance,
		0				/* WM_CREATE��LPARAM */
	);

	if( hwnd == NULL )
	{
		return 0;
	}

	s_main_window_handle = hwnd;

	ShowWindow( hwnd, nCmdShow );

	
	// �t�@�C���_�C�A���O��\��������(���K)
	{
		// CFile file = { "c:\\soft\\*.*" };  // �ŏ��ɊJ���ꏊ
		CFile file = { "D:\\13273_Yamazaki\\Desktop\\*.*" };

		// if (file.SelectOpenFile(hwnd, "�e�L�X�g�t�@�C��\0*.txt\0�S�Ẵt�@�C��\0*.*\0"))
		if (file.SelectSaveFile(hwnd, "PDFfile\0*.pdf\0�e�L�X�g�t�@�C��\0*.txt\0�S�Ẵt�@�C��\0*.*\0")) //\0 �I�[����
		{
			printf("�t�@�C�����I������܂����B\n");
			// printf("%s\n", file.m_path); // private�͐G��Ȃ�
		}
		else
		{
			printf("�t�@�C���̑I���͒��f����܂����B\n");
		}
	}
	
	// samplefunction.h ���t�@�C���_�C�A���O���J��
	// SampleFunction();

	MSG msg;

	while( 0 < GetMessage( &msg, NULL, 0, 0 ) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	
	// Debug�E�C���h�E�̔�\��
	win32utl::HideDebugConsole();

	return 0;
}


