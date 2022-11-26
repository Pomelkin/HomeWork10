#include "pt4.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

void vivod(string& s)
{
    int Num = s.find(" ");
    int k = (15-(Num-1));
    string s1 = "";
    for (int i = 0; i < k; i++) s1 += " ";
    s.insert(Num, s1, 0, k);
}


void sort_bin_insert(vector<string>& a, int n)
{
    int left, right, sred;
    string x;
    for (int i = 1; i < n; i++)
    {
        int i0Num = 0, i1Num = 0;
        
        string s = a[i];
        s = s.back();
        i0Num = stoi(s);

        s = a[i - 1];
        s = s.back();
        i1Num = stoi(s);


        if (i0Num < i1Num )
        {
            x = a[i];
            left = 0;

            right = i - 1;
            do
            {
                sred = (left + right) / 2;
                int SredNum = 0, XNum = 0;

                s = a[sred].back();
                SredNum = stoi(s);

                s = x.back();
                XNum = stoi(s);


                if (SredNum < XNum)
                    left = sred + 1;
                else right = sred - 1;
            } while (left <= right);
            for (int j = i - 1; j >= left; j--) a[j + 1] = a[j];
            a[left] = x;
        }
    }
    
}

void sort_bin_insert_name(vector<string>& a, int n)
{
    char ru[] = "A¡¬√ƒ≈®∆«»… ÀÃÕŒœ–—“”‘’÷◊ÿŸ›ﬁﬂ";
    int left = 0, right = 0, sred = 0;
    string x;
    for (int i = 1; i < n; i++)
    {
        int NumOfName0 = 0, NumOfName1 = 0, NumOfName20 = 0, NumOfName21 = 0;

        string s0 = a[i], s1 = a[i - 1];

        for (int j = 0; j < 30; j++) if (s0[0] == ru[j]) NumOfName0 = j;
        for (int j = 0; j < 30; j++) if (s1[0] == ru[j]) NumOfName1 = j;
        for (int j = 0; j < 30; j++) if (s0[1] == ru[j]) NumOfName20 = j;
        for (int j = 0; j < 30; j++) if (s1[1] == ru[j]) NumOfName21 = j;

        
        
        int i0Num = 0, i1Num = 0;

        string s = a[i];
        s = s.back();
        i0Num = stoi(s);

        s = a[i - 1];
        s = s.back();
        i1Num = stoi(s);

        vector <string> VecOfNum;
         
        if (NumOfName0 > NumOfName1 && i1Num == i0Num ) 
        {            
            for (int k = i - 1; k < n - 1; k++)
            {
                string s1 = a[k];
                s1 = s1.back();
                int k0Num = stoi(s1);

                s1 = a[k + 1];
                s1 = s1.back();
                int k1Num = stoi(s1);

                if (k1Num != k0Num)
                {
                    right = k;
                    break;
                }
            }
            
            for (int k = 0; k < n ; k++)
            {
                string s1 = a[k];
                s1 = s1.back();
                int k0Num = stoi(s1);

                if (k0Num == i0Num)
                {
                    left = k;
                    break;
                }
            }
            
            x = a[i];   
                do 
                {
                    sred = (left + right) / 2; 

                    string s3 = a[sred];
                    int NumOfNameSred = 0;
                    for (int j = 0; j < 30; j++) if (s3[0] == ru[j]) NumOfNameSred = j;
                    
                    if (NumOfNameSred > NumOfName0)
                        left = sred + 1;
                    else right = sred - 1;
                } while (left <= right); 
            for (int j = i - 1; j >= left; j--) a[j + 1] = a[j];
            a[left] = x; 
        }
        
        if (NumOfName20 > NumOfName21 && i1Num == i0Num && NumOfName1 == NumOfName0)
        {
            for (int k = i - 1; k < n - 1; k++)
            {
                string s1 = a[k];
                s1 = s1.back();
                int k0Num = stoi(s1);

                s1 = a[k + 1];
                s1 = s1.back();
                int k1Num = stoi(s1);

                if (k1Num != k0Num)
                {
                    right = k;
                    break;
                }
            }

            for (int k = 0; k < n; k++)
            {
                string s1 = a[k];
                s1 = s1.back();
                int k0Num = stoi(s1);

                if (k0Num == i0Num)
                {
                    left = k;
                    break;
                }
            }

            x = a[i];
            do
            {
                sred = (left + right) / 2;

                string s3 = a[sred];
                
                int NumOfNameSred = 0, NumOfNameSred2 = 0;
                for (int j = 0; j < 30; j++) if (s3[0] == ru[j]) NumOfNameSred = j;
                for (int j = 0; j < 30; j++) if (s3[1] == ru[j]) NumOfNameSred2 = j;

                if (NumOfNameSred == NumOfName0 && NumOfNameSred2 > NumOfName20)
                    left = sred + 1;
                else right = sred - 1;
            } while (left <= right);
            for (int j = i - 1; j >= left; j--) a[j + 1] = a[j];
            a[left] = x;
        }
        

    }
}


void Solve()
{
    Task("Five15");
    char in[250], t[250], out[250];
    pt >> in;
    OemToChar(in, t);
    ifstream FileIn(t);

    setlocale(LC_ALL, "Russian");

    vector <string> NameAndBallOfEge;
    int i = 0;
    while (!FileIn.eof())
    {
        i++;

        string s;

        getline(FileIn, s);
        NameAndBallOfEge.push_back(s);
    }
    i -= 1;
    NameAndBallOfEge.pop_back();
    
    sort_bin_insert(NameAndBallOfEge, i);
    sort_bin_insert_name(NameAndBallOfEge, i);

    pt >> out;
    OemToChar(out, t);
    ofstream FileOut(t);

    for (int j = 0; j < i; j++)
    {
        vivod(NameAndBallOfEge[j]);
        FileOut << NameAndBallOfEge[j] << endl;
    }

    FileIn.close();
    FileOut.close();
}