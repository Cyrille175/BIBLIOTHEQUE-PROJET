# Nom de l'exécutable
EXEC = mon_programme

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -g

# Fichiers sources
SRC = main.cpp Library.cpp date.cpp Emprunt.cpp Lecteur.cpp Livre.cpp author.cpp

# Fichiers objets générés
OBJ = $(SRC:.cpp=.o)

# Règle principale pour compiler l'exécutable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Règle pour compiler les fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

# Recompiler après nettoyage
rebuild: clean $(EXEC)
