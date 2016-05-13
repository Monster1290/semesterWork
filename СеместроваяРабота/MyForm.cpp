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

	СеместроваяРабота::MyForm form;
	Application::Run(%form);
}

void EnglishCaesarEncrypt(string &text, int &caesarKey, unsigned char &newCaesarEnglishSymbol, int &i)
//Шифр Цезаря для английского языка
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
//Шифр Цезаря для русского языка
{
	if (((text[i] >= 'А') && (text[i] <= 'Я'))||((text[i] >= 'а') && (text[i] <= 'я'))){   
		newCaesarRussianSymbol = text[i] + (caesarKey%32);
		if ((text[i] >= 'А') && (text[i] <= 'Я')) {
			if (newCaesarRussianSymbol > 'Я') newCaesarRussianSymbol += -'Я' + 'А' - 1;
			if (newCaesarRussianSymbol < 'А') newCaesarRussianSymbol += -'А' + 'Я' + 1;
		}
		if ((text[i] >= 'а') && (text[i] <= 'я')) {
			if (newCaesarRussianSymbol > 'я') newCaesarRussianSymbol+= -'я' + 'а' - 1;
			if (newCaesarRussianSymbol < 'а') newCaesarRussianSymbol += -'а' + 'я' + 1;
		}	
		text[i] = newCaesarRussianSymbol;
	}
}
void EnglishVigenereEncrypt(string &vigenereKey, short int &newVigenereEnglishSymbol,unsigned int &j)
//Шифр Виженера для английского языка
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
//Шифр Виженера для русского языка
{
	if ((newVigenereRussianSymbol >= 'А') && (newVigenereRussianSymbol <= 'Я')) {
		newVigenereRussianSymbol += toupper(vigenereKey[j]) - 'А' + 1;
		if (newVigenereRussianSymbol > 'Я') newVigenereRussianSymbol += -'Я' + 'А' - 1;
	}
	if ((newVigenereRussianSymbol >= 'а') && (newVigenereRussianSymbol <= 'я')) {
		newVigenereRussianSymbol += vigenereKey[j] - 'а' + 1;
		if (newVigenereRussianSymbol > 'я') newVigenereRussianSymbol += -'я' + 'а' - 1;
	}
}
//	Проверяет, относиться ли входная буква к входному алфавиту.
bool checkLanguage(char symForCheck, char firstAlphabetSym, char lastAlphabetSym) {
	char UpperFirst = toupper(firstAlphabetSym);
	char UpperLast = toupper(lastAlphabetSym);
	bool isUpper = ((symForCheck >= UpperFirst) && (symForCheck <= UpperLast));
	return (isUpper) || ((symForCheck >= firstAlphabetSym) && (symForCheck <= lastAlphabetSym));
}

namespace СеместроваяРабота {
System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//Шифр Цезаря
		locale loc("Russian");
		unsigned char newCaesarEnglishSymbol; //т.к. char только положительные
		char newCaesarRussianSymbol; //т.к. char могут быть и отрицательными
		if (!(((textBox3->Text[0] >= '1') && (textBox3->Text[0] <= '9'))||(textBox3->Text[0] == '-'))){
			MessageBox::Show("Неправильно введен ключ! Введите число!");
		    textBox3->Clear();
		}
		else {
			int caesarKey= Convert::ToInt32(textBox3->Text);
			String^ text1 = textBox1->Text;
			string text = msclr::interop::marshal_as<string>(text1); //преобразует system::string в std::string
			for (int i = 0; i < text.length(); i++) {
				if (isalpha(text[i], loc)) {          
					EnglishCaesarEncrypt(text,caesarKey,newCaesarEnglishSymbol,i);
					RussianCaesarEncrypt(text,caesarKey,newCaesarRussianSymbol,i);	
				}
			}
			textBox2->Text = gcnew String(text.c_str()); // записывает в textBox2 system::string
		}	 
	}

System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//Шифр Виженера
		locale loc("Russian");
		short int newVigenereEnglishSymbol;
		char newVigenereRussianSymbol;
		if (((textBox3->Text[0] >= '1') && (textBox3->Text[0] <= '9'))||(textBox3->Text[0] == '-')) {
			MessageBox::Show("Неправильно введен ключ! Введите слово!");
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
							MessageBox::Show("Неправильно введен ключ! Введите ключ на английскоя языке!");
							textBox3->Clear();
							break;
						}
						text[i] = newVigenereEnglishSymbol;
					}
					 if (checkLanguage(text[i], 'а', 'я')){
						 if (checkLanguage(vigenereKey[0], 'а', 'я')){
							newVigenereRussianSymbol=text[i];
							RussianVigenereEncrypt(vigenereKey,newVigenereRussianSymbol,j);
						}
						else {
							MessageBox::Show("Неправильно введен ключ! Введите ключ на русском языке!");
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