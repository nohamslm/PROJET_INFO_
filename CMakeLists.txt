cmake_minimum_required(VERSION 3.29)
project(PROJET_INFO_FINAL C)

set(CMAKE_C_STANDARD 23)

add_executable(PROJET_INFO_FINAL main.c
        source.c
        header.h
        menu.c
        menu.h
        joueur.c
        joueur.h
        plateau.c
        plateau.h
        deplacement.c
        deplacement.h
        score.c
        score.h
        sauvegarde.c
        sauvegarde.h
        aide.c
        aide.h)
