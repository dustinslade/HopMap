#include <iostream>
#include <sstream>
#include "hopMap.h"

using std::cout; using std::cin; using std::endl; using std::string;

int main() {

    //set up variables
    int size;
    hopMap hopMap;
    string name; string follower; string followee; string str; string start; string finish;

    /*
     * First Input:
     * take in users in network
     */
    cin >> size;
    for (int i=0; i<size; i++){
        cin >> name;
        hopMap.addNode(name);
    }


    /*
     * Second Input:
     * take in connections in network
     */
    cin >> size;
    getline (cin,str);
    for (int i=0; i<size; i++) {

        getline (cin,str);
        std::istringstream ss(str);
        string x;
        int z=0;

        while ( getline(ss, x, ' ') ) {
            if (z == 0)
                follower = x;

            else if (z == 1){}

            else if (z == 2)
                followee = x;

            z++;
        }
        //add follower to followee's vector of followers
        hopMap.findNode(followee)->addFollower( hopMap.findNode(follower) ) ;
    }

    /*
     * Third Input:
     * calculate hops
     */
    cin >> size;
    getline (cin,str);
    for (int i=0; i<size; i++) {

        hopMap.cleanDistance();
        getline (cin,str);
        std::istringstream ss(str);
        string x;
        int z=0;

        while ( getline(ss, x, ' ') ) {
            if (z == 0)
                start = x;

            else if (z == 1)
                finish = x;

            z++;
        }

        cout<<hopMap.minHops( hopMap.findNode(start), hopMap.findNode(finish) )<<endl;
    }

}
