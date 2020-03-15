//
//  DataLocality.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/18.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef DataLocality_h
#define DataLocality_h

//内存缓存未命中
//数组连续空间，指针非连续

//保持缓存数据盈满，移动内存开销小

//Pitfalls of Object-Oriented Programming

//热/冷分解
class AIComponent
{
public:
    AIComponent(){}
    virtual~AIComponent(){}
    
    virtual void update(){}
    
private:
    Vecotr goalPos_; //每帧更新   存实例对象
    LootDrop* loot_; //死亡掉落   存指针
}


//实体组件放到统一的数组

class Entity
{
public:
    AIComponent* ai() {return ai_;}
    PhysicsComponent* physics() {return physics_;}
    RenderComponent render() {return reder_;}
    
private:
    AIComponent* ai_;
    PhysicsComponent* physics_;
    RenderComponent* render_;
}


int main()
{
    static const int MAX_ENTITIES = 16;
    AIComponent* aiComponents = new AIComponent[MAX_ENTITIES];
    PhysicsComponent* physicsComponents = new PhysicsComponent[MAX_ENTITIES];
    RenderComponent** renderComponents = new RenderComponent[MAX_ENTITIES];
    
    while(true)
    {
        for(int i=0;i<numEntities;i++)
        {
            aiComponents[i]->update();
        }
    }
}


//


#endif /* DataLocality_h */
