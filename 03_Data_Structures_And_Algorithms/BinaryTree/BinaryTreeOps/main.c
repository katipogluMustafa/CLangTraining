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
  strcpy(user->name,"Undefined");	// In case user name-surname not specified, we put Undefined
  strcpy(user->surname,"Undefined");

return user;
}

User* insertNewUser(int id){
  User* user =  createUser(id);		// Create a user with given id by using factory function
  if( root == NULL )			// If root is null then make the new node as root
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
  printf("\nThe tree contains %s %s\n", user->name, user->surname);  
return true;
}

// Gets the user that we want to replace when deleting a user
// We break the connection with the user and its parent when returning since we'll put the user anywhere else
// if find a user to be put in the place returns the user otherwise returns NULL but in both case we'll use the return value in the caller
User* getInOrderSuccessor(User* user){
  if(user == NULL)		// if user == NULL, then we couldn't find a successor return NULL
    return NULL;
  User* ptr;
    
  User* ptrParent = user;	// save user's parent
  ptr = user->right;		// go right for once
  while( ptr->left != NULL){  // as long as left is not not, go left
    ptrParent = ptr;
    ptr = ptr->left;
  }

  // Now we have inorder successor at hand 
  if( ptrParent->left == ptr)	// check whether ptr left of its parent or right of its parent
    ptrParent->left = NULL;   // then break the connection between parent and user
  else
    ptrParent->right = NULL;

return ptr;			// return the user that you find as inorder sucessor
}

// Delete the user with given id from globally defined tree
// on Sucess returns true
// otherwise false
boolean deleteUser(int id){
  if(root == NULL)
    return false;

  User* inOrderSuccessor;  
  User* temp, *temp2;
  User* tempParent;

  if(root->id == id){					// if the root is the one that we want to delete
     if( root->left == NULL){				// if left child not exists, make right as root
       temp = root->right;
       free(root);
       root = temp;
       return true;
     }else if( root->right == NULL){			// if right child not exists, make left as root
       temp = root->left;
       free(root);
       root = temp;
       return true;
     }else{						// if two children exists, then find inOrderSuccessor(smallest element of right subtree)
       inOrderSuccessor = getInOrderSuccessor(root);	// get in order sucessor
       inOrderSuccessor->left = root->left;		// make its left and right as root's left and right
       inOrderSuccessor->right = root->right;	
       temp = root;					// save the root into temp so that later we can free it
       root = inOrderSuccessor;				// update the root as inOrderSucessor
       free(temp);					// free the old root
    return true;	
     }
  }
  else{							// if the one we want to delete is not the root					
    temp = root;				
    while( true ){					// iterate forever
      if( temp == NULL)					// if current user is null then we couldn't find the user, return false
        return false;
      else if( temp->id > id){				// if given id is less then the current node, go left
        tempParent = temp;				// don't forget to record its parent
        temp = temp->left;  	
      }else if( temp->id < id){				// if greater, go right
        tempParent = temp;
        temp = temp->right;
      }else{						// we found the id that we want to delete
        if( temp->left == NULL){			// if only right child exists or no child exists, then put right child into its place when deleting 
          temp2 = temp->right;
	  if( tempParent->left == temp ){
  	    tempParent->left = temp2;
    	  }else{
            tempParent->right = temp2;
	  }
          free(temp);
          return true; 
        }else if( temp->right == NULL){		  	// if only left child exists or no child exists, then put left child into its place when deleting
 	  temp2 = temp->left; 
	  if( tempParent->left == temp ){
  	    tempParent->left = temp2;
    	  }else{
            tempParent->right = temp2;
	  }
          free(temp);
          return true; 
        }else{ 						// else find inOrderSucessor and put that into the place that we get after deleting
          inOrderSuccessor = getInOrderSuccessor(temp);	// get inOrderSucessor
          if(inOrderSuccessor != NULL){			// if it is not null then put the old connections of currentNode into inOrderSucessor
            inOrderSuccessor->left = temp->left;
            inOrderSuccessor->right = temp->right;
          }
          // Find out whether temp is left or right child of its parent
          if( tempParent->left == temp ){
              tempParent->left = inOrderSuccessor;	// then replace the temp's place with inOrderSucessor
              free(temp);					// free the the user that you want to delete
          }else{
              tempParent->right = inOrderSuccessor;
              free(temp);
          }
	}
        return true; 					// we deleted successfully, return true
      }
    }
 
  }

return false;
}

// If friend found prints the friends of the given id 
void friends(int id){
  User* user = getUser(id);						// search and get the user with given id
  if( user == NULL || user->friends == NULL  || user->friendCount <= 0) // if user doesn't exists or doesn't have friend, just return, nothing to do
    return;
   
  User* currentFriend;							// Current friend that we want to print
  int friendId;								// currentFriend id
  int friendCount = user->friendCount;					// number of friends of the user that we found
  int i;								// iterator
  printf(" Friends Of %s:\n", user->name);				// we're gonna print the user's friends
  for(i = 0; i < friendCount;i++ ){					// iterate over friends 
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
// Returns size of the tree by recursively traversing the tree
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
    else if( temp->id > id){						// whenever we need to go left
      printf("%d - %s %s\n",temp->id, temp->name, temp->surname); 	// first print the current user
      printInOrder(temp->right);					// and its right sub tree
      temp = temp->left;						// then go left
    }else if( temp->id <= id)
      temp = temp->right;
  }
}

// Takes user input from the given file pointer
void fileInput(FILE* file){
  User* currentUser;				// Current user that we're inserting into the tree
  int id;					// current user id
  char name[100];				// current user name
  char surname[100];				// current user surname
  int user_friends[100];			// current user friends
  int friendsCount;				// current user friends count
  char temp;					// to check transitions from one field to the other, like ',' '-' '\n'
  int i;					// iterator
  while( !feof(file)  ){			// While we haven't reach EOF
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
    if( temp == ',' )
      while( fscanf(file, "%d", &user_friends[friendsCount++] ) != EOF  && (temp = fgetc(file)) == '-' );
    fscanf(file,"\n");	// Read line feed 

    currentUser = insertNewUser(id);		// insert new user into its sorted place with given id 
    strcpy(currentUser->name,name);		// fill name
    strcpy(currentUser->surname, surname);	// surname
    currentUser->friendCount = friendsCount;	// and friendCount fields
    for(int i = 0; i < friendsCount; i++)
      currentUser->friends[i] = user_friends[i];	// Copy each friend id into current user's friends field 
  }
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
  int in;								// current choice for the menu
  int id;								// id input from the user
  root = NULL;								// Start as root NULL

  FILE* file = fopen("Input.txt", "r");					
  if( file == NULL)
    fprintf(stderr,"\nInput.txt couldn't open");
  else
    fileInput(file);							// Take input from Input.txt
  fclose(file);								// free the resources of the Input.txt
   
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
		  fprintf(stderr,"\nUser Already Found in the Tree\n");
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
		  printf("\nSize of the Tree is %d\n", size(root) );
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

