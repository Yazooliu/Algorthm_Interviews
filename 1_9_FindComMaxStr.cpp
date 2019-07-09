// 面试题目One. 刷刷看 - 推荐算法工程师
// 9.编程题： 怎样找到两个字符串中最长公共子子串
// 具体编程思想：https://blog.csdn.net/qq_25800311/article/details/81607168
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void FindComMaxStr(string str1,string str2)
{
    if(str1.size()>str2.size())
        swap(str1,str2); // 希望这里str1的长度最小作为横坐标的个数
    int maxLen = 0,start = 0;
    int len1 = str1.length(),len2 = str2.length();
    vector<vector<int>> res(len1+1,vector<int>(len2+1,0)); // res初始化成len1+1行，和len2+1列，并且全部是0
    // 下面 i = 1,j=1 初始赋值是因为 表格是从第二个表格开始
    // 而str1 and str2的索引是从 0 k开始的，所以str1[i-1],str2[j-1]
    for (int i = 1;i<=len1;i++)
        for (int j = 1;j<=len2;j++){
            if(str1[i-1] == str2[j-1])
            {
                res[i][j] = res[i-1][j-1] +1; // 对角线上，如果前面的元素已经是1了，则后面的逐渐递加，最后的res[i][j]就是最大长度
                if (maxLen<res[i][j])
                {
                    maxLen  = res[i][j];
                    start   = i -maxLen; // 这里i 索引从1开始，所以i -maxLen 并不需要加1,start 表示最大公共字符串的开始位置
                }
            }
            
        }
    
    cout<<str1.substr(start,maxLen)<<endl; // position = start , maxlen = 长度
}

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        FindComMaxStr(str1,str2);
    }
    return 0;
}