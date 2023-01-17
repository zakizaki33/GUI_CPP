#ifndef INCLUDE_GRAPHICS_H
#define INCLUDE_GRAPHICS_H

#include <windows.h>

// struct CFile
class CFile
{
// 記述しないとデフォルトではpublic (class の時は逆)
private:
	char m_path[300];
public:
	CFile(const char* path);

	void SetPath(const char* path);
	const char* GetPath(void);

	bool IsExist(void);
	// void FileAccessSample(const char* path);

	/// <summary>ファイル選択ダイアログボックスを表示してパスを指定させる</summary>
	/// <param name="owner_handle">ダイアログボックスの親となるウィンドウのハンドル</param>
	/// <param name="filter">フィルターを表す文字列</param>
	/// <returns>true : 成功 / false : 失敗・中断</returns>
	bool  SelectOpenFile(HWND owner_handle, const char* filter);
	bool  SelectSaveFile(HWND owner_handle, const char* filter);
};

#endif   // INCLUDE_GRAPHICS_H