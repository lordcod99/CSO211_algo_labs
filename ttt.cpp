#include <bits/stdc++.h>
using namespace std;
#define push push_back
#define pop pop_back
#define f first
#define s second
#define mp make_pair
#define loop() for(int x=0;x<n;x++)
typedef long long int lint;

int a[3][3],cc=0;

void printx();

void auto_fun();

bool check();

pair<int,int> all_fill(int p);

int main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0);
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++) a[x][y] = 0;
    }
    int x,y;bool f=true;
    while(cc<9){
        system("cls");
        if(cc==0){
            cout<<"TIC TAC TOE\nCOORDS\n\n";
            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++) cout<<"("<<y+1<<","<<x+1<<") ";cout<<endl;
            }
            cout<<"\n";
        }
        printx();
        if(cc%2==1){
            auto_fun();
            f = false;
        }
        while(f){
            cout<<"Enter x and y coords";
            if(cc%2==0) cout<<" (X): ";
            else cout<<" (O): ";
            cin>>y>>x;
            if(a[x-1][y-1]!=0 || x<1 || x>3 || y<1 || y>3){
                system("cls");
                cout<<"Try Again\n\n";
                printx();
            }
            else{
                if(cc%2==0) a[x-1][y-1] = 1;
                else a[x-1][y-1] = 2;
                f = false;
            }
        }
        f = true;
        if(check()) break;
        ++cc;
    }
    if(cc==9){
        system("cls");
        printx();
        cout<<"Draw\n";
    }
    return 0;
}

void printx(){
    for(int x=0;x<3;x++){
        for(int y=0;y<2;y++){
            if(a[x][y]==0) cout<<" |";
            else if(a[x][y]==1) cout<<"X|";
            else cout<<"O|";
        }
        if(a[x][2]==0) cout<<" \n";
        else if(a[x][2]==1) cout<<"X\n";
        else cout<<"O\n";
        if(x!=2) cout<<"- - -\n";
    }
}

bool check(){
    if(cc<4) return false;
    for(int x=0;x<3;x++){
        if(a[x][0]==a[x][1] && a[x][1]==a[x][2]){
            if(a[x][0]==1){
                system("cls");
                printx();
                cout<<"\nX wins\n";
                return true;
            }
            else if(a[x][0]==2){
                system("cls");
                printx();
                cout<<"\nO wins\n";
                return true;
            }
        }
        if(a[0][x]==a[1][x] && a[1][x]==a[2][x]){
            if(a[0][x]==1){
                system("cls");
                printx();
                cout<<"\nX wins\n";
                return true;
            }
            else if(a[0][x]==2){
                system("cls");
                printx();
                cout<<"\nO wins\n";
                return true;
            }
        }
    }
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2]){
        if(a[0][0]==1){
            system("cls");
            printx();
            cout<<"\nX wins\n";
        }
        else if(a[0][0]==2){
            system("cls");
            printx();
            cout<<"\nO wins\n";
        }
        return true;
    }
    if(a[2][0]==a[1][1] && a[1][1]==a[0][2]){
        if(a[1][1]==1){
            system("cls");
            printx();
            cout<<"\nX wins\n";
        }
        else if(a[1][1]==2){
            system("cls");
            printx();
            cout<<"\nO wins\n";
        }
        return true;
    }
    return false;
}

// pair<int,int> all_fill(int p){
//     for(int x=0;x<3;x++){
//         if(a[x][0]==p && a[x][1]==0 && a[x][2]==p) return mp(x,1);
//         if(a[0][x]==p && a[1][x]==0 && a[2][x]==p) return mp(1,x);
//         for(int y=0;y<2;y++){
//             if(a[x][y]==p && a[x][y+1]==p) return mp(x,y+1);
//             if(a[y][x]==p && a[y+1][x]==p) return mp(y+1,x);
//         }
//     }
//     if(a[0][0]==p && a[1][1]==p) return mp(2,2);
//     if(a[1][1]==p && a[2][2]==p) return mp(0,0);
//     if(a[0][0]==p && a[2][2]==p) return mp(1,1);
//     if(a[0][2]==p && a[1][1]==p) return mp(2,0);
//     if(a[1][1]==p && a[2][0]==p) return mp(0,2);
//     if(a[0][2]==p && a[2][0]==p) return mp(1,1);
//     return mp(-1,-1);
// }

pair<int,int> all_fill(int p){
    for(int x=0;x<3;x++){
        if(a[x][0]==p && a[x][1]==p && a[x][2]==0) return mp(x,2);
        if(a[x][0]==0 && a[x][1]==p && a[x][2]==p) return mp(x,0);
        if(a[x][0]==p && a[x][1]==0 && a[x][2]==p) return mp(x,1);
        if(a[0][x]==p && a[1][x]==p && a[2][x]==0) return mp(2,x);
        if(a[0][x]==0 && a[1][x]==p && a[2][x]==p) return mp(0,x);
        if(a[0][x]==p && a[1][x]==0 && a[2][x]==p) return mp(1,x);
    }
    if(a[0][0]==p && a[1][1]==p && a[2][2]==0) return mp(2,2);
    if(a[0][0]==0 && a[1][1]==p && a[2][2]==p) return mp(0,0);
    if(a[0][0]==p && a[1][1]==0 && a[2][2]==p) return mp(1,1);
    if(a[0][2]==p && a[1][1]==p && a[2][0]==0) return mp(2,0);
    if(a[0][2]==0 && a[1][1]==p && a[2][0]==p) return mp(0,2);
    if(a[0][2]==p && a[1][1]==0 && a[2][0]==p) return mp(1,1);
    return mp(-1,-1);
}

void auto_fun(){
    cout<<cc<<endl;
    pair <int,int> aa = all_fill(1);
    pair <int,int> bb = all_fill(2);
    switch (cc){
        case 1:
            if(a[0][0]==1 || a[2][0]==1 || a[0][2]==1 || a[2][2]==1) a[1][1] = 2;
            else a[0][0] = 2;
            return;
        case 3:
            if(aa.f!=-1) a[aa.f][aa.s]=2;
            else if(a[0][0]==1 && a[2][2]==1) a[0][1] = 2;
            else if(a[0][2]==1 && a[2][0]==1) a[0][1] = 2;
            else if(a[0][0]==1 && a[2][1]==1) a[2][0] = 2;
            else if(a[0][0]==1 && a[1][2]==1) a[0][2] = 2;
            else if(a[0][2]==1 && a[2][1]==1) a[2][2] = 2;
            else if(a[0][2]==1 && a[1][0]==1) a[0][0] = 2;
            else if(a[2][2]==1 && a[0][1]==1) a[0][2] = 2;
            else if(a[2][2]==1 && a[1][0]==1) a[2][0] = 2;
            else if(a[2][0]==1 && a[0][1]==1) a[0][0] = 2;
            else if(a[2][0]==1 && a[1][2]==1) a[2][2] = 2;
            else a[0][2] = 2;
            return;
        case 5:
            if(bb.f!=-1) a[bb.f][bb.s] = 2;
            else if(aa.f!=-1) a[aa.f][aa.s] = 2;
            else if(a[1][1]==1) a[2][0] = 2;
            else if(a[1][0]==1 || a[1][2]==1) a[0][1] = 2;
            else a[1][0] = 2;
            return;
        case 7:
            if(bb.f!=-1) a[bb.f][bb.s] = 2;
            else if(aa.f!=-1) a[aa.f][aa.s] = 2;
            else{
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        if(a[x][y]==0){
                            a[x][y] = 2;
                            return;
                        }
                    }
                }
            }
            return;
    }
}