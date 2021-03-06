
    #include <bits/stdc++.h>

    using namespace std;

    struct process
    {
    int id,at,bt,wt,tat;
    bool operator<(const process a) const{
        return this->bt>a.bt||this->bt==a.bt&&this->at>a.at||this->bt==a.bt&&this->at==a.at&&this->id>a.id;// a<b==>a placed before b(b has higher priority)

    }
    };

    double total_tat=0,total_wt=0;



    int main()
    {
        int n;
        cout<<"ENTER NO OF PROCESSES: ";
        cin>>n;
        process *a=new process[n];

        map<int,vector<int>> m;


        for(int i=0;i<n;i++)
        {   cout<<"PROCESS "<<i+1<<"\n";
            cout<<"ARRIVAL TIME: ";
            cin>>a[i].at;
            cout<<"BURST TIME: ";
            cin>>a[i].bt;
            a[i].id=i+1;
            m[a[i].at].push_back(i);
        }
        priority_queue<process,vector<process>> Q;
        auto it=m.begin();
        int current_timer=0;
        cout<<"----------SORTED ACC TO WHICH PROCESSS GET FINISHED FIRST--------"<<endl;
        cout <<setw(20)<<"Processes id"<<setw(20)<<"Arrival Time"<<setw(20)<<"Burst time"<<setw(20)<<"Waiting time"<<setw(20)<<" Turn around time"<<endl;


        while(!Q.empty()||it!=m.end())
        {
                 while(it!=m.end()&&it->first<=current_timer)
                       {

                        for(auto x:it->second)
                        Q.push(a[x]);
                        it++;
                       }
                if(Q.empty())
                {       if(it!=m.end())
                        {


                    for(auto x:it->second)
                        Q.push(a[x]);
                    current_timer=Q.top().at;
                    it++;
                        }
                }





            process current=Q.top();

            Q.pop();

            current.wt=current_timer-current.at;
            current.tat=current.wt+current.bt;
            total_wt = total_wt + current.wt;
            total_tat = total_tat + current.tat;
            cout <<setw(20) << current.id <<setw(20)<<current.at<<setw(20)<< current.bt <<setw(20)<< current.wt <<setw(20)<< current.tat <<endl;

            current_timer+=current.bt;



        }


        cout << "Average waiting time = "<< total_wt /n<<"\n";
        cout << "Average turn around time = "<< total_tat/n<<"\n";
        delete []a;


        return 0;
    }

