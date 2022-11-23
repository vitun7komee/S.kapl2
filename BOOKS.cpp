#include "Books.h"

Book::Book(std::ifstream& file)
{
	file >> autor;
	file >> name;
	file >> year;
	file >> pages;
	file >> speciality;
	file.ignore();
	std::string splitLine;
	std::getline(file, splitLine);
}

void Book::print()
{
	std::cout << autor << '\n';
	std::cout << name << '\n';
	std::cout << year << '\n';
	std::cout << pages << '\n';
	std::cout << speciality << '\n';
	std::cout << "~~~~~~~~~~~~~~~~~~\n";
}

int Book::compare(const Book& b)
{
	int result = 1;
	if (year < b.year || year == b.year && name < b.name)
		result = -1;
	if (year == b.year && name == b.name)
		result = 0;
	return result;
}
bool Book::search(std::string searchname, std::string name) {
	bool find;
	find = false;
	std::string f = name;
	std::string f2 = searchname;
	for (int i = 0; i < (int)f.size(); i++) {
		f[i] = toupper(f[i]);
	}
	for (int k = 0; k < (int)f2.size(); k++) {
		f2[k] = toupper(f2[k]);
	}
	size_t pos = f.find(f2);
	if (pos != std::string::npos) {
		find = true;
	}	
	return find;
}
std::string Book::getname()
{
	return name;
}

int Book::getyear()
{
	return year;
}