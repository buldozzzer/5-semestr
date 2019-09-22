#include <iostream>
#include "Windows.h"
#include "conio.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	bool done = true;
	while (done)
	{
		printf("0 - Exit\n1 - Write value\n-->");
		char ch;
		cin >> ch;
		switch (ch) {
		case '0':
			done = false;
			break;
		case '1': {
			char *KeyName = new char[100];
			cout << "������� ��� �����: ";
			cin >> KeyName;
			char *KeyValue = new char[100];
			cout << "������� �������� �����: ";
			cin >> KeyValue;
			// ���� ������� ����� ���������
			char szPath[] = "Software\\RegistrySample\\";

			HKEY hKey;

			// ������� ���� � ����� HKEY_CURRENT_USER
			if (RegCreateKeyEx(HKEY_CURRENT_USER, szPath, 0, NULL, REG_OPTION_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) != ERROR_SUCCESS) {
				cout << "��� �������� ����� ��������� ������" << endl;
			}

			// ����� �������� ������ � ��������� ����
			if (RegSetValueEx(hKey, KeyName, 0, REG_SZ, (BYTE*)KeyValue, sizeof(KeyValue)) != ERROR_SUCCESS) {
				cout << "��� ������ ������ ��������� ������" << endl;
			}

			// ��������� ��������� �����
			if (RegCloseKey(hKey) != ERROR_SUCCESS) {
				cout << "��� �������� ����� ��������� ������" << endl;
			};

			CHAR szBuf[MAX_PATH];
			DWORD dwBufLen = MAX_PATH;

			if (RegGetValue(HKEY_CURRENT_USER, szPath, "Test String", RRF_RT_REG_SZ, NULL, (BYTE*)szBuf, &dwBufLen) != ERROR_SUCCESS) {
				cout << "��� ������ ������ ��������� ������" << endl;
			}
		}
			break;
		default:
			printf("Bad input!\n");
		}
	}
	system("pause");
	return 0;
}