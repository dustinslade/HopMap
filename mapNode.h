#ifndef MAPNODE_H
#define MAPNODE_H
#include <string>
#include <vector>

using std::string; using std::vector;
class mapNode
{
    public:
        mapNode();
        virtual ~mapNode();

        void setName(string name) { this->name = name; }
        string getName() { return name; }
        void addFollower(mapNode* node) { followers.push_back(node); }

        void setDistance(int val) { distance = val; }
        int getDistance() { return distance; }

        vector<mapNode*> followers;

    private:
    string name;
    int distance;
};

#endif // MAPNODE_H
