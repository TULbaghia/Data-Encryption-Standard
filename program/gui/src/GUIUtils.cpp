#include "GUIUtils.h"
#include <model\helperFunctions.h>
#include <fstream>
#include <deque>
#include <iterator>

using std::ifstream;
using std::ofstream;
using std::ios;
using std::deque;
using std::istreambuf_iterator;

string GUIUtils::getFilePath() {
	OpenFileDialog^ openFileDialog21 = gcnew OpenFileDialog;

	openFileDialog21->InitialDirectory = ".";
	openFileDialog21->Filter = "All files (*.*)|*.*";
	openFileDialog21->FilterIndex = 1;
	openFileDialog21->RestoreDirectory = true;

	String^ fileName = "";

	if (openFileDialog21->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		fileName = openFileDialog21->FileName;
	}

	return sStringToString(fileName);
}

string GUIUtils::setFilePath() {
	SaveFileDialog^ saveFileDialog21 = gcnew SaveFileDialog;

	saveFileDialog21->InitialDirectory = ".";
	saveFileDialog21->Filter = "All files (*.*)|*.*";
	saveFileDialog21->FilterIndex = 1;
	saveFileDialog21->RestoreDirectory = true;

	String^ fileName = "";

	if (saveFileDialog21->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		fileName = saveFileDialog21->FileName;
	}

	return sStringToString(fileName);
}

string GUIUtils::sStringToString(String^ str) {
	msclr::interop::marshal_context context;
	string nString = context.marshal_as<string>(str);
	return nString;
}

String^ GUIUtils::stringToSString(string str) {
	msclr::interop::marshal_context context;
	String^ nString = context.marshal_as<String^>(str);
	return nString;
}


// 1 = ASCII
// 2 = HEX
// 3 = BIN
string GUIUtils::changeTextDisplayType(int from, int to, string oldString) {
	string newString;
	if (from == 1) {
		if (to == 2) {
			oldString = helperFunctions::stringToBinaryString(oldString);
			oldString = helperFunctions::reverseString(oldString);
			newString = helperFunctions::binaryStringtoHexString(oldString);
		} else if (to == 3) {
			return helperFunctions::reverseString(helperFunctions::stringToBinaryString(oldString));
		} else {
			newString = oldString;
		}
	}
	if (from == 2) {
		if (to == 1) {
			oldString = helperFunctions::hexStringToBinaryString(oldString);
			newString = helperFunctions::binaryStringToString(oldString);
		} else if (to == 3) {
			oldString = helperFunctions::hexStringToBinaryString(oldString);
			newString = oldString;
		} else {
			newString = oldString;
		}
	}
	if (to == 3) {
		if (from == 1) {
			oldString = helperFunctions::binaryStringToString(oldString);
		} else if (from == 2) {
			newString = helperFunctions::binaryStringtoHexString(oldString);
		} else {
			newString = oldString;
		}
	}
	return newString;
}

string GUIUtils::readKeyFile(string filePath) {
	ifstream is;

	is.open(filePath, ios::binary);

	deque<unsigned char> buffStream(istreambuf_iterator<char>(is), {});
	is.close();
	string text;

	for (int i = 0; i < 8 && !buffStream.empty(); i++) {
		text += buffStream.front();
		buffStream.pop_front();
	}
	buffStream.clear();

	for (int i = text.size(); i < 8; i++) {
		text += '0';
	}

	return text;
}

void GUIUtils::saveKeyFile(string filePath, string text) {
	ofstream os;
	os.open(filePath, ios::binary);
	os << text;
	os.close();
}
