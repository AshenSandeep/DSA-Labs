#include <iostream>
#include<list>
using namespace std;

struct Node{
    
    int label;
    list<int> neighbours;
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    struct Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            // Node nodes[i] ;
            nodes[i].label=i+1;
        }
    }

    void addedge(int u, int v){
        nodes[u-1].neighbours.push_back(v);
        //select node u and push v into u's neighbour
        nodes[v-1].neighbours.push_back(u);
        //select node v and push u into v's neighbour
    }

    void print(){
        for(int i=0;i<n;i++){
            cout<<nodes[i].label<<"-->";
            for(int j : nodes[i].neighbours){
                cout<<j<<" - ";
                
            }
            cout<<endl;
        }
        //lets iterate through each node and print its neighbours

    }
};

int main() {
   struct Graph * g = new Graph;
    g->intializenodes();

    //add edges for the graphs here.
    g->addedge(1,2);
    g->addedge(2,3);
    g->addedge(3,1);
    g->addedge(1,4);
    g->addedge(4,7);
    g->addedge(7,5);
    g->addedge(5,8);
    g->addedge(5,6);
    g->addedge(6,2);
    g->addedge(6,4);
    g->addedge(1,5);
    g->addedge(4,8);
    
    //print the graph adjaceny list
    g->print();
}
