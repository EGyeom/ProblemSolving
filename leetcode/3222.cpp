class Solution {
public:
    string winningPlayer(int x, int y) {
        vector<string> players = {"Bob","Alice"};
        int idx = min(x,y/4);
        return players[(idx % 2)];
    }
};