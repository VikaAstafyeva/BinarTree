#include <iostream>
#define N 15
class Node;
int CountBranches(Node*, int);

class Node
{
    char str[N];
    Node* left, * right;

public:
    Node(char* STR)
    {
        int i;
        for (i = 0; i < N; i++)
            str[i] = STR[i];
        left = right = NULL;
    }

    void Add(char* STR)
    {
        int i;
        for (i = 0; i < N; i++)
            if (str[i] != STR[i])
            {
                if (str[i] < STR[i])
                {
                    if (right != NULL)
                        right->Add(STR);
                    else
                        right = new Node(STR);
                }
                else
                {
                    if (left != NULL)
                        left->Add(STR);
                    else
                        left = new Node(STR);
                }
                return;
            }
    }

    void Show()
    {
        std::cout << str << ' ';
        if (left != NULL)
            left->Show();
        if (right != NULL)
            right->Show();
    }

    void BranchCount(int currentLvl, int& counter, int& request)
    {
        if (++currentLvl == request)
            counter++;
        if (left != NULL)
            left->BranchCount(currentLvl, counter, request);
        if (right != NULL)
            right->BranchCount(currentLvl, counter, request);
    }
};

int CountBranches(Node* Root, int lvl)
{
    int i = 0;
    Root->BranchCount(-1, i, lvl);
    return i;
}
int main()
{
    Node* Root = NULL;
    char option, inputStr[N];
    int lvl;

    do
    {
        system("cls");
        std::cout << "1 - Add\n2 - Show\n3 - Count branches of level\n4 - Exit\nMy choice: ";

        std::cin >> option;
        switch (option)
        {
        case '1':
        {
            std::cout << "Input value: ";
            std::cin >> inputStr;
            if (Root != NULL)
                Root->Add(inputStr);
            else
                Root = new Node(inputStr);
        }break;

        case '2':
        {
            std::cout << "Current tree (straight bypass): ";
            if (Root != NULL)
                Root->Show();
            std::cout << std::endl;
            system("PAUSE");
        }break;

        case '3':
        {
            std::cout << "Input level: ";
            std::cin >> lvl;
            std::cout << "Branches of lvl " << lvl << " is " << CountBranches(Root, lvl) << std::endl;
            system("PAUSE");
        }break;
        }
    }   while (option != '4');
}

