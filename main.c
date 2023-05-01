#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ot[10][10],ow[10][10],od[10][10],bt[10][10],ba[10][10],bi[10][10],tr[10][10],tl[10][10],tv[10][10];
void anulare_rezervare(int matrice[10][10],int loc)
{  int conditienrloc=0;
  if(loc<=9)
                {   conditienrloc=1;
                    matrice[1][loc]=0;


                }
                if(loc%10==0)
                {   conditienrloc=1;
                    matrice[loc/10][10]=0;

                }

                if(conditienrloc==0)
                {
                    matrice[loc/10+1][loc%10]=0;

                }

}

void locuri_luate(int matrice[10][10])
{  int okocupare=0;
    int i,j,numarator=1;
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            if(matrice[i][j]!=0)
                {printf("%d ", numarator);
                okocupare=1;}
            numarator++;
        }


    if(okocupare==0)
        printf("Nu s-a facut nicio rezervare.");
}

void locuri_ocupate(int matrice[10][10])
{
    int numarator=1;
    printf("Locuri ocupate:");
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            if(matrice[i][j]!=0)
                printf("%d ", numarator);
            numarator++;
        }
        printf("\nAlegeti un loc:");
}
void printare_locuri()
{   int xi,xj;
    int numarator=1;

            printf("           ECRAN");
            printf("\n\n");
            for(xi=1;xi<=10;xi++)
          {

                printf("\n");
               for(xj=1;xj<=10;xj++)
                  {printf("%d",numarator);
                  printf("  ");
                  numarator++;}

}

printf("\n");

}
int asignare_loc(int matrice[10][10],int loc)
{   int conditienrloc=0;

    if(loc<=9)
                {   conditienrloc=1;
                    matrice[1][loc]+=1;
                    return matrice[1][loc];

                }
                if(loc%10==0)
                {   conditienrloc=1;
                    matrice[loc/10][10]+=1;
                    return matrice[loc/10][10];
                }

                if(conditienrloc==0)
                {
                    matrice[loc/10+1][loc%10]+=1;
                    return matrice[loc/10+1][loc%10];
                }


}

void golire_matrice(int matrixe[10][10])
{
    for(int yi=1;yi<=10;yi++)
   {
      for(int yj=1;yj<=10;yj++)
       matrixe[yi][yj]=0;
    }
}
void afisare_meniu()
{
    printf("                 CINEMA\n");
	printf(" ==================================================================\n");
	printf("||             1- Rezerva dupa locatie                            ||\n");
	printf("||             2- Locatii si filme                                ||\n");
	printf("||             3- Lista filme                                     ||\n");
	printf("||             4- Anulare rezervare                               ||\n");
	printf("||             5- Iesire.                                         ||\n");
	printf("||             6- Meniu Restaurant                                ||\n");
	printf("||================================================================||\n");
	printf("Alege:");
}

