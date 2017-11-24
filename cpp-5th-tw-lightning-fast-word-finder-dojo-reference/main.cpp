#include <iostream>
/*
namespace LightningFastWordFinder
{
    class Program
    {
        static string name = "YOUR NAME";
        static int numOfRuns = 1000;

        static double RunParserPerformanceTests(string text)
        {
            string longestWord;
            DateTime start = DateTime.Now;
            for (int i = 0; i < numOfRuns; ++i)
            {
                Console.WriteLine("Run: " + i);
                LightningWordFinder parser = new LightningWordFinder();
                longestWord = parser.GetLongestWord(text);

                if (longestWord != "Constantinopolitan")
                {
                    Console.WriteLine("The longest word is not what I wanted to see..");
                    Thread.Sleep(20);
                }
            }
            DateTime end = DateTime.Now;
            return end.Subtract(start).TotalMilliseconds / numOfRuns;
        }

        static void StoreHighScore(double highscore)
        {
            StreamWriter writer = File.AppendText("highscore.txt");
            writer.WriteLine(name + " Runs: " + numOfRuns + " Score: " + highscore);
            writer.Close();
        }

        static void Main(string[] args)
        {
            string text = File.ReadAllText("history-of-egypt-chaldea-syria-babylonia-assyria.txt");
            Console.WriteLine("Text length: " + text.Length);
            double avgRuntime = RunParserPerformanceTests(text);
            Console.WriteLine("Average Running Time: " + avgRuntime);
            StoreHighScore(avgRuntime);

            Console.ReadKey();
        }
    }
}

             string longestWord = String.Empty;

            int currentWordStart = 0;
            int currentWordLength = 0;
            int biggestWordLength = 0;
            int textLength = text.Length;
            for (int i = 0; i < textLength; ++i)
            {
                //if (!Char.IsLetter(text[i])) this is slower
                if( text[i] < 65 ||
                    text[i] > 122 ||
                   (text[i] > 90 && text[i] < 97) )
                {
                    if (currentWordLength > biggestWordLength)
                    {
                        string word = text.Substring(currentWordStart, currentWordLength);
                        if (word.Length > longestWord.Length)
                        {
                            longestWord = word;
                            biggestWordLength = currentWordLength;
                        }
                    }
                    currentWordLength = 0;
                    currentWordStart = i+1;
                    continue;
                }
                ++currentWordLength;
            }
            return longestWord;

*/

#include <fstream>
#include <string>
#include <cerrno>
#include <chrono>
#include "LightningWordFinder.hpp"

std::string getFileContents(const std::string& filename)
{
    std::string contents;
    std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);
    if(in) {
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
    }else{
        std::cout << "File reading was not successful: " << filename << std::endl;
    }
    return contents;
}

double runParserPerformanceTests(const std::string& text, const unsigned numOfRuns)
{
    unsigned penalty = 0;
    std::string longestWord;
    auto begin = std::chrono::high_resolution_clock::now();
    for(unsigned i = 0; i < numOfRuns; ++i)
    {
        //std::cout << "Run: " << i << std::endl;
        LightningWordFinder parser;
        longestWord = parser.getLongestWord(text);

        if (longestWord != "Constantinopolitan")
        {
            std::cout << "The longest word is not what I wanted to see.. '" << longestWord << "'" << std::endl;
            penalty += 20;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
    return duration / numOfRuns + penalty;
}

int main() {
    std::string text = getFileContents("../txt/history-of-egypt-chaldea-syria-babylonia-assyria.txt");
    std::cout << "Text length: " << text.size() << std::endl;
    if(text.empty()) return 1;

    double avgRuntime = runParserPerformanceTests(text, 1000);
    std::cout << "Average Running Time: " << std::fixed << avgRuntime << "ns" << std::endl;

    return 0;
}