//
//  SpacePartitioning.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/19.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef SpacePartitioning_h
#define SpacePartitioning_h

//二叉空间分割BSP k-d树  四叉树
//层次包围盒

class Unit
{
    friend class Grid;
    
public:
    Unit(Grid* grid,double x,double y)
    :grid_(grid),x_(x),y_(y){},pre_(nullptr),next_(next)
    {
        grid_->add(*this);
    }
    
    void move(double x,double y)
    {
        grid_->move(this,x,y);
    }
    
    
private:
    double x_,y_;
    Grid* grid_;
    
    Unit* pre;
    Unit* next_;
}


class Grid
{
public:
    Grid()
    {
        for(int i = 0;i<NUM_CELLS;i++)
        {
            for(int j = 0;j<CELL_SIZE;j++)
            {
                cells_[i][j] = nullptr;
            }
        }
    }
    
    void add(Unit* unit)
    {
        int cellX = (int)(unit->x_ /Grid::NUM_CELL);
        int cellY = (int)(unit->y_ /Grid::CELL_SIZE);
        
        unit->pre_ = nullptr;
        unit->next_ = cells_[cellX][cellY];
        cells_[cellX][cellY] = unit;
        
        if(unit->next_ != nullptr)
        {
            unit->next->pre = unit;
        }
    }
    
    void move(Unit* unit,double x,double y)
    {
        int oldCellX = (int)(unit->x_ /Grid::NUM_CELL);
        int oldCellY = (int)(unit->y_ /Grid::CELL_SIZE);
        
        int cellX = (int)(unit->x_ /Grid::NUM_CELL);
        int cellY = (int)(unit->y_ /Grid::CELL_SIZE);
        
        unit->x_ = x;
        unit->y_ = y;
        
        if(oldCellX == cellX && oldCellY == cellY)
            return;
        
        if(unit->pre != nullptr)
            unit->pre_->next_ = unit->next_;
        
        if(unit->next_ != nullptr)
            unit->next_->pre_ = unit->pre_;
        
        if(cells_[oldCellX][oldCellY] == unit)
        {
            cells_[oldCellX][oldCellY] = unit->next_;
        }
        
        add(unit);
    }
    
    void handleMelse()
    {
        for(int i = 0;i<NUM_CELL;i++)
        {
            for(int j = 0;i<CELL_SIZE;j++)
            {
                handleCell(cells_[i][j]);
            }
        }
    }
    
    handleCell(Unit* unit)
    {
        while(unit != nullptr)
        {
            Unit* other = unit->next;
            handleAttack(unit,other);
            
            other = other->next_;
        }
        
        unit = unit->next_;
    }
    
private:
    static const int NUM_CELLS = 10;
    static const int CELL_SIZe = 20;
    
    
    Unit* cells_[NUM_CELLS][CELL_SIZE];
}


#endif /* SpacePartitioning_h */
