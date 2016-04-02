#include <stdio.h>
#include <string.h>
int numDistinct(char * s,char * t){
    int lens = strlen(s);
    int lent = strlen(t);
    if(lens==0&&lent==0) return 1;
    if(lent>lens) return 0;
    int c[10][10]={0};
    
    for(int i = 0 ; i<=lens;i++) c[0][i] = 1;
    for(int i = 1 ; i<=lent;i++) c[i][0] = 0;
    
    for(int i=1;i<=lent;i++){
        for(int j = 1;j<=lens;j++){
            c[i][j] = c[i][j-1];
            if(s[j]==t[i]) c[i][j] +=c[i-1][j-1];
        }
    }
    return c[lent][lens];
}

int  main(){
   
    printf("%d\n", numDistinct("rabbbit","rabbit"));
    return 0;
    
}
