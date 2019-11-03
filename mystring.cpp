#include "mystring.h"
#include <iostream>
#include <cstring>

StringValue::StringValue(){
    count = 1;
    s = new char[1];
    s[0] = '\0';
}

StringValue::StringValue(const char* st):count{1}{
    s = new char[strlen(st) + 1];
    strcpy(s, st);
    s[strlen(st)]= '\0';
}

char* StringValue::cstr(){
    return s;
}
int& StringValue::setCount(){
    return count;
}
int StringValue::getCount()const {
    return count;
}

size_t StringValue::getLen()const {
    return strlen(s);
}

char& StringValue::operator[](size_t n){
    return s[n];
}
char StringValue::operator[](size_t n)const{
    return s[n];
}

StringValue::~StringValue(){
    delete[] s;
}




MyString::MyString(){
    this->string = new StringValue{};
}

MyString::MyString(char* const & s){
    string = new StringValue{s};
}

MyString::MyString(MyString const& s){
    string = s.string;
    string->setCount()++;
}

MyString::MyString(MyString && s){
    string = s.string;
    s.string = nullptr;
}
MyString::~MyString(){
    if(string != nullptr)
        deleteValue();
}

MyString& MyString::operator=(MyString&& rv)noexcept{
    if(this != &rv){
        deleteValue();
        string = rv.string;
        rv.string = nullptr;
    }
    return *this;
}
MyString& MyString::operator=(MyString const& s){
    if(this != &s){
        deleteValue();
        string = s.string;
        string->setCount()++;
    }
    return *this;
}


MyString MyString::operator+(MyString const& s) const{
    char* temp = new char[this->getLen() + s.getLen() + 1];
    strcpy(temp, this->string->cstr());
    strcat(temp, s.string->cstr());
    temp[this->getLen() + s.getLen() ] = '\0';
    MyString t = MyString{temp};
    delete [] temp;
    return t;
}

MyString MyString::operator+(char const& c) const{
    char *temp = new char[this->getLen() + 2];
    strcpy(temp, this->string->cstr());
    temp[this->getLen()] = c;
    temp[this->getLen() + 1] = '\0';
    MyString t  = MyString(temp);
    delete[] temp;
    return t;
}

MyString& MyString::operator+=(char const& c){
    *this = *this + c;
    return *this;
}

size_t MyString::getLen()const{
    return string->getLen();
}

char MyString::operator[](size_t idx)const{
    return string->operator[](idx);
}
char& MyString::operator[](size_t idx){
    if(string->getCount() == 1)
        return string->operator[](idx);
    char * temp = new char[strlen(cstr()) + 1];
    strcpy(temp,cstr());
    temp[strlen(cstr())] = '\0';
    deleteValue();
    string = new StringValue{temp};
    delete[] temp;
    return string->operator[](idx);
}

void MyString::deleteValue(){
    if(string != nullptr){
        string->setCount()--;
        if(string->getCount() == 0)
            delete string;
        string = nullptr;
    }
}


char* MyString::cstr()const{
    return string->cstr();
}


MyString& MyString::operator+=(MyString const& s){
    *this = *this + s;
    return *this;
}


std::ostream& operator<<(std::ostream& os, MyString const & m){
    os << m.cstr();
    return os;
}
std::istream& operator>>(std::istream& is, MyString& m){
    m.deleteValue();
    char c;
    char* temp = new char[1];
    temp[0] = '\0';
    while(is>>c){
        char* t = new char[strlen(temp) + 2];
        strcpy(t, temp);
        t[strlen(temp)] = c;
        t[strlen(temp) + 1] = '\0';
        delete[] temp;
        temp = std::move(t);
        t = nullptr;
    }
    delete[] temp;
    m = std::move(MyString{temp});
    return is;
}
