#include <bits/stdc++.h>
using namespace std ;

struct irregular
{
    char singular[100];
    char plural[100];
} irr[25];

char word[110][110];

char ne[110][110];

int main()
{
    int i,j,N,L,k,l,vainga_de;
    cin >> L >> N;

    for(i=0; i<L; i++)
    {
        cin >> irr[i].singular >> irr[i].plural;
    }
    for(i=0; i<N; i++)
    {
        cin >> word[i];
    }

    k=0;

    for(i=0; i<N; i++)
    {
        vainga_de=0;
        l=strlen(word[i]);
        for(j=0; j<L; j++)
        {
            if(strcmp(word[i],irr[j].singular)==0)
            {
                strcpy(word[i],irr[j].plural);
                cout << irr[j].plural << endl;
                vainga_de=1;
            }
        if(vainga_de==1) break;
        }
        if(vainga_de==1) continue;

        if(word[i][l-1]=='y'&&(word[i][l-2]!='a'&&word[i][l-2]!='e'&&word[i][l-2]!='i'&&word[i][l-2]!='o'&&word[i][l-2]!='u'))
        {
            word[i][l+1]='s';
            word[i][l]='e';
            word[i][l-1]='i';
            cout << word[i] << endl;
            continue;
        }
        else if (word[i][l-1]=='y'&&(word[i][l-2]=='a'||word[i][l-2]=='e'||word[i][l-2]=='i'||word[i][l-2]=='o'||word[i][l-2]=='u'))
        {
            word[i][l]='s';
            cout << word[i] << endl;
            continue;

        }
        else if(word[i][l-1]=='o'||word[i][l-1]=='s'||word[i][l-1]=='x')
        {
            word[i][l+1]='s';
            word[i][l]='e';
            cout << word[i] << endl;
            continue;

        }
        else if(word[i][l-1]=='h')
        {
            if(word[i][l-2]=='c'||word[i][l-2]=='s')
            {
                word[i][l+1]='s';
                word[i][l]='e';
                cout << word[i] << endl;
                continue;
            }
        }
        else word[i][l]='s';
        cout << word[i] << endl;
        continue;
    }

    return 0 ;
}
