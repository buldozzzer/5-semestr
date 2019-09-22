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
			cout << "Введите имя ключа: ";
			cin >> KeyName;
			char *KeyValue = new char[100];
			cout << "Введите значение ключа: ";
			cin >> KeyValue;
			// Ключ который будем создавать
			char szPath[] = "Software\\RegistrySample\\";

			HKEY hKey;

			// Создаем ключ в ветке HKEY_CURRENT_USER
			if (RegCreateKeyEx(HKEY_CURRENT_USER, szPath, 0, NULL, REG_OPTION_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) != ERROR_SUCCESS) {
				cout << "При создании ключа произошла ошибка" << endl;
			}

			// Пишем тестовую строку в созданный ключ
			if (RegSetValueEx(hKey, KeyName, 0, REG_SZ, (BYTE*)KeyValue, sizeof(KeyValue)) != ERROR_SUCCESS) {
				cout << "При записи строки произошла ошибка" << endl;
			}

			// Закрываем описатель ключа
			if (RegCloseKey(hKey) != ERROR_SUCCESS) {
				cout << "При закрытии ключа произошла ошибка" << endl;
			};

			CHAR szBuf[MAX_PATH];
			DWORD dwBufLen = MAX_PATH;

			if (RegGetValue(HKEY_CURRENT_USER, szPath, "Test String", RRF_RT_REG_SZ, NULL, (BYTE*)szBuf, &dwBufLen) != ERROR_SUCCESS) {
				cout << "При чтении строки произошла ошибка" << endl;
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