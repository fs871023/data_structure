學號：406315017
系級：心理四
姓名：鄧智宇
作業概述：
1.在主程式內部建立BST，然後實作infix-order和level-order的traversal
	infix-order實作參考課本的方法
	level-order實作則是建立一個queue來放走過的節點，先把root的data放入，
	然後dequeue最前面的data，如果他有child，也把兩者依序push進去
	最後會依照階層順序把所有資料印出來
2.建立BST->找到最大的硬幣總和路徑->把符合最大總和的路徑印出來
	最大總和的方式用遞迴處理，假設每次的路徑不會有負數的硬幣，
	計算左右子樹的其中的最大路徑總和，然後和現在的硬幣樹相加，遞迴後即可獲得最大的總和

	印出路徑方式如下：建立一stack來把位置的data push進去
	每次到下個節點的時候，都會把計算到目前為止的路徑總和，及把目前位置push 進stack
	如果現在到leaf了，就比對路徑總和是否等於最大總和，是得話就印出stack的內容
	如果還沒到leaf時，都遞迴處理左右子樹
	處理完後，把自己的位置data pop出來
有些資料要用指標傳遞，以確實能把每次更動儲存

參考網站：https://www.cnblogs.com/grandyang/p/4042156.html