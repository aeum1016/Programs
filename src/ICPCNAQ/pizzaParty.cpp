#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    n++;
    unordered_map<string, vector<string>> checks;
    unordered_set<string> needs;
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);
        if (input.substr(0, 2) == "if") {
            //do something for ifs
            int index = input.find(' ');
            input.erase(input.begin(), input.begin() + index + 1);
            index = input.find(' ');
            string check1 = input.substr(0, index);
            input.erase(input.begin(), input.begin() + index + 1);
            index = input.find(' ');
            string conditional = input.substr(0, index);
            input.erase(input.begin(), input.begin() + index + 1);
            index = input.find(' ');
            string check2 = input.substr(0, index);
            input.erase(input.begin(), input.begin() + index + 1);
            index = input.find(' ');
            input.erase(input.begin(), input.begin() + index + 1);
            string result = input;

            if (conditional == "and") {
                //check for both checks
                if (needs.find(check1) != needs.end() && needs.find(check2) != needs.end()) {
                    //insert result into needs
                    needs.insert(result);
                }
                else {
                    vector<string> v;
                    v.push_back(check1);
                    v.push_back(check2);
                    v.push_back(conditional);
                    checks[result] = v;
                }
            }
            else if (conditional == "or") {
                if (needs.find(check1) != needs.end() || needs.find(check2) != needs.end()) {
                    needs.insert(result);
                }
                else {
                    vector<string> v;
                    v.push_back(check1);
                    v.push_back(check2);
                    v.push_back(conditional);
                    checks[result] = v;
                }
            }
            auto iter = checks.begin();
            for (iter; iter != checks.end(); ++iter) {
                if (iter->second[2] == "and") {
                    if (needs.find(iter->second[0]) != needs.end() && needs.find(iter->second[1]) != needs.end()) {
                        //insert result into needs
                        needs.insert(iter->first);
                    }
                }
                else if (iter->second[2] == "or") {
                    if (needs.find(iter->second[0]) != needs.end() || needs.find(iter->second[1]) != needs.end()) {
                        needs.insert(iter->first);
                    }
                }
            }
        }
        else {
            //assume absolute
            needs.insert(input);
            //check for checks again
            auto iter = checks.begin();
            for (iter; iter != checks.end(); ++iter) {
                if (iter->second[2] == "and") {
                    if (needs.find(iter->second[0]) != needs.end() && needs.find(iter->second[1]) != needs.end()) {
                        //insert result into needs
                        needs.insert(iter->first);
                    }
                }
                else if (iter->second[2] == "or") {
                    if (needs.find(iter->second[0]) != needs.end() || needs.find(iter->second[1]) != needs.end()) {
                        needs.insert(iter->first);
                    }
                }
            }
        }
    }
    cout << needs.size() - 1;
}