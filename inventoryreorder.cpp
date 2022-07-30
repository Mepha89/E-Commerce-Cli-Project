#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
 

//Priority Queue in min heap mode
struct PriorityQueue
{
private:
    // vector  which stores heap elements
    vector<int> V;
 
    // return parent 
    int parentNode(int i) 
    {
        return (i - 1) / 2;
    }
 
    // return left child
    int LEFT(int i) 
    {
        return (2*i + 1);
    }
 
    // return right child
    int RIGHT(int i) 
    {
        return (2*i + 2);
    }
 

    //Goes down the heap
    void DownHeap(int i)
    {
        // obtain the left and right child of the given node
        int left = LEFT(i);
        int right = RIGHT(i);
 
        int smallest = i;

        //compares it with the left and right child to find the smallest value
        if (left < size() && V[left] < V[i]) {
            smallest = left;
        }
 
        if (right < size() && V[right] < V[smallest]) {
            smallest = right;
        }
 
        //change with a child that has lower priority & call DownHeap on it (recursion)
        if (smallest != i)
        {
            swap(V[i], V[smallest]);
            DownHeap(smallest);
        }
    }
 
    // Go up the Heap
    void UpHeap(int i)
    {
        //check to see if the heap property was "violated". if so, swap the child and parent node
        if (i && V[parentNode(i)] > V[i])
        {
            // the swap of parent and child
            swap(V[i], V[parentNode(i)]);
 
            // recursion of UpHeap
            UpHeap(parentNode(i));
        }
    }
 
public:
    // return the size of heap
    unsigned int size() {
        return V.size();
    }
    //check to see if heap is empty
    bool empty() {
        return size() == 0;
    }
 
    //put a key into the heap
    void push(int key)
    {
        // put another element at the end of vector
        V.push_back(key);
 
        //obtain the index and use UpHeap
        int index = size() - 1;
        UpHeap(index);
    }
 
    //Pop is a function that takes away the item with the lowest priority
    void pop()
    {
        try {
            //check if there are no items
            if (size() == 0)
            {
                throw out_of_range("There are no items");
            }
 
            //the last element replaces the root
            V[0] = V.back();
            V.pop_back();
 
            //use DownHeap on root node
            DownHeap(0);
        }
        //find the exception and output it
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
 

    void firstFive(PriorityQueue q)
    {

        try {
            //check if there are no items
            if (size() <=4)
            {
                throw out_of_range("There are no items");
            }
 
            // otherwise, print first 5 elements
            int temp1 = q.top();
            cout<<temp1<<", ";
            q.pop();
            int temp2 = q.top();
            cout<<temp2<<", ";
            q.pop();
            int temp3 = q.top();
            cout<<temp3<<", ";
            q.pop();
            int temp4 = q.top();
            cout<<temp4<<", ";
            q.pop();
            int temp5 = q.top();
            cout<<temp5<<"\n";
            q.pop();

            q.push(temp1);
            q.push(temp2);
            q.push(temp3);
            q.push(temp4);
            q.push(temp5);
            
            
            //cout<<V[0]<<", "<<V[1]<<", "<<V[2]<<", "<<V[3]<<", "<<V[4];       
        }
        // find and print the exception
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }

    int top()
    {
        try {
            //check if there are no items
            if (size() == 0)
            {
                throw out_of_range("There are no items");
            }
 
            //if there are items return the first one
            return V[0];        
        }
        // find and output the exception
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }


void Reorder20(PriorityQueue &q)
    {

        try {
            // check for items
            if (size() <=4)
            {
                throw out_of_range("There are no items");
            }
 
            // otherwise, add 20 to the quantity of the first 5 items in the priority list
            int temp1 = q.top();
            cout<<temp1<<", ";
            q.pop();
            int temp2 = q.top();
            cout<<temp2<<", ";
            q.pop();
            int temp3 = q.top();
            cout<<temp3<<", ";
            q.pop();
            int temp4 = q.top();
            cout<<temp4<<", ";
            q.pop();
            int temp5 = q.top();
            cout<<temp5<<"\n";
            q.pop();

            q.push(temp1 + 20);
            q.push(temp2 + 20);
            q.push(temp3 + 20);
            q.push(temp4 + 20);
            q.push(temp5 + 20);
            
            
            //cout<<V[0]<<", "<<V[1]<<", "<<V[2]<<", "<<V[3]<<", "<<V[4];       
        }
        // find and print the exception
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }





};
 
// Min Heap implementation in C++
int main()
{
    PriorityQueue pq;
 
    // Note: The element's value decides priority
 
    pq.push(45);
    pq.push(2);
    pq.push(35);
    pq.push(72);
    pq.push(54);
    pq.push(1);
 
    cout << "Size is " << pq.size() << endl;
 
    
    pq.Reorder20(pq); 
    pq.firstFive(pq);

 
 /*
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << endl << boolalpha << pq.empty();
 
    pq.top();    // top operation on an empty heap
    pq.pop();    // pop operation on an empty heap
    */
 
    return 0;
}
