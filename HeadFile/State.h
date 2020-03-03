//
//  State.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/16.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef State_h
#define State_h

using interface = struct;

//行为树和规划系统


//输入
enum class Input
{
    VK_NONE,
    VK_UP,
    VK_DOWN
}

enum class MoveType
{
    None,
    Ducking,
    Jummping
}

//英雄实体
class Heroine
{
    //函数定义
public:
    Heroine(){}
    virtual~Heroine(){}
    
    virtual void handleInput(Input input)
    {
        HeroineState* state = state_->handleInput(*this,input);
        if(state_)
        {
            delete state_;
            state_ = state;
            state_->entry(*this);
        }
    }
    
    virtual void setGraph(MoveType movetype)
    {
        //设置移动图片
    }
    
    virtual void update()
    {
        state_->update(*this);
    }
    
private:
    HeroineState* state_;
}

//状态
interface HeroineState
{
    virtual void entry(Heroine& heroine) = NULL;
    
    virtual HeroineState* handleInput(Heroine& heroine，Input input) = NULL;
    
    virtual void update(Heroine& heroine）= NULL;
}

 class DuckingState:public HeroineState
{
public:
    Duckingstate(){}
    virtual~DuckingState(){}
    
    virtual void entry(Heroine& heroine)
    {
        //状态参数
        heroine->setGraph(MoveType::Ducking);
    }
    
    virtual HeroineState* handleInput(Heroine& heroine,Input input)
    {
        if(input == Input::VK_UP)
        {
            return new DuckingState();
        }
    }
    
    virtual void update(Heroine& heroine)
    {
        
    }
    
}
    
//并发状态机
class HeroineWithEquipment
{
public:
    HeroineWithEquipment(){}
    virtual~HeroineEquipmeny(){}
    
private:
    HeroineState* state_;
    HeroineState* equipment_;
}
    
//层次状态机
class JummpState:public HeroineState
{
public:
    JummpState(){}
    virtual~JummpState(){}
    
    virtual void entry(Heroine& heroine)
    {
        //状态参数
        heroine->setGraph(MoveType::Jummp);
    }
    
    virtual HeroineState* handleInput(Heroine& heroine,Input input)
    {
        if(input == Input::VK_UP)
        {
            return new DuckingState();
        }
        else
        {
            return new HeroineState();
        }
    }
    
    virtual void update(Heroine& heroine)
    {
        
    }
}

//下推状态机
//用栈存状态，结束弹出当前个，返回上一个状态
    
    
#endif /* State_h */
