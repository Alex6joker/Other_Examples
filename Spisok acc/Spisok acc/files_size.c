#include <stdio.h>
#include "Empty_file.h"
#include <windows.h>

void files_size()
{
	FILE* file;
	int l,i;
	int m = 1; // ����������� �� ���� (0) ���, (1) ��
	char c;
	printf("--------------------------------------------------------------------------------");
	printf("    �� ������ ��������� ������� ������ � ������ � ���� ������(��) ��������\n");
	printf("--------------------------------------------------------------------------------");
	printf("\t���������� �� �������� ��� ������ ��������? ��(Y) ���(N)\n");
	printf("--------------------------------------------------------------------------------\n");
	c = getch();
	while(c!='Y' || c!='y')
	{
		if (c=='Y' || c=='y') break;
		if (c=='N' || c=='n') 
		{
			system("cls");
			return;
		}
		c = getch();
	}
	system("cls");
	file = fopen("Spisok #.txt","r");
	if (!file) 
	{
		m = 0;
		printf("������ ��� �������� ����� ��� ����� �� �� ����������\n");
		printf("����� ������ ����� ������ ���� �� #\n");
		printf("--------------------------------------------------------------------------------\n");
		system("pause");
		file = fopen("Spisok #.txt","w"); // ������� ������ ����
		fclose(file);
		file = fopen("Spisok #.txt","r");
	}
	fseek(file,0,SEEK_END);
	l = ftell(file); // ������ �����
	if (l!=0) l = 1; // ���� ���� �� ������, �� �������� ������������� �� 1
	switch(l)
	{
	case 0:
		fclose(file);
		if (m==1)
		{
			printf("���� �� # ����\n");
			printf("������� � ���� ������\n");
			printf("--------------------------------------------------------------------------------\n");
			system("pause");
		}
		vvod_empty_diez(); // ���� � ������ ����
		break;
	case 1:
		fclose(file);
		printf("--------------------------------------------------------------------------------\n");
		printf("���� ��� �������� # ��� �������� ������\n������� 1 ����� �������� ���� � ������ ����� ������ ���\n0 ��� ����������� ������\n");
		printf("--------------------------------------------------------------------------------\n");
		do
		{
		c = getch();
		__asm
		{
			xor ecx,ecx
			mov cl,c
			sub ecx,0x30
			xor eax,eax
			add eax,ecx
			mov i,eax
		}
		}while(i!=1 && i!=0);
		if (i==1) vvod_empty_diez(); 
		break;
	}
	file = fopen("Spisok bemol.txt","r");
	if (!file) 
	{
		m = 0;
		printf("--------------------------------------------------------------------------------");
		printf("������ ��� �������� ����� ��� ����� �� �� ����������\n");
		printf("����� ������ ����� ������ ���� �� ������\n");
		printf("--------------------------------------------------------------------------------");
		system("pause");
		file = fopen("Spisok bemol.txt","w"); // ������� ������ ����
		fclose(file);
		file = fopen("Spisok bemol.txt","r");
	}  
	fseek(file,0,SEEK_END);
	l = ftell(file);
	if (l!=0) l = 1;
	switch(l)
	{
	case 0:
		fclose(file);
		if (m==1)
		{
			printf("--------------------------------------------------------------------------------");
			printf("���� �� ������ ����\n");
			printf("������� � ���� ������\n");
			printf("--------------------------------------------------------------------------------\n");
			system("pause");
		}
		vvod_empty_bemol(); // ���� � ������ ����
		break;
	case 1:
		fclose(file);
		printf("--------------------------------------------------------------------------------\n");
		printf("���� ��� �������� ������ ��� �������� ������\n������� 1 ����� �������� ���� � ������ ����� ������ ���\n0 ��� ����������� ������\n");
		printf("--------------------------------------------------------------------------------\n");
		do
		{
		c = getch();
		__asm
		{
			xor ecx,ecx
			mov cl,c
			sub ecx,0x30
			xor eax,eax
			add eax,ecx
			mov i,eax
		}
		}while(i!=1 && i!=0);
		if (i==1) vvod_empty_bemol(); 
		break;
	}
	system("cls");
}