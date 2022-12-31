#include <iostream>
#include <cstring>
using namespace std;
int F[10001][10001],Q[10001][10001],G[10001][10001];

int main()
{
   cout<<"<<<<<<<<<     此程式提供兩種需求尺寸在原物料平面切割上的最佳排樣     >>>>>>>>>";
   cout<<endl<<"                        version 3.       update:2018/04/28"<<endl<<endl<<endl<<endl;
   start:
   int v[2],l[2],w[2];
   int Length,Wedth;
   int N[8]; // [n1wx,n1wy,n1lx,n1ly,n2wx,n2wy,n2lx,n2ly] 
   int n=2;
   int a=0,Lset[10001];//a=Lset裡面有計算到的最後的數的順序, Lset[a-1]表示運算到最後的數, 因為陣列從0開始 
   int b=0,Wset[10001];//a=Lset裡面有計算到的最後的數的順序, Lset[a-1]表示運算到最後的數, 因為陣列從0開始
   for(int j=0;j<a;j++)
   {
      for(int k=0;k<b&k<=j;k++)
      {
         F[Lset[j]][Wset[k]]=0;
         Q[Lset[j]][Wset[k]]=0;
         G[Lset[j]][Wset[k]]=0;
      }
   } 
//--------------------------------------------------------
   for(int i=0;i<n;i++)
      {
         cout<<"請輸入第 "<<i+1<<" 塊需求尺寸的長邊長度:"; 
         cin>>l[i];
         while(l[i]>10000)
         {
            cout<<"錯誤!數值須小於10000"<<endl<<"請重新輸入:";
            cin>>l[i];
         } 
         cout<<"請輸入第 "<<i+1<<" 塊需求尺寸的寬邊長度:"; 
         cin>>w[i];
         while(w[i]>l[i])
         {
            cout<<"錯誤!數值須小於等於長邊"<<endl<<"請重新輸入:";
            cin>>w[i];
         } 
         cout<<"請輸入第 "<<i+1<<" 塊需求尺寸的價值(或面積):"; 
         cin>>v[i];
      }
//-------------------------------------------------------
   cout<<endl<<"請輸入原物料板的長邊長度:"; 
   cin>>Length;
   while(Length>10000)
   {
      cout<<"錯誤!數值須小於10000"<<endl<<"請重新輸入:";
      cin>>Length;
   }
   cout<<"若無跑出數字，請耐心等候!!\n表示正在運算normal length"<<endl; 
   for(int i=0;i<=(Length/w[0]);i++)
   {
      for(int j=0;j<=(Length/l[0]);j++)
      {
         for(int k=0;k<=(Length/w[1]);k++)
         {
            for(int s=0;s<=(Length/l[1]);s++)
            {
               if(i*w[0]+j*l[0]+k*w[1]+s*l[1]<=Length)
               {
                  int judge=0;//-------------------------------------------------20180428 debug
                  for(int z=0;z<=a;z++)
                  {
                     if(i*w[0]+j*l[0]+k*w[1]+s*l[1]==Lset[z]&i*w[0]+j*l[0]+k*w[1]+s*l[1]>0)
                     {
                        judge=1;
                        break;
                     }
                  }
                  if(judge==0)
                  {
                     Lset[a]=i*w[0]+j*l[0]+k*w[1]+s*l[1];
                     a=a+1;// a到最後會多1, 要扣掉
                  }//------------------------------------------------------------- 
               }
            }
         }
      }
   }
   for(int i=0;i<a-1;i++) //泡沫搜尋法, 重新排序Lset裡面的數 
   {
      for(int j=i+1;j<a;j++)
      {
         if(Lset[i]>Lset[j])
         {
            int x=Lset[i];
            int y=Lset[j];
            Lset[i]=y;
            Lset[j]=x;
         }
      }
   }
   cout<<"Normal Length裡面共有 "<<a<<" 個數:"<<"\n";//陣列是從0開始為第一個數, a即為總共組合數的數量
   for(int i=0;i<a;i++)//Lset[a]=Length+1, 因此要取到a-1就好了 
   {
      cout<<Lset[i]<<", ";
   }
   cout<<endl;
//分隔 -------------------------------------------------------------------- 
   cout<<endl<<"請輸入原物料板的寬邊長度:"; 
   cin>>Wedth;
   while(Wedth>Length)
   {
      cout<<"錯誤!數值須小於等於長邊"<<endl<<"請重新輸入:";
      cin>>Wedth;
   }
   cout<<"若無跑出數字，請耐心等候!!\n表示正在運算normal Width"<<endl; 
   for(int i=0;i<=(Wedth/w[0]);i++)
   {
      for(int j=0;j<=(Wedth/l[0]);j++)
      {
         for(int k=0;k<=(Wedth/w[1]);k++)
         {
            for(int s=0;s<=(Wedth/l[1]);s++)
            {
               if(i*w[0]+j*l[0]+k*w[1]+s*l[1]<=Wedth)
               {
                  int judge=0;//-------------------------------------------------20180428 debug
                  for(int z=0;z<=b;z++)
                  {
                     if(i*w[0]+j*l[0]+k*w[1]+s*l[1]==Wset[z]&i*w[0]+j*l[0]+k*w[1]+s*l[1]>0)
                     {
                        judge=1;
                        break;
                     }
                  }
                  if(judge==0)
                  {
                     Wset[b]=i*w[0]+j*l[0]+k*w[1]+s*l[1];
                     b=b+1;// a到最後會多1, 要扣掉
                  }//-------------------------------------------------------------
               }
            }
         }
      }
   }
   for(int i=0;i<b-1;i++) //泡沫搜尋法, 重新排序Wset裡面的數 
   {
      for(int j=i+1;j<b;j++)
      {
         if(Wset[i]>Wset[j])
         {
            int x=Wset[i];
            int y=Wset[j];
            Wset[i]=y;
            Wset[j]=x;
         }
      }
   }
   cout<<"Normal Width裡面共有 "<<b<<" 個數:"<<"\n";//陣列是從0開始為第一個數, b即為總共組合數的數量
   for(int i=0;i<b;i++)//Wset[b]=Wedth+1, 因此要取到b-1就好了 
   {
      cout<<Wset[i]<<", ";
   }
   cout<<endl<<endl<<endl;
   system("pause");
//分隔 -------------------------------------------------------------------- 
   double START,END;
   START = clock();
   memset(F,0, sizeof(F));  //初始化F值為0
   memset(Q,0, sizeof(Q));  //初始化Q值為0
   memset(G,0, sizeof(G));  //初始化G值為0
   memset(N,0, sizeof(N));  //初始化所有切法的價值為零
   for(int j=0;j<a;j++) //變數X的遞增 
   {
      for(int k=0;k<b&k<=j;k++) //變數y的遞增, &表示兩個都要滿足才能進行 
      {
         cout<<endl<<endl<<"------------------------我是分隔線區隔每一個step off------------------------"<<endl<<endl<<"==============================================";
         cout<<"\n"<<"                 當 L="<<Lset[j]<<",W="<<Wset[k]<<" 時"<<"\n"<<"\n";
         cout<<"   --------------各切法之價值--------------   "<<"\n";
         if(Wset[k]>=l[0])
         {
            N[0]=F[Lset[j]][Wset[k]-l[0]]+(Lset[j]/w[0])*v[0];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"第1種切法："<<N[0]<<"\n";
         }
         if(Lset[j]>=l[0])
         {
            N[1]=F[Lset[j]-l[0]][Wset[k]]+(Wset[k]/w[0])*v[0];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"第2種切法："<<N[1]<<"\n";
         }
         if(Wset[k]>=w[0])
         {
            N[2]=F[Lset[j]][Wset[k]-w[0]]+(Lset[j]/l[0])*v[0];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"第3種切法："<<N[2]<<"\n";
         }
         if(Lset[j]>=w[0])
         {
            N[3]=F[Lset[j]-w[0]][Wset[k]]+(Wset[k]/l[0])*v[0];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"第4種切法："<<N[3]<<"\n";
         }
         if(Wset[k]>=l[1])
         {
            N[4]=F[Lset[j]][Wset[k]-l[1]]+(Lset[j]/w[1])*v[1];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"第5種切法："<<N[4]<<"\n";
         }
         if(Lset[j]>=l[1])
         {
            N[5]=F[Lset[j]-l[1]][Wset[k]]+(Wset[k]/w[1])*v[1];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"第6種切法："<<N[5]<<"\n";
         }
         if(Wset[k]>=w[1])
         {
            N[6]=F[Lset[j]][Wset[k]-w[1]]+(Lset[j]/l[1])*v[1];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"第7種切法："<<N[6]<<"\n";
         }
         if(j>=w[1])
         {
            N[7]=F[Lset[j]-w[1]][Wset[k]]+(Wset[k]/l[1])*v[1];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"第8種切法："<<N[7]<<"\n";
         }
         cout<<"   ----------------------------------------   "<<"\n"<<"\n";
         int maxN=0;
         for(int i=0;i<8;i++) //找尋最大價值的切法
         {
            if(N[i]>maxN)
            {
               maxN=N[i];
            }                         
         }
         for(int i=0;i<8;i++) 
         {
            if(N[i]>N[(i+1)%8]&&N[i]>N[(i+2)%8]&&N[i]>N[(i+3)%8]&&N[i]>N[(i+4)%8]
            &&N[i]>N[(i+5)%8]&&N[i]>N[(i+6)%8]&&N[i]>N[(i+7)%8])
            {
               Q[Lset[j]][Wset[k]]=i+1; //記錄Q(X,Y), 記錄只有一個最佳N值的該切法, 加1為使之往後推至8種 
               if(i==0) //記錄G值 
               {
                  G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]-l[0]];
                  if(G[Lset[j]][Wset[k]]<1)
                  {
                     G[Lset[j]][Wset[k]]=1;
                  }
                  if(Q[Lset[j]][Wset[k]]!=Q[Lset[j]][Wset[k]-l[0]])
                  {
                     G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]]+1;
                  }
               }
               if(i==1) //記錄G值 
               {
                  G[Lset[j]][Wset[k]]=G[Lset[j]-l[0]][Wset[k]];
                  if(G[Lset[j]][Wset[k]]<1)
                  {
                     G[Lset[j]][Wset[k]]=1;
                  }
                  if(Q[Lset[j]][Wset[k]]!=Q[Lset[j]-l[0]][Wset[k]])
                  {
                     G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]]+1;
                  }
               }
               if(i==2) //記錄G值 
               {
                  G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]-w[0]];
                  if(G[Lset[j]][Wset[k]]<1)
                  {
                     G[Lset[j]][Wset[k]]=1;
                  }
                  if(Q[Lset[j]][Wset[k]]!=Q[Lset[j]][Wset[k]-w[0]])
                  {
                     G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]]+1;
                  }
               }
               if(i==3) //記錄G值 
               {
                  G[Lset[j]][Wset[k]]=G[Lset[j]-w[0]][Wset[k]];
                  if(G[Lset[j]][Wset[k]]<1)
                  {
                     G[Lset[j]][Wset[k]]=1;
                  }
                  if(Q[Lset[j]][Wset[k]]!=Q[Lset[j]-w[0]][Wset[k]])
                  {
                     G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]]+1;
                  }
               }
               if(i==4) //記錄G值 
               {
                  G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]-l[1]];
                  if(G[Lset[j]][Wset[k]]<1)
                  {
                     G[Lset[j]][Wset[k]]=1;
                  }
                  if(Q[Lset[j]][Wset[k]]!=Q[Lset[j]][Wset[k]-l[1]])
                  {
                     G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]]+1;
                  }
               }
               if(i==5) //記錄G值 
               {
                  G[Lset[j]][Wset[k]]=G[Lset[j]-l[1]][Wset[k]];
                  if(G[Lset[j]][Wset[k]]<1)
                  {
                     G[Lset[j]][Wset[k]]=1;
                  }
                  if(Q[Lset[j]][Wset[k]]!=Q[Lset[j]-l[1]][Wset[k]])
                  {
                     G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]]+1;
                  }
               }
               if(i==6) //記錄G值 
               {
                  G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]-w[1]];
                  if(G[Lset[j]][Wset[k]]<1)
                  {
                     G[Lset[j]][Wset[k]]=1;
                  }
                  if(Q[Lset[j]][Wset[k]]!=Q[Lset[j]][Wset[k]-w[1]])
                  {
                     G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]]+1;
                  }
               }
               if(i==7) //記錄G值 
               {
                  G[Lset[j]][Wset[k]]=G[Lset[j]-w[1]][Wset[k]];
                  if(G[Lset[j]][Wset[k]]<1)
                  {
                     G[Lset[j]][Wset[k]]=1;
                  }
                  if(Q[Lset[j]][Wset[k]]!=Q[Lset[j]-w[1]][Wset[k]])
                  {
                     G[Lset[j]][Wset[k]]=G[Lset[j]][Wset[k]]+1;
                  }
               }
            }
         } 
         cout<<"   ---------------最大值切法---------------   "<<"\n"<<"   "; //找尋一樣同為最大價值的切法 
         int findmaxN[8],g[8]={99999,99999,99999,99999,99999,99999,99999,99999}; //找超久靠 
         int judgement=0; //找同為最大值的N 
         int findmin_g[8],min_g=9999,judgement_g=0; //g如果有一樣的, 再找       
         for(int x=0;x<8;x++)
         {                  
            if(N[x]==maxN&N[x]>0) //&極為重要....................................................關鍵 
            {
               cout<<x+1<<",";
               judgement=judgement+1;
               findmaxN[x]=1; 
            }                  
         }
         if(judgement>1) //表示max數不是只有一個 
         {
            if(findmaxN[0]==1)
            {
               g[0]=G[Lset[j]][Wset[k]-l[0]];
               if(Q[Lset[j]][Wset[k]-l[0]]!=1) 
               {
                  g[0]=g[0]+1;
               }
            }
            if(findmaxN[1]==1)
            {
               g[1]=G[Lset[j]-l[0]][Wset[k]];
               if(Q[Lset[j]-l[0]][Wset[k]]!=2)
               {
                  g[1]=g[1]+1;
               }
            }
            if(findmaxN[2]==1)
            {
               g[2]=G[Lset[j]][Wset[k]-w[0]];
               if(Q[Lset[j]][Wset[k]-w[0]]!=3)
               {
                  g[2]=g[2]+1;
               }
            }
            if(findmaxN[3]==1)
            {
               g[3]=G[Lset[j]-w[0]][Wset[k]];
               if(Q[Lset[j]-w[0]][Wset[k]]!=4)
               {
                  g[3]=g[3]+1;
               }
            }
            if(findmaxN[4]==1)
            {
               g[4]=G[Lset[j]][Wset[k]-l[1]];
               if(Q[Lset[j]][Wset[k]-l[1]]!=5)
               {
                  g[4]=g[4]+1;
               }
            }
            if(findmaxN[5]==1)
            {
               g[5]=G[Lset[j]-l[1]][Wset[k]];
               if(Q[Lset[j]-l[1]][Wset[k]]!=6)
               {
                  g[5]=g[5]+1;
               }
            }
            if(findmaxN[6]==1)
            {
               g[6]=G[Lset[j]][Wset[k]-w[1]];
               if(Q[Lset[j]][Wset[k]-w[1]]!=7)
               {
                  g[6]=g[6]+1;
               }
            }
            if(findmaxN[7]==1)
            {
               g[7]=G[Lset[j]-w[1]][Wset[k]];
               if(Q[Lset[j]-w[1]][Wset[k]]!=8)
               {
                  g[7]=g[7]+1;
               }
            }
            //cout<<endl<<"g[x]:"<<endl; //看哪個g[]值低,  
            //for(int x=0;x<8;x++)
            //{
            //        cout<<g[x]<<", ";
            //}
            cout<<endl;
            for(int x=0;x<8;x++) //找尋g陣列最小值
            {
               if(g[x]<min_g)
               {
                  min_g=g[x];
               }                         
            }
            for(int x=0;x<8;x++) 
            {
               if(g[x]<g[(x+1)%8]&&g[x]<g[(x+2)%8]&&g[x]<g[(x+3)%8]&&g[x]<g[(x+4)%8]
               &&g[x]<g[(x+5)%8]&&g[x]<g[(x+6)%8]&&g[x]<g[(x+7)%8])
               {
                  G[Lset[j]][Wset[k]]=g[x];
                  Q[Lset[j]][Wset[k]]=x+1;
                  cout<<endl<<"   選擇切割次數最少的切法: "<<x+1<<endl; 
               }
            }
            for(int x=0;x<8;x++) //找兩個以上一樣同為最小值的g值 
            {                  
               if(g[x]==min_g)
               {
                  judgement_g=judgement_g+1;
                  findmin_g[x]=1; 
               }
            }
            if(judgement_g>1)
            {
               G[Lset[j]][Wset[k]]=min_g;
               cout<<endl<<endl<<"   同價值也同樣具最少切割次數的切法為(表示"<<endl;
               cout<<"   以下切法皆可行，Q值將採數值最大的切法):"<<endl<<"   "; 
               for(int x=0;x<8;x++)
               {
                  if(g[x]==min_g)
                  {
                     cout<<x+1<<", ";
                     Q[Lset[j]][Wset[k]]=x+1;//Q如果是九, 後面的數Q若不為9會導致section增加, 因此如果有相同的g值, 取最大的那個記錄下來 
                  }
               }
               cout<<endl;
            }
         }
         
                   
         cout<<"\n"<<"   ----------------------------------------   "<<"\n"<<"\n";              
         F[Lset[j]][Wset[k]]=maxN;
         for(int x=0;x<8;x++)
         {
            N[x]=0;
            findmaxN[x]=0;
            findmin_g[x]=0;
            g[x]=99999;
         }
         cout<<"=============================================="<<endl;
      }
   }
   END = clock();
   float ratio,area;
   area=(Length*Wedth);
   cout<<endl<<endl<<"                        ↑↑以上為運算時的記錄值↑↑"<<endl<<endl<<"-----------------------------------RESULT-----------------------------------";
   cout << endl << "運算所花費的時間：" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
   cout<<"當 L="<<Lset[a-1]<<",W="<<Wset[b-1]<<", l1:"<<l[0]<<",w1="<<w[0]<<", l2="<<l[1]<<",w2="<<w[1]<<" 時有最佳解:";
   cout<<endl<<"F("<<Length<<","<<Wedth<<")=Normal Combination "<<"F("<<Lset[a-1]<<","<<Wset[b-1]<<")="
   <<F[Lset[a-1]][Wset[b-1]]<<endl<<"Q("<<Length<<","<<Wedth<<")=Normal Combination "<<"Q("<<Lset[a-1]<<","<<Wset[b-1]<<")="<<Q[Lset[a-1]][Wset[b-1]]
   <<endl<<"G("<<Length<<","<<Wedth<<")=Normal Combination "<<"G("<<Lset[a-1]<<","<<Wset[b-1]<<")="<<G[Lset[a-1]][Wset[b-1]];
   int first_piece=0,second_piece=0;
   int policy_L=Lset[a-1],policy_W=Wset[b-1];
   while(policy_L>0&policy_W>0)
   {
      if(Q[policy_L][policy_W]==1)
      {
         first_piece=first_piece+(F[policy_L][policy_W]-F[policy_L][policy_W-l[0]])/v[0];
      }
      if(Q[policy_L][policy_W]==2)
      {
         first_piece=first_piece+(F[policy_L][policy_W]-F[policy_L-l[0]][policy_W])/v[0];
      }
      if(Q[policy_L][policy_W]==3)
      {
         first_piece=first_piece+(F[policy_L][policy_W]-F[policy_L][policy_W-w[0]])/v[0];
      }
      if(Q[policy_L][policy_W]==4)
      {
         first_piece=first_piece+(F[policy_L][policy_W]-F[policy_L-w[0]][policy_W])/v[0];
      }
      if(Q[policy_L][policy_W]==5)
      {
         second_piece=second_piece+(F[policy_L][policy_W]-F[policy_L][policy_W-l[1]])/v[1];
      }
      if(Q[policy_L][policy_W]==6)
      {
         second_piece=second_piece+(F[policy_L][policy_W]-F[policy_L-l[1]][policy_W])/v[1];
      }
      if(Q[policy_L][policy_W]==7)
      {
         second_piece=second_piece+(F[policy_L][policy_W]-F[policy_L][policy_W-w[1]])/v[1];
      }
      if(Q[policy_L][policy_W]==8)
      {
         second_piece=second_piece+(F[policy_L][policy_W]-F[policy_L-w[1]][policy_W])/v[1];
      }
//-----------------------------------------------------
      if(Q[policy_L][policy_W]==1)
      {
         policy_W=policy_W-l[0];
      }
      else if(Q[policy_L][policy_W]==2)
      {
         policy_L=policy_L-l[0];
      }
      else if(Q[policy_L][policy_W]==3)
      {
         policy_W=policy_W-w[0];
      }
      else if(Q[policy_L][policy_W]==4)
      {
         policy_L=policy_L-w[0];
      }
      else if(Q[policy_L][policy_W]==5)
      {
         policy_W=policy_W-l[1];
      }
      else if(Q[policy_L][policy_W]==6)
      {
         policy_L=policy_L-l[1];
      }
      else if(Q[policy_L][policy_W]==7)
      {
         policy_W=policy_W-w[1];
      }
      else if(Q[policy_L][policy_W]==8)
      {
         policy_L=policy_L-w[1];
      }
   }
   ratio=((first_piece*w[0]*l[0])+(second_piece*w[1]*l[1]))/area;
   cout<<"\n"<<"第一塊共使用了: "<<first_piece<<" 塊\t第二塊共使用了: "<<second_piece<<" 塊\t面積利用率為: "<<ratio*100<<"%"<<"\n";
   cout<<"\n"<<"-----------------------------------POLICY-----------------------------------"<<"\n";
   policy_L=Lset[a-1],policy_W=Wset[b-1];
   while(policy_L>0&policy_W>0)
   {
      cout<<"F("<<policy_L<<","<<policy_W<<")="<<F[policy_L][policy_W]<<"\t時,放入第 ";
      if(Q[policy_L][policy_W]<5)
      {
         cout<<"1";
      }
      if(Q[policy_L][policy_W]>4)
      {
         cout<<"2";
      }
      cout<<" 塊並以 ";
      if(Q[policy_L][policy_W]==3||Q[policy_L][policy_W]==4||Q[policy_L][policy_W]>6)
      {
         cout<<"長邊";
      }
      if(Q[policy_L][policy_W]==5||Q[policy_L][policy_W]==6||Q[policy_L][policy_W]<3)
      {
         cout<<"短邊";
      }
      cout<<" 為方向平行於 ";
      if(Q[policy_L][policy_W]==1||Q[policy_L][policy_W]==3||Q[policy_L][policy_W]==5||Q[policy_L][policy_W]==7)
      {
         cout<<"X軸";
      }
      if(Q[policy_L][policy_W]==2||Q[policy_L][policy_W]==4||Q[policy_L][policy_W]==6||Q[policy_L][policy_W]==8)
      {
         cout<<"Y軸";
      }
      cout<<" , 共放 ";
      if(Q[policy_L][policy_W]==1)
      {
         cout<<(F[policy_L][policy_W]-F[policy_L][policy_W-l[0]])/v[0];
      }
      if(Q[policy_L][policy_W]==2)
      {
         cout<<(F[policy_L][policy_W]-F[policy_L-l[0]][policy_W])/v[0];
      }
      if(Q[policy_L][policy_W]==3)
      {
         cout<<(F[policy_L][policy_W]-F[policy_L][policy_W-w[0]])/v[0];
      }
      if(Q[policy_L][policy_W]==4)
      {
         cout<<(F[policy_L][policy_W]-F[policy_L-w[0]][policy_W])/v[0];
      }
      if(Q[policy_L][policy_W]==5)
      {
         cout<<(F[policy_L][policy_W]-F[policy_L][policy_W-l[1]])/v[1];
      }
      if(Q[policy_L][policy_W]==6)
      {
         cout<<(F[policy_L][policy_W]-F[policy_L-l[1]][policy_W])/v[1];
      }
      if(Q[policy_L][policy_W]==7)
      {
         cout<<(F[policy_L][policy_W]-F[policy_L][policy_W-w[1]])/v[1];
      }
      if(Q[policy_L][policy_W]==8)
      {
         cout<<(F[policy_L][policy_W]-F[policy_L-w[1]][policy_W])/v[1];
      }
      cout<<" 個"<<endl;
      if(Q[policy_L][policy_W]==1)
      {
         policy_W=policy_W-l[0];
      }
      else if(Q[policy_L][policy_W]==2)
      {
         policy_L=policy_L-l[0];
      }
      else if(Q[policy_L][policy_W]==3)
      {
         policy_W=policy_W-w[0];
      }
      else if(Q[policy_L][policy_W]==4)
      {
         policy_L=policy_L-w[0];
      }
      else if(Q[policy_L][policy_W]==5)
      {
         policy_W=policy_W-l[1];
      }
      else if(Q[policy_L][policy_W]==6)
      {
         policy_L=policy_L-l[1];
      }
      else if(Q[policy_L][policy_W]==7)
      {
         policy_W=policy_W-w[1];
      }
      else if(Q[policy_L][policy_W]==8)
      {
         policy_L=policy_L-w[1];
      }
   }
   cout<<"-----------------------------------ENDING-----------------------------------"<<"\n"<<"\n"<<"\n";
   select:
   short option;
   cout<<"重新開始請輸入 '1', 查詢請輸入 '2':";
   cin>>option;
   if(option==1)
   {           
      cout<<"\n"<<"\n"<<"\n"<<"\n"<<"<<<<<<<<<<在玩一次>>>>>>>>>>"<<"\n"<<"\n";
      goto start;
   }
   if(option==2)
   {
      goto search;
   } 
   if(option!=1&option!=2)
   {
      cout<<"錯誤! 請重新輸入!"<<endl;
      goto select;
   } 
   
   search:
   short num1,num2;
   cout<<"輸入欲查詢之長度:"; 
   cin>>num1;
   cout<<"輸入欲查詢之寬度:"; 
   cin>>num2;
   cout<<"F("<<num1<<","<<num2<<")="<<F[num1][num2]<<", "<<"Q("<<num1<<","<<num2<<")="<<Q[num1][num2]
   <<", "<<"G("<<num1<<","<<num2<<")="<<G[num1][num2]<<endl<<endl;
   goto select;
   
   system("pause");
   return 0;
}
