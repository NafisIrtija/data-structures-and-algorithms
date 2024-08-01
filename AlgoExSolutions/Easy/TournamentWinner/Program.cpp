#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string tournamentWinner(const vector<vector<string>>& competitions, const vector<int>& results)
{
    unordered_map<string, int> points{};
    for( int i = 0; i < competitions.size(); ++i) {
        points[competitions[i][!results[i]]] += 3;
        points[competitions[i][results[i]]] += 0;
    }
    auto compare = [](const pair<string, int>& p1, const pair<string, int>& p2) { return p1.second < p2.second; };
    auto winner = max_element(points.begin(), points.end(), compare);
    return winner->first;
}
int main()
{   
    vector<vector<string>> competitions { {"HTML", "C#"},
                                          {"C#", "Python"},
                                          {"Python", "HTML"} };
    vector<int> results {0, 0, 1};
    
    string winner = tournamentWinner(competitions, results);
    cout << winner << endl;
    return 0;
}
