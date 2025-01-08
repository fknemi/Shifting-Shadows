#include "Level.h"

#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "Level.h" // Make sure you're including the base class header

class LevelTwo : public Level {
    private:
        int stageCount = 2;
        std::vector<Rectangle> platforms;

        Platform *t1 = new Platform("assets/LevelTwo/top-1.png", {0,200}, 1);
        Platform *t2 = new Platform("assets/LevelTwo/top-2.png", {800,200}, 1);
        Platform *t3 = new Platform("assets/LevelTwo/top-double-platform.png", {1500,240}, 1);
        Platform *s1 = new Platform("assets/LevelTwo/end-side-wall.png", {2058,345}, 1);
        Platform *f1 = new Platform("assets/LevelTwo/top-floating-platform.png", {1750,245}, 1);
        Platform *p1 = new Platform("assets/LevelTwo/start-platform.png", {0,800}, 1);
        Platform *p2 = new Platform("assets/LevelTwo/platform-2.png", {740,830}, 1);
        Platform *p3 = new Platform("assets/LevelTwo/platform-2.png", {1250,830}, 1);
        Platform *p4 = new Platform("assets/LevelTwo/double-platform.png", {1690,830}, 1);
        Platform *p5 = new Platform("assets/LevelTwo/platform-2.png", {1900,830}, 1);
        Object *o1 = new Object("assets/LevelTwo/bigstones.png", {1757,136}, 1);
        Object *c1 = new Object("assets/LevelTwo/coin.png", {860,528}, 1);
        Object *c2 = new Object("assets/LevelTwo/coin.png", {1394,528}, 1);
        Object *c3 = new Object("assets/LevelTwo/coin.png", {1810,450}, 1);
        Object *c4 = new Object("assets/LevelTwo/coin.png", {1810,100}, 1);

    public:
        LevelTwo() {
            Rectangle p1Size = p1->getSize();
            Rectangle p2Size = p2->getSize();
            Rectangle p3Size = p3->getSize();
            Rectangle p4Size = p4->getSize();
            Rectangle p5Size = p5->getSize();
            //   platforms.push_back({0,500,2000,10}); // x,y,w,h
            platforms.push_back({p1Size.x,1300-p1Size.y,p1Size.width,p1Size.height}); // x,y,w,h


        }

        void drawPlatforms() override {
            t1->draw();
            t2->draw();
            t3->draw();
            s1->draw();
            f1->draw();
            p1->draw();
            p2->draw();
            p3->draw();
            p4->draw();
            p5->draw();
           // for (const auto &platform : platforms) {
             //   DrawRectangleLines(platform.x, platform.y, platform.width, platform.height, RED); // Visualize the platform's collision area

            //}
        }
        void drawObjects() override {
            o1->draw();
            c1->draw();
            c2->draw();
            c3->draw();
            c4->draw();
        }

        std::vector<Rectangle> getPlatforms() override { return platforms; }

        void update() override {
            // Update logic specific to LevelTwo
        }
};

#endif // LEVELTWO_H
