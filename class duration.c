#include<stdio.h>
struct time{
    char s[20];
    int h,m;
};
main()
{
    struct time st,et,cd;
    FILE *start,*end, *classduration;
    start = fopen("G:\\Class_duration\\start.txt", "r");
    end = fopen("G:\\Class_duration\\end.txt", "r");
    classduration = fopen("G:\\Class_duration\\duration.txt", "w");
    while(!feof(start))
    {
        fscanf(start, "%s", &st.s);
        fscanf(end, " %s ", &et.s);
        st.h= (st.s[0]-48)*10+st.s[1]-48;
        et.h= (et.s[0]-48)*10+et.s[1]-48;
        st.m= (st.s[3]-48)*10+st.s[4]-48;
        et.m= (et.s[3]-48)*10+et.s[4]-48;
        if(st.h<=et.h)
        {
            if(et.h==st.h)
            {
                cd.h=0;
            }
            else{
                cd.h=et.h-(st.h+1);
            }

            if(st.h==et.h)
            {
                cd.m=et.m-st.m;
            }
            else{
                cd.m=(60-st.m)+et.m;
            }
        }
        else{
            cd.h=(24-st.h)+et.h;
            cd.m=(60-st.m)+et.m;
        }
        if(cd.m>=60)
        {
            cd.m-=60;
            cd.h++;
        }
        int a,b;
        a=cd.h%10;
        b=(cd.h%100)/10;
        cd.s[0]=(b+48);
        cd.s[1]=(a+48);
        cd.s[2]=':';
        a=cd.m%10;
        b=(cd.m%100)/10;
        cd.s[3]=(b+48);
        cd.s[4]=(a+48);
        cd.s[5]='\0';
        fprintf(classduration, "%s\n",cd.s);
    }

    printf("Calculation Complete\n");
    fclose(start);
    fclose(end);
}
