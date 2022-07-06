#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main()
{
  unordered_map<string, double> timeZones;

  timeZones.emplace("UTC", 0);
  timeZones.emplace("GMT", 0);
  timeZones.emplace("BST", 1);
  timeZones.emplace("IST", 1);
  timeZones.emplace("WET", 0);
  timeZones.emplace("WEST", 1);
  timeZones.emplace("CET", 1);
  timeZones.emplace("CEST", 2);
  timeZones.emplace("EET", 2);
  timeZones.emplace("EEST", 3);
  timeZones.emplace("MSK", 3);
  timeZones.emplace("MSD", 4);
  timeZones.emplace("AST", -4);
  timeZones.emplace("ADT", -3);
  timeZones.emplace("NST", -3.5);
  timeZones.emplace("NDT", -2.5);
  timeZones.emplace("EST", -5);
  timeZones.emplace("EDT", -4);
  timeZones.emplace("CST", -6);
  timeZones.emplace("CDT", -5);
  timeZones.emplace("MST", -7);
  timeZones.emplace("MDT", -6);
  timeZones.emplace("PST", -8);
  timeZones.emplace("PDT", -7);
  timeZones.emplace("HST", -10);
  timeZones.emplace("AKST", -9);
  timeZones.emplace("AKDT", -8);
  timeZones.emplace("AEST", +10);
  timeZones.emplace("AEDT", +11);
  timeZones.emplace("ACST", +9.5);
  timeZones.emplace("ACDT", +10.5);
  timeZones.emplace("AWST", +8);

  int q; cin >> q;
  while(q--)
  {
    string time;
    int minutes;
    cin >> time;
    if(time == "noon") minutes = 12 * 60;
    else if(time == "midnight") minutes = 0;
    else{
      string am;
      cin >> am;
      int hours = stoi(time.substr(0, time.find(':')+1));
      hours += (am=="a.m." ? 0 : 12) + (hours == 12 ? -12 : 0);
      int minute = stoi(time.substr(time.find(':')+1));
      minutes = (hours * 60) + minute;
    }
    string t1, t2; cin >> t1 >> t2;


    double timeDiff = timeZones.at(t2) - timeZones.at(t1);
    minutes += timeDiff*60;
    if(minutes < 0) minutes += 24*60;

    int hours = (minutes/60)%24, minute = minutes%60;

    if(hours == 12 && minute == 0) printf("noon\n");
    else if(hours == 0 && minute == 0) printf("midnight\n");
    else 
    {
      bool am = true;
      if(hours >= 12) 
      {
        hours -= 12;
        am = false;
      }
      if(hours == 0) hours = 12;
      cout << hours << ":" << setfill('0') << setw(2) << minute << " " << (am ? "a.m." : "p.m."); 
      cout << endl;
    }
  }
  return 0;
}