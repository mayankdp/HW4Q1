#include <iostream>
#include <stack>
using namespace std;

// Display the stack from bottom to first
void DisplayStack(stack<int> s)
{
    if (s.empty())
        return;

    int x = s.top();
    s.pop();
    DisplayStack(s);
    cout << x << " ";
    s.push(x);
}

// Reversing the stack elements from the first on left
void ReverseStack(stack<int> s, int number)
{
    stack<int> temp;
    int num;

    for (int i = 0; i < number; i++)
    {
        num = s.top();
        s.pop();
        temp.push(num);
    }
    DisplayStack(temp);
}

int main()
{
    int sequenceLength, item, reversalNum;
    stack<int> stack;
    bool Nseq = true;
    bool Mseq = true;

    // This loop is for user to choose to do all the below steps again
    while (Nseq)
    {
        Mseq = true;
        cout << "First give us the length of a sequence N (<=100): ";
        cin >> sequenceLength;

        // Entering valid N's length
        while (sequenceLength > 100)
        {
            cout << "Please enter valid length for N (<=100): " << endl;
            cin >> sequenceLength;
        }
        cout << "You have entered: " << sequenceLength << endl;

        // User input sequence numbers of N times
        for (int i = 1; i <= sequenceLength; i++)
        {
            cout << i << ": ";
            cin >> item;
            stack.push(item);
        }

        // Calling DisplayStack to show User's N sequence stack
        cout << "Your N sequence is: ";
        DisplayStack(stack);
        cout << "\n";

        // This loop is for user to start from here
        while (Mseq)
        {
            cout << "Please input M reversal number <= " << stack.size() << ": ";
            cin >> reversalNum;

            // This loop checks whether user entered valid M number. if not then ask againg.
            while (reversalNum > stack.size())
            {
                cout << "Please enter valid M reversal number: ";
                cin >> reversalNum;
            }

            // Displaying the reverse M numbers of stack
            cout << "Reversed first M numbers from the Stack: ";
            ReverseStack(stack, reversalNum);
            cout << "\n";

            // Remove M numbers from the stack
            for (int i = 0; i < reversalNum; i++)
                stack.pop();

            // Displaying remaining elements for stack
            if (stack.size() != 0)
            {
                cout << "Your final N Stack: ";
                DisplayStack(stack);
            }
            else
                cout << "Your final N Stack: EMPTY STACK";
            cout << "\n";

            // Repeating above steps from the start of from the reverse
            int x;
            cout << "Repeat above steps: \n 1. Start from the beginning \n 2. Reverse remaining sequence \n 3. End now \n Enter your choice:";
            cin >> x;
            if (x == 1)
            {
                Nseq = true;
                Mseq = false;
                while (stack.size() > 0)
                    stack.pop();
            }
            else if (x == 2)
            {
                Mseq = true;
            }
            else
            {
                Nseq = false;
                Mseq = false;
            }
        }
    }
}