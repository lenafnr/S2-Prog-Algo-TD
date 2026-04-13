#include <iostream>
#include <vector>
#include <unordered_set>

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
    Position(int x, int y) : x(x), y(y) {}

    bool operator==(const Position &p) const
    {
        return x == p.x && y == p.y;
    }

    Position &operator+=(Direction d)
    {
        if (d == Direction::Up) y--;
        else if (d == Direction::Down) y++;
        else if (d == Direction::Left) x--;
        else if (d == Direction::Right) x++;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const Position &p)
{
    return os << '(' << p.x << ", " << p.y << ')';
}

Direction turn_right(Direction d)
{
    if (d == Direction::Up) return Direction::Right;
    if (d == Direction::Right) return Direction::Down;
    if (d == Direction::Down) return Direction::Left;
    return Direction::Up;
}

struct StructMap
{
    std::vector<Position> obstacles;
    Position guardPosition;
    Direction guardDirection;
    int width{};
    int height{};
};

StructMap parse_input(std::istream &input_stream)
{
    StructMap map;
    int y = 0;

    for (std::string line{}; std::getline(input_stream, line, '\n') and line != "";)
    {
        map.width = line.size();

        for (int x = 0; x < (int)line.size(); x++)
        {
            char c = line[x];

            if (c == '#')
                map.obstacles.push_back(Position(x, y));
            else if (c == '^')
            {
                map.guardDirection = Direction::Up;
                map.guardPosition = Position(x, y);
            }
            else if (c == 'v')
            {
                map.guardDirection = Direction::Down;
                map.guardPosition = Position(x, y);
            }
            else if (c == '<')
            {
                map.guardDirection = Direction::Left;
                map.guardPosition = Position(x, y);
            }
            else if (c == '>')
            {
                map.guardDirection = Direction::Right;
                map.guardPosition = Position(x, y);
            }
        }
        y++;
    }

    map.height = y;
    return map;
}

namespace std
{
    template <>
    struct hash<Position>
    {
        std::size_t operator()(const Position &pos) const
        {
            return std::hash<int>()(pos.x) ^ (std::hash<int>()(pos.y) << 1);
        }
    };
}

struct WalkResult
{
    Position final_position;
    size_t steps_taken;
    std::unordered_set<Position> visited_positions;
};

bool is_obstacle(const Position &p, const std::vector<Position> &obstacles)
{
    for (const auto &o : obstacles)
        if (o == p)
            return true;
    return false;
}

WalkResult simulate_guard(const StructMap &map, size_t max_steps)
{
    WalkResult result;

    Position position = map.guardPosition;
    Direction direction = map.guardDirection;

    result.visited_positions.insert(position);

    size_t steps = 0;

    while (steps < max_steps)
    {
        Position next = position;
        next += direction;

        // partie debug grace a l'IA car je n'avais pas le bon nb de sorties
        if (next.x < 0 || next.x >= map.width ||
            next.y < 0 || next.y >= map.height)
        {
            break;
        }

        if (is_obstacle(next, map.obstacles))
        {
            direction = turn_right(direction);
        }
        else
        {
            position = next;
            result.visited_positions.insert(position);
            steps++;
        }
    }

    result.final_position = position;
    result.steps_taken = steps;

    return result;
}

int main()
{
    StructMap map = parse_input(std::cin);

    WalkResult result = simulate_guard(map, 10000);

    std::cout << "Nb positions: "
              << result.visited_positions.size() << std::endl;
}