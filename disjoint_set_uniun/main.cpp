#include<iostream>
#include<vector>
#include"DSU.h"
using std::cout;
using std::endl;


struct Edge{
  int src; 
  int dest;
};

class Graph{

   
   public:
   std::vector<std::vector<int>> adjList;

   Graph(std::vector<Edge> const&edges, int n){
         
        adjList.resize(n);
       for(auto &edge:edges){
        adjList[edge.src].push_back(edge.dest);
       }

   }
};

bool isCycle(Graph const&graph , int n){
     
     DSU ds(n);

     for(int u = 0; u<n; ++u){
        for(int v:graph.adjList[u]){

            int x = ds.Find_Ultimate_Parent(u);
            int y = ds.Find_Ultimate_Parent(v);

            if( x == y){
                return true;
            }else{
                ds.UNION_BY_RANK(x,y);
            }
        }
     }

     return false;

}


int main(){
    
  
    DSU ds(7);
    ds.UNION_BY_RANK(1,2);
    ds.UNION_BY_RANK(2,3);
    ds.UNION_BY_RANK(4,5);
    ds.UNION_BY_RANK(6,7);
    ds.UNION_BY_RANK(5,6);

    if(ds.Find_Ultimate_Parent(3) == ds.Find_Ultimate_Parent(7)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }

    ds.UNION_BY_RANK(3,7);

    if(ds.Find_Ultimate_Parent(3) == ds.Find_Ultimate_Parent(7)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }





    // for finding cycle using disjoint_uniun_set
      int n = 12;
    std::vector<Edge> edge ={
       {0, 1}, {0, 6}, {0, 7}, {1, 2}, {1, 5}, {2, 3},
        {2, 4}, {7, 8}, {7, 11}, {8, 9}, {8, 10}, {10, 11}
    };

    Graph graph(edge, n);

    if(isCycle(graph, n)){
        cout<<"Cycle Found"<<endl;
    }else{
        cout<<"Cycle Not Found "<<endl;
    }
    


}