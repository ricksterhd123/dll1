#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

typedef int __declspec(dllimport) (__cdecl* f_sum)(int a, int b);

int main() {
	int STATUS = 0;
	const WCHAR* path = L"./Dll1.dll";
	HINSTANCE p = LoadLibrary(path);

	if (!p) {
		cout << "Failed to find library" << endl;
		return EXIT_FAILURE;
	}

	cout << "Succesfully loaded library" << endl;

	f_sum sum = (f_sum)GetProcAddress(p, "sum");
	if (!sum) {
		cout << "Failed to find function 'sum'" << endl;
		FreeLibrary(p);
		return EXIT_FAILURE;
	}

	cout << "sum(4, 4) = " << sum(4, 4) << endl;

	if (!FreeLibrary(p)) {
		cout << "Failed to free library" << endl;
		return EXIT_FAILURE;
	}

	cout << "Succesfully freed library" << endl;
	return STATUS;
}
