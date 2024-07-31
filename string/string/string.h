#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
namespace sy
{
	class string {
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator begin()const
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		iterator end()const
		{
			return _str + _size;
		}
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		void Swap(string &tmp)
		{
			std::swap(_str, tmp._str);
			std::swap(_capacity, tmp._capacity);
			std::swap(_size, tmp._size);
		}
		string(const string& s)
		{
			string tmp(s._str);
			Swap(tmp);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				Swap(tmp);
				return *this;
			}
		}
		size_t size()
		{
			return _size;
		}
		size_t capacity()
		{
			return _capacity;
		}
    	 char* c_str()const
		{
			return _str;
		}
		char operator[](size_t pos)
		{
			return _str[pos];
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		void push_back(char ch);
		void reserve(size_t n);
		void append(const char* str);
		string& operator += (char ch);
		string& operator +=(const char* str);
		void insert(size_t pos,char ch);
		void insert(size_t pos, const char*str);
		void erase(size_t pos,size_t len);
		size_t find(char ch, size_t pos=0);
		size_t find(const char* str, size_t pos = 0);
		string substr(size_t pos, size_t len);
	private:
		 char* _str;
		size_t _capacity;
		size_t _size;
		
	};
	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);
	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
	void test();
};