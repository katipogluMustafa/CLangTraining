#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main( int argc, char* argv[] ){

  char* feeds[] = {
  		    "https://www.wired.com/feed/rss",	    
  		    "https://www.wired.com/feed/category/security/latest/rss",
		    "https://www.wired.com/feed/category/transportation/latest/rss",
		    "https://www.wired.com/feed/category/backchannel/latest/rss",
		    "http://feeds.abcnews.com/abcnews/usheadlines",
		    "http://rss.cnn.com/rss/cnn_topstories.rss",
		    "http://www.theguardian.com/world/usa/rss",
		    "http://www.latimes.com/world/rss2.0.xml",
		    "http://www.newyorker.com/feed/news",
		    "http://www.politico.com/rss/Top10Blogs.xml",
		    "http://feeds.feedburner.com/AtlanticNational",
		    "http://www.rollcall.com/rss/all_news.xml",
		    "http://feeds.feedburner.com/motherjones/Polities",
		    "http://dailycaller.com/section/politics/feed/",
		    "http://rss.sciam.com/ScientificAmerican-Global",
		    "http://rss.nytimes.com/services/xml/rss/nyt/Space.xml",
		    "http://time.com/tech/feed/",
		    "http://www.gamasutra.com/static2/rssfeeds.html",
		    "http://rss.canoe.com/Money/home.xml",
		    "http://rss.canada.com/get/?F7523",
		    "http://www.thestar.com/feeds.articles.entertainment.rss",
		    "http://feeds.bbci.co.uk/news/world/asia/rss.xml",
  		  };
  int times = 22;
  char* phrase = argv[1];
  int i;
  
  for(i = 0; i < times; i++){
    	  
    char var[255];
    sprintf(var, "RSS_FEED=%s", feeds[i]);
    
    // let's construct the environment array
    char* vars[] = {var, NULL};
    
    // First let's fork() to clone the process.
    pid_t pid = fork();
    if( pid == -1  ){   // If fork() returns -1 there was a problem cloning the process.
      fprintf(stderr, "Can't fork proscess: %s\n", strerror(errno) );
      return 1;
    }    
    
    if(!pid){ 		// If fork() returnes 0, the code is running in the child process
      
      if(execle( "/usr/bin/python", "/usr/bin/python","./rssgossip.py" , phrase ,NULL, vars ) == -1){
      	  fprintf(stderr, "Can't run sciprt: %s\n", strerror(errno));
	  return 1;
      }

    }

  }


return 0;
}
