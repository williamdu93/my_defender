/*
** EPITECH PROJECT, 2019
** h
** File description:
** h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>

int jeu (int ac, char **av)
{
    /*Pour le jeu*/
    sfRenderWindow *window;
    /* La map de jeu*/
    sfSprite *sprite10;
    sfTexture *texture10;
    /* Son pour le jeu */
    sfSoundBuffer *soundbuffer;
    sfSound *sound;

/* MAP mais bug encore donc pas la peine de mettre la map en structure pour l'instant*/
/*
  sprite10 = sfSprite_create();
  texture10 = sfTexture_createFromFile("IMG_20190223_125230.jpg", NULL);
  sfSprite_setTexture(sprite10, texture10, sfTrue);
  sfRenderWindow_drawSprite(window, sprite10, NULL);


    /*Son du jeu ff*/
    soundbuffer = sfSoundBuffer_createFromFile("sweets-parade-full-english-lyrics.ogg");
    sound = sfSound_create();
    sfSound_setBuffer(sound, soundbuffer);
    sfSound_play(sound);
    sfSound_setVolume(sound, 5);
    sfSound_setLoop(sound, sfTrue);
    sfSound_getLoop(sound);
}


char *my_putnbr(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    int j = 1;

    while ((nb / j) >= 10)
        j = j * 10;
    while (j > 0) {
        str[i] = (nb/j) % 10 + '0';
        j = j / 10;
        i = i + 1;
    }
    while (i < 10) {
        str[i] = '\0';
        i += 1;
    }
    return (str);
}






/* Animation des monstres */

sfIntRect animation(sfSprite *sprite11, sfClock *clock, sfIntRect rect10)
{
    sfTime time = sfClock_getElapsedTime(clock);
    int a = time.microseconds / 50000.0;

    if (a % 6 == 0)
        rect10.left = 65;
    if (a % 6 == 1)
        rect10.left = 130;
    if (a % 6 == 2)
        rect10.left = 195;
    if (a % 6 == 3)
        rect10.left = 260;
    if (a % 6 == 4)
        rect10.left = 325;
    if (a % 6 == 5)
        rect10.left = 0;
    return (rect10);
}


void    my_putchar (char c)
{
    write (1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
	my_putchar(str[i]);
	i = i + 1;
    }
    return (0);
}










