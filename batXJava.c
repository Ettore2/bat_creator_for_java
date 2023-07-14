#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 200
#define REGISTER_FILE_NAME "created bat register.txt"

int main (int argn,char *argv[]){//

    int i,j,k;
    int inaguageId;
    char mainPath[MAX_STRING_LENGTH +1],mainName[MAX_STRING_LENGTH +1],outputDirectory[MAX_STRING_LENGTH +1],outputName[MAX_STRING_LENGTH +1];
    char directoryForBatFile[MAX_STRING_LENGTH +1], mainClassName[MAX_STRING_LENGTH +1],outputFilePath[MAX_STRING_LENGTH*2+6]={""};
    
    FILE *pFile;
    printf("%s\n",argv[0]);
    


    //get the linguage for running the program
    printf("\n0 = English \n1 = italiano");
    printf("\n: ");
    scanf("%d",&inaguageId);
    fflush(stdin);


    //get project Main class dyrectory
    switch(inaguageId){
    	case 0:
    		printf("inser the directory of the .clas file that contain the main (use \\) (max %d letters)\n",MAX_STRING_LENGTH);
    		break;
    	case 1:
    		printf("\ninserici la directory del file .clas che contiene il main (usa \\) (max %d lettere)\n",MAX_STRING_LENGTH);	
    		break;
	}
    scanf("%[^\n]s",&mainPath);
    fflush(stdin);
    
    printf("\nmainPath: %s",mainPath); // debug

    //get output dyrectory
    switch(inaguageId){
    	case 0:
    		printf("inser the directory for output file (use \\) (max %d letters)\n",MAX_STRING_LENGTH);
    		break;
    	case 1:
    		printf("\ninserici la directory per il file di output (usa \\) (max %d lettere)\n",MAX_STRING_LENGTH);
    		break;	
	}
    scanf("%[^\n]s",&outputDirectory);
    fflush(stdin);


    //get output file name
    switch(inaguageId){
    	case 0:
    		printf("inser the output file name (the file will be called name.bat) (max %d letters)\n",MAX_STRING_LENGTH);
    		break;
    	case 1:
    		printf("\ninserici la dell file di output (il file sara chiamato nome.bat) (max %d lettere)\n",MAX_STRING_LENGTH);
    		break;	
	}
    scanf("%[^\n]s",&outputName);
    fflush(stdin);
    strcat(outputName,".bat");
    
//--------------------------------------------------------------------------------------------end of data gaining

    //create the string that describe the output file
    strcat(outputFilePath,outputDirectory);
    strcat(outputFilePath,"\\");
    strcat(outputFilePath,outputName);

//-------------------------------------------------------------------------------------------------end of data elaboration

    //find the lasl "\" and the last "." in mainPath
    j = 0;
    k = 0;
    for(i = 0; i < MAX_STRING_LENGTH; i++){
        if(mainPath[i] == '\\'){
            j = i;
        }
        if(mainPath[i] == '.'){
            k = i;
        }
    }

    //create the string for the cd of the .bat file
    for(i = 0; i < j; i++){
        directoryForBatFile[i] = mainPath[i];
    }
    directoryForBatFile[i] = '\0';

    //get the name of the main class (without the .class)
    i = 0;
    j++;
    while(j < k){
        mainClassName[i] = mainPath[j];

        i++;
        j++;
    }
    mainClassName[i] = '\0';

    //create the bat file
    pFile=fopen(outputFilePath,"w");
    
    
    fprintf(pFile,"cd \"%s\"\njava \"%s\"\npause",directoryForBatFile,mainClassName);//ci scvrivo le istruzioni
    fclose(pFile);
    

//---------------------------------------------------------------------------------------------------have created the output file

    //update the register of bat created
    pFile=fopen(REGISTER_FILE_NAME,"a");
    switch(inaguageId){
    	case 0:
    fprintf(pFile,"\n\ncreated file: %s\n",outputName);
    fprintf(pFile,"\nin the directory: %s\n",outputDirectory);
    fprintf(pFile,"that run the file: \"%s\"\n",mainPath);
    fprintf(pFile,"-record end-");
    		break;
    	case 1:
    fprintf(pFile,"\n\ncreato file: %s\n",outputName);
    fprintf(pFile,"\nnella directory: %s\n",outputDirectory);
    fprintf(pFile,"che avvia il file: \"%s\"\n",mainPath);
    fprintf(pFile,"-fine record-");
    		break;	
	}
    fclose(pFile);


    //screen output
    switch(inaguageId){
    	case 0:
    printf("\n\ncreated file: %s\n",outputName);
    printf("in the directory: %s\n",outputDirectory);
    printf("that run the file: \"%s\"\n",mainPath);
    printf("-end of the profram-");
    		break;
    	case 1:
    printf("\n\ncreato file: %s\n",outputName);
    printf("nella directory: %s\n",outputDirectory);
    printf("che avvia il file: \"%s\"\n",mainPath);
    printf("-fine del programma-");
    		break;	
	}


    printf("\nfine\n");
    system("pause");
}//fine main