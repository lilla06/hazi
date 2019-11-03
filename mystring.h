#include <iostream>
#include <cstring>

class StringValue{
    char* s;
    int count;
public:
    StringValue();
    
    StringValue(const char* st);
    
    char* cstr();
    int& setCount();
    int getCount()const;
    
    size_t getLen()const;
    
    char& operator[](size_t n);
    char operator[](size_t n)const;
    
    ~StringValue();
};



class MyString{
public:
    StringValue* string;
public:
    MyString();
    
    MyString(char* const & s);
    
    
    MyString(MyString const& s);
    MyString(MyString && s);
   
    
    MyString& operator=(MyString&&)noexcept;
    MyString& operator=(MyString const&);
    
    MyString operator+(MyString const&) const;
    MyString& operator+=(MyString const&);
    
    MyString operator+(char const& c) const;
    
    MyString& operator+=(char const& c);
    
    size_t getLen()const;
    
    char operator[](size_t idx)const;
    
    char& operator[](size_t idx);
    
    void deleteValue();
    
    char* cstr()const;
    
    ~MyString();

};

std::ostream& operator<<(std::ostream& os, MyString const & m);
std::istream& operator>>(std::istream& is, MyString& m);







