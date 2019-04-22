#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true  (1)
#define false (0)
typedef int boolean;

typedef struct user{
  int id;
  struct user* left;
  struct user* right;
  int friends[100];
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
            flag = false;		// Exit the loop
          }
        else				// if greater than node's id
          if( temp->right != NULL ) 
            temp = temp->right;		// go right
          else{
            temp->right = user;	 	// if right is null, put there
            flag = false;		// Exit the loop
          }
    }
  }
    
  return user; 
}

// Print the id-name-surname in increasing sorted order in the given tree
void printInOrder(User* head){
  if( head == NULL )
	return;
  printInOrder(head->left);
  printf("%d - %s %s\n",head->id, head->name, head->surname); 
  printInOrder(head->right);
}

// Search for a user in the tree 
// if found, returns the user
// if not found returns null
User* getUser(int id){
  User* temp = root;

  while( true ){     
    if( temp == NULL)
      return NULL;	 		// if the node we're at is null then not found return NULL
    if( temp->id == id )
      return temp; 			// if given id the same as the node's id then we found return the node
    else if( temp->id > id)
      temp = temp->left;		// if given id less go left
    else
      temp = temp->right;		// if given id greater go right  
  } 

}

// if the given id found in the tree prints the name-surname of the user and returns true to the caller
// if not found, returns false
boolean contains(int id){ 
  User* user = getUser(id);	// Search for user with given id
  if( user == NULL )		// if user is null then the person is not in the tree
    return false;		// return false to the caller

  // we found user, print it out
  printf("The tree contains %s %s\n", user->name, user->surname);  
return true;
}

// Returns true if the user to be deleted is successfully deleted
// otherwise returns false to the caller
boolean deleteUser(int id){
  if(root == NULL)
    return false;
  User *temp = root;		// Iterator
  User *tempParent = root;	// When iterating, parent will be stored
  User *user;			// Found user will be stored
  User *userParent;		// Found user's parent will be stored

  if( root->id == id){		// If the root is the one that we want to delete
   free(root);
   root = NULL;			
   return true;		 	// Deleted successfully
  }
  else				// If the root is not what we're looking for, continue searching
    while( true){		// Iterate forever, we'll exit the function when we delete the element
      if( temp->id < id )	// If id less then the node
  	if(temp->left == NULL)  // Check whether it exists or not 
            return false;	// if it does not exists, then we shall exit the function since we couldn't found 
          else{			// if left subtree exists
  	  tempParent = temp;	
  	  temp = temp->left;	// go left
  	}
      else if(temp->id > id)    // if id greater than the node
  	if(temp->right == NULL) // control left subtree
            return false;	// if it does not exists, exit since not found
          else{			// If right subtree exists
  	  tempParent = temp;   
  	  temp = temp->right;   // go right
  	}
      else{ 				// id matched with current node, the user to be deleted is found 
        userParent = tempParent;		
        user = temp;			// user represents the node that we need to delete	
        if(user->left == NULL){		// if only right child exists or no child exists
          user = user->right;		// make the user points to its right child
  	  free(temp);			// delete the right child, temp currently points to the user to be deleted
        }else if( user->right == NULL){ // if left child only exists or no child exists
  	  user = user->left;		// make the user points to its left child
  	  free(temp);			// delete the left child, temp currently points to the user to be deleted
        }else{				// if both childs exists, we need to find inorder successor and put into the place that we want to delete
  					// Okay, hold on, we're gonna find inorder successor
  	  temp = user->right;		// First go right
	  tempParent = user->right; 	// and record the place into tempParent
          while( temp->left != NULL ){  // As long as node's left is not null
  	    tempParent = temp;
  	    temp = temp->left;		// go left
  	  }	 
	  // we got ot of while loop, so this means we found the last NonNull left(stored inside temp variable)
  	  tempParent->left = NULL;		// first make the place of the temp variable as NULL, remember tempParent's left is stored in temp variable	
  	  // Here temp still points to the old children of tempParent
	  // We'll put this into the place that we want to delete so let's prepare the temp
  	  temp->left = user->left;		// first make the temp's left as user's left
  	  temp->right = user->right;		// and temp's right as user's right
	  // we currently don't exactly know whether $user is left of the $userParent or right of the $userParent 
  	  if( userParent->left == user )  	// if it is left of its parent 
  	    userParent->left = temp;		// just put parent's left the temp, the variable the we prepared to put there
  	  else if( userParent->right == user)	// if it is right of its parent
  	    userParent->right = temp;		// why not put the temp there ? :)
  	
	  free(user);				// Free the user now	
  	  return true;				// Successfully we deleted
        }
      }
    } 
}

// If friend found prints the friends of the given id 
void friends(int id){
  User* user = getUser(id);
  if( user == NULL || user->friends == NULL  || user->friendCount <= 0)
    return;
   
  User* currentFriend;
  int friendId;
  int friendCount = user->friendCount;
  int i;
  printf(" Friends Of %s:\n", user->name);
  for(i = 0; i < friendCount;i++ ){
    friendId = user->friends[i];					// get next friend id from the user's friends array
    currentFriend = getUser(friendId);					// search for the user in the tree, we assume we always find the user in the tree
    printf("---");
    printf("%s %s\n", currentFriend->name, currentFriend->surname);     // prints @NonNull friend
  }
}

// Prints @NonNull User
void printUser(User* user){
  printf("ID: %d\nName: %s\nSurname: %s",user->id, user->name, user->surname); 
  friends(user->id);
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
    printInOrder(user->left);	// Since left subtree less than the node, first print that part
    printInOrder(user->right);  // now print the other part so that overall output is in sorted order.
  }

}


