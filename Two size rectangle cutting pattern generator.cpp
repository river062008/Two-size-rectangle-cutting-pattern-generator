#include <iostream>
#include <cstring>
using namespace std;
int F[10001][10001],Q[10001][10001],G[10001][10001];

int main()
{
   cout<<"<<<<<<<<<     ���{�����Ѩ�ػݨD�ؤo�b�쪫�ƥ������ΤW���̨αƼ�     >>>>>>>>>";
   cout<<endl<<"                        version 3.       update:2018/04/28"<<endl<<endl<<endl<<endl;
   start:
   int v[2],l[2],w[2];
   int Length,Wedth;
   int N[8]; // [n1wx,n1wy,n1lx,n1ly,n2wx,n2wy,n2lx,n2ly] 
   int n=2;
   int a=0,Lset[10001];//a=Lset�̭����p��쪺�̫᪺�ƪ�����, Lset[a-1]��ܹB���̫᪺��, �]���}�C�q0�}�l 
   int b=0,Wset[10001];//a=Lset�̭����p��쪺�̫᪺�ƪ�����, Lset[a-1]��ܹB���̫᪺��, �]���}�C�q0�}�l
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
         cout<<"�п�J�� "<<i+1<<" ���ݨD�ؤo���������:"; 
         cin>>l[i];
         while(l[i]>10000)
         {
            cout<<"���~!�ƭȶ��p��10000"<<endl<<"�Э��s��J:";
            cin>>l[i];
         } 
         cout<<"�п�J�� "<<i+1<<" ���ݨD�ؤo���e�����:"; 
         cin>>w[i];
         while(w[i]>l[i])
         {
            cout<<"���~!�ƭȶ��p�󵥩����"<<endl<<"�Э��s��J:";
            cin>>w[i];
         } 
         cout<<"�п�J�� "<<i+1<<" ���ݨD�ؤo������(�έ��n):"; 
         cin>>v[i];
      }
//-------------------------------------------------------
   cout<<endl<<"�п�J�쪫�ƪO���������:"; 
   cin>>Length;
   while(Length>10000)
   {
      cout<<"���~!�ƭȶ��p��10000"<<endl<<"�Э��s��J:";
      cin>>Length;
   }
   cout<<"�Y�L�]�X�Ʀr�A�Э@�ߵ���!!\n��ܥ��b�B��normal length"<<endl; 
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
                     a=a+1;// a��̫�|�h1, �n����
                  }//------------------------------------------------------------- 
               }
            }
         }
      }
   }
   for(int i=0;i<a-1;i++) //�w�j�j�M�k, ���s�Ƨ�Lset�̭����� 
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
   cout<<"Normal Length�̭��@�� "<<a<<" �Ӽ�:"<<"\n";//�}�C�O�q0�}�l���Ĥ@�Ӽ�, a�Y���`�@�զX�ƪ��ƶq
   for(int i=0;i<a;i++)//Lset[a]=Length+1, �]���n����a-1�N�n�F 
   {
      cout<<Lset[i]<<", ";
   }
   cout<<endl;
//���j -------------------------------------------------------------------- 
   cout<<endl<<"�п�J�쪫�ƪO���e�����:"; 
   cin>>Wedth;
   while(Wedth>Length)
   {
      cout<<"���~!�ƭȶ��p�󵥩����"<<endl<<"�Э��s��J:";
      cin>>Wedth;
   }
   cout<<"�Y�L�]�X�Ʀr�A�Э@�ߵ���!!\n��ܥ��b�B��normal Width"<<endl; 
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
                     b=b+1;// a��̫�|�h1, �n����
                  }//-------------------------------------------------------------
               }
            }
         }
      }
   }
   for(int i=0;i<b-1;i++) //�w�j�j�M�k, ���s�Ƨ�Wset�̭����� 
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
   cout<<"Normal Width�̭��@�� "<<b<<" �Ӽ�:"<<"\n";//�}�C�O�q0�}�l���Ĥ@�Ӽ�, b�Y���`�@�զX�ƪ��ƶq
   for(int i=0;i<b;i++)//Wset[b]=Wedth+1, �]���n����b-1�N�n�F 
   {
      cout<<Wset[i]<<", ";
   }
   cout<<endl<<endl<<endl;
   system("pause");
