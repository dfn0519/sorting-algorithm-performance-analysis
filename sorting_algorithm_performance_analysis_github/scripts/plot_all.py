import pandas as pd
import matplotlib.pyplot as plt

# =========================
# Experiment 1
# =========================

df1 = pd.read_csv("experiment1.csv")

print("Experiment 1:")
print(df1.head())

data_types = df1["DataType"].unique()

for data_type in data_types:


    data = df1[df1["DataType"] == data_type]

    plt.figure(figsize=(10, 6))


    for algorithm in data["Algorithm"].unique():

        algorithm_data = data[
            data["Algorithm"] == algorithm
        ].sort_values("Size")

        plt.plot(
            algorithm_data["Size"],
            algorithm_data["Time"],
            marker="o",
            label=algorithm
        )


    plt.xscale("log")


    plt.yscale("log")
    plt.ylim(1e-4, 10)

    plt.xlabel("Input Size (n)")
    plt.ylabel("Average Execution Time (seconds)")

    plt.title(
        f"Sorting Algorithm Performance - {data_type} Data"
    )

    plt.grid(True, which="both", alpha=0.3)

    plt.legend()

    plt.tight_layout()

    file_name = (
        "experiment1_"
        + data_type.lower().replace(" ", "_")
        + ".png"
    )

    plt.savefig(file_name, dpi=300)

    plt.show()


# =========================
# Experiment 2
# =========================

df2 = pd.read_csv("experiment2.csv")

print("\nExperiment 2:")
print(df2.head())

plt.figure(figsize=(10, 6))

for algorithm in df2["Algorithm"].unique():

    algorithm_data = df2[
        df2["Algorithm"] == algorithm
    ].sort_values("ValueRange")

    plt.plot(
        algorithm_data["ValueRange"],
        algorithm_data["Time"],
        marker="o",
        label=algorithm
    )


plt.xscale("log")

plt.xlabel("Value Range (k)")
plt.ylabel("Average Execution Time (seconds)")

plt.title(
    "Sorting Algorithm Performance with Different Value Ranges"
)

plt.grid(True, which="both", alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "experiment2_value_range.png",
    dpi=300
)

plt.show()