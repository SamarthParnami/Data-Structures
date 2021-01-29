#include <bits/stdc++.h>

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
class List{
public:
    variable val;
    List* next=nullptr;

    List(variable val,List* next=nullptr)
    {
        this->val=val;
        this->next=next;
    }
    void pushBack(variable val)
    {
        List* start=this;
        while(start->next!=nullptr)
        {
            start=start->next;
        }
        start->next=new List<variable>(val);
    }
    List* popFront()
    {
        List* nex=this->next;
        delete this;
        return nex;
    }
    void pop()
    {

        List* start=this;
        while(start->next->next!=nullptr)
        {
            start=start->next;
        }
        delete start->next;
        start->next=nullptr;
    }
    List* invertList()
    {
        List* head=this;
        List* prev=nullptr;
        while(head->next!=nullptr)
        {
            List* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        head->next=prev;
        return head;
    }


};
template<typename variable>
class graphNode{
public:
    variable val;
    List<pairOf<graphNode<variable>*,double>*>* adjacent;
    bool visited;
    graphNode(variable val)
    {
        this->val=val;
        adjacent=nullptr;
    }
    void addNeighbour(graphNode<variable>* neighbour,double distance)
    {

        if(!isAdjacentNode(neighbour))
        {

            pairOf<graphNode<variable>*,double>* temp=new pairOf<graphNode<variable>*,double>(neighbour,distance);
            if(adjacent==nullptr)
            {
                adjacent=new List<pairOf<graphNode<variable>*,double>*>(temp);
            }
            else{
                adjacent->pushBack(temp);
            }
        }
        else{
            cout<<"It's already an adjacent node!"<<endl;
        }

    }
    bool isAdjacentNode(graphNode<variable>* neighbour)
    {
        List<pairOf<graphNode<variable>*,double>*>* temp=adjacent;

        while(temp!=nullptr)
        {

            if(temp->val->first==neighbour)
            {
                return true;
            }
            temp=temp->next;
        }


        return false;
    }
    void setVisited(bool visited)
    {
        this->visited=visited;
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

        graphNode<variable>* temp=new graphNode<variable>(a);
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
            neighbour=addNode(to);
        }
        node->addNeighbour(neighbour,weight);

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
    vector<variable> BFS(variable from)
    {

        vector<variable> ans;
        graphNode<variable>* start=isNodePresent(from);
        queue<graphNode<variable>*> travel;
        for(int i=0;i<nodes.size();i++)
        {
            if(nodes[i]!=nullptr)
            {
                nodes[i]->setVisited(false);
            }
        }

        ans.push_back(start->val);
        start->setVisited(true);
        List<pairOf<graphNode<variable>*,double>*>* neighbour=start->adjacent;
        while(neighbour!=nullptr)
        {
            if(!neighbour->val->first->visited)
            {
                ans.push_back(neighbour->val->first->val);
                travel.push(neighbour->val->first);
                neighbour->val->first->setVisited(true);
            }
            neighbour=neighbour->next;
        }

        while(!travel.empty())
        {
            neighbour=travel.front()->adjacent;
            while(neighbour!=nullptr)
            {
                if(!neighbour->val->first->visited)
                {
                    ans.push_back(neighbour->val->first->val);
                    travel.push(neighbour->val->first);
                    neighbour->val->first->setVisited(true);
                }
                neighbour=neighbour->next;
            }
            travel.pop();
        }

        return ans;
    }

};
void printVector(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Graph <int> taste(5);
    taste.addUndirectedEdge(-1,44,1);
    taste.addUndirectedEdge(-1,9,15);
    taste.addUndirectedEdge(44,55,1);
    taste.addUndirectedEdge(44,9,4);
    printVector(taste.BFS(-1));



    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}
