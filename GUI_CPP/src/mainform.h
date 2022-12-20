/************************************************************

	メイン画面を操作するための関数

************************************************************/
#ifndef INCLUDE_MAIN_FORM_H
#define ICNLUDE_MAIN_FORM_H

#include <windows.h>

namespace mainform
{
	/// <summary>全てのGUI部品を描画する</summary>
	void  PaintAllItems( HDC hdc );

	/// <summary>指定位置のボタンを押す</summary>
	/// <remarks>状態変化時の再描画とボタンが押されることによる機能の実行を含む</remarks>
	void  PressButtonAt( int x, int y );

	/// <summary>全てのボタンを押されていない状態に戻す</summary>
	void  ReleaseButtons( void );

	void MoveActiveTextBoxCareTo(int position);

	void MoveActiveTextBoxCareBy(int position);

	void SelectNextTextBox(void);

	void InsertCharacter(char c);

	void BackSpace(void);



}

#endif
