#include<iostream>
#include<vector>
#include<algorithm>

bool SortHelper(std::pair<int*, int> a, std::pair<int*, int> b) { return(*(a.first) < *(b.first)); }

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int*> nodes;
    std::vector<std::pair<int*, int>> to_be_sorted(n);

    for (int i = 0; i < n; i++)
    {
        int* temp = new int;
        std::cin >> *temp;
        nodes.push_back(temp);
        to_be_sorted[i].first = temp;
        to_be_sorted[i].second = i;
    }

    std::sort(to_be_sorted.begin(), to_be_sorted.end(), SortHelper);

    int index_delete = to_be_sorted[to_be_sorted.size() - k].second;

    if (2 * index_delete + 1 > n - 1)
    {
        nodes.erase(nodes.begin() + index_delete);
    }
    else if (2 * index_delete + 1 == n - 1)
    {
        nodes[index_delete] = nodes[nodes.size() - 1];
        nodes.pop_back();
    }
    else if (2 * index_delete + 2 <= n - 1)
    {
        int most_left_index = index_delete * 2 + 2;
        while (most_left_index * 2 + 1 <= n - 1)
            most_left_index = most_left_index * 2 + 1;

        nodes[index_delete] = nodes[most_left_index];
        nodes.erase(nodes.begin() + most_left_index);
    }


    for (int i = 0; i < nodes.size(); i++)
        std::cout << *nodes[i] << " ";


    return 0;
}
