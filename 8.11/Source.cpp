#include <windows.h>
#include <tchar.h>
#include "resource.h"

int score = 0;
HWND hButton1;
HWND hButton2;
HWND hButton3;
HWND hButton4;
HWND hButton5;
HWND hButton6;
HWND hButton7;
HWND hButton8;
HWND hButton9;
HWND hButton10;
HWND hButton11;
HWND hButton12;
HWND hEdit1;
HWND hEdit2;
HWND hEdit3;
HWND hEdit4;

TCHAR edit1[50], edit2[50], edit3[50], edit4[50];

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	// создаём главное окно приложения на основе модального диалога
	return  DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp)
{
	switch (message)
	{
	case WM_INITDIALOG:
		hButton1 = GetDlgItem(hWnd, IDC_RADIO2);
		hButton2 = GetDlgItem(hWnd, IDC_RADIO5);
		hButton3 = GetDlgItem(hWnd, IDC_RADIO8);
		hButton4 = GetDlgItem(hWnd, IDC_RADIO10);
		hButton5 = GetDlgItem(hWnd, IDC_RADIO15);
		hButton6 = GetDlgItem(hWnd, IDC_RADIO16);
		hButton7 = GetDlgItem(hWnd, IDC_RADIO23);
		hButton8 = GetDlgItem(hWnd, IDC_RADIO28);
		hButton9 = GetDlgItem(hWnd, IDC_CHECK5);
		hButton10 = GetDlgItem(hWnd, IDC_CHECK6);
		hButton11 = GetDlgItem(hWnd, IDC_CHECK8);
		hButton12 = GetDlgItem(hWnd, IDC_CHECK9);
		hEdit1 = GetDlgItem(hWnd, IDC_EDIT1);
		hEdit2 = GetDlgItem(hWnd, IDC_EDIT2);
		hEdit3 = GetDlgItem(hWnd, IDC_EDIT3);
		hEdit4 = GetDlgItem(hWnd, IDC_EDIT4);
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wp) == IDC_BUTTON1)
		{
			LRESULT lResult1 = SendMessage(hButton1, BM_GETCHECK, 0, 0);
			LRESULT lResult2 = SendMessage(hButton2, BM_GETCHECK, 0, 0);
			LRESULT lResult3 = SendMessage(hButton3, BM_GETCHECK, 0, 0);
			LRESULT lResult4 = SendMessage(hButton4, BM_GETCHECK, 0, 0);
			LRESULT lResult5 = SendMessage(hButton5, BM_GETCHECK, 0, 0);
			LRESULT lResult6 = SendMessage(hButton6, BM_GETCHECK, 0, 0);
			LRESULT lResult7 = SendMessage(hButton7, BM_GETCHECK, 0, 0);
			LRESULT lResult8 = SendMessage(hButton8, BM_GETCHECK, 0, 0);
			LRESULT lResult9 = SendMessage(hButton9, BM_GETCHECK, 0, 0);
			LRESULT lResult10 = SendMessage(hButton10, BM_GETCHECK, 0, 0);
			LRESULT lResult11 = SendMessage(hButton11, BM_GETCHECK, 0, 0);
			LRESULT lResult12 = SendMessage(hButton12, BM_GETCHECK, 0, 0);
			GetWindowText(hEdit1, edit1, 50);
			GetWindowText(hEdit2, edit2, 50);
			GetWindowText(hEdit3, edit3, 50);
			GetWindowText(hEdit4, edit4, 50);
			if (lResult1 == BST_CHECKED)
				score += 10;
			if (lResult2 == BST_CHECKED)
				score += 10;
			if (lResult3 == BST_CHECKED)
				score += 10;
			if (lResult4 == BST_CHECKED)
				score += 10;
			if (lResult5 == BST_CHECKED)
				score += 10;
			if (lResult6 == BST_CHECKED)
				score += 10;
			if (lResult7 == BST_CHECKED)
				score += 10;
			if (lResult8 == BST_CHECKED)
				score += 10;
			if (lResult9 == BST_CHECKED && lResult10 == BST_CHECKED)
			{
				LRESULT check1 = SendDlgItemMessage(hWnd, IDC_CHECK4, BM_GETCHECK, 0, 0);
				if (check1 != BST_CHECKED)
					score += 10;
			}
			if (lResult11 == BST_CHECKED && lResult12 == BST_CHECKED)
			{
				LRESULT check1 = SendDlgItemMessage(hWnd, IDC_CHECK7, BM_GETCHECK, 0, 0);
				if (check1 != BST_CHECKED)
					score += 10;
			}
			if (!lstrcmp(edit1, TEXT("Лондон")))
			{
				score+=10;
			}
			if (!lstrcmp(edit2, TEXT("Столетняя")))
			{
				score += 10;
			}
			if (!lstrcmp(edit3, TEXT("Печенье")))
			{
				score += 10;
			}
			if (!lstrcmp(edit4, TEXT("Голубой")))
			{
				score += 10;
			}
			TCHAR buf[50];
			wsprintf(buf, TEXT("Ваша оценка: %d"), score);
			MessageBox(hWnd, buf, TEXT("Результат"), MB_OK);
			score = 0;
		}
		return TRUE;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;
	}
	return FALSE;
}