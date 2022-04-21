#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
#include <map>

using namespace std;
using std::ifstream;
using std::vector;

struct word_struct {
    std::string word;
    int len;
    std::map<char, int> dominant;
};

class Statistics {

 public:
     void solve() {
         read_data();
         print_output();
     }

 private:
     int N;
     std::vector<word_struct> words;
     std::vector<int> result;

     void read_data() {
         ifstream input_data;
         input_data.open("statistics.in");
         if (!input_data) {
             printf("error\n");
         }
         input_data >> N;
         for (int i = 0; i < N; ++i) {
            word_struct new_word;
            input_data >> new_word.word;
            new_word.len = new_word.word.size();
            for (int j = 0; j < new_word.len; ++j) {
                if (new_word.dominant.find(new_word.word[j]) == new_word.dominant.end()) {
                    new_word.dominant.insert({new_word.word[j], 1});
                } else {
                    new_word.dominant.at(new_word.word[j]) += 1;
                }
            }
            words.push_back(new_word);
         }
     }


    void get_solve() {
        int first_letter = 0;
        while (first_letter < 25) {
            int value = first_letter + 'a';
            int sum = 0;
            int count = 0;
            sort(words.begin(), words.end(), [&](word_struct& a, word_struct& b)-> bool
            {
                if (b.dominant.find(char(value)) == b.dominant.end()) {
                    b.dominant.insert({char(value),0});
                }
                int valoare2 = b.dominant.at(char(value));
                if (a.dominant.find(char(value)) == a.dominant.end()) {
                    a.dominant.insert({char(value),0});
                }
                int valoare1 = a.dominant.at(char(value));

                return (2 * valoare1 - a.len) > (2 * valoare2 - b.len);
            });
            for (int i = 0; i < N; ++i) {
                sum += (2 * words[i].dominant.at(char(first_letter + 'a')) - words[i].len);
                if (sum > 0) {
                    count++;
                }
            }
            result.push_back(count);
            first_letter++;
        }
        sort(result.begin(), result.end(), greater<int>());
    }

    void print_output() {
        /*Printare in fisierul de out*/
        get_solve();
        ofstream outfile("statistics.out");
        outfile << result[0];
        outfile.close();
    }
};

int main() {
    auto* statistics = new (nothrow) Statistics();
    if (!statistics) {
        cerr << "Error\n";
        return -1;
    }
    statistics->solve();
    delete statistics;
    return 0;
}