int main(int ac, char **av)
{    
/* Notice */
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    {
        my_putstr("Bienvenu dans le monde merveilleux de lolipopia\n");
        my_putstr("Héros tu as des pouvoirs extraordinaire\n");
        my_putstr("Seul toi peux nous sauver des terribles monstres tantacules\n");
        my_putstr("Grâce à l'argent de lolipopia tu peux engager nos plus braves soldats\n");
        my_putstr("Tu as le controle total sur nous mais attention il y a des contraintes\n");
        my_putstr("Tu peux qu'invoquer que 5 fois le même soldat donc choisi bien l'ordre\n");
        my_putstr("Tu peux avoir plus d'info sur les tourelles en appuiant sur l'écrou en bas à gauche quand tu a lancé le jeu puis rappuie sur entrer pour repondre le combat\n");
        my_putstr("Pour mettre le combat en pause appuie sur échap\n");
        my_putstr("Le but de ta mission et de proteger notre château bonne chance héros\n");
        return 0;
    }
    sfRenderWindow *window; //s
    sfVideoMode videomode = {1900, 1000, 32};//s
    sfEvent event;//s
/* pour le menu */
/* Image de fond */
    sfSprite *sprite;//s
    sfTexture *texture;//s
/*Son pour le menu*/
    sfSoundBuffer *soundbuffer;//s
    sfSound *sound;//s
/* Image de bouton */ 
    sfSprite *sprite2;//s
    sfTexture *texture2;//s
    sfVector2f pos = {1450, 300};//s
    sfIntRect rect;//s

    rect.top = 0;//s
    rect.left = 0;//s
    rect.width = 400;//s
    rect.height = 139;//s
/* Image du bouton quitter */
    sfSprite *sprite3;
    sfTexture *texture3;
    sfVector2f pos2 = {1500, 700};
    sfIntRect rect2;

    rect2.top = 0;
    rect2.left = 0;
    rect2.width = 300;
    rect2.height = 139;

/* Son pour le jeu */
    sfSoundBuffer *soundbuffer2;
    sfSound *sound2;
/* Monstre qui arrive au bout du chemin */
    sfSoundBuffer *soundbuffer10;
    sfSound *sound10;

/* Image de fond du jeu */
    sfSprite *sprite10;
    sfTexture *texture10;
/* Argent */

    int argent = 700;
    sfSprite *sprite1000;
    sfTexture *texture1000;
    sfVector2f pos1000 = {90 ,10};
    sfText *text;
    sfFont *font;
    text = sfText_create();
    font = sfFont_createFromFile("arial.ttf");
    sfText_setString(text, my_putnbr(argent));
    sfText_setFont(text,font);
    sfText_setCharacterSize(text, 50);
        
   
/*Image du monstre + gameplay du monstre */
    sfSprite *sprite11;
    sfTexture *texture11;
    sfIntRect rect10;
    sfClock *clock;
    float seconds;
    sfVector2f pos10 = {-1000 ,100};
    float x = 1;
    int vie2 = 10;
    int vie3 = 5;
    
    // float y = 1;
    int vie = 2;
    int monstre_vie = 5;
    rect10.top = 0;
    rect10.left = 0;
    rect10.width = 65;
    rect10.height = 65;
/* Parametre pour voir les tourelles */
    sfSprite *sprite20;
    sfTexture *texture20;
    sfVector2f pos20 = {1700, 850};
    sfIntRect rect20;

    rect20.top = 0;
    rect20.left = 0;
    rect20.width = 128;
    rect20.height = 128;


    
/* Inventaire */
    sfSprite *sprite50;
    sfTexture *texture50;
    sfVector2f pos50 = {250, 900};
    sfIntRect rect50;
    
    sfSprite *sprite51;
    sfTexture *texture51;
    sfVector2f pos51 = {550, 900};
    sfIntRect rect51;
    
    sfSprite *sprite52;
    sfTexture *texture52;
    sfVector2f pos52 = {850, 900};
    sfIntRect rect52;
    
    sfSprite *sprite53;
    sfTexture *texture53;
    sfVector2f pos53 = {1150, 900};
    sfIntRect rect53;
    
    sfSprite *sprite54;
    sfTexture *texture54;
    sfVector2f pos54 = {1450, 900};
    sfIntRect rect54;



/* Pause */
    sfSprite *sprite13;
    sfTexture *texture13;
    sfVector2f pos13 = {200, 400};
    sfIntRect rect12;

    rect12.top = 0;
    rect12.left = 0;
    rect12.width = 256;
    rect12.height = 256;


    sfSprite *sprite14;
    sfTexture *texture14;
    sfVector2f pos14 = {800, 400};
    sfIntRect rect13;

    rect13.top = 0;
    rect13.left = 0;
    rect13.width = 256;
    rect13.height = 256;


    sfSprite *sprite15;
    sfTexture *texture15;
    sfVector2f pos15 = {1400, 400};
    sfIntRect rect14;

    rect14.top = 0;
    rect14.left = 0;
    rect14.width = 256;
    rect14.height = 256;

/* Tourelle + description */
    sfSprite *sprite21;
    sfTexture *texture21;
    sfVector2f pos21 = {300, 0};

    sfSprite *sprite22;
    sfTexture *texture22;
    sfVector2f pos22 = {600, 0};

    sfSprite *sprite23;
    sfTexture *texture23;
    sfVector2f pos23 = {900, 0};

    sfSprite *sprite24;
    sfTexture *texture24;
    sfVector2f pos24 = {1200, 0};

    sfSprite *sprite25;
    sfTexture *texture25;
    sfVector2f pos25 = {1500, 0};

    sfSprite *sprite26;
    sfTexture *texture26;
    sfVector2f pos26 = {300, 500};

    sfSprite *sprite27;
    sfTexture *texture27;
    sfVector2f pos27 = {600, 500};

    sfSprite *sprite28;
    sfTexture *texture28;
    sfVector2f pos28 = {900, 500};

    sfSprite *sprite29;
    sfTexture *texture29;
    sfVector2f pos29 = {1200, 500};

    sfSprite *sprite30;
    sfTexture *texture30;
    sfVector2f pos30 = {1500, 500};

/* Changement de la sourir + tourelle*/

    sfSprite *sprite100;
    sfTexture *texture100;
    int hit100 = 0;

    sfSprite *sprite101;
    sfTexture *texture101;
    int hit101 = 0;

    sfSprite *sprite102;
    sfTexture *texture102;
    int hit102 = 0;

    sfSprite *sprite103;
    sfTexture *texture103;
    int hit103 = 0;

    sfSprite *sprite104;
    sfTexture *texture104;
    int hit104 = 0;

    sfSprite *sprite105;
    sfTexture *texture105;
    int hit105 = 0;
    
    sfSprite *sprite106;
    sfTexture *texture106;
    int hit106 = 0;

    sfSprite *sprite107;
    sfTexture *texture107;
    int hit107 = 0;

    sfSprite *sprite108;
    sfTexture *texture108;
    int hit108 = 0;

    sfSprite *sprite109;
    sfTexture *texture109;
    int hit109 = 0;


    sfSprite *sprite110;
    sfTexture *texture110;
    int hit110 = 0;

    sfSprite *sprite111;
    sfTexture *texture111;
    int hit111 = 0;

    sfSprite *sprite112;
    sfTexture *texture112;
    int hit112 = 0;

    sfSprite *sprite113;
    sfTexture *texture113;
    int hit113 = 0;

    sfSprite *sprite114;
    sfTexture *texture114;
    int hit114 = 0;

    sfSprite *sprite115;
    sfTexture *texture115;
    int hit115 = 0;

    sfSprite *sprite116;
    sfTexture *texture116;
    int hit116 = 0;

    sfSprite *sprite117;
    sfTexture *texture117;
    int hit117 = 0;

    sfSprite *sprite118;
    sfTexture *texture118;
    int hit118 = 0;

    sfSprite *sprite119;
    sfTexture *texture119;
    int hit119 = 0;

    sfSprite *sprite120;
    sfTexture *texture120;
    int hit120 = 0;

    sfSprite *sprite121;
    sfTexture *texture121;
    int hit121 = 0;

    sfSprite *sprite122;
    sfTexture *texture122;
    int hit122 = 0;

    sfSprite *sprite123;
    sfTexture *texture123;
    int hit123 = 0;

    sfSprite *sprite124;
    sfTexture *texture124;
    int hit124 = 0;

    window = sfRenderWindow_create(videomode,"Tower defense", sfDefaultStyle, NULL);//s

/* Pour le fond */
    sprite = sfSprite_create();//s
    texture = sfTexture_createFromFile("manga-sexy-image-large-2593.jpg", NULL);//s
    sfSprite_setTexture(sprite, texture, sfTrue);//s

/* Pour le bouton éteint */ 
    sprite2 = sfSprite_create();//s
    texture2 = sfTexture_createFromFile("button-play-en-us.png", NULL);//s
    sfSprite_setTexture(sprite2, texture2, sfTrue);//s
    sfSprite_setPosition(sprite2,pos);//s
    sfSprite_setTextureRect(sprite2,rect);//s

/* Bouton quitter */
    sprite3 = sfSprite_create();
    texture3 = sfTexture_createFromFile("61155.png", NULL);
    sfSprite_setTexture(sprite3, texture3, sfTrue);
    sfSprite_setPosition(sprite3,pos2);
    sfSprite_setTextureRect(sprite3,rect2);

/*Son du menu*/
    soundbuffer = sfSoundBuffer_createFromFile("boku-no-hero-academia-season-2-ost-worthy-rival-written-and-read-as-friend.ogg");//s
    sound = sfSound_create();//s
    sfSound_setBuffer(sound, soundbuffer);//s
    sfSound_play(sound);//s
    sfSound_setVolume(sound, 5);//s
    sfSound_setLoop(sound, sfTrue);//s
    sfSound_getLoop(sound);//s

/* Map du jeu */
    sprite10 = sfSprite_create();
    texture10 = sfTexture_createFromFile("IMG_20190223_125230.jpg", NULL);
    sfSprite_setTexture(sprite10, texture10, sfTrue);

/* Le monstre */
    sprite11 = sfSprite_create();
    texture11 = sfTexture_createFromFile("577322152.png", NULL);
    sfSprite_setTexture(sprite11, texture11, sfTrue);   
    clock = sfClock_create();

/* Inventaire */
    
    sprite50 = sfSprite_create();
    texture50 = sfTexture_createFromFile("1tourelle.png", NULL);
    sfSprite_setTexture(sprite50, texture50, sfTrue);

    sprite51 = sfSprite_create();
    texture51 = sfTexture_createFromFile("2tourelle.png", NULL);
    sfSprite_setTexture(sprite51, texture51, sfTrue);

    sprite52 = sfSprite_create();
    texture52 = sfTexture_createFromFile("3tourelle.png", NULL);
    sfSprite_setTexture(sprite52, texture52, sfTrue);

    sprite53 = sfSprite_create();
    texture53 = sfTexture_createFromFile("4tourelle.png", NULL);
    sfSprite_setTexture(sprite53, texture53, sfTrue);

    sprite54 = sfSprite_create();
    texture54 = sfTexture_createFromFile("5tourelle.png", NULL);
    sfSprite_setTexture(sprite54, texture54, sfTrue);
/* Pause */
    sprite13 = sfSprite_create();
    texture13 = sfTexture_createFromFile("Button-Close-icon.png", NULL);
    sfSprite_setTexture(sprite13, texture13, sfTrue);

    sprite14 = sfSprite_create();
    texture14 = sfTexture_createFromFile("resume.png", NULL);
    sfSprite_setTexture(sprite14, texture14, sfTrue);

    sprite15 = sfSprite_create();
    texture15 = sfTexture_createFromFile("white-37292_960_720.png", NULL);
    sfSprite_setTexture(sprite15, texture15, sfTrue);



/* Voir les tourelles */
    sprite20 = sfSprite_create();
    texture20 = sfTexture_createFromFile("parametre.png", NULL);
    sfSprite_setTexture(sprite20, texture20, sfTrue);
    sfSprite_setTextureRect(sprite20,rect20);

    int in_game = 0;//s
    int dans_menu = 0;
     
/* Menu des tourelles + description  */
    sprite21 = sfSprite_create();
    texture21 = sfTexture_createFromFile("340px-Nowi_Eternal_Witch_Face.png", NULL);
    sfSprite_setTexture(sprite21, texture21, sfTrue);

    sprite22 = sfSprite_create();
    texture22 = sfTexture_createFromFile("aa075bbf32ac9774f219219c8cc63e97.png", NULL);
    sfSprite_setTexture(sprite22, texture22, sfTrue);

    sprite23 = sfSprite_create();
    texture23 = sfTexture_createFromFile("Cordelia_été_Normal.png", NULL);
    sfSprite_setTexture(sprite23, texture23, sfTrue);

    sprite24 = sfSprite_create();
    texture24 = sfTexture_createFromFile("image.png", NULL);
    sfSprite_setTexture(sprite24, texture24, sfTrue);

    sprite25 = sfSprite_create();
    texture25 = sfTexture_createFromFile("DhrQ5NhXkAAIZas.png", NULL);
    sfSprite_setTexture(sprite25, texture25, sfTrue);

    sprite26 = sfSprite_create();
    texture26 = sfTexture_createFromFile("1.png", NULL);
    sfSprite_setTexture(sprite26, texture26, sfTrue);

    sprite27 = sfSprite_create();
    texture27 = sfTexture_createFromFile("2.png", NULL);
    sfSprite_setTexture(sprite27, texture27, sfTrue);

    sprite28 = sfSprite_create();
    texture28 = sfTexture_createFromFile("3.png", NULL);
    sfSprite_setTexture(sprite28, texture28, sfTrue);

    sprite29 = sfSprite_create();
    texture29 = sfTexture_createFromFile("4.png", NULL);
    sfSprite_setTexture(sprite29, texture29, sfTrue);

    sprite30 = sfSprite_create();
    texture30 = sfTexture_createFromFile("5.png", NULL);
    sfSprite_setTexture(sprite30, texture30, sfTrue);


/* sourir + tourelle*/
    sprite100 = sfSprite_create();
    texture100 = sfTexture_createFromFile("spritetourelle1.png", NULL);
    sfSprite_setTexture(sprite100, texture100, sfTrue);
    
    int as1 = 0;
    int second1 = 0;
    
    sprite101 = sfSprite_create();
    texture101 = sfTexture_createFromFile("spritetourelle1.png", NULL);
    sfSprite_setTexture(sprite101, texture101, sfTrue);
    
    int as2 = 0;
    int second2 = 0;



    sprite102 = sfSprite_create();
    texture102 = sfTexture_createFromFile("spritetourelle1.png", NULL);
    sfSprite_setTexture(sprite102, texture102, sfTrue);
    int as3 = 0;
    int second3 = 0;

    sprite103 = sfSprite_create();
    texture103 = sfTexture_createFromFile("spritetourelle1.png", NULL);
    sfSprite_setTexture(sprite103, texture103, sfTrue);
    int as4 = 0;
    int second4 = 0;

    sprite104 = sfSprite_create();
    texture104 = sfTexture_createFromFile("spritetourelle1.png", NULL);
    sfSprite_setTexture(sprite104, texture104, sfTrue);
     int as5 = 0;
     int second5 = 0;

     
    sprite105 = sfSprite_create();
    texture105 = sfTexture_createFromFile("100.png", NULL);
    sfSprite_setTexture(sprite105, texture105, sfTrue);
    
    int as6 = 0;
    int second6 = 0;
    
    sprite106 = sfSprite_create();
    texture106 = sfTexture_createFromFile("100.png", NULL);
    sfSprite_setTexture(sprite106, texture106, sfTrue);
    
    int as7 = 0;
    int second7 = 0;



    sprite107 = sfSprite_create();
    texture107 = sfTexture_createFromFile("100.png", NULL);
    sfSprite_setTexture(sprite107, texture107, sfTrue);
    int as8 = 0;
    int second8 = 0;

    sprite108 = sfSprite_create();
    texture108 = sfTexture_createFromFile("100.png", NULL);
    sfSprite_setTexture(sprite108, texture108, sfTrue);
    int as9 = 0;
    int second9 = 0;

    sprite109 = sfSprite_create();
    texture109 = sfTexture_createFromFile("100.png", NULL);
    sfSprite_setTexture(sprite109, texture109, sfTrue);
     int as10 = 0;
    int second10 = 0;

    sprite110 = sfSprite_create();
    texture110 = sfTexture_createFromFile("101.png", NULL);
    sfSprite_setTexture(sprite110, texture110, sfTrue);
    
    int as11 = 0;
    int second11 = 0;
    
    sprite111 = sfSprite_create();
    texture111 = sfTexture_createFromFile("101.png", NULL);
    sfSprite_setTexture(sprite111, texture111, sfTrue);
    
    int as12 = 0;
    int second12 = 0;



    sprite112 = sfSprite_create();
    texture112 = sfTexture_createFromFile("101.png", NULL);
    sfSprite_setTexture(sprite112, texture112, sfTrue);
    int as13 = 0;
    int second13 = 0;

    sprite113 = sfSprite_create();
    texture113 = sfTexture_createFromFile("101.png", NULL);
    sfSprite_setTexture(sprite113, texture113, sfTrue);
    int as14 = 0;
    int second14 = 0;

    sprite114 = sfSprite_create();
    texture114 = sfTexture_createFromFile("101.png", NULL);
    sfSprite_setTexture(sprite114, texture114, sfTrue);
     int as15 = 0;
     int second15 = 0;

     
    sprite115 = sfSprite_create();
    texture115 = sfTexture_createFromFile("102.png", NULL);
    sfSprite_setTexture(sprite115, texture115, sfTrue);
    
    int as16 = 0;
    int second16 = 0;
    
    sprite116 = sfSprite_create();
    texture116 = sfTexture_createFromFile("102.png", NULL);
    sfSprite_setTexture(sprite116, texture116, sfTrue);
    
    int as17 = 0;
    int second17 = 0;



    sprite117 = sfSprite_create();
    texture117 = sfTexture_createFromFile("102.png", NULL);
    sfSprite_setTexture(sprite117, texture117, sfTrue);
    int as18 = 0;
    int second18 = 0;

    sprite118 = sfSprite_create();
    texture118 = sfTexture_createFromFile("102.png", NULL);
    sfSprite_setTexture(sprite118, texture118, sfTrue);
    int as19 = 0;
    int second19 = 0;

    sprite119 = sfSprite_create();
    texture119 = sfTexture_createFromFile("102.png", NULL);
    sfSprite_setTexture(sprite119, texture119, sfTrue);
     int as20 = 0;
    int second20 = 0;

    sprite120 = sfSprite_create();
    texture120 = sfTexture_createFromFile("103.png", NULL);
    sfSprite_setTexture(sprite120, texture120, sfTrue);
    
    int as21 = 0;
    int second21 = 0;
    
    sprite121 = sfSprite_create();
    texture121 = sfTexture_createFromFile("103.png", NULL);
    sfSprite_setTexture(sprite121, texture121, sfTrue);
    
    int as22 = 0;
    int second22 = 0;



    sprite122 = sfSprite_create();
    texture122 = sfTexture_createFromFile("103.png", NULL);
    sfSprite_setTexture(sprite122, texture122, sfTrue);
    int as23 = 0;
    int second23 = 0;

    sprite123 = sfSprite_create();
    texture123 = sfTexture_createFromFile("103.png", NULL);
    sfSprite_setTexture(sprite123, texture123, sfTrue);
    int as24 = 0;
    int second24 = 0;

    sprite124 = sfSprite_create();
    texture124 = sfTexture_createFromFile("103.png", NULL);
    sfSprite_setTexture(sprite124, texture124, sfTrue);
     int as25 = 0;
     int second25 = 0;

/* Argent */
    sprite1000 = sfSprite_create();
    texture1000 = sfTexture_createFromFile("piece-mario-png-5.png", NULL);
    sfSprite_setTexture(sprite1000, texture1000, sfTrue);
    sfSprite_setPosition(sprite1000,pos1000);

/* lancement du jeu */
    while (sfRenderWindow_isOpen(window))//s
    {
        sfSprite_setPosition(sprite11,pos10);
        sfSprite_setPosition(sprite50,pos50);
        sfSprite_setPosition(sprite51,pos51);
        sfSprite_setPosition(sprite52,pos52);
        sfSprite_setPosition(sprite53,pos53);
        sfSprite_setPosition(sprite54,pos54);
        sfSprite_setPosition(sprite20,pos20);
     

        if (in_game == 1 ) {
            if (pos10.x < 200){
                pos10.x = pos10.x + x;
            }

            if (pos10.x == 200 && pos10.y < 450){
                pos10.y = pos10.y + x;}

            if (pos10.y == 450 && pos10.x < 270){
                pos10.x = pos10.x + x;
            }

            if (pos10.x == 270 && pos10.y < 680){
                pos10.y = pos10.y + x;
            }

            if (pos10.y == 680 && pos10.x < 380){
                pos10.x = pos10.x + x;}

            if (pos10.x == 380 && pos10.y < 700){
                pos10.y = pos10.y + x;}

            if (pos10.y == 700 && pos10.x < 470){
                pos10.x = pos10.x + x;}

            if (pos10.x == 470 && pos10.y < 750){
                pos10.y = pos10.y + x;
            }

            if (pos10.y == 750 && pos10.x < 800){
                pos10.x = pos10.x + x;
            }

            if (pos10.x == 800 && pos10.y >= 100){
                pos10.y = pos10.y - x;
            }

            if (pos10.y == 100 && pos10.x < 1100){
                pos10.x = pos10.x + x;
            }

            if (pos10.x == 1100 && pos10.y < 800){
                pos10.y = pos10.y + x;
            }

            if (pos10.y == 800 && pos10.x < 1150){
                pos10.x = pos10.x + x;
            }

            if (pos10.x == 1150 && pos10.y < 850){
                pos10.y = pos10.y + x;
            }

            if (pos10.y == 850 && pos10.x < 1525){
                pos10.x = pos10.x + x;
            }

            if (pos10.x == 1525 && pos10.y >= 300){
                pos10.y = pos10.y - x;
            }

            if (pos10.y == 300 && pos10.x >= 1475){
                pos10.x = pos10.x - x;
            }

            if (pos10.x == 1475 && pos10.y >= 225 && pos10.y < 850){
                pos10.y = pos10.y - x;
            }







            if (pos10.x == 1475 && pos10.y == 225)
            {
                soundbuffer10 = sfSoundBuffer_createFromFile("senpai-yamete-kudasai.ogg");
                sound10 = sfSound_create();
                sfSound_setBuffer(sound10, soundbuffer10);
                sfSound_play(sound10);
                sfSound_setVolume(sound10, 10);

                vie = vie - 1;

            }
        }



if (monstre_vie <= 0 || (pos10.x == 1475 && pos10.y == 225) && vie != 0)
{
hit100 = 0;
  hit101 = 0;
  hit102 = 0;
  hit103 = 0;
  hit104 = 0;
  hit105 = 0;
  hit106 = 0;
  hit107 = 0;
  hit108 = 0;
  hit109 = 0;
  hit110 = 0;
  hit111 = 0;
  hit112 = 0;
  hit113 = 0;
  hit114 = 0;
  hit115 = 0;
  hit116 = 0;
  hit117 = 0;
  hit118 = 0;
  hit119 = 0;
  hit120 = 0;
  hit121 = 0;
  hit122 = 0;
  hit123 = 0;
  hit124 = 0;
  pos10 = (sfVector2f) {-1000 ,100};
  sfSprite_setPosition(sprite11,pos10);
  
  x = 1;
  monstre_vie = vie3 + 5;
  vie3 = monstre_vie;

  if (monstre_vie >= 80)
  {
      sfRenderWindow_close(window);
  }


}

        if (vie == 0)
        {
            sfSprite_destroy(sprite10);
            sfTexture_destroy(texture10);
            sfSprite_destroy(sprite11);
            sfTexture_destroy(texture11);
            sfSprite_destroy(sprite20);
            sfTexture_destroy(texture20);
            sfSound_destroy(sound10);
            sfSoundBuffer_destroy(soundbuffer10);
            sfSoundBuffer_destroy(soundbuffer2);
            sfSound_destroy(sound2);
            sfRenderWindow_destroy(window);
            return (0);
        }
        sfSprite_setTextureRect(sprite11,rect10);
        sfSprite_setTextureRect(sprite20,rect20);
        rect10 = animation(sprite11, clock, rect10);
         

/* Prendre les tourelles */

        if (event.mouseButton.x >= pos50.x && event.mouseButton.x
            <= pos50.x + 100) {
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && event.mouseButton.y >= pos50.y && event.mouseButton.y
                <= pos50.y + 100){
                    if (as1 == 0 && as2 == 0 && as3 == 0 && as4 == 0 && as5 == 0 && argent >= 150) {
                sfRenderWindow_setMouseCursorVisible(window,sfFalse);
                argent -= 150;
                sfText_setString(text, my_putnbr(argent));
                if (second1 == 0)
                    as1 = 1;
                else if (second2 == 0)
                    as2 = 1;
                else if (second3 == 0)
                    as3 = 1;
                else if (second4 == 0)
                    as4 = 1;
                else if (second5 == 0)
                    as5 = 1;
                else
                    sfRenderWindow_setMouseCursorVisible(window,sfTrue);
                    }
            }
        }

        if (event.mouseButton.x >= pos51.x && event.mouseButton.x
            <= pos51.x + 100) {
           if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && event.mouseButton.y >= pos51.y && event.mouseButton.y
                <= pos51.y + 100){
                    if (as6 == 0 && as7 == 0 && as8 == 0 && as9 == 0 && as10 == 0 && argent >= 150) {
                sfRenderWindow_setMouseCursorVisible(window,sfFalse);
                argent -= 150;
                sfText_setString(text, my_putnbr(argent));
                if (second6 == 0)
                    as6 = 1;
                else if (second7 == 0)
                    as7 = 1;
                else if (second8 == 0)
                    as8 = 1;
                else if (second9 == 0)
                    as9 = 1;
                else if (second10 == 0)
                    as10 = 1;
                else
                    sfRenderWindow_setMouseCursorVisible(window,sfTrue);
                    }
            }
        }

        if (event.mouseButton.x >= pos52.x && event.mouseButton.x
            <= pos52.x + 100) {
           if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && event.mouseButton.y >= pos52.y && event.mouseButton.y
                <= pos52.y + 100){
                    if (as11 == 0 && as12 == 0 && as13 == 0 && as14 == 0 && as15 == 0 && argent >= 150) {
                sfRenderWindow_setMouseCursorVisible(window,sfFalse);
                argent -= 150;
                sfText_setString(text, my_putnbr(argent));
                if (second11 == 0)
                    as11 = 1;
                else if (second12 == 0)
                    as12 = 1;
                else if (second13 == 0)
                    as13 = 1;
                else if (second14 == 0)
                    as14 = 1;
                else if (second15 == 0)
                    as15 = 1;
                else
                    sfRenderWindow_setMouseCursorVisible(window,sfTrue);
                    }
            }
        }

        if (event.mouseButton.x >= pos53.x && event.mouseButton.x
            <= pos53.x + 100) { 
          if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && event.mouseButton.y >= pos53.y && event.mouseButton.y
                <= pos53.y + 100){
                    if (as16 == 0 && as17 == 0 && as18 == 0 && as19 == 0 && as20 == 0 && argent >= 150) {
                sfRenderWindow_setMouseCursorVisible(window,sfFalse);
                argent -= 150;
                sfText_setString(text, my_putnbr(argent));
                if (second16 == 0)
                    as16 = 1;
                else if (second17 == 0)
                    as17 = 1;
                else if (second18 == 0)
                    as18 = 1;
                else if (second19 == 0)
                    as19 = 1;
                else if (second20 == 0)
                    as20 = 1;
                else
                    sfRenderWindow_setMouseCursorVisible(window,sfTrue);
                    }
            }
        }

        if (event.mouseButton.x >= pos54.x && event.mouseButton.x
            <= pos54.x + 100) {
if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && event.mouseButton.y >= pos54.y && event.mouseButton.y
                <= pos54.y + 100){
                    if (as21 == 0 && as22 == 0 && as23 == 0 && as24 == 0 && as25 == 0 && argent >= 250) {
                sfRenderWindow_setMouseCursorVisible(window,sfFalse);
                argent -= 250;
                sfText_setString(text, my_putnbr(argent));
                if (second21 == 0)
                    as21 = 1;
                else if (second22 == 0)
                    as22 = 1;
                else if (second23 == 0)
                    as23 = 1;
                else if (second24 == 0)
                    as24 = 1;
                else if (second25 == 0)
                    as25 = 1;
                else
                    sfRenderWindow_setMouseCursorVisible(window,sfTrue);
                    }
            }          
        }



