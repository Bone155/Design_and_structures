#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::fstream;
using std::ios;
using std::cout;
using std::cin;
using std::endl;

struct BookInfo
{
	int callNumber;
	string title;
	string author;
	int bookStatus;
	int dueDate;
	string borrower;
};

void textFile() {
	int lines = 0;
	fstream file;
	string input;
	cout << "Write in a file" << endl << "Display, write, clear, or quit" << endl << endl;
	while (true) {
		cin >> input;
		if (input == "Display" || input == "display") {
			file.open("MyLog.txt", ios::in);
			if (!file.is_open())
			{
				std::cerr << "File not found." << endl;
			}
			string text;
			while (std::getline(file, text)) {
				cout << text << endl;
			}
			cout << endl;
			file.close();
		}
		else if (input == "Write" || input == "write") {
			cout << "How many lines do you want to write" << endl;
			file.open("MyLog.txt", ios::out | ios::app);
			if (!file.is_open())
			{
				std::cerr << "File not found." << endl;
			}
			file.clear();
			cin >> lines;
			cout << endl;
			for (int i = -1; i < lines; i++) {
				std::getline(cin, input);
				file << input << endl;
			}
			cout << endl;
			file.flush();
			file.close();
		}
		else if (input == "Clear" || input == "clear") {
			file.open("MyLog.txt", ios::out | ios::trunc);
			cout << endl;
			file.close();
		}
		else if (input == "Quit" || input == "quit") {
			break;
		}
		else if (cin.fail()) {
			cout << "invalid input" << endl;
			cin.clear();
		}

	}
	
}

void Load() {
	fstream dataFile;
	dataFile.open("Library.dat", ios::out);
	if (!dataFile.is_open) {
		while (!dataFile.eof() && dataFile.peek() != EOF)
		{
			BookInfo books;
			dataFile.read((char*)&books, sizeof(BookInfo));
			cout << books.callNumber << endl << books.title << endl << books.author << books.bookStatus << endl << books.dueDate << endl << books.borrower << endl << endl;
		}
		dataFile.close();
	}
	else {
		fstream txtFile;
		txtFile.open("library.txt", ios::in);
		if (!txtFile.is_open()) {
			cout << "Error" << endl;
		}
		else {
			BookInfo books;
			string text;
			while (std::getline(txtFile, text)) {
				
			}
		}
	}
}

void binaryFile() {
	
}

int main() {

	//textFile();

	binaryFile();

	system("pause");
	return 0;
}