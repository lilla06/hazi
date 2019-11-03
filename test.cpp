#include <iostream>
#include "mystring.h"

int main(int argc, const char * argv[]) {
//konstruktorok
    MyString s1{};
 
    MyString s2{(char*)"hello"};
    std::cout << s2 << std::endl;   //hello
 
    MyString s3{s2};
    std::cout << s3<< std::endl;    //hello
    
    char * fa = (char*)"fa";
    MyString s4{fa};
    std::cout << s4 << std::endl;    //fa
    
//beolvasas
    std::cin >> s1;
    std::cout << s1 << std::endl;   //input
    
//értékadás
    s3 = s1;
    std::cout << s3 << std::endl;   //input
    
    s3 = s1 + s4;
    std::cout << s3 << std::endl;   //inputfa
//összefűzés
    s3 = s1 + '_';
    std::cout << s3 <<std::endl;    //input_
    
    s1 += '_';
    std::cout << s1 << std::endl;   //input_
    
    s3 = s1 + s4;
    std::cout << s3 << std::endl;   //alma_fa
    
    s1 += s4;
    std::cout << s1 << std::endl;   //alma_fa
    
    s2 = s2 + 'W' + 'O';
    std::cout << s2 << std::endl;   //helloWO
 
//hossz
    size_t i = s2.getLen();
    std::cout << i << std::endl;    //7

    
//indexelés
    char a = s2[0];
    std::cout << a << std::endl;    //h

    s2[5] = '-';
    std::cout << s2 << std::endl;   //hello-O

    return 0;
}
