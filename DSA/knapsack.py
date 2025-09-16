def read_properties(A):
    propfile = open("props.txt", "r")
    lines = propfile.readlines()

    for line in lines:
        A.append(line.split())
    
    if (len(A) != 3):
        print(f"Format unsupported.\nCurrent Format: {A}")
        exit(1)

    if (len(A[0]) != len(A[1]) or len(A[2]) != len(A[1])):
        print(f"All lines should be of the same length.\nFirst Line: {A[0]}\nSecond Line: {A[1]}\nThird Line: {A[2]}")
        exit(1)
    return A

def get_ProfitPerWeight(A):
    ppw = []
    ppw = A[1]/A[2]
    return ppw

def fillTheBag(A, max_w):
    pos = -1
    wt = 0

    xi = [0] * len(A)
    while(wt <= max_w):
        pos = A[3].index(max(A[3]))
        if (max(A[3]) == -1):
            break
        if (wt + A[2][pos] <= max_w):
            wt = wt + A[2][pos]
            xi[pos] = 1.0
        else:
            xi[pos] = (max_w - wt)/A[2][pos]
            wt = max_w
        A[3][pos] = -1
    return xi

A=[]
A=read_properties(A)
metric = get_ProfitPerWeight(A)
A.append(metric)

max_w = float(input("Enter the maximum weight that the bag can hold: "))
ob_ratio = fillTheBag(A, max_w)
profit = 0
for i in len(A):
    profit = profit + ob_ratio[i] * A[1]
