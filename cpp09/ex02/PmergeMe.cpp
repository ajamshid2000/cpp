/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamshid <ajamshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:43:54 by ajamshid          #+#    #+#             */
/*   Updated: 2025/06/03 12:17:48 by ajamshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "list"
#include "sstream"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

int is_all_digits(std::string str)
{
    for (std::string::iterator begin = str.begin(); begin != str.end(); begin++)
    {

        if (!std::isdigit(*begin))
        {
            return 0;
        }
    }
    return 1;
}

int toInt(const std::string &str)
{
    std::istringstream iss(str);
    int result;
    iss >> result;
    if (iss.fail() || !iss.eof() || result < 0)
        throw std::runtime_error("Error");
    return result;
}

std::vector<size_t> j_vec(size_t n)
{
    std::vector<size_t> indices;
    size_t j0 = 0, j1 = 1, j = 0;
    indices.push_back(0);
    while ((j = j1 + 2 * j0) < n)
    {
        indices.push_back(j);
        j0 = j1;
        j1 = j;
    }

    for (size_t i = 0; i < n; ++i)
        if (std::find(indices.begin(), indices.end(), i) == indices.end())
            indices.push_back(i);
    return indices;
}

std::deque<size_t> j_deq(size_t n)
{
    std::deque<size_t> indices;
    size_t j0 = 0, j1 = 1, j = 0;
    indices.push_back(0);
    while ((j = j1 + 2 * j0) < n)
    {
        indices.push_back(j);
        j0 = j1;
        j1 = j;
    }
    for (size_t i = 0; i < n; ++i)
        if (std::find(indices.begin(), indices.end(), i) == indices.end())
            indices.push_back(i);
    return indices;
}

void PmergeMe::sort(int argc, char **argv)
{
    std::vector<int> original;
    std::vector<int> vec;
    std::deque<int> deq;
    for (int j = 1; j < argc; j++)
    {
        int temp = toInt(argv[j]);
        if (std::find(vec.begin(), vec.end(), temp) != vec.end())
            throw std::runtime_error("Error: duplicates found in input.");
        vec.push_back(temp);
        deq.push_back(temp);
        original.push_back(temp);
    }

    clock_t start_vec = clock();
    vec = sort_vector(vec);
    clock_t end_vec = clock();

    clock_t start_deq = clock();
    deq = sort_deque(deq);
    clock_t end_deq = clock();

    std::cout << "before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << original[i] << " ";
    std::cout << std::endl
              << "after: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << original.size() << " elements with std::vector : " << end_vec - start_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << original.size() << " elements with std::deque : " << end_deq - start_deq << " us" << std::endl;
}

std::vector<int> PmergeMe::sort_vector(std::vector<int> &vec)
{
    (void)vec;
    std::vector<int> main;
    std::vector<int> aux;
    size_t i;
    i = 0;
    if (vec.size() == 1)
        return vec;

    while (vec.size())
    {
        int pair_one = vec.back();
        vec.pop_back();
        if (!vec.size())
        {
            aux.push_back(pair_one);
            break;
        }
        int pair_two = vec.back();
        vec.pop_back();
        if (pair_one > pair_two)
        {
            main.push_back(pair_one);
            aux.push_back(pair_two);
        }
        else
        {
            aux.push_back(pair_one);
            main.push_back(pair_two);
        }
    }
    if (main.size() == 1)
    {
        i = 0;
        std::vector<size_t> a = j_vec(aux.size());
        size_t j;
        while (i < aux.size())
        {
            j = a[i];
            std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), aux[j]);
            main.insert(it, aux[j]);
            i++;
        }
        return main;
    }
    else
        main = sort_vector(main);

    i = 0;
    std::vector<size_t> a = j_vec(aux.size());
    size_t j;
    while (i < aux.size())
    {
        j = a[i];
        std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), aux[j]);
        main.insert(it, aux[j]);
        i++;
    }
    return main;
    // while (aux.size())
    // {
    //     std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), aux.back());
    //     main.insert(it, aux.back());
    //     aux.pop_back();
    // }
    // return main;
}

std::deque<int> PmergeMe::sort_deque(std::deque<int> &deq)
{
    (void)deq;
    std::deque<int> main;
    std::deque<int> aux;
    size_t i;
    i = 0;
    if (deq.size() == 1)
        return deq;

    while (deq.size())
    {
        int pair_one = deq.back();
        deq.pop_back();
        if (!deq.size())
        {
            aux.push_back(pair_one);
            break;
        }
        int pair_two = deq.back();
        deq.pop_back();
        main.push_back(std::max(pair_one, pair_two));
        aux.push_back(std::min(pair_one, pair_two));
    }
    if (main.size() == 1)
    {
        i = 0;
        std::deque<size_t> a = j_deq(aux.size());
        size_t j;
        while (i < aux.size())
        {
            j = a[i];
            std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), aux[j]);
            main.insert(it, aux[j]);
            i++;
        }
        return main;
    }
    else
        main = sort_deque(main);
    i = 0;
    std::deque<size_t> a = j_deq(aux.size());
    size_t j;
    while (i < aux.size())
    {
        j = a[i];
        std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), aux[j]);
        main.insert(it, aux[j]);
        i++;
    }
    return main;
}
