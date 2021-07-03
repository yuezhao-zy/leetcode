ass Solution {
    public:
    bool wordBreak(string s, vector<string>& wordDict) {
            bool can_reach[s.size()];
            fill(can_reach,can_reach+s.size(),false);
            can_reach[0] = true;
            for(int i = 0;i < s.size();i ++){
                        if (!can_reach[i])
                            continue;
                        for(int j = 0;j < wordDict.size();j ++){
                                        if (s.substr(i,wordDict[j].length()) == wordDict[j]){
                                                            if (i+wordDict[j].length() == s.size()){
                                                                                    return true;
                                                                                }
                                                            can_reach[i+wordDict[j].length()] = true;
                                                        }

                                    }
                    }
            return false;

        }
};


