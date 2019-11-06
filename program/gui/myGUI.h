#pragma once

#include <iostream>
#include "src/GUIUtils.h"
#include "src/GUIHandler.h"
#include <model\Encryption\DataStandardEncryption.h>
#include <model\helperFunctions.h>

using std::rand;

namespace DES_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class myGUI : public System::Windows::Forms::Form {
	public:
		GUIHandler guiHandler;
	private: System::Windows::Forms::Button^ moveOutToIn;
	private: System::Windows::Forms::Button^ keySaveToFileButton;
	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::TextBox^ fileOutTextBox;

	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::TextBox^ fileInTextBox;
	private: System::Windows::Forms::Button^ fileOutButton;


	private: System::Windows::Forms::Button^ fileInButton;
	private: System::Windows::Forms::Button^ fileMoveOutToIn;

	public:


	public:
		GUIUtils guiUtils;
		myGUI(void) {
			InitializeComponent();
		}

	protected:
		~myGUI() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ keyLoadFromFileButton;
	private: System::Windows::Forms::TextBox^ keyTextBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ keyRadioButton1;
	private: System::Windows::Forms::RadioButton^ keyRadioButton2;
	private: System::Windows::Forms::RadioButton^ keyRadioButton3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textInTextBox;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ textButtonDecrypt;

	private: System::Windows::Forms::Button^ textButtonEncrypt;

	private: System::Windows::Forms::TextBox^ textOutTextBox;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ fileButtonDecrypt;

	private: System::Windows::Forms::Button^ fileButtonEncrypt;

	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::RadioButton^ textOutRadio2;

	private: System::Windows::Forms::RadioButton^ textOutRadio1;

	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::RadioButton^ textInRadioButton2;


