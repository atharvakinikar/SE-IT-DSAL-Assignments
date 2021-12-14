#include "implementation.h"

int main()
{
    ThreadedBinaryTree ob;
    int v, ch;
    cout << "***Threaded Binary Tree***\n";
    cout << "\nCreating Tree\n";
    ob.create();
    do
    {
        cout << "\nTBT operations\n";
        cout << "1.Insert \n2.Preorder traversal\n3.Inorder traversal\n4.Exit" << endl;
        cout << "Enter Your Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter data you want to insert: " << endl;
            cin >> v;
            ob.insert(v);
            break;
        case 2:
            cout << "\nPreorder traversal is: ";
            ob.preorder();
            break;
        case 3:
            cout << "\nInorder traversal is: ";
            ob.inorder();
            break;
        case 4:
            cout << "===Thank you for using TBT===\n";
            cout << "---------Program Terminated---------";
            exit(0);
        default:
            cout << "\nInvalid Input\n";
        }
    } while (ch != 0);
    return 0;
}