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
	// メンバpathは勝手に探しに行ってくれる
	{
		return false;
	}
	else
	{
		if(fp!=0){
			fclose(fp);    // ファイルを閉じるのを忘れないように！
		}
		return true;
	}
}

/// <summary>ファイル選択ダイアログボックスを表示してパスを指定させる</summary>
/// <param name="owner_handle">ダイアログボックスの親となるウィンドウのハンドル</param>
/// <param name="filter">フィルターを表す文字列</param>
/// <returns>true : 成功 / false : 失敗・中断</returns>
bool  CFile::SelectOpenFile(HWND owner_handle, const char* filter)
{
	OPENFILENAMEA selector = {};

	//	char selected_file_name[300] = "";				// 選択されたファイルの名前だけを抜き出して取得したいときに使う

	selector.lStructSize = sizeof(OPENFILENAMEA);		// 構造体自身のサイズ
	selector.hwndOwner = owner_handle;				// ダイアログボックスの親となるウィンドウのハンドル
	selector.lpstrFilter = filter;					// フィルタを表す文字列
	selector.nFilterIndex = 1;							// 初期フィルタのインデックス（１から開始）／０ならlpstrCustomFilterを使う
	selector.lpstrFile = m_path;						// 選択されたファイルのパスの格納先となる配列／あらかじめ有効なパスを格納しておけば起動時にこのファイルが選択されている
	selector.nMaxFile = 300;						// 選択されたファイルのパスの格納先となる配列の大きさ（終端文字分を含む文字数）
//	selector.lpstrFileTitle    = selected_file_name;		// 選択されたファイルのファイル名の格納先となる配列
//	selector.nMaxFileTitle     = 300;						// 選択されたファイルのファイル名の格納先となる配列の大きさ（終端文字分を含む文字数）
	selector.lpstrInitialDir = "c:\\";					// ダイアログボックス起動時点で表示させたいディレクトリ（ただしlpstrFileが優先される）
	selector.lpstrTitle = "ファイルの選択";			// ダイアログボックスのタイトル
	selector.Flags = OFN_FILEMUSTEXIST;			// 存在するファイルしか選択できないという指定

	if (::GetOpenFileNameA(&selector) == 0)				// 戻り値は、成功なら０以外／キャンセルやエラーなら０
	{
		return false;
	}
	else
	{
		return true;
	}
}


/// <summary>ファイル選択ダイアログボックスを表示してパスを指定させる</summary>
/// <param name="owner_handle">ダイアログボックスの親となるウィンドウのハンドル</param>
/// <param name="filter">フィルターを表す文字列</param>
/// <returns>true : 成功 / false : 失敗・中断</returns>
bool  CFile::SelectSaveFile(HWND owner_handle, const char* filter)
{
	OPENFILENAMEA selector = {};

	//   char selected_file_name[300] = "";			// 選択されたファイルの名前だけを抜き出して取得したいときに使う

	selector.lStructSize = sizeof(OPENFILENAMEA);	// 構造体自身のサイズ
	selector.hwndOwner = owner_handle;		// ダイアログボックスの親となるウィンドウのハンドル
	selector.lpstrFilter = filter;			// フィルタを表す文字列
	selector.nFilterIndex = 1;				// 初期フィルタのインデックス（１から開始）／０ならlpstrCustomFilterを使う
	selector.lpstrFile = m_path;				// 選択されたファイルのパスの格納先となる配列／あらかじめ有効なパスを格納しておけば起動時にこのファイルが選択されている
	selector.nMaxFile = 300;				// 選択されたファイルのパスの格納先となる配列の大きさ（終端文字分を含む文字数）
//   selector.lpstrFileTitle    = selected_file_name;		// 選択されたファイルのファイル名の格納先となる配列
//   selector.nMaxFileTitle     = 300;				// 選択されたファイルのファイル名の格納先となる配列の大きさ（終端文字分を含む文字数）
	selector.lpstrInitialDir = "c:\\";			// ダイアログボックス起動時点で表示させたいディレクトリ（ただしlpstrFileが優先される）
	selector.lpstrTitle = "名前を付けて保存する";	// ダイアログボックスのタイトル
	selector.Flags = OFN_OVERWRITEPROMPT;	// 上書きする場合には確認メッセージを表示するという指定

	if (::GetSaveFileNameA(&selector) == 0)		// 戻り値は、成功なら０以外／キャンセルやエラーなら０
	{
		return false;
	}
	else
	{
		return true;
	}
}
