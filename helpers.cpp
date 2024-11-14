#include "helpers.h"

void drawLine(SDL_Plotter& g, point start, point end, color _color)
{
    double distance = sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2));

    for(int i = 0; i <= distance; i++)
    {
        g.plotPixel((end.x - start.x) / distance * i + start.x,
                    (end.y - start.y) / distance * i + start.y,
                    _color);
    }
}

void drawCircle(SDL_Plotter& g, point center, int radius, color _color)
{
    for(int x = 0; x < radius * 2; x++)
    {
        for(int y = 0; y < radius * 2; y++)
        {
            // r^2 >= x^2 + y^2 to draw a filled circle
            if(pow(radius, 2) >= pow(x - radius, 2) + pow(y - radius, 2))
            {
                g.plotPixel(center.x - radius + x,
                            center.y - radius + y, _color);
            }
        }
    }
}

void drawRing(SDL_Plotter& g, point center, int radius, color _color,
              double thickness)
{
    int diff;

    for(int x = 0; x < radius * 2 + thickness * 2; x++)
    {
        for(int y = 0; y < radius * 2 + thickness * 2; y++)
        {
            diff = abs(pow(radius, 2) - (pow(x - radius - thickness, 2)
                       + pow(y - radius - thickness, 2)));

            if(diff <= radius * thickness)
            {
                g.plotPixel(center.x - radius - thickness + x,
                            center.y - radius - thickness + y, _color);
            }
        }
    }
}

//Defaults values in config.h
void createSettingsFile(int boardSize,
                        bool isPvAI,
                        bool isPlayerWhite,
                        double komi,
                        color validHighlight,
                        color invalidHighlight)
{
    ofstream file("settings.txt");
    assert(file);

    file << "Board Size:\n";
    file << boardSize << "\n";

    file << "Player vs AI:\n";
    file << isPvAI << "\n";

    file << "Player Starts White:\n";
    file << isPlayerWhite << "\n";

    file << "Komi:\n";
    file << komi << "\n";

    file << "Valid Placement HighLight Color:\n";
    file << validHighlight.R << " " << validHighlight.G
         << " " << validHighlight.B << "\n";

    file << "Invalid Placement HighLight Color:\n";
    file << invalidHighlight.R << " " << invalidHighlight.G
         << " " << invalidHighlight.B << "\n";

    file << flush;

    file.close();
}

void extractSettings(int& boardSize,
                     bool& isPvAI,
                     bool& isPlayerWhite,
                     double& komi,
                     color& validHighlight,
                     color& invalidHighlight)
{
    ifstream file("settings.txt");
    assert(file);

    string tmp;
    unsigned int r, g, b;

    getline(file, tmp);
    file >> boardSize;
    file.ignore();

    getline(file, tmp);
    file >> isPvAI;
    file.ignore();

    getline(file, tmp);
    file >> isPlayerWhite;
    file.ignore();

    getline(file, tmp);
    file >> komi;
    file.ignore();

    getline(file, tmp);
    file >> r;
    file >> g;
    file >> b;
    validHighlight = color(r,g,b);
    file.ignore();

    getline(file, tmp);
    file >> r;
    file >> g;
    file >> b;
    invalidHighlight = color(r,g,b);
    file.ignore();

    file.close();
}
