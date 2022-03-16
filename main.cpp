#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int sequenceLength, item;
    stack<int> stack;

    cout << "First give us the length of a sequence (<=100): ";
    cin >> sequenceLength;

    while (sequenceLength > 100)
    {
        cout << "Please enter valid length (<=100): " << endl;
        cin >> sequenceLength;
    }
    cout << "You have entered: " << sequenceLength << endl;

    for (int i = 1; i <= sequenceLength; i++)
    {
        cout << i << ": ";
        cin >> item;
        stack.push(item);
        cout << "Your sequence: " << stack.top() << endl;
    }
}