#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class graph{
    public:
        int V;
        list<int> *adj;
        graph(int v){
            V = v;
            adj = new list<int>[V];
        }

        void addEdge(int u, int v){
            adj[u].push_back(v);
            // adj[v].push_back(u); //to make it un-directed
        }

        void dfshelper(int curr, vector<bool>&vis){
            cout<<curr;
            vis[curr] = true;
            for(int v:adj[curr]){
                if(!vis[v]){
                    cout<<"->";
                    dfshelper(v,vis);
                }
            }
        }
        void dfs(){
            int curr = 0;
            vector<bool> vis(V,false);
            dfshelper(curr, vis);
        }

        void bfs(){
            queue<int> res;
            vector<bool> vis(V,false);
            res.push(0);
            vis[0] = true;
            while(res.size() > 0){
                int u = res.front();
                res.pop();
                cout<<u<<"->";
                for(int v:adj[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        res.push(v);
                    }
                }
            }
            cout<<"End"<<endl;
        }

        void topodfs(int curr, vector<bool> &vis, stack<int> &res){
            vis[curr] = true;
            for(int v: adj[curr]){
                if(!vis[v]){
                    topodfs(v,vis,res);
                }
            }
            res.push(curr);
        }
        void toposort(){
            vector<bool>vis(V,false);
            stack<int>res;
            for(int i=0; i<V; i++){
                if(!vis[i]){
                    topodfs(i,vis,res);
                }
            }
            while(res.size()>0){
                cout<<res.top()<<" ";
                res.pop();
            }
        }
};


int main(){
    graph g(6);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,3);
    g.dfs();
    cout<<endl;
    g.bfs();
    cout<<endl;
    g.toposort();
}