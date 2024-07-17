bool isWord(string &s, int start, int end, vector<string> &dictionary) {
    string word = s.substr(start, end - start + 1);
    unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
    return dictSet.find(word) != dictSet.end();
}

void helper(int ind, int n, vector<string> &dictionary, string &s, vector<string> &ans, string &currentString) {
    if (ind == n) {
        ans.push_back(currentString.substr(0, currentString.size() - 1)); // Remove trailing space
        return;
    }

    for (int end = ind; end < n; ++end) {
        if (isWord(s, ind, end, dictionary)) {
            string word = s.substr(ind, end - ind + 1);
            currentString.append(word + " ");
            helper(end + 1, n, dictionary, s, ans, currentString);
            currentString.erase(currentString.size() - word.size() - 1, word.size() + 1);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary) {
    vector<string> ans;
    string currentString = "";
    helper(0, s.size(), dictionary, s, ans, currentString);
    return ans;
}