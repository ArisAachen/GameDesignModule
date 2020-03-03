//
//  Prototype.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/16.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef Prototype_h
#define Prototype_h

//头等公民类型 first-class types

using interface = struct;

//怪物接口
interface Monster
{
    virtual~Monster(){}
    virtual Monster* clone() = NULL;
}

//妖怪类
class Ghost:public Monster
{
    //函数定义
public:
    Ghost(){}
    Ghost(int nHealth,int nSpeed):nHealth_(nHealth),nSpeed_(nSpeed){}
    virtual~Ghost(){}
    
    virtual Monster* clone()
    {
        return new Ghost(nHealth_,nSpeed_);
    }
    
private:
    int nHealth_;
    int nSpeed_;
}

//怪物生成器
class Spawner
{
public:
    Spawner()=delete;
    Spawner(Monster* prototype):prototype_(prototype){}
    
    Monster* spawnMonster()
    {
        return prototype_->clone();
    }
    
private:
    Monster* prototype_;
}



#endif /* Prototype_h */
