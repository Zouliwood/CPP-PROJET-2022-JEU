cmake_minimum_required(VERSION 3.23)
project(cpp_projet_2022_jeu)

set(CMAKE_CXX_STANDARD 14)

##sfml

set(SFML_INCLUDE_DIR "./SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "./SFML-2.5.1/lib")
set(SFML_DIR "./SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

##sfml

add_executable(cpp_projet_2022_jeu
        main.cpp model/src/plateau/Plateau.cpp model/hrc/plateau/Plateau.hpp model/src/joueurs/Player.cpp model/hrc/joueurs/Player.hpp model/src/joueurs/PlayerDominos.cpp model/hrc/joueurs/PlayerDominos.hpp model/src/joueurs/PlayerCarcassonne.cpp model/hrc/joueurs/PlayerCarcassonne.hpp model/hrc/enum/environment.hpp model/hrc/enum/colorCarcassonne.hpp model/hrc/enum/colorTrax.hpp model/src/tuile/Tuile.cpp model/hrc/tuile/Tuile.hpp model/src/tuile/TuileDominos.cpp model/hrc/tuile/TuileDominos.hpp model/src/tuile/TuileTrax.cpp model/hrc/tuile/TuileTrax.hpp model/src/tuile/TuileCarcassonne.cpp model/hrc/tuile/TuileCarcassonne.hpp model/src/plateau/Pion.cpp model/hrc/plateau/Pion.hpp model/src/Sac.cpp model/hrc/Sac.hpp model/hrc/enum/roleCarcassonne.hpp model/src/joueurs/PlayerTrax.cpp model/hrc/joueurs/PlayerTrax.hpp model/hrc/enum/directionTuile.hpp model/src/tuile/fragment/FragmentTuile.cpp model/hrc/tuile/fragment/FragmentTuile.hpp model/src/tuile/fragment/FragmentTriple.cpp model/hrc/tuile/fragment/FragmentTriple.hpp model/src/tuile/fragment/FragmentSolo.cpp model/hrc/tuile/fragment/FragmentSolo.hpp controler/src/Controller.cpp controler/hrc/Controller.hpp model/src/plateau/PlateauCarcassonne.cpp model/hrc/plateau/PlateauCarcassonne.hpp model/src/plateau/PlateauDominos.cpp model/hrc/plateau/PlateauDominos.hpp model/src/plateau/PlateauTrax.cpp model/hrc/plateau/PlateauTrax.hpp)

##sfml

target_link_libraries (cpp_projet_2022_jeu sfml-graphics sfml-window sfml-system)

##smfl