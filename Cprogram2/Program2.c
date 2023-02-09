/*
 * Program2.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Nathan Bui
 */
#include <stdio.h>
int main(){
	int entry = 10;
	while (entry != 0 & entry != 1){
		printf("Enter 0 or 1 to STOP\n Enter the NFL score: ");
		scanf("%d", &entry);
		if (entry == 1 || entry == 0){
			break;
		}
		int td_and_2 = 0;
		int td_and_fg = 0;
		int td = 0;
		int fg = 0;
		int safety = 0;
		for(int i = 0; i <= entry / 8; ++i) {
			for(int j = 0; j <= (entry - i*8) / 7; ++j) {
				for(int k = 0; k <= (entry - (i*8 + j*7)) / 6; ++k)
					for(int l = 0; l <= (entry - (i*8 + j*7 + k*6)) / 3; ++l){
						for(int m = 0; m <= (entry - (i*8 + j*7 + k*6 + l*3)) / 2; ++m){
							if(i * 8 + j * 7 + k * 6 + l * 3 + m * 2 == entry) {
								printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, m );
							}
						}
					}
				}
			}
		}
	return 0;
}
