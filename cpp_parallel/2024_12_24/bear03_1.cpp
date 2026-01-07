#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

#include <unordered_set>

using namespace std;

bool areAnagrams(const string& str1, const string& str2) {
    if (str1.length() != str2.length() || str1 == str2) {
        return false;
    }

    unordered_map<char, int> charCount;

    for (char c : str1) {
        charCount[c]++;
    }

    for (char c : str2) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return false;
        }
    }
    return true;
}

int countAnagramPairs(const string& str) {
    vector<string> words;
    string word = "";

    for (char c : str) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }
    cout<<words.size()<<words[2]<<endl;

    int count = 0;
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if (words[i]== words[j]) continue;
            if (areAnagrams(words[i], words[j])) {
                count++;
            }
        }
    }

    return count;
}



int countAnagramPairs_new(const string& str) {
    vector<string> words;
    string word = "";

    for (char c : str) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }
    cout<<words.size()<<words[2]<<endl;

    unordered_map<string, unordered_set<string>> anagrams;
    for (auto word: words) {
        bool find = false;
        for (auto it = anagrams.begin(); it != anagrams.end(); ++it) {
            if (areAnagrams(word, it->first)) {
                it->second.insert(word);
                find = true;
            }
        }
        if (!find) {
            anagrams[word] = {};
        }
    }
    int count = 0;
    for (auto it = anagrams.begin(); it != anagrams.end(); ++it) {
        count += it->second.size();
    }

    // int count = 0;
    // for (int i = 0; i < words.size() - 1; ++i) {
    //     for (int j = i + 1; j < words.size(); ++j) {
    //         if (words[i]== words[j]) continue;
    //         if (areAnagrams(words[i], words[j])) {
    //             count++;
    //         }
    //     }
    // }

    return count;
}

int main() {
    string str = "a c b c run urn urn";
    int anagramPairs = countAnagramPairs_new(str);
    std::cout << "Number of anagram pairs: " << anagramPairs << std::endl; 
    return 0;
}