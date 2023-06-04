# -*- coding: utf-8 -*-
import random

def selection_sort(num):
    for i in range(len(num)):
        min = num[i] # 仮の最小値
        min_pos = i  # 仮の最小値の場所
        for n in range(i+1, len(num)):
            if num[n] < min : # 比較対象の数字が仮の最小値より小さければ、仮の最小値を更新
                min = num[n]
                min_pos = n
        tmp = num[i] # 最小値と最初の数を入れ替え
        num[i] = min
        num[min_pos] = tmp
    return num

def bubble_sort(num):
    for i in range(len(num)):
        for n in range(len(num)-1,i,-1):
            if num[n] < num[n-1] : # 比較対象の数字が一つ前の数字より小さければ入れ換える
                tmp = num[n]
                num[n] = num[n-1]
                num[n-1] = tmp
    return num

def heap_add(num, c):
    while True:
        p = (c-1)/2 # 親のインデックスを計算
        if p < 0 :
            break
        # 親の方が小さい場合はbreak
        if num[p] <= num[c]:
            break
        #num[p], num[c] = num[c], num[p]
        tmp = num[p]; num[p]=num[c]; num[c]=tmp
        c = p # 親ノードを新たな子ノードにする

def heap_del(num, length, p):
    while True:
        c = p*2+1 # 子のインデックスを計算
        if c >= length:
            break
        if c+1 < length and num[c+1] <= num[c] :
            c = c+1
        # 親の方が小さい場合はbreak
        if num[p] <= num[c]:
            break
        tmp = num[p]; num[p]=num[c]; num[c]=tmp
        p = c # 子ノードを新たな親ノードにする

def heap_sort(num):
    for i in range(1,len(num)):
        # 最初のヒープを作る
        heap_add(num, i)
    for i in range(len(num)):
        tmp = num[len(num)-1-i] # num[-1]
        num[len(num)-1-i] = num[0]
        num[0] = tmp
        heap_del(num, len(num)-1-i, 0)
    # 逆順にする
    for i in range(len(num)/2):
        tmp = num[i]
        num[i] = num[len(num)-i-1]
        num[len(num)-i-1] = tmp

def merge(num, left, right, size):
    tmp = [0]*(left+size)
    i = left;
    j = right;
    k = left;
    l = left + size
    while i < right and j < l:
        if num[i] < num[j]:
            tmp[k] = num[i];
            i+=1
        else:
            tmp[k] = num[j];
            j+=1
        k+=1
    if i < right :
        for h in range(i, right):
            tmp[k] = num[h];
            k+=1
    if j < l :
        for h in range(j, l):
            tmp[k] = num[h];
            k+=1
    for h in range(left, l):
        num[h] = tmp[h]

def merge_sort_impl(num, left, right):
    if left < right :
        middle = (right + left)/2
        merge_sort_impl(num, left, middle)
        merge_sort_impl(num, middle+1, right)
        merge(num, left, middle+1, right-left+1)

def merge_sort(num):
    merge_sort_impl(num, 0, len(num)-1)

def quick_sort_impl(num, first, last):
    x = (num[first] + num[last])/2
    i = first
    j = last
    while True:
        while num[i] < x:
            i+=1
        while x < num[j]:
            j-=1
        if i >= j:
            break
        num[i], num[j] = num[j], num[i] ## num[i] = num[j]; num[j] = num[i]
        i+=1;
        j-=1
    if first < i - 1:
        quick_sort_impl(num, first, i - 1)
    if j + 1 < last:
        quick_sort_impl(num, j + 1, last)

def quick_sort(num):
    quick_sort_impl(num, 0, len(num)-1)

import time
def run_sort(f):
    num = [random.randint(1,1000) for i in range(10000)]
    start = time.clock()
    # call function
    f(num)
    elapsed_time = time.clock() - start
    print("%20s : elapsed time %f [sec]"%(f.__name__, elapsed_time))


run_sort(selection_sort)
run_sort(bubble_sort)
run_sort(heap_sort)
run_sort(merge_sort)
run_sort(quick_sort)


import random
from datetime import datetime

def output_rand(length):
    random.seed(datetime.now())
    # num = [random.randint(1,1000) for i in range(length)]
    num = []
    for i in range(length):
        num.append(random.randint(0, 1000))

    f = open('rand.txt', 'w')
    f.write('%s'%num)

def run_sort(f):
    num = eval(open('rand.txt','r').read())
    start = time.clock()
    # call function
    f(num)
    elapsed_time = time.clock() - start
    print("%20s : elapsed time %f [sec]"%(f.__name__, elapsed_time))

output_rand(10000)
run_sort(selection_sort)
run_sort(bubble_sort)
run_sort(heap_sort)
run_sort(merge_sort)
run_sort(quick_sort)
