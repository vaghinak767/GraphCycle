// #include <iostream>
// #include <fstream>
// #include <string>

// int main() {
//     std::ifstream inputFile("input.txt"); // Open the input file

//     if (!inputFile) {
//         std::cerr << "Error opening file." << std::endl;
//         return 1;
//     }

//     std::string line;

//     // Read the file line by line and output each line
//     while (std::getline(inputFile, line)) {
//         std::cout << "1";
//         std::cout << line << std::endl;
//     }

//     // Close the file
//     inputFile.close();

//     return 0;
// }

#include <iostream>
#include <fstream>
#include <vector>
class Graf;
class Kogh
{
private:
    friend Graf;
    int x;
    int y;

public:
    Kogh(int a, int b)
    {
        x = a;
        y = b;
    }
    friend const std::ostream &operator<<(std::ostream &out, const Kogh &a);
    friend const std::ostream &operator<<(std::ostream &out, Graf &g);
};
const std::ostream &operator<<(std::ostream &out, const Kogh &a)
{
    out << a.x << '-' << a.y << '\n';
    return out;
}

class Graf
{
private:
    std::vector<Kogh> E;
    std::vector<int> V;

public:
    Graf(std::vector<Kogh> tmp, std::vector<int> g) : E{tmp}, V{g}
    {
    }
    Graf(int a, int b)
    {
        E = std::vector<Kogh>();
        V = std::vector<int>();
    }
    int the_longest()
    {
        std::cout << "t";
        if (V.size() == 0)
        {
            return 0;
        }
        int n = V.size();
        int tmp1 = 0;
        tmp1 = check(*this, V[0]);
        int tmp2 = 0;
        for (int j = 1; j < n; ++j)
        {
            tmp2 = check(*this, V[j]);
            if (tmp2 > tmp1)
            {
                tmp1 = tmp2;
            }
        }
        return tmp1;
    }
    int check(Graf g, int gagat)
    {
        std::cout << "c";
        int s1 = 0, s2 = 0;
        int max = 0;
        int n = g.V.size();
        for (int i = 0; i < n; ++i)
        {
            if (g.E[i].x == gagat)
            {
                s1 = helper(g, gagat, gagat, s1);
            }
            else if (g.E[i].y == gagat)
            {
                s2 = helper(g, gagat, gagat, s2);
            }
            if (s1 > max)
                max = s1;
            if (s2 > max)
                max = s2;
        }
        return max;
    }
    int helper(Graf &g, int gagat, int ynt, int &erk)
    {
        std::cout << "h";
        if (g.E.size() == 1)
        {
            if (gagat == g.E[0].x && ynt == g.E[0].y || gagat == g.E[0].y && ynt == g.E[0].x)
            {
                std::cout << '1';
                return erk;
            }
            if (gagat == g.E[0].y && ynt == g.E[0].x)
            {
                std::cout << '2';
                return erk;
            }
            else
            {
                std::cout << '3';
                erk = 0;
                return erk;
            }
        }
        int n = g.E.size();
        int max = 0;
        int t = 0;
        for (int i = 0; i < n; ++i)
        {
            if (g.E[i].x == ynt)
            {
                Graf tmp(g);
                for (std::vector<Kogh>::iterator it = tmp.E.begin(); it != tmp.E.end();)
                {
                    if (it->x == E[i].x && it->y == E[i].y)
                    {
                        it = tmp.E.erase(it);
                        ++erk;
                        break;
                    }
                    else
                        ++it;
                }
                t = helper(tmp, gagat, g.E[i].y, erk);
            }
            if (t > max)
            {
                max = t;
            }
        }
        return max;
    }
    friend const std::ostream &operator<<(std::ostream &out, Graf &g);
};

const std::ostream &operator<<(std::ostream &out, Graf &g)
{
    int size = g.E.size();
    for (int i = 0; i < size; ++i)
    {
        out << g.E[i].x << '-' << g.E[i].y << '\n';
    }
    return out;
}
int main()
{
    std::ifstream file("input.txt", std::ios::in);
    std::vector<int> vec;
    std::vector<Kogh> Ee;
    if (file.is_open())
    {
        std::string tox;
        std::getline(file, tox);
        std::string tox1;
        std::getline(file, tox1);
        int size = tox1.size();
        for (int i = 1; i <= size; ++i)
        {
            vec.push_back(i);
        }
        for (int i = 0; i < size - 2; i += 4)
        {
            Ee.push_back({tox1[i] - '0', tox1[i + 2] - '0'});
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
    Graf G(Ee, vec);
    std::cout << G;
    std::cout << G.the_longest() << std::endl;
    return 0;
}
