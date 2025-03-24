# Jeu de Cochon

## Rêgles 
```
- si 1 alors on perd tout les points non mis en banque, et on passe au joueur suivant
- 2 = 2 points 
- 3 = 3 points
- 4 = 4 points
- 5 = 5 points
- 6 = 6 points
```

- R pour rolling et donc lancer un tirage, B pour bank et save les points 

## Les Robots

Si on choisit de jouer avec des bots on définit si on joue avec ou plusieurs, on leur donne un nom random choisit dans une liste

Après on demande de choisir le niveau du/des bots, entre 1 et 3
```
- 1 - le/les bot/s joue/nt aléatoirement
- 2 - le sauvegarde tout les 5 lancés 
- 3 - le/les bot/s se base/nt sur les points en bank du joueur (et des autres bots) pour choisir ses actions 
```