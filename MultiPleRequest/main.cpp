#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <unordered_map>

using namespace std;

int main()
{
    // read the string filename
    string filename{"hosts_access_log_00.txt"};
    vector<string> timestamps;
    vector<string> timestamps_filtered;
    regex regexp("[0-9]{2}\\/\\bJul\\b\\/[0-9]{4}\\:[0-9]{2}\\:[0-9]{2}\\:[0-9]{2}");
    fstream req_file;
    string line;
    req_file.open(filename, ios::in);
    while ( getline (req_file,line) )
    {
        // flag type for determining the matching behavior (in this case on string objects)
        smatch m;
        // regex_search that searches pattern regexp in the string mystr
        regex_search(line, m, regexp);
        for (auto x : m)
            timestamps.push_back(x);
    }
    req_file.close();
    fstream out_file;
    out_file.open("req_"+filename, ios::out);
    std::unordered_map<string, int> frequencyMap;
    for (string x : timestamps)
    {
        auto search = frequencyMap.find(x);
        if(search != frequencyMap.end())
            frequencyMap[x] = ++frequencyMap[x];
        else
            frequencyMap[x] = 1;
    }

    for(auto &dic: frequencyMap)
    {
        if(dic.second > 1)
            timestamps_filtered.push_back(dic.first);
    }
    for(auto &timestamp: timestamps_filtered)
        out_file << timestamp << '\n';
    out_file.close();

    return 0;
}
