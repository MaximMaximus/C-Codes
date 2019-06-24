struct Object
{
  bool dead;
  Object* next;
  Object* previous;
};

Object * firstObject =NULL;
Object * lastObject =NULL;

Object* NewObject()
{
  if(firstObject==NULL)
  {
	firstObject=new Object;
	lastObject=firstObject;
	lastObject->next=NULL;
	lastObject->previous=NULL;
  }
  else
  {
	lastObject->next=new Object;
	lastObject->next->previous=lastObject;
	lastObject=lastObject->next;
	lastObject->next=NULL;
  }

  lastObject->dead=false;
  return lastObject;
}

void DeleteAllObject()
{
  Object* thisObject=firstObject;
  Object* deadObject=NULL;
  while(thisObject!=NULL)
  {
	deadObject=thisObject;
	thisObject=thisObject->next;
	delete deadObject;
  }
  firstObject=NULL;
  lastObject=NULL;
}

void RenderObject()
{
  Object* thisObject=firstObject;
  Object* deadObject=NULL;
  while(thisObject!=NULL)
  {
	if(thisObject->dead)
	{
	  deadObject=thisObject;
	  thisObject=thisObject->next;
	  if(firstObject==deadObject)
	  {
		firstObject=thisObject;
		if(thisObject!=NULL)
		{
		  thisObject->previous=NULL;
		}
	  }
	  else
	  {
		deadObject->previous->next=thisObject;
		if(thisObject!=NULL)
		{
		  thisObject->previous=deadObject->previous;
		}
	  }
	  if(lastObject==deadObject)
	  {
		lastObject=deadObject->previous;
	  }
	  delete deadObject;
	}
	else
	{
	  //Add you code here
	  //This is where your objects are rendered into the game world

	  thisObject=thisObject->next;
	}
  }
}

void UpdateObject()
{
  Object* thisObject=firstObject;
  while(thisObject!=NULL)
  {
	//Add your code here
	//This is where you define the behaviour of your objects

	thisObject=thisObject->next;
  }
}

//And a quick addition:
int CountObject()
{
  Object* thisObject=firstObject;
  int count=0;
  while(thisObject!=NULL)
  {
	count++;
	thisObject=thisObject->next;
  }
   return count;
}
