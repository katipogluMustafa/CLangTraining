#include<stdio.h>
#include<string.h>

// Globals

char tracks[][80] = {
                        "I left my heart in Harvard Med School",
                        "Newark, Newark - a wondeful town",
                        "Dancing with a Dork ",
                        "From here to maternity",
                        "The gril from Iwo Jima",
                 };

// Funcs

void find_track(char search_for[]){
  int i;
  for(i = 0; i < 5; i++){
     if( strstr(tracks[i], search_for) ){
		printf("Track %i: '%s'\n",i,tracks[i]);	
     }
  }
}

int main(){

  char search_for[80];
  printf("Search for: ");
  scanf("%79s",search_for);
 
  /*
	if you try to use fgets instead of scanf like this
		fgets(search_for, 80, stdin);
	--> you won't get any output since the searched string will almost never be found on the track list.

	you'll need to delete the \n at the end of the input string by doing something like this
		search_for[strlen(search_for) - 1] = '\0';
  */

  
  find_track(search_for);

return 0;
}


