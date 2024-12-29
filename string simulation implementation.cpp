#include <iostream>
#include <cassert>
using namespace std;

class String
{
public:
    String(const char *str = "")
    {
        if (nullptr == str)
        {
            assert(false);
            return;
        }
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }
    String(const String &s)
        : _str(nullptr)
    {
        String strTmp(s._str);
        swap(_str, strTmp._str);
    }
    // 对比下和上面的赋值那个实现比较好？
    String &operator=(String s)
    {
        swap(_str, s._str);
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
