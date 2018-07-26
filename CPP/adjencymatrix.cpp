#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int nodes;

    cin>>nodes;

    int matrix[nodes][nodes] = {0},invalid=0;

    int maxEdges = (nodes*nodes)-nodes;

    for(int i = 0; i < maxEdges; i++){

        int x,y;

        cin>>x>>y;

        if((x == -1) && (y == -1)){

            break;

        }
        if(x>=nodes || y>=nodes || x<0 || y<0)
        {
          cout<<"Invalid edge"<<endl;
        }


        matrix[x][y] = 1;
        for (int i = 0; i < nodes; i++){

        for(int j = 0; j < nodes; j++){

            cout<<matrix[i][j]<<" ";

        }

        cout<<endl;

    }
	return 0;
}

