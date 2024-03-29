# Variable-Increment-CBF
A C++ implementation of a Variable-Increment Counting Bloom Filter.

The VI-CBF was originally proposed by Rottenstreich *et al.* in their paper "[The Variable-Increment Counting Bloom Filter](http://www.cs.technion.ac.il/~ykanizo/papers/tr11-05_variable.pdf)", IEEE INFOCOM 2012,

The VI-CBF is an improvement over the regular CBF, as it provides a lower False Positive Rate with the same number of bits. It works by incrementing the counters of the bloom filter with **variable values** when inserting elements, as opposed to simply incrementing by one. This allows more accurate statements about the likelyhood that a certain element is in a certain filter.

For more details, check the [original paper](http://www.cs.technion.ac.il/~ykanizo/papers/tr11-05_variable.pdf).

This code is built for readability, not efficiency. If you need an efficient implementation, build by your own :).


## Parameter Description

- `m`: the size of entries.
- `k`: the number of hash functions, note that we actually use `2*k` hash functions in the evaluation.
- `L`: the first item of `DL` array.

Maybe you don't understand the parameters mentioned above, the answer is in the paper :).

## A Few Evaluations

- For each test we used the optimal `k`, and run 10 times.

### Scenario L = 2

| L = 2 | 6 bits       |         |         |         |         |         |         |         |         |         |            |      |        |      |
| ----- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ---------- | ---- | ------ | ---- |
|       | test1   | test2   | test3   | test4   | test5   | test6   | test7   | test8   | test9   | test10  | avreage    |      | m      | k    |
| 20    | 0.0574  | 0.05805 | 0.0586  | 0.0581  | 0.05775 | 0.0563  | 0.05635 | 0.058   | 0.0587  | 0.0586  | 0.05782778 |      | 66667  | 4    |
| 25    | 0.0277  | 0.02865 | 0.02675 | 0.0288  | 0.0291  | 0.02895 | 0.0262  | 0.02785 | 0.02595 | 0.02875 | 0.02788889 |      | 83333  | 4    |
| 30    | 0.01585 | 0.01635 | 0.01625 | 0.01695 | 0.01575 | 0.01695 | 0.01355 | 0.01365 | 0.01585 | 0.01455 | 0.01557    |      | 100000 | 5    |
| 35    | 0.0057  | 0.00645 | 0.00735 | 0.00755 | 0.0077  | 0.0059  | 0.00645 | 0.00645 | 0.00705 | 0.00725 | 0.00690556 |      | 116667 | 6    |
| 40    | 0.00285 | 0.0031  | 0.004   | 0.00275 | 0.00355 | 0.0038  | 0.0039  | 0.00395 | 0.00345 | 0.0029  | 0.00348889 |      | 133333 | 7    |
| 45    | 0.0016  | 0.00255 | 0.00145 | 0.00185 | 0.00155 | 0.00135 | 0.00175 | 0.0017  | 0.0018  | 0.0016  | 0.00173333 |      | 150000 | 8    |
| 50    | 0.00085 | 0.00085 | 0.00075 | 0.00095 | 0.00075 | 0.0007  | 0.0007  | 0.00095 | 0.00075 | 0.0007  | 0.000795   |      | 166667 | 9    |
| 55    | 0.00055 | 0.00045 | 0.0006  | 0.00055 | 0.00035 | 0.00035 | 0.00025 | 0.00045 | 0.0005  | 0.00045 | 0.00045    |      | 183333 | 10   |

### Scenario L = 4

| L = 4 | 7 bits      |         |         |         |         |         |         |         |         |                                                              |            |      |        |      |
| ----- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------------------------------------------------------------ | ---------- | ---- | ------ | ---- |
|       | test1   | test2   | test3   | test4   | test5   | test6   | test7   | test8   | test9   | test10                                                       | avreage    |      | m      | k    |
| 20    | 0.04215 | 0.04275 | 0.04195 | 0.0413  | 0.04155 | 0.0421  | 0.04085 | 0.04185 | 0.0434  | 0.04185                                                      | 0.04195556 |      | 57143  | 3    |
| 25    | 0.01945 | 0.01925 | 0.0198  | 0.0188  | 0.01925 | 0.01865 | 0.01885 | 0.01835 | 0.01865 | 0.01875                                                      | 0.01892778 |      | 71429  | 4    |
| 30    | 0.00925 | 0.00915 | 0.01055 | 0.01235 | 0.00975 | 0.00965 | 0.0108  | 0.0138  | 0.00815 | 0.0078                                                       | 0.01034444 |      | 85714  | 5    |
| 35    | 0.00465 | 0.00405 | 0.0051  | 0.0059  | 0.00445 | 0.00405 | 0.0041  | 0.005   | 0.0054  | 0.005                                                        | 0.00477    |      | 100000 | 6    |
| 40    | 0.0024  | 0.00245 | 0.00215 | 0.00175 | 0.002   | 0.002   | 0.00205 | 0.0021  | 0.0019  | 0.0024                                                       | 0.00212    |      | 114286 | 7    |
| 45    | 0.00115 | 0.0009  | 0.00095 | 0.00095 | 0.001   | 0.0008  | 0.00085 | 0.001   | 0.00075 | 0.0008 | 0.000915   |      | 128571 | 8    |
| 50    | 0.00045 | 0.00055 | 0.0004  | 0.00045 | 0.00045 | 0.00045 | 0.0004  | 0.0004  | 0.0004  | 0.00045                                                      | 0.00044    |      | 142857 | 9    |
| 55    | 0.00025 | 0.0002  | 0.0002  | 0.00025 | 0.00025 | 0.00035 | 0.0002  | 0.0003  | 0.0003  | 0.00025                                                      | 0.00025556 |      | 157143 | 10   |

