寻找二叉树中所有路径的路径之和等于给定值：从二叉树根节点开始进行查找，直到叶结点为止，如果此时路径之和等于给定的值就保存下来，
如果不等于就回退到父结点，寻找另一个子树上的路径，可以使用递归，因为需要保存父节点和已经找到的路径，可以使用栈进行保存已找到的路径，
递归的过程就是出栈入栈的顺序。