/* Voir les tourelles */

        if (event.mouseButton.x >= pos20.x && event.mouseButton.x
            <= pos20.x + 300) {
            if (event.mouseButton.y >= pos20.y && event.mouseButton.y
                <= pos20.y + 300){
                dans_menu = 2;

                while (in_game == 1 && dans_menu == 2)
                {
                

                
                    while (sfRenderWindow_pollEvent(window,&event)) {

                        sfSprite_setPosition(sprite21,pos21);
                        sfRenderWindow_drawSprite(window, sprite21, NULL);


                        sfSprite_setPosition(sprite22,pos22);
                        sfRenderWindow_drawSprite(window, sprite22, NULL);
                        
                        sfSprite_setPosition(sprite23,pos23);
                        sfRenderWindow_drawSprite(window, sprite23, NULL);
                        
                        sfSprite_setPosition(sprite24,pos24);
                        sfRenderWindow_drawSprite(window, sprite24, NULL);
                        
                        sfSprite_setPosition(sprite25,pos25);
                        sfRenderWindow_drawSprite(window, sprite25, NULL);

                        sfSprite_setPosition(sprite26,pos26);
                        sfRenderWindow_drawSprite(window, sprite26, NULL);


                        sfSprite_setPosition(sprite27,pos27);
                        sfRenderWindow_drawSprite(window, sprite27, NULL);

	                    sfSprite_setPosition(sprite28,pos28);
                        sfRenderWindow_drawSprite(window, sprite28, NULL);

                        sfSprite_setPosition(sprite29,pos29);
                        sfRenderWindow_drawSprite(window, sprite29, NULL);

                        sfSprite_setPosition(sprite30,pos30);
                        sfRenderWindow_drawSprite(window, sprite30, NULL);




                        sfRenderWindow_display(window);


                        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn)
                            dans_menu = 0;
                    }
                }
            }
        }


