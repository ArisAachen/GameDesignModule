//
//  Observer.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/16.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

#include <vector>

//数据流编程   函数响应式编程

//游戏实体
class Unity
{
public:
    Unity(){}
    virtual ~Unity(){}
    
    virtual bool isHero(){return isHero_;}
    
private:
    bool isHero_;
}

//通知枚举
enum class Event
{
    VK_UP,
    VK_DOWN
}


using interface = struct;

//观察者接口
interface Observer
{
public:
    virtual void onNotify(Unity& unity,Event event) = NULL;
}

class Achievements:public Observer
{
    //函数定义
public:
    Achievements(){}
    virtual~Achievements(){}
    
    //发送消息
    virtual void onNotify(Unity& unity,Event event)
    {
        switch (event) {
            case Event::VK_UP:
                if(unity.isHero())
                {
                    //时间通知
                }
                
                break;
                
            default:
                break;
        }
    }
    
}


//被观察者
class Subject
{
    //函数定义
public:
    Subject(){}
    virtual~Subject(){}
    
    //方法定义
protected:
    //新增观察者
    virtual void addObserver(Observer && observer)
    {
        //查重判断
        
        //右值引用
        observers_.emplace_back(std::move(observer));
    }
    
    //移除观察者
    virtual void removeObserver(Observer & observer)
    {
        //存在判断
        
        //删除对象
    }
    
    //发送通知
    virtual void botify(Unity& unity,Event event)
    {
        for(Observer observer:observers_)
        {
            observer.onNotify(unity,event);
        }
    }
    
private:
    std::vector<Observer> observers_; //存指针更好
}

//用链表实现，内存分配问题

#endif /* Observer_h */
