#include <stdio.h>
#include <iostream>
#include <string>
#include <regex>

int main(){
    std::string s;
    std::getline(std::cin, s);
    std::regex r("\\s+");
    std::regex_replace(s, r, "");
    printf("Thank you, %s, and farewell!", s.c_str());
    return 0;
}