/*Pause*/
        while (sfRenderWindow_pollEvent(window,&event))//s                                                                                                                                   
        {
            if (as1 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite100, cursor_pos);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as1 == 1)
                        {
                            as1 = 0;
                            second1 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }



          if (as2 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos2 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite101, cursor_pos2);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as2 == 1)
                        {
                            as2 = 0;
                            second2 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }


          if (as3 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos3 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite102, cursor_pos3);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as3 == 1)
                        {
                            as3 = 0;
                            second3 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }




          if (as4 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos4 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite103, cursor_pos4);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as4 == 1)
                        {
                            as4 = 0;
                            second4 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }







          if (as5 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos5 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite104, cursor_pos5);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as5 == 1)
                        {
                            as5 = 0;
                            second5 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }



if (as6 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos6 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite105, cursor_pos6);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as6 == 1)
                        {
                            as6 = 0;
                            second6 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }

if (as7 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos7 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite106, cursor_pos7);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as7 == 1)
                        {
                            as7 = 0;
                            second7 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }

if (as8 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos8 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite107, cursor_pos8);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as8 == 1)
                        {
                            as8 = 0;
                            second8 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }




if (as9 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos9 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite108, cursor_pos9);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as9 == 1)
                        {
                            as9 = 0;
                            second9 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }




