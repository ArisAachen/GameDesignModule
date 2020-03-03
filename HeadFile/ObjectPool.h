//
//  ObjectPool.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/19.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef ObjectPool_h
#define ObjectPool_h


class Particle
{
public:
    Particle(){}
    virtual~Particle(){}
    
    bool inUse()const {return framesLeft_ > 0;}
    
    void setNext(Praticle* next)
    {
        state_.next = next;
    }
    
    Particle* getNext()const {return state_.next;}
    
    void init(double x,double y,double xVel,double yVel,int framesLeft)
    {
        if(!inUse()) return;
        
        x_ = x;
        y_ = t;
        xVel_ = xVel;
        yVel_ = yVel;
        framesLeft_ = framesLeft;
    }
    
    bool animate()
    {
        if(!inUse()) return;
        framesLeft_ --;
        x_ += xVel;
        y_ += yVel;
        
        return framesLeft_ == 0;
    }
    
private:
    int framesLeft_;
    
    union
    {
        struct
        {
            double x,y,xVel,yVel;
        }live;
        
        Particle* next_;
    }state_;
    
}



class ParticlePool
{
public:
    ParticlePool()
    {
        firstAvailable_ = particles_[0];
        
        for(int i = 0;i < POOL_SIZE;i++)
        {
            particles_[i]->setNext(particles_[i+1]);
        }
        
        
        particles_[POOL_SIZE - 1].setNext(nullptr);
    }
    virtual~ParticlePool(){}
    
    void create(double x,double y,double xVel,double yVel,int framesLeft)
    {
        assert(firstAvailable != nullptr);
        
        Particle* newParticle = firstAvailable_;
        
        firstAvailable_ = newParticle->getNext();
        
        newParticle->init(x,y,Xvel,yVel,framesLeft);
    }
    
    void animate()
    {
        for(int i = 0;i<POOL_SIZE;i++)
        {
            if(particles_[i].animate())
            {
                particles_[i].setNext(firstAvailable_);
                firstAvailable_ = &particle[i];
            }
        }
    }
    
    
private:
    Particle* firstAvailable_;
    static const int POOL_SIZE = 100;
    Praticle particles_[POOL_SIZE];
}




#endif /* ObjectPool_h */
