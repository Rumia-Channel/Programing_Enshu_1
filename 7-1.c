#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INMAX 100
#define INMIN 1

long int l_abs(long int lnumb){
	if (lnumb<-0){
	lnumb=lnumb*-1;
	}
	return lnumb;
}

int ndiff(long int usrin, long int answr){

	long int compa;

	printf("正解は%dで、", answr);

	//DEBUG
	//printf("%ld \n", num1);
	//printf("%ld \n", num2);

	compa = l_abs((usrin - answr));
	if (compa==0){
		printf("正解！ \n");
		return 1;
	} else if (compa<=5){
		printf("めっちゃ惜しい! \n");
	} else if (compa<=10){
		printf("惜しい！ \n");
	} else{
		printf("残念！ \n");
	}
	return 0;
}

/*整数以外が入力された際の無限ループを回避したかったが、動作せず
long int ch_ns(char *input){
	char *end;
	printf(input);
	long int rtnum = strtol(input, &end, 10);
	if (*end != '\0'){
		return 0;
	}
	return rtnum;
}
*/

void prrnk(double ranks[10]) {
	int howeq = 0;
	printf("RANKING                    SCORE\n");
	for(int i=0; i<10; i++){

		printf("%02d           ...           %f\n", i+1-howeq, ranks[i]);

		if (i<9 && ranks[i] == ranks[i+1]){
			howeq++;
		}else {
			howeq = 0;
		}

	}
}

double caluc(double ranks[10], double avtry)
{
    double tmprk[10];
    int rank;
    //ランクの計算
    for (int i = 0; i < 11; i++){
        
        if (i==10){
            printf("あなたはランキング外です。\n");
            break;
        }

        if (avtry <= ranks[i]){
            rank = i+1;
            if (avtry == ranks[i]){
                printf("あなたの順位は同率%d位です。\n", rank);
            } else {
                printf("あなたの順位は第%d位です。\n", rank);
            }
            tmprk[i] = avtry;

            for (int j = i+1; j < 11; j++){
                tmprk[j] = ranks[j-1];
            }

            break;
        }
        tmprk[i] = ranks[i];
    }

    for (int i = 0; i < 10; i++){
        ranks[i] = tmprk[i];
    }
}

int main(void)
{
	long int ranum;
	/*TEST用 動作せず
	 * char *input;*/
	long int usrin;
	int retry=3;
	int nturn;
	int hwtry;
	int replay;

	double avtry;

	double ranks[10] = {1.1,1.5,1.6,1.7,1.75,1.8,2.1,2.3,2.5,2.9};

	while(1) {
	
		prrnk(ranks);

		//初期化
		nturn=0;
		hwtry=0;

		while(retry>nturn){
			
			nturn++;
	
			printf("ターン%dです。 \n", nturn);
			
			//試行回数を初期化
			int nmtry=0;
			//予想処理
			while(1){
				nmtry++;
				hwtry++;
				srandom((unsigned)time(NULL));
				printf("第%d回目の予想> ", nmtry);
				scanf("%ld", &usrin);
			
				/*TEST用 動作しないため保留 なぜか数値だろうが文字だろうがメモリダンプする。
				 * scanf("%c", &input);
				printf("TEST1");
				usrin = ch_ns(input);
				if (usrin==0){
					printf("不正な文字列が入力されました。1～100までの10進数の数値のみを入力してください。\n");
					nmtry--;
					continue;
				}*/
				ranum = (random() % (INMAX - INMIN) + INMIN);
				
				//DEBUG
				ranum = 21;
	
				if (ndiff(usrin, ranum)==1){
					printf("%d回目の予想で正解しました。\n", nmtry);
					break;
				}
			}
		}

		avtry = (double)hwtry/(double)nturn;
	
		printf("%dターンで%d回の予想をしました。スコア(平均回数)は%f回です。\n", nturn,hwtry,avtry);
	
		if (avtry<=3){
		printf("すごい！\n");
		} else if (avtry<=5){
		printf("まあまあですね。\n");
		} else if (avtry<=10){
			printf("まだまだですね。\n");
		} else{
			printf("頑張りましょう。\n");
		}

		caluc(ranks, avtry);
		prrnk(ranks);

		printf("もう一度やりますか？(Yes...1/No...0) > ");
		scanf("%d", &replay);
		if (replay==0){
			break;
		}
		
	}
	return 0;
}
