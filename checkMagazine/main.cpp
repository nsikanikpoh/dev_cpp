#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    unordered_map<string, int> words;
    for (auto &it: magazine)
        words[it]++;
    for (auto &it: ransom) {
        if (words[it]>0)
            words[it]--;
        else
            return false;
    }
    return true;
}
// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    if(ransom_note(magazine, note))
    cout<<"Yes"<<'\n';
    else
    cout<<"No"<<'\n';

}


int main()
{
vector<string> mag{"ive", "got", "a", "lovely", "bunch", "of", "coconuts"};
vector<string> ras{"ive", "got", "some", "coconuts"};
checkMagazine(mag, ras);
    return 0;
}
