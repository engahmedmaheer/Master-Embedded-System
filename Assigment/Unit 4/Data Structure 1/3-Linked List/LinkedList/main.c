/*******************************************************************/
/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   LinkedList  		********************/
/*****************	 @Proj:    Student Data Base *******************/
/*****************   @SWC:     Data Structure	********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#include "stdio.h"
#include "stdint.h"
#include "conio.h"
#include "string.h"
#include "math.h"
#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdout);fflush(stdin)

struct Sdata
{
	int ID;
	char name[40];
	int height;
};

struct SStudent
{
	struct Sdata Student;
	struct SStudent* ptrNextStudent;
};

struct SStudent* gPtrFirstStudent = NULL;

//APIs
//Add Student
void AddStudent()
{
	struct SStudent* ptrNewStudent;
	struct SStudent* ptrLastStudent;
	char temp[40];
	//check if list is empty
	if (gPtrFirstStudent == NULL)
	{
		//create
		ptrNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
		//assign it to gPtrFirstStudent
		gPtrFirstStudent = ptrNewStudent;
	}
	//list contains records
	else
	{
		//find last record
		ptrLastStudent=gPtrFirstStudent;
		while(ptrLastStudent->ptrNextStudent)
		{
			ptrLastStudent=ptrLastStudent->ptrNextStudent;
		}
		ptrNewStudent=(struct SStudent*) malloc (sizeof(struct SStudent));
		ptrLastStudent->ptrNextStudent=ptrNewStudent;
	}
	DPRINTF("\nEnter the ID:");
	gets(temp);
	ptrNewStudent->Student.ID = atoi(temp);
	DPRINTF("\nEnter the student Full Name:");
	gets(ptrNewStudent->Student.name);
	DPRINTF("\nEnter height:");
	gets(temp);
	ptrNewStudent->Student.height= atoi(temp);
	ptrNewStudent->ptrNextStudent=NULL;
}

//delete
int DeleteStudent()
{
	char temp[40];
	int i , wanted_ID;
	DPRINTF("\nEnter Student ID to be Deleted: ");
	gets(temp);
	wanted_ID = atoi(temp);
	if(gPtrFirstStudent)
	{
		struct SStudent* ptrPrevStudent=NULL;
		struct SStudent* ptrSelectedStudent=gPtrFirstStudent;
		while(ptrSelectedStudent)
		{
			if(ptrSelectedStudent->Student.ID == wanted_ID)
			{
				if(ptrPrevStudent)
				{
					ptrPrevStudent->ptrNextStudent=ptrSelectedStudent->ptrNextStudent;
				}
				else
				{
					gPtrFirstStudent=ptrSelectedStudent->ptrNextStudent;
				}
				free(ptrSelectedStudent);
				return 1;
			}
			ptrPrevStudent=ptrSelectedStudent;
			ptrSelectedStudent=ptrSelectedStudent->ptrNextStudent;

		}

	}
	DPRINTF("\nID Not Found");
	return 0;
}
//delete all
void DeleteAll()
{
	struct SStudent* ptrCurrentStudent=gPtrFirstStudent;
	struct SStudent* ptrTemp;
	if(gPtrFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY List");
	}
	else
	{
		while(ptrCurrentStudent)
		{
			ptrTemp=ptrCurrentStudent;
			ptrCurrentStudent=ptrCurrentStudent->ptrNextStudent;
			free(ptrTemp);
		}
		gPtrFirstStudent=NULL;
	}
}
//view
void ViewStudents()
{
	int counter=0;
	struct SStudent* ptrCurrentStudent=gPtrFirstStudent;
	if(gPtrFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY List");
	}
	else
	{
		while(ptrCurrentStudent)
		{
			DPRINTF("\nRecord Number %d",counter+1);
			DPRINTF("\nID :%d",ptrCurrentStudent->Student.ID);
			DPRINTF("\nName: %s",ptrCurrentStudent->Student.name);
			DPRINTF("\nHeight: %d",ptrCurrentStudent->Student.height);
			ptrCurrentStudent=ptrCurrentStudent->ptrNextStudent;
			counter++;
		}
	}
}
//reverse
void reverse()
{
	if(gPtrFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY List");
	}
	else
	{
		struct SStudent* ptrCurrentStudent=gPtrFirstStudent->ptrNextStudent;
		struct SStudent* ptrPrevStudent=gPtrFirstStudent;
		struct SStudent* ptrNext=NULL;
		while(ptrCurrentStudent){
			ptrNext=ptrCurrentStudent->ptrNextStudent;
			ptrCurrentStudent->ptrNextStudent=ptrPrevStudent;
			ptrPrevStudent=ptrCurrentStudent;
			ptrCurrentStudent=ptrNext;
		}
		gPtrFirstStudent->ptrNextStudent=NULL;
		gPtrFirstStudent=ptrPrevStudent;

	}

}
//middle
void mid()
{
	int counter=0;
	struct SStudent* ptrCurrentStudent=gPtrFirstStudent;
	if(gPtrFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY List");
	}
	else
	{
		int mid =ceil(length_R(gPtrFirstStudent)/2);
		while(counter!=mid)
		{
			counter++;
			ptrCurrentStudent=ptrCurrentStudent->ptrNextStudent;
		}
		DPRINTF("\n\tMid of List");
		DPRINTF("\nID :%d",ptrCurrentStudent->Student.ID);
		DPRINTF("\nName: %s",ptrCurrentStudent->Student.name);
		DPRINTF("\nHeight: %d",ptrCurrentStudent->Student.height);
	}
}

//nth node
void GetNth()
{
	int count=0,wanted_node;
	char temp[10];
	struct SStudent* ptrCurrentStudent=gPtrFirstStudent;
	if(gPtrFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY List");
	}
	else
	{
		DPRINTF("\nEnter Nth position wanted");
		gets(temp);
		wanted_node=atoi(temp);
		while(wanted_node!=count)
		{
			ptrCurrentStudent=ptrCurrentStudent->ptrNextStudent;
			count++;
		}
		if(ptrCurrentStudent==NULL)
		{
			DPRINTF("\nNth position not found");
		}
		else
		{
			DPRINTF("\nID :%d",ptrCurrentStudent->Student.ID);
			DPRINTF("\nName: %s",ptrCurrentStudent->Student.name);
			DPRINTF("\nHeight: %d",ptrCurrentStudent->Student.height);
		}
	}
}
//length itrative
void length_I()
{
	int count=0;
	struct SStudent* ptrCurrentStudent=gPtrFirstStudent;
	if(gPtrFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY List");
	}
	else
	{
		while(ptrCurrentStudent)
		{
			count++;
			ptrCurrentStudent=ptrCurrentStudent->ptrNextStudent;
		}
		DPRINTF("length = %d",count);
	}
}
//length recersive
int length_R(struct SStudent*check)
{
	if(check)
		return 1+length_R(check->ptrNextStudent);
	else
		return 0;
}
//nth node from end
void nth_end()
{
	if(gPtrFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY List");
	}
	else
	{
		int end=length_R(gPtrFirstStudent);
		int index=0;
		struct SStudent* temp=gPtrFirstStudent;
		DPRINTF("\nenter the index from end :");
		scanf("%d",&index);
		index=end-index;
		while(index)
		{
			index--;
			temp=temp->ptrNextStudent;
		}
		DPRINTF("\nID :%d",temp->Student.ID);
		DPRINTF("\nName: %s",temp->Student.name);
		DPRINTF("\nHeight: %d",temp->Student.height);
	}


}

//detect loop
int loop()
{
	if(gPtrFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY List");
	}
	else
	{
		struct SStudent* ptrSlow;
		struct SStudent* ptrFast;
		ptrSlow=gPtrFirstStudent;
		ptrFast=gPtrFirstStudent;
		while(ptrSlow&&ptrFast&&ptrFast->ptrNextStudent)
		{
			ptrSlow=ptrSlow->ptrNextStudent;
			ptrFast=ptrFast->ptrNextStudent->ptrNextStudent;
			if(ptrSlow==ptrFast)
			{
				DPRINTF("\nThere is Loop");
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	char temp[40];
	while(1)
	{
		DPRINTF("\n============================");
		DPRINTF("\n\tChoose one of the following options ");
		DPRINTF("\n: Add student ");
		DPRINTF("\n: Delete student ");
		DPRINTF("\n: Delete all ");
		DPRINTF("\n: View students ");
		DPRINTF("\n: Reverse list ");
		DPRINTF("\n: Find Middle ");
		DPRINTF("\n: nth node ");
		DPRINTF("\n: List length ");
		DPRINTF("\n: List length ");
		DPRINTF("\n: Nth node from the end");
		DPRINTF("\n: Detect Loop");
		DPRINTF("\nEnter 0 to exit ");
		DPRINTF("\nEnter your option: ");
		gets(temp);
		DPRINTF("\n============================");
		switch(atoi(temp))
		{
		case 0: return 0; break;
		case 1: AddStudent();break;
		case 2: DeleteStudent();break;
		case 3: DeleteAll();break;
		case 4: ViewStudents();break;
		case 5: reverse();break;
		case 6: mid();break;
		case 7: GetNth();break;
		case 8: length_I();break;
		case 9: DPRINTF("length = %d",length_R(gPtrFirstStudent));break;
		case 10:nth_end();break;
		case 11:if(!loop())DPRINTF("\nNO LOOP");break;
		default:
			DPRINTF("\ninvalid entry");break;
		}
	}
	return 0;
}
