#include <stdio.h>
#include <stdlib.h>

#define ITEMS_PER_SIDE 3

/** Enumeration type for the possible actions the user can pick in the puzzle game */
typedef enum {move_boat, move_wolf, move_goat, move_cabbage} action_e;
/** Enumeration type for the two sides of the river (used to indicate the position of the boat). */
typedef enum {left, right} side_e;

/* TODO: Define an enumeration type named item_e that can hold the different items/animals (wolf, goat and gabbage),
 *       as well as a value (none) indicating that there is no item.
 */



/**
 * Interactively lets the user play the puzzle game
 * @return whether the user succeeded or not.
 */
int play_puzzle();

/**
 * TODO: This function should implement the logic that checks if the side is safe,
 *       i.e. that the wolf doesn't eat the goat and the goat doesn't eat the cabbage.
 * @param side Array of items or empty places on the given side of the river
 * @return 1 (true) if the side is safe, or 0 (false) if either the wolf and goat is together on the side,
 *         or the goat and the cabbage is together on the side.
 */
int is_safe(item_e side[]);

/**
 * TODO: This function should implement the logic that checks if all three items/animals (wolf, goat and cabbage) is on the given side.
 * @param side Array of items or empty places on the given side of the river
 * @return 1 (true) if the all three items are on the given side, or 0 (false) otherwise.
 */
int all_items_on(item_e side[]);

/**
 * Prompts the user for an action to move the boat or move one of the items/animals (wolf, goat or cabbage).
 * @return the chosen action as an action_e enum.
 */
action_e input_action();

/**
 * Perform the given action. This may update the item_on_boat, boat_position, left_side and/or right_side
 * @param action The action to perform
 * @param item_on_boat The item (if any) that is currently on the boat.
 * @param boat_position The current position (left or right) of the boat.
 * @param side Array of the items or empty places on the side of the river where the boat currently is.
 */
void do_action(action_e action, item_e *item_on_boat, side_e *boat_position, item_e side[]);

/**
 * Moves the given item (if present) between the boat and the side of the river
 */
void move_item(item_e item_to_move, item_e *item_on_boat, item_e side[]);

/**
 * Searches for the item in the side array
 * @param item The item to search for
 * @param side The array of items or empty places to search
 * @return a pointer to the location of the item, or NULL if the item was not found.
 */
item_e* find_item(item_e item, item_e side[]);

/**
 * Swaps the items at the locations pointed to by the pointers a and b.
 */
void swap(item_e *a, item_e *b);

/**
 * Prints to console the current state of the river sides and the boat.
 */
void print_scene(item_e left_side[], item_e right_side[], item_e item_on_boat, side_e boat_position);

/**
 * Converts the item of enum type item_e to a corresponding char value for console output.
 */
char item_to_char(item_e item);


int main(void) {
    int result = play_puzzle();
    if (result) {
        printf("Success!!\n");
    } else {
        printf("Failure :(\n");
    }
    return 0;
}

int play_puzzle() {
    side_e boat_position = left; // The side of the river that the boat and farmer is currently on.
    item_e item_on_boat = none;  // The item (wolf, goat, cabbage), if any, that is currently with the farmer on the boat.
    item_e left_side[ITEMS_PER_SIDE] = {wolf, goat, cabbage}; // The items (or empty slots) on the left side of the river.
    item_e right_side[ITEMS_PER_SIDE] = {none, none, none};   // The items (or empty slots) on the right side of the river.

    print_scene(left_side, right_side, item_on_boat, boat_position);
    do {
        action_e action = input_action();
        item_e *current_side = boat_position == left ? left_side : right_side;
        do_action(action, &item_on_boat, &boat_position, current_side);
        print_scene(left_side, right_side, item_on_boat, boat_position);

        item_e *other_side = boat_position == left ? right_side : left_side;
        if (!is_safe(other_side)) { // If the other side, from where the farmer and boat are, is not safe, the game ends.
            return 0;
        }
    } while (!all_items_on(right_side));
    return 1;
}

int is_safe(item_e side[]) {
    /* TODO: Implement the logic that checks if the side is safe, i.e. the wolf doesn't eat the goat and the goat doesn't eat the cabbage.
     *  HINT: You can use the function find_item(item, side) to check if item is on this side of the river.
     */
    return 1;
}

int all_items_on(item_e side[]) {
    /* TODO: Implement the logic that checks if all three items/animals (wolf, goat and cabbage) is on the given side.
     *  HINT: You can use the function find_item(item, side) to check if item is on this side of the river.
     */
    return 0;
}

action_e input_action() {
    printf("\nChoose who to move: wolf (w), goat (g), cabbage (c), boat(b)");
    char action;
    scanf(" %c", &action);
    switch (action) {
    case 'w':
        return move_wolf;
    case 'g':
        return move_goat;
    case 'c':
        return move_cabbage;
    case 'b':
        return move_boat;
    default:
        printf("Invalid action: %c\n", action);
        exit(EXIT_FAILURE);
    }
}

void do_action(action_e action, item_e *item_on_boat, side_e *boat_position, item_e side[]) {
    switch (action) {
    case move_wolf:
        move_item(wolf, item_on_boat, side);
        break;
    case move_goat:
        move_item(goat, item_on_boat, side);
        break;
    case move_cabbage:
        move_item(cabbage, item_on_boat, side);
        break;
    case move_boat:
        *boat_position = *boat_position == left ? right : left;
        break;
    }
}

void move_item(item_e item_to_move, item_e *item_on_boat, item_e side[]) {
    if (item_to_move == *item_on_boat) {
        item_to_move = none; // If the item is on the boat, find an empty place on the current_side to swap with the boat.
    }
    item_e *found_item = find_item(item_to_move, side);
    if (found_item != NULL) {
        swap(found_item, item_on_boat);
    }
}

item_e* find_item(item_e item, item_e side[]) {
    for (int i = 0; i < ITEMS_PER_SIDE; i++) {
        if (side[i] == item) return &side[i];
    }
    return NULL;
}

void swap(item_e *a, item_e *b) {
    const item_e temp = *a;
    *a = *b;
    *b = temp;
}

void print_scene(item_e left_side[], item_e right_side[], item_e item_on_boat, side_e boat_position) {
    for (int i = 0; i < ITEMS_PER_SIDE; i++) {
        printf("%c | ~ ~ ~ ~ | %c\n", item_to_char(left_side[i]), item_to_char(right_side[i]));
    }
    printf("  %c%c~ ~ ~ ~%c%c  \n",
           boat_position == left ? item_to_char(item_on_boat) : ' ',
           boat_position == left ? 'b' : ' ',
           boat_position == right ? 'b' : ' ',
           boat_position == right ? item_to_char(item_on_boat) : ' ');
}

char item_to_char(item_e item) {
    switch (item) {
    case wolf:
        return 'w';
    case goat:
        return 'g';
    case cabbage:
        return 'c';
    case none:
    default:
        return ' ';
    }
}
