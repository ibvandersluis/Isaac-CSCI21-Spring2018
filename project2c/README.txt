Whether a stack or queue is used, the outcomes are the same: the same number of
games are played, and the winner is the same. This is true regardless of how
many players are in the tournament. But the procedure is significantly
different.

I tested these scenarios:
    stack - 4 players
    queue - 4 players
    stack - 16 players
    queue - 16 players

Using a stack creates a tournament style where there is a
"challenger", and any player who beats the challenger becomes the challenger
themselves. Whoever is the challenger at the end is the winner. In this style,
the number of games played per person is not distributed very evenly: most
players only play one game, maybe a few, and a couple players play many games.

On the other hand, using a queue creates what some may consider a more
traditional tournament. Everyone is broken off into pairs, who playe each other.
The winners of those rounds go on to the next, and the losers are out. Repeat
until there is a winner. The number of games played tend to be more evenly
distributed: half of the players will play 1 game, half again will play 2, half
again 3, and so on.

Since the outcomes are the same no matter which is used, neither one is
particularly better. But in a real-world environment, a queue-based tournament
would be both faster (because multiple matches could take place at the same
time) and more enjoyable for everyone involved. Queue-based tournaments are
the way to go.