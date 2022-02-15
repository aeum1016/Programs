#include <string>
#include <regex>

#pragma once

using namespace std;

/**
 * reads and loads the name and gatorID input from cin
 */
void loadInput(string& name, string& gatorID)
{
      getline(cin, name);

      int secondQuotation = name.find('\"', 2);
      gatorID = name.substr(secondQuotation+2);
      name = name.substr(1, secondQuotation);
}

/**
 * returns whether the input string is
 * a valid gatorID.
 * 
 * @return is the input a valid gatorID
 */
bool isValidGatorID(string gatorID)
{
  regex id("^[0-9]{8}$");
  return regex_match(gatorID, id);
}

/**
 * returns whether the input string is
 * a valid name.
 * 
 * @return is the input a valid name.
 */
bool isValidName(string name)
{
  regex nameRegEx("^\"[A-Za-z\\s]+\"$");
  return regex_match(name, nameRegEx);
}

/**
 * returns whether the input strings are both
 * valid
 * 
 * @return are the inputs a valid name and valid gatorID
 */
bool isValidInput(string name, string gatorID)
{
  return isValidName(name) && isValidGatorID(gatorID);
}

/**
 * prints "successful"
 */
void printSuccessful()
{
  cout << "successful" << endl;
}

/**
 * prints "unsuccessful"
 */
void printUnsuccessful()
{
  cout << "unsuccessful" << endl;
}