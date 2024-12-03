#include<stdio.h>

int main(){
	int n,m,pick;
	int arr[100][100];
	int cross[100];
	do{
		printf("\tMENU");
		printf("\n1.Nhap kick co va cac gia tri cua mang: ");
		printf("\n2.In ra mang: ");
		printf("\n3.In ra cac phan tu tren duong bien va tinh tich: ");
		printf("\n4.In ra cac phan tu tren duong chep chinh: ");
		printf("\n5.In ra cac phan tu tren duong cheo phu: ");
		printf("\n6.sap sep duong cheo chinh theo thu tu tang dan: ");
		printf("\n7.tim kiem phan tu va in ra phan tu do: ");
		printf("\n8.thoat: ");
		printf("\nLua chon cua ban: ");
		scanf("%d", &pick);
		switch (pick){
			case 1:{
				printf("nhap so hang: ");
                scanf("%d", &n);
                printf("nhap so cot: ");
                scanf("%d", &m);
                for (int i=0; i<n; i++){
                    for (int j=0; j<m; j++){
                        printf("Nhap phan tu [%d][%d]: ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
				break;
			}
			case 2:{
				printf("Mang da nhap la: \n");
				for (int i=0; i<n; i++){
					printf("\t");
                    for (int j = 0; j<m; j++){
                        printf("%d\t", arr[i][j]);
                    }
                    printf("\n");
                }
				break;
			}
			case 3:{
				int product = 1;
                printf("cac phan tu tren duong bien: \n");
                for (int i=0; i<n; i++) {
                    for (int j=0; j<m; j++){
                        if (i==0 || i==n - 1 || j==0 ||j==m - 1) {
                            printf("%d; ", arr[i][j]);
                            product*= arr[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien: %d\n", product);
				break;
			}
			case 4:{
				printf("Cac phan tu tren duong cheo chinh: ");
                for (int i=0; i<n && i<m; i++){
                    printf("%d; ", arr[i][i]);
                    cross[i]=arr[i][i];
                }
                printf("\n");
				break;
			}
			case 5:{
				printf("Cac phan tu tren duong cheo phu: ");
                for (int i=0; i<n && i<m; i++){
                    printf("%d; ", arr[i][m - i - 1]);
                }
                printf("\n");
				break;
			}
			case 6:{
				int size=sizeof(cross)/sizeof(cross[0]);
			    printf("\n");
			    for (int i=1; i<size; i++) {
			        int key=cross[i];
			        int j=i-1;
			        while (j>=0 && cross[j]>key) {
			            cross[j+1] = cross[j];
			            j--;
			        }
			        cross[j+1]=key;
			    }
			    printf("sau khi sap xep: ");
			    for (int i=0; i<size; i++) {
			        printf("%d ", cross[i]);
			    }
			    printf("\n");
				break;
			}
			case 7:{
				int x;
				printf("Nhap vao so ngau nhien: ");
				scanf("%d", &x);
				for (int i=0; i<n; i++){
					 for (int j=0; j<m; j++){
						if (arr[i][j]==x){
							printf("Vi tri cau phan tu la: a[%d][%d] ", i, j);
						}
					}
				}	
				break;
			}
			case 8:{
				break;
			}
			default:{
				printf("khong hop le");
			}
		}
	} while(pick!=8);
	return 0;
}
