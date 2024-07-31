#include"string.h"
namespace sy {
    void string:: reserve(size_t n)
    {
        if (n > _capacity)
        {
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[]_str;
            _str = tmp;
            _capacity = n;
        }
    }
    void string:: push_back(char ch)
    {
        if (_capacity == _size)
        {
            reserve(_capacity == 0 ? 4 : 2 * _capacity);
        }
        _str[_size] = ch;
        _size++;
        _str[_size] = '\0';
    }
    void string:: append(const char* str)
    {
        size_t len = strlen(str);
        if (_capacity -_size< len)
        {
            reserve(_capacity + len > 2 * _capacity ? _capacity + len : 2 * _capacity);
        }
        strcpy(_size+_str,str);
        _size += len;
        _str[_size] = '\0';
    }
    string&string:: operator += (char ch)
    {
        push_back(ch);
        return *this;
    }
    string& string:: operator +=( const char*str)
    {
        append(str);
        return *this;
    }
    void string:: insert(size_t pos, char ch)
    {
        reserve(_capacity + 1);
        for (size_t end =_size; end >=pos; end--)
        {
            _str[end + 1] = _str[end];
        }
        _str[pos] = ch;
        _size++;
    
    }
    void string::insert(size_t pos, const char* str)
    {
        reserve(_capacity + strlen(str));
        for (size_t end = _size; end >= pos; end--)
        {
            _str[end + strlen(str)] = _str[end];
        }
        for (size_t i = 0; i < strlen(str); i++)
        {
            _str[pos+i] = str[i];
        }
        _size += strlen(str);
    }
    void string:: erase(size_t pos, size_t len)
    {
        assert(pos < _size);
        if (len + pos > _size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            
            for (size_t s=pos;s<=_size-len;s++)
            {
                _str[s] = _str[s + len];
            }
            _size -= len;
            
        }

    }
    size_t string::find(char ch, size_t pos)
    {
        assert(pos < _size);
        for (size_t i = pos; i < _size; i++)
        {
            if (_str[i] == ch)
            {
                return i;
            }
        }
        return -1;
    }
    size_t  string:: find(const char* str, size_t pos )
    {
        assert(pos < _size);
        const char* pst = strstr(_str +pos, str);
        if (pst == nullptr)
            return -1;
        return pst - _str;
    }
    string string::substr(size_t pos, size_t len)
    {
        assert(pos < _size);
        if (pos + len > _size)
        {
            len = _size - pos;
        }
        string m;
        m.reserve(_size - pos);
        for (size_t i = 0; i < len; i++)
        {
            m+= _str[pos + i];
        }
        return m;
    }

    bool operator<(const string& s1,const  string& s2)
    {
        return (strcmp(s1.c_str(),s2.c_str())<0);
    }
    bool operator<=(const string& s1, const string& s2)
    {
        return (strcmp(s1.c_str(), s2.c_str())<= 0);
    }
    bool operator>(const string& s1, const string& s2)
    {
        return (strcmp(s1.c_str(), s2.c_str()) > 0);
    }
    bool operator>=(const string& s1, const string& s2)
    {
        return (strcmp(s1.c_str(), s2.c_str()) >= 0);
    }
    bool operator==(const string& s1, const string& s2)
    {
        return (strcmp(s1.c_str(), s2.c_str()) == 0);

    }
    bool operator!=(const string& s1, const string& s2)
    {
        return !(strcmp(s1.c_str(), s2.c_str()) == 0);
    }
    ostream& operator<<(ostream& out, const string& s)
    {
        string::iterator it = s.begin();
        while (it != s.end())
        {
            out << *it;
            it++;
        }
        return out;
    }
    istream& operator>>(istream& in, string& s)
    {
        s.clear();
        const int i = 64;
        int num = 0;
        char buff[i];
        char ch;
            ch= in.get();
        while (ch != '\n')
        {
            buff[num++] = ch;
            if (num == i - 1)
            {
                buff[num] = '\0';
                s += buff;
                num = 0;
            }
            ch = in.get();
        }
           if (num > 0)
            {	
               buff[num] = '\0';
               s += buff;
            }
    
        return in;
    }



    void  test()
    {
        string s1;
        string s2("dad");
        s2.push_back('a');
        cin >> s1;
        cout << s1 << endl;

    }

}

    
