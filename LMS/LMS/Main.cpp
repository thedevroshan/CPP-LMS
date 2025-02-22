#include <iostream>
#include <vector>


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
		std::cout << "All Available Books" << std::endl;
		for (int i = 0;i < books.size();i++) {
			std::cout << books.at(i) << std::endl;
		}
	}
};

int main() {
	Library* library = new Library("RK Library");
	std::string userCommand = "";
	std::cin >> userCommand;
	return 0;
}