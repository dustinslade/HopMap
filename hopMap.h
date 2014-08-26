#ifndef HOPMAP_H
#define HOPMAP_H
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include "mapNode.h"

using std::vector;
using std::string;
using std::queue;

class hopMap
{
    public:
        hopMap();
        virtual ~hopMap();
        void print();

        void addNode(string name);
        mapNode* findNode(string name);
        int minHops(mapNode* start, mapNode* finish);
        void cleanDistance();

    private:
        vector<mapNode*> nodeArray;
};

#endif // HOPMAP_H
