from mrjob_wordcount import MRWordCount
import sys

def lab(job):
    if job == "count":
        print("do word count")
    else:
        print("program not supported")

if __name__ == '__main__':
    job = sys.argv[1]
    lab(job)