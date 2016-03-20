def writeListToFile(list ,filename):
    f = open(filename,'w')
    stringOfCoordinates = ""
    for coordinate in list:
        for component in coordinate:
            stringOfCoordinates += str(component) + " "
        stringOfCoordinates += "\n"
    f.write(stringOfCoordinates)





if __name__ == '__main__':
    I = [(100.0,50.2),(20.2,100.3),(100.5,40.1),(0,0)]
    writeListToFile(I, "data/data.txt")
