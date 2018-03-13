#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int nums[], int &counter, int &counter2, int num);
void selectionSort(int nums[],int& counter, int &counter2, int num);
void insertionSort(int nums[],int& counter, int& counter2, int num);

int main()
{
    srand(time(0));
    int num = 5000;
    int list1[num];
    int list2[num];
    int list3[num];
    int list1ACount = 0, list1CCount = 0;
    int list2ACount = 0, list2CCount = 0;
    int list3ACount = 0, list3CCount = 0;
    for(int i = 0; i < num; i++){
        list1[i] = rand();
        list2[i] = list1[i];
        list3[i] = list1[i];
    }
    bubbleSort(list1,list1ACount,list1CCount,num);
    selectionSort(list2,list2ACount,list2CCount,num);
    insertionSort(list3,list3ACount,list3CCount,num);
    cout << "Number of Comparisons---" << endl;
    cout << "  Bubble Sort: " << list1CCount << endl;
    cout << "  Selection Sort: " << list2CCount << endl;
    cout << "  Insertion Sort: " << list3CCount << endl;
//    cout << "  Insertion Sort: " << endl;
    cout << endl;
    cout << "Number of item assignments---" << endl;
    cout << "  Bubble Sort: " << list1ACount << endl;
    cout << "  Selection Sort: " << list2ACount << endl;
    cout << "  Insertion Sort: " << list3ACount << endl;
////    cout << "  Insertion Sort: " << endl;
//    for(int i = 0; i < num; i++)
//        cout << list1[i] << " " << list3[i] << endl;
}
void bubbleSort(int nums[],int& counter, int& counter2, int num){
    counter = 0;
    counter2 = 0;
    for(int i = 1; i < num; i++){
        for(int k = 0; k < (num - i); k++){
            counter2++;
            if(nums[k] > nums[k+1]){
                swap(nums[k],nums[k+1]);
                counter++;
            }
        }
    }
}
void selectionSort(int nums[],int& counter, int& counter2, int num){
    counter = 0;
    counter2 = 0;
    int smallest;
    for(int i = 0; i < num - 1; i++){
        smallest = i;
        for(int k = i+1; k < num; k++){
            counter2++;
            if(nums[k] < nums[smallest]){
                smallest = k;
                counter++;
            }
        }
        swap(nums[i],nums[smallest]);
    }

}
void insertionSort(int nums[],int& counter, int& counter2, int num){
    int temp = 0;
    int loc = 0;
    for(int i = 1; i < num; i++){
        if(nums[i] < nums[i-1]){
            temp = nums[i];
            loc = i;
            do
            {
                nums[loc] = nums[loc-1];
                loc--;
                counter++;
                counter2++;
            }while(loc > 0 && nums[loc -1] > temp);
            nums[loc] = temp;

        }
    }
    counter2-=2;
}

