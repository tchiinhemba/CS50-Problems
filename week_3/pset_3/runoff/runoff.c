#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Get number of voters
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Query for each voter's preferences
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank (preference) of the voter
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record the vote, if valid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until a winner is determined
    while (true)
    {
        // Calculate votes based on remaining candidates
        tabulate();

        // Check if a candidate has won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, all remaining candidates are winners
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate candidates with the minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Search for the candidate by name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // If found, store their index in the preferences array for the voter
            preferences[voter][rank] = i;
            return true;
        }
    }
    // If the name doesn't match any candidate, return false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Iterate over each voter
    for (int i = 0; i < voter_count; i++)
    {
        // For each voter, check their highest-ranked candidate that has not been eliminated
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)
            {
                // Count the vote for that candidate
                candidates[candidate_index].votes++;
                break; // Stop looking at further preferences for this voter
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // A winner must have more than half the total votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name); // Print the winner's name
            return true;
        }
    }
    return false;
}

// Find the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_votes = voter_count; // Start with the highest possible number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes; // Update the minimum votes found
        }
    }
    return min_votes;
}

// Return true if the election is tied between all remaining candidates
bool is_tie(int min)
{
    // Check if all remaining candidates have the same number of votes (min)
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false; // Not a tie if any candidate has different votes
        }
    }
    return true; // It's a tie if all remaining candidates have the same votes
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Eliminate all candidates with the minimum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
