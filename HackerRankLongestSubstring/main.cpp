#include <iostream>

std::pair<char, unsigned> longestSubstring(const std::string&);

int main() {
    std::pair<char, unsigned> longest_substring = longestSubstring("aaaabbbbbbcccccccnee");
    std::cout << "Longest reoccuring character is: '" << longest_substring.first
              << "', at: " << longest_substring.second << " times." << std::endl;
    return 0;
}

std::pair<char, unsigned> longestSubstring(const std::string &s){
    unsigned max_length = 0, curr_length = 0;
    char last, max = 0;
    for(char c: s) {
        curr_length++;
        if(c != last) {
            if(curr_length > max_length) {
                max_length = curr_length;
                max = last;
            }
            curr_length = 0;
        }
        last = c;
    }
    return std::make_pair(max, max_length);
}
