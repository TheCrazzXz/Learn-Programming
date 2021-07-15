#include <stdio.h>
int GamePart2(int aw_user3, int *points);


int inputErrorVal(int aw_user)
{
     printf("\n ['%d'] Veuillez rentrer une option valide 1 / 2", aw_user);
}

int GameOver(int *points)
{
     printf("\nGame Over ! | %d points", *points);
}
int level_up(int *points)
{
     printf("\nFelicitaions ! Tu as gagné + 1 score !");
     printf("\nTu as maintenant %d points", *points);
}


int main(void)
{
     int points = 0;
     printf("- Salut toi ! :)");
     printf("\nRepondre : 1 : T'es qui ? / 2 : S'enfuir : ");
     int aw_user = 0;
     scanf("%d", &aw_user);
     if(aw_user == 1)
          {
               printf("\n- Je suis Jean-Luc ducker");
               printf("\nRepondre : 1 : Ravi de faire votre connaissence / 2 : Quest-ce que vous voulez ? : ");
               int aw_user2 = 0;
               scanf("%d", &aw_user2);
               if (aw_user2 == 1)
                    {
                         printf("\n- Merci ! Tu veux etre mon pote ?");
                         printf("\nRepondre : 1 : Ok ! / 2 : Non desole ! : ");
                         int aw_user3 = 0;
                         scanf("%d", &aw_user3);
                         if(aw_user3 == 1)
                         {
                              GamePart2(aw_user3, &points);
                         }
                         else if(aw_user3 == 2)
                         {
                              printf("\nBon bah a++");
                              GameOver(&points);
                         }
                         else
                         {
                              inputErrorVal(aw_user3);
                         }
                         
                    }
               else if(aw_user2 == 2)
                    {
                         printf("\n- Je veux juste etre ton ami c'est tout ! ");
                         printf("\nRepondre : 1 : Ok ! / 2 : Non desole ! : ");
                         int aw_user3 = 0;
                         scanf("%d", &aw_user3);
                         if(aw_user3 == 1)
                              {
                                   GamePart2(aw_user3, &points);
                              }
                         if(aw_user3 == 2)
                              {
                                   printf("\nBon bah dommage ! AUREVOIR !");
                                   GameOver(&points);
                              }
                         else
                              {
                              inputErrorVal(aw_user3);
                              }
                    }
               else
                    {
                         inputErrorVal(aw_user2);
                    }
          }
     else if (aw_user == 2)
          {
               printf("\n*Vous fuyez...");
               printf("\n- HE ! nan att reviens !!");
               GameOver(&points);
               
          }

     else 
          {
               inputErrorVal(aw_user);
          }

     signed char text_user[] = "";
     return 0;
}

int GamePart2(int aw_user3, int *points)
{
     level_up(points);
     printf("\n- Ok ! Cool quest-ce que tu veux faire en tant qu'ami ?\n 1 : Parler / 2 : Faire un jeu ");
     int aw_user4 = 0;
     scanf("%d", &aw_user4);
     if(aw_user4 = 1)
          {
               printf("\n- Vasy ! Tu veux dire quoi ? : \n");
               signed char aw_user5[] = "";
               scanf("%s", &aw_user5);
               printf("\n- Ah désolé j'ai pas entendu ! Tu peux répéter ? STP\n");
               printf("\n$- Je disais que : ");
               scanf("%s", &aw_user5);
          }
     if(aw_user4 = 2)
          {
               printf("\n- Ah désolé j'aime pas jouer !");
          }
     else
          {
               inputErrorVal(aw_user4);
          }
                              
}
