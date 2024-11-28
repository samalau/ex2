/******************
Name: Samantha Newmark
ID: 346587629
Assignment: ex2
*******************/

#include <stdio.h>

#define SYMBOLS_INPUT_SIZE 5
#define MAX_INPUT 3000
#define MAX_SUM 9

int main() {

	char option = '0' ;
	while ((option != '7') == 1) {
		printf("Choose an option:"
				"\n\t1. Happy Face"
				"\n\t2. Balanced Number"
				"\n\t3. Generous Number"
				"\n\t4. Circle Of Joy"
				"\n\t5. Happy Numbers"
				"\n\t6. Festival Of Laughter"
				"\n\t7. Exit\n") ;
		char c ;
		option = getchar() ;
		while (option == 32) {
			option = getchar() ;
		}
		if (option != '1' && option != '2' && option != '3' && option != '4' && option != '5' && option != '6' && option != '7') {
			while ((c = getchar()) != '\n' && c != EOF) ;
			printf("This option is not available, please try again.\n") ;
			continue ;
		}
		int valid = 1 ;
		if (option == '7') {
			printf("Thank you for your journey through Numeria!\n") ;
			break ;
		} else {
		
		
			switch (option) {
				
				// Case 1: Happy Face
				case '1': {
					while ((c = getchar()) != '\n') ;
					char eyes = '\0', nose = '\0', mouth = '\0' ;
					int faceSize = 0 ;
					valid = 1 ;
					// symbols --> face size --> make face
					printf("Enter symbols for the eyes, nose, and mouth:\n") ;
					while (1) {
						char symbolsInput[SYMBOLS_INPUT_SIZE + 1] = {0} ;
						int ind = 0 ;
						valid = 1 ;
						while ((c = getchar()) != '\n' && c != EOF) {
							if (ind >= SYMBOLS_INPUT_SIZE ||
							(c != 32 && (ind == 1 || ind == 3)) ||
							(c < 33 && (ind != 1 && ind != 3))) {
								valid = 0 ;
								break ;
							}
							symbolsInput[ind++] = c ;
						}
						symbolsInput[ind] = '\0' ;					
						if (!valid || ind != SYMBOLS_INPUT_SIZE) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							continue ;
						}
						eyes = symbolsInput[0] ;
						nose = symbolsInput[2] ;
						mouth = symbolsInput[4] ;
						break ;
					}
					// --> face size --> make face
					printf("Enter face size:\n") ;
					while (1) {
						char faceSizeInput[MAX_INPUT + 1] = {0} ;
						int ind = 0 ;
						valid = 1 ;
						while ((c = getchar()) != '\n' && c != EOF) {
							if (ind >= MAX_INPUT - 1 || c < '0' || '9' < c) {
								valid = 0 ;
								break ;
							}
							faceSizeInput[ind++] = c ;
						}
						faceSizeInput[ind] = '\0' ;
						int i = 0 ;
						while (faceSizeInput[i] == '0') {
							i++ ;
						}
						if (i != ind) {
							int lastDigit = faceSizeInput[ind - 1] ;
							if (lastDigit % 2 == 0) {
								valid = 0 ;
							}
							else {
								faceSize = 0 ;
								for (int k = i ; k < ind ; k++) {
									faceSize = faceSize * 10 + (faceSizeInput[k] - '0') ;
								}
								if (faceSize <= 0) {
									valid = 0 ;
								}
							}
						}
						if (!valid || i == ind) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							printf("The face's size must be an odd and positive number, please try again:\n") ;
							continue ;
						}
						break ;
					}
					// --> make face
					int secondEye = faceSize + 1 ;
					for (int i = 0 ; i <= secondEye ; i++) {
						if (i == 0) {
							putchar(eyes) ;
						} else if (i == secondEye) {
							printf("%c\n", eyes) ;
						} else {
							putchar(32) ;
						}
					}
					int second = (1 + faceSize) / 2 ;
					for (int i = 0 ; i <= second ; i++) {
						if (i == second) {
							printf("%c\n", nose) ;
						} else {
							putchar(32) ;
						}
					}
					int makeMouth = faceSize + 1 ;
					for (int i = 0 ; i <= makeMouth ; i++) {
						if (i == 0) {
							putchar('\\') ;
						} else if (i == makeMouth) {
							printf("/\n") ;
						} else {
							putchar(mouth) ;
						}
					}
					break ;
				}

				// Case 2
				case '2': {
					while ((c = getchar()) != '\n') ;
					printf("Enter a number:\n") ;
					while (1) {
						char input[MAX_INPUT + 1] = {0} ;
						valid = 1 ;
						int ind = 0 ;
						int frontSection = 0, endSection = 0 ;
						while ((c = getchar()) != '\n' && c != EOF) {
							if (ind >= MAX_INPUT - 1 || c < '0' || '9' < c) {
								while ((c = getchar()) != '\n' && c != EOF) ;
								valid = 0 ;
								break ;
							}
							input[ind++] = c ;
						}
						input[ind] = '\0' ;
						if (!valid) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							printf("Only positive number is allowed, please try again:\n") ;
							continue ;
						}
						int i = 0 ;
						while (input[i] == '0') {
							i++ ;
						}
						if (i == ind) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							valid = 0 ;
							printf("Only positive number is allowed, please try again:\n") ;
							continue ;
						}
						char *strVal = input ;
						int length = 0 ;
						while (strVal[length] != '\0') length++ ;
						if (length == 0) {
							frontSection = 0 ;
							endSection = -1 ;
						} else if (length >= 1) {
							int sectionSize = length - i ;
							if (length == 1 || sectionSize == 1) {
								frontSection = 0 ;
								endSection = 0 ;
							} else {
								int j = 0, k = 0 ;
								int chunkSpace = 1 ;
								int value = 0 ;
								if (sectionSize % 2 != 0) {
									--sectionSize ;
									sectionSize /= 2 ;
									for (j = 0 ; j < sectionSize ; j++) {
										chunkSpace *= 10 ;
									}
									for (k = i ; k < ind ; k++) {
										value = value * 10 + (input[k] - '0') ;
									}
									frontSection = value / chunkSpace ;
									frontSection /= 10 ;
								} else {
									sectionSize /= 2 ;
									for (j = 0 ; j < sectionSize ; j++) {
										chunkSpace *= 10 ;
									}
									for (k = i ; k < ind ; k++) {
										value = value * 10 + (input[k] - '0') ;
									}
									frontSection = value / chunkSpace ;
								}
								endSection = value % chunkSpace ;
								int *sections[] = { &frontSection, &endSection } ;
								for (i = 0 ; i < 2 ; i++) {
									int *sectionSpecific = sections[i] ;
									while (*sectionSpecific > MAX_SUM) {
										*sectionSpecific = (*sectionSpecific % 10) + (*sectionSpecific / 10) ;
									}
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
					break ;
				}

				// Case 3
				case '3': {
					while ((c = getchar()) != '\n') ;
					printf("Enter a number:\n") ;
					while (1) {
						char input[MAX_INPUT + 1] = {0} ;
						valid = 1 ;
						int ind = 0 ;
						while ((c = getchar()) != '\n' && c != EOF) {
							if (ind >= MAX_INPUT - 1 || c < '0' || '9' < c) {
								while ((c = getchar()) != '\n' && c != EOF) ;
								valid = 0 ;
								break ;
							}
							input[ind++] = c ;
						}
						input[ind] = '\0' ;
						if (!valid) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							printf("Only positive number is allowed, please try again:\n") ;
							continue ;
						}
						int i = 0 ;
						while (input[i] == '0') {
							i++ ;
						}
						int k = 0, n = 0 ;
						for (k = i ; k < ind ; k++) {
							n = n * 10 + (input[k] - '0') ;
						}
						int sum = 0 ;
						for (i = 2 ; i * i <= n ; i++) {
							if (n % i == 0) {
								sum += i ;
								if (i != n / i) {
									sum += n / i ;
								}
							}
						}
						if (n < 1 || n > MAX_INPUT) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							printf("Only positive number is allowed, please try again:\n") ;
							continue ;
						}
						if (sum > n) {
							printf("This number is generous!\n") ;
						} else {
							printf("This number does not share.\n") ;
						}
						break ;
					}
					break ;
				}

				// Case 4
				case '4': {
					while ((c = getchar()) != '\n') ;
					printf("Enter a number:\n") ;
					while (1) {
						// circle is complete only if both forward, reverse are 1
						int forward = 1, reverse = 1 ;  
						char input[MAX_INPUT + 1] = {0} ;
						valid = 1 ;
						int ind = 0 ;
						while ((c = getchar()) != '\n' && c != EOF) {
							if (ind >= MAX_INPUT - 1 || c < '0' || '9' < c) {
								while ((c = getchar()) != '\n' && c != EOF) ;
								valid = 0 ;
								break ;
							}
							input[ind++] = c ;
						}
						input[ind] = '\0' ;
						int i = 0, k = 0, n = 0 ;
						if (valid) {
							while (input[i] == '0') {
								i++ ;
							}
							for (k = i ; k < ind ; k++) {
								n = n * 10 + (input[k] - '0') ;
							}
							if (n == 1) {
								printf("The circle remains incomplete.\n") ;
								break ;
							}
						}
						if (!valid || n < 1) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							printf("Only positive number is allowed, please try again:\n") ;
							continue ;
						}
						int n_copy = n, n_reversed = 0 ;
						while (n_copy > 0) {
							n_reversed = (n_reversed * 10) + (n_copy % 10) ;
							n_copy /= 10 ;
						}
						int uncheckedValues[] = {n, n_reversed} ;
						for (k = 0 ; k < 2 ; k++) {
							int n_n = uncheckedValues[k] ;
							int d = n_n - 1 ;
							int r = 0 ;
							while (d % 2 == 0) {
								d /= 2 ; r++ ;
							}
							int bases[] = {2, 3, 5, 7, 11, 13, 17, 19} ;
							for (i = 0 ; i < 8 && bases[i] < n_n ; i++) {
								int b = bases[i] ;
								int x = 1;
								int d_copy = d ;
								while (d_copy) {
									if (d_copy % 2 == 1) {
										x = (x * b) % n_n ;
									}
									b = (b * b) % n_n ;
									d_copy /= 2 ;
								}
								if (x != 1 && x != n_n - 1) {
									int m = 1 ;
									for (int j = 0 ; j < r - 1 && m ; j++) {
										x = (x * x) % n_n ;
										if (x == n_n - 1) {
											m = 0 ;
											break ;
										}
									}
									if (m) {
										forward = reverse = 0 ;
										break ;
									}
								}
							}
							if (!forward || !reverse) {
								break ;
							}
						}
						if (forward && reverse) {
							printf("This number completes the circle of joy!\n") ;
						} else {
							printf("The circle remains incomplete.\n") ;
						}
						break ;
					}
					break ;
				}

				// Case 5: Happy numbers
				case '5': {
					while ((c = getchar()) != '\n') ;
					printf("Enter a number:\n") ;
					while (1) {
						char input[MAX_INPUT + 1] = {0} ;
						valid = 1 ;
						int ind = 0 ;
						while ((c = getchar()) != '\n' && c != EOF) {
							if (ind >= MAX_INPUT - 1 || c < '0' || '9' < c) {
								valid = 0 ;
								break ;
							}
							input[ind++] = c ;
						}
						input[ind] = '\0' ;
						int i = 0 ;
						while (input[i] == '0') i++ ;
						if (!valid || i == ind) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							printf("Only positive number is allowed, please try again:\n") ;
							continue ;
						}
						int k= 0, n = 0 ;
						for (k = i ; k < ind ; k++) {
							n = n * 10 + (input[k] - '0') ;
						}
						printf("Between 1 and %d only these numbers bring happiness: ", n) ;
						for (i = 1 ; i <= n ; i++) {
							int whatAreYouFeeling = i ;
							while (whatAreYouFeeling != 1 && whatAreYouFeeling != 4) {
								int sum = 0 ;
								while (whatAreYouFeeling > 0) {
									int dig = (whatAreYouFeeling % 10) ;
									sum += dig * dig ;
									whatAreYouFeeling /= 10 ;
								}
								whatAreYouFeeling = sum ;
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
				case '6': {

					while ((c = getchar()) != '\n') ;

					char smileCheck[7] = {'s', 'm', 'i', 'l', 'e', ':', '\0'} ;
					char cheerCheck[7] = {'c', 'h', 'e', 'e', 'r', ':', '\0'} ;
					int smileNumber, cheerNumber;
					printf("Enter a smile and cheer number:\n") ;
					
					while (1) {
						valid = 1 ;
						while ((c = getchar()) == 32) ;
						if (c == '\n') {
							printf("Only 2 different positive numbers in the given format"
									" are allowed for the festival, please try again:\n") ;
							continue ;
						}

						char identifySmile[7] = {0} ;
						int ind = 0 ;
						while (c != ':' && c != '\n' && (c < '0' || '9' < c)) {
							if (c != 32) {
								identifySmile[ind++] = c ;
							}
							c = getchar() ;
						}

						if (c == ':') {
							identifySmile[ind++] = c ;
						}

						identifySmile[ind] = '\0' ;
						
						for (int j = 0 ; j < 6; j++) {
							if (identifySmile[j] != smileCheck[j]) {
								valid = 0 ;
								if (c != '\n') {
									while ((c = getchar()) != '\n' && c != EOF) ;
								}
								printf("Only 2 different positive numbers in the given format"
										" are allowed for the festival, please try again:\n") ;
								break ;
							}
						}
						if (!valid) continue ;
						c = getchar() ;
						while (c == 32) {
							c = getchar() ;
						}
						if (c < '0' || '9' < c ) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							valid = 0 ;
							printf("Only 2 different positive numbers in the given format"
									" are allowed for the festival, please try again:\n") ;
							continue ;
						}

						char smileNumberIn[MAX_INPUT + 1] = {0} ;
						ind = 0 ;
						while ('0' <= c && c <= '9') {
							smileNumberIn[ind++] = c ;
							if (ind >= MAX_INPUT - 1) {
								if (c != '\n') {
									while ((c = getchar()) != '\n' && c != EOF) ;
								}
								valid = 0 ;
								printf("Only 2 different positive numbers in the given format"
										" are allowed for the festival, please try again:\n") ;
								break ;
							}
							c = getchar() ;
						}
						if (!valid) {
							continue ;
						}
						smileNumberIn[ind] = '\0' ;

						while (c == 32 || c == ',') {
							c = getchar() ;
						}

						char identifyCheer[7] = {0} ;
						ind = 0 ;
						while (c != ':' && c != '\n' && (c < '0' || '9' < c)) {
							if (ind >= 7) {
								valid = 0;
								break;
							}
							if (c != 32) {
								identifyCheer[ind++] = c ;
							}
							c = getchar() ;
						}

						if (!valid) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							valid = 0 ;
							printf("Only 2 different positive numbers in the given format"
									" are allowed for the festival, please try again:\n") ;
							continue ;
						}

						if (c == ':') {
							identifyCheer[ind++] = c ;
						}
						identifyCheer[ind] = '\0' ;

						for (int j = 0 ; j < 6; j++) {
							if (identifyCheer[j] != cheerCheck[j]) {
								valid = 0 ;
								break ;
							}
						}
						if (!valid) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							printf("Only 2 different positive numbers in the given format"
									" are allowed for the festival, please try again:\n") ;
							continue ;
						}

						while ((c = getchar()) == 32) ;

						if (c < '0' || '9' < c ) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							valid = 0 ;
							printf("Only 2 different positive numbers in the given format"
									" are allowed for the festival, please try again:\n") ;
							continue ;
						}

						char cheerNumberIn[MAX_INPUT + 1] = {0} ;
						ind = 0 ;
						while ('0' <= c && c <= '9') {
							cheerNumberIn[ind++] = c ;
							if (ind >= MAX_INPUT - 1) {
								valid = 0 ;
								break ;
							}
							c = getchar() ;
						}
						if (!valid) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							printf("Only 2 different positive numbers in the given format"
									" are allowed for the festival, please try again:\n") ;
							continue ;
						}
						cheerNumberIn[ind] = '\0' ;

						while (c == 32) {
							c = getchar() ;
						}
						
						if (c != '\n') {
							while ((c = getchar()) != '\n' && c != EOF) ;
							valid = 0 ;
							printf("Only 2 different positive numbers in the given format"
									" are allowed for the festival, please try again:\n") ;
							continue ;
						}
						
						int j = 0 ;
						while (smileNumberIn[j] == '0') j++ ;

						int k = 0 ;
						while (cheerNumberIn[k] == '0') k++ ;
						
						smileNumber = 0 ;
						for (int i = j ; smileNumberIn[i] != '\0' ; i++) {
							smileNumber = smileNumber * 10 + (smileNumberIn[i] - '0') ;
						}
						
						cheerNumber = 0;
						for (int i = k ; cheerNumberIn[i] != '\0' ; i++) {
							cheerNumber = cheerNumber * 10 + (cheerNumberIn[i] - '0') ;
						}
						
						if (smileNumber <= 0 || cheerNumber <= 0 || smileNumber == cheerNumber) {
							if (c != '\n') {
								while ((c = getchar()) != '\n' && c != EOF) ;
							}
							valid = 0 ;
							printf("Only 2 different positive numbers in the given format"
									" are allowed for the festival, please try again:\n") ;
							continue ;
						}
						break ;
					}
					printf("Enter maximum number for the festival:\n") ;
					int maximum = 0 ;
					while (!maximum) {
						int maximumOut = 0 ;
						while (maximumOut == 0) {
							c = getchar() ;
							if (c == '\n') {
								printf("Only positive maximum number is allowed, please try again:\n") ;
								maximum = 0 ;
								break ;
							} else if (c == 32) {
								c = getchar() ;
								if (c < 32 || '9' < c) {
									if (c != '\n') {
										while ((c = getchar()) != '\n' && c != EOF) ;
									}
									valid = 0 ;
									printf("Only positive maximum number is allowed, please try again:\n") ;
									maximum = 0 ;
									break ;
								}
							}
							while (c == 32) {
								c = getchar() ;
							}
							if (c < 32 || '9' < c) {
								if (c != '\n') {
									while ((c = getchar()) != '\n' && c != EOF) ;
								}
								printf("Only positive maximum number is allowed, please try again:\n") ;
								maximum = 0 ;
								break ;
							}
							ungetc(c, stdin) ;
							maximumOut = scanf("%d", &maximum) ;
							while ((c = getchar()) == 32) ;
							if (maximumOut == 0 || maximum < 1 || c != '\n') {
								if (c != '\n') {
									while ((c = getchar()) != '\n' && c != EOF) ;
								}
								printf("Only positive maximum number is allowed, please try again:\n") ;
								maximum = 0 ;
								break ;
							}
						}
					}
					for (int i = 1 ; i <= maximum ; i++) {
						int isSmile = (i % smileNumber) == 0, isCheer = (i % cheerNumber) == 0 ;
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
				}
			}
		}
	}
	return 0 ;
}
