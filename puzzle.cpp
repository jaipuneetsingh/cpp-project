#include<stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  int s[9];
  int children;
  int to_goal;
  int path[50];
  int pi;
  struct node *c1,*c2;
  struct node *c3,*c4;
};
typedef struct node board;
board *open[50],*found;
int front=-1,rear=-1;

void copyarray(int s[],int d[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    d[i]=s[i];
  }
}

int moves[9][5] =
{
  { 1, 3, -1, -1, 2 },
  { 0, 2, 4, -1, 3 },
  { 1, 5, -1, -1, 2 },
  { 0, 4, 6, -1, 3 },
  { 1, 3, 5, 7, 4 },
  { 2, 4, 8, -1, 3 },
  { 3, 7, -1, -1, 2 },
  { 4, 6, 8, -1, 3 },
  { 5, 7, -1, -1, 2 }
};

int level=-1,imp_count;
int flag=0;

void enq(board *b)
{
  if(rear==-1)
  {
    front++;
    open[++rear]=b;
  }
  else if(rear>=50)
  {
    printf("\nQueue is full.");
    getch();
    exit(0);
  }
  else
  {
    open[++rear]=b;
  }
}

void deq()
{
  front++;
  if(front>rear)
  {
   front=-1;
   rear=-1;
  }
  else if(front==-1)
   printf("\nQueue is empty.");
}

board* getboard()
{
  board *b=(board*)malloc(sizeof(board));
  if(b==NULL)
  {
    printf("\nMemory underflow.");
    getch();
    exit(0);
  }
  else
  {
  b->children=0;
  b->to_goal=0;
  b->pi=0;;
  b->c1=NULL;
  b->c2=NULL;
  b->c3=NULL;
  b->c4=NULL;
  return b;
  }
  return NULL;
}

void printboard(board *b)
{
  int i,c=0;
  printf("\n");
  for(i=0;i<9;i++)
  {
    printf(" %d ",b->s[i]);
    if(c==2)
    {
     printf("\n");
     c=0;
    }
    else
     c++;
  }
  getch();
}

void makemove(board *init,board *c,int mi,int ni)
{
    int i,j,temp;
    for(i=0;i<9;i++)
    {
      c->s[i]=init->s[i];
    }
    temp=c->s[mi];
    c->s[mi]=c->s[moves[mi][ni]];
    c->s[moves[mi][ni]]=temp;
}

void is_on_path(board *goal,board *c)
{
  int i,cnt=0;
  for(i=0;i<9;i++)
  {
    if(goal->s[i]==c->s[i])
      cnt++;
  }
  imp_count=cnt;
}

int is_prev(board *cur,board *prev)
{
  int i,cnt=0;
  for(i=0;i<9;i++)
  {
    if(cur->s[i]==prev->s[i])
      cnt++;
  }
  if(cnt==9)
   return 0;
  else
   return 1;
}

void spantree(board *init)
{
  int i,j,mi,ni=-1;


  for(j=0;j<9;j++)
  {
     if(init->s[j]==0)
     {
       mi=j;
       break;
     }
  }

  level++;
  if(level==5)
  {
    level--;
    return;
  }
  else
   init->children=moves[mi][4];

  for(i=0;i<init->children;i++)
  {
    board *temp=getboard();

    for(j=0;j<9;j++)
    {
     if(init->s[j]==0)
     {
       mi=j;
       break;
     }
    }

    for(j=0;j<4;j++)
    {
    if(moves[mi][j]!=-1 && j>ni)
    {
     ni=j;
     break;
    }
    }

    switch((i+1))
    {
     case 1:
       init->c1=temp;
       copyarray(init->path,temp->path,init->pi);
       temp->pi=init->pi;
       temp->path[(temp->pi)++]=1;
       makemove(init,init->c1,mi,ni);
       spantree(init->c1);
       break;
     case 2:
       init->c2=temp;
       copyarray(init->path,temp->path,init->pi);
       temp->pi=init->pi;
       temp->path[(temp->pi)++]=2;
       makemove(init,init->c2,mi,ni);
       spantree(init->c2);
       break;
     case 3:
       init->c3=temp;
       copyarray(init->path,temp->path,init->pi);
       temp->pi=init->pi;
       temp->path[(temp->pi)++]=3;
       makemove(init,init->c3,mi,ni);
       spantree(init->c3);
       break;
     case 4:
       init->c4=temp;
       copyarray(init->path,temp->path,init->pi);
       temp->pi=init->pi;
       temp->path[(temp->pi)++]=4;
       makemove(init,init->c4,mi,ni);
       spantree(init->c4);
       break;
     default:
       printf("\nNot able to allocate childs.");
    }

  }
     level--;
     return;
}

