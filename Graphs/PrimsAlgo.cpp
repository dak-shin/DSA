#include <bits/stdc++.h>
using namespace std;
#define V 4

int primMST(int graph[V][V])
{

	int key[V];int res=0;
  /*
    Both the key and the mSet array is used pick the next edge to include
    in the MST. Initially only the zero vertex has the key set to 0, rest are
    set to  INT_MAX
  */
	fill(key,key+V,INT_MAX);
	bool mSet[V]; key[0]=0;

	for (int count = 0; count < V ; count++)
	{
		int u = -1;

		for(int i=0;i<V;i++)
		    if(!mSet[i]&&(u==-1||key[i]<key[u]))
		        u=i;
    /*
      In the first iteration the the zero vertex is added to the MST and hence mst[0] is set to True

    */
		mSet[u] = true;
		res+=key[u];


		for (int v = 0; v < V; v++)
      
			if (graph[u][v]!=0 && mSet[v] == false)
				key[v] = min(key[v],graph[u][v]);
	}
    return res;
}

int main()
{
	int graph[V][V] = { { 0, 5, 8, 0},
						{ 5, 0, 10, 15 },
						{ 8, 10, 0, 20 },
						{ 0, 15, 20, 0 },};

	cout<<primMST(graph);

	return 0;
}
