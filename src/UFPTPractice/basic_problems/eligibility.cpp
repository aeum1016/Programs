#include <stdio.h>
#include <string>
#include <iostream>

int main(){
  int q; scanf("%d", &q);
  while(q--)
  {
    std::string name;
    int year, bYear, courses;
    std::cin >> name;
    scanf("%d/%*d/%*d", &year);
    scanf("%d/%*d/%*d", &bYear);
    scanf("%d", &courses);
    std::cout << name;
    printf(" %s\n", (year >= 2010 || bYear >= 1991) ? "eligible" : (courses <= 40) ? "coach petitions" : "ineligible");
  }
  return 0;
}