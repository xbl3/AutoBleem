//
// Created by screemer on 2018-12-15.
//


#ifndef CBLEEMSYNC_GAME_H
#define CBLEEMSYNC_GAME_H


#include <vector>
#include <map>


using namespace std;


class Disc {
public:
    string diskName;
    string cueName = "";
    // verifications

    bool cueFound = false;
    bool binVerified = false;
};

class Game {
public:
    int folder_id;
    string fullPath;
    string pathName;
    string title;
    string publisher;
    int players;
    int year;
    vector<Disc> discs;

    bool gameDataFound = false;
    bool pcsxCfgFound = false;
    bool gameIniFound = false;
    bool gameIniValid = false;
    bool imageFound = false;
    bool licFound = false;
    bool automationUsed = false;

    void readIni(string path);

    void saveIni(string path);
    void recoverFiles();
    bool verify();
    bool print();

    string scanSerial();

private:

    string firstBinPath = "";

    map<string, string> iniValues;

    void parseIni(string path);
    void updateObj();
    bool validateCue(string cuePath, string path);
    string valueOrDefault(string name, string def);


};


#endif //CBLEEMSYNC_GAME_H
