#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>


using namespace std;

#define N 4096

int main(int argc, char** argv ) {
    long long t1, t2, freq;
	char str[N];
	unsigned lines=0;
	DWORD nRead;
	BOOL bResult;
	
	//if (argc == 1) 
    //{
     //   cerr << "Error: need text file\n";
      //  return 1;
    //}
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";

	HANDLE f = CreateFile(L"a.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// ����������� ����� ����� � 1 ���
	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// ������� ����� ����� ��������� �����
	
	do {
		bResult = ReadFile(f, str, N, &nRead, NULL);
		for( DWORD i = 0; i<nRead; ++i)
			if (str[i] == '\n')
				lines++;
	} while (!(bResult && nRead == 0));
	
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// ������� ����� ����� ��������� �����
	
	CloseHandle(f);

	
	
	cout << "\n Time spent:" << fixed << setprecision(3) << (t2-t1)/(1.*freq);
	cout << "\n " << lines << "lines\n";
	return 0;
}