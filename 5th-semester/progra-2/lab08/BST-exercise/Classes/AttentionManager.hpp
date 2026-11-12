//
// Created by zincronit on 11/11/26.
//

#ifndef BST_EXERCISE_ATTENTIONMANAGER_HPP
#define BST_EXERCISE_ATTENTIONMANAGER_HPP

#include "SearchBinaryTree.hpp"
#include "Emergency.hpp"
#include "Urgency.hpp"
#include "NonUrgency.hpp"
class AttentionManager
{
public:
    ~AttentionManager() = default;
    void load_attentions(const std::string& );
    void print_attentions(const std::string& ) const;
    void print_emergency(std::ofstream& ) const;
    void print_urgency(std::ofstream& ) const;
    void print_non_urgency(std::ofstream& ) const;

private:
    class SearchBinaryTree tree;
};


#endif //BST_EXERCISE_ATTENTIONMANAGER_HPP
