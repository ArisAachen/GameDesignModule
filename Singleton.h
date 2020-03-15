//
//  Singleton.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/16.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h

//全局变量不好
//代码晦涩难懂，寻找全局变量
//促进耦合
//并发支持不友好

//c++11 静态成员变量只初始化一次
//单例继承

enum class PlaformType
{
    None,
    PS3,
    WiFi
}

class FileSystem;

class PS3FileSystem:public FileSystem
{
public:
    virtual char* read(char* path)
    {
        //read file
    }
    
    virtual void write(char* path,char* text)
    {
        //write something
    }
}

class WiFiFileSystem:public FileSystem
{
public:
    virtual char* read(char* path)
    {
        //read file
    }
    
    virtual void write(char* path,char* text)
    {
        //write something
    }
}

#define PlatformId PlatformType::PS3

class FileSystem
{
public:
    static FileSystem& instance()
    {
#if PlatformId == Plarform::PS3
        static FileSystem* instance = new PS3FileSystem();
#else if PlatformId == Platform::WiFi
        static FileSystem* instance = new WiFiFileSystem();
#endif
        return *instance;
    }
    
    virtual~FileSystem();
    
    virtual char* read(char* path) = NULL:
    
    virtual void write(char* path,char* text) = NULL;
    
    //函数定义
protected:
    FileSystem(){}
}

//确保一个实例
class SingleOnly
{
public:
    SingleOnly()
    {
        assert(!instantiated_);
        instantiated_ = true;
    }
    
    virtual~SingleOnly()
    {
        instantiated_ = false;
    }
    
private:
    static bool instantiated_;
}


//单例替代
//对象当成参数传递

//基类继承
class Log
{
public:
    Log(){}
    virtual~Log(){}
    
    virtual void write(char* text)
    {
        //write something
    }
}


class Gameobject
{
protected:
    Log& getLog()
    {
        return log_;
    }
    
private:
    static Log& log_;
}

class Enemy:public Gameobject
{
public:
    void doSomething()
    {
        getLog().write(...);
    }
}

//统一全局对象访问
class Game
{
public:
    static Game& instance()
    
    Log& getLog() {return *log_;}
    FileSystem& getFileSystem() {return *files_;}
    
private:
    static Game instance_;
    Log* log_;
    FileSystem* files_;
}

//服务定位器访问

#endif /* Singleton_h */
