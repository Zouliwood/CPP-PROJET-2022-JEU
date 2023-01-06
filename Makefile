CC= g++ -Wall -std=c++11 #factorisation pour la lisibilité
CCO= $(CC) -c $< #factorisation
LIBS= -lsfml-graphics -lsfml-window -lsfml-system #SFML
OBJECTS= PionObjView.o ControllerTrax.o ControllerDominos.o ControllerCarcassonne.o TuileTraxObjView.o TuileDominosObjView.o TuileCarcassonneObjView.o State.o SettingsStateView.o PlateauTraxStateView.o PlateauDominosStateView.o PlateauCarcassonneStateView.o MenuView.o PlateauObjView.o PanelPionObjView.o ComposantView.o ButtonObj.o BackGroundObjView.o Sac.o AxeVector.o TuileTrax.o TuileDominos.o TuileCarcassonne.o Tuile.o FragmentTuile.o FragmentTriple.o FragmentSolo.o FragmentQuadruple.o PlateauTrax.o PlateauDominos.o PlateauCarcassonne.o Controller.o colorTrax.o directionTuile.o environment.o roleCarcassonne.o Player.o PlayerCarcassonne.o PlayerDominos.o PlayerTrax.o Pion.o Plateau.o main.o #Test.o #Tous nos objets

HRC=hrc/
SRC=src/
ENUM=hrc/model/enum/

all	:$(OBJECTS) #pour le make de base todo: fichier out
	$(CC) -o runtest $(OBJECTS) $(LIBS)

Main.o:	main.cpp
	$(CCO)

Controller.o: $(SRC)/controller/Controller.cpp $(HRC)/controller/Controller.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

ControllerCarcassonne.o: $(SRC)/controller/ControllerCarcassonne.cpp $(HRC)/controller/ControllerCarcassonne.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

ControllerDominos.o: $(SRC)/controller/ControllerDominos.cpp $(HRC)/controller/ControllerDominos.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
		$(CCO)

ControllerTrax.o: $(SRC)/controller/ControllerTrax.cpp $(HRC)/controller/ControllerTrax.hpp #ici on a un noeud avec ses deux fils couple (cpp, hpp)
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

Player.o: $(HRC)model/joueurs/Player.hpp $(SRC)model/joueurs/Player.cpp
		$(CCO)

PlayerCarcassonne.o: $(HRC)model/joueurs/PlayerCarcassonne.hpp $(SRC)model/joueurs/PlayerCarcassonne.cpp
		$(CCO)

PlayerDominos.o: $(HRC)model/joueurs/PlayerDominos.hpp $(SRC)model/joueurs/PlayerDominos.cpp
		$(CCO)

PlayerTrax.o: $(HRC)model/joueurs/PlayerTrax.hpp $(SRC)model/joueurs/PlayerTrax.cpp
		$(CCO)

Pion.o: $(HRC)model/plateau/Pion.hpp $(SRC)model/plateau/Pion.cpp
		$(CCO)

Plateau.o: $(HRC)model/plateau/Plateau.hpp $(SRC)model/plateau/Plateau.cpp
		$(CCO)

PlateauCarcassonne.o: $(HRC)model/plateau/PlateauCarcassonne.hpp $(SRC)model/plateau/PlateauCarcassonne.cpp
		$(CCO)

PlateauDominos.o: $(HRC)model/plateau/PlateauDominos.hpp $(SRC)model/plateau/PlateauDominos.cpp
		$(CCO)

PlateauTrax.o: $(HRC)model/plateau/PlateauTrax.hpp $(SRC)model/plateau/PlateauTrax.cpp
		$(CCO)

FragmentQuadruple.o: $(HRC)model/tuile/fragment/FragmentQuadruple.hpp $(SRC)model/tuile/fragment/FragmentQuadruple.cpp
		$(CCO)

FragmentSolo.o: $(HRC)model/tuile/fragment/FragmentSolo.hpp $(SRC)model/tuile/fragment/FragmentSolo.cpp
		$(CCO)

