#pragma once

#include <set>
#include <vector>
template <typename RobotType>
class Env
{
public:
    Env();
    ~Env();
private:
    size_t block_width;
    size_t block_height;
    size_t scale;
    std::set<int> obs_block;
    std::set<int> rack_block;

    std::vector<RobotType> robots;

    bool remote_attached = false;

public:
    void attachRemote();
};