int solve_by_bfs(board *prev,board *init,board *goal)
{
  int i,j,mi,ni=-1,s1;

  if(front>rear && flag==0)
  {
    return 0;
  }
  else if(front>rear && flag==1)
  { return 1; }

  for(i=0;i<9;i++)
  {
    if(init->s[i]==0)
    {
       mi=i;
       break;
    }
  }

  for(i=0;i<init->children;i++)
  {
    for(j=0;j<4;j++)
    {
    if(moves[mi][j]!=-1 && j>ni)
    {
     ni=j;
     break;
    }
    }

    switch((i+1))
    {
     case 1:
       is_on_path(goal,init->c1);
       if(imp_count==9)
       {
    init->c1->to_goal=1;
    init->c1->path[(init->c1->pi)++]=-1;
    found=init->c1;
    return 1;
       }
       else
       {
     s1=is_prev(prev,init->c1);
     if(s1==1 && init->c1->children!=0)
     {
      enq(init->c1);
     }
       }
       break;
     case 2:
       is_on_path(goal,init->c2);
       if(imp_count==9)
       {
    init->c2->to_goal=1;
    init->c2->path[(init->c2->pi)++]=-1;
    found=init->c2;
    return 1;
       }
       else
       {
     s1=is_prev(prev,init->c2);
     if(s1==1 && init->c2->children!=0)
     {
     enq(init->c2);
     }
       }
       break;
     case 3:
       is_on_path(goal,init->c3);
       if(imp_count==9)
       {
    init->c3->to_goal=1;
    init->c3->path[(init->c3->pi)++]=-1;
    found=init->c3;
    return 1;
       }
       else
       {
     s1=is_prev(prev,init->c3);
     if(s1==1 && init->c3->children!=0)
     {
      enq(init->c3);
     }
       }
       break;
     case 4:
       is_on_path(goal,init->c4);
       if(imp_count==9)
       {
    init->c4->to_goal=1;
    init->c4->path[(init->c4->pi)++]=-1;
    found=init->c4;
    return 1;
       }
       else
       {
     s1=is_prev(prev,init->c4);
     if(s1==1 && init->c4->children!=0)
     {
      enq(init->c4);
     }
       }
       break;
     default:
       printf("\nNot able to MOVE.");
    }
  }

     deq();
     s1=is_prev(prev,open[front]);
     if(s1==1)
     {
     flag=solve_by_bfs(init,open[front],goal);
     open[front]->to_goal=flag;
     if(flag==1)
      return 1;
     else
      return 0;
     }

     return 0;
}

void getpath(board *init,board *b)
{
  int i=0;
  int c=b->path[i++];
  board *p=init;

  while(c!=-1)
  {

     switch(c)
     {
      case 1:
         printboard(p->c1);
         getch();
         p=p->c1;
         break;
      case 2:
         printboard(p->c2);
         getch();
         p=p->c2;
         break;
      case 3:
         printboard(p->c3);
         getch();
         p=p->c3;
         break;
      case 4:
         printboard(p->c4);
         getch();
         p=p->c4;
         break;
      default:
         printf("\nPath error.");
     }

    c=b->path[i++];
      }
}

void printpuzzle(board *b)
{
  int i;
  for(i=0;i<4;i++)
  {
   switch((i+1))
   {
    case 1:
      if(b->c1!=NULL && b->c1->to_goal==1)
      {
    printboard(b->c1);
    getch();
    printpuzzle(b->c1);
      }
      break;
    case 2:
      if(b->c2!=NULL && b->c2->to_goal==1)
      {
    printboard(b->c2);
    getch();
    printpuzzle(b->c2);
      }
      break;
    case 3:
      if(b->c3!=NULL && b->c3->to_goal==1)
      {
    printboard(b->c3);
    getch();
    printpuzzle(b->c3);
      }
      break;
    case 4:
      if(b->c4!=NULL && b->c4->to_goal==1)
      {
    printboard(b->c4);
    getch();
    printpuzzle(b->c4);
      }
      break;
     default:
       return;
   }
  }
}

int main()
{
  board *init,*goal;
  int i,j,t[9];
  clrscr();
  init=getboard();
  printf("\nEnter initial state for 8-puzzle problem(order:left to right and top to bottom):\n");

  for(i=0;i<9;i++)
   scanf("%d",&init->s[i]);

  int cnt=0;
  for(i=0;i<9;i++)
  {
    int lcnt=0;
    for(j=i+1;j<9;j++)
    {
     if(init->s[j]<init->s[i] && init->s[j]!=0)
       lcnt++;
    }
    cnt=cnt+lcnt;
  }
  goal=getboard();
  printf("\ncount:%d\n",cnt);
  if((cnt%2)==0)
  {
    goal->s[0]=0;
    goal->s[1]=1;
    goal->s[2]=2;
    goal->s[3]=3;
    goal->s[4]=4;
    goal->s[5]=5;
    goal->s[6]=6;
    goal->s[7]=7;
    goal->s[8]=8;
  }
  else
  {
    goal->s[0]=1;
    goal->s[1]=2;
    goal->s[2]=3;
    goal->s[3]=8;
    goal->s[4]=0;
    goal->s[5]=4;
    goal->s[6]=7;
    goal->s[7]=6;
    goal->s[8]=5;

  }
  printf("\nYour goal state is:\n");
  printboard(goal);
  printf("\nYour inital state is:\n");
  printboard(init);
  printf("\nPress any key to move towards the goal state...\n");
  getch();
  is_on_path(goal,init);
  init->to_goal=1;
  enq(init);
  spantree(init);
  flag=solve_by_bfs(init,init,goal);
  if(flag==1)
  {
  getpath(init,found);
  getch();
  printf("\nYour goal state is reached.");
  getch();
  }
  else
  {
   printf("\nToo complex problem. Please try again.");
   getch();
  }

  return 0;
}