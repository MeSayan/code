def readContents():
  contents = []
  while( True ):
    line = input()
    if line == "":
      break
    else:
      contents = contents + [line]
  return(contents)

def readfromfile(filename):
  contents = []
  fh = open(filename,"r");
  contents = fh.readlines();
  fh.close()
  return(contents)


def playerDict(matchinfo):
  ( playerdict, players ) = ( {} , [] )

  for i in matchinfo:
    players = i.split(":")
    if players[0] not in playerdict.keys():
      playerdict[ players[0] ] = [ 0,0,0,0,0,0 ]
    if players[1] not in playerdict.keys():
      playerdict[ players[1] ] = [ 0,0,0,0,0,0 ]
    players = []

  return(playerdict)

def process(playerDict,matchinfo):
  ( winner,loser,score,terms ) = ( "","","",[] )
  for i in matchinfo:
    terms = i.split(":")

    (winner,loser,score) = ( terms[0],terms[1],terms[2] )

    #print("Winner:",winner,"Loser:",loser,"Score:",score,end="")
    #print("Before Match:",playerDict[winner],playerDict[loser])
    sets = score.split(",")

    # Computing whether best-of-3 or best-of-5
    if len(sets) > 3:
      playerDict[winner][0] += 1
    else:
      playerDict[winner][1] += 1

    ## Setting No of sets won for each player
    setcount  = 0
    for i in sets:
      playerDict[winner][3] += int(i[0])
      playerDict[loser][3]   += int(i[2])
      playerDict[winner][5] += int(i[2])
      playerDict[loser][5] += int(i[0])
      pos = i.index("-")
      if i[0:pos] > i[pos+1]:
        # Winner wins the game
        setcount += 1
        playerDict[winner][2] += 1
        playerDict[loser][4]  += 1
        #print(playerDict[winner],playerDict[loser],"setcount",setcount)

      else:
        # Loser wins the set
        playerDict[loser][2]  += 1
        playerDict[winner][4] += 1
        #print(playerDict[winner],playerDict[loser])
    #print("After Match:",playerDict[winner],playerDict[loser])
  return(playerDict)


def appendPlayerName(playerDict):
  for i in playerDict.keys():
    playerDict[i].insert(0,i)
  return(playerDict)

def comparePlayers(a,b):
  for i in range(1,len(a)):
    if a[i] > b[i]:
      return(1)
    elif a[i] < b[i]:
      return(-1)
  return(0)



contents = readfromfile("Data")
#for i in contents:
  #print(i,end="")


playerDict = process(playerDict(contents),contents)
playerDict = appendPlayerName(playerDict)
playerList = list(playerDict)
print(playerList)
playerList = sorted(playerList,key=comparePlayers)

print(playerList)

#
#for i in playerDict.keys():
#print(playerDict[i],sep=":\t")

