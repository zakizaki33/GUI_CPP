#ifndef INCLUDE_GRAPHICS_H
#define INCLUDE_GRAPHICS_H

#include <windows.h>

// struct CFile
class CFile
{
// �L�q���Ȃ��ƃf�t�H���g�ł�public (class �̎��͋t)
private:
	char m_path[300];
public:
	CFile(const char* path);

	void SetPath(const char* path);
	const char* GetPath(void);

	bool IsExist(void);
	// void FileAccessSample(const char* path);

	/// <summary>�t�@�C���I���_�C�A���O�{�b�N�X��\�����ăp�X���w�肳����</summary>
	/// <param name="owner_handle">�_�C�A���O�{�b�N�X�̐e�ƂȂ�E�B���h�E�̃n���h��</param>
	/// <param name="filter">�t�B���^�[��\��������</param>
	/// <returns>true : ���� / false : ���s�E���f</returns>
	bool  SelectOpenFile(HWND owner_handle, const char* filter);
	bool  SelectSaveFile(HWND owner_handle, const char* filter);
};

#endif   // INCLUDE_GRAPHICS_H