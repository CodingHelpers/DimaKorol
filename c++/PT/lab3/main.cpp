/* Author: David Zaretsky
 *
 * Task:
 * Создать класс String, реализующий работу со строчками с учетом числа
 * обращений к ним (со счетчиками). Так, например, при присвоении одной строки
 * другой, не выделяется новая память для хранения строки, а лишь увеличивается
 * счетчик ее использования. Класс должен предоставлять основные операции по
 * работе со строками (сложение, сравнение, присваивание и т.д.). Данный класс должен
 * позволять использовать себя (те данные, которые он хранит) в функциях стандартной
 * библиотеки.
 */

#include <iostream>
#include <cstring>
using namespace std;

class String {
public:
    String() : String("") {}

    String(const char* from) : String(std::string(from)) {}

    String(const string& from) {
        this->_len = from.length();
        this->_cnt = new int;
        this->_str = new char[_len+1];
        *_cnt = 0;
        strcpy(this->_str, from.c_str());
    }

    String(const String& from) {
        this->_cnt = from._cnt;
        this->_len = from._len;
        this->_str = from._str;
        (*this->_cnt)++;
    }

    ~String() {
        if(!_cnt) {
            return;
        }

        (*_cnt)--;

        cout << str() << ": " << *_cnt << endl;

        if(*_cnt >= 0) {
            return;
        }

        if(_str) {
            delete[] _str;
            delete _cnt;
            _len = 0;
        }
   }

    String& operator= (const String& from) {
        if(_cnt) {
            (*_cnt)--;

            cout << str() << ": " << *_cnt << endl;

            if(*_cnt < 0) {
                if(_str) {
                    delete[] _str;
                    delete _cnt;
                    _len = 0;
                }
            }
        }

        if(this == &from) {
            return *this;
        }

        this->_cnt = from._cnt;
        this->_len = from._len;
        this->_str = from._str;
        (*this->_cnt)++;

        return *this;
    }

    friend String operator+ (const String& a, const String& b) {
        std::string temp;
        temp.append(a.str());
        temp.append(b.str());
        return String(temp);
    }

    friend bool operator== (const String& a, const String& b) {
        return strcmp(a.str(), b.str()) ? false : true;
    }

    friend bool operator!= (const String& a, const String& b) {
        return strcmp(a.str(), b.str()) ? true : false;
    }

    friend bool operator<  (const String& a, const String& b) {
        return strcmp(a.str(), b.str()) < 0;
    }

    friend bool operator>  (const String& a, const String& b) {
        return strcmp(a.str(), b.str()) > 0;
    }

    friend bool operator<= (const String& a, const String& b) {
        return a < b || a == b;
    }

    friend bool operator>= (const String& a, const String& b) {
        return a > b || a == b;
    }

    const char* str() const {
        return _str;
    }

    size_t len() const {
        return _len;
    }

private:
    char* _str;
    size_t _len;
    int* _cnt;
};

int main(int argc, char *argv[]) {

    String helloworld("dummy");
    String hello2("line");

    {
        String hello("Hello ");
        String world("World");

        hello2 = hello;

        helloworld = hello + world;
    }

    String str1("lol");

    String str2 = str1;
    String str3 = str2;
    String str4 = str1;
    String str5 = str1;
    String str6 = str5;

    hello2 = str4;

    cout << hello2.str() << endl << helloworld.str() << endl << str3.str() << endl;
    return 0;
}
