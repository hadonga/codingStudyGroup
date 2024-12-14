# 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
# 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

# 输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
# 输出：3
# 解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

def maxEnvelopes(envelopes):
    # sort by h first
    envelopesSortedHeight = sort(envelopes, axis =0)
    envelopesSorted = envelopesSortedHeight
    for i in envelopesSortedHeight:
        if i[0] ==




envelopes = [[5,4],[6,4],[6,7],[2,3]]