# 2023_Kart_Project

Dans ce dossier GitHub, vous trouverez toutes les informations pour continuer le projet.
Ce dernier est composé d'une carte de commande avec la NUCLEO STM32G431RB ainsi que d'un onduleur.

## Table des matières

- [Cahier des charges](#charges)
- [PCB de commande](#commande)
- [Onduleur](#onduleur)
- [Code](#code)

## Cahier des charges

Le but est de faire rouler le kart à 20 km/h.
Le moteur est un moteur OZO 3500W à alimenter en 72 V (https://ozo-electric.com/fr/moteurs-centraux-brushless/679130-moteur-moto-3500w-electrique-central-brushless-bldc.html).
La batterie fourni une tension de  72V (https://ozo-electric.com/fr/72v/282892-batterie-72v-21ah-1512wh-pvc-panasonic-lithium.html#/285-connecteur_de_charge-anderson_pp30/282864-bms-60a_continu_250a_max_compatible_charge_rapide_10a/168358-connecteur_de_puissance-amass_xt90).

## PCB de commande

Ce PCB est composé de la carte NUCLEO, d'une isolation galvanique et d'un level-shifter.
L'isolation galvanique pourra disparaître pour faire un seul PCB commun par la suite. En effet, des optocoupleurs sont prévus comme driver de MOSFET.

## Onduleur

L'onduleur a les caractéristiques suivantes : 
- Tension d'alimentation : 72 V
- Courant nominal : 48 A
De plus, sur cette carte, nous avons prévu une alimentation 15V afin d'alimenter la carte de commande.

## Code

Le code est réalisé avec STM32CubeIDE.
Nous utilisons : 
- 6 sorties GPIO pour commander l’onduleur
- 3 entrées GPIO pour les capteurs Hall
- 1 entrée ADC pour le potentiomètre
- 1 entrée ADC pour le capteur de tension de la batterie
- 1 entrée ADC pour les capteurs de courant de phase

