// maybe I can edit this to not lose position


#include <bits/stdc++.h>
using namespace std;

void generate(string& cur,
              const string& chars,
              int k,
              int pos,
              int reqMask,
              int curMask)
{
    if (pos == k) {
        if ((curMask & reqMask) == reqMask) {
            cout << cur << '\n';
        }
        return;
    }

    for (char c : chars) {
        cur[pos] = c;

        int nextMask = curMask;
        if ('a' <= c && c <= 'z')
            nextMask |= 1 << (c - 'a'); // nextMask becoems all the charachters I need.

        generate(cur, chars, k, pos + 1, reqMask, nextMask);
    }
}


int main()
{
    string chars = "abcdefghijk";   // alphabet
    string required = "ach";  // must appear
    // char required[5] = {'_','_','_','_','_'};
    // required[0] = 'a';
    // required[1] = 'c';
    // required[2] = 'h';
    int k = 4;               // length of output strings

    string testWord = "ahjioc";
    int testMask = 0;
    for (char c : testWord){
        if(c != '_')
            testMask |= 1 << (c - 'a');
    }
    // Build required mask
    int reqMask = 0;
    for (char c : required){
        if(c != '_')
            reqMask |= 1 << (c - 'a');
    }

    
    // reqMask is 1 and 0 of does the letter appear
    // a b c
    // 1 0 1

    cout << reqMask << endl;
    cout << testMask << endl;

    if((testMask & reqMask) == reqMask){
        cout << "the word works";
    }




    


    
    string cur(k, ' ');
    //generate(cur, chars, k, 0, reqMask, 0);

    return 0;
}