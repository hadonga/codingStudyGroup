https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/solutions/2809359/tao-lu-jiao-ni-jie-jue-ding-chang-hua-ch-fzfo/

举例
示例 1，s=abciiidef, k=3。

从左到右遍历 s。
首先统计前 k−1=2 个字母的元音个数，这有 1 个。
s[2]=c 进入窗口，此时找到了第一个长为 k 的子串 abc，现在元音个数有 1 个，更新答案最大值。然后 s[0]=a 离开窗口，现在元音个数有 0 个。
s[3]=i 进入窗口，此时找到了第二个长为 k 的子串 bci，现在元音个数有 1 个，更新答案最大值。然后 s[1]=b 离开窗口，现在元音个数有 1 个。
s[4]=i 进入窗口，此时找到了第三个长为 k 的子串 cii，现在元音个数有 2 个，更新答案最大值。然后 s[2]=c 离开窗口，现在元音个数有 2 个。
s[5]=i 进入窗口，此时找到了第四个长为 k 的子串 iii，现在元音个数有 3 个，更新答案最大值。然后 s[3]=i 离开窗口，现在元音个数有 2 个。
s[6]=d 进入窗口，此时找到了第五个长为 k 的子串 iid，现在元音个数有 2 个，更新答案最大值。然后 s[4]=i 离开窗口，现在元音个数有 1 个。
s[7]=e 进入窗口，此时找到了第六个长为 k 的子串 ide，现在元音个数有 2 个，更新答案最大值。然后 s[5]=i 离开窗口，现在元音个数有 1 个。
s[8]=f 进入窗口，此时找到了第七个长为 k 的子串 def，现在元音个数有 1 个，更新答案最大值。遍历结束。
定长滑窗套路
我总结成三步：入-更新-出。

入：下标为 i 的元素进入窗口，更新相关统计量。如果 i<k−1 则重复第一步。
更新：更新答案。一般是更新最大值/最小值。
出：下标为 i−k+1 的元素离开窗口，更新相关统计量。