if (as10 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos10 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite109, cursor_pos10);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as10 == 1)
                        {
                            as10 = 0;
                            second10 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }

if (as11 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos11 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite110, cursor_pos11);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as11 == 1)
                        {
                            as11 = 0;
                            second11 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }



          if (as12 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos12 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite111, cursor_pos12);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as12 == 1)
                        {
                            as12 = 0;
                            second12 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }


          if (as13 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos13 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite112, cursor_pos13);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as13 == 1)
                        {
                            as13 = 0;
                            second13 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }




          if (as14 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos14 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite113, cursor_pos14);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as14 == 1)
                        {
                            as14 = 0;
                            second14 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }







          if (as15 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos15 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite114, cursor_pos15);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as15 == 1)
                        {
                            as15 = 0;
                            second15 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }



if (as16 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos16 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite115, cursor_pos16);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as16 == 1)
                        {
                            as16 = 0;
                            second16 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }

if (as17 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos17 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite116, cursor_pos17);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as17 == 1)
                        {
                            as17 = 0;
                            second17 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }

if (as18 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos18 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite117, cursor_pos18);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as18 == 1)
                        {
                            as18 = 0;
                            second18 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }




if (as19 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos19 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite118, cursor_pos19);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as19 == 1)
                        {
                            as19 = 0;
                            second19 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }




