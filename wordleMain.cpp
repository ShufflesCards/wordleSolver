#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
#define ll long long
using vi = vector<int>;
using vvi = vector<vi>;

using vs = vector<string>;
using vvs = vector<vs>;
using vvvs = vector<vvs>;
using vvvvs = vector<vvvs>;
using vvvvvs = vector<vvvvs>;

using vc = vector<char>;

/*
Using Structs

struct WordInfo{
    string word;
    int freq[26];   // frequency arr of each letter

};

big arr of WordInfo

get all words in and att them to the big arr of WordInfo

for green:
    check if word has charachters in the right place

for yellow:
    have a freq arr for how many times each letter appears in the input
    vector<pair<char, int>> yellowIn; // letter, forbiden position
    int minCount[26]; // freq arr of how many times each letter appears. This should not reset after every call to the yellow check function
    
    check freq arr of the yellowIn word against each yellow word
    then check if any words have a letter in the same place as yellowIn


for (const WordInfo& w : words) {
    if (!satisfiesGreen(w))  continue;
    if (!satisfiesYellow(w)) continue;
    if (!satisfiesGray(w))   continue;

candidates.push_back(&w);

as green, yellow, and gray get more restrictive, candidates will get smaller

}


*/






/*
logic
Simple Solution First
This is a naive approach. I am getting rid of every word that can not work. I am unable to see words that do not work, so I can not use them to gain extra information.
only 2315 words
we can be inefficient because of how few words there are

Full list of words
Organized alphabetically, in a multidementional arr
    User enters the poisition of all yellow, green, and all gray

Green:
    do this frst because it has the most restrictions
    copy all words with letter at green spot to arrGreen
    be carful about doubles

Yellow:
    remove all words with letter in yellow spot
    remove all words without the letter

Gray:
    remove all words with gray letters




*/







/*
void printAll(vvvvvs lis){

    auto start1 = high_resolution_clock::now();
    for(const auto &let1 : lis){
        for(const auto &let2 : let1){
            for(const auto &let3 : let2){
                for(const auto &let4 : let3){
                    for(const auto &let5 : let4){
                        if(let5.length() > 3){
                            cout << let5 << " ";
                        }
                    }
                }
            }
        }
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "\n\n\n";
    cout << "Time taken by function 1: "<< duration1.count() << " microseconds" << endl;
    // cout << "Time taken by function 2: "<< duration2.count() << " microseconds" << endl;


}
*/

struct WordInfo{
    string word;    // string of a single word
    int freq[26];   // frequency arr of each letter

};

// all of the words
vector<WordInfo> words;
// all the words that work
vector<const WordInfo*> candidates;


void preprocess(const string& w) {
    WordInfo info;
    info.word = w;
    memset(info.freq, 0, sizeof(info.freq));
    for (char c : w) info.freq[c - 'a']++;

    words.push_back(info);
}


bool satisfiesGreen(const WordInfo& w) {

    return true;
}



vector<pair<char, int>> yellow;  // (letter, forbidden_position)
int minCount[26];                // freq arr of how many times each letter appears. This should not reset after every call to the yellow check function

bool satisfiesYellow(const WordInfo& w) {
    // frequency requirement
    for (int i = 0; i < 26; i++) {
        if (w.freq[i] < minCount[i]) return false;
    }

    // forbidden positions
    for (auto [ch, pos] : yellow) {
        if (w.word[pos] == ch) return false;
    }

    return true;
}

bool satisfiesGray(const WordInfo& w) {

    return true;
}




