#include <iostream>
#include <fstream>
#include "Books.h"

using TInfo = Book;

struct NODE
{
	TInfo info;
	NODE* next, * prev;
	NODE(TInfo info, NODE* next = nullptr, NODE* prev = nullptr) :info(info), next(next), prev(prev) {}
	~NODE()
	{
		next = nullptr;
		prev = nullptr;
	}
};

using ptrNODE = NODE*;

struct DLIST
{
private:
	ptrNODE begin, end;
public:
	DLIST()
	{
		begin = nullptr;
		end = nullptr;
	}
	DLIST(const char* file_name);
	void first_node(const Book& b);
	bool empty();
	void add_before(ptrNODE ptr, const Book& b);
	void add_after(ptrNODE ptr, const Book& b);
	void print();
	Book& Delete(ptrNODE& ptr);
	ptrNODE get_begin()
	{
		return begin;
	}
	~DLIST();
};
