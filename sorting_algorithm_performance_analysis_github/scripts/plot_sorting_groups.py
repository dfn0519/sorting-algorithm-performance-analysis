from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

base = Path(".")
df1 = pd.read_csv(base / "experiment1.csv")
df2 = pd.read_csv(base / "experiment2.csv")

root = base / "sorting_charts"
bubble_dir = root / "bubble_group"
merge_dir = root / "merge_group"
counting_dir = root / "counting_group"

for folder in [bubble_dir, merge_dir, counting_dir]:
    folder.mkdir(parents=True, exist_ok=True)

bubble_group = ["Bubble", "Selection", "Insertion"]
merge_group = ["Merge", "Quick", "Heap", "Radix"]

def natural_log_limits(values):
    vals = np.asarray(values, dtype=float)
    vals = vals[np.isfinite(vals) & (vals > 0)]
    if len(vals) == 0:
        return None
    return max(vals.min() * 0.7, 1e-6), vals.max() * 1.35

def plot_group(group, folder, title):
    for dtype in df1["DataType"].unique():
        d = df1[(df1["DataType"] == dtype) & (df1["Algorithm"].isin(group))].copy()
        if d.empty:
            continue

        plt.figure(figsize=(9, 5.5))

        for algo in group:
            a = d[d["Algorithm"] == algo].sort_values("Size")
            a = a[a["Time"] > 0]

            if not a.empty:
                plt.plot(
                    a["Size"], a["Time"],
                    marker="o",
                    linewidth=1.8,
                    markersize=5,
                    label=algo
                )

        plt.xscale("log")
        plt.yscale("log")

        lim = natural_log_limits(d["Time"])
        if lim:
            plt.ylim(*lim)

        plt.xlabel("Input Size (n)")
        plt.ylabel("Average Execution Time (seconds)")
        plt.title(f"{title} - {dtype} Data")
        plt.grid(True, which="major", alpha=0.3)
        plt.legend()
        plt.tight_layout()

        plt.savefig(
            folder / f"{dtype.lower().replace(' ', '_')}.png",
            dpi=300,
            bbox_inches="tight"
        )

        plt.show()

plot_group(
    bubble_group,
    bubble_dir,
    "Quadratic Sorting Algorithms"
)

plot_group(
    merge_group,
    merge_dir,
    "Efficient Sorting Algorithms"
)

plt.figure(figsize=(9, 5.5))

order = ["Counting", "Radix", "Quick", "Merge", "Heap"]
algos = [a for a in order if a in df2["Algorithm"].unique()]
algos += [a for a in df2["Algorithm"].unique() if a not in algos]

for algo in algos:
    a = df2[df2["Algorithm"] == algo].sort_values("ValueRange")
    a = a[a["Time"] > 0]

    if not a.empty:
        plt.plot(
            a["ValueRange"], a["Time"],
            marker="o",
            linewidth=1.8,
            markersize=5,
            label=algo
        )

plt.xscale("log")
plt.yscale("log")

lim = natural_log_limits(df2["Time"])
if lim:
    plt.ylim(*lim)

plt.xlabel("Value Range (k)")
plt.ylabel("Average Execution Time (seconds)")
plt.title("Effect of Value Range on Sorting Performance")
plt.grid(True, which="major", alpha=0.3)
plt.legend()
plt.tight_layout()

plt.savefig(
    counting_dir / "value_range.png",
    dpi=300,
    bbox_inches="tight"
)

plt.show()
