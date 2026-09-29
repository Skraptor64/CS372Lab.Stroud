//outlined in ms copilot
#include <iostream>
#include <vector>
using namespace std;

int josephus(int N, int M) {
    vector<int> players;
    players.reserve(N);

    for (int i = 1; i <= N; ++i)
        players.push_back(i);

    int index = 0;

    while (players.size() > 1) {
        index = (index + M) % players.size();
        players.erase(players.begin() + index);
    }

    return players[0];
}

int main() {
    int N, M;
    cout << "Enter number of players: ";
    cin >> N;
    cout << "Enter number of passes: ";
    cin >> M;

    int winner = josephus(N, M);
    cout << winner << ", win!" << endl;

    return 0;
}
