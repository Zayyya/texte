#include "TText.h"
#include <clocale>
#include <string>
#include <iostream>
#include <fstream>

#include <vld.h>

using namespace std;

TTextMem TLink::MemHeader;

void main()
{
	try
	{
		setlocale(LC_ALL, "Rus");
		TLink::InitMem(100);
		TText t;
		string str;
		
		t.LoadText("txt.txt");
		int n;
		cout << "\t\t �������������� �������\n\n";
		do
		{
			cout << "������� ����� ��������:" << endl;
			cout << "1. ������� �� ����� ������� �����" << endl;
			cout << "2. ��������� ����� ����� �� �����" << endl;
			cout << "3. �������� ������ � ������ �������" << endl;
			cout << "4. �������� ������ � ������ �������" << endl;
			cout << "5. �������� ������ � ������ �������" << endl;
			cout << "6. �������� ������ � ������ �������" << endl;
			cout << "7. ������� ������ �� ������� ������" << endl;
			cout << "8. ������� ������ �� ������� ������" << endl;
			cout << "9. ������� ������ �� ������� ������" << endl;
			cout << "10. ������� ������ �� ������� ������" << endl;
			cout << "11. ������� ������� ������" << endl;
			cout << "12. �������� ������� ������" << endl;
			cout << "13. ������� ������ ��������� �������" << endl;
			cout << "14. ������� ������" << endl;
			cout << "15. ������� �� ������ �����" << endl;
			cout << "16. ������� �� ��������� �����" << endl;
			cout << "17. ������� �� ��������� �����" << endl;
			cout << "18. ������� �� ���������� �����" << endl;
			cout << "19. ��������� ����� � ����" << endl;
			cout << "20. �����" << endl;
			cin >> n;
			switch (n)
			{
			case 1: cout << endl;
				t.PrintText();
				break;

			case 2: cout << "������� ��� ��������� � �������:" << endl;
				cin.get();
				getline(cin, str);
				t.LoadText(str);
				break;

			case 3: cout << "������� �����, ������� ������ ��������:" << endl;
				cin.get();
				getline(cin, str);
				t.InsNextLine(str);
				cout << endl;
				t.PrintText();
				break;

			case 4: cout << "������� �����, ������� ������ ��������:" << endl;
				cin.get();
				getline(cin, str);
				t.InsDownLine(str);
				cout << endl;
				t.PrintText();
				break;

			case 5: cout << "������� �����, ������� ������ ��������:" << endl;
				cin.get();
				getline(cin, str);
				t.InsNextSection(str);
				cout << endl;
				t.PrintText();
				break;

			case 6: cout << "������� �����, ������� ������ ��������:" << endl;
				cin.get();
				getline(cin, str);
				t.InsDownSection(str);
				cout << endl;
				t.PrintText();
				break;

			case 7:	t.DelNextLine();
				cout << endl;
				t.PrintText();
				break;

			case 8: t.DelDownLine();
				cout << endl;
				t.PrintText();
				break;

			case 9:	t.DelNextSection();
				cout << endl;
				t.PrintText();
				break;

			case 10: t.DelDownSection();
				cout << endl;
				t.PrintText();
				break;

			case 11: cout << "������ ������:" << endl;
				cout << t.GetLine() << endl;
				break;

			case 12: cout << "������� �����, ������� ������ ��������:" << endl;
				cin.get();
				getline(cin, str);
				t.SetLine(str);
				cout << endl;
				t.PrintText();
				break;

			case 13: TLink::PrintFree();
				break;

			case 14: int k;
				TLink::MemCleaner(t, k);
				cout << "������� " << '(' << k << ')' << endl;
				break;

			case 15: t.GoFirstLink();
				break;

			case 16: t.GoNextLink();
				break;

			case 17: t.GoDownLink();
				break;

			case 18: t.GoPrevLink();
				break;

			case 19: cout << "������� ��� ���������, � ������� ������ ��������� �����:" << endl;
				cin.get();
				getline(cin, str);
				t.SaveText(str);
				break;

			case 20: break;

			default: cout << "������������ ����! ������� ����� �������� ������." << endl;
			}
			cout << endl;
		} while (n != 20);
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}