	private: System::Windows::Forms::RadioButton^ textInRadioButton1;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->keyLoadFromFileButton = (gcnew System::Windows::Forms::Button());
			this->keyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->keyRadioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->keyRadioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->keyRadioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->keySaveToFileButton = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->moveOutToIn = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->textOutRadio2 = (gcnew System::Windows::Forms::RadioButton());
			this->textOutRadio1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textInRadioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->textInRadioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textInTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textButtonDecrypt = (gcnew System::Windows::Forms::Button());
			this->textButtonEncrypt = (gcnew System::Windows::Forms::Button());
			this->textOutTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->fileMoveOutToIn = (gcnew System::Windows::Forms::Button());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->fileOutButton = (gcnew System::Windows::Forms::Button());
			this->fileOutTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->fileInButton = (gcnew System::Windows::Forms::Button());
			this->fileInTextBox = (gcnew System::Windows::Forms::TextBox());
			this->fileButtonDecrypt = (gcnew System::Windows::Forms::Button());
			this->fileButtonEncrypt = (gcnew System::Windows::Forms::Button());
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
			this->groupBox9->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->SuspendLayout();
			// 
			// keyLoadFromFileButton
			// 
			this->keyLoadFromFileButton->Location = System::Drawing::Point(9, 200);
			this->keyLoadFromFileButton->Name = L"keyLoadFromFileButton";
			this->keyLoadFromFileButton->Size = System::Drawing::Size(231, 35);
			this->keyLoadFromFileButton->TabIndex = 0;
			this->keyLoadFromFileButton->Text = L"Wczytaj z pliku";
			this->keyLoadFromFileButton->UseVisualStyleBackColor = true;
			this->keyLoadFromFileButton->Click += gcnew System::EventHandler(this, &myGUI::keyLoadFromFileButton_Click);
			// 
			// keyTextBox
			// 
			this->keyTextBox->Location = System::Drawing::Point(9, 45);
			this->keyTextBox->MaxLength = 64;
			this->keyTextBox->Multiline = true;
			this->keyTextBox->Name = L"keyTextBox";
			this->keyTextBox->Size = System::Drawing::Size(231, 62);
			this->keyTextBox->TabIndex = 1;
			this->keyTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->keyTextBox->TextChanged += gcnew System::EventHandler(this, &myGUI::keyTextBox_TextChanged);
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
			// keyRadioButton1
			// 
			this->keyRadioButton1->AutoSize = true;
			this->keyRadioButton1->Checked = true;
			this->keyRadioButton1->Location = System::Drawing::Point(6, 23);
			this->keyRadioButton1->Name = L"keyRadioButton1";
			this->keyRadioButton1->Size = System::Drawing::Size(78, 17);
			this->keyRadioButton1->TabIndex = 3;
			this->keyRadioButton1->TabStop = true;
			this->keyRadioButton1->Text = L"tekst ASCII";
			this->keyRadioButton1->UseVisualStyleBackColor = true;
			this->keyRadioButton1->CheckedChanged += gcnew System::EventHandler(this, &myGUI::keyRadioButton1_CheckedChanged);
			// 
			// keyRadioButton2
			// 
			this->keyRadioButton2->AutoSize = true;
			this->keyRadioButton2->Location = System::Drawing::Point(6, 46);
			this->keyRadioButton2->Name = L"keyRadioButton2";
			this->keyRadioButton2->Size = System::Drawing::Size(47, 17);
			this->keyRadioButton2->TabIndex = 4;
			this->keyRadioButton2->Text = L"HEX";
			this->keyRadioButton2->UseVisualStyleBackColor = true;
			this->keyRadioButton2->CheckedChanged += gcnew System::EventHandler(this, &myGUI::keyRadioButton2_CheckedChanged);
			// 
			// keyRadioButton3
			// 
			this->keyRadioButton3->AutoSize = true;
			this->keyRadioButton3->Enabled = false;
			this->keyRadioButton3->Location = System::Drawing::Point(6, 65);
			this->keyRadioButton3->Name = L"keyRadioButton3";
			this->keyRadioButton3->Size = System::Drawing::Size(43, 17);
			this->keyRadioButton3->TabIndex = 5;
			this->keyRadioButton3->Text = L"BIN";
			this->keyRadioButton3->UseVisualStyleBackColor = true;
			this->keyRadioButton3->Visible = false;
			this->keyRadioButton3->CheckedChanged += gcnew System::EventHandler(this, &myGUI::keyRadioButton3_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->keyRadioButton1);
			this->groupBox1->Controls->Add(this->keyRadioButton3);
			this->groupBox1->Controls->Add(this->keyRadioButton2);
			this->groupBox1->Location = System::Drawing::Point(9, 113);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(231, 75);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Klucz w formacie";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(9, 287);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(231, 35);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Generuj klucz";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &myGUI::button3_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->keySaveToFileButton);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->keyTextBox);
			this->groupBox2->Controls->Add(this->keyLoadFromFileButton);
			this->groupBox2->Controls->Add(this->groupBox1);
			this->groupBox2->Location = System::Drawing::Point(626, 13);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(246, 330);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ustawienia klucza";
			// 
			// keySaveToFileButton
			// 
			this->keySaveToFileButton->Location = System::Drawing::Point(9, 243);
			this->keySaveToFileButton->Name = L"keySaveToFileButton";
			this->keySaveToFileButton->Size = System::Drawing::Size(231, 35);
			this->keySaveToFileButton->TabIndex = 8;
			this->keySaveToFileButton->Text = L"Zapisz do pliku";
			this->keySaveToFileButton->UseVisualStyleBackColor = true;
			this->keySaveToFileButton->Click += gcnew System::EventHandler(this, &myGUI::keySaveToFileButton_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->moveOutToIn);
			this->groupBox3->Controls->Add(this->groupBox6);
			this->groupBox3->Controls->Add(this->groupBox5);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->textInTextBox);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->textButtonDecrypt);
			this->groupBox3->Controls->Add(this->textButtonEncrypt);
			this->groupBox3->Controls->Add(this->textOutTextBox);
			this->groupBox3->Location = System::Drawing::Point(13, 13);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(607, 330);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Szyfrowanie / Deszyfrowanie tekstu";
			// 
			// moveOutToIn
			// 
			this->moveOutToIn->Location = System::Drawing::Point(242, 190);
			this->moveOutToIn->Name = L"moveOutToIn";
			this->moveOutToIn->Size = System::Drawing::Size(123, 35);
			this->moveOutToIn->TabIndex = 8;
			this->moveOutToIn->Text = L"<---";
			this->moveOutToIn->UseVisualStyleBackColor = true;
			this->moveOutToIn->Click += gcnew System::EventHandler(this, &myGUI::moveOutToIn_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->textOutRadio2);
			this->groupBox6->Controls->Add(this->textOutRadio1);
			this->groupBox6->Location = System::Drawing::Point(371, 246);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(229, 75);
			this->groupBox6->TabIndex = 7;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Format danych wyjściowych";
			// 
			// textOutRadio2
			// 
			this->textOutRadio2->AutoSize = true;
			this->textOutRadio2->Checked = true;
			this->textOutRadio2->Location = System::Drawing::Point(6, 44);
			this->textOutRadio2->Name = L"textOutRadio2";
			this->textOutRadio2->Size = System::Drawing::Size(74, 17);
			this->textOutRadio2->TabIndex = 1;
			this->textOutRadio2->TabStop = true;
			this->textOutRadio2->Text = L"dane HEX";
			this->textOutRadio2->UseVisualStyleBackColor = true;
			this->textOutRadio2->CheckedChanged += gcnew System::EventHandler(this, &myGUI::textOutRadio2_CheckedChanged);
			// 
			// textOutRadio1
			// 
			this->textOutRadio1->AutoSize = true;
			this->textOutRadio1->Location = System::Drawing::Point(6, 23);
			this->textOutRadio1->Name = L"textOutRadio1";
			this->textOutRadio1->Size = System::Drawing::Size(79, 17);
			this->textOutRadio1->TabIndex = 0;
			this->textOutRadio1->TabStop = true;
			this->textOutRadio1->Text = L"dane ASCII";
			this->textOutRadio1->UseVisualStyleBackColor = true;
			this->textOutRadio1->CheckedChanged += gcnew System::EventHandler(this, &myGUI::textOutRadio1_CheckedChanged);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->textInRadioButton2);
			this->groupBox5->Controls->Add(this->textInRadioButton1);
			this->groupBox5->Location = System::Drawing::Point(7, 246);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(229, 75);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Format danych wejściowych";
			// 
			// textInRadioButton2
			// 
			this->textInRadioButton2->AutoSize = true;
			this->textInRadioButton2->Location = System::Drawing::Point(7, 44);
			this->textInRadioButton2->Name = L"textInRadioButton2";
			this->textInRadioButton2->Size = System::Drawing::Size(74, 17);
			this->textInRadioButton2->TabIndex = 1;
			this->textInRadioButton2->TabStop = true;
			this->textInRadioButton2->Text = L"dane HEX";
			this->textInRadioButton2->UseVisualStyleBackColor = true;
			this->textInRadioButton2->CheckedChanged += gcnew System::EventHandler(this, &myGUI::textInRadioButton2_CheckedChanged);
			// 
			// textInRadioButton1
			// 
			this->textInRadioButton1->AutoSize = true;
			this->textInRadioButton1->Checked = true;
			this->textInRadioButton1->Location = System::Drawing::Point(7, 20);
			this->textInRadioButton1->Name = L"textInRadioButton1";
			this->textInRadioButton1->Size = System::Drawing::Size(79, 17);
			this->textInRadioButton1->TabIndex = 0;
			this->textInRadioButton1->TabStop = true;
			this->textInRadioButton1->Text = L"dane ASCII";
			this->textInRadioButton1->UseVisualStyleBackColor = true;
			this->textInRadioButton1->CheckedChanged += gcnew System::EventHandler(this, &myGUI::textInRadioButton1_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(368, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Dane wyjściowe";
			// 
			// textInTextBox
			// 
			this->textInTextBox->Location = System::Drawing::Point(6, 40);
			this->textInTextBox->Multiline = true;
			this->textInTextBox->Name = L"textInTextBox";
			this->textInTextBox->Size = System::Drawing::Size(230, 195);
			this->textInTextBox->TabIndex = 0;
			this->textInTextBox->TextChanged += gcnew System::EventHandler(this, &myGUI::textInTextBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Dane wejściowe";
			// 
			// textButtonDecrypt
			// 
			this->textButtonDecrypt->Location = System::Drawing::Point(242, 286);
			this->textButtonDecrypt->Name = L"textButtonDecrypt";
			this->textButtonDecrypt->Size = System::Drawing::Size(123, 35);
			this->textButtonDecrypt->TabIndex = 3;
			this->textButtonDecrypt->Text = L"Deszyfruj";
			this->textButtonDecrypt->UseVisualStyleBackColor = true;
			this->textButtonDecrypt->Click += gcnew System::EventHandler(this, &myGUI::textButtonDecrypt_Click);
			// 
			// textButtonEncrypt
			// 
			this->textButtonEncrypt->Location = System::Drawing::Point(242, 240);
			this->textButtonEncrypt->Name = L"textButtonEncrypt";
			this->textButtonEncrypt->Size = System::Drawing::Size(123, 35);
			this->textButtonEncrypt->TabIndex = 2;
			this->textButtonEncrypt->Text = L"Szyfruj";
			this->textButtonEncrypt->UseVisualStyleBackColor = true;
			this->textButtonEncrypt->Click += gcnew System::EventHandler(this, &myGUI::textButtonEncrypt_Click);
			// 
			// textOutTextBox
			// 
			this->textOutTextBox->Location = System::Drawing::Point(371, 40);
			this->textOutTextBox->Multiline = true;
			this->textOutTextBox->Name = L"textOutTextBox";
			this->textOutTextBox->ReadOnly = true;
			this->textOutTextBox->Size = System::Drawing::Size(230, 195);
			this->textOutTextBox->TabIndex = 1;
			this->textOutTextBox->TextChanged += gcnew System::EventHandler(this, &myGUI::textOutTextBox_TextChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->fileMoveOutToIn);
			this->groupBox4->Controls->Add(this->groupBox9);
			this->groupBox4->Controls->Add(this->groupBox8);
			this->groupBox4->Controls->Add(this->fileButtonDecrypt);
			this->groupBox4->Controls->Add(this->fileButtonEncrypt);
			this->groupBox4->Location = System::Drawing::Point(13, 349);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(607, 200);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Szyfrowanie / Deszyfrowanie pliku";
			// 
			// fileMoveOutToIn
			// 
			this->fileMoveOutToIn->Location = System::Drawing::Point(169, 154);
			this->fileMoveOutToIn->Name = L"fileMoveOutToIn";
			this->fileMoveOutToIn->Size = System::Drawing::Size(140, 35);
			this->fileMoveOutToIn->TabIndex = 7;
			this->fileMoveOutToIn->Text = L"Wej <--- Wyj";
			this->fileMoveOutToIn->UseVisualStyleBackColor = true;
			this->fileMoveOutToIn->Click += gcnew System::EventHandler(this, &myGUI::fileMoveOutToIn_Click);
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->fileOutButton);
			this->groupBox9->Controls->Add(this->fileOutTextBox);
			this->groupBox9->Location = System::Drawing::Point(5, 92);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(596, 55);
			this->groupBox9->TabIndex = 6;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Plik wyjściowy";
			// 
			// fileOutButton
			// 
			this->fileOutButton->Location = System::Drawing::Point(555, 17);
			this->fileOutButton->Name = L"fileOutButton";
			this->fileOutButton->Size = System::Drawing::Size(35, 24);
			this->fileOutButton->TabIndex = 6;
			this->fileOutButton->Text = L"...";
			this->fileOutButton->UseVisualStyleBackColor = true;
			this->fileOutButton->Click += gcnew System::EventHandler(this, &myGUI::fileOutButton_Click);
			// 
			// fileOutTextBox
			// 
			this->fileOutTextBox->Location = System::Drawing::Point(6, 19);
			this->fileOutTextBox->Name = L"fileOutTextBox";
			this->fileOutTextBox->Size = System::Drawing::Size(543, 20);
			this->fileOutTextBox->TabIndex = 5;
			this->fileOutTextBox->TextChanged += gcnew System::EventHandler(this, &myGUI::fileOutTextBox_TextChanged);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->fileInButton);
			this->groupBox8->Controls->Add(this->fileInTextBox);
			this->groupBox8->Location = System::Drawing::Point(5, 28);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(596, 55);
			this->groupBox8->TabIndex = 4;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Plik wejściowy";
			// 
			// fileInButton
			// 
			this->fileInButton->Location = System::Drawing::Point(555, 17);
			this->fileInButton->Name = L"fileInButton";
			this->fileInButton->Size = System::Drawing::Size(35, 24);
			this->fileInButton->TabIndex = 6;
			this->fileInButton->Text = L"...";
			this->fileInButton->UseVisualStyleBackColor = true;
			this->fileInButton->Click += gcnew System::EventHandler(this, &myGUI::fileInButton_Click);
			// 
			// fileInTextBox
			// 
			this->fileInTextBox->Location = System::Drawing::Point(6, 19);
			this->fileInTextBox->Name = L"fileInTextBox";
			this->fileInTextBox->Size = System::Drawing::Size(543, 20);
			this->fileInTextBox->TabIndex = 5;
			this->fileInTextBox->TextChanged += gcnew System::EventHandler(this, &myGUI::fileInTextBox_TextChanged);
			// 
			// fileButtonDecrypt
			// 
			this->fileButtonDecrypt->Location = System::Drawing::Point(461, 154);
			this->fileButtonDecrypt->Name = L"fileButtonDecrypt";
			this->fileButtonDecrypt->Size = System::Drawing::Size(140, 35);
			this->fileButtonDecrypt->TabIndex = 1;
			this->fileButtonDecrypt->Text = L"Deszyfruj";
			this->fileButtonDecrypt->UseVisualStyleBackColor = true;
			this->fileButtonDecrypt->Click += gcnew System::EventHandler(this, &myGUI::fileButtonDecrypt_Click);
			// 
			// fileButtonEncrypt
			// 
			this->fileButtonEncrypt->Location = System::Drawing::Point(315, 154);
			this->fileButtonEncrypt->Name = L"fileButtonEncrypt";
			this->fileButtonEncrypt->Size = System::Drawing::Size(140, 35);
			this->fileButtonEncrypt->TabIndex = 0;
			this->fileButtonEncrypt->Text = L"Szyfruj";
			this->fileButtonEncrypt->UseVisualStyleBackColor = true;
			this->fileButtonEncrypt->Click += gcnew System::EventHandler(this, &myGUI::fileButtonEncrypt_Click);
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
			this->label5->Text = L"Maksajda Michał";
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
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void saveFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {}

	private: System::Void keyTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (keyTextBox->Text->Length < guiHandler.keyMaxLength) {
			keyTextBox->MaxLength = guiHandler.keyMaxLength;
		}
		if (keyRadioButton2->Checked) {
			String^ allowedChars = "0123456789AaBbCcDdEeFf";
			for (int i = 0; i < keyTextBox->Text->Length; i++) {
				bool isAllowed = false;
				for (int j = 0; j < allowedChars->Length; j++) {
					if (keyTextBox->Text[i] == allowedChars[j]) {
						isAllowed = true;
						break;
					}
				}
				if (!isAllowed) {
					keyTextBox->Text = keyTextBox->Text->Substring(0, i);
					keyTextBox->SelectionStart = keyTextBox->Text->Length;
				}
			}
		}
	}
	private: System::Void keyRadioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (keyRadioButton1->Checked) {
			string text = guiUtils.changeTextDisplayType(guiHandler.keyPreviousState, 1, guiUtils.sStringToString(keyTextBox->Text));
			guiHandler.keyMaxLength = 8;
			keyTextBox->Text = guiUtils.stringToSString(text);
			guiHandler.keyPreviousState = 1;
		}
	}
	private: System::Void keyRadioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (keyRadioButton2->Checked) {
			string text = guiUtils.changeTextDisplayType(guiHandler.keyPreviousState, 2, guiUtils.sStringToString(keyTextBox->Text));
			guiHandler.keyMaxLength = 16;
			keyTextBox->Text = guiUtils.stringToSString(text);
			guiHandler.keyPreviousState = 2;
		}
	}
	private: System::Void keyRadioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (keyRadioButton3->Checked) {
			string text = guiUtils.changeTextDisplayType(guiHandler.keyPreviousState, 3, guiUtils.sStringToString(keyTextBox->Text));
			guiHandler.keyMaxLength = 64;
			keyTextBox->Text = guiUtils.stringToSString(text);
			guiHandler.keyPreviousState = 3;
		}
	}
	private: System::Void keyLoadFromFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string fileName = guiUtils.getFilePath();
		if(fileName.length() > 0) {
			string fileText = guiUtils.readKeyFile(fileName);
			fileText = guiUtils.changeTextDisplayType(1, guiHandler.keyPreviousState, fileText);
			keyTextBox->Text = guiUtils.stringToSString(fileText);
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ allowedChars;
		if (keyRadioButton1->Checked) {
			allowedChars += "zxcvbnm,.asdfghjkl;qwertyuiop[]`1234567890-=~!@#$%^&*()_+}{POIUYTREWQASDFGHJKL:><MNBVCXZ?";
		} else if (keyRadioButton2->Checked) {
			allowedChars += "0123456789ABCDEF";
		}
		keyTextBox->Text = "";
		for (int i = 0; i < keyTextBox->MaxLength; i++) {
			keyTextBox->Text += allowedChars[rand()%allowedChars->Length];
		}
	}
	private: System::Void textInRadioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textInRadioButton1->Checked) {
			string text = guiUtils.changeTextDisplayType(guiHandler.textInPreviousState, 1, guiUtils.sStringToString(textInTextBox->Text));
			textInTextBox->Text = guiUtils.stringToSString(text);
			guiHandler.textInPreviousState = 1;
		}
	}
	private: System::Void textInRadioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textInRadioButton2->Checked) {
			string text = guiUtils.changeTextDisplayType(guiHandler.textInPreviousState, 2, guiUtils.sStringToString(textInTextBox->Text));
			textInTextBox->Text = guiUtils.stringToSString(text);
			guiHandler.textInPreviousState = 2;
		}
	}
	private: System::Void textInTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textOutRadio1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textOutRadio1->Checked) {
			string text = guiUtils.changeTextDisplayType(guiHandler.textOutPreviousState, 1, guiUtils.sStringToString(textOutTextBox->Text));
			textOutTextBox->Text = guiUtils.stringToSString(text);
			guiHandler.textOutPreviousState = 1;
		}
	}
	private: System::Void textOutRadio2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textOutRadio2->Checked) {
			string text = guiUtils.changeTextDisplayType(guiHandler.textOutPreviousState, 2, guiUtils.sStringToString(textOutTextBox->Text));
			textOutTextBox->Text = guiUtils.stringToSString(text);
			guiHandler.textOutPreviousState = 2;
		}
	}
	private: System::Void textOutTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void moveOutToIn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textOutTextBox->Text->Length > 0) {
			if (textOutRadio2->Checked) {
				textInRadioButton2->Checked = true;
			}
			if (textOutRadio1->Checked) {
				textInRadioButton1->Checked = true;
			}
			textInTextBox->Text = textOutTextBox->Text;
			textOutTextBox->Text = "";
		}
	}
	private: System::Void textButtonEncrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		Key key;
		string tkey = guiUtils.sStringToString(keyTextBox->Text);
		if (keyRadioButton2->Checked) {
			tkey = guiUtils.changeTextDisplayType(2, 1, tkey);
		}
		if (keyRadioButton3->Checked) {
			tkey = guiUtils.changeTextDisplayType(3, 1, tkey);
		}
		if (textInTextBox->Text->Length > 0 && textInTextBox->Text->Length > 0 && key.setKey(tkey)) {
			string pText = guiUtils.sStringToString(textInTextBox->Text);
			if (textInRadioButton2->Checked) {
				pText = guiUtils.changeTextDisplayType(2, 1, pText);
			}
			DataStandardEncryption des;
			string cText = des.encrypt(pText, key);
			textOutRadio2->Checked = true;
			textOutTextBox->Text = guiUtils.stringToSString(cText);
		}
	}
	private: System::Void textButtonDecrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		Key key;
		string tkey = guiUtils.sStringToString(keyTextBox->Text);
		if (keyRadioButton2->Checked) {
			tkey = guiUtils.changeTextDisplayType(2, 1, tkey);
		}
		if (keyRadioButton3->Checked) {
			tkey = guiUtils.changeTextDisplayType(3, 1, tkey);
		}
		if (textInTextBox->Text->Length > 0 && textInTextBox->Text->Length > 0 && key.setKey(tkey)) {
			string pText = guiUtils.sStringToString(textInTextBox->Text);
			if (textInRadioButton2->Checked) {
				pText = guiUtils.changeTextDisplayType(2, 1, pText);
			}
			DataStandardEncryption des;
			string cText = des.decrypt(pText, key);
			textOutRadio1->Checked = true;
			textOutTextBox->Text = guiUtils.stringToSString(cText);
		}
	}
	private: System::Void keySaveToFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string fileName = guiUtils.setFilePath();
		if (fileName.length() > 0) {
			guiUtils.saveKeyFile(fileName, guiUtils.changeTextDisplayType(guiHandler.keyPreviousState, 1, guiUtils.sStringToString(keyTextBox->Text)));
		}
	}
	private: System::Void fileInTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void fileInButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string fileName = guiUtils.getFilePath();
		if (fileName.size() > 0) {
			fileInTextBox->Text = guiUtils.stringToSString(fileName);
		}
	}
	private: System::Void fileOutTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void fileOutButton_Click(System::Object^ sender, System::EventArgs^ e) {
		string fileName = guiUtils.setFilePath();
		if (fileName.length() > 0) {
			fileOutTextBox->Text = guiUtils.stringToSString(fileName);
		}
	}
	private: System::Void fileMoveOutToIn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (fileOutTextBox->Text->Length > 0) {
			fileInTextBox->Text = fileOutTextBox->Text;
			fileOutTextBox->Text = "";
		}
	}
	private: System::Void fileButtonEncrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		Key key;
		string tkey = guiUtils.sStringToString(keyTextBox->Text);
		if (keyRadioButton2->Checked) {
			tkey = guiUtils.changeTextDisplayType(2, 1, tkey);
		}
		if (keyRadioButton3->Checked) {
			tkey = guiUtils.changeTextDisplayType(3, 1, tkey);
		}
		if (fileInTextBox->Text->Length > 0 && fileOutTextBox->Text->Length > 0 && key.setKey(tkey)) {
			string pText = guiUtils.sStringToString(fileInTextBox->Text);
			string cText = guiUtils.sStringToString(fileOutTextBox->Text);

			DataStandardEncryption des;
			des.encrypt(pText, cText, key);
		}
	}
	private: System::Void fileButtonDecrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		Key key;
		string tkey = guiUtils.sStringToString(keyTextBox->Text);
		if (keyRadioButton2->Checked) {
			tkey = guiUtils.changeTextDisplayType(2, 1, tkey);
		}
		if (keyRadioButton3->Checked) {
			tkey = guiUtils.changeTextDisplayType(3, 1, tkey);
		}
		if (fileInTextBox->Text->Length > 0 && fileOutTextBox->Text->Length > 0 && key.setKey(tkey)) {
			string pText = guiUtils.sStringToString(fileInTextBox->Text);
			string cText = guiUtils.sStringToString(fileOutTextBox->Text);

			DataStandardEncryption des;
			des.decrypt(pText, cText, key);
		}
	}
};
}
