def orangecap(dict):
    players = {}
    topscorer = ''
    topscore = 0
    for match in dict.keys():
        for player in dict[match].keys():
            if player not in players:
                players[player] = 0
    
    
    for match in dict.keys():
        for player in dict[match].keys():
            players[player] = players[player] + dict[match][player]
    
    ## Finding Top Score
    (topscore,topscorer) = (0,"") 
    for player in players.keys():
        if players[player] > topscore:
            topscore = players[player]
            topscorer = player
    	
    print(players)
    return(topscorer,topscore)




	





	



    


    

