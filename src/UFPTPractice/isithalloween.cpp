#include <stdio.h>
#include <string>
#include <iostream>

int main(){
  std::string MD;
  std::getline(std::cin, MD);
  if((MD == "OCT 31") || (MD == "DEC 25"))
  {
    printf("yup");
  }
  else printf("nope");
  return 0;
}