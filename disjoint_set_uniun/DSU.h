#ifndef DSU_H
#define DSU_H
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

class DSU
{
public:
    DSU(int n)
    {
        CountOfGroups = n;
        rank.resize(n + 1, 0);
        parents.resize(n + 1);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            parents[i] = i;
            size[i] = 1;
        }
    }

    bool isValidId(int id)
    {
        int parent_size = parents.size();
        if (id >= 0 && id < parent_size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    int Find_Ultimate_Parent(int id);

    void UNION_BY_RANK(int u, int v);

    void UNION_BY_SIZE(int u, int v);

    int GROUP_COUNT();  // returns the no disjoint sets

private:
    int CountOfGroups;
    std::vector<int> parents;
    std::vector<int> rank;
    std::vector<int> size;
};

int DSU::Find_Ultimate_Parent(int id)
{
    int parent = parents[id];
    if (parent == id)
    {
        return parent;
    }
    else
    {
        return parents[id] = Find_Ultimate_Parent(parent);
    }
}

void DSU::UNION_BY_RANK(int u, int v)
{

    if (!(isValidId(u) && isValidId(v)))
    {
        return;
    }
    int group_1 = Find_Ultimate_Parent(u);
    int group_2 = Find_Ultimate_Parent(v);
    if (group_1 == group_2)
        return;
    CountOfGroups--;
    int RANK_GROUP_1 = rank[group_1];
    int RANK_GROUP_2 = rank[group_2];
    if (RANK_GROUP_1 < RANK_GROUP_2)
    {
        parents[group_1] = group_2;
        
    }else if(RANK_GROUP_2 < RANK_GROUP_1){
          parents[group_2] = group_1;
    }else{
         parents[group_2] = group_1;
         rank[group_1]++;
    }
}

void DSU::UNION_BY_SIZE(int u, int v)
{
       if(!(isValidId(u) && isValidId(v)))
    {
        return;
    }
    int group_1 = Find_Ultimate_Parent(u);
    int group_2 = Find_Ultimate_Parent(v);
    if (group_1 == group_2)
        return;
    CountOfGroups--;
    int RANK_GROUP_1 = rank[group_1];
    int RANK_GROUP_2 = rank[group_2];
    if (RANK_GROUP_1 < RANK_GROUP_2)
    {
        parents[group_1] = group_2;
        size[group_2]+=size[group_1];
    }
    else{
         parents[group_2] = group_1;
         size[group_1]+=size[group_2];
    }
}

int DSU::GROUP_COUNT(){
    return CountOfGroups;
}

#endif