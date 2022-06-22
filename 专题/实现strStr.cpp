class Solution {
public:
    //构造next
    void getNext(vector<int>& next, string& needle){
     int j=-1;
     next[0] = j;
     //i从1开始，j初始值为-1，j应该从j+1=0开始
     for(int i =1; i<needle.size(); i++){
         //前后缀不同
         while(j >= 0 && needle[i] != needle[j+1]) j = next[j];//回退
         //前后缀相同
         if(needle[i] == needle[j+1]) j++;
         //将j（前缀的长度）存入next
         next[i] = j;
     }   
    }
    int strStr(string haystack,string needle){
        //needle为空字符串，返回0
        if(needle.size() == 0){
            return 0;
        }
        //创建next数组,并计算next数组
        vector<int> next(needle.size());
        getNext(next,needle);
        //因为next数组记录的起始位置为-1
        int j = -1;
        //遍历原串
        for(int i = 0; i<haystack.size(); i++){
            //原串和匹配串 开始匹配，i从0开始，j从-1开始
            //不匹配，前后缀不相同时，i指针不变，j回退
            while(j >= 0 && haystack[i] != needle[j+1]){
                j = next[j];
            }
            //匹配上，i和j同时向后移动，i的移动在for循环中
            if(haystack[i] == needle[j+1]){
                j++;
            }
            //原串中出现了匹配串，即j的值==匹配串长度-1,j来到最长匹配长度的最后一位，-1是因为j从-1开始少算了1
            if(j == (needle.size() - 1)){
                return (i-needle.size()+1);
            }
        }
        return -1;
    }
};