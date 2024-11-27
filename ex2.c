/******************
Name: Samantha Newmark
ID: 346587629
Assignment: ex2
*******************/

#include <stdio.h>

#define SYMBOLS_INPUT_MIN_MAX 5
#define MAX_INPUT 1048576LL
#define MAX_SUM 9LL

int main() {
	while (1) {
		printf("Choose an option:"
				"\n\t1. Happy Face"
				"\n\t2. Balanced Number"
				"\n\t3. Generous Number"
				"\n\t4. Circle Of Joy"
				"\n\t5. Happy Numbers"
				"\n\t6. Festival Of Laughter"
				"\n\t7. Exit\n") ;
		int choice ;
		char c ;
		c = getchar() ;
		if (c == '\n' || c == ' ' || c == '\t' || c < '1' || '7' < c) {
			if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
			printf("This option is not available, please try again.\n") ;
			continue ;
		}
		ungetc(c, stdin) ;
		if (scanf("%1d%c", &choice, &c) != 2 || c != '\n'|| choice < 1 || 7 < choice) {
			while ((c = getchar()) != '\n' && c != EOF) ;
			printf("This option is not available, please try again.\n") ;
			continue ;
		}
		if (choice == 7) {
			printf("Thank you for your journey through Numeria!\n") ;
			break ;
		} 
		switch (choice) {

			////////////////////////////////////////////////////////////////

			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/

			case 1: {
				int tooLarge ;
				int valid, lastDigit ;
				int symbols = 0, size = 0 ;
				long long i, k, ind, faceSize, first, second, third, secondEye, makeMouth ;
				char c, eyes, nose, mouth ;
				// symbols --> face size --> make face
				printf("Enter symbols for the eyes, nose, and mouth:\n") ;
				while (!symbols) {
					char symbolsInput[SYMBOLS_INPUT_MIN_MAX + 1] = {0};
					ind = 0, tooLarge = 0 ;
					valid = 1 ;
					while ((c = getchar()) != '\n' && c != EOF) {
						if (ind >= SYMBOLS_INPUT_MIN_MAX) {
							tooLarge = 1 ;
							break ;
						}
						if (c != 32 && (ind == 1 || ind == 3)) {
							valid = 0 ;
							break ;
						} else if (c < 33 && (ind != 1 && ind != 3)) {
							valid = 0 ;
							break ;
						}
						symbolsInput[ind++] = c ;
					}
					symbolsInput[ind] = '\0' ;					
					if (tooLarge || !valid || ind != SYMBOLS_INPUT_MIN_MAX) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Please try again:\n") ;
						continue ;
					}
					eyes = symbolsInput[0] ;
					nose = symbolsInput[2] ;
					mouth = symbolsInput[4] ;
					symbols = 1 ;
				}
				// --> face size --> make face
				printf("Enter face size:\n") ;
				while (!size) {
					char faceSizeInput[MAX_INPUT + 1] = {0} ;
					ind = 0, tooLarge = 0 ;
					valid = 1 ;
					while ((c = getchar()) != '\n' && c != EOF) {
						if (ind >= MAX_INPUT - 1) {
							tooLarge = 1 ;
							break ;
						}
						if (c < '0' || '9' < c) {
							valid = 0 ;
							break ;
						}
						faceSizeInput[ind++] = c ;
					}
					if (tooLarge) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Input is too large, please try again:\n") ;
						continue ;
					}
					faceSizeInput[ind] = '\0' ;
					i = 0 ;
					while (faceSizeInput[i] == '0') { i++ ; }
					if (i != ind) {
						lastDigit = faceSizeInput[ind - 1] ;
						if (lastDigit % 2 == 0) { valid = 0 ; }
						else {
							faceSize = 0 ;
							for (k = i ; k < ind ; k++) {
								faceSize = faceSize * 10 + (faceSizeInput[k] - '0') ;
							}
							if (faceSize <= 0) { valid = 0 ; }
						}
					}
					if (!valid || i == ind) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("The face's size must be an odd and positive number, please try again:\n") ;
						continue ;
					}
					size = 1 ;
				}
				// --> make face
				char yesNo ;
				if (faceSize > 64) {
					while (1) {
						printf("This size might be too large to display optimally, continue to display? [y/n]: \n") ;
						scanf("%c", &yesNo) ;
						while ((c = getchar()) != '\n' && c != EOF) ;
						if (yesNo == 'n' || yesNo == 'N') {
							valid = 0 ;
							break ;
						} else if (yesNo == 'y' || yesNo == 'Y') { break ; }
						else { continue ; }
					}
				}
				if (valid) {
					first = faceSize ;
					second = (1 + faceSize) / 2 ;
					third = faceSize ;
					secondEye = first + 1 ;
					for (i = 0 ; i <= secondEye ; i++) {
						if (i == 0) { putchar(eyes) ; }
						else if (i == secondEye) { printf("%c\n", eyes) ; }
						else { putchar(32) ; }
					}
					for (i = 0 ; i <= second ; i++) {
						if (i == second) { printf("%c\n", nose) ; }
						else { putchar(32) ; }
					}
					makeMouth = third + 1 ;
					for (i = 0 ; i <= makeMouth ; i++) {
						if (i == 0) { putchar('\\') ; }
						else if (i == makeMouth) { printf("/\n") ; }
						else { putchar(mouth) ; }
					}
				}
				break ;
			}

			////////////////////////////////////////////////////////////////

			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/

			case 2: {
				printf("Enter a number:\n") ;
				while (1) {
					char input[MAX_INPUT + 1] = {0} ;
					char c ;
					int tooLarge = 0 ;
					int valid = 1 ;
					int odd ;
					long long ind = 0 ;
					long long i, j, k, length, sectionSize, chunkSpace, frontSection, endSection, value ;
					while ((c = getchar()) != '\n' && c != EOF) {
						if (ind >= MAX_INPUT - 1) {
							while ((c = getchar()) != '\n' && c != EOF) ;
							tooLarge = 1 ;
							break ;
						}
						if (c < '0' || '9' < c) {
							while ((c = getchar()) != '\n' && c != EOF) ;
							valid = 0 ;
							break ;
						}
						input[ind++] = c ;
					}
					if (tooLarge) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Input is too large, please try again:\n") ;
						continue ;
					}
					input[ind] = '\0' ;
					i = 0 ;
					while (input[i] == '0') { i++ ; }
					if (!valid || i == ind) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only positive number is allowed, please try again:\n") ;
						continue ;
					}
					char *strVal = input ;
					length = 0 ;
					while (strVal[length] != '\0') length++ ;
					if (length == 0) {
						frontSection = 0 ;
						endSection = -1 ;
					} else if (length >= 1) {
						sectionSize = length - i ;
						if (length == 1 || sectionSize == 1) {
							frontSection = 0 ;
							endSection = 0 ;
						} else {
							odd = 0 ;
							if (sectionSize % 2 != 0) {
								odd = 1 ;
								--sectionSize ;
							}
							sectionSize /= 2 ;
							chunkSpace = 1 ;
							for (j = 0 ; j < sectionSize ; j++) {
								chunkSpace *= 10 ;
							}
							value = 0 ;
							for (k = i ; k < ind ; k++) {
								value = value * 10 + (input[k] - '0') ;
							}
							frontSection = value / chunkSpace ;
							if (odd) { frontSection /= 10 ; }
							endSection = value % chunkSpace ;
							long long *sections[] = {&frontSection, &endSection} ;
							for (i = 0 ; i < 2 ; i++) {
								long long *sectionSpecific = sections[i] ;
								while (*sectionSpecific > MAX_SUM) {
									*sectionSpecific = (*sectionSpecific % 10) + (*sectionSpecific / 10) ;
								}
							}
						}
					}
					if (frontSection == endSection) {
						printf("This number is balanced and brings harmony!\n") ;
						break ;
					} else {
						printf("This number isn't balanced and destroys harmony.\n") ;
						break ;
					}
				}
				break ;
			}
			
			////////////////////////////////////////////////////////////////

			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/

			case 3: {
				char c ;
				long long k ;
				printf("Enter a number:\n") ;
				while (1) {
					char input[MAX_INPUT + 1] = {0} ;
					int tooLarge = 0 ;
					int valid = 1 ;
					long long ind = 0, sum = 0, n = 0, i = 0 ;
					while ((c = getchar()) != '\n' && c != EOF) {
						if (ind >= MAX_INPUT - 1) {
							while ((c = getchar()) != '\n' && c != EOF) ;
							tooLarge = 1 ;
							break ;
						}
						if (c < '0' || '9' < c) {
							while ((c = getchar()) != '\n' && c != EOF) ;
							valid = 0 ;
							break ;
						}
						input[ind++] = c ;
					}
					if (tooLarge) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Input is too large, please try again:\n") ;
						continue ;
					}
					input[ind] = '\0' ;
					while (input[i] == '0') { i++ ; }
					for (k = i ; k < ind ; k++) {
						n = n * 10 + (input[k] - '0') ;
					}
					if (!valid || n < 1 || n > MAX_INPUT) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only positive number is allowed, please try again:\n") ;
						continue ;
					}
					for (i = 2 ; i * i <= n ; i++) {
						if (n % i == 0) {
							sum += i ;
							if (i != n / i) {
								sum += n / i ;
							}
						}
					}
					if (sum > n) {
						printf("This number is generous!\n") ;
						break ;
					} else {
						printf("This number does not share.\n") ;
						break ;
					}
				}
				break ;
			}

			////////////////////////////////////////////////////////////////

			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/

			case 4: {
				char c ;
				int forward = 1, reverse = 1 ;  // circle is complete only if both forward, reverse are 1 ;
				long long k ;
				printf("Enter a number:\n") ;
				while (1) {
					char input[MAX_INPUT + 1] = {0} ;
					int tooLarge = 0 ;
					int valid = 1 ;
					long long ind = 0, i = 0, n = 0, n_reversed = 0 ;
					while ((c = getchar()) != '\n' && c != EOF) {
						if (ind >= MAX_INPUT - 1) {
							while ((c = getchar()) != '\n' && c != EOF) ;
							tooLarge = 1 ;
							break ;
						}
						if (c < '0' || '9' < c) {
							while ((c = getchar()) != '\n' && c != EOF) ;
							valid = 0 ;
							break ;
						}
						input[ind++] = c ;
					}
					if (tooLarge) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Input is too large, please try again:\n") ;
						continue ;
					}
					input[ind] = '\0' ;
					while (input[i] == '0') { i++ ; }
					for (k = i ; k < ind ; k++) {
						n = n * 10 + (input[k] - '0') ;
					}
					if (n == 1) {
						printf("The circle remains incomplete.\n") ;
						break ;
					}
					if (!valid || n < 1) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only positive number is allowed, please try again:\n") ;
						continue ;
					}
					long long n_copy = n ;
					while (n_copy > 0) {
						n_reversed = (n_reversed * 10) + (n_copy % 10) ;
						n_copy /= 10 ;
					}
					long long uncheckedValues[] = {n, n_reversed} ;
					for (k = 0 ; k < 2 ; k++) {
						long long n_n = uncheckedValues[k] ;
						long long d = n_n - 1 ;
						int r = 0 ;
						while (d % 2 == 0) {d /= 2 ; r++ ; }
						long long bases[] = {2, 3, 5, 7, 11, 13, 17, 19} ;
						for (i = 0 ; i < 8 && bases[i] < n_n ; i++) {
							long long b = bases[i] ;
							long long x = 1;
							long long d_copy = d ;
							while (d_copy) {
								if (d_copy % 2 == 1) { x = (x * b) % n_n ; }
								b = (b * b) % n_n ;
								d_copy /= 2 ;
							}
							if (x != 1 && x != n_n - 1) {
								long long m = 1 ;
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
						if (!forward || !reverse) { break ; };
					}
					if (forward && reverse) {
						printf("This number completes the circle of joy!\n") ;
						break ;
					} else {
						printf("The circle remains incomplete.\n") ;
						break ;
					}
				}
				break ;
			}

			////////////////////////////////////////////////////////////////

			// Case 5
			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/

			case 5: {
				printf("Enter a number:\n") ;
				while (1) {
					char input[MAX_INPUT + 1] = {0} ;
					char c ;
					int tooLarge = 0 ;
					int valid = 1 ;
					int odd ;
					long long ind = 0, n = 0 ;
					long long i, j, k ;
					while ((c = getchar()) != '\n' && c != EOF) {
						if (ind >= MAX_INPUT - 1) {
							tooLarge = 1 ;
							break ;
						}
						if (c < '0' || '9' < c) {
							valid = 0 ;
							break ;
						}
						input[ind++] = c ;
					}
					input[ind] = '\0' ;
					i = 0 ;
					while (input[i] == '0') { i++ ; }
					if (tooLarge || !valid || i == ind) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only positive number is allowed, please try again:\n") ;
						continue ;
					}
					for (k = i ; k < ind ; k++) {
						n = n * 10 + (input[k] - '0') ;
					}
					printf("Between 1 and %lld only these numbers bring happiness: ", n) ;
					for (i = 1 ; i <= n ; i++) {
						long long whatAreYouFeeling = i ;
						while (whatAreYouFeeling != 1 && whatAreYouFeeling != 4) {
							long long sum = 0 ;
							while (whatAreYouFeeling > 0) {
								long long dig = (whatAreYouFeeling % 10) ;
								sum += dig * dig ;
								whatAreYouFeeling /= 10 ;
							}
							whatAreYouFeeling = sum ;
						}
						if (whatAreYouFeeling == 1) {
							printf("%lld ", i) ;
						}
					}
					printf("\n") ;
					break ;
				}
				break ;
			}
			
			////////////////////////////////////////////////////////////////

			// Case 6
			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/


			case 6: {
				char smileCheck[7] = {'s', 'm', 'i', 'l', 'e', ':', '\0'} ;
				char cheerCheck[7] = {'c', 'h', 'e', 'e', 'r', ':', '\0'} ;
				char c ;
				long long ind = 0 ;
				long long i, j, k, smileNumber, cheerNumber ;
				int valid, tooLarge ;

				printf("Enter a smile and cheer number:\n") ;

				int formatCheck = 0 ;
				while (!formatCheck) {
					char identifySmile[7] = {0} ;
					char identifyCheer[7] = {0} ;
					char smileNumberIn[MAX_INPUT + 1] = {0} ;
					char cheerNumberIn[MAX_INPUT + 1] = {0} ;

					valid = 1 ;
					ind = 0 ;

					c = getchar() ;
					while (c == 32) {
						c = getchar() ;
					}
					if (c == '\n') {
						printf("Only 2 different positive numbers in the given format"
								" are allowed for the festival, please try again:\n") ;
						continue ;
					}
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

					for (j = 0 ; j < 6; j++) {
						if (identifySmile[j] != smileCheck[j]) {
							valid = 0 ;
							break ;
						}
					}

					c = getchar() ;
					if (c == 32) {
						while (c == 32) {
							c = getchar() ;
						}
					}
					
					if (c < '0' || '9' < c ) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only 2 different positive numbers in the given format"
								" are allowed for the festival, please try again:\n") ;
						continue ;
					}

					ind = 0 ;
					while ('0' <= c && c <= '9') {
						smileNumberIn[ind++] = c ;
						if (ind >= MAX_INPUT - 1) {
							valid = 0 ;
							break ;
						}
						c = getchar() ;
					}

					if (!valid) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only 2 different positive numbers in the given format"
								" are allowed for the festival, please try again:\n") ;
						continue ;
					}

					smileNumberIn[ind] = '\0' ;

					while (c == 32 || c == ',') {
						c = getchar() ;
					}

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
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only 2 different positive numbers in the given format"
								" are allowed for the festival, please try again:\n") ;
						continue ;
					}

					if (c == ':') {
						identifyCheer[ind++] = c ;
					}

					identifyCheer[ind] = '\0' ;

					for (j = 0 ; j < 6; j++) {
						if (identifyCheer[j] != cheerCheck[j]) {
							valid = 0 ;
							break ;
						}
					}

					while ((c = getchar()) == 32) ;

					ind = 0 ;

					if (c < '0' || '9' < c ) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only 2 different positive numbers in the given format"
								" are allowed for the festival, please try again:\n") ;
						continue ;
					}

					while ('0' <= c && c <= '9') {
						cheerNumberIn[ind++] = c ;
						if (ind >= MAX_INPUT - 1) {
							valid = 0 ;
							break ;
						}
						c = getchar() ;
					}
					cheerNumberIn[ind] = '\0' ;

					while (c == 32) {
						c = getchar() ;
					}
					
					if (!valid) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only 2 different positive numbers in the given format"
								" are allowed for the festival, please try again:\n") ;
						continue ;
					}

					if (c != '\n') {
						while ((c = getchar()) != '\n' && c != EOF) ;
						printf("Only 2 different positive numbers in the given format"
								" are allowed for the festival, please try again:\n") ;
						continue ;
					}
					
					j = 0 ;
					while (smileNumberIn[j] == '0') { j++ ; }

					k = 0 ;
					while (cheerNumberIn[k] == '0') { k++ ; }

					smileNumber = 0 ;
					for (i = j ; smileNumberIn[i] != '\0' ; i++) {
						smileNumber = smileNumber * 10 + (smileNumberIn[i] - '0') ;
					}
					
					cheerNumber = 0;
					for (i = k ; cheerNumberIn[i] != '\0' ; i++) {
						cheerNumber = cheerNumber * 10 + (cheerNumberIn[i] - '0') ;
					}
					
					if (smileNumber <= 0 || cheerNumber <= 0 || smileNumber == cheerNumber) {
						if (c != '\n') { while ((c = getchar()) != '\n' && c != EOF) ; } ;
						printf("Only 2 different positive numbers in the given format"
								" are allowed for the festival, please try again:\n") ;
						continue ;
					} else {
						formatCheck = 1 ;
					}
				}
				printf("Enter maximum number for the festival:\n") ;
				long long maximum = 0 ;
				while (!maximum) {
					long long maximumOut = 0 ;
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
						maximumOut = scanf("%lld", &maximum) ;
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
				for (i = 1 ; i <= maximum ; i++) {
					if ((i % smileNumber) != 0 && (i % cheerNumber) != 0) {
						printf("%lld\n", i) ;
					} else if ((i % smileNumber) == 0 && (i % cheerNumber) != 0) {
						printf("Smile!\n") ;
					} else if ((i % smileNumber) != 0 && (i % cheerNumber) == 0) {
						printf("Cheer!\n") ;
					} else if ((i % smileNumber) == 0 && (i % cheerNumber) == 0) {
						printf("Festival!\n") ;
					}
				}
			}
			break ;
		}
	}
	return 0 ;
}
