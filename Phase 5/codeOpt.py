import time
def printl(list1):
    for i in list1:
        print(i)
        time.sleep(0.05)
        
def listToString(s):
    str1 = ""
    for ele in s:
        str1 += ele
        str1 += "\n"
    return str1

def existslabel(lines, i):
    if(i == 0):
        return 0
    while(i>=0):
        if(len(lines[i].split()) == 2):
            return 1
        i = i - 1
    return 0
        
def exists_lhs(lines, variable, start, end):
    for i in range(start, end):
        if(lines[i].split()[0] == variable):
            return 1
    return 0
def exists_rhs(lines, lhs, start):
    for i in range(len(lines)-1, start-1, -1):
        if(len(lines[i].split()) == 5):
            rhs1 = lines[i].split()[2]
            rhs2 = lines[i].split()[4]
            if(rhs1 == lhs or rhs2 == lhs):              
                return i
        elif(len(lines[i].split()) == 3):
            rhs = lines[i].split()[2]
            if(rhs == lhs):
                return i
        elif(len(lines[i].split()) == 4):
            rhs = lines[i].split()[1]
            l1 = ""
            l2 = ""
            fl = 0
            for x in rhs:
                if x in [">", "<", "=", "!"]:
                    fl = 1
                    continue
                if (x == "="):
                    continue
                if(fl == 0):
                    l1 = l1 + x
                if(fl == 1):
                    l2 = l2 + x
            if(l1 == lhs or l2 == lhs):
                return i
    return -1
        
        
def findLoopLines(lines):
    gotoindex = dict()
    loopblock = []
    labelindex = dict()
    for i in range(len(lines)):
        lines[i] = lines[i].strip("\n")
        if(len(lines[i].split())==2 and lines[i].split()[0] == 'goto'):
            gotoindex[lines[i].split()[1]] = i
        if(len(lines[i].split()) == 2 and lines[i].split()[1] == ':'):
            labelindex[lines[i].split()[0]] = i
    for key in gotoindex:
        if(gotoindex[key]>labelindex[key]):
            loopblock.append([labelindex[key], gotoindex[key]])
    return loopblock

def loopMotion(lines):
    for i in range(len(lines)):
        lines[i] = lines[i].strip("\n")
    loopblock = findLoopLines(lines)
    for i in loopblock:
        initloc = i[0]
        for j in range(i[0], i[1]):
            
                
            if(len(lines[j].split()) == 3 and (lines[j].split()[0][0]!='*' and lines[j].split()[2].isdigit())):
                temp = lines.pop(j)
                lines.insert(initloc, temp)
                initloc+=1
            if(len(lines[j].split())==3 and (lines[j].split()[0][0]!='*' and lines[j].split()[2][0]!='*')):
                arg = lines[j].split()[2]
                
                if(not exists_lhs(lines, arg, initloc, i[1])):
                    temp = lines.pop(j)
                    lines.insert(initloc, temp)
                    initloc+=1
            if(len(lines[j].split()) == 5):
                arg1 = lines[j].split()[2]
                arg2 = lines[j].split()[4]
                
                if(arg1.isdigit() and arg2.isdigit() and (lines[j].split()[0][0]!='*')):
                    temp = lines.pop(j)
                    lines.insert(initloc, temp)
                    initloc+=1
                elif(arg1.isdigit()and (arg2[0]!='*' and lines[j].split()[0][0]!='*')):
                    if(not exists_lhs(lines, arg2, initloc, i[1])):
                       temp = lines.pop(j)
                       lines.insert(i[0], temp)
                elif(arg2.isdigit()and (arg1[0]!='*' and lines[j].split()[0][0]!='*')):
                    if(not exists_lhs(lines, arg1, initloc, i[1])):
                        temp = lines.pop(j)
                        lines.insert(initloc, temp)
                        initloc+=1
                else:
                    if(not exists_lhs(lines, arg1, initloc, i[1]) and not exists_lhs(lines, arg2, initloc, i[1]) and (arg1[0]!='*' and arg2[0]!='*' and lines[j].split()[0][0]!='*')):
                        temp  = lines.pop(j)
                        lines.insert(initloc, temp)
                        initloc+=1
            
                        
                        
            
                
                
    printl(lines)
    return lines, loopblock
    
    
def elimDeadCode(lines):
    flag = 0
    newlines = []
    for i in range(len(lines)):
        lines[i] = lines[i].strip("\n")
        outflag = 0
        if(existslabel(lines, i) == 1):
            newlines.append(lines[i])
            continue
        if(len(lines[i].split()) == 5 or len(lines[i].split()) == 3):

            lhs = lines[i].split()[0]
            
            for j in range(i+1, len(lines)):

                if(len(lines[j].split()) == 5):
                    rhs1 = lines[j].split()[2]
                    rhs2 = lines[j].split()[4]
                    if(rhs1 == lhs or rhs2 == lhs):
                        outflag = 1
                        flag = 1
                        break

                elif(len(lines[j].split()) == 3):

                    rhs = lines[j].split()[2]

                    if(rhs == lhs):
                        outflag =1
                        flag = 1
                        break
                
                elif(len(lines[j].split()) == 4):
                    rhs = lines[j].split()[1]
                    l1 = ""
                    l2 = ""
                    fl = 0
                    
                    for x in rhs:
                        if x in [">", "<", "=", "!"]:
                            fl = 1
                            continue
                        if (x == "="):
                            continue
                        if(fl == 0):
                            l1 = l1 + x
                        if(fl == 1):
                            l2 = l2 + x
                    
                    if(l1 == lhs or l2 == lhs):
                        flag = 1
                        outflag = 1
                        break
                else:

                    continue

            if(outflag == 1):
                
                newlines.append(lines[i])
                    
                    
                
        else:
            newlines.append(lines[i])
            continue
    
    return newlines

                
fin = open("input.txt", "r")
fout = open("Optimized_ICG.txt", "w")


lines = fin.readlines()

for i in lines:
    print(i)

print()
print("Dead Code Elimination")
print("_____________________")
print()
lines = elimDeadCode(lines)
printl(lines)
looplines = findLoopLines(lines)
loop = []
for i in range(len(looplines)):
    for j in range(looplines[i][0], looplines[i][1]+1):
        loop.append(j)


print("Loop Invariant Code Motion")
print("__________________________")
print()
lines, loopblock = loopMotion(lines)
optimizedOutput = listToString(lines)
fout.write(optimizedOutput)


