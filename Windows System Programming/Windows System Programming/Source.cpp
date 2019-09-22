#include <iostream>
#include "Windows.h"
#include "conio.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	LARGE_INTEGER start, end, time, frequency;
	int ch = _getch();
	if (ch != ' ') {
		while (true) {
			QueryPerformanceFrequency(&frequency);
			QueryPerformanceCounter(&start);
			int ch = _getch();
			QueryPerformanceCounter(&end);
			time.QuadPart = end.QuadPart - start.QuadPart;
			cout << time.QuadPart / frequency.QuadPart << endl;
			start.QuadPart = end.QuadPart;
			end.QuadPart += time.QuadPart;
			if (ch == ' ') break;

		}
	}
	system("pause");
	return 0;
}