#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true  (1)
#define false (0)
typedef int boolean;

typedef struct user{
  struct user* left;
  struct user* right;
  int id;
  int* friends;
  int friendCount;
  char name[100];
  char surname[100];
} User;

User* root; 		// Root of the tree


User* createUser(int id){
  User* user = (User*) malloc(sizeof(User));
 
  user->left = NULL;
  user->right = NULL;
  user->id = id;
  user->friends = NULL;
  user->friendCount = -1;		// Shows friends arrays is not initialized yet
  strcpy(user->name,"Undefined");
  strcpy(user->surname,"Undefined");

return user;
}

User* insertNewUser(int id){
  User* user =  createUser(id);
  if( root == NULL )
    root = user;
  else{
    User* temp = root;
    boolean flag = true;
    
    while( flag ){
        if( temp->id == user->id )
            return NULL; 		// Already found in the tree, return NULL
        else if( temp->id > id) 	// if less than node's id
          if( temp->left != NULL)
            temp = temp->left;		// go left
          else{
            temp->left = user; 		// if left is null, put there
            flag = false;
          }
        else				// if greater than node's id
          if( temp->right != NULL ) 
            temp = temp->right;		// go right
          else{
            temp->right = user;	 	// if right is null, put there
            flag = false;
          }
      }
    }
    
  return user; 
}

User* deleteUser(int id){
  if(root == NULL)
    return NULL;
  User *temp = root;
  User *tempParent = root;
  User *user, *userParent;

  if( root->id == id){
   temp = root; 
   free(root);
 
  }
  else
    while( true){
      if( temp->id < id )
  	if( temp->left == NULL )
            return NULL;
          else{
  	  tempParent = temp;
  	  temp = temp->left;
  	}
      else if(temp->id > id)
  	if( temp->right == NULL )
            return NULL;
          else{
  	  tempParent = temp;
  	  temp = temp->right;
  	}
      else{ 				// id matched, user to be deleted is found 
        userParent = tempParent;		
        user = temp;			// user represents the node that we need to delete	
        if(user->left == NULL){		// if right child or no child exists
          user = user->right;		
  	free(temp);
        }else if( user->right == NULL){   // if left child only exists
  	user = user->left;
  	free(temp);
        }else{				// if both childs exists
  	tempParent = user->right;
  	temp = user->right;
          while( temp->left != NULL ){
  	  tempParent = temp;
  	  temp = temp->left;
  	}
  	tempParent->left = NULL;	
  	//temp still points to the old children of tempParent
  	temp->left = user->left;
  	temp->right = user->right;
  	if( userParent->left == user )
  	  userParent->left = temp;
  	else if( userParent->right == user)
  	  userParent->right = temp;
  	
  	temp = user;
  	free(user);
  	return temp;
        }
  
      }
  
    } 

return NULL;
}

void printUser(User* user){
  printf("ID: %d\nName: %s\nSurname: %s\n",user->id, user->name, user->surname);  
}

boolean contains(int id){ 
  User* user = getUser(id);
  if( user == NULL )
    return false;
  
  printUser(user);  
return true;
}

// If friend found prints 
void friends(int id){
  User* user = getUser(id);
  if( user == NULL || user->friends == NULL  || user->friendCount <= 0)
    return;
   
  int i;
  User* temp;
  printf("Friends of the %s ->>>>", user->name);
  for(i = 0; i < user->friendCount; i++){
    temp = getUser( user->friends[i] );
    printUser( temp ); 
  }
  
}

// Size of the Tree
int size(User* temp){
  if( temp == NULL )
    return 0;
  
  return size(temp->left) + 1 + size(temp->right);
}

// Print the subtree of the given id in increasing sorted order
void printNext(int id){
  User* user = getUser(id);
  if( user == NULL )
    fprintf(stderr,"The id is not found at the tree, we can not print its descendants...\n");
  else{
    printInOrder(user->left);
    printInOrder(user->right);
  }
}

User* getUser(int id){
  User* temp = root;

  while( true ){
    if( temp == NULL )
      return false; 		// if the node we're at is null then not found return NULL
    if( temp->id == id ){ 
      return temp;		// if given id the same as the node's id then we found return the node
    }
    else if( temp->id < id)
      temp = temp->left;	// if given id less go left
    else
      temp = temp->right;	// if given id greater go right
  } 
}

// Print 
void printGreater(int id){
  User* temp = root;
  while( true ){
    if( temp == NULL )
      return;
    else if( temp->id > id){
      temp = temp->left;
      printInOrder(temp->right);
    }else if( temp->id < id)
      temp = temp->right;
  }
}


// Print the users' id-name-surname in increasing sorted order in the whole tree
void printInOrder(User* head){
  if( head == NULL )
	return;
  printInOrder(head->left);
  printf("ID: %d\nName: %s\nSurname: %s\n",head->id, head->name, head->surname); 
  printInOrder(head->right);
}

void printChoices(){
  printf("1) insertNewUser\n");
  printf("2) deleteUser\n");
  printf("3) contains\n");
  printf("4) friends\n");
  printf("5) size\n");
  printf("6) printNext\n");
  printf("7) printGreater\n");
  printf("8) printInOrder\n");
  printf("0 For Exit\n");  
}

int main(){
  int in,id;
  printf("*** Binary Operations ***\n");
  root = NULL;
  do{
    printChoices(); 
    printf("\nWhich operation do you want to perform : ");
    scanf("%d",&in);
    switch(in){
      case 0:
	break;
      case 1:
	// insertNewUser
		printf("\nWhat is the ID of the new user? : ");
		scanf("%d",&id);
	 	User* user = insertNewUser(id);
		if( user != NULL ){
		  printf("\nWhat is the name the name of user? : ");
		  scanf("%s",user->name);
		  printf("\nWhat is the name the surname? : ");
		  scanf("%s",user->surname);
		}else
		  fprintf(stderr,"User Already Found in the Tree\n");
	break;
      case 2:
	// deleteUser
		printf("\nWhat is the ID of the user that you want to delete: ");
		scanf("%d", &id);
	 	User* deletedUser = deleteUser(id); 	
		if( deletedUser == NULL)
		  fprintf(stderr,"\nUnsuccessful deletion : User does not exists!\n");
		else
		  printf("\n%s %s successfully deleted\n", deletedUser->name, deletedUser->surname);
	break;
      case 3:
	// contains
		printf("\n What is the ID: ");
		scanf("%d", &id);
	 	if( contains(id) == false )
		  printf("\nThe tree does not contain the id %d\n", id);	
	break;

      case 4:
	// friends
		printf("\n What is the ID: ");
		scanf("%d", &id);
		// print friends
	break;

      case 5:
	// size
		if( root != NULL )
		  printf("Size of the Tree is %d\n", size(root) );
		else
		  printf("Size is 0\n");
	break;

      case 6:
	// printNext
		printf("\n What is the ID: ");
		scanf("%d", &id);
		printNext(id);
	break;

      case 7:
	// printGreater
		printf("\n What is the ID: ");
		scanf("%d", &id);
		printGreater(id);	
	break;
      case 8:
	// printInOrder
	printInOrder(root);
	break;
      default:
	printf("\n !! Invalid Input\n");
    }
  }while( in != 0);
 
return 0;
}

