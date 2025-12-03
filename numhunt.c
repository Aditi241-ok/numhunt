#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print analysis after game ends
void showAnalysis(int attempts, int secret, int won) {
    printf("\n===== GAME ANALYSIS =====\n");
    printf("Secret Number was: %d\n", secret);
    printf("Total Attempts Used: %d\n", attempts);

    if (won)
        printf("Result: YOU WON! 🎉\n");
    else
        printf("Result: YOU LOST! 😢\n");

    if (attempts <= 3)
        printf("Performance: 🔥 Excellent! Sharp mind!\n");
    else if (attempts <= 5)
        printf("Performance: 👍 Good job, keep improving!\n");
    else
        printf("Performance: 🙂 Needs practice, you got this!\n");

    printf("==========================\n");
}

int main() {
    int secret, guess, lives = 7, attempts = 0, won = 0;

    srand(time(0));  
    secret = rand() % 100 + 1;

    printf("\n🎮 NUMBER HUNT ADVENTURE 🎮\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("You have 7 lives. Good luck!\n\n");

    while (lives > 0) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == secret) {
            printf("\n✨ Correct! You found the number!\n");
            won = 1;
            break;
        }

        lives--;  // lose a life

        if (guess > secret) {
            if (guess - secret <= 5)
                printf("Hint: 🔥 Slightly High! Lives left: %d\n\n", lives);
            else
                printf("Hint: Too High! Lives left: %d\n\n", lives);
        } 
        else {
            if (secret - guess <= 5)
                printf("Hint: 🔥 Slightly Low! Lives left: %d\n\n", lives);
            else
                printf("Hint: Too Low! Lives left: %d\n\n", lives);
        }
    }

    // Show final analysis
    showAnalysis(attempts, secret, won);

    return 0;
}
