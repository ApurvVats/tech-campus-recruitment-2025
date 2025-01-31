Discussion: Efficient Log Extraction from Large Files

Solutions Considered

1. Naive Approach - Line-by-Line Writing
- Reads the log file line by line and writes each matching log directly to the output file.
- Inefficient for 1TB files due to constant disk I/O.
- Slow performance because writing is done per log instead of in batches.

2. Buffered Writing (Optimized I/O)
- Instead of writing each line separately, stores batches of logs in memory and writes them in bulk.
- Significantly reduces disk writes and improves efficiency.
- Handles large files without excessive memory usage.

3. Multi-threaded Processing with Buffered I/O (Final Solution)
- Uses multi-threading to process logs faster.
- Implements buffered writing with locks to avoid frequent disk writes.
- Faster than single-threaded solutions.
- Efficient for both SSD and HDD storage.
- Scales well for extremely large log files.

Final Solution Summary

Why was C++ chosen?
- Memory Efficiency: No unnecessary overhead like Python or Java.
- Fast File I/O: Uses ifstream and ofstream with binary mode for better performance.
- Multi-threading Support: Uses C++ threads to improve speed.
- Direct Control Over Resources: Optimizes buffer sizes, locking mechanisms, and memory allocation.

The final implementation uses:
- Multi-threading with std::thread to process logs faster.
- Buffered writing with vector<string> buffer to reduce disk I/O overhead.
- Mutex Locking with std::mutex to handle parallel writes without corruption.

Steps to Run

1. Compilation
Run the following command to compile the program
g++ -O3 -std=c++17 -pthread -o extract_logs extract_logs.cpp

2. Execution
Run the program by providing
- Log file path
- Date to filter in YYYY-MM-DD format

./extract_logs test_logs.log 2024-12-01

3. Output
Extracted logs will be saved in
output/output_2024-12-01.txt

Key Takeaways

- Fastest approach with multi-threading and buffered writes.
- Scales well for 1TB plus log files.
- C++ chosen for speed, efficiency, and memory control.
- Batch processing ensures high performance on large datasets.

Next Steps

git add Discussion.md
git commit -m "Added Discussion.md with approach, execution steps, and summary"
git push origin main

Submit your GitHub repository link in the form.
