//
// Created by HP on 2/17/2025.
//
#include <iostream>

using namespace std;

class GameEntry{
private:
    GameEntry() {}

    string name;
    int score;
public:
    GameEntry(string& n, int s){
        name = n;
        score = s;
    }

    string getName(){
        return name;
    }
    int getScore() const{
        return score;
    }
    friend class GameRecord;
};
class GameRecord{
private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
public:
    GameRecord(int c){
        maxEntries = c;
        entries = new GameEntry[maxEntries];
        numEntries = 0;
    }
    ~GameRecord(){
        delete[] entries;
    }
    bool isEmpty(){
        return numEntries==0;
    }
    void add(GameEntry& e){
        int e_score = e.getScore();
        int count = 0;
        while (e_score < entries[count].getScore()){
            count++;
        }
    }
};