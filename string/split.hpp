auto split = [](string s, char c) -> vector<string> {
    vector<string> S;
    string t;
    for (char &&v : s) {
        if (v == c) {
            if (!t.empty()) S.push_back(t);
            t.clear();
        } else {
            t += v;
        }
    }
    if (!t.empty()) S.push_back(t);
    return S;
};
