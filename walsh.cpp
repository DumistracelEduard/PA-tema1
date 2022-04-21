#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using std::ifstream;
using std::vector;

class WALSH{
 public:
    void solve() {
        read_data();
        print_output();
    }

 private:
    int N, K;

    std::vector<pair<int, int>> v;

    std::vector<int> result;

    void read_data() {
        ifstream input_data;
        input_data.open("walsh.in");
        if (!input_data) {
            printf("error\n");
        }
        input_data >> N;
        input_data >> K;

        while (!input_data.eof()) {
            int data_1;
            int data_2;
            input_data >> data_1;
            input_data >> data_2;

            v.push_back(make_pair(data_1, data_2));
        }
        input_data.close();
    }

    bool help(int x, int y, int tlx, int tly, int drx, int dry) {
        return (tlx <= x && x <= drx) && (tly <= y && y <= dry);
    }

    int get_element(int x, int y, int tlx, int tly, int D, int lower,
        int upper, int max) {
        if (D == 1) {
            if (max % 2 == 0)
                return 0;
            else
                return 1;
        }

        int drx = tlx + D - 1;
        int dry = tly + D - 1;

        int mx = (tlx + drx) / 2;
        int my = (tly + dry) / 2;

        int new_D = (D / 2);
        int cnt = (upper - lower + 1) / 4;

        /* stanga-sus */
        int new_lower = lower;
        int new_upper = new_lower + cnt - 1;

        if (help(x, y, tlx, tly, mx, my)) {
            return get_element(x, y, tlx, tly, new_D,
                new_lower, new_upper, max);
        }

        /* dreapta-sus */
        new_lower += cnt;
        new_upper += cnt;

        if (help(x, y, tlx, my + 1, mx, dry)) {
            return get_element(x, y, tlx, my + 1, new_D,
                new_lower, new_upper, max);
        }

        /* stanga-jos */
        new_lower += cnt;
        new_upper += cnt;

        if (help(x, y, mx + 1, tly, drx, my)) {
            return get_element(x, y, mx + 1, tly, new_D,
                new_lower, new_upper, max);
        }

        /* dreapta-jos */
        new_lower += cnt;
        new_upper += cnt;

        if (help(x, y, mx + 1, my + 1, drx, dry)) {
            max++;
            return get_element(x, y, mx + 1, my + 1, new_D,
                new_lower, new_upper, max);
        }

        return -1;
    }

    void get_result() {
        int D = N;
        int lower = 1;
        int upper = D * D;
        for (int i = 0; i < K; ++i) {
            result.push_back(get_element(v[i].first, v[i].second,
                1, 1, D, lower, upper, 0));
        }
    }

    void print_output() {
        /*Printare in fisierul de out*/
        ofstream outfile("walsh.out");
        get_result();
        for (int i = 0; i < K; ++i) {
            outfile << result[i];
            outfile << "\n";
        }
        outfile.close();
    }
};


int main(int argc, char **argv) {
    auto* walsh = new (nothrow) WALSH();
    if (!walsh) {
        cerr << "Error\n";
        return -1;
    }
    walsh->solve();
    delete walsh;
    return 0;
}
