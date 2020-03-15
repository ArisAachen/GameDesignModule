//
//  DirtyBit.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/18.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef DirtyBit_h
#define DirtyBit_h

#define MAX_CHILDREN

//转化函数
class Transform
{
public:
    static Transform origin()
    {
        //原生转化
    }
    
    
    Transform combine(Transform& other)
    {
        //父物件组合
    }
}

//节点
class GraphNode
{
public:
    GraphNode(Mesh* mesh)
    :mesh_(mesh),dirty_(true),local_(Transform::origin()){}
    
    void setTransform(Transform local)
    {
        local_ = local;
        dirty_ = true;
    }
    
    void render(Transform parentWorld,bool dirty)
    {
        dirty |= dirty_;
        if(dirty)
        {
            world_ = local_.combine(parentWorld);
            dirty_ = false;
        }
        
        if(mesh_) renderMesh(mesh_,world_);
        
        for(int i = 0;i<numChildren_,i++)
        {
            children[i]->render(world_,dirty);
        }
    }
    
private:
    Mesh* mesh_;
    Transform local_;
    Transform world_;
    bool dirty_;
    GraphNode* children_[MAX_CHILDREN];
}



#endif /* DirtyBit_h */
