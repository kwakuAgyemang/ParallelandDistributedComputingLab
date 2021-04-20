from mrjob.job import MRJob
from mrjob.step import MRStep




class MRMatrixMultiplication(MRJob):

    def configure_args(self):
        """The program counts the number of times a word appears in a text file"""
        super(MRMatrixMultiplication, self).configure_args()
        self.add_file_arg(
            "--stop-words",
            help = "specify the stop words file."
        )
    
    def mapper_init(self):
        """This method initializes the resources needed by the mapper function"""
        file = self.options.stop_words 
        self.stopwords_set = None 
        with open(file, 'r') as f:
            words = [[num for num in line.split(',')] for line in f]
        self.stopwords_set = set(words)

    def mapper(self, _, line):
        A = []
        B = []
        current = A

        for line in file.readlines():
            if ',' not in line: 
                current = B
            else:
                current.append([]) 
                for x in line.split(','): 
                    current[len(current) - 1].append(int(x))
                yield(word, A, B)

    def matrixCalc(self, A, B):
        C = []
        for i in range(A.length()):
            C[i] = 0.0
            for j in range(B.length()):
                C[i] += A[i][j] * B[j]
        return C


    def reducer(self, word, A, B):
        yield(word, matrixCalc(A, B))

if __name__ == '__main__':
    MRMatrixMultiplication.run()