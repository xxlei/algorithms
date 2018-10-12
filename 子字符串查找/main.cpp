#include <iostream>
#include <string>
using namespace std;
int search_violence1(string pat, string txt);
int main()
{
    string a = "hobbyl";
    string b = "byl";
    int pos = search_string(b, a);
    cout << "pos: " << pos << endl;
    return 0;
}

/**************************************************/
/***********暴力子字符串查找实现1******************/
/**************************************************/
int search_violence1(string pat, string txt)
{
    int m = pat.size();
    int n = txt.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == m)
            return i;
    }
    return -1;
}
/**************************************************/
/***********暴力子字符串查找实现2******************/
/**************************************************/
int search_violence2(string pat, string txt)
{
    int m = pat.length();
    int n = txt.length();
    int i, j;
    for (i = 0, j = 0; i < n && j < m; i++)
    {
        if (txt[i] == pat[j])
            j++;
        else
        {
            i -= j;
            j = 0;
        }
    }
    if (j == m)
        return i - m;
    else
        return -1;
}