//���j -------------------------------------------------------------------- 
   double START,END;
   START = clock();
   memset(F,0, sizeof(F));  //��l��F�Ȭ�0
   memset(Q,0, sizeof(Q));  //��l��Q�Ȭ�0
   memset(G,0, sizeof(G));  //��l��G�Ȭ�0
   memset(N,0, sizeof(N));  //��l�ƩҦ����k�����Ȭ��s
   for(int j=0;j<a;j++) //�ܼ�X�����W 
   {
      for(int k=0;k<b&k<=j;k++) //�ܼ�y�����W, &��ܨ�ӳ��n�����~��i�� 
      {
         cout<<endl<<endl<<"------------------------�ڬO���j�u�Ϲj�C�@��step off------------------------"<<endl<<endl<<"==============================================";
         cout<<"\n"<<"                 �� L="<<Lset[j]<<",W="<<Wset[k]<<" ��"<<"\n"<<"\n";
         cout<<"   --------------�U���k������--------------   "<<"\n";
         if(Wset[k]>=l[0])
         {
            N[0]=F[Lset[j]][Wset[k]-l[0]]+(Lset[j]/w[0])*v[0];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"��1�ؤ��k�G"<<N[0]<<"\n";
         }
         if(Lset[j]>=l[0])
         {
            N[1]=F[Lset[j]-l[0]][Wset[k]]+(Wset[k]/w[0])*v[0];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"��2�ؤ��k�G"<<N[1]<<"\n";
         }
         if(Wset[k]>=w[0])
         {
            N[2]=F[Lset[j]][Wset[k]-w[0]]+(Lset[j]/l[0])*v[0];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"��3�ؤ��k�G"<<N[2]<<"\n";
         }
         if(Lset[j]>=w[0])
         {
            N[3]=F[Lset[j]-w[0]][Wset[k]]+(Wset[k]/l[0])*v[0];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"��4�ؤ��k�G"<<N[3]<<"\n";
         }
         if(Wset[k]>=l[1])
         {
            N[4]=F[Lset[j]][Wset[k]-l[1]]+(Lset[j]/w[1])*v[1];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"��5�ؤ��k�G"<<N[4]<<"\n";
         }
         if(Lset[j]>=l[1])
         {
            N[5]=F[Lset[j]-l[1]][Wset[k]]+(Wset[k]/w[1])*v[1];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"��6�ؤ��k�G"<<N[5]<<"\n";
         }
         if(Wset[k]>=w[1])
         {
            N[6]=F[Lset[j]][Wset[k]-w[1]]+(Lset[j]/l[1])*v[1];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"��7�ؤ��k�G"<<N[6]<<"\n";
         }
         if(j>=w[1])
         {
            N[7]=F[Lset[j]-w[1]][Wset[k]]+(Wset[k]/l[1])*v[1];
            cout<<"   F("<<Lset[j]<<","<<Wset[k]<<"),"<<"\t"<<"\t"<<"��8�ؤ��k�G"<<N[7]<<"\n";
         }
         cout<<"   ----------------------------------------   "<<"\n"<<"\n";
         int maxN=0;
         for(int i=0;i<8;i++) //��M�̤j���Ȫ����k
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
               Q[Lset[j]][Wset[k]]=i+1; //�O��Q(X,Y), �O���u���@�ӳ̨�N�Ȫ��Ӥ��k, �[1���Ϥ��������8�� 
               if(i==0) //�O��G�� 
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
               if(i==1) //�O��G�� 
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
               if(i==2) //�O��G�� 
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
               if(i==3) //�O��G�� 
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
               if(i==4) //�O��G�� 
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
               if(i==5) //�O��G�� 
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
               if(i==6) //�O��G�� 
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
               if(i==7) //�O��G�� 
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
         cout<<"   ---------------�̤j�Ȥ��k---------------   "<<"\n"<<"   "; //��M�@�˦P���̤j���Ȫ����k 
         int findmaxN[8],g[8]={99999,99999,99999,99999,99999,99999,99999,99999}; //��W�[�a 
         int judgement=0; //��P���̤j�Ȫ�N 
         int findmin_g[8],min_g=9999,judgement_g=0; //g�p�G���@�˪�, �A��       
         for(int x=0;x<8;x++)
         {                  
            if(N[x]==maxN&N[x]>0) //&�������n....................................................���� 
            {
               cout<<x+1<<",";
               judgement=judgement+1;
               findmaxN[x]=1; 
            }                  
         }
         if(judgement>1) //���max�Ƥ��O�u���@�� 
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
            //cout<<endl<<"g[x]:"<<endl; //�ݭ���g[]�ȧC,  
            //for(int x=0;x<8;x++)
            //{
            //        cout<<g[x]<<", ";
            //}
            cout<<endl;
            for(int x=0;x<8;x++) //��Mg�}�C�̤p��
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
                  cout<<endl<<"   ��ܤ��Φ��Ƴ̤֪����k: "<<x+1<<endl; 
               }
            }
            for(int x=0;x<8;x++) //���ӥH�W�@�˦P���̤p�Ȫ�g�� 
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
               cout<<endl<<endl<<"   �P���Ȥ]�P�˨�̤֤��Φ��ƪ����k��(���"<<endl;
               cout<<"   �H�U���k�ҥi��AQ�ȱN�ļƭȳ̤j�����k):"<<endl<<"   "; 
               for(int x=0;x<8;x++)
               {
                  if(g[x]==min_g)
                  {
                     cout<<x+1<<", ";
                     Q[Lset[j]][Wset[k]]=x+1;//Q�p�G�O�E, �᭱����Q�Y����9�|�ɭPsection�W�[, �]���p�G���ۦP��g��, ���̤j�����ӰO���U�� 
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
   cout<<endl<<endl<<"                        �����H�W���B��ɪ��O���ȡ���"<<endl<<endl<<"-----------------------------------RESULT-----------------------------------";
   cout << endl << "�B��Ҫ�O���ɶ��G" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
   cout<<"�� L="<<Lset[a-1]<<",W="<<Wset[b-1]<<", l1:"<<l[0]<<",w1="<<w[0]<<", l2="<<l[1]<<",w2="<<w[1]<<" �ɦ��̨θ�:";
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
   cout<<"\n"<<"�Ĥ@���@�ϥΤF: "<<first_piece<<" ��\t�ĤG���@�ϥΤF: "<<second_piece<<" ��\t���n�Q�βv��: "<<ratio*100<<"%"<<"\n";
   cout<<"\n"<<"-----------------------------------POLICY-----------------------------------"<<"\n";
   policy_L=Lset[a-1],policy_W=Wset[b-1];
   while(policy_L>0&policy_W>0)
   {
      cout<<"F("<<policy_L<<","<<policy_W<<")="<<F[policy_L][policy_W]<<"\t��,��J�� ";
      if(Q[policy_L][policy_W]<5)
      {
         cout<<"1";
      }
      if(Q[policy_L][policy_W]>4)
      {
         cout<<"2";
      }
      cout<<" ���åH ";
      if(Q[policy_L][policy_W]==3||Q[policy_L][policy_W]==4||Q[policy_L][policy_W]>6)
      {
         cout<<"����";
      }
      if(Q[policy_L][policy_W]==5||Q[policy_L][policy_W]==6||Q[policy_L][policy_W]<3)
      {
         cout<<"�u��";
      }
      cout<<" ����V����� ";
      if(Q[policy_L][policy_W]==1||Q[policy_L][policy_W]==3||Q[policy_L][policy_W]==5||Q[policy_L][policy_W]==7)
      {
         cout<<"X�b";
      }
      if(Q[policy_L][policy_W]==2||Q[policy_L][policy_W]==4||Q[policy_L][policy_W]==6||Q[policy_L][policy_W]==8)
      {
         cout<<"Y�b";
      }
      cout<<" , �@�� ";
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
      cout<<" ��"<<endl;
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
   cout<<"���s�}�l�п�J '1', �d�߽п�J '2':";
   cin>>option;
   if(option==1)
   {           
      cout<<"\n"<<"\n"<<"\n"<<"\n"<<"<<<<<<<<<<�b���@��>>>>>>>>>>"<<"\n"<<"\n";
      goto start;
   }
   if(option==2)
   {
      goto search;
   } 
   if(option!=1&option!=2)
   {
      cout<<"���~! �Э��s��J!"<<endl;
      goto select;
   } 
   
   search:
   short num1,num2;
   cout<<"��J���d�ߤ�����:"; 
   cin>>num1;
   cout<<"��J���d�ߤ��e��:"; 
   cin>>num2;
   cout<<"F("<<num1<<","<<num2<<")="<<F[num1][num2]<<", "<<"Q("<<num1<<","<<num2<<")="<<Q[num1][num2]
   <<", "<<"G("<<num1<<","<<num2<<")="<<G[num1][num2]<<endl<<endl;
   goto select;
   
   system("pause");
   return 0;
}
