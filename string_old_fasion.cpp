#include <iostream>
#include <cassert>
using namespace std;

class String
{
public:
    String(const char *str = "")
    {
        // 构造String类对象时，如果传递nullptr指针，可以认为程序非
        if (nullptr == str)
        {
            assert(false);
            return;
        }
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }
    String(const String &s)
        : _str(new char[strlen(s._str) + 1])
    {
        strcpy(_str, s._str);
    }
    String &operator=(const String &s)
    {
        if (this != &s)
        {
            char *pStr = new char[strlen(s._str) + 1];
            strcpy(pStr, s._str);
            delete[] _str;
            _str = pStr;
        }
        return *this;
    }

    ~String()
    {
        if (_str)
        {
            delete[] _str;
            _str = nullptr;
        }
    }

private:
    char *_str;
};
