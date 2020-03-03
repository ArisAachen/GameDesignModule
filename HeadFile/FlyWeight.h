//
//  FlyWeight.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/15.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef FlyWeight_h
#define FlyWeight_h

//享元模式

//纹理类
class Texture
{
public:
    Texture();
    virtual ~Texture();
}

//地形类
class Terrain
{
    //函数定义
public:
    Terrain() = delete;
    Terrain(int moveCost,bool isWater,Texture textture):moveCost_(moveCost),
    isWater_(isWater),texture_(texture)
    
    virtual ~Terrain();
    
public:
    int getMovecost() const {return moveCost_;}
    bool isWater() const {return isWater_;}
    const Texture& getTexture() const {return texure_;}
    
private:
    int moveCost_;
    bool isWater_;
    Texture texture_;
}

//地图类
class World
{
    //函数定义
public:
    World();
    virtual ~World();
    
public:
    void generateWorld()
    {
        for(int nWidth=0;nWidth<WIDTH;nWidth++)
        {
            for(int nHeight=0;nHeight<HEIGHT;nHeight++)
            {
                tiles_[nWidth][nHeight]= &grassTerrain_;
            }
        }
    }
    
    
#define Width 10
#define HEIGHT 20
private:
    Terrain tiles_[WIDTH][HEIGHT];
    
    //享元
private:
    Terrain grassTerrain_;
    Terrain hillTerrain_;
    Terrain riverTerrain_;
}



#endif /* FlyWeight_h */
