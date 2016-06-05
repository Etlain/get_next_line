# get_next_line

finished.

int	get_next_line(int const fd, char **line);

Description : 

Utilise un file descriptor(man open) pour lire en fonction 
de la taille de son BUFF_SIZE(voir .h) et stocke dans "line"
une ligne après chaque appel.

Retour      :

Retourne -1 en cas d'erreur.
