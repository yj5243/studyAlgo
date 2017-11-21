// ConsoleApplication2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "string.h"
#include "stdlib.h"
#include "algorithm"

int X[1000];
int Y[1000];
int Z[1000];
 

int ccw(int Ax, int Ay, int Az, int Bx, int By, int Bz) {
 

    int tmpX = Ay * Bz - Az * By; 
    int tmpY = Ax * Bz - Az * Bx;
    int tmpZ = Ax * By - Ay * Bx;


    //printf("ccs : %d %d %d\n", tmpX, tmpY, tmpZ);

 
    if( tmpX == 0  && tmpY == 0 &&  tmpZ == 0) return 0;
    else return 1;
    
} 

int tri(int Ax, int Ay, int Az, int Bx, int By, int Bz, int Cx, int Cy, int Cz) {
    int returnValeu = (Ay * Bz - By * Az) * Cx - (Ax*Bz - Bx*Az) * Cy + (Ax * By - Bx * Ay) * Cz;
    //printf("%d \n", returnValeu);
    return returnValeu;
} 

int main()
{ 
    int Position1;
    int Position2;
    int Position3;
    int retValue = 3;
    int Sum = 0;
    int testCase = 0;


	freopen("test.txt", "rw", stdin);

    scanf("%d", &testCase);

    for( int k = 1; k<= testCase ; k++) {
        for (int i = 0; i <3; i++) {
            scanf("%d %d %d", &X[i], &Y[i], & Z[i]);
            //printf("%d %d %d\n", X[i], Y[i], Z[i]);
            if( X[i] == 0 && Y[i] == 0 && Z[i] == 0 && Sum == 0 ) Sum = Sum + 0;
            else Sum++;
        }
        
        if( Sum == 0) { 
            retValue = 0;
        }
        else {
            
            Position1 = ccw(X[0],Y[0],Z[0],X[1],Y[1], Z[1]);
            Position2 = ccw(X[1],Y[1],Z[1],X[2],Y[2], Z[2]);
            Position3 = ccw(X[2],Y[2],Z[2],X[0],Y[0], Z[0]);
            if( Position1 == 0 && Position2 == 0 && Position3 == 0  ) {
                retValue = 1;
            } else if( tri(X[0] ,Y[0] ,Z[0], X[1], Y[1], Z[1], X[2], Y[2], Z[2]) == 0 ) {
                retValue = 2; 
            }
            else {
                retValue = 3;
            }
        }
  
        printf("retValue %d\n", retValue);

        Sum = 0;
        retValue = 3;
    }

 

 



    return 0;
}
 
