#include <stdio.h>
int main(){
int T = 0;
scanf("%d", &T);
for(int tc = 1; tc <= T; tc++){
    int n, m = 0;
    scanf("%d %d", &n, &m);
    int arr[n] = {0,};
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("#%d %d",tc, arr[m%n]);
}
return 0;
}