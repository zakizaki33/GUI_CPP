#ifndef INCLUDE_SAMPLE_FUNCTION_H
#define INCLUDE_SAMPLE_FUNCTION_H
#include <string>

// ��������i�[����ϐ����`
extern std::string str_samplefunc;
static char buffer2[100 + 1];

/// <summary>�t�@�C������f�[�^��ǂݍ���ŉ�ʂɕ\�������A�̏���</summary>
void  SampleFunction(void );
const char* SampleFunction2(void);

/// <summary>���݂̊e���l���擾����</summary>
int  GetCurrentX( void );
int  GetCurrentY( void );
int  GetCurrentAverage( void );

#endif	// INCLUDE_SAMPLE_FUNCTION_H
