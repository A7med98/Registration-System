#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Student Student;
typedef struct Student* StudentPtr;
typedef struct Course Course;
typedef struct Course* CoursePtr;
typedef struct Node Node;
typedef struct Node* NodePtr;		
struct Student{
	int id;
	char* name ;
  double gpa;
  int ch;
};
struct Course{
	int id;
  char* code;
	char* name;
  int ch;
};
struct Node{
  StudentPtr StuPtr;
  CoursePtr CoursePtr;
	NodePtr next;
};NodePtr head = NULL;
void Register(StudentPtr sp,CoursePtr cp){
  NodePtr new_node = (NodePtr) malloc(sizeof(Node));
  new_node->StuPtr=sp;
  new_node->CoursePtr=cp;
  if(head == NULL||(*sp).gpa > (*head->StuPtr).gpa){
	  	new_node -> next = head;
      head = new_node;
	}
  else{
    NodePtr temp=head;
    while(temp -> next && ((*temp->next->StuPtr).gpa ) > (*sp).gpa){
      temp = temp -> next;
  }
  new_node -> next = temp -> next;
		temp -> next = new_node;
  
}
}
void Withdraw(StudentPtr sp,CoursePtr cp){
  NodePtr temp = head;
  int t=0;
  while(temp){
    if(temp->StuPtr==sp && temp->CoursePtr==cp){
      free(temp);
      t=1;
    }
    temp = temp -> next;
  }
  if(t==0){
    printf("this Student did not register this Course\n");
  }
}
void DisplayStudent(StudentPtr sp){
   NodePtr temp = head;
   int t=0;
  while(temp){
    if(temp->StuPtr==sp){
      printf("%s - %s -  %d - %d\n", (*temp->CoursePtr).name,(*temp->CoursePtr).code,(*temp->CoursePtr).id,(*temp->CoursePtr).ch);
      t=1;
    }
    temp=temp->next;
  }
  if(t==0){
    printf("this Student did not register to any Course\n");
  }
}
void DisplayCourse(CoursePtr cp){
   NodePtr temp = head;
   int t=0;
  while(temp){
    if(temp->CoursePtr ==cp){
      printf("%s - %d - %f - %d\n", (*temp->StuPtr).name,(*temp->StuPtr).id,(*temp->StuPtr).gpa,(*temp->StuPtr).ch);
    t=1;
    }
    temp=temp->next;
  }
  if(t==0){
    printf("this Course did not been registered by any Student\n");
  }
}

int main(void) {
  Student s[10];
  for(int i=0;i<10;i++){
    s[i].id=i+1;
  }
    s[0].gpa=3.0;
    s[1].gpa=3.4;
    s[2].gpa=3.3;
    s[3].gpa=3.1;
    s[4].gpa=3.2;
    s[5].gpa=2.2;
    s[6].gpa=2.33;
    s[7].gpa=3.44;
    s[8].gpa=4.0;
    s[9].gpa=3.7;
    s[0].name= "Ahmed Tarek";
    s[1].name= "Khaled Ahmed";
    s[2].name= "Ibrahim Nasrallah";
    s[3].name= "Tony Ibrahim";
    s[4].name= "Pierre-Emerick Aubameyang";
    s[5].name= "MO Salah";
    s[6].name= "Antoine Griezmann";
    s[7].name= "Ahmed Ahmed";
    s[8].name= "Mohamed Ahmed";
    s[9].name= "Ali Ali";
    s[0].ch=33;
    s[1].ch=66;
    s[2].ch=45;
    s[3].ch=24;
    s[4].ch=21;
    s[5].ch=12;
    s[6].ch=15;
    s[7].ch=30;
    s[8].ch=3;
    s[9].ch=33;        

  Course c[3];
  for(int i=0;i<3;i++){
    c[i].id=i+1;
    c[i].ch=3;
  }
  c[0].code="CS212000DB";
  c[1].code="CS212101IS";
  c[2].code="CS212221AI";
  c[0].name="CS1009";
  c[1].name="CS2121";
  c[2].name="CS2133";
  int x;
  while(x!=0){
  printf("1- Display all students. \n2- Display all courses. \n3- Register course to student. \n4- Withdraw course from student. \n5- Display Student Schedule. \n6- Display Course Schedule. \n0- Exit the program.\n");
  scanf("%d",&x);
  if(x==1){
    for(int i=0;i<10;i++){
    printf("%s - %d - %f - %d\n", s[i].name,s[i].id,s[i].gpa,s[i].ch);
    }
  }
  if(x==2){
    for(int i=0;i<3;i++){
    printf("%s - %s -  %d - %d\n", c[i].name,c[i].code,c[i].id,c[i].ch);
    }
  }
  if(x==3){
    int z;
    printf("Choose the Student id\n");
    scanf("%d",&z);
    int y;
    printf("Choose the Course id\n");
    scanf("%d",&y);
    Register(&s[z-1],&c[y-1]);
  }
  if(x==4){
    int z;
    printf("Choose the Student id\n");
    scanf("%d",&z);
    int y;
    printf("Choose the Course id\n");
    scanf("%d",&y);
    Withdraw(&s[z-1],&c[y-1]);
  }
  if(x==5){
    int z;
    printf("Choose the Student id\n");
    scanf("%d",&z);
    DisplayStudent(&s[z-1]);
  }
  if(x==6){
    int z;
    printf("Choose the Course id\n");
    scanf("%d",&z);
    DisplayCourse(&c[z-1]);
  }


}
}