#pragma once

#include <algorithm>
#include <string>

#define RA_FOLDER "/media/retroarch"

enum ImageType { IMAGE_NO_GAME_FOUND = -1,
                 IMAGE_BIN = 0, // must be 0 to match existing game.ini
                 IMAGE_PBP = 1, // must be 1 to match existing game.ini
                 IMAGE_IMG
//                 IMAGE_ISO // not supported yet
};

const char GAME_DATA[] = "GameData";
const char GAME_INI[] = "Game.ini";
const char PCSX_CFG[] = "pcsx.cfg";
const char EXT_PNG[] = ".png";
const char EXT_PBP[] = ".pbp";
const char EXT_ECM[] = ".ecm";
const char EXT_BIN[] = ".bin";
const char EXT_IMG[] = ".img";
//const char EXT_ISO[] = ".iso";
const char EXT_CUE[] = ".cue";
const char EXT_LIC[] = ".lic";

//////////////////////////////
// inline std:string functions
//////////////////////////////

//******************
// ltrim
//******************
// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

//******************
// rtrim
//******************
// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

//******************
// trim
//******************
// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

//******************
// lcase
//******************
// converts all, or part, of the passed string to lower case.  a reference to the modified string is returned.
static inline std::string &lcase(std::string &s, int nchars = 0) {
    if (nchars == 0) nchars = s.length();
    for (int i = 0; i < nchars; i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

//******************
// ucase
//******************
// converts all, or part, of the passed string to upper case.  a reference to the modified string is returned.
static inline std::string &ucase(std::string &s, int nchars = 0) {
    if (nchars == 0) nchars = s.length();
    for (int i = 0; i < nchars; i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

//******************
// ReturnLowerCase
//******************
// returns a lower case copy of the string.  the passed string is not modified.
static inline std::string ReturnLowerCase(const std::string& s) {
  std::string temp = s;
  for (auto& c : temp) {
    c = tolower(c);
  }

  return temp;
}

//*******************************
// ReturnUpperCase
//*******************************
// returns an upper case copy of the string.  the passed string is not modified.
static inline std::string ReturnUpperCase(const std::string& s) {
  std::string temp = s;
  for (auto& c : temp) {
    c = toupper(c);
  }

  return temp;
}

//*******************************
// SortByCaseInsensitive
//*******************************
static inline bool SortByCaseInsensitive(const std::string & left, const std::string & right) {
    return ReturnLowerCase(left) < ReturnLowerCase(right);
}
