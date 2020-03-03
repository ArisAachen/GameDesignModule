//
//  Component.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/18.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef Component_h
#define Component_h

using interface = struct;

//游戏实体
class Unity
{
public:
    Unity() {}
    virtual~Unity(){}
    
    void updte(World& world,Graphics& graphics)
    {
        input_->update(*this);
        physics_->update(*this,world);
        graphics_->update(*this,graphics);
    }
    
public:
    int velocity_;
    
private:
    InputComponent input_;
    GraphicsComponent graphics_;
    PhysicsCompoent physics_;
}

class Graphics
{
public:
    Graphics(){}
    virtual~Graphics(){}
}

class World
{
public:
    World(){}
    virtual~World(){}
}


//输入组件
interface InputComponent
{
    virtual void update(Unity& unity) = NULL;
}

//渲染组件
interface GraphicsComponent
{
    virtual void update(Unity& unity,Graphics& graphics) = NULL;
}

class ColorGraphicsComponent:public GraphicsComponent
{
public:
    ColorGraphicsComponent(){}
    virtual~ColorGraphicsCompoenent(){}
    
    virtual void update(Unity& unity,Graphics& graphics)
    {
        Sprite* sprite = spriteStand_;
        if(unity->velocity < 0)
        {
            sprite = spriteLeft_;
        }
        else if(unity->velocity > 0)
        {
            sprite = spriteRight_;
        }
        
        graphics->draw(sprite);
    }
    
    
private:
    Sprite spriteStand_;
    Sprite spriteWalkLeft_;
    Sprite spriteWalkRight_;
}

//物理组件
interface PhysicsCompoent
{
    virtual void update(Unity& unity,World& world) = NULL:
}

    
    
//玩家输入组件
class PlayerInputComponent:public InputComponent
{
public:
    PlayerinputComponent(){}
    virtual~PlayerInputComponent(){}
    
    
    virtual void update(Unity& unity)
    {
        unity->velocity += WALK_ACCELERATION;
    }
    
private:
    static const int WALK_ACCELERATION = 1;
}





#endif /* Component_h */
