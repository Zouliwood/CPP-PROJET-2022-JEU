CC= g++ -Wall -std=c++11 #factorisation pour la lisibilité
CCO= $(CC) -c $< #factorisation
LIBS= -lsfml-graphics -lsfml-window -lsfml-system #SFML
OBJECTS= PionObjView.o ControllerTrax.o ControllerDominos.o ControllerCarcassonne.o TuileTraxObjView.o TuileDominosObjView.o TuileCarcassonneObjView.o State.o SettingsStateView.o PlateauTraxStateView.o PlateauDominosStateView.o PlateauCarcassonneStateView.o MenuView.o PlateauObjView.o PanelPionObjView.o ComposantView.o ButtonObj.o BackGroundObjView.o Sac.o AxeVector.o TuileTrax.o TuileDominos.o TuileCarcassonne.o Tuile.o FragmentTuile.o FragmentTriple.o FragmentSolo.o FragmentQuadruple.o PlateauTrax.o PlateauDominos.o PlateauCarcassonne.o Controller.o colorTrax.o directionTuile.o environment.o roleCarcassonne.o Player.o PlayerCarcassonne.o PlayerDominos.o PlayerTrax.o Pion.o Plateau.o main.o #Test.o #Tous nos objets

HRC=hrc/
SRC=src/
ENUM=hrc/model/enum/

all	:$(OBJECTS) #pour le make de base todo: fichier out
	$(CC) -o launch $(OBJECTS) $(LIBS)
	mv *.o "out" | echo "Fin du makefile... ./launch"

Main.o:	main.cpp
	$(CCO)

Controller.o: $(HRC)controller/Controller.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

ControllerCarcassonne.o: $(SRC)controller/ControllerCarcassonne.cpp $(HRC)controller/ControllerCarcassonne.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

ControllerDominos.o: $(SRC)controller/ControllerDominos.cpp $(HRC)controller/ControllerDominos.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

ControllerTrax.o: $(SRC)controller/ControllerTrax.cpp $(HRC)controller/ControllerTrax.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

#ici il n'est plus utilse de précisé le nom puisque "$<" s'en occupe

colorTrax.o: $(ENUM)colorTrax.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

directionTuile.o: $(ENUM)directionTuile.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

environment.o: $(ENUM)environment.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

roleCarcassonne.o: $(ENUM)roleCarcassonne.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

Player.o: $(SRC)model/joueurs/Player.tpp $(HRC)model/joueurs/Player.hpp
		$(CCO)

PlayerCarcassonne.o: $(SRC)model/joueurs/PlayerCarcassonne.cpp $(HRC)model/joueurs/PlayerCarcassonne.hpp
		$(CCO)

PlayerDominos.o: $(SRC)model/joueurs/PlayerDominos.cpp $(HRC)model/joueurs/PlayerDominos.hpp
		$(CCO)

PlayerTrax.o: $(SRC)model/joueurs/PlayerTrax.cpp $(HRC)model/joueurs/PlayerTrax.hpp
		$(CCO)

Pion.o: $(SRC)model/plateau/Pion.cpp $(HRC)model/plateau/Pion.hpp
		$(CCO)

Plateau.o: $(SRC)model/plateau/Plateau.tpp $(HRC)model/plateau/Plateau.hpp
		$(CCO)

PlateauCarcassonne.o: $(SRC)model/plateau/PlateauCarcassonne.cpp $(HRC)model/plateau/PlateauCarcassonne.hpp
		$(CCO)

PlateauDominos.o: $(SRC)model/plateau/PlateauDominos.cpp $(HRC)model/plateau/PlateauDominos.hpp
		$(CCO)

PlateauTrax.o: $(SRC)model/plateau/PlateauTrax.cpp $(HRC)model/plateau/PlateauTrax.hpp
		$(CCO)

FragmentQuadruple.o: $(SRC)model/tuile/fragment/FragmentQuadruple.tpp $(HRC)model/tuile/fragment/FragmentQuadruple.hpp
		$(CCO)

