/*Given an image represented by an NxN matrix, where each pixel in the image is 4 
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?*/


/*brute force*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotatematrix(vector<vector<int>> &v, int n) {
    vector<vector<int>> res(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][n - 1 - i] = v[i][j];
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    ans = rotatematrix(v, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*optimised*/
#include <bits/stdc++.h>
using namespace std;

void rotatematrix(vector<vector<int>> &v, int n) {
   

    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n; j++) {
            swap(v[i][j],v[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin(),v[i].end());
    }
    

   
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

     rotatematrix(v, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}