int main()
{   golire_matrice(ot);
    golire_matrice(ow);
    golire_matrice(od);
    golire_matrice(bt);
    golire_matrice(ba);
    golire_matrice(bi);
    golire_matrice(tr);
    golire_matrice(tl);
    golire_matrice(tv);
    int iesire6;
typedef struct Restaurant{
  int pi,pe,pa,na,suc,apa,ceai;

};
struct Restaurant pret={5, 7, 10, 10, 5, 3, 4};
  int okloc=0,iesire4=1;
  int iesiremeniu=0;
    char path[]="./fisier_bilete.txt";

    int a=0,i,j,b,d,nrloc,a1,pb;
    char c,nume[30];
    afisare_meniu();

    while(a!=5)
{   iesire4=0;
   iesire6=0;
    scanf("%d", &a);
    if(a==1)
    {   int pb=1;
        int iesiremeniu=0;
        printf("Alege locatia:\n1)ORADEA\n2)BUCURESTI\n3)TIMISOARA\n");
        scanf("%d", &b);
        while(b==1&&iesiremeniu==0)//ORADEA
        {
            system("cls");
            printf("\nAlegeti filmul dorit:\n\na)Titanic(20:00)\nb)Wild West(20:15)\nc)Dracula(20:30)\n");
            scanf("%c", &c);
            if(c=='a'||c=='A')//titanic
            {   FILE *f;
                system("cls");
          while(pb==1)
              { int ocupat=0;
                    printf("\n");
                  printare_locuri();
                printf("\n");
                locuri_ocupate(ot);

              while(ocupat==0)
              {   scanf("%d", &nrloc);
                  if(asignare_loc(ot,nrloc)>=2)
                    printf("Locul este deja ocupat, alegeti alt loc:");
                  else
                  {
                      asignare_loc(ot,nrloc);
                      ocupat=1;
                  }

              }
                printf("\n");
                printf("Introduceti numele:");
                fflush(stdin);
                gets(nume);
             printf("\n");
             printf("----------BILET   TITANIC-----------\n");
             printf("| Nume:%s\n",nume);
             printf("| Locul dumneavoastra:%d           |\n", nrloc);
             printf("| Ora inceperii filmului:20:00     |\n");
             printf("| Locatia:Oradea                   |\n");
             printf("| Vizionare placuta!               |\n");
             printf("------------------------------------");





             f=fopen(path, "a");
                fprintf(f,"\n");
             fprintf(f,"----------BILET   TITANIC-----------\n");
             fprintf(f,"| Nume:%s\n",nume);
             fprintf(f,"| Locul dumneavoastra:%d           |\n", nrloc);
             fprintf(f,"| Ora inceperii filmului:20:00     |\n");
             fprintf(f,"| Locatia:Oradea                   |\n");
             fprintf(f,"| Vizionare placuta!               |\n");
             fprintf(f,"------------------------------------");
             fclose(f);


             printf("\n1.Faceti o alta rezervare\n2.Meniu\n");
             scanf("%d", &pb);

            if(pb==2)
            {   system("cls");
                iesiremeniu=1;
                continue;
            }
              }
            if(iesiremeniu==1)
                system("cls");
               afisare_meniu();
                continue;
            }


        if(c=='b'||c=='B')//wildwest
          {FILE *f;
              system("cls");
            while(pb==1)
              { int ocupat=0;
                    printf("\n");
                  printare_locuri();
                printf("\n");
                locuri_ocupate(ow);

              while(ocupat==0)
              {   scanf("%d", &nrloc);
                  if(asignare_loc(ow,nrloc)>=2)
                    printf("Locul este deja ocupat, alegeti alt loc:");
                  else
                  {
                      asignare_loc(ow,nrloc);
                      ocupat=1;
                  }

              }
                printf("\n");
                printf("Introduceti numele:");
                fflush(stdin);
                gets(nume);
             printf("\n");
             printf("----------BILET   WILD WEST----------\n");
             printf("| Nume:%s\n",nume);
             printf("| Locul dumneavoastra:%d            |\n", nrloc);
             printf("| Ora inceperii filmului:20:15      |\n");
             printf("| Locatia:Oradea                    |\n");
             printf("| Vizionare placuta!                |\n");
             printf("-------------------------------------");



             f=fopen(path, "a");
                fprintf(f,"\n");
             fprintf(f,"----------BILET   WILD WEST----------\n");
             fprintf(f,"| Nume:%s\n",nume);
             fprintf(f,"| Locul dumneavoastra:%d           |\n", nrloc);
             fprintf(f,"| Ora inceperii filmului:20:15     |\n");
             fprintf(f,"| Locatia:Oradea                   |\n");
             fprintf(f,"| Vizionare placuta!               |\n");
             fprintf(f,"------------------------------------");
             fclose(f);

 printf("\n1.Faceti o alta rezervare\n2.Meniu\n");
             scanf("%d", &pb);

            if(pb==2)
            {   system("cls");
                iesiremeniu=1;
                continue;
            }
              }
               if(iesiremeniu==1)
                system("cls");
               afisare_meniu();
                continue;

            }


          if(c=='c'||c=='C')//dracula
          {  FILE *f;
              system("cls");
             while(pb==1)
              { int ocupat=0;
                    printf("\n");
                  printare_locuri();
                printf("\n");
                locuri_ocupate(od);

              while(ocupat==0)
              {   scanf("%d", &nrloc);
                  if(asignare_loc(od,nrloc)>=2)
                    printf("Locul este deja ocupat, alegeti alt loc:");
                  else
                  {
                      asignare_loc(od,nrloc);
                      ocupat=1;
                  }

              }

                printf("\n");
                printf("Introduceti numele:");
                fflush(stdin);
                gets(nume);
             printf("\n");
             printf("----------BILET   DRACULA-----------\n");
             printf("| Nume:%s\n",nume);
             printf("| Locul dumneavoastra:%d           |\n", nrloc);
             printf("| Ora inceperii filmului:20:30     |\n");
             printf("| Locatia:Oradea                   |\n");
             printf("| Vizionare placuta!               |\n");
             printf("------------------------------------");




              f=fopen(path, "a");
                fprintf(f,"\n");
             fprintf(f,"----------BILET   DRACULA-----------\n");
             fprintf(f,"| Nume:%s\n",nume);
             fprintf(f,"| Locul dumneavoastra:%d           |\n", nrloc);
             fprintf(f,"| Ora inceperii filmului:20:30     |\n");
             fprintf(f,"| Locatia:Oradea                   |\n");
             fprintf(f,"| Vizionare placuta!               |\n");
             fprintf(f,"------------------------------------");
             fclose(f);

             printf("\n1.Faceti o alta rezervare\n2.Meniu\n");
             scanf("%d", &pb);

            if(pb==2)
            {   system("cls");
                iesiremeniu=1;
                continue;
            }
              }
               if(iesiremeniu==1)
                system("cls");
               afisare_meniu();
                continue;
            }
        }

        while(b==2&&iesiremeniu==0)//BUCURESTI
        {system("cls");
          printf("\nAlegeti filmul dorit:\n\na)Titanic(20:45)\nb)Avengers(21:00)\nc)The imitation game(21:15)\n");
            scanf("%c", &c);
          if(c=='a'||c=='A')
          {   FILE *f;
              system("cls");
              while(pb==1)
              { int ocupat=0;
                    printf("\n");
                  printare_locuri();
                printf("\n");
                locuri_ocupate(bt);

              while(ocupat==0)
              {   scanf("%d", &nrloc);
                  if(asignare_loc(bt,nrloc)>=2)
                    printf("Locul este deja ocupat, alegeti alt loc:");
                  else
                  {
                      asignare_loc(bt,nrloc);
                      ocupat=1;
                  }

              }
                printf("\n");
                printf("Introduceti numele:");
                fflush(stdin);
                gets(nume);
             printf("\n");
             printf("----------BILET   TITANIC-----------\n");
             printf("| Nume:%s\n",nume);
             printf("| Locul dumneavoastra:%d           |\n", nrloc);
             printf("| Ora inceperii filmului:20:45     |\n");
             printf("| Locatia:Bucuresti                |\n");
             printf("| Vizionare placuta!               |\n");
             printf("------------------------------------");





             f=fopen(path, "a");
                fprintf(f,"\n");
             fprintf(f,"----------BILET   TITANIC-----------\n");
             fprintf(f,"| Nume:%s\n",nume);
             fprintf(f,"| Locul dumneavoastra:%d           |\n", nrloc);
             fprintf(f,"| Ora inceperii filmului:20:45     |\n");
             fprintf(f,"| Locatia:Bucuresti                |\n");
             fprintf(f,"| Vizionare placuta!               |\n");
             fprintf(f,"------------------------------------");
             fclose(f);

          printf("\n1.Faceti o alta rezervare\n2.Meniu\n");
             scanf("%d", &pb);

            if(pb==2)
            {   system("cls");
                iesiremeniu=1;
                continue;
            }
              }
               if(iesiremeniu==1)
                system("cls");
               afisare_meniu();
                continue;

            }
           if(c=='b'||c=='B')
           {   FILE *f;
               system("cls");
                while(pb==1)
              { int ocupat=0;
                    printf("\n");
                  printare_locuri();
                printf("\n");
                locuri_ocupate(ba);

              while(ocupat==0)
              {   scanf("%d", &nrloc);
                  if(asignare_loc(ba,nrloc)>=2)
                    printf("Locul este deja ocupat, alegeti alt loc:");
                  else
                  {
                      asignare_loc(ba,nrloc);
                      ocupat=1;
                  }

              }

                printf("\n");
                printf("Introduceti numele:");
                fflush(stdin);
                gets(nume);
             printf("\n");
             printf("----------BILET   AVENGERS----------\n");
             printf("| Nume:%s\n",nume);
             printf("| Locul dumneavoastra:%d           |\n", nrloc);
             printf("| Ora inceperii filmului:21:00     |\n");
             printf("| Locatia:Bucuresti                |\n");
             printf("| Vizionare placuta!               |\n");
             printf("------------------------------------");






             f=fopen(path, "a");
                fprintf(f,"\n");
             fprintf(f,"----------BILET   AVENGERS----------\n");
             fprintf(f,"| Nume:%s\n",nume);
             fprintf(f,"| Locul dumneavoastra:%d           |\n", nrloc);
             fprintf(f,"| Ora inceperii filmului:21:00     |\n");
             fprintf(f,"| Locatia:Bucuresti                |\n");
             fprintf(f,"| Vizionare placuta!               |\n");
             fprintf(f,"------------------------------------");
             fclose(f);
           printf("\n1.Faceti o alta rezervare\n2.Meniu\n");
             scanf("%d", &pb);

            if(pb==2)
            {   system("cls");
                iesiremeniu=1;
                continue;
            }
              }
          if(iesiremeniu==1)
                system("cls");
               afisare_meniu();
                continue;
            }

            if(c=='c'||c=='C')
            {  FILE *f;
                system("cls");
              while(pb==1)
              { int ocupat=0;
                    printf("\n");
                  printare_locuri();
                printf("\n");
                locuri_ocupate(bi);

              while(ocupat==0)
              {   scanf("%d", &nrloc);
                  if(asignare_loc(bi,nrloc)>=2)
                    printf("Locul este deja ocupat, alegeti alt loc:");
                  else
                  {
                      asignare_loc(bi,nrloc);
                      ocupat=1;
                  }

              }
                printf("\n");
                printf("Introduceti numele:");
                fflush(stdin);
                gets(nume);
             printf("\n");
             printf("-------BILET   IMITATION GAME-------\n");
             printf("| Nume:%s\n",nume);
             printf("| Locul dumneavoastra:%d           |\n", nrloc);
             printf("| Ora inceperii filmului:21:15     |\n");
             printf("| Locatia:Bucuresti                |\n");
             printf("| Vizionare placuta!               |\n");
             printf("------------------------------------");





             f=fopen(path, "a");
                fprintf(f,"\n");
             fprintf(f,"-------BILET   IMITATION GAME-------\n");
             fprintf(f,"| Nume:%s\n",nume);
             fprintf(f,"| Locul dumneavoastra:%d           |\n", nrloc);
             fprintf(f,"| Ora inceperii filmului:21:15     |\n");
             fprintf(f,"| Locatia:Bucuresti                |\n");
             fprintf(f,"| Vizionare placuta!               |\n");
             fprintf(f,"------------------------------------");
             fclose(f);
            printf("\n1.Faceti o alta rezervare\n2.Meniu\n");
             scanf("%d", &pb);

            if(pb==2)
            {   system("cls");
                iesiremeniu=1;
                continue;
            }
              }
         if(iesiremeniu==1)
                system("cls");
               afisare_meniu();
                continue;
            }
        }
        while(b==3&&iesiremeniu==0)//TIMISOARA
        {system("cls");

        printf("\nAlegeti filmul dorit:\n\na)Red(21:30)\nb)Lean 4 real(21:45)\nc)Vlone(22:00)\n");
            scanf("%c", &c);
          if(c=='a'||c=='A')
          {  FILE *f;
              system("cls");
              while(pb==1)
              { int ocupat=0;
                    printf("\n");
                  printare_locuri();
                printf("\n");
                locuri_ocupate(tr);

              while(ocupat==0)
              {   scanf("%d", &nrloc);
                  if(asignare_loc(tr,nrloc)>=2)
                    printf("Locul este deja ocupat, alegeti alt loc:");
                  else
                  {
                      asignare_loc(tr,nrloc);
                      ocupat=1;
                  }

              }
                printf("\n");
                printf("Introduceti numele:");
                fflush(stdin);
                gets(nume);
             printf("\n");
             printf("----------BILET   RED---------------\n");
             printf("| Nume:%s\n",nume);
             printf("| Locul dumneavoastra:%d           |\n", nrloc);
             printf("| Ora inceperii filmului:21:30     |\n");
             printf("| Locatia:Timisoara                |\n");
             printf("| Vizionare placuta!               |\n");
             printf("------------------------------------");




             f=fopen(path, "a");
                fprintf(f,"\n");
             fprintf(f,"----------BILET   RED---------------\n");
             fprintf(f,"| Nume:%s\n",nume);
             fprintf(f,"| Locul dumneavoastra:%d           |\n", nrloc);
             fprintf(f,"| Ora inceperii filmului:21:30     |\n");
             fprintf(f,"| Locatia:Timisoara                |\n");
             fprintf(f,"| Vizionare placuta!               |\n");
             fprintf(f,"------------------------------------");
             fclose(f);

         printf("\n1.Faceti o alta rezervare\n2.Meniu\n");
             scanf("%d", &pb);

            if(pb==2)
            {   system("cls");
                iesiremeniu=1;
                continue;
            }
              }
            if(iesiremeniu==1)
                system("cls");
               afisare_meniu();
                continue;
            }
           if(c=='b'||c=='B')
           {  FILE *f;
               system("cls");
             while(pb==1)
              { int ocupat=0;
                    printf("\n");
                  printare_locuri();
                printf("\n");
                locuri_ocupate(tl);

              while(ocupat==0)
              {   scanf("%d", &nrloc);
                  if(asignare_loc(tl,nrloc)>=2)
                    printf("Locul este deja ocupat, alegeti alt loc:");
                  else
                  {
                      asignare_loc(tl,nrloc);
                      ocupat=1;
                  }

              }

                printf("\n");
                printf("Introduceti numele:");
                fflush(stdin);
                gets(nume);
             printf("\n");
             printf("--------BILET   LEAN 4 REAL---------\n");
             printf("| Nume:%s\n",nume);
             printf("| Locul dumneavoastra:%d           |\n", nrloc);
             printf("| Ora inceperii filmului:21:45     |\n");
             printf("| Locatia:Timisoara                |\n");
             printf("| Vizionare placuta!               |\n");
             printf("------------------------------------");




             f=fopen(path, "a");
                fprintf(f,"\n");
             fprintf(f,"--------BILET   LEAN 4 REAL---------\n");
             fprintf(f,"| Nume:%s\n",nume);
             fprintf(f,"| Locul dumneavoastra:%d           |\n", nrloc);
             fprintf(f,"| Ora inceperii filmului:21:45     |\n");
             fprintf(f,"| Locatia:Timisoara                |\n");
             fprintf(f,"| Vizionare placuta!               |\n");
             fprintf(f,"------------------------------------");
             fclose(f);
            printf("\n1.Faceti o alta rezervare\n2.Meniu\n");
             scanf("%d", &pb);

            if(pb==2)
            {   system("cls");
                iesiremeniu=1;
                continue;
            }
              }
      if(iesiremeniu==1)
                system("cls");
               afisare_meniu();
                continue;
            }
            if(c=='c'||c=='C')
            {   FILE *f;
                system("cls");
               while(pb==1)
              { int ocupat=0;
                    printf("\n");
                  printare_locuri();
                printf("\n");
                locuri_ocupate(tv);

              while(ocupat==0)
              {   scanf("%d", &nrloc);
                  if(asignare_loc(tv,nrloc)>=2)
                    printf("Locul este deja ocupat, alegeti alt loc:");
                  else
                  {
                      asignare_loc(tv,nrloc);
                      ocupat=1;
                  }

              }
                printf("\n");
                printf("Introduceti numele:");
                fflush(stdin);
                gets(nume);
             printf("\n");
             printf("---------BILET   VLONE--------------\n");
             printf("| Nume:%s\n",nume);
             printf("| Locul dumneavoastra:%d           |\n", nrloc);
             printf("| Ora inceperii filmului:22:00     |\n");
             printf("| Locatia:Timisoara                |\n");
             printf("| Vizionare placuta!               |\n");
             printf("------------------------------------");




             f=fopen(path, "a");
                fprintf(f,"\n");
             fprintf(f,"---------BILET   VLONE--------------\n");
             fprintf(f,"| Nume:%s\n",nume);
             fprintf(f,"| Locul dumneavoastra:%d           |\n", nrloc);
             fprintf(f,"| Ora inceperii filmului:22:00     |\n");
             fprintf(f,"| Locatia:Timisoara                |\n");
             fprintf(f,"| Vizionare placuta!               |\n");
             fprintf(f,"------------------------------------");
             fclose(f);
             printf("\n1.Faceti o alta rezervare\n2.Meniu\n");
             scanf("%d", &pb);

            if(pb==2)
            {   system("cls");
                iesiremeniu=1;
                continue;
            }
              }
        if(iesiremeniu==1)
                system("cls");
               afisare_meniu();
                continue;
            }

        }
    }

	if(a==2)
   {    system("cls");
        printf("Lista cu locatiile si filmele lor");
        printf("\n\n  1.ORADEA\na)Titanic\nb)Wild West\nc)Dracula");
        printf("\n\n  2.BUCURESTI\na)Ttanic\nb)Avengers\nc)The imitation game");
        printf("\n\n  3.TIMISOARA\na)Red\nb)Lean 4 real\nc)Vlone\n");
        printf("\n1.Meniu\n5.Iesire\n");
        scanf("%d", &a1);
        if(a1==1)
        {  system("cls");
           afisare_meniu();

        }
        if(a1==5)
        {
            break;
            a=5;
        }

   }
   if(a==3)
   {
       printf("\nLista tuturor filmelor:\n");
       printf("1.Titanic\n2.Wild West\n3.Dracula\n4.Avengers\n5.The imitation game\n6.Red\n7.Lean 4 real\n8.Vlone\n");
    printf("\n1.Meniu\n5.Iesire");
    scanf("%d", &a1);
        if(a1==1)
        {  system("cls");
           afisare_meniu();

        }
        if(a1==5)
        {
            break;
            a=5;
        }
   }

   while(a==4&&iesire4!=10)
   {  int aa,aa1,ab=0;
       system("cls");
       printf("Alegeti filmul la care doriti sa anulati rezervarea:");
       printf("\n   ORADEA:\n1.Rezervari Titanic:");
       locuri_luate(ot);
       printf("\n2.Rezervari Wild West:");
       locuri_luate(ow);
        printf("\n3.Rezervari Dracula:");
       locuri_luate(od);
       printf("\n\n\n   BUCURESTI:\n4.Rezervari Titanic:");
       locuri_luate(bt);
        printf("\n5.Rezervari Avengers:");
      locuri_luate(ba);
        printf("\n6.Rezevcari The imitation game:");
       locuri_luate(bi);
        printf("\n\n\n   TIMISOARA:\n7.Rezervari Red:");
       locuri_luate(tr);
        printf("\n8.Rezervari Lean 4 real:");
       locuri_luate(tl);
        printf("\n9.Rezervari Vlone:");
       locuri_luate(tv);
       printf("\n10.Meniu\n");



       scanf("%d", &ab);
       if(ab==1)
       {
           aa1=1;


         while(aa1==1&&iesire4!=10)
       { int loca;
           system("cls");
           printf("Introduceti locul de pe care doriti sa anulati rezervarea din urmatoarele:");
           locuri_luate(ot);
           printf("\n");
           scanf("%d", &loca);
           anulare_rezervare(ot,loca);
           printf("\nAnularea rezervari s-a efectuat\n1.Anulati inca o rezervare\n10.Meniu");
           scanf("%d", &aa1);

       }

       }

        if(ab==2)
        {aa1=1;

       while(aa1==1&&iesire4!=10)
       { int loca;
           system("cls");
           printf("Introduceti locul de pe care doriti sa anulati rezervarea din urmatoarele:");
           locuri_luate(ow);
           printf("\n");
           scanf("%d", &loca);
           anulare_rezervare(ow,loca);
           printf("\nAnularea rezervari s-a efectuat\n1.Anulati inca o rezervare\n2.Meniu");
           scanf("%d", &aa1);
       }

       }

        if(ab==3)
       {

        aa1=1;

       while(aa1==1&&iesire4!=10)
       { int loca;
           system("cls");
           printf("Introduceti locul de pe care doriti sa anulati rezervarea din urmatoarele:");
           locuri_luate(od);
           printf("\n");
           scanf("%d", &loca);
           anulare_rezervare(od,loca);
           printf("\nAnularea rezervari s-a efectuat\n1.Anulati inca o rezervare\n2.Meniu");
           scanf("%d", &aa1);
       }}


       if(ab==4)
       {

        aa1=1;
       while(aa1==1&&iesire4!=10)
       { int loca;
           system("cls");
           printf("Introduceti locul de pe care doriti sa anulati rezervarea din urmatoarele:");
           locuri_luate(bt);
           printf("\n");
           scanf("%d", &loca);
           anulare_rezervare(bt,loca);
           printf("\nAnularea rezervari s-a efectuat\n1.Anulati inca o rezervare\n2.Meniu");
           scanf("%d", &aa1);
       }}

       if(ab==5)
       {

        aa1=1;
       while(aa1==1&&iesire4!=10)
       { int loca;
           system("cls");
           printf("Introduceti locul de pe care doriti sa anulati rezervarea din urmatoarele:");
           locuri_luate(ba);
           printf("\n");
           scanf("%d", &loca);
           anulare_rezervare(ba,loca);
           printf("\nAnularea rezervari s-a efectuat\n1.Anulati inca o rezervare\n2.Meniu");
           scanf("%d", &aa1);
       }}

       if(ab==6)
       {

        aa1=1;
       while(aa1==1&&iesire4!=10)
       { int loca;
           system("cls");
           printf("Introduceti locul de pe care doriti sa anulati rezervarea din urmatoarele:");
           locuri_luate(bi);
           printf("\n");
           scanf("%d", &loca);
           anulare_rezervare(bi,loca);
           printf("\nAnularea rezervari s-a efectuat\n1.Anulati inca o rezervare\n2.Meniu");
           scanf("%d", &aa1);
       }}

       if(ab==7)
       {

        aa1=1;
       while(aa1==1&&iesire4!=10)
       { int loca;
           system("cls");
           printf("Introduceti locul de pe care doriti sa anulati rezervarea din urmatoarele:");
           locuri_luate(tr);
           printf("\n");
           scanf("%d", &loca);
           anulare_rezervare(tr,loca);
           printf("\nAnularea rezervari s-a efectuat\n1.Anulati inca o rezervare\n2.Meniu");
           scanf("%d", &aa1);
       }}

       if(ab==8)
       {

        aa1=1;
       while(aa1==1&&iesire4!=10)
       { int loca;
           system("cls");
           printf("Introduceti locul de pe care doriti sa anulati rezervarea din urmatoarele:");
           locuri_luate(tl);
           printf("\n");
           scanf("%d", &loca);
           anulare_rezervare(tl,loca);
           printf("\nAnularea rezervari s-a efectuat\n1.Anulati inca o rezervare\n2.Meniu");
           scanf("%d", &aa1);
       }}

       if(ab==9)
       {

        aa1=1;
       while(aa1==1&&iesire4!=10)
       { int loca;
           system("cls");
           printf("Introduceti locul de pe care doriti sa anulati rezervarea din urmatoarele:");
           locuri_luate(tv);
           printf("\n");
           scanf("%d", &loca);
           anulare_rezervare(tv,loca);
           printf("\nAnularea rezervari s-a efectuat\n1.Anulati inca o rezervare\n2.Meniu");
           scanf("%d", &aa1);
       }

       }
       if(ab==10)
      {iesire4=10;

      system("cls");
      afisare_meniu();
      continue;
      }

   }
   if(a==6&&iesire6==0)
   {
       system("cls");
       printf("Lista preturilor de la Restaurantul Cinemaului:\na)MANCARE:\n1.Popcorn mic:%d\n2.Popcorn mediu:%d\n3.Popcorn mare:%d\n4.Nachos:%d\n\nb)BAUTURI:\n1.Apa:%d\n2.Ceai:%d\n3.Suc:%d\n5.Iesire", pret.pi, pret.pe,pret.pa,pret.na,pret.apa,pret.ceai,pret.suc);
       scanf("%d", &iesire6);
       if(iesire6==5)
       {
           iesire6=1;
           iesiremeniu=1;
           system("cls");
       }
   }
   if(iesiremeniu==1)
   {   iesiremeniu=0;
       afisare_meniu();

   }

}
    return 0;
}
