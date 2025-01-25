#include <stdio.h>

#include "game.h"



int main()
{
    t_game * g = game_init();

    game_loop(g);
    return 0;
}

void game_loop(t_game * g)
{

    print_player_coins(g->player); // Afficher le nombre de jetons du joueur
    broker_new_hand(g); // Le croupier pioche
    player_new_hand(g); // Le joueur pioce
    print_player_hand(g->player); // Afficher la main du joueur
    broker_place_bet(g); // Le croupier mise
    player_place_bet(g); // Le joueur mise
    sum_player_hand(g->player); /* Le joueur choisi la valeur de ses Valets (1
    ou 11) et cette function "return" le score du joueur */
    int p_hand = sum_player_hand(g->player);
    print_turn_results(g, p_hand); /* Afficher le score du croupier et du
    joueur (le score du joueur doit être donné par la variable p_hand) */ 


    if (p_hand > 21)
    {
        player_lost(g); // Le joueur perd
        player_breakthrough(g);
    }
    else if (p_hand < 22)
    {
        player_ask_cards(g);
        player_win(g); // Le joueur gagne
    }



 /*   if (p_hand == 21)
    {
            player_jackpot(g); // Le joueur fait 21
    }

    */ 
}

