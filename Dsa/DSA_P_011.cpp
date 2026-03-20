#include<bits/stdc++.h>
using namespace std ;
int n , m;
char a [1005] [1005];
bool vs [1005][1005];
int dx[4] = {-1 , 1 , 0 , 0};
int dy[4] = {0 , 0 , -1 , 1};
// ghi chú : k = 0 lên , 1 xuống , 2 , trái , 3 phải
void dfs (int i ,int j){
    vs[i][j] = true;
    for (int k =  0 ; k < 4 ; k ++){
        int ni = i + dx[k];
        int nj = j + dx[k];
        if (ni >= 0  && ni < n && nj >=0 && nj < m ){
            if (a[ni][nj] == '#' && !vs[ni][nj]){
                dfs (ni,nj);
            } 
        }
    }
}

int main (){
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j ++){
            cin >> a[i][j] ;
        }
    }
    int count = 0 ;
    for (int i = 0 ;  i< n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (a[i][j] == '#' && !vs[i][j]){
                count ++;
                dfs (i,j);
            }
        }
    }
    cout << count << endl;
}