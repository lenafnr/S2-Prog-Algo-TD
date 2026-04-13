#include <iostream>

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

struct Position
{
    int x{};
    int y{};

    Position() {}

    Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    };

    bool operator==(Position const p)
    {
        return x == p.x && y == p.y;
    }

    Position &operator+=(Position const p)
    {
        x += p.x;
        y += p.y;
        return *this;
    }

    Position &operator+=(Direction d)
    {
        if (d == Direction::Up)
        {
            y--;
        }
        else if (d == Direction::Down)
        {
            y++;
        }
        else if (d == Direction::Left)
        {
            x--;
        }
        else if (d == Direction::Right)
        {
            x++;
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, const Position& p)
{
    return os << '(' << p.x << ", " << p.y << ')';
}

Direction turn_right(Direction d)
{
    if (d == Direction::Up)
    {
        return Direction::Right;
    }
    else if (d == Direction::Down)
    {
        return Direction::Left;
    }
    else if (d == Direction::Left)
    {
        return Direction::Up;
    }
    else if (d == Direction::Right)
    {
        return Direction::Down;
    }
}

struct StructMap
{
    std::vector<Position> obstacles;
    Position guardPosition;
    Direction guardDirection;
};

StructMap parse_input(std::istream &input_stream)
{
    StructMap map;
    int y = 0;

    for (std::string line{}; std::getline(input_stream, line, '\n') and line != "";)
    {
        for (int x = 0; x < line.size(); x++)
        {
            char c = line[x];
            if (c == '#')
            {
                map.obstacles.push_back(Position(x, y));
            }
            else if (c == '^')
            {
                map.guardDirection = Direction::Up;
                map.obstacles.push_back(Position(x, y));
            }
            else if (c == 'v')
            {
                map.guardDirection = Direction::Down;
                map.obstacles.push_back(Position(x, y));
            }
            else if (c == '<')
            {
                map.guardDirection = Direction::Left;
                map.obstacles.push_back(Position(x, y));
            }
            else if (c == '>')
            {
                map.guardDirection = Direction::Right;
                map.obstacles.push_back(Position(x, y));
            }
        }
        y++;
    }
    return map;
}