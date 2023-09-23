#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int randomgenerate(int range_start,int  range_end )
{
    int random_num = 0;
    srand(time(NULL));
    random_num = rand()%(range_end-range_start+1)+range_start;
    return random_num ;
}


int main()
{
    int  start_range = 0, end_range = 0 , num_random  = 0 ;
    int guess_num = 0 ;
    bool flag1 = true, flag2 = true,flag_range = true ,correct_guess = false ;
    int attempt_count1 = 5 ,attempt_count2 = 5 ;

    cout <<"Hello\n\nLet's to go to guess the number\n"<<endl;
    cout <<"please can you give a range of numbers that you want to guess within\n"<<endl;
    while(flag_range)
    {
    cout <<"enter the starting of range\n"<<endl;
    cin >> start_range;
    cout <<"enter the ending of range\n"<<endl;
    cin >> end_range;
    if(start_range>=end_range)
    {
        cout<<"you make error in entering the range\n please, enter  correct range"<<endl;
    }
    else{
        flag_range =false;
    }
    }
    cout<<endl;
    num_random = randomgenerate(start_range,end_range);
    cout <<"The number of available attempts is 5"<<endl;
    cout <<endl;
    while (flag1)
    {
        while(flag2)
        {
             cout <<"enter the the guess number\n"<<endl;
             cin >> guess_num;
             if((guess_num<=end_range)&&(guess_num>=start_range))
             {
                 cout << "the number is in range \n"<<endl;
                 flag2 = false ;
             }
             else
             {
                cout << "you enter number  is out of range \n please, enter number in specific range \n"<<endl;
             }
              attempt_count2--;
                if (attempt_count2==0)
                {
                    cout << " you exceed the number of available attempts"<<endl;
                    flag1 = false ;
                    flag2 = false ;
                }
        }
        if(flag1==false)
        {break;}

       if (guess_num == num_random)
    {
        cout <<"your guess is correct"<<endl;
        correct_guess = true ;
        break ;
    }
    else if (guess_num > num_random)
    {
       cout <<" your guess is too high \n please guess again "<<endl<<endl;
       flag2 = true ;
    }
    else if (guess_num < num_random)
    {
        cout <<" your guess is too low \n please guess again "<<endl<<endl;
        flag2 = true ;
    }
    attempt_count1--;
    if ( attempt_count1 == 0)
    {
         cout << " you exceed the number of available attempts"<<endl;
         flag1 = false ;
    }
  }


  if(correct_guess)
  {
      cout<<" you succeed to determine the correct number "<<endl;
  }
  else
  {
      cout <<" you fail to determine the correct number "<<endl<<"The generating random number is : "<<num_random<<endl;
  }
  cout<<endl<<" Game Over "<<endl;
    return 0;
}
