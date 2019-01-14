/* https://github.com/Rtoax/M-L/blob/219096ba7546fe06300b663d79264f98b596790e/NN-02-3layer-mnist/util/mnist-utils.c */

/* neural network to recognize handwritten single digit numbers image files. */

int getStandardDigitPixel(int num, int pixelId){
    
    char numStr[(28*28)+1];
    
    switch (num) {
            
        case 1:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............XXXX............");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            break;
            
        case 2:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXX...................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXXX...................");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            break;
            
        case 3:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            break;
            
        case 4:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXX.......XXXX.........");
            strcat(numStr,"....XXXX.......XXXX.........");
            strcat(numStr,"....XXXX.......XXXX.........");
            strcat(numStr,"....XXXXX......XXXX.........");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"...............XXXX.........");
            strcat(numStr,"...............XXXX.........");
            strcat(numStr,"...............XXXX.........");
            strcat(numStr,"...............XXXX.........");
            strcat(numStr,"...............XXXX.........");
            strcat(numStr,"...............XXXX.........");
            strcat(numStr,"...............XXXX.........");
            strcat(numStr,"...............XXXX.........");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            break;
            
        case 5:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            break;
            
        case 6:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXX...................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXX....................");
            strcat(numStr,"....XXXXX...................");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            break;
            
        case 7:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            break;
            
        case 8:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            break;
            
        case 9:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"....................XXXX....");
            strcat(numStr,"...................XXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            break;
            
            
        default:
            strcpy(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXX............XXXX....");
            strcat(numStr,"....XXXXX..........XXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,"....XXXXXXXXXXXXXXXXXXXX....");
            strcat(numStr,".....XXXXXXXXXXXXXXXXXX.....");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            strcat(numStr,"............................");
            
            break;
    }

    return (numStr[pixelId]=='X')?1:0;
    
}