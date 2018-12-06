#include<iostream>
#include <vector>
#include <stack>
using namespace std;

//create a vector array for adj list with max node size 100

vector<int> adj[100];

//define a boolean array for keeping track of visited nodes

bool visited[100];

void dft(int x){
    //create an int stack
    stack<int> dftStack;

    //push x onto the stack and mark the node visited
    dftStack.push(x);

    //while stack is not empty
    while(!dftStack.empty()){
        //pop a node from stack and print it
        cout<<dftStack.top()<<" ";
        visited[dftStack.top()]=true;
        for(int i=0; i<adj[dftStack.top()].size();i++){    
            if(visited[adj[dftStack.top()][i]]==false){
                dftStack.push(adj[dftStack.top()][i]);
            }
        }
     	// Get all adjacent vertices of the popped vertex s
        // If an adjacent has not been visited, then push it
        // to the stack and mark it as visited
        dftStack.pop();
    }
    cout<<endl;
}



int main(){
    int x,y,nodes,edges;
    //read number of nodes and edges from the user
    //Ex:
    // 3
    // 3
    cout<<"Enter number of nodes, then number of edges \n"; cin>>nodes; cin>>edges;

    cout<<endl<<"Creating graph with "<<nodes<<" and "<<edges<<" edges.\n";

    //Then read the individual edge pairs(x,y) from the user and insert into the graph
    //to insert into a vector use push_back function
    //Ex:
    //0 1
    //1 2
    //0 2

    for(int i = 0; i<edges; i++){
        cout<<"Please enter node/node connection "<<i+1<<": ";
        cin>>x>>y;
        cout<<endl<<"Node "<<x<<"--->Node "<<y<<endl;
        adj[x].push_back(y);
    }


    //print the content of graph
    //sample output:
    // adk[0] : 1-->2
    // adj[1] : 2
    // adj[2] :

    for(int i=0;i<100;i++){
        if(adj[i].size()!=0){
            cout<<"Node "<<i;
            for(int j=0; j<adj[i].size();j++){
                cout<<"-->"<<adj[i][j];
            }
        cout<<endl;
        }    
    }


    //initialize the status of each node unvisited
    for(int i=0; i<100;i++){
        visited[i]=false;
    }




    //print the depth-first traversal of the graph
    //sample output:
    // 0 2 1
    dft(0); //write a function for implementing depth-first traversal
    return 0;
}




