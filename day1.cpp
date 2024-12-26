#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(const string& n1, const string& n2) {
    size_t dot1 = n1.find('.');
    size_t dot2 = n2.find('.');

    int x1 = (dot1 != string::npos) ? stoi(n1.substr(0, dot1)) : stoi(n1);
    int x2 = (dot2 != string::npos) ? stoi(n2.substr(0, dot2)) : stoi(n2);

    if (x1 != x2) {
        return x1 < x2;
    }

    int y1 = (dot1 != string::npos) ? stoi(n1.substr(dot1 + 1)) : -1;
    int y2 = (dot2 != string::npos) ? stoi(n2.substr(dot2 + 1)) : -1;

    return y1 < y2;
}



int main() {
    int N;
    cin >> N;

    vector<string> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << numbers[i] << endl;
    }

    return 0;
    }