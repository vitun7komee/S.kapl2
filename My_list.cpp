#include "My_List.h"

ptrNODE findbook(ptrNODE begin, const Book& b)
{
	ptrNODE p = begin;
	while (p  && p->info.compare(b) < 0  )
		p = p->next;
	return p;
}

DLIST::DLIST(const char* file_name)
{
	std::ifstream file(file_name);
	Book bk(file);
	first_node(bk);
	ptrNODE b;
	while (!file.eof())
	{
		Book x(file);
		b = findbook(begin, x);
		if (b)
			add_before(b, x);
		else
			add_after(end, x);
	}
	file.close();
}

void DLIST::first_node(const Book& b)
{
	begin = new NODE(b);
	end = begin;
}

bool DLIST::empty()
{
	return begin == nullptr;
}

void DLIST::add_after(ptrNODE ptr, const Book& b)
{
	ptrNODE p = new NODE(b, ptr->next, ptr);
	if (ptr == end)
		end = p;
	else
		ptr->next->prev = p;
	ptr->next = p;
}

void DLIST::add_before(ptrNODE ptr, const Book& b)
{
	ptrNODE p = new NODE(b, ptr, ptr->prev);
	if (ptr == begin)
		begin = p;
	else
		ptr->prev->next = p;
	ptr->prev = p;
}

void DLIST::print()
{
	ptrNODE ptr = begin;
	while (ptr)
	{
		ptr->info.print();
		ptr = ptr->next;
	}
}

Book& DLIST::Delete(ptrNODE& ptr)
{
	ptrNODE p = ptr;
	if (ptr == begin) 
	{
		begin = p->next;
		ptr = begin;
		if (p->next)
			p->next->prev = nullptr;
	}
	else
		if (ptr == end)
		{
			end = p->prev;
			ptr = end;
			if (p->prev)
				p->prev->next = nullptr;
		}
		else 
		{
			ptr = ptr->next;
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
	static Book stud;
	stud = p->info;
	delete p;
	return stud;
}

DLIST::~DLIST()
{
	while (!empty())
		Delete(begin);
}