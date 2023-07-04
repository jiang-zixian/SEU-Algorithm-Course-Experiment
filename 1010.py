def binary_search(lst, target):

    #return: 目标元素在列表中的索引，若不存在则返回-1
    left=0
    right=len(lst) - 1
    mid=oldmid=0
    while left <= right:
        oldmid=mid
        print(left, right,oldmid)
        mid = (left + right) // 2
        if lst[mid] == target:
            return [mid,oldmid]
        elif lst[mid] < target:
            left = mid+1
        else:
            right = mid-1
    return [-1,oldmid]

if __name__ == '__main__':
    M=int(input())  # 测试多少组
    for i in range(1,M+1):
        n, target, *lst = map(int, input().split())
        print(n,target,lst)
        [mid,oldmid]=binary_search(lst, target)
        if mid==-1:
            print("not found, father is ", lst[oldmid])
        else:
            print("success, father is ",lst[oldmid])
