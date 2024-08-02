#pragma once
#include<iostream>
using namespace std;
namespace jl {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return  _finish;
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return end_of_storage - _start;
		}
		bool empty()
		{
			return (size() == 0);
		}

		void swap(vector<T>& v)
		{
			std::swap(v._finish = _finish);
			std::swap(v._start = _start);
			std::swap(v.end_of_storage = end_of_storage);
		}
		vector()
		{
		}
		vector(size_t n, const T& value = T())
		{
			reserve(n);
			while (_finish - _start != n)
			{
				push_back(value);
			}
		}
		vector(const vector<T>& v)
		{
			reserve(v.size());
			for (auto e : v)
			{
				push_back(e);
			}
		}
		vector<T>& operator= (vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = end_of_storage = nullptr;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (n > _finish - _start)
				{
					*_finish = value;
					++_finish;
				}
			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t ysize = size();
				iterator newstart = new T[n];
				for (size_t i = 0; i < ysize; i++)
				{
					newstart[i] = _start[i];
				}
				delete[] _start;
				_start = newstart;
				_finish = _start + ysize;
				end_of_storage = _start + n;
			}
		}
		void push_back(const T& x)
		{
			//ÅÐ¶ÏÈÝÁ¿
			if (capacity() == size())
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			_finish++;
		}
		void  pop_back()
		{
			_finish--;

		}

		iterator insert(iterator pos, const T& x)
		{
			if (capacity() == size())
			{
				reserve(size() + 1);
			}
			for (iterator end = _finish - 1; end >= pos; end--)
			{
				*(end + 1) = *(end);
			}
			*pos = x;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			while (pos + 1 < _finish)
			{
				*(pos) = *(pos + 1);
			}
			_finish--;
		}
		T& operator[](size_t pos)
		{
			return *(_start + pos);
		}
		const T& operator[](size_t pos)const
		{
			return *(_start + pos);
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator end_of_storage = nullptr;
	};


template<class Container>
void print_container(const Container& v)
{
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
	void test_vector1()
	{
		vector<int> v;
		v.resize(10, 1);
		v.reserve(20);

		print_container(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(15, 2);
		print_container(v);

		v.resize(25, 3);
		print_container(v);

		v.resize(5);
		print_container(v);

	}
}


