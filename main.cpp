#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include<iomanip>
using namespace std;
//nutrient class the base
class nutrient
{
public :
 virtual void cropsAvail() = 0;       //pure virtual function
};
//nitrogen class 1st derived from nutrients
class cNitrogen : public nutrient
{
public :
     float nitrogen;
   /* void getnitro()                 //used to get the nitrogen of the field
    {
        cout << "Enter the value of nitrogen present in your field " << endl;
        cin >> nitrogen;
    }*/



 //crops available for the nitrogen
void cropsAvail()
    {
       cout << "\nthese are the crops available for nitrogen \n";
 //within a switch statement will write all the crops available for them
                  if(nitrogen<2)
                  cout<<"you can grow 'rice and cotton' with this nitrogen content\n";
                    else if(nitrogen <2.5)
                    cout<< "you can grow 'rice cotton  maize' with this nitrogen content \n";
                        else if(nitrogen <5)
                        cout<< "you can grow 'rice ,cotton , maize and wheat ' with this nitrogen content \n";
                            else if(nitrogen <10)
                            cout<< "you can grow 'rice cotton  maize, wheat sugarcane' with this nitrogen content \n";
                        else
                        cout<< "you can grow 'rice cotton  maize wheat sugarcane beetroot' with this nitrogen content \n";

    }
};
//potassium class 2nd derived from nutrients
class cPotassium : public nutrient
{
public :
      float potassium;
  

 /*  void getpotash()                 //used to get the potassium of the field
    {
        cout << "Enter the value of potassium present in your field " << endl;
        cin >> potassium;
    }*/
//crops  AVAILABLE FOR potassium
void cropsAvail()
    {
       cout << "\nthese are the crops avaliable in the potassium region\n";    //within a switch statement will write all the crops available for them
          if(potassium <2)
            cout<< "you can grow 'rice cotton  wheat' with this potassium content \n";
             else if(potassium <2.5)
                    cout<< "you can grow 'rice cotton wheat maize ' with this potassium content \n";
                else if(potassium <5)
                    cout<< "you can grow 'rice cotton  maize wheat  beetroot' with this potassium content \n";
                    else
                    cout<< "you can grow 'rice cotton  maize wheat beetroot sugarcane' with this potassium content \n";
 }
};
//sulfur class 3rd derived from nutrients
class cSulfur : public nutrient
{
public:
    float sulfur;
   
 /*void getsul()
    {
     cout << "Enter the value of sulfur present in your field " << endl;
     cin >> sulfur;
  }*/
 //crops available for the sulfur
void cropsAvail()
    {
               cout << "\nthese are the crops available in the sulfur region\n";//within a switch statement will write all the crops available for them
 if(sulfur <2)
                    cout<< "you can grow 'cotton beetroot wheat' with this sulfur content \n";
                    else if(sulfur <3.6)
                    cout<< "you can grow 'rice cotton  beetroot wheat' with this sulfur content \n";
                    else if(sulfur <6.6)
                    cout<< "you can grow 'rice cotton sugarcane beetroot wheat' with this sulfur content \n";
                    else
                    cout<< "you can grow 'rice cotton  beetroot maize sugarcane wheat' with this sulfur content \n";
}
};
//class crop the ultimate derived class
class crop : public cNitrogen , public cPotassium , public cSulfur
{
public :
    char finalCropChoice[20];
    // here we will find the best crop he can grow using values of nitro potash and sulfur
    //the best crop
void bestCrop()
   {
       cout << "\nthis is the best crop in the field\n";
       if( nitrogen<2 && potassium<2 &&sulfur<2)
        strcpy(finalCropChoice , "cotton");
 else if(nitrogen>2 && nitrogen<3 && potassium>1 && potassium<2 && sulfur>0 && sulfur<1)
        strcpy(finalCropChoice , "Wheat");
            else if(nitrogen>3 && nitrogen<6 && potassium>3 && potassium<6 && sulfur>4 && sulfur<7)
           strcpy( finalCropChoice , "Sugarcane");
            else if(nitrogen>1.5 && nitrogen<3 && potassium>2 && potassium<3 && sulfur>6.5 && sulfur<9)
            strcpy(finalCropChoice , "Maize");
            else if(nitrogen>0.5 && nitrogen<1.5 && potassium>0 && potassium<1 && sulfur>3 && sulfur<4)
            strcpy(finalCropChoice , "Rice");
            else if(nitrogen>10 && nitrogen<16 && potassium>3 && potassium<5.5 && sulfur>0 && sulfur<1.5)
            strcpy(finalCropChoice , "Beetroot");
 else
            {printf("\n correct values not entered\n");
               goto skip;  }

          skip:  printf("THe best crop that you can grow is %s",finalCropChoice);
}

