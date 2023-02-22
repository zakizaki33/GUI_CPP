#ifndef INCLUDE_SAMPLE_FUNCTION_H
#define INCLUDE_SAMPLE_FUNCTION_H
#include <string>

// 文字列を格納する変数を定義
static std::string str_samplefunc;
static char buffer2[100 + 1];

/// <summary>ファイルからデータを読み込んで画面に表示する一連の処理</summary>
void  SampleFunction(void );
void  SampleFunction(const char *);

/// <summary>現在の各数値を取得する</summary>
int  GetCurrentX( void );
int  GetCurrentY( void );
int  GetCurrentAverage( void );

#endif	// INCLUDE_SAMPLE_FUNCTION_H