if (as20 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos20 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite119, cursor_pos20);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as20 == 1)
                        {
                            as20 = 0;
                            second20 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }


if (as21 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos21 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite120, cursor_pos21);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as21 == 1)
                        {
                            as21 = 0;
                            second21 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }



          if (as22 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos22 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite121, cursor_pos22);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as22 == 1)
                        {
                            as22 = 0;
                            second22 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }


          if (as23 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos23 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite122, cursor_pos23);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as23 == 1)
                        {
                            as23 = 0;
                            second23 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }




          if (as24 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos24 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite123, cursor_pos24);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as24 == 1)
                        {
                            as24 = 0;
                            second24 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }

if (as25 == 1 && event.type == sfEvtMouseMoved) {
                sfVector2f cursor_pos25 = {event.mouseMove.x, event.mouseMove.y};
                sfSprite_setPosition(sprite124, cursor_pos25);

            }
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && as25 == 1)
                        {
                            as25 = 0;
                            second25 = 1;
                            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
                        }

            if (event.type == sfEvtClosed) {//s                                                                                                                                               
                sfRenderWindow_close(window);//s                                                                                                                                              
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {

                dans_menu = 1;

                while (in_game == 1 && dans_menu == 1) {
                    while (sfRenderWindow_pollEvent(window,&event)) {
                        

                        /* retour au menu */
                        if (event.mouseButton.x >= pos15.x && event.mouseButton.x
                            <= pos15.x + 300) {
                            if (event.mouseButton.y >= pos15.y && event.mouseButton.y
                                <= pos15.y + 300){

                                in_game = 1;
                                dans_menu = 0; 
                                break;
                            }
                        }
                        /* reprendre  */
                        if (event.mouseButton.x >= pos14.x && event.mouseButton.x
                            <= pos14.x + 380) {
                            if (event.mouseButton.y >= pos14.y && event.mouseButton.y
                                <= pos14.y + 380){
                                dans_menu = 0;
                                break ;
                            }
                        }
                        /* quitter */
                        if (event.mouseButton.x >= pos13.x && event.mouseButton.x
                            <= pos13.x + 380) {
                            if (event.mouseButton.y >= pos13.y && event.mouseButton.y
                                <= pos13.y + 380){
                                sfSprite_destroy(sprite10);
                                sfSprite_destroy(sprite11);
                                sfSprite_destroy(sprite50);
                                sfSprite_destroy(sprite51);
                                sfSprite_destroy(sprite52);
                                sfSprite_destroy(sprite53);
                                sfSprite_destroy(sprite54);
                                sfSprite_destroy(sprite13);
                                sfSprite_destroy(sprite14);
                                sfSprite_destroy(sprite15);
                                sfSprite_destroy(sprite20);
                                sfTexture_destroy(texture10);
                                sfTexture_destroy(texture11);
                                sfTexture_destroy(texture50);
                                sfTexture_destroy(texture51);
                                sfTexture_destroy(texture52);
                                sfTexture_destroy(texture53);
                                sfTexture_destroy(texture54);
                                sfTexture_destroy(texture13);
                                sfTexture_destroy(texture14);
                                sfTexture_destroy(texture15);
                                sfTexture_destroy(texture20);
                                sfSound_destroy(sound2);
                                sfSoundBuffer_destroy(soundbuffer2);
                                sfRenderWindow_destroy(window);

                                return (0);
                            }
                        }


                        //  if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn)
                        //    dans_menu = 0;
                    }
                    sfSprite_setTextureRect(sprite13,rect12);
                    sfSprite_setPosition(sprite13,pos13);
                    sfRenderWindow_drawSprite(window, sprite13, NULL);

                    sfSprite_setTextureRect(sprite14,rect13);
                    sfSprite_setPosition(sprite14,pos14);
                    sfRenderWindow_drawSprite(window, sprite14, NULL);

                    sfSprite_setTextureRect(sprite15,rect14);
                    sfSprite_setPosition(sprite15,pos15);
                    sfRenderWindow_drawSprite(window, sprite15, NULL);



                    sfRenderWindow_display(window);

                }
            }
        }

        if (event.mouseButton.type == sfEvtMouseButtonReleased)//s
        {
            if (in_game == 0) {
/* Lancer le jeu */
                if (event.mouseButton.x >= pos.x && event.mouseButton.x//s
                    <= pos.x + 380) {//s
                    if (event.mouseButton.y >= pos.y && event.mouseButton.y//s
                        <= pos.y + 380){//s
                        rect.left = 400;//s
                        sfSprite_setTextureRect(sprite2,rect);//s
                        in_game = 1;//s
                        sfSprite_destroy(sprite);//s
                        sfSprite_destroy(sprite2);//s
                        sfSound_destroy(sound);//s
                        sfSoundBuffer_destroy(soundbuffer);//s
                        /*Son du jeu*/
                        soundbuffer2 = sfSoundBuffer_createFromFile("sweets-parade-full-english-lyrics.ogg");
                        sound2 = sfSound_create();
                        sfSound_setBuffer(sound2, soundbuffer2);
                        sfSound_play(sound2);
                        sfSound_setVolume(sound2, 3);
                        sfSound_setLoop(sound2, sfTrue);
                        sfSound_getLoop(sound2);

                    }//s
                }//s
/* Bouton quitter */
                if (event.mouseButton.x >= pos2.x && event.mouseButton.x
                    <= pos2.x + 280) {
                    if (event.mouseButton.y >= pos2.y && event.mouseButton.y
                        <= pos2.y + 280){
                        sfSprite_destroy(sprite);
                        sfSprite_destroy(sprite2);
                        sfSprite_destroy(sprite3);
                        sfTexture_destroy(texture);
                        sfTexture_destroy(texture2);
                        sfTexture_destroy(texture3);
                        sfSound_destroy(sound);
                        sfSoundBuffer_destroy(soundbuffer);
                        sfRenderWindow_destroy(window);
                        return (0);
                    }

                }
            }
        }

        sfRenderWindow_clear(window, sfBlack);//s

        if (in_game == 1)
        {
            sfRenderWindow_drawSprite(window, sprite10, NULL);
            sfRenderWindow_drawSprite(window, sprite11, NULL);
            sfRenderWindow_drawSprite(window, sprite50, NULL);
            sfRenderWindow_drawSprite(window, sprite51, NULL);
            sfRenderWindow_drawSprite(window, sprite52, NULL);
            sfRenderWindow_drawSprite(window, sprite53, NULL);
            sfRenderWindow_drawSprite(window, sprite54, NULL);
            sfRenderWindow_drawSprite(window, sprite20, NULL);
            sfRenderWindow_drawSprite(window, sprite1000, NULL);
            sfRenderWindow_drawText(window,text, NULL);

            int secours1 = 0;
            if (as1 == 1 || second1 == 1) {
                sfRenderWindow_drawSprite(window, sprite100, NULL);
                secours1 = 1;
                }
            if (as2 == 1 || second2 == 1) {
                sfRenderWindow_drawSprite(window, sprite101, NULL);
                }
            if (as3 == 1 || second3 == 1) {
                sfRenderWindow_drawSprite(window, sprite102, NULL);
                }
            if (as4 == 1 || second4 == 1) {
                sfRenderWindow_drawSprite(window, sprite103, NULL);
                }
            if (as5 == 1 || second5 == 1) {
                sfRenderWindow_drawSprite(window, sprite104, NULL);
                }
            
            if (as6 == 1 || second6 == 1) {
                sfRenderWindow_drawSprite(window, sprite105, NULL);
                }
            if (as7 == 1 || second7 == 1) {
                sfRenderWindow_drawSprite(window, sprite106, NULL);
                }
            if (as8 == 1 || second8 == 1) {
                sfRenderWindow_drawSprite(window, sprite107, NULL);
                }
            if (as9 == 1 || second9 == 1) {
                sfRenderWindow_drawSprite(window, sprite108, NULL);
                }
            if (as10 == 1 || second10 == 1) {
                sfRenderWindow_drawSprite(window, sprite109, NULL);
                }

            if (as11 == 1 || second11 == 1) {
                sfRenderWindow_drawSprite(window, sprite110, NULL);
                }
            if (as12 == 1 || second12 == 1) {
                sfRenderWindow_drawSprite(window, sprite111, NULL);
                }
            if (as13 == 1 || second13 == 1) {
                sfRenderWindow_drawSprite(window, sprite112, NULL);
                }
            if (as14 == 1 || second14 == 1) {
                sfRenderWindow_drawSprite(window, sprite113, NULL);
                }
            if (as15 == 1 || second15 == 1) {
                sfRenderWindow_drawSprite(window, sprite114, NULL);
                }
            
            if (as16 == 1 || second16 == 1) {
                sfRenderWindow_drawSprite(window, sprite115, NULL);
                }
            if (as17 == 1 || second17 == 1) {
                sfRenderWindow_drawSprite(window, sprite116, NULL);
                }
            if (as18 == 1 || second18 == 1) {
                sfRenderWindow_drawSprite(window, sprite117, NULL);
                }
            if (as19 == 1 || second19 == 1) {
                sfRenderWindow_drawSprite(window, sprite118, NULL);
                }
            if (as20 == 1 || second20 == 1) {
                sfRenderWindow_drawSprite(window, sprite119, NULL);
                }
            
            if (as21 == 1 || second21 == 1) {
                sfRenderWindow_drawSprite(window, sprite120, NULL);
                }
            if (as22 == 1 || second22 == 1) {
                sfRenderWindow_drawSprite(window, sprite121, NULL);
                }
            if (as23 == 1 || second23 == 1) {
                sfRenderWindow_drawSprite(window, sprite122, NULL);
                }
            if (as24 == 1 || second24 == 1) {
                sfRenderWindow_drawSprite(window, sprite123, NULL);
                }
            if (as25 == 1 || second25 == 1) {
                sfRenderWindow_drawSprite(window, sprite124, NULL);
                }

        float v = 0.1;
        sfFloatRect monstre666 = sfSprite_getGlobalBounds(sprite11);

        if (second1 == 1 && hit100 == 0) {
 
        sfFloatRect tourelle1 = sfSprite_getGlobalBounds(sprite100);
        if (sfFloatRect_intersects(&monstre666, &tourelle1, NULL) == sfTrue)
        {

           x = 0.5;
           hit100 = 1;
        }
    }


     if (second2 == 1 && hit101 == 0) {
   
        sfFloatRect tourelle2 = sfSprite_getGlobalBounds(sprite101);
        if (sfFloatRect_intersects(&monstre666, &tourelle2, NULL) == sfTrue)
        {
          hit101 = 1;
         x = 0.25;

        }
    }

     if (second3 == 1 && hit102 == 0) {
   
        sfFloatRect tourelle3 = sfSprite_getGlobalBounds(sprite102);
        if (sfFloatRect_intersects(&monstre666, &tourelle3, NULL) == sfTrue)
        {
          hit102 = 1;
          x = 0.1225;
        }
    }


     if (second4 == 1 && hit103 == 0) {
   
        sfFloatRect tourelle4 = sfSprite_getGlobalBounds(sprite103);
        if (sfFloatRect_intersects(&monstre666, &tourelle4, NULL) == sfTrue)
        {
          hit103 = 1;
          x = 0.06125;
        }
    }


     if (second5 == 1 && hit104 == 0) {
   
        sfFloatRect tourelle5 = sfSprite_getGlobalBounds(sprite104);
        if (sfFloatRect_intersects(&monstre666, &tourelle5, NULL) == sfTrue)
        {
            hit104 = 1;
          x = 0.030625;
        }
    }

        if (second6 == 1 && hit105 == 0) {
 
        sfFloatRect tourelle6 = sfSprite_getGlobalBounds(sprite105);
        if (sfFloatRect_intersects(&monstre666, &tourelle6, NULL) == sfTrue)
        {
          vie2 = monstre_vie;
           monstre_vie = monstre_vie - 5;
           hit105 = 1;
        }
    }

     if (second7 == 1 && hit106 == 0) {
   
        sfFloatRect tourelle7 = sfSprite_getGlobalBounds(sprite106);
        if (sfFloatRect_intersects(&monstre666, &tourelle7, NULL) == sfTrue)
        {
          hit106 = 1;
           vie2 = monstre_vie;
           monstre_vie = monstre_vie - 5;
        }
    }


     if (second8 == 1 && hit107 == 0) {
   
        sfFloatRect tourelle8 = sfSprite_getGlobalBounds(sprite107);
        if (sfFloatRect_intersects(&monstre666, &tourelle8, NULL) == sfTrue)
        {
          hit107 = 1;
           vie2 = monstre_vie;
           monstre_vie = monstre_vie - 5;
        }
    }

     if (second9 == 1 && hit108 == 0) {
   
        sfFloatRect tourelle9 = sfSprite_getGlobalBounds(sprite108);
        if (sfFloatRect_intersects(&monstre666, &tourelle9, NULL) == sfTrue)
        {
          hit108 = 1;
           vie2 = monstre_vie;
           monstre_vie = monstre_vie - 5;
        }
    }

     if (second10 == 1 && hit109 == 0) {
   
        sfFloatRect tourelle10 = sfSprite_getGlobalBounds(sprite109);
        if (sfFloatRect_intersects(&monstre666, &tourelle10, NULL) == sfTrue)
        {
          hit109 = 1;
           vie2 = monstre_vie;
           monstre_vie = monstre_vie - 5;
        }
    }

    if (second11 == 1 && hit110 == 0) {
 
        sfFloatRect tourelle11 = sfSprite_getGlobalBounds(sprite110);
        if (sfFloatRect_intersects(&monstre666, &tourelle11, NULL) == sfTrue)
        {
          
           vie2 = monstre_vie;
           monstre_vie = monstre_vie - 10;
           hit110 = 1;
        }
    }


     if (second12 == 1 && hit111 == 0) {
   
        sfFloatRect tourelle12 = sfSprite_getGlobalBounds(sprite111);
        if (sfFloatRect_intersects(&monstre666, &tourelle12, NULL) == sfTrue)
        {
          hit111 = 1;
           vie2 = monstre_vie;
           monstre_vie = monstre_vie - 10;
        }
    }

     if (second13 == 1 && hit112 == 0) {
   
        sfFloatRect tourelle13 = sfSprite_getGlobalBounds(sprite112);
        if (sfFloatRect_intersects(&monstre666, &tourelle13, NULL) == sfTrue)
        {
          hit112 = 1;
           vie2 = monstre_vie;
           monstre_vie = monstre_vie - 10;
        }
    }


     if (second14 == 1 && hit113 == 0) {
   
        sfFloatRect tourelle14 = sfSprite_getGlobalBounds(sprite113);
        if (sfFloatRect_intersects(&monstre666, &tourelle14, NULL) == sfTrue)
        {
          hit113 = 1;
           vie2 = monstre_vie;
           monstre_vie = monstre_vie - 10;
        }
    }

     if (second15 == 1 && hit114 == 0) {
   
        sfFloatRect tourelle15 = sfSprite_getGlobalBounds(sprite114);
        if (sfFloatRect_intersects(&monstre666, &tourelle15, NULL) == sfTrue)
        {
          hit114 = 1;
           vie2 = monstre_vie;
           monstre_vie = monstre_vie - 10;
        }
    }


    if (second16 == 1 && hit115 == 0) {
   
        sfFloatRect tourelle16 = sfSprite_getGlobalBounds(sprite115);
        if (sfFloatRect_intersects(&monstre666, &tourelle16, NULL) == sfTrue)
        {
          hit115 = 1;
          argent = argent + 50;
          sfText_setString(text, my_putnbr(argent));
        }
    }

    if (second17 == 1 && hit116 == 0) {
   
        sfFloatRect tourelle17 = sfSprite_getGlobalBounds(sprite116);
        if (sfFloatRect_intersects(&monstre666, &tourelle17, NULL) == sfTrue)
        {
          hit116 = 1;
          argent = argent + 50;
          sfText_setString(text, my_putnbr(argent));
        }
    }


    if (second18 == 1 && hit117 == 0) {
   
        sfFloatRect tourelle18 = sfSprite_getGlobalBounds(sprite117);
        if (sfFloatRect_intersects(&monstre666, &tourelle18, NULL) == sfTrue)
        {
          hit117 = 1;
          argent = argent + 50;
          sfText_setString(text, my_putnbr(argent));
        }
    }

    if (second19 == 1 && hit118 == 0) {
   
        sfFloatRect tourelle19 = sfSprite_getGlobalBounds(sprite118);
        if (sfFloatRect_intersects(&monstre666, &tourelle19, NULL) == sfTrue)
        {
          hit118 = 1;
          argent = argent + 50;
          sfText_setString(text, my_putnbr(argent));
        }
    }


    if (second20 == 1 && hit119 == 0) {
   
        sfFloatRect tourelle20 = sfSprite_getGlobalBounds(sprite119);
        if (sfFloatRect_intersects(&monstre666, &tourelle20, NULL) == sfTrue)
        {
          hit119 = 1;
          argent = argent + 50;
         sfText_setString(text, my_putnbr(argent));
        }
    }

   if (second21 == 1 && hit120 == 0) {
   
        sfFloatRect tourelle21 = sfSprite_getGlobalBounds(sprite120);
        if (sfFloatRect_intersects(&monstre666, &tourelle21, NULL) == sfTrue)
        {
          hit120 = 1;
          argent = argent + 25;
           vie2 = monstre_vie;
          monstre_vie = monstre_vie - 10;
          sfText_setString(text, my_putnbr(argent));
        }
    }


 if (second22 == 1 && hit121 == 0) {
   
        sfFloatRect tourelle22 = sfSprite_getGlobalBounds(sprite121);
        if (sfFloatRect_intersects(&monstre666, &tourelle22, NULL) == sfTrue)
        {
          hit121 = 1;
          argent = argent + 25;
           vie2 = monstre_vie;
          monstre_vie = monstre_vie - 10;
          sfText_setString(text, my_putnbr(argent));
        }
    }


 if (second23 == 1 && hit122 == 0) {
   
        sfFloatRect tourelle23 = sfSprite_getGlobalBounds(sprite122);
        if (sfFloatRect_intersects(&monstre666, &tourelle23, NULL) == sfTrue)
        {
          hit122 = 1;
          argent = argent + 25;
           vie2 = monstre_vie;
          monstre_vie = monstre_vie - 10;
         sfText_setString(text, my_putnbr(argent));
        }
    }


 if (second24 == 1 && hit123 == 0) {
   
        sfFloatRect tourelle24 = sfSprite_getGlobalBounds(sprite123);
        if (sfFloatRect_intersects(&monstre666, &tourelle24, NULL) == sfTrue)
        {
          hit123 = 1;
          argent = argent + 25;
           vie2 = monstre_vie;
          monstre_vie = monstre_vie - 10;
         sfText_setString(text, my_putnbr(argent));
        }
    }


 if (second25 == 1 && hit124 == 0) {
   
        sfFloatRect tourelle25 = sfSprite_getGlobalBounds(sprite124);
        if (sfFloatRect_intersects(&monstre666, &tourelle25, NULL) == sfTrue)
        {
          hit124 = 1;
          argent = argent + 25;
          argent = argent + 25;
          monstre_vie = monstre_vie - 10;
         sfText_setString(text, my_putnbr(argent));
        }
 }

        }
        sfVector2f pas_les_boobs = {230, 470};
        if (in_game == 0) {//s
            sfRenderWindow_drawSprite(window, sprite, NULL);//s
            sfRenderWindow_drawSprite(window, sprite2, NULL);//s
            sfRenderWindow_drawSprite(window, sprite3, NULL);
        }//s
        sfRenderWindow_display(window);//s
    }//s
    if (in_game == 0) {//s
        sfSprite_destroy(sprite);//s
        sfSprite_destroy(sprite2);//s
        sfSoundBuffer_destroy(soundbuffer);//s
        sfSound_destroy(sound);//s
    }//s
    sfTexture_destroy(texture);//s
    sfTexture_destroy(texture2);//s
    sfTexture_destroy(texture3);
    sfRenderWindow_destroy(window);//s

    return (0);//s
}
