#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int countOperation;
    cin >> countOperation;

    vector<bool> queue;
    for (int i = 0; i < countOperation; ++i)
    {
         string operation;
         cin >> operation;

        if (operation == "WORRY")
        {
            int index;
            cin >> index;
            queue[index] = true;
        }
        else if (operation == "QUIET")
        {
            int index;
            cin >> index;
            queue[index] = false;
        }
        else if (operation == "COME")
        {
            int k;
            cin >> k;
            if (k > 0)
            {
                queue.resize(queue.size() + k, false);
            }
            else
            {
                queue.resize(queue.size() + k);
            }
        }
        else if (operation == "WORRY_COUNT")
        {
            int count = 0;
            for (int j = 0; j < queue.size(); ++j)
            {
              if (queue[j])
              {
                  ++count;
              }
            }
            cout << count << endl;
        }
    }

   return 0;
}
