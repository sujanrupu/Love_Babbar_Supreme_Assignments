class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        vector<int> result(N, 0);
        sort(deck.begin(), deck.end());
        everyOther(deck, result, 0, 0, false);
        return result;
    }
    
    void everyOther(vector<int>& deck, vector<int>& result, int indexInDeck, int indexInResult, bool skip) {
        int N = deck.size();
        if (indexInDeck == N) return;
        while (indexInResult < N) {
            if (result[indexInResult] == 0) {
                if (!skip) {
                    result[indexInResult] = deck[indexInDeck];
                    indexInDeck++;
                }
                skip = !skip;
            }
            indexInResult++;
        }
        everyOther(deck, result, indexInDeck, 0, skip);
    }
};