FragmentSolo.o: $(SRC)model/tuile/fragment/FragmentSolo.tpp $(HRC)model/tuile/fragment/FragmentSolo.hpp
		$(CCO)

FragmentTriple.o: $(SRC)model/tuile/fragment/FragmentTriple.tpp $(HRC)model/tuile/fragment/FragmentTriple.hpp
		$(CCO)

FragmentTuile.o: $(SRC)model/tuile/fragment/FragmentTuile.tpp $(HRC)model/tuile/fragment/FragmentTuile.hpp
		$(CCO)

Tuile.o: $(SRC)model/tuile/Tuile.tpp $(HRC)model/tuile/Tuile.hpp
		$(CCO)

TuileCarcassonne.o: $(SRC)model/tuile/TuileCarcassonne.cpp $(HRC)model/tuile/TuileCarcassonne.hpp
		$(CCO)

TuileDominos.o: $(SRC)model/tuile/TuileDominos.cpp $(HRC)model/tuile/TuileDominos.hpp
		$(CCO)

TuileTrax.o: $(SRC)model/tuile/TuileTrax.cpp $(HRC)model/tuile/TuileTrax.hpp
		$(CCO)

AxeVector.o: $(SRC)model/vector/AxeVector.tpp $(HRC)model/vector/AxeVector.hpp
		$(CCO)

Sac.o: $(SRC)model/Sac.cpp $(HRC)model/Sac.hpp
		$(CCO)

BackGroundObjView.o: $(SRC)view/obj/composant/BackGroundObjView.cpp $(HRC)view/obj/composant/BackGroundObjView.hpp
		$(CCO)

ButtonObj.o: $(SRC)view/obj/composant/ButtonObj.cpp $(HRC)view/obj/composant/ButtonObj.hpp
		$(CCO)

ComposantView.o: $(SRC)view/obj/composant/ComposantView.cpp $(HRC)view/obj/composant/ComposantView.hpp
		$(CCO)

PanelPionObjView.o: $(SRC)view/obj/plateau/PanelPionObjView.cpp $(HRC)view/obj/plateau/PanelPionObjView.hpp
		$(CCO)

PionObjView.o: $(SRC)view/obj/plateau/PionObjView.cpp $(HRC)view/obj/plateau/PionObjView.hpp
		$(CCO)

PlateauObjView.o: $(SRC)view/obj/plateau/PlateauObjView.cpp $(HRC)view/obj/plateau/PlateauObjView.hpp
		$(CCO)

MenuView.o: $(SRC)view/obj/state/view/MenuView.cpp $(HRC)view/obj/state/view/MenuView.hpp
		$(CCO)

PlateauCarcassonneStateView.o: $(SRC)view/obj/state/view/PlateauCarcassonneStateView.cpp $(HRC)view/obj/state/view/PlateauCarcassonneStateView.hpp
		$(CCO)

PlateauDominosStateView.o: $(SRC)view/obj/state/view/PlateauDominosStateView.cpp $(HRC)view/obj/state/view/PlateauDominosStateView.hpp
		$(CCO)

PlateauTraxStateView.o: $(SRC)view/obj/state/view/PlateauTraxStateView.cpp $(HRC)view/obj/state/view/PlateauTraxStateView.hpp
		$(CCO)

SettingsStateView.o: $(SRC)view/obj/state/view/SettingsStateView.cpp $(HRC)view/obj/state/view/SettingsStateView.hpp
		$(CCO)

State.o: $(HRC)view/obj/state/State.hpp
		$(CCO)

TuileCarcassonneObjView.o: $(SRC)view/obj/tuile/TuileCarcassonneObjView.cpp $(HRC)view/obj/tuile/TuileCarcassonneObjView.hpp
		$(CCO)

TuileDominosObjView.o: $(SRC)view/obj/tuile/TuileDominosObjView.cpp $(HRC)view/obj/tuile/TuileDominosObjView.hpp
		$(CCO)

TuileTraxObjView.o: $(SRC)view/obj/tuile/TuileTraxObjView.cpp $(HRC)view/obj/tuile/TuileTraxObjView.hpp
		$(CCO)

clean:
	rm -rf *.o launch