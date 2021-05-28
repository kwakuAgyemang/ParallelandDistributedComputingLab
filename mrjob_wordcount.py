from mrjob.job import MRJob
from mrjob.step import MRStep
import re

WORD_RE = re.compile(r"[\w']+")

class MRWordCount(MRJob):

    def configure_args(self):
        """The program counts the number of times a word appears in a text file"""
        super(MRWordCount, self).configure_args()
        self.add_file_arg(
            "--stop-words",
            help = "specify the stop words file."
        )
    
    def mapper_init(self):
        """This method initializes the resources needed by the mapper function"""
        file = self.options.stop_words 
        self.stopwords_set = None 
        with open(file, "r") as f:
            words = [i.strip().lower() for i in f.read().split()]
        self.stopwords_set = set(words)

    def mapper(self, _, line):
        for word in WORD_RE.findall(line):
            if word not in self.stopwords_set:
                yield(word.lower(), 1)

    def combiner(self, word, counts):
        yield(word, sum(counts))

    def reducer(self, word, counts):
        yield(word, sum(counts))

if __name__ == '__main__':
    MRWordCount.run()