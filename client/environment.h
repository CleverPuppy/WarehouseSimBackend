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

    std::set<int> obs_block_s;
    std::set<int> rack_block_s;

    std::vector<RobotType> robots;
};