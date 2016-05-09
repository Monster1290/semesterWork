#include <msclr\marshal_cppstd.h>
#include <string>
#include <algorithm>
#include <locale>
using namespace std;

#pragma once
locale loc("Russian");
unsigned char newEnglishSymbol; //�.�. char ������ �������������
char newRussianSymbol; //�.�. char ����� ���� � ��������������
char newSymbol;

void EnglishCaesarEncrypt(string &text, int &caesarKey, unsigned char &newEnglishSymbol, int &i)
//���� ������ ��� ����������� �����
{
	if (((text[i] >= 'A') && (text[i] <= 'Z'))||((text[i] >= 'a') && (text[i] <= 'z'))){ 
		while ((caesarKey>27)||(caesarKey<-27)){  
			if (caesarKey>27) caesarKey=caesarKey-26;
			if (caesarKey<-27) caesarKey=caesarKey+26;
		}
	    newEnglishSymbol = text[i] + caesarKey;
		if ((text[i] >= 'a') && (text[i] <= 'z')) {
			if (newEnglishSymbol > 'z')  newEnglishSymbol += -'z' + 'a' - 1; 
			if (newEnglishSymbol < 'a')  newEnglishSymbol += -'a' + 'z' + 1; 
		}
		if ((text[i] >= 'A') && (text[i] <= 'Z')) {
			if (newEnglishSymbol > 'Z') newEnglishSymbol += -'Z' + 'A' - 1;
			if (newEnglishSymbol < 'A') newEnglishSymbol += -'A' + 'Z' + 1;
		}
		text[i] = newEnglishSymbol;
	}
}
void RussianCaesarEncrypt(string &text, int &caesarKey, char &newRussianSymbol, int &i)
//���� ������ ��� �������� �����
{
	if (((text[i] >= '�') && (text[i] <= '�'))||((text[i] >= '�') && (text[i] <= '�'))){   
		while ((caesarKey>33)||(caesarKey<-33)){
			if (caesarKey>33) caesarKey=caesarKey-32;
			if (caesarKey<-33) caesarKey=caesarKey+32;
		}
		newRussianSymbol = text[i] + caesarKey;
		if ((text[i] >= '�') && (text[i] <= '�')) {
			if (newRussianSymbol > '�') newRussianSymbol += -'�' + '�' - 1;
			if (newRussianSymbol < '�') newRussianSymbol += -'�' + '�' + 1;
		}
		if ((text[i] >= '�') && (text[i] <= '�')) {
			if (newRussianSymbol > '�') newRussianSymbol+= -'�' + '�' - 1;
			if (newRussianSymbol < '�') newRussianSymbol += -'�' + '�' + 1;
		}	
		text[i] = newRussianSymbol;
	}
}
void EnglishVigenereEncrypt(string &vigenereKey, char &newSymbol,unsigned int &j)
{
	if (((newSymbol >= 'A') && (newSymbol <= 'Z'))||((newSymbol >= 'a') && (newSymbol <= 'z'))){
		if ((newSymbol >= 'A') && (newSymbol <= 'Z')) {
			newSymbol += toupper(vigenereKey[j]) - 'A';
			if (newSymbol > 'Z') newSymbol += -'Z' + 'A' - 1;
		 }
		if ((newSymbol >= 'a') && (newSymbol <= 'z')) {
			newSymbol += vigenereKey[j] - 'a';
			if (newSymbol > 'z') newSymbol += -'z' + 'a' - 1;
		 }
	}
}
void RussianVigenereEncrypt(string &vigenereKey, char &newSymbol,unsigned int &j)
{
	if (((newSymbol >= '�') && (newSymbol <= '�'))||((newSymbol >= '�') && (newSymbol <= '�'))){
		if ((newSymbol >= '�') && (newSymbol <= '�')) {
			newSymbol += toupper(vigenereKey[j]) - '�' + 1;
			if (newSymbol > '�') newSymbol += -'�' + '�' - 1;
		}
		if ((newSymbol >= '�') && (newSymbol <= '�')) {
			newSymbol += vigenereKey[j] - '�' + 1;
			if (newSymbol > '�') newSymbol += -'�' + '�' - 1;
		}
	}
}
namespace ����������������� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label3;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Garamond", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label3->Location = System::Drawing::Point(316, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 27);
			this->label3->TabIndex = 3;
			this->label3->Text = L"��������";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(21, 70);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(353, 244);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(395, 70);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(353, 244);
			this->textBox2->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Garamond", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(159, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 21);
			this->label1->TabIndex = 6;
			this->label1->Text = L"�����";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Garamond", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(471, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(210, 21);
			this->label2->TabIndex = 7;
			this->label2->Text = L"������������� �����";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(97, 327);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 31);
			this->button1->TabIndex = 9;
			this->button1->Text = L"���� ������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(97, 366);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(147, 34);
			this->button2->TabIndex = 10;
			this->button2->Text = L"���� ��������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(352, 334);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 18);
			this->label5->TabIndex = 13;
			this->label5->Text = L"����:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(321, 355);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(110, 20);
			this->textBox3->TabIndex = 14;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 417);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//���� ������
		if (!(((textBox3->Text[0] >= '1') && (textBox3->Text[0] <= '9'))||(textBox3->Text[0] == '-'))){
			MessageBox::Show("����������� ������� ������");
		    textBox3->Clear();
		}
		else {
			int caesarKey= Convert::ToInt32(textBox3->Text);
			String^ text1 = textBox1->Text;
			string text = msclr::interop::marshal_as<string>(text1); //����������� system::string � std::string
			for (int i = 0; i < text.length(); i++) {
				if (isalpha(text[i], loc)) {          
					EnglishCaesarEncrypt(text,caesarKey,newEnglishSymbol,i);
					RussianCaesarEncrypt(text,caesarKey,newRussianSymbol,i);	
				}
			}
			textBox2->Text = gcnew String(text.c_str()); // ���������� � textBox2 system::string
		}	 
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//���� ��������
		if (((textBox3->Text[0] >= '1') && (textBox3->Text[0] <= '9'))||(textBox3->Text[0] == '-')) {
			MessageBox::Show("����������� ������� ������");
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
				 newSymbol = text[i];
				 if (isalpha(newSymbol, loc)) {
					 EnglishVigenereEncrypt(vigenereKey,newSymbol,j);
					 RussianVigenereEncrypt(vigenereKey,newSymbol,j);
				     text[i] = newSymbol;
					 j = (j + 1 == vigenereKey.length()) ? 0 : j + 1;
				 }
			}
			textBox2->Text = gcnew String(text.c_str()); // ���������� � textBox2 system::string
		}
	}
};
}
