#include "file.h"
#include <stdio.h>
#include <string.h>
#include <Shlwapi.h>

CFile::CFile(const char* path) 
{
	strcpy_s(m_path, path);
}

void CFile::SetPath(const char* path) {
	// strcpy_s(m_path, path);
	PathCanonicalizeA(m_path, path);
}

const char* CFile::GetPath(void) {
	return m_path;
}

bool CFile::IsExist(void) 
{
	FILE* fp = NULL;

	if (fopen_s(&fp, m_path, "r") != 0)
	// �����opath�͏���ɒT���ɍs���Ă����
	{
		return false;
	}
	else
	{
		if(fp!=0){
			fclose(fp);    // �t�@�C�������̂�Y��Ȃ��悤�ɁI
		}
		return true;
	}
}

/// <summary>�t�@�C���I���_�C�A���O�{�b�N�X��\�����ăp�X���w�肳����</summary>
/// <param name="owner_handle">�_�C�A���O�{�b�N�X�̐e�ƂȂ�E�B���h�E�̃n���h��</param>
/// <param name="filter">�t�B���^�[��\��������</param>
/// <returns>true : ���� / false : ���s�E���f</returns>
bool  CFile::SelectOpenFile(HWND owner_handle, const char* filter)
{
	OPENFILENAMEA selector = {};

	//	char selected_file_name[300] = "";				// �I�����ꂽ�t�@�C���̖��O�����𔲂��o���Ď擾�������Ƃ��Ɏg��

	selector.lStructSize = sizeof(OPENFILENAMEA);		// �\���̎��g�̃T�C�Y
	selector.hwndOwner = owner_handle;				// �_�C�A���O�{�b�N�X�̐e�ƂȂ�E�B���h�E�̃n���h��
	selector.lpstrFilter = filter;					// �t�B���^��\��������
	selector.nFilterIndex = 1;							// �����t�B���^�̃C���f�b�N�X�i�P����J�n�j�^�O�Ȃ�lpstrCustomFilter���g��
	selector.lpstrFile = m_path;						// �I�����ꂽ�t�@�C���̃p�X�̊i�[��ƂȂ�z��^���炩���ߗL���ȃp�X���i�[���Ă����΋N�����ɂ��̃t�@�C�����I������Ă���
	selector.nMaxFile = 300;						// �I�����ꂽ�t�@�C���̃p�X�̊i�[��ƂȂ�z��̑傫���i�I�[���������܂ޕ������j
//	selector.lpstrFileTitle    = selected_file_name;		// �I�����ꂽ�t�@�C���̃t�@�C�����̊i�[��ƂȂ�z��
//	selector.nMaxFileTitle     = 300;						// �I�����ꂽ�t�@�C���̃t�@�C�����̊i�[��ƂȂ�z��̑傫���i�I�[���������܂ޕ������j
	selector.lpstrInitialDir = "c:\\";					// �_�C�A���O�{�b�N�X�N�����_�ŕ\�����������f�B���N�g���i������lpstrFile���D�悳���j
	selector.lpstrTitle = "�t�@�C���̑I��";			// �_�C�A���O�{�b�N�X�̃^�C�g��
	selector.Flags = OFN_FILEMUSTEXIST;			// ���݂���t�@�C�������I���ł��Ȃ��Ƃ����w��

	if (::GetOpenFileNameA(&selector) == 0)				// �߂�l�́A�����Ȃ�O�ȊO�^�L�����Z����G���[�Ȃ�O
	{
		return false;
	}
	else
	{
		return true;
	}
}


/// <summary>�t�@�C���I���_�C�A���O�{�b�N�X��\�����ăp�X���w�肳����</summary>
/// <param name="owner_handle">�_�C�A���O�{�b�N�X�̐e�ƂȂ�E�B���h�E�̃n���h��</param>
/// <param name="filter">�t�B���^�[��\��������</param>
/// <returns>true : ���� / false : ���s�E���f</returns>
bool  CFile::SelectSaveFile(HWND owner_handle, const char* filter)
{
	OPENFILENAMEA selector = {};

	//   char selected_file_name[300] = "";			// �I�����ꂽ�t�@�C���̖��O�����𔲂��o���Ď擾�������Ƃ��Ɏg��

	selector.lStructSize = sizeof(OPENFILENAMEA);	// �\���̎��g�̃T�C�Y
	selector.hwndOwner = owner_handle;		// �_�C�A���O�{�b�N�X�̐e�ƂȂ�E�B���h�E�̃n���h��
	selector.lpstrFilter = filter;			// �t�B���^��\��������
	selector.nFilterIndex = 1;				// �����t�B���^�̃C���f�b�N�X�i�P����J�n�j�^�O�Ȃ�lpstrCustomFilter���g��
	selector.lpstrFile = m_path;				// �I�����ꂽ�t�@�C���̃p�X�̊i�[��ƂȂ�z��^���炩���ߗL���ȃp�X���i�[���Ă����΋N�����ɂ��̃t�@�C�����I������Ă���
	selector.nMaxFile = 300;				// �I�����ꂽ�t�@�C���̃p�X�̊i�[��ƂȂ�z��̑傫���i�I�[���������܂ޕ������j
//   selector.lpstrFileTitle    = selected_file_name;		// �I�����ꂽ�t�@�C���̃t�@�C�����̊i�[��ƂȂ�z��
//   selector.nMaxFileTitle     = 300;				// �I�����ꂽ�t�@�C���̃t�@�C�����̊i�[��ƂȂ�z��̑傫���i�I�[���������܂ޕ������j
	selector.lpstrInitialDir = "c:\\";			// �_�C�A���O�{�b�N�X�N�����_�ŕ\�����������f�B���N�g���i������lpstrFile���D�悳���j
	selector.lpstrTitle = "���O��t���ĕۑ�����";	// �_�C�A���O�{�b�N�X�̃^�C�g��
	selector.Flags = OFN_OVERWRITEPROMPT;	// �㏑������ꍇ�ɂ͊m�F���b�Z�[�W��\������Ƃ����w��

	if (::GetSaveFileNameA(&selector) == 0)		// �߂�l�́A�����Ȃ�O�ȊO�^�L�����Z����G���[�Ȃ�O
	{
		return false;
	}
	else
	{
		return true;
	}
}
