#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

static int timer;
static bool timesUp = 0;
int high;
int low;
int counter = 0;

void TimerFunction() {

    while(timer) {

        this_thread::sleep_for(chrono::seconds(1));
        cout <<"                             " << timer << " seconds left" << endl;
        timer--;
    }
    timesUp = 1;

}

void gameFunction() {

 while(!timesUp) {
        if(timesUp) {
            break;
        }
        //generate random number in range low - high
        int numberOne = low+ rand()%(high-(low-1));
        int numberTwo = low + rand()%(high -(low-1));
        int signDecider = rand();

        if(signDecider%2 == 0) {

            int answer = max(numberOne,numberTwo) + min(numberOne,numberTwo);
            cout << max(numberOne,numberTwo) << '+' << min(numberOne,numberTwo) << '=' << endl;

            int inputANS;

            while(inputANS != answer) {
                if(!timesUp){
                    cin >> inputANS;
                }
                if(inputANS == answer) {
                    break;
                }
            }

            inputANS = -1;
            counter++;
            continue;
            
        }else {

            int answer = max(numberOne,numberTwo) - min(numberOne,numberTwo);
            cout << max(numberOne,numberTwo) << '-' << min(numberOne,numberTwo) << '=' << endl;

            int inputANS1;

            while(inputANS1 != answer) {
                cin >> inputANS1;
                if(inputANS1 == answer) {
                    break;
                }
            }

            inputANS1 = -1;
            counter++;
            continue;
        }
    } 

    //end function
}


int main(void) {

    cout << "ENTER HIGHEST NUMBER HERE: " << endl;
        cin >> high;
    cout << "ENTER LOWEST NUMBER HERE: " << endl;
        cin >> low;
    cout << "ENTER TIME LIMIT IN SECONDS HERE: " << endl;

    cin >> timer;
    int k = timer;


    thread timerThread(TimerFunction);
    thread gameThread(gameFunction);

    timerThread.join();
    gameThread.join();

    cout << "Times Up! You scored " << counter << " points." << endl;    
   
}