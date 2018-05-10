/*===========================================
*    
*    xxxxx for xxxx
*    
*    Created by Haugy on 03/05/2018
*    Copyright (c) 2018 Haugy. All right reserved.
*    
*===========================================*/

/*Q:
'''给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
'''
*/

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int slen = strlen(s);
    if (slen == 0){
        return 0;
    }
    printf("%d\n", slen);
    //记录最长子串
    int ch_num = 1;
    //记录num是否+1
    int ch_flag = 0;
    //char* ch_temp;
    //ch_temp[0] = s[0];
    for (int i = 1; i < slen; i++){
        //printf("i:%d\n", i);
        for (int n = 1; n <= ch_num; n++){
            if (s[i] == s[i - n]){
                int ch_pre_num = i + ch_num - n + 1;
                printf("pre_num:%d\n", ch_pre_num);
                //跳转的字符中没有重复
                while (1){
                    i++;
                    if (i > slen){
                        break;
                    }
                    for (int m = 1; m <= ch_num; m++){
                        if (s[i] == s[i - m]){
                            if (ch_pre_num < i + ch_num - m + 1) {
                                ch_pre_num = i + ch_num - m + 1;
                            }
                            printf("ch_pre_num:%d\n", ch_pre_num);
                        }
                    }
                    //结束条件
                    if (i == ch_pre_num){
                        i = ch_pre_num - 1;
                        printf("while if:%c:%d\n", s[i], i);
                        break;
                    }
                    printf("while:%c:%d\n", s[i], ch_num);
                }
                printf("i_index: %d\n", i);
                ch_flag = 1;
                break;
            }
        }
        if (ch_flag != 1){
            ch_num++;
        }
        else{
            ch_flag = 0;
        }
        printf("%c:%d\n", s[i], ch_num);
    }
    printf("%d\n", ch_num);
    return ch_num;
}

//test
int main(int argc, char** argv)
{
    int len = lengthOfLongestSubstring(argv[1]);
    printf("string: %s\n", argv[1]);
    printf("lengest: %d\n", len);
    return 0;
}
