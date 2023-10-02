class Solution {
public:
    bool winnerOfGame(string colors) {
        // variables to store the total number of moves possible by Alice and Bob
        int alice = 0;
        int bob = 0;

        // will count the consequent same colors
        int cnt = 0;
        // will store the color of prev position
        char prev = colors[0];

        // counting the moves possibles
        for(char ch: colors)
        {
            if(ch == prev)
                cnt++;
            else
            {
                if(prev == 'A')
                    alice += max(0, cnt - 2);
                else
                    bob += max(0, cnt - 2);
                prev = ch;
                cnt = 1;
            }
        }
        if(prev == 'A')
            alice += max(0, cnt - 2);
        else
            bob += max(0, cnt - 2);

        // if Alice can make more moves than Bob, then Alice wins
        if(alice > bob)
            return true;

        // else Bob wins
        return false;
    }
};