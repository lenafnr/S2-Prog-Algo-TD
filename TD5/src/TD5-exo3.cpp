#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card
{
    CardKind kind;
    CardValue value;

    bool operator==(Card const &other) const
    {
        return kind == other.kind && value == other.value;
    }
    size_t hash() const
    {
        return static_cast<size_t>(kind) * 13 + static_cast<size_t>(value);
    }
};

namespace std
{
    template <>
    struct hash<Card>
    {
        size_t operator()(Card const &card) const
        {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size)
{
    std::vector<Card> cards{};
    cards.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const &card)
{
    std::string name{};

    unsigned int card_value{(static_cast<unsigned int>(card.value) + 2) % 14};

    if (card_value < 10)
    {
        name += '0' + std::to_string(card_value);
    }
    else if (card_value == 10)
    {
        name += "10";
    }
    else if (card_value == 11)
    {
        name += 'J';
    }
    else if (card_value == 12)
    {
        name += 'Q';
    }
    else if (card_value == 13)
    {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart)
    {
        name += "Heart";
    }
    else if (card.kind == CardKind::Diamond)
    {
        name += "Diamond";
    }
    else if (card.kind == CardKind::Club)
    {
        name += "Club";
    }
    else if (card.kind == CardKind::Spade)
    {
        name += "Spade";
    }
    return name;
}

int main()
{
    srand(time(NULL));

    std::vector<Card> liste_cartes = get_cards(100);

    std::unordered_map<Card, int> compteur_cartes;

    for (size_t i = 0; i < liste_cartes.size(); ++i)
    {
        compteur_cartes[liste_cartes[i]]++;
    }

    for (const auto &paire : compteur_cartes)
    {
        std::cout << card_name(paire.first) << " apparait " << paire.second << " fois" << std::endl;
    }
}