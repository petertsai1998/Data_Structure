#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<queue>
 using namespace std;

 int main()
 {
    int t;
    queue<int> land_11;
    queue<int> land_12;
    queue<int> land_21;
    queue<int> land_22;
    queue<int> land_31;
    queue<int> land_32;
    queue<int> t_0;
    queue<int> t_1;
    queue<int> t_2;
    queue<int> t_3;
    int plane[3000]={0};               //plane status
    int fuel[3000]={0};
    int land=1;                 //store new take index
    int take=0;                 // store new land index
    int s[3000]={0};            // store second
    int emer=0;;
    int crased=0;
    int ta;                  
    int la; 
    int load[4]={0};                   //loading  
    int takeloading;
    int landloading;             
    srand(time(NULL));

    t=500; //cin >> t
    for(int i=0;i<t;i++)     //set fuel and time
    {   
        int runway[4]={0};
        cout<<endl;
        cout << "#Simulation time:" << i << endl;
        load[0]=t_0.size();
        load[1]=land_11.size()+land_12.size()+t_1.size();
        load[2]=land_21.size()+land_22.size()+t_2.size();
        load[3]=land_31.size()+land_32.size()+t_3.size();
        //do t
        for(int i=0;i<3000;i++)     //do t 
        {
            if(plane[i]==1)
            {
                s[i]+=1;
                if(fuel[i]>0)
                    fuel[i]-=1; 
            }
        }    
        ta=rand()%4;
        la=rand()%4;
        landloading=(land_11.size()+land_12.size()+land_21.size()+land_22.size()+land_31.size()+land_32.size()+la)/6;
        takeloading=(t_0.size()+t_1.size()+t_2.size()+t_3.size()+ta)/4;
        cout << "Step1:" << endl;
        cout << "landing plane:";
        // arrange landing
        for(int i=0;i<la;i++)       
        {
            plane[land] = 1;                
            fuel[land]= (rand()%9)+1;    
            cout <<"(" << land <<"," << fuel[land] << ")";
            if(land_11.size() <= landloading) 
            {
                land_11.push(land);
                //cout << "21  ";
            }   
            else if (land_12.size() <= landloading)
            {
                land_12.push(land);
                //cout << "22  ";
            }
            else if (land_21.size() <= landloading) 
            {
                land_21.push(land);
                //cout << "31  ";
            }
            else if (land_22.size() <= landloading)
            {
                land_22.push(land);
                //cout << "32  ";
            }
            else if (land_31.size() <= landloading)
            {    
                land_31.push(land);
                //cout << "41  ";
            }
            else 
            {
                land_32.push(land);
                //cout << "42  ";
            }
            land +=2;
        }
        cout<<endl;
        //delete crash
        if(!land_11.empty())
        {
            while(plane[land_11.front()]==0)
            {
                land_11.pop();
                if(land_11.empty())
                    break;
            }
        }
        if(!land_12.empty())
        {
            while(plane[land_12.front()]==0)
            {
                land_12.pop();
                if(land_12.empty())
                    break;
            }
        }  
        if(!land_21.empty())
        {
            while(plane[land_21.front()]==0)
            {
                land_21.pop();
                if(land_21.empty())
                    break;
            }
        }
        if(!land_22.empty())
        {
            while(plane[land_22.front()]==0)
            {
                land_22.pop();
                if(land_22.empty())
                    break;
            }
        }   
        if(!land_31.empty())
        {
            while(plane[land_31.front()]==0)
            {
                land_31.pop();
                if(land_31.empty())
                    break;
            }
        }
        if(!land_32.empty())
        {
            while(plane[land_32.front()]==0)
            {
                land_32.pop();
                if(land_32.empty())
                    break;
            }
        }  
        //landing
        cout << endl;
        cout <<"Runway2" << endl;
        if(land_11.size()+land_12.size()>0)    //runway
        {
            if(land_11.size()>land_12.size())
            {   
                cout << "L1:(" << land_11.front() << "," << fuel[land_11.front()] << ")" << endl;
                plane[land_11.front()]=0;
                runway[1]=1;
                land_11.pop();
            }
            else
            {
                cout << "L2:(" << land_12.front() << "," << fuel[land_12.front()] << ")" << endl;
                plane[land_12.front()]=0;
                runway[1]=1;
                land_12.pop();
            }
        }
        cout << endl;
        cout <<"Runway3" << endl;
        if(land_21.size()+land_22.size()>0)    //runway
        {
            if(land_21.size()>land_22.size())
            {   
                cout << "L1:(" << land_21.front() << "," << fuel[land_21.front()] << ")" << endl;
                plane[land_21.front()]=0;
                runway[2]=1;
                land_21.pop();
            }
            else
            {
                cout << "L2:(" << land_22.front() << "," << fuel[land_22.front()] << ")" << endl;
                plane[land_22.front()]=0;
                runway[2]=1;
                land_22.pop();
            }
        }
        cout << endl;
        cout <<"Runway4" << endl;
        if(land_31.size()+land_32.size()>0)    //runway
        {
            if(land_31.size()>land_32.size())
            {   
                cout << "L1:(" << land_31.front() << "," << fuel[land_31.front()] << ")" << endl;
                plane[land_31.front()]=0;
                runway[3]=1;
                land_31.pop();
            }
            else
            {
                cout << "L2:(" << land_32.front() << "," << fuel[land_32.front()] << ")" << endl;
                plane[land_32.front()]=0;
                runway[3]=1;
                land_32.pop();
            }
        }
        cout<<endl;
        cout<< "step2:" <<endl;
        cout << "takeoff plane:"; 
        //create takeoff +arrange
        for(int i=0;i<ta;i++)        
        {
            plane[take] = 1;
            cout <<"("<< take << ")";               
            if(t_3.size()<=takeloading)
            {
                t_3.push(take);
            }
            else if (t_2.size()<=takeloading)
            {
                t_2.push(take);
            }
            else if (t_1.size()<=takeloading)
            {
                t_1.push(take);
            }
            else
            {
                t_0.push(take);
            }
            take +=2;
        }
        cout<<endl;
        //takeoff
        cout << endl;
        cout <<"Runway1" << endl;     
        if(t_0.size()>0 && runway[0]==0)
        {
            cout<<"T:("<< t_0.front() <<")" <<endl;
            plane[t_0.front()]=0;
            runway[0]=1;
            t_0.pop();
        }
        cout << endl;
        cout <<"Runway2" << endl; 
        if(t_1.size()>0 && runway[1]==0)
        {
            cout<<"T:("<< t_1.front() <<")" <<endl;
            plane[t_1.front()]=0;
            runway[1]=1;
            t_1.pop();
        }
        cout << endl;
        cout <<"Runway3" << endl; 
        if(t_2.size()>0 && runway[2]==0)
        {
            cout<<"T:("<< t_2.front() <<")" <<endl;
            plane[t_2.front()]=0;
            runway[2]=1;
            t_2.pop();
        } 
        cout << endl;       
        cout <<"Runway4" << endl; 
        if(t_3.size()>0 && runway[3]==0)
        {
            cout<<"T:("<< t_3.front() <<")" <<endl;
            plane[t_3.front()]=0;
            runway[3]=1;
            t_3.pop();
        }
        cout<<endl;
        cout<<"step 3:"<<endl;
        cout<<"emergency plane:";
        for(int i=1;i<3000;)
        {
            if(plane[i]==1 && fuel[i]==0)
            {
                cout<<"("<< i <<")"<< endl; 
                emer +=1; 
                if(runway[0]==0)   
                {
                    cout<<endl;
                    cout<<"Runway1"<<endl;
                    plane[i]=0;
                    cout<<"("<< i <<")"<<endl;
                }  
                else if(runway[1]==0)
                {
                    cout<<endl;
                    cout<<"Runway2"<<endl;
                    plane[i]=0;
                    cout<<"("<< i <<")"<<endl;
                }  
                else if(runway[2]==0)
                {
                    cout<<endl;
                    cout<<"Runway3"<<endl;
                    plane[i]=0;
                    cout<<"("<< i <<")"<<endl;
                } 
                else if(runway[3]==0)
                {
                    cout<<endl;
                    cout<<"Runway4"<<endl;
                    plane[i]=0;
                    cout<<"("<< i <<")"<<endl;
                }   
                else
                {
                    plane[i]=0;
                    crased+=1;
                }
            }
            i+=2;
        }
        cout<<endl;
        cout<<"Step 4:";
        cout<<endl;
        //delete crash
        if(!land_11.empty())
        {
            while(plane[land_11.front()]==0)
            {
                land_11.pop();
                if(land_11.empty())
                    break;
            }
        }
        if(!land_12.empty())
        {
            while(plane[land_12.front()]==0)
            {
                land_12.pop();
                if(land_12.empty())
                    break;
            }
        }  
        if(!land_21.empty())
        {
            while(plane[land_21.front()]==0)
            {
                land_21.pop();
                if(land_21.empty())
                    break;
            }
        }
        if(!land_22.empty())
        {
            while(plane[land_22.front()]==0)
            {
                land_22.pop();
                if(land_22.empty())
                    break;
            }
        }   
        if(!land_31.empty())
        {
            while(plane[land_31.front()]==0)
            {
                land_31.pop();
                if(land_31.empty())
                    break;
            }
        }
        if(!land_32.empty())
        {
            while(plane[land_32.front()]==0)
            {
                land_32.pop();
                if(land_32.empty())
                    break;
            }
        }  
        if(runway[0]==0)
        {   
            cout<<"Runway 1";
            cout<<endl;
            if(!land_11.empty())
            {
                plane[land_11.front()]=0;
                cout << "("<<land_11.front()<<")"<<endl;
                land_11.pop();
            }
            else if(!land_12.empty())
            {
                plane[land_12.front()]=0;
                cout << "("<<land_12.front()<<")"<<endl;
                land_12.pop();
            }
            else if(!land_21.empty())
            {
                plane[land_21.front()]=0;
                cout << "("<<land_21.front()<<")"<<endl;
                land_21.pop();
            }
            else if(!land_22.empty())
            {
                plane[land_22.front()]=0;
                cout << "("<<land_22.front()<<")"<<endl;
                land_22.pop();
            }
            else if(!land_31.empty())
            {
                plane[land_31.front()]=0;
                cout << "("<<land_31.front()<<")"<<endl;
                land_31.pop();
            }
            else if(!land_32.empty())
            {
                plane[land_32.front()]=0;
                cout << "("<<land_32.front()<<")"<<endl;
                land_32.pop();
            }
        }
        if(runway[1]==0)
        {
            cout<<"Runway 2";
            cout<<endl;
            if(!land_11.empty())
            {
                plane[land_11.front()]=0;
                cout << "("<<land_11.front()<<")"<<endl;
                land_11.pop();
            }
            else if(!land_12.empty())
            {
                plane[land_12.front()]=0;
                cout << "("<<land_12.front()<<")"<<endl;
                land_12.pop();
            }
            else if(!land_21.empty())
            {
                plane[land_21.front()]=0;
                cout << "("<<land_21.front()<<")"<<endl;
                land_21.pop();
            }
            else if(!land_22.empty())
            {
                plane[land_22.front()]=0;
                cout << "("<<land_22.front()<<")"<<endl;
                land_22.pop();
            }
            else if(!land_31.empty())
            {
                plane[land_31.front()]=0;
                cout << "("<<land_31.front()<<")"<<endl;
                land_31.pop();
            }
            else if(!land_32.empty())
            {
                plane[land_32.front()]=0;
                cout << "("<<land_32.front()<<")"<<endl;
                land_32.pop();
            }
        }
        if(runway[2]==0)
        {
           cout<<"Runway 3";
           cout<<endl;
            if(!land_11.empty())
            {
                plane[land_11.front()]=0;
                cout << "("<<land_11.front()<<")"<<endl;
                land_11.pop();
            }
            else if(!land_12.empty())
            {
                plane[land_12.front()]=0;
                cout << "("<<land_12.front()<<")"<<endl;
                land_12.pop();
            }
            else if(!land_21.empty())
            {
                plane[land_21.front()]=0;
                cout << "("<<land_21.front()<<")"<<endl;
                land_21.pop();
            }
            else if(!land_22.empty())
            {
                plane[land_22.front()]=0;
                cout << "("<<land_22.front()<<")"<<endl;
                land_22.pop();
            }
            else if(!land_31.empty())
            {
                plane[land_31.front()]=0;
                cout << "("<<land_31.front()<<")"<<endl;
                land_31.pop();
            }
            else if(!land_32.empty())
            {
                plane[land_32.front()]=0;
                cout << "("<<land_32.front()<<")"<<endl;
                land_32.pop();
            } 
        }

        if(runway[3]==0)
        {
            cout<<"Runway 4";
            cout<<endl;
            if(!land_11.empty())
            {
                plane[land_11.front()]=0;
                cout << "("<<land_11.front()<<")"<<endl;
                land_11.pop();
            }
            else if(!land_12.empty())
            {
                plane[land_12.front()]=0;
                cout << "("<<land_12.front()<<")"<<endl;
                land_12.pop();
            }
            else if(!land_21.empty())
            {
                plane[land_21.front()]=0;
                cout << "("<<land_21.front()<<")"<<endl;
                land_21.pop();
            }
            else if(!land_22.empty())
            {
                plane[land_22.front()]=0;
                cout << "("<<land_22.front()<<")"<<endl;
                land_22.pop();
            }
            else if(!land_31.empty())
            {
                plane[land_31.front()]=0;
                cout << "("<<land_31.front()<<")"<<endl;
                land_31.pop();
            }
            else if(!land_32.empty())
            {
                plane[land_32.front()]=0;
                cout << "("<<land_32.front()<<")"<<endl;
                land_32.pop();
            }
        }
        cout<<endl;
    }
    cout << "How Many Time You Want to Simulate:"<< t << endl;

    double ltime=0;
    double save=0;
    for(int i=1;i<land;)
    {
        ltime +=s[i];
        save+=fuel[i];
        i+=2;
    }
    cout <<"average landing waiting time:"<< ltime/(land/2)+1<<"(s)"<<endl;

    double ttime=0; 
    for(int i=0;i<take;)
    {
        ttime+=s[i];
        i+=2;
    }
    cout <<"average takeoff waiting time:"<< ttime/(take/2)+1<<"(s)"<<endl;
    cout <<"average fuel saved:"<< save/(land/2)+1<<"(s)"<<endl;

    /*for(int i=0;i<land;i++)
    {
        cout << "i=" << i << "  ";
        cout << plane[i]<<"  "; 
        cout << fuel[i];
        cout<<endl;
    }
    */
    
    cout <<"total plane in emergency:"<<emer<<endl;
    cout <<"total plane crased:"<< crased<<endl;
 }
