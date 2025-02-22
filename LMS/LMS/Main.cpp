#include <iostream>
#include <vector>
#include<string>


class Library {
	std::string libraryName;
	std::vector<std::string> books;

public:
	Library(std::string libraryName) {
		this->libraryName = libraryName;
	}

	void AddBooks(std::string bookName) {
		books.push_back(bookName);
		std::cout << bookName << " Book Added" << std::endl;
	}

	void DeleteBook(std::string bookName) {
		books.erase(remove(books.begin(), books.end(), bookName), books.end());
	}

	void ShowAllBooks() {
		if (books.empty()) {
			std::cout << "No Books Available Right Now" << std::endl;
			return;
		}
		std::cout << "All Available Books" << std::endl;
		for (int i = 0;i < books.size();i++) {
			std::cout << books.at(i) << std::endl;
		}
	}
};

int main() {
	Library* library = new Library("RK Library");

	std::cout << "Commands" << std::endl;
	std::cout << "0-> ShowAllBooks" << std::endl;
	std::cout << "1-> AddBook" << std::endl;
	std::cout << "2-> DeleteBook" << std::endl;
	std::cout << "3-> BorrowBook" << std::endl;
	std::cout << "4-> ReturnBook" << std::endl;
	std::cout << "5-> Exit" << std::endl;

	int userCommand = 0;
	std::string bookName = "";
	while (userCommand != 5) {
		if (userCommand > 5)
			std::cout << "Invaild Command"<<std::endl;

		std::cout << "Command>> ";
		std::cin >> userCommand;
		std::cin.ignore();

		switch (userCommand)
		{
            case 0:
				library->ShowAllBooks();
				break;
			case 1:
				std::cout << "Book Name-> ";
				std::getline(std::cin, bookName);
				library->AddBooks(bookName);
				break;
		default:
			break;
		}
	}
	delete library;
	return 0;
}