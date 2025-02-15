class RollingHash {
public:
    using LL = long long;
    LL mod1, base, mod2;
    vector<LL> h1, p1;
    vector<LL>h2, p2;
    template<class T>
    RollingHash(const T& data, LL mod1,LL mod2, LL base): mod1(mod1),mod2(mod2), base(base), h1{0}, p1{1}, h2{0}, p2{1} {
        for(auto d: data) {
            h1.push_back((h1.back() * base % mod1 + (LL)d) % mod1);
            p1.push_back(p1.back() * base % mod1);
            h2.push_back((h2.back() * base % mod2 + (LL)d) % mod2);
            p2.push_back(p2.back() * base % mod2);
        }
    }
    pair<LL,LL> get(int l, int r) {
        return {(h1[r + 1] - h1[l] * p1[r - l + 1] % mod1 + mod1) % mod1, 
            (h2[r + 1] - h2[l] * p2[r - l + 1] % mod2 + mod2) % mod2};
    }
};
