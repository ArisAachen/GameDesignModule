//
//  TypeObject.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/17.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef TypeObject_h
#define TypeObject_h


//类型对象
class Breed
{
public:
    Breed(Breed* parent,int health,const char* attack)
    :health_(health),attack_(attack)
    {
        if(parent != nullptr) health_ = parent->getHealth();
        
        if(parent != nullptr) memcpy(...);
    }
    
    Breed(int health,const char* attack):health_(health),attack_(attack){}
    virtual~Breed(){}
    
    virtual const char* getAttack(){return attack_;}
    
    virtual int getHealth() {return health_;}
    
    Monster* createMonster()
    {
        return new Monster(*this);
    }
    
private:
    int health_;
    const char* attack_;
}

//持有者
class Monster
{
    friend class Breed;
    
public:
    virtual~Monster();
    
    virtual const char* getAttack()
    {
        return breed_->getAttack();
    }
    
    virtual int getHealth()
    {
        return breed_->getHealth();
    }
    
private:
    Monster(Breed & breed):breed_(breed){}
    
    
private:
    Breed breed_;
    
}



#endif /* TypeObject_h */
