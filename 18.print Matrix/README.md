需要画图帮助理解！

顺时针打印矩阵内容，从外到内一层一层输出，按照向右->向下->向左->向上，一共输出四次，在输出一层时注意停止开始的条件，输出一圈矩阵的行列减少2，
因此如果要输出必须保证当前的行列小于矩阵行列的一半，在输出时会遇到三种特殊情况：（1）只有向右的输出边；（2）只有向右和向下的输出边；
（3）只有向右向下和向左的输出边。只有在width-startX-1>0时才能继续向下输出，在保证向下输出的条件和height-startY-1这两个条件保证下才能继续向左输出，
只有在width-startX-1>0和height-startY-1>1（因为已经向右输出了）条件下才能继续向上输出。
