#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>vec(1000,vector<int>(1000));

    for(int i=0;i<1000;i++)
    {
         for(int j=0;j<1000;j++)
         {
            vec[i][j]=0;
         }
    }

    string line;
    ifstream fin;
    fin.open("input.txt");
    if(fin.is_open()==false)
    {
        cout<<"Something is wrong";
    }
    else
    {
        int arr[4];
        int count=0;
        while(getline(fin,line,'\n'))
        {
            cout<<line<<endl;
            string str;
            int sw=0;
            string state=line.substr(0,7);
            if(state=="toggle ")
            {
                sw=2;
            }
            else if(state=="turn of")
            {
                sw=0;
            }
            else if(state=="turn on")
            {
                sw=1;
            }
            for(int i=0;i<line.size();i++)
            {
                if(line[i]>='0'&&line[i]<='9')
                {
                    str+=line[i];
                    if(i==line.size()-1)
                    {
                        arr[count++]=stoi(str);
                        str.clear();
                        count=0;
                    }
                }
                else
                {
                    if(str.empty())
                    {
                        continue;
                    }
                    else
                    {
                        arr[count++]=stoi(str);
                        str.clear();
                    }
                }
            }
            if(sw==0)
            {
                for(int i=arr[0];i<=arr[2];i++)
                {
                    for(int j=arr[1];j<=arr[3];j++)
                    {
                        vec[i][j]=0;
                    }
                }
            }
            else if(sw==1)
            {
                for(int i=arr[0];i<=arr[2];i++)
                {
                    for(int j=arr[1];j<=arr[3];j++)
                    {
                        vec[i][j]=1;
                    }
                }
            }
            else{
                for(int i=arr[0];i<=arr[2];i++)
                {
                    for(int j=arr[1];j<=arr[3];j++)
                    {
                        if(vec[i][j]==0)
                        {
                            vec[i][j]=1;
                        }
                        else
                        {
                            vec[i][j]=0;
                        }
                    }
                }

            }
        }

        int cnt=0;
        for(int i=0;i<1000;i++)
        {
            for(int j=0;j<1000;j++)
            {
                if(vec[i][j]==1)cnt++;
            }
        }

        cout<<cnt<<endl;
        fin.close();

    }

    return 0;
}
