#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct my_struct
{
    char data[50];
} key[100],iden[100],ope[100];
int isKeyword(char s[])
{
   char keyword[32][10]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
    int i, flag = 0;
	for(i = 0; i < 32; i++)
    {
		if(strcmp(keyword[i],s)==0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int isIdentifier(char s[],int len)
{
    int i,j,flag=1;
    for(i=0;i<len;i++)
    {
        if( isdigit(s[0]) || !(isalnum(s[i]) || s[i]=='_'))
            return 0;
    }
    return flag;
}
int isOperator(char s[])
{
    char operators[17][4]={"+","-","*","/","%","++","--","==","=",">","<","<=",">=","!=","&&","||","!"};
    int i, flag = 0;
	for(i = 0; i < 17; i++)
    {
		if(strcmp(operators[i],s)==0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
main()
{
    freopen("input.txt","r",stdin);
    int i,j,k,l,x,y,te,keyin=0,idenin=0,opein=0;
    char str[1000],temp[20];
    while(scanf("%[^\n]s",str)==1)
    {
        getchar();
        l=strlen(str);
        for(i=0;i<l;i++)
        {
            if(isalnum(str[i]))
            {
                te=0;
                temp[te++]=str[i];
                for(j=i+1;j<l;j++)
                {
                    if(isalnum(str[j]))
                        temp[te++]=str[j];
                    else
                    break;
                }
                temp[te]='\0';
                i=j-1;
                if(isKeyword(temp))
                {
                    int x,flag=0;
                    for(x=0;x<keyin;x++)
                    {
                        if(strcmp(temp,key[x].data)==0)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                        strcpy(key[keyin++].data,temp);
                }

                else if(isIdentifier(temp,te))
                {
                    int x,flag=0;
                    for(x=0;x<idenin;x++)
                    {
                        if(strcmp(temp,iden[x].data)==0)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                        strcpy(iden[idenin++].data,temp);
                }
            }
            else if(str[i]!=' ')
            {
                te=0;
                temp[te++]=str[i];
                for(j=i+1;j<l;j++)
                {
                    if(isalnum(str[j]) || str[j]==' ' || str[j]==';')
                        break;
                    else
                        temp[te++]=str[j];
                }
                temp[te]='\0';
                i=j-1;
                if(isOperator(temp))
                {
                    int x,flag=0;
                    for(x=0;x<opein;x++)
                    {
                        if(strcmp(temp,ope[x].data)==0)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        strcpy(ope[opein++].data,temp);
                    }
                }
            }

        }

    }
    if(keyin)
    {
        printf("Keyword:  ");
        for(i=0;i<keyin;i++)
            printf("%s  ",key[i].data);

        printf("\n\n");
    }
    if(idenin)
    {
        printf("Identifier:  ");
        for(i=0;i<idenin;i++)
            printf("%s  ",iden[i].data);
        printf("\n\n");
    }
    if(opein)
    {
        printf("Operator:  ");
        for(i=0;i<opein;i++)
            printf("%s  ",ope[i].data);
        printf("\n\n");
    }


    return 0;
}
