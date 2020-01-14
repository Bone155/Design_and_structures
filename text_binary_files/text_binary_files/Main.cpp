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
	char callNumber[9];
	char title[15];
	char author[30];
	char bookStatus[1];
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

//void load() {
//	fstream dataFile;
//	dataFile.open("library.dat", ios::in | ios::binary);
//	if (dataFile.is_open) {
//		while (!dataFile.eof() && dataFile.peek() != EOF)
//		{
//			BookInfo books;
//			dataFile.read((char*)&books, sizeof(BookInfo));
//		}
//		dataFile.close();
//	}
//	else {
//		fstream txtFile;
//		txtFile.open("library.txt", ios::in);
//		if (!txtFile.is_open()) {
//			cout << "Error" << endl;
//		}
//		else {
//			BookInfo books[3];
//			string text;
//			for (int i = 0; i < 3; i++) {
//				std::getline(txtFile, text);
//				strcpy_s(books[i].callNumber, text.c_str());
//				std::getline(txtFile, text);
//				strcpy_s(books[i].title, text.c_str());
//				std::getline(txtFile, text);
//				strcpy_s(books[i].author, text.c_str());
//				std::getline(txtFile, text);
//				strcpy_s(books[i].bookStatus, text.c_str());
//			}
//			txtFile.close();
//			dataFile.open("library.dat", ios::out | ios::binary);
//			dataFile.write((char*)&books, sizeof(BookInfo));
//			dataFile.close();
//			
//		}
//	}
//}
//
//BookInfo save(BookInfo book) {
//	fstream file;
//	file.open("library.dat", ios::out | ios::binary);
//	if (file.is_open) {
//		for (int i = 0; i < 3; i++) {
//			file.write((char*)&book, sizeof(BookInfo));
//			
//		}
//		file.close();
//	}
//	return book;
//
//}
//
//BookInfo find(BookInfo books[], string title) {
//	BookInfo book;
//	fstream file;
//	file.open("library.dat", ios::in | ios::binary);
//	if (file.is_open) {
//		for (int i = 0; i < 3; i++) {
//			file.read((char*)&books[i], sizeof(BookInfo));
//			if (books[i].title == title) {
//				book = books[i];
//			}
//		}
//		file.close();
//	}
//	return book;
//
//}
//
//void display(BookInfo book) {
//	fstream dataFile;
//	dataFile.open("library.dat", ios::in | ios::binary);
//	if (dataFile.is_open) {
//		dataFile.read((char*)&book, sizeof(BookInfo));
//		cout << book.callNumber << endl << book.title << endl << book.author << book.bookStatus << endl << endl;
//	}
//	dataFile.close();
//}
//
//BookInfo update(BookInfo book) {
//	fstream txtfile;
//	txtfile.open("library.txt", ios::in | ios::out);
//	if (!txtfile.is_open())
//	{
//		std::cerr << "File not found." << endl;
//	}
//	txtfile.clear();
//	cout << endl;
//	
//	txtfile << book.bookStatus << endl;
//	cout << endl;
//	txtfile.flush();
//	txtfile.close();
//
//	fstream datafile;
//	datafile.open("library.dat", ios::out | ios::binary);
//	if (datafile.is_open) {
//		datafile.write((char*)&book.bookStatus, sizeof(BookInfo));
//	}
//	datafile.close();
//}
//
//void binaryFile() {
//	load();
//
//
//}

int main() {

	textFile();

	//binaryFile();

	system("pause");
	return 0;
}