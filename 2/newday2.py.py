amountofUnsafeReports = 0
f = open("input2.txt", "r")
for line in f:
    report = line.split()
    safe = True
    diffList = []
    for i in range(1,len(report)):
        if safe == False:
            continue
        diff = int(report[i])-int(report[i-1])
        diffList.append(diff)
        if not (0 < abs(diff) < 4):
            amountofUnsafeReports+=1
            print(amountofUnsafeReports, report, diffList)
            safe = False
    if safe:
        if all(n>0 for n in diffList) or all(n<0 for n in diffList):
            continue
        else:
            amountofUnsafeReports+=1
            print(amountofUnsafeReports, report, diffList)
            
print(1000 - amountofUnsafeReports)