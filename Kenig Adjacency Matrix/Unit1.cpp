//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdio.h>
#include <conio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct schema
{
        int number;
        int circuit;
        schema* next;
        schema* prev;
}*head,*tail;
int counter_input=0; //������� �� ������ �������� ���������� �� �����
char* probel = "        ";
char* new_line = "\n";
AnsiString FileName ="";
char* MyFile;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{

	FILE* f0;
        int i = 0; //  ���� ��������� ��� �������� ������ AnsiString � char
        if(counter_input!=0) // ���� ��� ��� ����� �������
        {
                schema* temp;
                while(head!=NULL) // ������� ���������� ����� ������
                {
                        temp=head;
                        head=head->next;
                        free(temp);
                }
        }
        counter_input++;
	head = NULL;
	tail = NULL;
        if(OpenDialog1->Execute())   // ����� ���� �������� �����, ���� ��� ������ ���� - ��������� ������ ���� � �����
        {
                FileName = OpenDialog1->FileName;
        }
        MyFile = FileName.c_str(); // ������� Ansi � char* ����� ������� c_str()
	f0 = fopen(MyFile,"r");
        Memo1->Text="";
        Memo4->Text="";
        if(!f0)
        {
             Memo3->Text="������ �������� �����";
             return;
        }
        i = 0; // ������ �� fscanf
	while(!feof(f0))
	{
		schema* next_element;
		next_element = (struct schema*)malloc(sizeof(struct schema));
		next_element->next=head;
		next_element->prev=tail;
		if (head) head->prev = next_element;
		head=next_element;
		if (!tail) tail=head;
		i = fscanf(f0,"%d%d",&(next_element->number),&(next_element->circuit));
                if(i!=2)    //  ���� ������ ����������� � �������, �� ������� ������ � ������ �� �������
                {
                        schema* temp;
                        while(head!=NULL) // ������� ���������� ����� ������
                        {
                                temp=head;
                                head=head->next;
                                free(temp);
                        }
                        Memo3->Text="������ ��� ���������� ������ �� �����";
                        fclose(f0);
                        return;
                }
	}
	fclose(f0);
        if ((tail!=NULL) && (head!=NULL)) // ���� ���������� �� ����� ������� ���������
        {
                Memo3->Text="������ �� ����� ���� ������� ���������";
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        int z=0;
        schema* temp = tail;
        if(counter_input==0) // ���� �� ���� ������� �� ������ �������� ������
        {
                Memo4->Text="�� ���� ����������� �������� �� �����";
                return;
        }
        if (head==NULL)            //���� ��������� �����
        {
               Memo4->Text="��������� ���������� �����";
               return;
        }
        Memo4->Text="";
        while(head!=NULL)
        {
            if((temp==tail) && (z==1)) break;
            if((temp==tail) && (z==0)) z++;
            Memo4->Lines->Text=Memo4->Lines->Text+tail->number+" ";
            Memo4->Lines->Text=Memo4->Lines->Text+tail->circuit+new_line;
            tail = tail->prev;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
     Memo4->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
       Memo1->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int i,j;
        int mass[7][7];
	int z = 0;    // ������� ������� �� ���� ���������
        schema* tmp = head;
	schema* tmp_tail = tail;
        if(counter_input==0) // ���� �� ���� ������� �� ������ �������� ������
        {
                Memo1->Text="�� ���� ����������� �������� �� �����";
                return;
        }
        if(head==NULL)
        {
              Memo1->Lines->Text="������ �� ���� ���������";
              return;
        }
        Memo1->Text="";
	while(head!=NULL)
	{
		for(i=1;i<=7;i++)
		{
			for(j=1;j<=7;j++)
			{
				if ((i==tail->number) && (j==tail->circuit))
				{
					if((tail==tmp_tail) && (z!=0)) 
					{
						head = NULL;
						break; 
					}
					if((tail==tmp_tail) && (z==0)) z++;
					mass[i-1][j-1]=1;
					tail = tail->prev;
				}
				if(mass[i-1][j-1]!=1) mass[i-1][j-1]=0;
			}
		}
	}
        Memo1->Lines->Text=Memo1->Lines->Text+new_line;
	for(i=0;i<7;i++)                // �����
	{
                Memo1->Lines->Text=Memo1->Lines->Text+probel;
		for(j=0;j<7;j++)
                {
                        Memo1->Lines->Text=Memo1->Lines->Text+mass[i][j]+probel;
                }
                Memo1->Lines->Text=Memo1->Lines->Text+new_line;
	}
        head=tmp;
        tail=tmp_tail;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo3Change(TObject *Sender)
{
        Memo3->Alignment=taCenter;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
        schema* temp;
        while(head!=NULL) // ������� ���������� ����� ������
        {
                temp=head;
                head=head->next;
                free(temp);
        }
        Form1->Close();
}
//---------------------------------------------------------------------------


