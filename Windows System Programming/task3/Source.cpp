#include <iostream>
#include "Windows.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	char buf[100];
	char line[] = "Problem!?";
	DWORD bufer;
	HANDLE FileHandle1 = CreateFile("C:/Users/Ivan/Desktop/file1.txt", GENERIC_ALL, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE FileHandle2 = CreateFile("C:/Users/Ivan/Desktop/file2.txt", GENERIC_ALL, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD size = GetFileSize(FileHandle1, &size);
	ReadFile(FileHandle1, buf, size, &bufer, NULL);
	WriteFile(FileHandle2, buf, size, NULL, NULL);
	CloseHandle(FileHandle1);
	CloseHandle(FileHandle2);
	system("pause");
	return 0;
}