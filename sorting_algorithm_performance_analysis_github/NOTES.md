# Repository 整理說明

這份 GitHub 版本以原始上傳專案為基礎重新整理資料夾與檔名，保留原本的演算法、實驗資料與圖表。

另外修正兩個不影響整體實驗設計的小問題：

1. Bubble Sort 對兩個元素的邊界判斷。
2. Counting Sort 使用完 counting array 後補上 `free()`，避免記憶體未釋放。

其餘 benchmark 設計與原始 CSV 結果均保留。
