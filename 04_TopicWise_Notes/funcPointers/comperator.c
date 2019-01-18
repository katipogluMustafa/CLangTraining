#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// sort integer scores, with the smallest first
int compare_scores(const void* score_a, const void* score_b){
  int a1 = *(int*)score_a;
  int b1 = *(int*)score_b;
  
  return a1 - b1;
}

// Sort integer scores, with the largest first.
int compare_scores_des(const void* score_a, const void* score_b){
 int a1 = *(int*)score_a;
 int b1 = *(int*)score_b;
 return b1-a1;
}

typedef struct{
  int width;
  int height;
} rectangle;

// Sort the rectangles in area order smallest first.
int compare_areas(const void* a, const void* b){
  rectangle* a1 = (rectangle*)a;
  rectangle* b1 = (rectangle*)b;
  int area_a = a1->width * a1->height;
  int area_b = b1->width * b1->height;

  return area_a - area_b;
}

// Sort a list of names in alphabetical order. case-sensitive.
int compare_names(const void* a, const void* b){
  char** a1 = (char**)a;
  char** b1 = (char**)b; 
  return strcmp(*a1,*b1);
}

// Sort the rectangles in area order, largest first;
int compare_areas_desc(const void* a, void* b){
  return compare_areas(b,a);
}

// Sort a list of names reverse alphabetical order case-sensitive.
int compare_names_desc(const void* a, const void* b){
  return compare_names(b,a);
}

int main()
{
  int scores[] = {543, 323, 32, 554, 11, 3, 112};
  int i;

  qsort(scores,7,sizeof(int), compare_scores_des);
  puts("These are the scores in order:");
  for(i = 0; i < 7; i++){
    printf("Score = %d\n", scores[i]);
  }
  char* names[] = {"Karen", "Mark", "Brett", "Molly"};
  puts("These are the names in order:");
  qsort(names, 4, sizeof(char*), compare_names);  
  for(i = 0; i < 4; i++){
    printf("Score = %s\n", names[i]);
  }
return 0;
}
