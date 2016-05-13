#include "MyForm.h"
#include <msclr\marshal_cppstd.h>
#include <string>
#include <algorithm>
#include <locale>
using namespace std;

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	�����������������::MyForm form;
	Application::Run(%form);
}

void EnglishCaesarEncrypt(string &text, int &caesarKey, unsigned char &newCaesarEnglishSymbol, int &i)
//���� ������ ��� ����������� �����
{
	if (((text[i] >= 'A') && (text[i] <= 'Z'))||((text[i] >= 'a') && (text[i] <= 'z'))){ 
	    newCaesarEnglishSymbol = text[i] + (caesarKey%26);
		if ((text[i] >= 'a') && (text[i] <= 'z')) {
			if (newCaesarEnglishSymbol> 'z')  newCaesarEnglishSymbol += -'z' + 'a' - 1; 
			if (newCaesarEnglishSymbol < 'a')  newCaesarEnglishSymbol += -'a' + 'z' + 1; 
		}
		if ((text[i] >= 'A') && (text[i] <= 'Z')) {
			if (newCaesarEnglishSymbol > 'Z') newCaesarEnglishSymbol += -'Z' + 'A' - 1;
			if (newCaesarEnglishSymbol < 'A') newCaesarEnglishSymbol += -'A' + 'Z' + 1;
		}
		text[i] = newCaesarEnglishSymbol;
	}
}
void RussianCaesarEncrypt(string &text, int &caesarKey, char &newCaesarRussianSymbol, int &i)
//���� ������ ��� �������� �����
{
	if (((text[i] >= '�') && (text[i] <= '�'))||((text[i] >= '�') && (text[i] <= '�'))){   
		newCaesarRussianSymbol = text[i] + (caesarKey%32);
		if ((text[i] >= '�') && (text[i] <= '�')) {
			if (newCaesarRussianSymbol > '�') newCaesarRussianSymbol += -'�' + '�' - 1;
			if (newCaesarRussianSymbol < '�') newCaesarRussianSymbol += -'�' + '�' + 1;
		}
		if ((text[i] >= '�') && (text[i] <= '�')) {
			if (newCaesarRussianSymbol > '�') newCaesarRussianSymbol+= -'�' + '�' - 1;
			if (newCaesarRussianSymbol < '�') newCaesarRussianSymbol += -'�' + '�' + 1;
		}	
		text[i] = newCaesarRussianSymbol;
	}
}
void EnglishVigenereEncrypt(string &vigenereKey, short int &newVigenereEnglishSymbol,unsigned int &j)
//���� �������� ��� ����������� �����
{
	if ((newVigenereEnglishSymbol >= 'A') && (newVigenereEnglishSymbol <= 'Z')) {
		newVigenereEnglishSymbol += toupper(vigenereKey[j]) - 'A';
		if (newVigenereEnglishSymbol > 'Z') newVigenereEnglishSymbol += -'Z' + 'A' - 1;
	}
	if ((newVigenereEnglishSymbol >= 'a') && (newVigenereEnglishSymbol <= 'z')) {
		newVigenereEnglishSymbol += vigenereKey[j] - 'a';
		if (newVigenereEnglishSymbol > 'z') newVigenereEnglishSymbol += -'z' + 'a' - 1;
	}	
}

void RussianVigenereEncrypt(string &vigenereKey, char &newVigenereRussianSymbol,unsigned int &j)
//���� �������� ��� �������� �����
{
	if ((newVigenereRussianSymbol >= '�') && (newVigenereRussianSymbol <= '�')) {
		newVigenereRussianSymbol += toupper(vigenereKey[j]) - '�' + 1;
		if (newVigenereRussianSymbol > '�') newVigenereRussianSymbol += -'�' + '�' - 1;
	}
	if ((newVigenereRussianSymbol >= '�') && (newVigenereRussianSymbol <= '�')) {
		newVigenereRussianSymbol += vigenereKey[j] - '�' + 1;
		if (newVigenereRussianSymbol > '�') newVigenereRussianSymbol += -'�' + '�' - 1;
	}
}
//	���������, ���������� �� ������� ����� � �������� ��������.
bool checkLanguage(char symForCheck, char firstAlphabetSym, char lastAlphabetSym) {
	char UpperFirst = toupper(firstAlphabetSym);
	char UpperLast = toupper(lastAlphabetSym);
	bool isUpper = ((symForCheck >= UpperFirst) && (symForCheck <= UpperLast));
	return (isUpper) || ((symForCheck >= firstAlphabetSym) && (symForCheck <= lastAlphabetSym));
}

namespace ����������������� {
System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//���� ������
		locale loc("Russian");
		unsigned char newCaesarEnglishSymbol; //�.�. char ������ �������������
		char newCaesarRussianSymbol; //�.�. char ����� ���� � ��������������
		if (!(((textBox3->Text[0] >= '1') && (textBox3->Text[0] <= '9'))||(textBox3->Text[0] == '-'))){
			MessageBox::Show("����������� ������ ����! ������� �����!");
		    textBox3->Clear();
		}
		else {
			int caesarKey= Convert::ToInt32(textBox3->Text);
			String^ text1 = textBox1->Text;
			string text = msclr::interop::marshal_as<string>(text1); //����������� system::string � std::string
			for (int i = 0; i < text.length(); i++) {
				if (isalpha(text[i], loc)) {          
					EnglishCaesarEncrypt(text,caesarKey,newCaesarEnglishSymbol,i);
					RussianCaesarEncrypt(text,caesarKey,newCaesarRussianSymbol,i);	
				}
			}
			textBox2->Text = gcnew String(text.c_str()); // ���������� � textBox2 system::string
		}	 
	}

System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//���� ��������
		locale loc("Russian");
		short int newVigenereEnglishSymbol;
		char newVigenereRussianSymbol;
		if (((textBox3->Text[0] >= '1') && (textBox3->Text[0] <= '9'))||(textBox3->Text[0] == '-')) {
			MessageBox::Show("����������� ������ ����! ������� �����!");
			textBox3->Clear();
		}
		else {
			String^ key1 = textBox3->Text;
			string vigenereKey = msclr::interop::marshal_as<string>(key1);
			String^ text1 = textBox1->Text;
			string text = msclr::interop::marshal_as<string>(text1);
			transform(vigenereKey.begin(), vigenereKey.end(), vigenereKey.begin(), ::tolower);
			unsigned int j = 0;
			 for (int i = 0; i < text.length(); i++) {
				 if (isalpha(text[i], loc)) {
					 if (checkLanguage(text[i], 'a', 'z')){
						 if (checkLanguage(vigenereKey[0], 'a', 'z')){
							newVigenereEnglishSymbol=text[i];
							EnglishVigenereEncrypt(vigenereKey,newVigenereEnglishSymbol,j);
						}
						else {
							MessageBox::Show("����������� ������ ����! ������� ���� �� ���������� �����!");
							textBox3->Clear();
							break;
						}
						text[i] = newVigenereEnglishSymbol;
					}
					 if (checkLanguage(text[i], '�', '�')){
						 if (checkLanguage(vigenereKey[0], '�', '�')){
							newVigenereRussianSymbol=text[i];
							RussianVigenereEncrypt(vigenereKey,newVigenereRussianSymbol,j);
						}
						else {
							MessageBox::Show("����������� ������ ����! ������� ���� �� ������� �����!");
							textBox3->Clear();
							break;
						}
						text[i] = newVigenereRussianSymbol;
					}
					
					j = (j + 1 == vigenereKey.length()) ? 0 : j + 1;
				 }
			 textBox2->Text = gcnew String(text.c_str()); 
			 }
		}
	}
}