 //then the inclusion of the friend function for loans
    friend void loan(crop c);
};
void loan(crop c)
{
cout << "\ncalculating the loan";
int finalCrop ;                         //finalCrop is the int value associated with the crop
if(strcmp(c.finalCropChoice,"sugarcane" )||strcmp(c.finalCropChoice,"beetroot"))
    finalCrop = 1;
else if(strcmp(c.finalCropChoice,"rice"))
finalCrop = 2;
else if(strcmp(c.finalCropChoice,"cotton")||strcmp(c.finalCropChoice,"maize"))
finalCrop = 3;
else
finalCrop = 4;
cout<<"\nloans details\n";
switch(finalCrop)
{
case 1:         cout << "loans available :" ;
                cout << "sugar development fund loan \n" ;
                cout << "current interest rate:" ;
                cout << "6% interest rate\n" ;
                break ;
case 2:         cout << "loans available \n" ;
                cout << "Rashtriya krishi vikas yojana loan\n" ;
                cout << "current interest rate:" ;
                cout << "4% interest rate\n" ;
                break ;

case 3:         cout << "Pradhan mantri Yojana loan\n" ;
                cout << "current interest rate:" ;
                cout << "5% rate\n" ;
                break ;
default :       cout << "Invalid Crop Name \n" ;
                cout << "You can apply for loan under Pradhan mantri fasal suraksha yojana special loans\n" ;
                cout << " contact your nearest mandal\n" ;
                break ;
}
}


