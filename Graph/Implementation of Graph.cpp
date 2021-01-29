#include <bits/stdc++.h>
#include "List.h"
using namespace std;

template<typename a,typename b>
class pairOf{
public:
    a first;
    b second;
    pairOf(a first, b second)
    {
        this->first=first;
        this->second=second;
    }
};

template<typename variable>
class graphNode{
public:
    variable val;
    List<pairOf<graphNode<variable>*,double>>* adjacent;
    graphNode(variable val)
    {
        this->val=val;
        adjacent=nullptr;
    }
    void addNeighbour(graphNode<variable>* neighbour,double distance)
    {
        if(!isAdjacentNode(neighbour))
        {
            if(adjacent==nullptr)
            {
                adjacent=new adjacent<pairOf<graphNode<variable>*,double>>(pairOf(neighbour,distance));
            }
            else{
                adjacent.pushBack(pairOf(neighbour,distance));
            }
        }
        else{
            cout<<"It's already an adjacent node!"<<endl;
        }
    }
    bool isAdjacentNode(graphNode<variable>* neighbour)
    {
        List<pairOf<graphNode<variable>*,double>> temp=adjacent;
       
        while(temp!=nullptr&&temp.next!=nullptr)
        {
            if(temp.val.first==neighbour)
            {
                return true;
            }
            temp=temp.next;
        }
        if(temp.val.first==neighbour)
        {
            return true;
        }
        return false;
    }
    
    
};
template<typename variable>
class Graph{
public:
    int nodeCount;
    vector<graphNode<variable>*> nodes;
    Graph(int nodeCount)
    {
        this->nodeCount=nodeCount;
    }
    graphNode<variable>* addNode(variable a)
    {
        graphNode<variable>* temp=new graphNode<variable>(a)
        nodes.push_back(temp);
        return temp;
    }
    void addDirectedEdge(variable from, variable to, double weight)
    {
        graphNode<variable>* node=isNodePresent(from);
        if(!node)
        {
            node=addNode(from);
        }
        graphNode<variable>* neighbour=isNodePresent(to);
        if(!neighbour)
        {
            neighbour=addNode(to)
        }
        node->addNeighbour(to,weight);
    }
    void addUndirectedEdge(variable from,variable to, double weight)
    {
        addDirectedEdge(from,to,weight);
        addDirectedEdge(to,from,weight);
    }
    graphNode<variable>* isNodePresent(variable val)
    {
        for(int i=0;i<nodes.size();i++)
        {
            if(nodes[i]!=nullptr)
            {
                if(nodes[i]->val==val)
                {
                    return nodes[i];
                }
            }
        }
        return nullptr;
    }
    
};

int main()
{




    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}
