#include "Level.h"
#include "vector"
#include <iostream>
#ifndef LEVELONE_H
#define LEVELONE_H

#include "Level.h" // Make sure you're including the base class header

class LevelOne : public Level {
    private:
        int stageCount = 1;
        std::vector<Rectangle> platforms;
        Platform *p1 = new Platform("assets/LevelOne/platform.png", {0,800}, 1);
        Object *o1 = new Object("assets/LevelOne/tree.png", {181,420}, 1);
        Object *o2 = new Object("assets/LevelOne/tree.png", {764,321}, 1);
        Object *o3 = new Object("assets/LevelOne/stone-right-pointer.png", {423,420}, 1);
        Object *c1 = new Object("assets/LevelOne/coin.png", {1220,321}, 1);

    public:
        LevelOne() {
            Rectangle p1Size = p1->getSize();
            platforms.push_back({p1Size.x,p1Size.height - 62,p1Size.width,p1Size.height - 98}); // x,y,w,h
            platforms.push_back({530,p1Size.height- 110,p1Size.width - 530,p1Size.height - 400}); // x,y,w,h
            platforms.push_back({625,p1Size.height- 158,p1Size.width - 625,p1Size.height - 400}); // x,y,w,h

        }

        void drawPlatforms() override {
            p1->draw();

            //           for (const auto &platform : platforms) {
            //             DrawRectangleLines(platform.x, platform.y, platform.width, platform.height, RED); // Visualize the platform's collision area

            //       }
        }
        void drawObjects() override {
            o1->draw();
            o2->draw();
            o3->draw();
            c1->draw();
        }
        std::vector<Rectangle> getPlatforms() override { return platforms; }

        void update() override {
            // Update logic specific to LevelOne
        }
};

#endif // LEVELONE_H
