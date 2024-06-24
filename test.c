/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:33:35 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/24 13:57:44 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//値を交換する関数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
	printf("\x1b[33mswap\n");
}

/*クイックソート*/
void QuickSort(int A[], int left, int right)
{
    // 変数定義
    int Left, Right;
    int pivot;

    // 初期値は引数から
    Left = left; Right = right;

    // 基準は真ん中に設定
    pivot = A[(left + right) / 2];
	
	printf("pivot = %d\nLeft = %d\nRight = %d\n", pivot, Left, Right);

    // ソーティング
    while (1) {

        // 基準より小さい値を左から見つけていく
        while (A[Left] < pivot) Left++;

        // 基準より大きい値を右から見つけていく
        while (pivot < A[Right]) Right--; 

        // 見つかった値の順序が逆になったら終了 
        if (Left >= Right) break;

        // 値を交換
        swap(&A[Left], &A[Right]);

        // 次の値に移動
        Left++; Right--;

    }

	int	i = 0;
	while (i < 5)
	{
		printf("\x1b[36m%d ", A[i]);
		i++;
	}
	printf("\x1b[0m\n");
	

    //左のデータ群を対象としてクイックソートを再帰
    if (left < Left - 1) QuickSort(A, left, Left - 1);

    //右のデータ群を対象としてクイックソートを再帰
    if (Right + 1 < right) QuickSort(A, Right + 1, right);

}

int	main(void)
{
	int	*a;
	
	a = (int *)malloc(5 * sizeof(int));
	if (a == NULL)
		return (1);
	a[0] = 5;
	a[1] = 4;
	a[2] = 3;
	a[3] = 2;
	a[4] = 1;
	int	i = 0;
	while (i < 5)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
	QuickSort(a, 0, 4);
	i = 0;
	while (i < 5)
	{
		printf("%d ", a[i]);
		i++;
	}
	free(a);
	return (0);
}