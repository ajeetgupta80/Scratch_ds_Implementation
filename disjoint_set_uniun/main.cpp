#include<iostream>
#include"DSU.h"
using std::cout;
using std::endl;





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
}