FragmentTriple.o: $(HRC)model/tuile/fragment/FragmentTriple.hpp $(SRC)model/tuile/fragment/FragmentTriple.cpp
		$(CCO)

FragmentTuile.o: $(HRC)model/tuile/fragment/FragmentTuile.hpp $(SRC)model/tuile/fragment/FragmentTuile.cpp
		$(CCO)

Tuile.o: $(HRC)model/tuile/Tuile.hpp $(SRC)model/tuile/Tuile.cpp
		$(CCO)

TuileCarcassonne.o: $(HRC)model/tuile/TuileCarcassonne.hpp $(SRC)model/tuile/TuileCarcassonne.cpp
		$(CCO)

TuileDominos.o: $(HRC)model/tuile/TuileDominos.hpp $(SRC)model/tuile/TuileDominos.cpp
		$(CCO)

TuileTrax.o: $(HRC)model/tuile/TuileTrax.hpp $(SRC)model/tuile/TuileTrax.cpp
		$(CCO)

AxeVector.o: $(HRC)model/vector/AxeVector.hpp $(SRC)model/vector/AxeVector.cpp
		$(CCO)

Sac.o: $(HRC)model/Sac.hpp $(SRC)model/Sac.cpp
		$(CCO)

BackGroundObjView.o: $(HRC)view/obj/composant/BackGroundObjView.hpp $(SRC)view/obj/composant/BackGroundObjView.cpp
		$(CCO)

ButtonObj.o: $(HRC)view/obj/composant/ButtonObj.hpp $(SRC)view/obj/composant/ButtonObj.cpp
		$(CCO)

ComposantView.o: $(HRC)view/obj/composant/ComposantView.hpp $(SRC)view/obj/composant/ComposantView.cpp
		$(CCO)

PanelPionObjView.o: $(HRC)view/obj/plateau/PanelPionObjView.hpp $(SRC)view/obj/plateau/PanelPionObjView.cpp
		$(CCO)

PionObjView.o: $(HRC)view/obj/plateau/PionObjView.hpp $(SRC)view/obj/plateau/PionObjView.cpp
		$(CCO)

PlateauObjView.o: $(HRC)view/obj/plateau/PlateauObjView.hpp $(SRC)view/obj/plateau/PlateauObjView.cpp
		$(CCO)

MenuView.o: $(HRC)view/obj/state/view/MenuView.hpp $(SRC)view/obj/state/view/MenuView.cpp
		$(CCO)

PlateauCarcassonneStateView.o: $(HRC)view/obj/state/view/PlateauCarcassonneStateView.hpp $(SRC)view/obj/state/view/PlateauCarcassonneStateView.cpp
		$(CCO)

PlateauDominosStateView.o: $(HRC)view/obj/state/view/PlateauDominosStateView.hpp $(SRC)view/obj/state/view/PlateauDominosStateView.cpp
		$(CCO)

PlateauTraxStateView.o: $(HRC)view/obj/state/view/PlateauTraxStateView.hpp $(SRC)view/obj/state/view/PlateauTraxStateView.cpp
		$(CCO)

SettingsStateView.o: $(HRC)view/obj/state/view/SettingsStateView.hpp $(SRC)view/obj/state/view/SettingsStateView.cpp
		$(CCO)

State.o: $(HRC)view/obj/state/State.hpp
		$(CCO)

TuileCarcassonneObjView.o: $(HRC)view/obj/tuile/TuileCarcassonneObjView.hpp $(SRC)view/obj/tuile/TuileCarcassonneObjView.cpp
		$(CCO)

TuileDominosObjView.o: $(HRC)view/obj/tuile/TuileDominosObjView.hpp $(SRC)view/obj/tuile/TuileDominosObjView.cpp
		$(CCO)

TuileTraxObjView.o: $(HRC)view/obj/tuile/TuileTraxObjView.hpp $(SRC)view/obj/tuile/TuileTraxObjView.cpp
		$(CCO)

clean:
	rm -rf *.o runtest