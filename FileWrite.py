

def writeListToFile(list ,filename):
    f = open(filename,'a')
    stringOfCoordinates = ""
    for coordinate in list:
        for component in coordinate:
            stringOfCoordinates += str(component) + " "
        stringOfCoordinates += "\n"
    f.write(stringOfCoordinates)





if __name__ == '__main__':
    I = [(1.0,50.2),(2.2,100.3),(1.5,40.1),(0,0)]
    writeListToFile(I, "data/data.txt")
