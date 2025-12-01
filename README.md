# Cartographie Réseau 101 : Exploration et Analyse avec le Terminal

## Postulat :

Je suis sur une machine connectée à un réseau local via Ethernet. La machine dispose d'un terminal, de l'éditeur de texte nano, ainsi que de mes compétences techniques en réseau et systèmes et programmation. Je n'ai pas accès à des outils graphiques ou à des interfaces spécialisées, ce qui limite les options disponibles.

Mon objectif est de cartographier le réseau local, c'est-à-dire d’identifier les autres machines connectées, les dispositifs réseau, leurs adresses IP et MAC, et obtenir des informations sur les services disponibles sur ces hôtes.

Je vais effectuer une reconnaissance active et passive du réseau pour obtenir un aperçu global de son architecture et de ses équipements au travers l'envoi de paquet d'apres les differente couche de reseau analysé.


## Outils 1:

uint32_t *gnr_range_ip(int network_type, const char *ip_start, const char *ip_end, uint32_t *size);

La fonction *gnr_range_ip genere un range d'ip destination pret à être utilisé dans les header ip;


/*
    les reseaux privées sont defini d'apres la rfc 1918

    FLAGS

    PRIVATE_1       10.255.255.255  (10/8 prefix)
    PRIVATE_2       172.31.255.255  (172.16/12 prefix)
    PRIVATE_3       192.168.255.255 (192.168/16 prefix)
    ALL             0.0.0.0         (0/0 prefix)
    CUSTOM          plage personalisé

*/