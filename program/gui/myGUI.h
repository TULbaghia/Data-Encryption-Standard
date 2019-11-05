#pragma once

#include "src/GUIHandler.h"
#include <iostream>

namespace DES_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for myGUI
	/// </summary>
	public ref class myGUI : public System::Windows::Forms::Form
	{
	public:
		GUIHandler guiHandler;
		myGUI(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~myGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::RadioButton^ radioButton7;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(9, 214);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(231, 35);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Wczytaj z pliku";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &myGUI::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 45);
			this->textBox1->MaxLength = 64;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(231, 62);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &myGUI::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Wprowadź klucz";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(6, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(84, 17);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"tekstu ASCII";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &myGUI::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 42);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(106, 17);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->Text = L"Heksadecymalny";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 65);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(60, 17);
			this->radioButton3->TabIndex = 5;
			this->radioButton3->Text = L"Binarny";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Location = System::Drawing::Point(9, 113);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(231, 95);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Klucz ma format";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(9, 258);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(231, 35);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Generuj klucz";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->groupBox1);
			this->groupBox2->Location = System::Drawing::Point(626, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(246, 316);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ustawienia klucza";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &myGUI::groupBox2_Enter);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->groupBox6);
			this->groupBox3->Controls->Add(this->groupBox5);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Location = System::Drawing::Point(13, 13);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(607, 315);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Szyfrowanie / Deszyfrowanie tekstu";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->radioButton7);
			this->groupBox6->Controls->Add(this->radioButton6);
			this->groupBox6->Location = System::Drawing::Point(371, 231);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(229, 75);
			this->groupBox6->TabIndex = 7;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Format danych wyjściowych";
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Checked = true;
			this->radioButton7->Location = System::Drawing::Point(6, 44);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(74, 17);
			this->radioButton7->TabIndex = 1;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"dane HEX";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(6, 23);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(79, 17);
			this->radioButton6->TabIndex = 0;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"dane ASCII";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->radioButton5);
			this->groupBox5->Controls->Add(this->radioButton4);
			this->groupBox5->Location = System::Drawing::Point(7, 231);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(229, 75);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Format danych wejściowych";
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(7, 44);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(74, 17);
			this->radioButton5->TabIndex = 1;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"dane HEX";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Checked = true;
			this->radioButton4->Location = System::Drawing::Point(7, 20);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(79, 17);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"dane ASCII";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(368, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Dane wyjściowe";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(6, 44);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(230, 180);
			this->textBox2->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Dane wejściowe";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(242, 271);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(123, 35);
			this->button5->TabIndex = 3;
			this->button5->Text = L"Deszyfruj";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(242, 230);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(123, 35);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Szyfruj";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(371, 44);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(230, 180);
			this->textBox3->TabIndex = 1;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button7);
			this->groupBox4->Controls->Add(this->button6);
			this->groupBox4->Location = System::Drawing::Point(12, 334);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(607, 215);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Szyfrowanie / Deszyfrowanie pliku";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(501, 174);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(100, 35);
			this->button7->TabIndex = 1;
			this->button7->Text = L"Deszyfruj";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(502, 133);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(100, 35);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Szyfruj";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &myGUI::saveFileDialog1_FileOk);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->AddExtension = false;
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->label6);
			this->groupBox7->Controls->Add(this->label5);
			this->groupBox7->Controls->Add(this->label4);
			this->groupBox7->Location = System::Drawing::Point(626, 448);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(246, 101);
			this->groupBox7->TabIndex = 12;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Autorzy:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(15, 75);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Panas Patryk";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(15, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(89, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Maksaida Michał";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Guzek Paweł";
			// 
			// myGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 561);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Name = L"myGUI";
			this->Text = L"DataEncryptionStandard - Kryptografia zadanie 1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void myGUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//string fileName = GUtil::getFilePath();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}



private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void saveFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
};
}