// Print the users that has greater id than the input id 
void printGreater(int id){
  User* temp = root;
  while( true ){
    if( temp == NULL )
      return;
    else if( temp->id > id){
      printf("%d - %s %s\n",temp->id, temp->name, temp->surname); 
      printInOrder(temp->right);
      temp = temp->left;
    }else if( temp->id <= id)
      temp = temp->right;
  }
}


void fileInput(FILE* file){
  User* currentUser;
  char buffer[200];
  int id;
  char name[100];
  char surname[100];
  int user_friends[100];
  int friendsCount;
  char temp;
  int i;
  while( !feof(file)  ){
    // Take Id
    fscanf(file, "%d,", &id);
    // Take Name
    i = 0;
    while(  ( temp = fgetc(file) ) != ' ' && ( name[i++] = temp ) );
    name[i] = '\0';

    // Take Surname
    i = 0;
    while( ( ( temp = fgetc(file) ) != ',' && temp != '\n' ) && ( surname[i++] = temp ) );
    surname[i] = '\0';
    
    // If any friend exists, take them
    friendsCount = 0;
    if( temp == ',')
      while( fscanf(file, "%d", &user_friends[friendsCount++] ) != EOF  && (temp = fgetc(file)) == '-' );
    fscanf(file,"\n");								// Read line feed 

    currentUser = insertNewUser(id);		// insert new user into its sorted place with given id 
    strcpy(currentUser->name,name);		// fill name
    strcpy(currentUser->surname, surname);	// surname
    currentUser->friendCount = friendsCount;	// and friendCount fields
    for(int i = 0; i < friendsCount; i++)
      currentUser->friends[i] = user_friends[i];	// Copy each friend id into current user's friends field
//    friends(currentUser->id);
 
  }
}


void batchInputIntoTheTree(FILE* file){
/*  User* currentUser;		// Current user to be stored in the Tree
  int id;		
  char name[100];		// max 100 char name
  char* ptr;
  char surname[100];		// max 100 char surname
  char lastComma;		// for controlling friend input
  int friendss[100];		// store input friend ids
  int friendCount = 0;		// Number of friends that we've taken for the current user
  char temp;			// stores current character read from fgetc
  while( fscanf(file, "%d,%s %[^,\n\r]", &id, name,surname) != EOF){
    ptr = name;
    while( ptr )
    // Get The User Details 
    printf("ID= %d NAME= %s SURNAME= %s\n",id,name,surname);
      if( fgetc(file) == ',' ) 	// then we have friend input
        do{
          fscanf(file,"%d",&friendss[friendCount++]);       
	}while( ( temp = fgetc(file) ) != '-' && temp != '\n' && temp != '\r');		// \r control for windows new line
    currentUser = insertNewUser(id);		// insert new user into its sorted place with given id 
//    strcpy(currentUser->name,name);		// fill name
//    strcpy(currentUser->surname, surname);	// surname
    currentUser->friendCount = friendCount;	// and friendCount fields
    for(int i = 0; i < friendCount; i++)
      currentUser->friends[i] = friendss[i];	// Copy each friend id into current user's friends field
//    friends(currentUser->id);
  }
*/
  fileInput(file);
}


void printChoices(){
  printf("\n1) insertNewUser\n");
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
  int in;	// current choice for the menu
  int id;	// id input from the user
  root = NULL;
  FILE* file = fopen("Input.txt", "r");
  if( file == NULL)
    fprintf(stderr,"\nInput.txt couldn't open");
  else
    batchInputIntoTheTree(file);
  fclose(file);
   
  printf("*** Binary Operations ***\n");
  do{
    printChoices(); 
    printf("\nWhich operation do you want to perform : ");
    scanf("%d",&in);
    switch(in){
      case 0:								// Exit
	break;	
      case 1:								// insertNewUser
		printf("\nWhat is the ID of the new user? : ");
		scanf("%d",&id);
	 	User* user = insertNewUser(id);
		if( user != NULL ){
		  printf("\nWhat is the name the name of user? : ");
		  scanf("%s",user->name);
		  printf("\nWhat is the name the surname? : ");
		  scanf("%s",user->surname);
		}else
		  fprintf(stderr,"\nUser Already Found in the Tree");
	break;
      case 2:								// deleteUser
		printf("\nWhat is the ID of the user that you want to delete: ");
		scanf("%d", &id);
		if( !deleteUser(id) )
		  fprintf(stderr,"\nUnsuccessful deletion : User does not exists!\n");
	break;
      case 3:								// contains
		printf("\nWhat is the ID: ");
		scanf("%d", &id);
	 	if( contains(id) == false )
		  fprintf(stderr, "\nThe tree does not contain the id %d\n", id);	
	break;

      case 4:								// friends
		printf("\n What is the ID: ");
		scanf("%d", &id);
		friends(id);
	break;

      case 5:								// size
		if( root != NULL )
		  printf("\nSize of the Tree is %d", size(root) );
		else
		  printf("\nSize is 0\n");
	break;

      case 6:								// printNext
		printf("\nWhat is the ID: ");
		scanf("%d", &id);
		printNext(id);
	break;

      case 7:								// printGreater
		printf("\nWhat is the ID: ");
		scanf("%d", &id);
		printGreater(id);	
	break;
      case 8:								// printInOrder
	printInOrder(root);
	break;
      default:
	printf("\n !! Invalid Input\n");
    }
  }while( in != 0);
 
return 0;
}

