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
        main.cpp src/model/plateau/Plateau.tpp hrc/model/plateau/Plateau.hpp src/model/joueurs/Player.tpp hrc/model/joueurs/Player.hpp src/model/joueurs/PlayerDominos.cpp hrc/model/joueurs/PlayerDominos.hpp src/model/joueurs/PlayerCarcassonne.tpp hrc/model/joueurs/PlayerCarcassonne.hpp hrc/model/enum/environment.hpp hrc/model/enum/colorCarcassonne.hpp hrc/model/enum/colorTrax.hpp src/model/tuile/Tuile.cpp hrc/model/tuile/Tuile.hpp src/model/tuile/TuileDominos.cpp hrc/model/tuile/TuileDominos.hpp src/model/tuile/TuileTrax.cpp hrc/model/tuile/TuileTrax.hpp src/model/tuile/TuileCarcassonne.cpp hrc/model/tuile/TuileCarcassonne.hpp src/model/plateau/Pion.cpp hrc/model/plateau/Pion.hpp src/model/Sac.cpp hrc/model/Sac.hpp hrc/model/enum/roleCarcassonne.hpp src/model/joueurs/PlayerTrax.cpp hrc/model/joueurs/PlayerTrax.hpp hrc/model/enum/directionTuile.hpp src/model/tuile/fragment/FragmentTuile.tpp hrc/model/tuile/fragment/FragmentTuile.hpp src/model/tuile/fragment/FragmentTriple.tpp hrc/model/tuile/fragment/FragmentTriple.hpp src/model/tuile/fragment/FragmentSolo.tpp hrc/model/tuile/fragment/FragmentSolo.hpp src/controler/Controller.cpp hrc/controler/Controller.hpp src/model/plateau/PlateauCarcassonne.cpp hrc/model/plateau/PlateauCarcassonne.hpp src/model/plateau/PlateauDominos.cpp hrc/model/plateau/PlateauDominos.hpp src/model/plateau/PlateauTrax.cpp hrc/model/plateau/PlateauTrax.hpp src/model/vector/AxeVector.tpp hrc/model/vector/AxeVector.hpp hrc/view/obj/composant/ComposantView.h src/view/obj/composant/ComposantView.cpp src/view/obj/tuile/TuileDominosObjView.cpp hrc/view/obj/tuile/TuileDominosObjView.h src/view/obj/plateau/PlateauObjView.cpp hrc/view/obj/plateau/PlateauObjView.h src/view/obj/composant/ButtonObj.cpp hrc/view/obj/composant/ButtonObj.h hrc/view/obj/state/State.h src/view/obj/state/view/MenuView.cpp hrc/view/obj/state/view/MenuView.h src/view/obj/state/view/SettingsStateView.cpp hrc/view/obj/state/view/SettingsStateView.h src/view/obj/state/view/PlateauDominoStateView.cpp hrc/view/obj/state/view/PlateauDominoStateView.h src/view/obj/composant/BackGroundObjView.cpp hrc/view/obj/composant/BackGroundObjView.h src/view/obj/state/view/PlateauTraxStateView.cpp hrc/view/obj/state/view/PlateauTraxStateView.h src/view/obj/tuile/TuileTraxObjView.cpp hrc/view/obj/tuile/TuileTraxObjView.h src/model/tuile/fragment/FragmentQuadruple.tpp hrc/model/tuile/fragment/FragmentQuadruple.hpp src/view/obj/state/view/PlateauCarcassonneStateView.cpp hrc/view/obj/state/view/PlateauCarcassonneStateView.hpp src/view/obj/tuile/TuileCarcassonneObjView.cpp hrc/view/obj/tuile/TuileCarcassonneObjView.hpp)

##sfml

target_link_libraries (cpp_projet_2022_jeu sfml-graphics sfml-window sfml-system)

##smfl