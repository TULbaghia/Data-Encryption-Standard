#pragma once
#include <string>

using namespace System::Windows::Forms;

using std::string;

namespace GUtil {
	/*char* getCString(System::String^ text);
	string getString(char* ptr_char);
	string getFilePath();*/


	//char* getCString(System::String^ text) {
	//	// get unsigned char array from System::String
	//	cli::array<wchar_t>^ chArray = text->ToCharArray();
	//	cli::array<unsigned char, 1>^ arr = System::Text::Encoding::ASCII->GetBytes(chArray);

	//	// declare a C array
	//	char* c_arr = new char[arr->Length + 1];
	//	memset(c_arr, NULL, arr->Length + 1);

	//	System::IntPtr c_arr_ptr(c_arr);

	//	// copy from .NETs unsigned char array to char array
	//	System::Runtime::InteropServices::Marshal::Copy(arr, 0, c_arr_ptr, arr->Length);

	//	return c_arr;
	//}

	//string getString(char* ptr_char) {
	//	string nstr(ptr_char);
	//	delete[] ptr_char;
	//	return nstr;
	//}

	string getFilePath() {
		OpenFileDialog^ openFileDialog21 = gcnew OpenFileDialog;

		openFileDialog21->InitialDirectory = ".";
		openFileDialog21->Filter = "All files (*.*)|*.*";
		openFileDialog21->FilterIndex = 1;
		openFileDialog21->RestoreDirectory = true;

		string fileName;

		if (openFileDialog21->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			auto xfileName = (openFileDialog21->FileName->ToString());
		}

		return fileName;
	}


}