int main()
{
    cNitrogen n;
    cPotassium p;
    cSulfur s;
    crop cr;
 char city[50];
 int areaOption;
 cout<<"**** * **** *    ***       **** *    * **** ***** **** *      *"<<endl;
 cout<<"*    * *    *    *  *      *     *  *  *      *   *    * *  * *"<<endl;
 cout<<"**** * **** *    *   *     ****   **   ****   *   **** *   *  *"<<endl;
 cout<<"*    * *    *    *  *         *   **      *   *   *    *      *"<<endl;
 cout<<"*    * **** **** ***       ****   **   ****   *   **** *      *"<<endl<<"\n"<<"\n";
        
 MENU:
 cout << " 1.Modify or View the City list \n 2.Enter the City Directly" <<endl;
 cout << "Enter option:" <<endl;
 cin >> areaOption;
 fstream area;
// area.open("Area.txt",ios::app|ios::in|ios::out);
 switch(areaOption)
 {
     case 1 :                        //will be used to modify the area list like adding deleting etc
                                    //check if this works otherwise paste the full function here
                 int choice;
                    do{
                    cout << "------------MENU-------------\n";
                    cout << "\n1.Insert city to the File\n2.View cities present in file\n3.Exit\n ";
                    cout << "Enter choice:";
                    cin >> choice;
	  switch(choice)
                    {
                        case 1 :     area.open("Area.txt",ios::app|ios::in);
                                    cout << "Enter the city to be inserted in the list  " <<endl;
                                    cin >> city;
                                    area << city << endl;               //this is for inserting in the file
                                    cout << "Insertion successful";
                                    area.close();
                                    break;

                        case 2 :    cout <<"These area the cities in the list " << endl;
                                     area.open("Area.txt",ios::out|ios::in);
                                    while(area >> city)          //reading from the file
                                    {
                                        cout << city << endl;
                                    }
                                    area.close();
                                    break;
                        case 3 : goto MENU;//we should come out ,correction
		  default :  cout <<"Wrong optiion entered \n";//same here
                        }
                    }while(choice==1||choice==2);
                 area.close();
case 2 :   int insideAreaOption;
                int fieldNo,fNoEntered;
                char ownerName[50];
                float nitroValue,potashValue,sulfurValue;
                cout << "Enter the name of the city \n";
                cin >> city ;
	 fstream fCity;
	 fCity.open(city,ios::app|ios::in|ios::out);
         	 fCity.close();
                BEF: do{
                cout << "------------OPTIONS------------\n";
                cout << "1.Know contents of nitrogen,potassium,sulfur and crops to be grown\n";
                cout << "2.add/view data of field \n";
                cout << "Enter choice:\n";
                cin >> insideAreaOption;
	switch(insideAreaOption)
                        {   
case 2 :		 int inField;
                                     do{
                                    cout << "\nyou are in "<<city << endl;
                                    cout << "------------MENU------------"<<endl;
                                    cout << "1.Add contents to the field\n"<<"2.View all data\n3.previous menu\n"<<endl;
                                    cout<<"enter choice:\n";
                                    cin >> inField;
			 switch(inField)
                                            {
                                                case 1 :fCity.open(city,ios::app|ios::in|ios::out);
                                                cout<<"\nenter data of field\n";
                                                cout<<"\nFIELD NO:";
                                                cin>>fieldNo;
                                                cout<<"\nOWNER NAME:";
                                                cin>>ownerName;
                                                cout<<"\nNITROGEN,POTTASIUM,SULPHUR VALUES:";
                                                cin>>nitroValue>>potashValue>>sulfurValue;
    fCity<<fieldNo<<std::setw(17)<<ownerName<<std::setw(4)<<nitroValue<<std::setw(8)<<potashValue<<std::setw(8)<<sulfurValue<<endl;
   cout <<"Addition  successful\n";
   fCity.close();
    break;
 case 2 :				string s;
                                                              cout << "data in this file "<<city<<endl;
                                                              fCity.open(city,ios::app|ios::in|ios::out);
                                                              cout<<"\nFIELD NO.    NAME    NVAL   PVAL    SVAL\n"; 
 while(getline(fCity,s))
                                                                {
                                                                cout<<s<<endl;}
                                                                fCity.close();
                                                                break;
         //case 3:				cout<<"\nprevious menu\n";
                                                            goto BEF;
                                                             }
				}while(inField==1||inField==2||inField==3);
 case 1 :		 cout << "Enter the field Number:";
                                     cin >> fNoEntered ;
                                     fCity.open(city,ios::in);

                                     if(!fCity)
                                     {
                                         cout << "\ncannot open the file ";
                                         return 1;
                                    }
                                   while(fCity >> fieldNo >> ownerName >> nitroValue >> potashValue >> sulfurValue)
                                        {


                                            if (fieldNo == fNoEntered)
                                            {
                                                cout << "\nField Number:" << fieldNo;
                                                cout << "\nField Owner name:" << ownerName;
                                                cout << "\nNITOGEN value in field:" << nitroValue;
                                                cout << "\nPOTTASIUM value in field:" << potashValue;
                                                cout << "\nSULPHUR value in field:" << sulfurValue;
                                                n.nitrogen = nitroValue;
                                                p.potassium = potashValue;
                                                s.sulfur = sulfurValue;
                                                n.cropsAvail();
                                                p.cropsAvail();
                                                s.cropsAvail();
                                                cr.bestCrop();
                                                loan(cr);
                                            }
                                        }
                                        break;
		default : cout << "Enter proper option\n";
                                    break;
                        }
}while(insideAreaOption==1||insideAreaOption==2);
}
}
