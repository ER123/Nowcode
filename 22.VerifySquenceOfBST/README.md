判断一个序列是不是一个搜索二叉树后续遍历的结果：此题与重建二叉树解法相似，搜索二叉树的后续遍历的根节点在最后一个，前面的结点可以分为两部分，
一部分都比根节点小，另一部分都比根节点大，而且两部分都是连续的，每个部分又都可以分为左右两部分，因此可以使用递归进行求解。
