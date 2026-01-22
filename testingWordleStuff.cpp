#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;
#define ll long long
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;

using vs = vector<string>;
using vvs = vector<vs>;
using vvvs = vector<vvs>;
using vvvvs = vector<vvvs>;
using vvvvvs = vector<vvvvs>;

using vc = vector<char>;

/*
checks if the second thing is in the first thing
*/
template <typename Container, typename T>
bool isIn(const Container& c, const T& x) {
    return find(begin(c), end(c), x) != end(c);
}

int main(){


    // vvi orig = {{1,2,3},{4,5,6},{7,8,9}, {10,11,12}};
    // vvi sub(&orig[1],&orig[3]);
    // for(int i = 0; i < sub.size(); i++){
    //     for(int j = 0; j < sub[i].size(); j++){
    //         cout << sub[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // vi ori = {1,2,3,4,5,6,7,8,9};
    // int star = 3;
    // int en = 7;
    // for(star; star <= en; star++){
    //     cout << ori[star] << endl;
    // }

    // cout << "things happened";

    // vvvi bigList= {{{111,112},{121,122},{131,132}},{{211,212},{221,222},{231,232}},{{311,312},{321,322},{331,332}},{{411,412},{421,422},{431,432}}};

    // vvvi newList(vvvi(4, vvi(3, vi(2, 5))));

    // newList[0] = bigList[0]; 
    // Copies over only stuff where the number in the hundereds place works

    // for(int i = 0; i < newList.size(); i++){
    //     for(int j = 0; j < newList[i].size(); j++){
    //         newList[i][1] = bigList[i][1];
    //     }
    // }
    // Copies over only stuff where the number in the tens place works

    // for(int i = 0; i < newList.size(); i++){
    //     for(int j = 0; j < newList[i].size(); j++){
    //         for(int k = 0; k < newList[i][j].size(); k++){
    //             newList[i][j][1] = bigList[i][j][1];
    //         }
    //     }
    // }
    // Coppies stuff over only when stuff in the oens place works

    // these filters do not work together, I will try to make a new filter

    /*
    int istart = 0;
    int iend = 4;
    int jstart = 0;
    int jend = 3;
    int kstart = 0;
    int kend = 2;
    
    jstart = 1;
    jend = 2;
    kstart = 0;
    kend = 1;

    for(int i = istart; i < iend; i++){
        for(int j = jstart; j < jend; j++){
            for(int k = kstart; k < kend; k++){
                newList[i][j][k] = bigList[i][j][k];
            }
        }
    }
    // this works with the 3 digits together


    for(int i = 0; i < newList.size(); i++){
        for(int j = 0; j < newList[i].size(); j++){
            for(int k = 0; k < newList[i][j].size(); k++){
                
                    cout << newList[i][j][k] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
    

    */

    /*
    char letter[5];
    letter[0] = 'a';
    letter[3] = 'd';

    for(auto thing : letter){
        cout << thing << " ";
    }
    cout << endl;

    for(int i = 0; i < size(letter); i++){
        if(i != letter[i]){
            cout << "letter ";
        }
        cout << letter[i] << " ";
    }
    cout << endl;
    */
    

    /*
    // for loop for each digit of a number
    // lets say we want the digit 5 to be in here somewhere

    int val = 2;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                for(int h = 0; h < 10; h++){
                    
                    // if none of the numbers == val
                    if( ((i != val) && (j != val) && (k != val) && (h != val))){
                        if(h < val){
                            h = val;
                        } else if(k < val){
                            k = val;
                            h = 0;
                        } else if(j < val){
                            j = val;
                            k = 0;
                            h = 0;
                        } else if(i < val){
                            i = val;
                            j = 0;
                            k = 0;
                            h = 0;
                        } else{
                            // end loop
                            break;
                        }
                    }

                    cout << i << j << k << h << ", ";

                }
            }
        }

    }

    */

    // now to make this exclude val at a position


    // yellowInts works the same way val does previously, but as an array
    /*
    int yellowInts[5] = {-1, -1, -1, -1, -1};
    yellowInts[0] = 3;
    yellowInts[4] = 7;

    int bitmask = 0;
    for(int i : yellowInts){
        if(i != -1)
        bitmask |= 1 << (i);
    }

    cout << bitmask;
    */
    /*
    if(find(begin(yellowInts), end(yellowInts), 7) != end(yellowInts)){
        cout << "5 was in the array";
    }

    if( ((isIn(yellowInts, i)) && (isIn(yellowInts, j)) && (isIn(yellowInts, k)) && (isIn(yellowInts, h))))
    */

    

    
    /*
    int val = 2;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                for(int h = 0; h < 10; h++){
                    
                    // in real code, I could just check isalpha instead of hard coding in what spots the yellowInts are in

                    // if none of the numbers = yellowInts[0]
                    // delte i != later, since it is yellow at i, we know the letter is not there
                    if( ((i != yellowInts[0]) && (j != yellowInts[0]) && (k != yellowInts[0]) && (h != yellowInts[0]))){
                        // I need to include this
                    }

                    // if( ((i != yellowInts[1]) && (j != yellowInts[1]) && (k != yellowInts[1]) && (h != yellowInts[1]))){

                    // }

                    // if( ((i != yellowInts[2]) && (j != yellowInts[2]) && (k != yellowInts[2]) && (h != yellowInts[2]))){

                    // }

                    // if( ((i != yellowInts[3]) && (j != yellowInts[3]) && (k != yellowInts[3]) && (h != yellowInts[3]))){

                    // }

                    // if none of the numbers = yellowInts[4]
                    if( ((i != yellowInts[4]) && (j != yellowInts[4]) && (k != yellowInts[4]) && (h != yellowInts[4]))){

                    }

                    // if none of the numbers == val
                    if( ((i != val) && (j != val) && (k != val) && (h != val))){
                        if(h < val){
                            h = val;
                        } else if(k < val){
                            k = val;
                            h = 0;
                        } else if(j < val){
                            j = val;
                            k = 0;
                            h = 0;
                        } else if(i < val){
                            i = val;
                            j = 0;
                            k = 0;
                            h = 0;
                        } else{
                            // end loop
                            break;
                        }
                    }

                    cout << i << j << k << h << ", ";

                }
            }
        }

    }

    */

    // vvvi bigList = {{{111,112},{121,122},{131,132}},{{211,212},{221,222},{231,232}},{{311,312},{321,322},{331,332}},{{411,412},{421,422},{431,432}}};
    // vvvi newList(vvvi(4, vvi(3, vi(2))));

    // make a pruning algorithm with .clear and .erase
    // bigList[1].clear();


    // for(int i = 0; i < bigList.size(); i++){
    //     if(!bigList[i].empty()){
    //         for(int j = 0; j < bigList[i].size(); j++){
    //             if(!bigList[i][j].empty()){
    //                 for(int k = 0; k < bigList[i][j].size(); k++){
    //                         cout << bigList[i][j][k] << ", ";
    //                 }
    //                 cout << endl;
    //             }
    //         }
    //         cout << endl;
    //     }
    // }
    /*
    newList[1][1] = bigList[1][1];

    
    for(int i = 0; i < newList.size(); i++){
        if(!newList[i].empty()){
            for(int j = 0; j < newList[i].size(); j++){
                if(!newList[i][j].empty()){
                    bool emptyList = true;
                    for(int k = 0; k < newList[i][j].size(); k++){
                            emptyList = true;
                            if(newList[i][j][k] != 0){ // this means there is at least one item in that list
                                emptyList = false;
                            }

                    }
                    if(emptyList){
                        newList[i][j].clear();
                        j--;
                    }

                }
            }
            // cout << endl;
        }
    }

    
    int x = 0;
    */
    // doing it this way does not work
    // for(int i = 0; i < newList.size() && !newList[i].empty(); i++){

    //         for(int j = 0; j < newList[i].size() && !newList[i][j].empty(); j++){

    //                 for(int k = 0; k < newList[i][j].size(); k++){
    //                         cout << newList[i][j][k] << ", ";
    //                         x++;
    //                 }
    //                 cout << endl;
                
    //         }
    //         cout << endl;
        
    // }
    
    // for(const auto &hundo : newList){
    //     if(!hundo.empty()){
    //         for(const auto &ten : hundo){
    //             if(!ten.empty()){
    //                 for(const auto &one : ten){
    //                     cout << one << " ";
    //                     x++;
    //                 }
    //             }
    //         }
    //     }
    // }


    // cout << x;


    
    // for(int i = 0; i < newList.size(); i++){
    //     for(int j = 0; j < newList[i].size(); j++){
    //         for(int k = 0; k < newList[i][j].size(); k++){
    //             cout << newList[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    



    // all lists start with them being full of all the letters

    // vc possibleAll = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    vc possibleAll = {'a','b','c','d','e','f','g','h','i'};
    vc possibleFirst = {'a','b'};
    vc possibleSecond = {'a','b'};
    vc possibleThird = {'a','b'};
    vc possibleFourth = {'a','b'};
    vc possibleFifth = {'a','b', 'c', 'd'};

    auto new_end = remove(possibleFifth.begin(), possibleFifth.end(), 'b');
    possibleFifth.erase(new_end, possibleFifth.end());

    for(auto c : possibleFifth){
        cout << c << " ";
    }

    // // get all the ones where the first letter works
    // for(int i = 0; i < possibleFirst.size(); i++){
    //     for(int j = 0; j < possibleSecond.size(); j++){
    //         for(int k = 0; k < possibleThird.size(); k++){
    //             cout << possibleFirst[i] << possibleSecond[j] << possibleThird[k] << "\n";
    //         }
    //     }
    // }

    return 0;

}


