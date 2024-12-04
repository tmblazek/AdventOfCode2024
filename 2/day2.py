import numpy as np
def checkPassing (line):
    return len(np.unique(np.sign(np.diff(line)))) == 1 and np.all(np.abs(np.diff(line))<4) and (np.unique(np.sign(np.diff(line)))[0] != 0)
def main():
    entries = []
    with open ("input2.txt", "r") as fp:
        while (line :=fp.readline()):
            newentry = [int(x) for x in line.split(" ")]
            entries.append(newentry)
    passing = 0
    for line in entries:
        if checkPassing(line):
            passing+=1
    print(f"Passing 1: {passing}")
    passing = 0
    for idx, line in enumerate(entries):
        if (checkPassing(line)):passing+=1
        else:
            for ii in range(len(line)):
                redline = line.copy()
                del redline[ii]
                if(checkPassing(redline)):
                    passing+=1
                    break
            else:
                print(idx)
    print(f"Passing 2: {passing}")
     
        


if __name__ == "__main__": main()         
        