### Scenario L = 8


| L = 8 | 8 bits      |         |         |         |         |         |         |         |         |         |            |      |        |      |
| ----- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ---------- | ---- | ------ | ---- |
|       | test1   | test2   | test3   | test4   | test5   | test6   | test7   | test8   | test9   | test10  | avreage    |      | m      | k    |
| 20    | 0.0423  | 0.05665 | 0.05785 | 0.0598  | 0.0452  | 0.04275 | 0.0574  | 0.04575 | 0.04825 | 0.05475 | 0.05204444 |      | 50000  | 3    |
| 25    | 0.0213  | 0.0218  | 0.02105 | 0.02135 | 0.0211  | 0.0231  | 0.02215 | 0.02395 | 0.02115 | 0.02245 | 0.02201111 |      | 62500  | 4    |
| 30    | 0.0108  | 0.0089  | 0.00945 | 0.01005 | 0.0102  | 0.0101  | 0.0113  | 0.0122  | 0.0116  | 0.0114  | 0.01057778 |      | 75000  | 5    |
| 35    | 0.00405 | 0.00405 | 0.0045  | 0.0048  | 0.0047  | 0.00435 | 0.0054  | 0.0052  | 0.00405 | 0.00655 | 0.00484444 |      | 87500  | 6    |
| 40    | 0.00225 | 0.002   | 0.0025  | 0.0019  | 0.0022  | 0.0019  | 0.0024  | 0.0026  | 0.0023  | 0.00255 | 0.00226111 |      | 100000 | 7    |
| 45    | 0.001   | 0.0011  | 0.00095 | 0.00135 | 0.00085 | 0.00095 | 0.0009  | 0.0012  | 0.00115 | 0.0016  | 0.00111667 |      | 112500 | 8    |
| 50    | 0.0002  | 0.00035 | 0.00055 | 0.0004  | 0.0007  | 0.0007  | 0.0004  | 0.0005  | 0.00035 | 0.0007  | 0.00051667 |      | 125000 | 9    |
| 55    | 0.0001  | 0.0002  | 0.0003  | 0.0001  | 0.0001  | 0.00035 | 0.0004  | 0.00015 | 0.0002  | 0.0001  | 0.0002     |      | 137500 | 10   |

### Scenario L = 16


| L = 16 | 9 bits      |         |         |         |         |         |         |         |         |         |            |      |        |      |
| ------ | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- | ---------- | ---- | ------ | ---- |
|        | test1   | test2   | test3   | test4   | test5   | test6   | test7   | test8   | test9   | test10  | avreage    |      | m      | k    |
| 20     | 0.05405 | 0.0507  | 0.0524  | 0.05675 | 0.0565  | 0.0541  | 0.05435 | 0.0541  | 0.0546  | 0.05325 | 0.05408333 |      | 44444  | 3    |
| 25     | 0.02645 | 0.0267  | 0.02455 | 0.02435 | 0.0267  | 0.02385 | 0.02655 | 0.0259  | 0.0261  | 0.0273  | 0.02577778 |      | 55556  | 4    |
| 30     | 0.0135  | 0.0131  | 0.01385 | 0.0125  | 0.0129  | 0.01385 | 0.01325 | 0.01345 | 0.0132  | 0.0135  | 0.01333333 |      | 66667  | 5    |
| 35     | 0.0064  | 0.0068  | 0.00685 | 0.00665 | 0.00675 | 0.00615 | 0.00615 | 0.00695 | 0.00685 | 0.0064  | 0.006595   |      | 77778  | 6    |
| 40     | 0.00305 | 0.00265 | 0.00305 | 0.00315 | 0.0033  | 0.003   | 0.00345 | 0.00315 | 0.00345 | 0.00335 | 0.00314444 |      | 88889  | 7    |
| 45     | 0.00145 | 0.00145 | 0.0013  | 0.00165 | 0.0017  | 0.0017  | 0.00115 | 0.00175 | 0.00165 | 0.00155 | 0.00152222 |      | 100000 | 8    |
| 50     | 0.00085 | 0.0008  | 0.00055 | 0.00055 | 0.0008  | 0.00065 | 0.0006  | 0.00095 | 0.00055 | 0.00055 | 0.00067857 |      | 111111 | 9    |
| 55     | 0.0004  | 0.00045 | 0.0004  | 0.0004  | 0.0005  | 0.0003  | 0.0003  | 0.00035 | 0.0005  | 0.0005  | 0.00041111 |      | 122222 | 10   |

## Summary

![](https://img2018.cnblogs.com/blog/1092957/201906/1092957-20190604222520794-1268984295.png)
