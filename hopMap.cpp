#include "hopMap.h"

hopMap::hopMap() {
    //ctor
}

hopMap::~hopMap() {
    //dtor
}

//creates a new node with the given string and adds it to
//the network
void hopMap::addNode(string name) {
    mapNode* node = new mapNode;
    node->setName(name);
    nodeArray.push_back(node);
}

//given a string name this function finds the node in the
//network that contains said string
mapNode* hopMap::findNode(string name) {
    for (int i=0; i <nodeArray.size(); i++ ) {
        if ( nodeArray[i]->getName() == name )
            return nodeArray[i];
    }
    return NULL;
}

//only used for testing purposes
//prints out all network members followed by their followers
void hopMap::print() {
    for (int i=0; i <nodeArray.size(); i++ ) {
        std::cout<<std::endl;
        std::cout<<nodeArray[i]->getName()<<": ";
        for (int z=0; z < nodeArray[i]->followers.size(); z++){
            std::cout<<nodeArray[i]->followers[z]->getName()<<" ";
        }
    }
}

//this function calculates the minimum number of hops between
//two nodes in the network (given)
int hopMap::minHops(mapNode* start, mapNode* finish){
    int hops = 0;
    mapNode* temp = new mapNode;

    //make a queue to keep track of nodes to explore
    queue<mapNode*> nodeQueue;
    nodeQueue.push(start);
    start->setDistance(0);

    while (!nodeQueue.empty()){
        temp = nodeQueue.front();
        nodeQueue.pop();
        //sets hops by "generation" or distance of ancestor
        hops = 1 + temp->getDistance();

        //if we find our final node return distance
        if (temp == finish)
            return temp->getDistance();

        //add all unexplored followers of current node to the queue
        for (int i=0; i < temp->followers.size(); i++){
            if (temp->followers[i]->getDistance() == -1){
                temp->followers[i]->setDistance(hops);
                nodeQueue.push(temp->followers[i]);
            }
        }
    }

    //all nodes have been examined and we have
    //not found the finish. return -1
    return -1;
}

//Resets distance flags for all nodes in the network
void hopMap::cleanDistance(){
    for (int i=0; i<nodeArray.size(); i++){
        nodeArray[i]->setDistance(-1);
    }
}