void solve(){
    ifstream WordleFile("wordle-answers-alphabetical.txt");



    // vvvvvs listTemplate(26, vvvvs(26, vvvs(26, vvs(26, vs(26, "\0")))));

    // vvvvvs allWords = listTemplate;
    
    
    string txt;
    // auto startTxt = high_resolution_clock::now();
    if(true){
        
        while(getline(WordleFile, txt)){

            preprocess(txt);

            //cout << txt << "\n";
            

        }
    }
    WordleFile.close();
    
    







    for (const WordInfo& w : words) {
        if (!satisfiesGreen(w))  continue;
        if (!satisfiesYellow(w)) continue;
        if (!satisfiesGray(w))   continue;
    
        candidates.push_back(&w);
    }




    // /*
    // cout << "first: " << fir << " secold: " << sec << " third: " << thi << " fourth: " << fou << " fifth: " << fif << endl;
    // cout << "first: " << fir-'a' << " secold: " << sec-'a' << " third: " << thi-'a' << " fourth: " << fou-'a' << " fifth: " << fif-'a' << endl;
    // */
    
    // // all letters that can be in the word
    // vc possibleAll = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    

    // /*
    // START OF CODE FOR GREEN
    // */

    // vc definateFir = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    // vc definateSec = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    // vc definateThi = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    // vc definateFou = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    // vc definateFif = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    // cout << "what green charachters do you have? Format with _ for non green. ex if you have a green 'e' and 'a' you would type _ea__ if the word was beans \n";
    // string greenIn; cin >> greenIn;
    // char fir = greenIn[0];
    // char sec = greenIn[1];
    // char thi = greenIn[2];
    // char fou = greenIn[3];
    // char fif = greenIn[4];


    // if(isalpha(fir)){
    //     definateFir.resize(1);
    //     definateFir[0] = fir;
    // }

    // if(isalpha(sec)){
    //     definateSec.resize(1);
    //     definateSec[0] = sec;
    // }
    // if(isalpha(thi)){
    //     definateThi.resize(1);
    //     definateThi[0] = thi;
    // }
    // if(isalpha(fou)){
    //     definateFou.resize(1);
    //     definateFou[0] = fou;
    // }
    // if(isalpha(fif)){
    //     definateFif.resize(1);
    //     definateFif[0] = fif;
    // }

    // vvvvvs greenList = listTemplate;
    // vvvvvs oldWords = allWords;

    


    // for(int i = 0; i < definateFir.size(); i++){
    //     for(int j = 0; j < definateSec.size(); j++){
    //         for(int k = 0; k < definateThi.size(); k++){
    //             for(int h = 0; h < definateFou.size(); h++){
    //                 for(int g = 0; g < definateFif.size(); g++){
    //                     greenList[definateFir[i]-'a'][definateSec[j]-'a'][definateThi[k]-'a'][definateFou[h]-'a'][definateFif[g]-'a'] = oldWords[definateFir[i]-'a'][definateSec[j]-'a'][definateThi[k]-'a'][definateFou[h]-'a'][definateFif[g]-'a'];
    //                     // cout << greenList[definateFir[i]-'a'][definateSec[j]-'a'][definateThi[k]-'a'][definateFou[h]-'a'][definateFif[g]-'a'] << " ";
    //                 }
    //             }
    //         }
    //     }
    // }


    // printAll(greenList);



    // /*
    // END OF CODE FOR GREEN
    // */




    // cout << "what yellow charachters do you have? Format with _ for non yellow. \n";
    // string yellowIn; cin >> yellowIn;
   
    // // yellow list includes stuff from green list
    // vvvvvs yellowList = listTemplate; // this is slow

    // // seperate loop for each letter

    // vc possibleFir = {};
    // vc possibleSec = {};
    // vc possibleThi = {};
    // vc possibleFou = {};
    // vc possibleFif = {};

    // if(isalpha(yellowIn[0])){
    //     auto new_end = remove(definateFir.begin(), definateFir.end(), yellowIn[0]);
    //     definateFir.erase(new_end, definateFir.end());
    // }
    // if(isalpha(yellowIn[1])){
    //     auto new_end = remove(definateSec.begin(), definateSec.end(), yellowIn[1]);
    //     definateSec.erase(new_end, definateSec.end());
    // }
    // if(isalpha(yellowIn[2])){
    //     auto new_end = remove(definateThi.begin(), definateThi.end(), yellowIn[2]);
    //     definateThi.erase(new_end, definateThi.end());
    // }
    // if(isalpha(yellowIn[3])){
    //     auto new_end = remove(definateFou.begin(), definateFou.end(), yellowIn[3]);
    //     definateFou.erase(new_end, definateFou.end());
    // }
    // if(isalpha(yellowIn[4])){
    //     auto new_end = remove(definateFif.begin(), definateFif.end(), yellowIn[4]);
    //     definateFif.erase(new_end, definateFif.end());
    // }

    // for(int i = 0; i < yellowIn.size(); i++){
    //     if(!isalpha(yellowIn[i])){
    //         continue;
    //     }
    //     if(yellowIn[0] != yellowIn[i])
    //         possibleFir.push_back(yellowIn[i]);
    // }
    // for(int i = 0; i < yellowIn.size(); i++){
    //     if(!isalpha(yellowIn[i])){
    //         continue;
    //     }
    //     if(yellowIn[1] != yellowIn[i])
    //         possibleSec.push_back(yellowIn[i]);
    // }
    // for(int i = 0; i < yellowIn.size(); i++){
    //     if(!isalpha(yellowIn[i])){
    //         continue;
    //     }
    //     if(yellowIn[2] != yellowIn[i])
    //         possibleThi.push_back(yellowIn[i]);
    // }
    // for(int i = 0; i < yellowIn.size(); i++){
    //     if(!isalpha(yellowIn[i])){
    //         continue;
    //     }
    //     if(yellowIn[3] != yellowIn[i])
    //         possibleFou.push_back(yellowIn[i]);
    // }
    // for(int i = 0; i < yellowIn.size(); i++){
    //     if(!isalpha(yellowIn[i])){
    //         continue;
    //     }
    //     if(yellowIn[4] != yellowIn[i])
    //         possibleFif.push_back(yellowIn[i]);
    // }


    // if(definateFir.size() == 1){
    //     possibleFir = definateFir;
    // }
    // if(definateSec.size() == 1){
    //     possibleSec = definateSec;
    // }
    // if(definateThi.size() == 1){
    //     possibleThi = definateThi;
    // }
    // if(definateFou.size() == 1){
    //     possibleFou = definateFou;
    // }
    // if(definateFif.size() == 1){
    //     possibleFif = definateFif;
    // }


    // // cout << "Possible First\n";
    // // for(auto c : possibleFir){
    // //     cout << c << " ";
    // // }
    // // cout << "\nPossible Second\n";
    // // for(auto c : possibleSec){
    // //     cout << c << " ";
    // // }
    // // cout << endl;




    // /*
    // does not work
    // */

    // /*
    // // locks first letter to be one of the possible yellow letters
    // for(int i = 0; i < possibleFir.size(); i++){
    //     for(int j = 0; j < definateSec.size(); j++){
    //         for(int k = 0; k < definateThi.size(); k++){
    //             for(int h = 0; h < definateFou.size(); h++){
    //                 for(int g = 0; g < definateFif.size(); g++){
    //                     yellowList[possibleFir[i]-'a'][definateSec[j]-'a'][definateThi[k]-'a'][definateFou[h]-'a'][definateFif[g]-'a'] = greenList[possibleFir[i]-'a'][definateSec[j]-'a'][definateThi[k]-'a'][definateFou[h]-'a'][definateFif[g]-'a'];
    //                 }
    //             }
    //         }
           
    //     }
    // }

    // // locks second letter to be one of the possible yellow letters
    // for(int i = 0; i < definateFir.size(); i++){
    //     for(int j = 0; j < possibleSec.size(); j++){
    //         for(int k = 0; k < definateThi.size(); k++){
    //             for(int h = 0; h < definateFou.size(); h++){
    //                 for(int g = 0; g < definateFif.size(); g++){
    //                     yellowList[definateFir[i]-'a'][possibleSec[j]-'a'][definateThi[k]-'a'][definateFou[h]-'a'][definateFif[g]-'a'] = greenList[definateFir[i]-'a'][possibleSec[j]-'a'][definateThi[k]-'a'][definateFou[h]-'a'][definateFif[g]-'a'];
    //                 }
    //             }
    //         }
           
    //     }
    // }

    // // lock third letter
    // for(int i = 0; i < definateFir.size(); i++){
    //     for(int j = 0; j < definateSec.size(); j++){
    //         for(int k = 0; k < possibleThi.size(); k++){
    //             for(int h = 0; h < definateFou.size(); h++){
    //                 for(int g = 0; g < definateFif.size(); g++){
    //                     yellowList[definateFir[i]-'a'][definateSec[j]-'a'][possibleThi[k]-'a'][definateFou[h]-'a'][definateFif[g]-'a'] = greenList[definateFir[i]-'a'][definateSec[j]-'a'][possibleThi[k]-'a'][definateFou[h]-'a'][definateFif[g]-'a'];
    //                 }
    //             }
    //         }
           
    //     }
    // }

    // // lock in fourth letter
    // for(int i = 0; i < definateFir.size(); i++){
    //     for(int j = 0; j < definateSec.size(); j++){
    //         for(int k = 0; k < definateThi.size(); k++){
    //             for(int h = 0; h < possibleFou.size(); h++){
    //                 for(int g = 0; g < definateFif.size(); g++){
    //                     yellowList[definateFir[i]-'a'][definateSec[j]-'a'][definateThi[k]-'a'][possibleFou[h]-'a'][definateFif[g]-'a'] = greenList[definateFir[i]-'a'][definateSec[j]-'a'][definateThi[k]-'a'][possibleFou[h]-'a'][definateFif[g]-'a'];
    //                 }
    //             }
    //         }
           
    //     }
    // }

    // // lock in fifth letter
    // for(int i = 0; i < definateFir.size(); i++){
    //     for(int j = 0; j < definateSec.size(); j++){
    //         for(int k = 0; k < definateThi.size(); k++){
    //             for(int h = 0; h < definateFou.size(); h++){
    //                 for(int g = 0; g < possibleFif.size(); g++){
    //                     yellowList[definateFir[i]-'a'][definateSec[j]-'a'][definateThi[k]-'a'][definateFou[h]-'a'][possibleFif[g]-'a'] = greenList[definateFir[i]-'a'][definateSec[j]-'a'][definateThi[k]-'a'][definateFou[h]-'a'][possibleFif[g]-'a'];
    //                 }
    //             }
    //         }
           
    //     }
    // }


    // */

    
    // /*
    // for(int i = 0; i < greenList.size(); i++){
    //     for(int j = 0; j < greenList[i].size(); j++){
    //         for(int k = 0; k < greenList[i][j].size(); k++){
    //             for(int h = 0; h < greenList[i][j][k].size(); h++){
    //                 for(int g = 0; g < greenList[i][j][k][h].size(); g++){
    //                     // check if this has all the letters fom yellowIn
    //                     yellowList[i][j][k][h][g] = greenList[i][j][k][h][g];
    //                 }
    //             }
    //         }
    //     }
    // }
    // */


    // cout << "\n\nyellowList\n\n";
    // printAll(yellowList);

    

}

int main(){
    
    
    solve();


    return 0;
}