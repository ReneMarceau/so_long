# Choses à faire

## MLX42

- [x] Se familiariser avec les fonctions de la mlx 

## Base de game

- [x] Créer la structure de la game 
- [x] Set toutes les valeurs par défauts de la structure 
- [x] Initialisation du jeu avec `mlx_init()`

## Ouverture de fichier

- [x] Lecture de map avec `open, get_next_line, close`
- [x] Parsing de la map dans une matrice

## XPM

- [ ] Télecharger les sprites en PNG ***<sup>klaksi</sup>***
- [ ] Redimensionner les PNG à la bonne dimension
- [ ] Convertir PNG en `XPM`
- [ ] Convertir XPM en `XPM42`
- [x] Load tous les différents XPM avec `mlx_load_xpm42`
- [x] Changer toutes les textures(XPM) en images avec `mlx_texture_to_image`

## Erreurs

- [x] Écrire les différents messages d'érreurs
- [x] Nombre d'arguments `argc`
- [ ] Vérifier si le fichier existe et l'extention du fichier est bonne `.ber`
- [x] Map est rectangulaire
- [x] La map est entourée uniquement de murs
- [x] Vérifier que tous les espaces vides sont remplie de `0`
- [x] Tous les caractères sont correctes
- [x] Vérifier qu'il y a au moins 1 collectible et uniquement 1 joueur et 1 sortie
- [ ] Checker si il y a un chemin valide (il est possible de terminer la carte)

## Render

- [x] Calculer la taille de la window et la display en fonction ***<sup>rmarceau</sup>***
- [x] Analyser la map parsée et afficher en fonction de l'élement `mlx_image_to_window()`

## Interaction avec le clavier

- [x] Implementer les fonctions nécessaire pour les hooks des différents touches `mlx_key_hook()`
- [x] Permettre le personnage à bouger ou pas en fonctions des obstacles autour de lui (Chaque mouvements doient être compter)
- [ ] Ouvrir la porte après que tous les collectibles ont été collecter

## Fonction d'exit

- [x] sprites : `mlx_destroy_image()`
- [x] Windows : `mlx_destroy_window()`
- [x] mlx : `mlx_destroy_display() + free()`
- [x] Puis bien tout `free()` `valgrind`
- [x] Bien free la map quand la croix est press


## Bonus

- [ ] Afficher le nombre de mouvements sur l'écran `mlx_string_put`
- [ ] Créer des ennemies
- [ ] Ajouter des sprites animations

### Git

#### Avant de bosser
- git pull

- git checkout -b "NomDeLaBranch"

#### Après avoir bosser

- git add .

- git commit -m "René est trop stylé"

- git push

- `pull request sur github`

- git checkout main

- git pull

- git branch -D "NomDeLaBranch"

### Leaks

Pour check les leaks `leaks --atExit -- ./so_long maps/basic.ber`

### Debug

- lldb so_long "map"

- b main

- run

- gui
