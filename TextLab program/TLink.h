#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MaxLen 255

#include <string>
#include "TText.h"
#include <iostream>
using namespace std;

class TLink;
class TText;

class TTextMem
{
	TLink* pFirst, * pLast, * pFree;
	friend class TLink;
};

class TLink
{
public:
	char str[MaxLen];    // ������ ������
	TLink* pNext;        // ��������� �� ��������� ������ ������
	TLink* pDown;        // ��������� �� ����������
	static TTextMem MemHeader;   // ��� ���������� �������
	TLink(const char* s = NULL, TLink* pN = NULL, TLink* pD = NULL);
	~TLink();
	static void InitMem(int size);       // ������������� ������ 
	void* operator new(size_t size);     // ��������� �����
	void operator delete(void* p);       // ������������ �����
	static void MemCleaner(TText& txt, int& count);    // "������� ������"
	static void PrintFree();             // ������ ��������� �������
	int isAtom();                        // �������� ����������� ��������
};