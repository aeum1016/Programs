#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;

  printf("%s", s.find("ss") != std::string::npos ? "hiss" : "no hiss");
  return 0;
}