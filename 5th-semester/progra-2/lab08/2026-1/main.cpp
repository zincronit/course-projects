//
// Created by zincronit on 11/11/26.
//

#include "Classes/AttentionManager.hpp"
#include "Utilities/Utils.hpp"
int main()
{
    AttentionManager manager;
    manager.load_attentions("../Files/Data/attentions.csv");
    manager.print_attentions("../Files/Data/report.txt");

    return 0;
}