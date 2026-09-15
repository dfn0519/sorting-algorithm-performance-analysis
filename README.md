# 排序演算法效能分析與比較

這是我在大學期間自己完成的排序演算法實作與效能分析專案。除了實作不同排序方法之外，我也希望實際觀察理論上的時間複雜度，在不同資料規模與資料排列方式下會呈現什麼樣的差異。

在測試過程中，我發現單純比較「誰跑得最快」其實不一定公平。例如 Counting Sort 的執行時間除了受到資料數量 `n` 影響，也會受到數值範圍 `k` 影響。因此後來另外設計第二組實驗，固定資料量並改變 Value Range，觀察不同條件對結果的影響。

## 專案內容

目前實作的排序演算法包含：

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Radix Sort
- Counting Sort

其中第一組實驗主要比較不同資料規模與資料排列方式，第二組實驗則進一步觀察 Value Range 對排序效能的影響。

## 實驗一：不同資料規模與資料分布

測試資料分成四種：

- `Random`：隨機資料
- `Reverse`：反向排序資料
- `Sorted`：已排序資料
- `Almost Sorted`：大部分已排序，只隨機交換少部分元素

因為 `O(n²)` 演算法在大量資料下需要非常久的執行時間，所以測試時分成兩組資料規模：

- Bubble / Selection / Insertion：1,000 ～ 50,000
- Merge / Quick / Heap / Radix：50,000 ～ 100,000,000

每一組測試都會執行 **10 次並取平均時間**，降低單次測量造成的誤差。

### O(n²) 演算法比較

以 Random Data 為例：

![Quadratic sorting algorithms](results/figures/quadratic/random.png)

隨著輸入資料量增加，Bubble、Selection、Insertion 的執行時間成長速度都很明顯。這也符合這類演算法在一般情況下約為 `O(n²)` 的理論特性。

不同資料分布的完整圖表可以在 [`results/figures/quadratic`](results/figures/quadratic) 查看。

### 較高效率演算法比較

以 Random Data 為例：

![Efficient sorting algorithms](results/figures/efficient/random.png)

Merge、Quick、Heap、Radix 在較大的資料量下仍能完成測試，因此我將它們和 `O(n²)` 演算法分開畫圖，避免時間尺度差異太大，讓較快演算法的曲線全部擠在一起看不清楚。

完整圖表可以在 [`results/figures/efficient`](results/figures/efficient) 查看。

## 實驗二：Value Range 對效能的影響

第二組實驗固定：

```text
n = 100000
```

接著改變資料中的數值範圍：

```text
10
100
1,000
10,000
100,000
500,000
1,000,000
```

比較的演算法包含 Merge、Quick、Radix、Heap 與 Counting Sort。

![Value range experiment](results/figures/value_range/value_range.png)

從目前測試結果可以看到，Counting Sort 在 Value Range 較小時速度非常快，但隨著 `k` 增加，所需要處理的 counting array 也會變大，因此執行時間逐漸增加。

這讓我注意到：**不同排序演算法受到的輸入條件並不完全相同，所以只用單一資料生成方式比較執行時間，可能會讓結果產生偏差。**

## 我在實作過程中遇到的問題

一開始我把所有演算法畫在同一張圖上，但 Bubble、Selection 等較慢演算法會把 Y 軸範圍拉得很大，使 Merge、Quick 等演算法的差異幾乎看不出來。後來我依照演算法特性分組畫圖，並使用 log scale，讓不同資料規模下的變化比較容易觀察。

另外，一開始看到 Counting Sort 明顯比其他方法快時，我原本只把它當成演算法本身的優勢，但後來發現資料的數值範圍也會直接影響它的時間與空間成本。因此我增加了第二組 Value Range 實驗，而不是只保留原本的執行時間比較。

這個過程讓我比較能理解，做效能分析不只是把程式跑完、記錄時間，還需要去思考測試條件是否公平，以及圖表呈現方式會不會影響對結果的判讀。

## 專案結構

```text
.
├── README.md
├── Makefile
├── requirements.txt
├── src/
│   ├── experiment_1.c
│   ├── experiment_2.c
│   ├── sorting/
│   ├── datasets/
│   └── benchmark/
├── data/
│   ├── experiment1.csv
│   └── experiment2.csv
├── scripts/
│   ├── plot_all.py
│   └── plot_sorting_groups.py
└── results/
    └── figures/
        ├── quadratic/
        ├── efficient/
        └── value_range/
```

## 執行方式

### 1. 編譯 C 程式

在 Linux / macOS 或有安裝 GCC、Make 的環境中：

```bash
make
```

也可以只編譯其中一組：

```bash
make experiment1
make experiment2
```

產生的執行檔會放在 `bin/`。

> 注意：Experiment 1 最大會測到 100,000,000 筆資料，執行時間與記憶體需求都比較高。如果只是想測試程式是否能執行，可以先把 `src/experiment_1.c` 裡的 size 調小。

### 2. Python 畫圖

安裝套件：

```bash
pip install -r requirements.txt
```

目前 CSV 與圖表都已經保留在 repository 中，所以不重新跑 benchmark 也可以直接查看結果。

如果要重新畫分組圖表，可以先進入專案根目錄，再執行對應 script。原始 script 是我實驗時使用的版本，CSV 路徑可以依自己的執行位置做調整。

## 目前結果資料

原始 benchmark 結果保留在：

- [`data/experiment1.csv`](data/experiment1.csv)
- [`data/experiment2.csv`](data/experiment2.csv)

圖表則整理在：

- [`results/figures/quadratic`](results/figures/quadratic)
- [`results/figures/efficient`](results/figures/efficient)
- [`results/figures/value_range`](results/figures/value_range)

## 後續可以繼續改進的地方

目前主要以 `clock()` 測量執行時間，因此當演算法執行非常快時，CSV 中可能出現接近 `0.000000` 的結果。之後可以改用解析度更高的計時方式，並加入標準差或 error bar，進一步觀察多次測試之間的波動。

另外也可以加入更多資料生成方式、記憶體使用量比較，或針對 Quick Sort 的 pivot 選擇方式做更完整的測試。

---

這個專案是我從「實作演算法」進一步嘗試做效能測試與結果分析的練習。對我來說，比最後哪個演算法最快更重要的是：在看到結果之後，能不能找出不合理的地方，再回頭調整測試方法並找出可能的原因。
