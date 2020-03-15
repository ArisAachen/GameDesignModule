//
//  CommandModule.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/15.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef CommandModule_h
#define CommandModule_h

//接口定义
using interface = struct;


interface Untiy
{
    virtual void jummp() = NULL;
}

//玩家类
class CGameActor:public Unity
{
    //函数定义
public:
    CGameActor() {}
    virtual ~CGameActor(){}
    
    //运动实现
    virtual void jummp()
    {
        //方法实现
    }
}


//命令接口
interface Command
{
    //操作执行
    virtual void execute() = NULL;
}


class JummpCommand:public Command
{
    //函数定义
public:
    JummpCommand() = delete;
    JummpCommand(Unity* unity):unity_(unity){}
    virtual ~JummpCommand(){}
    
    //虚方法实现
    virtual void execute()
    {
        actor.jummp();
    }
    
    
    Unity* unity_{nullptr};
}






#endif /* CommandModule_h */
