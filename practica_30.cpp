#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Clase Pokemon
class Pokemon
{
private:
    std::string name;
    std::string type;
    std::string description;

public:
    Pokemon(std::string name, std::string type, std::string description) : name(name), type(type), description(description) {}

    std::string getName() const
    {
        return name;
    }

    std::string getType() const
    {
        return type;
    }

    std::string getDescription() const
    {
        return description;
    }
};

// Clase Pokedex
class Pokedex
{
private:
    std::vector<Pokemon> pokemonList;

public:
    void addPokemon(const Pokemon &pokemon)
    {
        pokemonList.push_back(pokemon);
    }

    Pokemon searchPokemonByName(const std::string &name) const
    {
        auto it = std::find_if(pokemonList.begin(), pokemonList.end(), [&name](const Pokemon &pokemon)
                               { return pokemon.getName() == name; });

        if (it != pokemonList.end())
        {
            return *it;
        }
        else
        {
            return Pokemon("", "", "");
        }
    }

    void displayPokemonDetails(const Pokemon &pokemon) const
    {
        std::cout << "Name: " << pokemon.getName() << std::endl;
        std::cout << "Type: " << pokemon.getType() << std::endl;
        std::cout << "Description: " << pokemon.getDescription() << std::endl;
    }
};

// Función para agregar un Pokémon de manera manual a la Pokédex
void addPokemonManually(Pokedex &pokedex)
{
    std::string name, type, description;
    std::cout << "Enter the name of the Pokémon: ";
    std::cin >> name;
    std::cout << "Enter the type of the Pokémon: ";
    std::cin >> type;
    std::cout << "Enter the description of the Pokémon: ";
    std::cin.ignore(); // Ignorar el salto de línea pendiente
    std::getline(std::cin, description);

    Pokemon newPokemon(name, type, description);
    pokedex.addPokemon(newPokemon);

    std::cout << "Pokémon added successfully!" << std::endl;
}

// Función para crear un equipo Pokémon
void createPokemonTeam(Pokedex &pokedex)
{
    std::vector<Pokemon> team;
    int teamSize;
    std::cout << "Enter the size of the Pokémon team: ";
    std::cin >> teamSize;

    for (int i = 0; i < teamSize; i++)
    {
        std::string name;
        std::cout << "Enter the name of Pokémon " << i + 1 << ": ";
        std::cin >> name;

        Pokemon pokemon = pokedex.searchPokemonByName(name);
        if (pokemon.getName() != "")
        {
            team.push_back(pokemon);
            std::cout << "Pokémon added to the team!" << std::endl;
        }
        else
        {
            std::cout << "Pokémon not found in the Pokédex." << std::endl;
        }
    }

    // Mostrar los detalles del equipo Pokémon
    std::cout << "Pokémon Team:" << std::endl;
    for (const Pokemon &pokemon : team)
    {
        pokedex.displayPokemonDetails(pokemon);
        std::cout << std::endl;
    }
}

int main()
{
    // Crear una instancia de la Pokedex
    Pokedex pokedex;
    char option;

    std::cout << "quiere registrar pokemons nuevos?";
    std::cin >> option;

    // Agregar algunos Pokémon a la Pokédex
    do
    {
        if (option == 'S' || option == 's')
        {
            addPokemonManually(pokedex);

            std::cout << "quiere registrar pokemons nuevos?";
            std::cin >> option;
        }
        else
        {
            break;
        }
    } while (option != 'N' || option != 'n');

    // Búsqueda y visualización de detalles de Pokémon
    std::string searchName;
    std::cout << "Enter the name of the Pokémon to search: ";
    std::cin >> searchName;

    Pokemon foundPokemon = pokedex.searchPokemonByName(searchName);

    if (foundPokemon.getName() != "")
    {
        std::cout << "Pokémon found!" << std::endl;
        pokedex.displayPokemonDetails(foundPokemon);
    }
    else
    {
        std::cout << "Pokémon not found." << std::endl;
    }

    // crear equipo pokemon
    createPokemonTeam(pokedex);

    return 0;
}
