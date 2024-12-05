
/******************
Name: Samantha Newmark
ID: 346587629
Assignment: ex2
*******************/

#include <stdio.h>

#define SYMBOLS_INPUT_SIZE 5
#define MAX_INPUT 2048
#define MAX_SUM 9

int option = 0 ;

int main() {
	while (option != 7) {

		option = 0 ;

		printf("Choose an option:"
			"\n\t1. Happy Face"
			"\n\t2. Balanced Number"
			"\n\t3. Generous Number"
			"\n\t4. Circle Of Joy"
			"\n\t5. Happy Numbers"
			"\n\t6. Festival Of Laughter"
			"\n\t7. Exit\n") ;
		
		if (scanf(" %d", &option) != 1 || option < 1 || option > 7) {
			printf("This option is not available, please try again.\n") ;
			scanf("%*[^\n]") ;
			scanf("%*c") ;
			continue ;
		}

		scanf("%*[^\n]") ;
		scanf("%*c") ;

		switch (option) {

			case 7: {
				printf("Thank you for your journey through Numeria!\n") ;
				break ;
			}

			// Case 1: Happy Face
			case 1: {
				char eyes = '\0', nose = '\0', mouth = '\0' ;
				printf("Enter symbols for the eyes, nose, and mouth:\n") ;
				while (eyes == '\0' || nose == '\0' || mouth == '\0') {
					if (scanf(" %c %c %c", &eyes, &nose, &mouth) == EOF) {
						scanf("%*[^\n]") ;
						scanf("%*c") ;
						option = 7 ;
						break ;
					}
					if (eyes == '\0' || nose == '\0' || mouth == '\0') {
						eyes = '\0', nose = '\0', mouth = '\0' ;
						scanf("%*[^\n]") ;
						scanf("%*c") ;
						continue ;
					}
					scanf("%*[^\n]") ;
					scanf("%*c") ;
					printf("Enter face size:\n") ;
					int faceSize = 0 ;
					while (faceSize <= 0 || faceSize % 2 == 0) {
						int input = scanf(" %d", &faceSize) ;
						if (input == EOF) {
							option = 7 ;
							break ;
						}
						if (input != 1) {
							scanf("%*[^\n]") ;
							scanf("%*c") ;
							printf("The face's size must be an odd and positive number, please try again:\n") ;
							continue ;
						}
						if (faceSize <= 0 || faceSize % 2 == 0) {
							faceSize = 0 ;
							scanf("%*[^\n]") ;
							scanf("%*c") ;
							printf("The face's size must be an odd and positive number, please try again:\n") ;
							continue ;
						}
					}

					scanf("%*[^\n]") ;
					scanf("%*c") ;

					if (option == 7) {
						break ;
					}

					// Draw eyes
					int secondEye = faceSize + 1 ;
					for (int i = 0 ; i <= secondEye ; i++) {
						if (i == 0 || i == secondEye) {
							printf("%c", eyes) ;
						} else {
							printf(" ") ;
						}
					}
					printf("\n") ;

					// Draw nose
					int second = (faceSize + 1) / 2 ;
					for (int i = 0 ; i <= second ; i++) {
						if (i == second) {
							printf("%c\n", nose) ;
						} else {
							printf(" ") ;
						}
					}

					// Draw mouth
					int makeMouth = faceSize + 1 ;
					for (int i = 0 ; i <= makeMouth ; i++) {
						if (i == 0) {
							printf("\\") ;
						} else if (i == makeMouth) {
							printf("/\n") ;
						} else {
							printf("%c", mouth) ;
						}
					}
				}
				break ;
			}

			// Case 2
			case 2: {
				printf("Enter a number:\n") ;
				int number = 0 ;
				while (number <= 0) {
					int input = scanf(" %d", &number) ;
					if (input == EOF) {
						option = 7 ;
						break ;
					}
					if (input != 1 || number <= 0) {
						scanf("%*[^\n]") ;
						scanf("%*c") ;
						printf("Only positive number is allowed, please try again:\n") ;
						continue ;
					}
				}

				scanf("%*[^\n]") ;
				scanf("%*c") ;

				if (option == 7) {
					break ;
				}

				int frontSection = 0, endSection = 0 ;
				int length = 0 ;
				int remain = number ;
				while (remain != 0) {
					remain = remain / 10 ;
					length++ ;
				}
				if (length == 1) {
					frontSection = 0 ;
					endSection = 0 ;
				} else {
					int chunk = length / 2 ;
					int divider = 1 ;
					for (int j = 0 ; j < chunk ; j++) {
						divider *= 10 ;
					}

					frontSection = number / divider ;
					endSection = number % divider ;
					int *sections[] = { &frontSection, &endSection } ;

					for (int i = 0 ; i < 2 ; i++) {
						int *sectionSpecific = sections[i] ;
						while (*sectionSpecific > MAX_SUM) {
							*sectionSpecific = (*sectionSpecific % 10) + (*sectionSpecific / 10) ;
						}
					}
				}

				if (frontSection == endSection) {
					printf("This number is balanced and brings harmony!\n") ;
					break ;
				}
				printf("This number isn't balanced and destroys harmony.\n") ;
				break ;
			}

			// Case 3
			case 3: {

				printf("Enter a number:\n") ;
				int number = 0 ;
				while (number <= 0) {
					int input = scanf(" %d", &number) ;
					if (input == EOF) {
						option = 7 ;
						break ;
					}
					if (input != 1 || number <= 0) {
						scanf("%*[^\n]") ;
						scanf("%*c") ;
						printf("Only positive number is allowed, please try again:\n") ;
						continue ;
					}
				}

				scanf("%*[^\n]") ;
				scanf("%*c") ;

				if (option == 7) {
					break ;
				}

				int sum = 0 ;
				for (int i = 1 ; i * i <= number ; i++) {
					if (number % i == 0) {
						sum += i ;
						if (i != number / i) {
							sum += number / i ;
						}
					}
				}
				if (sum > number) {
					printf("This number is generous!\n") ;
				} else {
					printf("This number does not share.\n") ;
				}
				break ;
			}
			
			// Case 4
			case 4: {
				printf("Enter a number:\n") ;
				int forward = 0 ;
				while (forward <= 0) {
					int input = scanf(" %d", &forward) ;
					if (input == EOF) {
						option = 7 ;
						break ;
					}
					if (input != 1 || forward <= 0) {
						scanf("%*[^\n]") ;
						scanf("%*c") ;
						printf("Only positive number is allowed, please try again:\n") ;
						continue ;
					}
					scanf("%*[^\n]") ;
					scanf("%*c") ;
					if (forward == 1) {
						printf("The circle remains incomplete.\n") ;
						break ;
					}
					int forwardCopy = forward ;
					int reverse = 0 ;
					while (forwardCopy > 0) {
						reverse = (reverse * 10) + (forwardCopy % 10) ;
						forwardCopy /= 10 ;
					}
					int bases[] = {2, 3, 5, 7, 11, 13, 17, 19} ;
					int values[] = {forward, reverse} ;
					int isForward = 1 , isReverse = 1 ;
					for (int v = 0 ; v < 2 ; v++) {
						int current = values[v], d = current - 1, r = 0 ;
						while (d % 2 == 0) { d /= 2 ; r++ ; }
						for (int b = 0 ; b < 8 && bases[b] < current ; b++) {
							int base = bases[b] ;
							int x = 1, d_copy = d ;
							while (d_copy) {
								if (d_copy % 2 == 1) {
									x = (x * base) % current ;
								}
								base = (base * base) % current ;
								d_copy /= 2 ;
							}
							if (x != 1 && x != current - 1) {
								int composite = 1 ;
								for (int j = 0 ; j < r - 1 && composite ; j++) {
									x = (x * x) % current ;
									if (x == current - 1) {
										composite = 0 ;
										break ;
									}
								}
								if (composite) {
									if (v == 0) isForward = 0 ;
									if (v == 1) isReverse = 0 ;
									break ;
								}
							}
						}
					}
					if (isForward && isReverse) {
						printf("This number completes the circle of joy!\n") ;
					} else {
						printf("The circle remains incomplete.\n") ;
					}
					break ;
				}
				break ;
			}
			
			// Case 5: Happy numbers
			case 5: {
				printf("Enter a number:\n") ;
				int finalNumber = 0 ;
				while (finalNumber <= 0) {
					int input = scanf(" %d", &finalNumber) ;
					if (input == EOF) {
						option = 7 ;
						break ;
					}
					if (input != 1 || finalNumber <= 0) {
						scanf("%*[^\n]") ;
						scanf("%*c") ;
						printf("Only positive number is allowed, please try again:\n") ;
						continue ;
					}
					scanf("%*[^\n]") ;
					scanf("%*c") ;
					printf("Between 1 and %d only these numbers bring happiness: ", finalNumber) ;
					for (int i = 1 ; i <= finalNumber ; i++) {
						int seen[1000] = {0};
						int whatAreYouFeeling = i;
						while (whatAreYouFeeling != 1 && whatAreYouFeeling != 4) {
							if (whatAreYouFeeling < 1000) {
								if (seen[whatAreYouFeeling]) {
									break;
								}
								seen[whatAreYouFeeling] = 1;
							}
							int sum = 0, temp = whatAreYouFeeling;
							while (temp > 0) {
								int dig = temp % 10;
								sum += dig * dig;
								temp /= 10;
							}
							whatAreYouFeeling = sum;
						}
						if (whatAreYouFeeling == 1) {
							printf("%d ", i) ;
						}
					}
					printf("\n") ;
					break ;
				}
				break ;
			}

			// Case 6: Festival of Laughter
			case 6: {
				printf("Enter a smile and cheer number:\n") ;
				int smileNumber = 0, cheerNumber = 0 ;
				while (1) {
					if (scanf(" smile : %d , cheer : %d", &smileNumber, &cheerNumber) != 2 ||
							smileNumber <= 0 || cheerNumber <= 0 || smileNumber == cheerNumber) {
						scanf("%*[^\n]") ;
						scanf("%*c") ;
						printf("Only 2 different positive numbers in the given format"
								" are allowed for the festival, please try again:\n") ;
						continue ;
					}
					break ;
				}
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				printf("Enter maximum number for the festival:\n") ;
				int maxNum = 0 ;
				if (scanf(" %d", &maxNum) != 1 || maxNum <= 0) {
					maxNum = 0 ;
					scanf("%*[^\n]") ;
					scanf("%*c") ;
					printf("Only positive maximum number is allowed, please try again:\n") ;
					continue ;
				}
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				for (int i = 1 ; i <= maxNum ; i++) {
					int isSmile = (i % smileNumber) == 0 ;
					int isCheer = (i % cheerNumber) == 0 ;
					if (isSmile && isCheer) {
						printf("Festival!\n") ;
					} else if (isSmile) {
						printf("Smile!\n") ;
					} else if (isCheer) {
						printf("Cheer!\n") ;
					} else {
						printf("%d\n", i) ;
					}
				}
				break ;
			}
		}
	}
	return 0 ;
}
