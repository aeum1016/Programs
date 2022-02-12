#include <string>
#include <regex>

#pragma once

using namespace std;

bool validateGatorID(int gatorID)
{
  regex id("^[0-9]{8}$");
  return regex_match(to_string(gatorID), id);
}

bool validateName(string name)
{
  regex nameRegEx("^\"[A-Za-z\\s]+\"$");
  return regex_match(name, nameRegEx);
}