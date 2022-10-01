#pragma once
#include "quad.h"
template <typename value_t>
class list {
public:
	using value_type = value_t;
	using pointer = value_type*;
	using reference = value_type&;
protected:
	struct node {
		value_type data;
		node* next = nullptr, * prior = nullptr;
		node() 	{}
		node(quad* a):data(a),next(nullptr)	{}
	};
	node head, tail;
	void _init() {
		head.next = &tail;
		tail.prior = &head;
		tail.next = nullptr;
	}
	void _link_after(node* pre, node* p) {
		p->prior = pre;
		p->next = pre->next;
		pre->next->prior = p;
		pre->next = p;
	}
public:
	list() noexcept {
		_init();
	}
	virtual ~list() noexcept {
		clear();
	}
	void push_back(const value_type& v) {
		_link_after(tail.prior, new node{ v });
	}
	void clear() {
		node* p = head.next, *q;
		while (p != &tail) 	{
			q = p;
			p = p->next;
			delete q;
		}
	}
	using range = node*;
	class iterator 	{
	private:
		range p;
	public:
		using value_type = list::value_type;
		using pointer = list::pointer;
		using reference = list::reference;
		iterator(range q = nullptr) : p(q) 	{		}
		bool operator!=(const iterator& i) 	{
			return p != i.p;
		}
		iterator& operator++() 	{
			p = p->next;
			return *this;
		}
		reference operator*() 	{
			return p->data;
		}
	};
	iterator begin() {
		return iterator(head.next);
	}
	iterator end() {
		return iterator(&tail);
	}
};