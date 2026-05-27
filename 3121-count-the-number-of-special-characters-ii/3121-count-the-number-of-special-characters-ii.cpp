class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26> isValid, seenUpper, seenLower;
isValid.set();

    for(char c : word){
        if(islower(c)){
            int idx = c - 'a';
            if(seenUpper[idx]){
                isValid[idx] = 0;
            }
            seenLower[idx] = 1;
        }
        else{
            int idx = c - 'A';
            seenUpper[idx] = 1;
        }
    }

    int special = 0;

    for(int i = 0; i < 26; ++i){
        if(isValid[i] && seenLower[i] && seenUpper[i]){
            ++special;
        }
    }

    return special;
  }
};