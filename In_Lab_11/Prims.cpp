#include <iostream>
#include <vector>
using namespace std;


/////////////////////////// 210568J //////////////////////////////
int minNodeIndex(vector<int> &nodes,vector<int> &mstSet){
    int minIndex=-1;
    int minValue=INT_MAX;
    for(int i=0;i<mstSet.size();i++){
       
        if(!mstSet[i] && nodes[i]<minValue){
            minValue=nodes[i];
            minIndex=i;
        }
    }
    return  minIndex;
}

// print  MST
void printMST(vector<int> &parents,vector<vector<int>> &graph){
    cout<<" Edge     Weight "<<endl;
    
    for(int i=1;i<parents.size();i++){
        printf(" %d - %d      %d    \n",parents[i],i,graph[parents[i]][i]);
    }
    
}

//built the prims algorithm
void prims_MST_Algorithm(vector<vector<int>> &graph,int startNode){
    int noOfNodes=graph[0].size();

    vector<int> parents(noOfNodes,-1);  // store MST
    vector<int> mstSet(noOfNodes,false);    //to store each node is visited or not--mstSet
    vector<int> nodes(noOfNodes,INT_MAX);   //set value of all nodes as infinity

    mstSet[startNode]=true;
    nodes[startNode]=0;                   //set starting node as 0
    vector<int> edgeValuesForCurrentVertex=graph[startNode]; //[0,3,0,0,0,1]
    for(int i=0;i<noOfNodes;i++){
        //1. check whether is there exist an edge between (u,v)=(startNode->i)
        if(edgeValuesForCurrentVertex[i]!=0 && edgeValuesForCurrentVertex[i]<nodes[i]){
            nodes[i]=edgeValuesForCurrentVertex[i];
            parents[i]=startNode;
        }
    }  
   

    for(int i=0;i<(noOfNodes-1);i++){ 
        int minIndex=minNodeIndex(nodes,mstSet);  // find minIndex
        mstSet[minIndex]= true;
        edgeValuesForCurrentVertex=graph[minIndex];
        for(int j=0;j<noOfNodes;j++) {
            
            if(edgeValuesForCurrentVertex[j]!=0 && edgeValuesForCurrentVertex[j]<nodes[j] && !mstSet[j]){
                nodes[j]=edgeValuesForCurrentVertex[j];
                parents[j]=minIndex;
            }
        }
    }
    cout<<"Starting vertex: "<<startNode<<endl;
   
    printMST(parents,graph);
}


int main() {
    vector<vector<int>> graph={{0,3,0,0,0,1},            //adjecencyMatrix
                               {3,0,2,1,10,0},
                               {0,2,0,3,0,5},
                               {0,1,3,0,5,0},
                               {0,10,0,5,0,4},
                               {1,0,5,0,4,0}};

    prims_MST_Algorithm(graph,0);
    return 0;
}