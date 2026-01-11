/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:08:33 by ajamshid          #+#    #+#             */
/*   Updated: 2025/05/27 16:16:13 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
// int main()
// {
//     std::list<int> mstack;
//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.back() << std::endl;
//     mstack.pop_back();
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     //[...]
//     mstack.push_back(0);
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     return 0;
// }

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

// void printStack(MutantStack<int> &s)
// {
//     std::cout << "Stack contents (from bottom to top): ";
//     for (MutantStack<int>::iterator it = s.begin(); it != s.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }

// int main()
// {
//     std::cout << "===== Basic Stack Test =====" << std::endl;
//     MutantStack<int> stack;

//     stack.push(10);
//     stack.push(20);
//     stack.push(30);
//     printStack(stack);

//     std::cout << "Top: " << stack.top() << std::endl;

//     stack.pop();
//     std::cout << "After one pop:" << std::endl;
//     printStack(stack);

//     std::cout << "Stack size: " << stack.size() << std::endl;

//     std::cout << "\n===== Iterator Modification Test =====" << std::endl;
//     for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
//         *it += 1;
//     printStack(stack);

//     std::cout << "\n===== Const Iterator Test =====" << std::endl;
//     const MutantStack<int> constStack = stack;
//     for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     std::cout << "\n===== Copy Constructor Test =====" << std::endl;
//     MutantStack<int> copiedStack(stack);
//     printStack(copiedStack);

//     std::cout << "\n===== Assignment Operator Test =====" << std::endl;
//     MutantStack<int> assignedStack;
//     assignedStack = stack;
//     printStack(assignedStack);

//     return 0;
// }

