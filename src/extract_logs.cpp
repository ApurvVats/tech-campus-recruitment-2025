#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread> 
#include <mutex>  
using namespace std;


mutex write_lock;

void flush_buffer(ofstream &outfile, vector<string> &buffer) {
    lock_guard<mutex> lock(write_lock);
    for (const auto &entry : buffer) outfile << entry << '\n';
    buffer.clear();
}

void extract_logs(const string &log_file, const string &date) {
    ifstream infile(log_file, ios::in | ios::binary);
    if (!infile) return;
    
    ofstream outfile("output/output_" + date + ".txt", ios::out | ios::binary);
    if (!outfile) return;

    string line;
    vector<string> buffer;
    buffer.reserve(20000);

    while (getline(infile, line)) {
        if (line.compare(0, 10, date) == 0) {
            buffer.push_back(move(line));
            if (buffer.size() >= 20000) flush_buffer(outfile, buffer);
        }
    }
    
    flush_buffer(outfile, buffer);

    infile.close();
    outfile.close();
}

int main(int argc, char *argv[]) {
    if (argc != 3) return 1;
    thread log_thread(extract_logs, argv[1], argv[2]);
    log_thread.join();
    return 0;
}
