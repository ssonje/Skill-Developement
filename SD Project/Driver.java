/*The driver class which contains the interface for the dictionary*/

import java.io.*;

//Class of the dictionary containing the array of 26 trees

class Dictionary
{

         public WordTree WordList[] = new WordTree[26];
         public int ListSize[];

         public Dictionary()
         {
            ListSize=new int[26];
            for(char namecount=97;namecount<=122;namecount++)  
            {
                String name=namecount+"";
                WordList[namecount-97]=new WordTree(name);
                ListSize[namecount-97]=0;
            }
         }

     //the method for adding new word and meaning to the dictionary
    public void getWordMeaning() throws java.io.IOException
    {
          String word,meaning;
          System.out.print("Enter Word: ");
          word = read.GetString();
          System.out.print("Enter Meaning: ");
          meaning = read.GetString();
          WordList[getIndex(word)].addEntry(word,meaning);
          ListSize[getIndex(word)]++;
          System.out.print("Word entered at location "+getIndex(word)+"\n");
    }

     //the method for deleting a word and meaning from the dicitonary
     public void deleteWordMeaning() throws NullPointerException, java.io.IOException
     {
          String word;
          System.out.print("Enter word: ");
          word=read.GetString();
          WordList[getIndex(word)].deleteEntry(word);
          ListSize[getIndex(word)]--;
          System.out.println(word + " deleted");
     }

     //The method for finding the meaning in the dicitonary
     public void findMeaning() throws NullPointerException, java.io.IOException
     {
          String word;
          System.out.print("Enter word: ");
          word=read.GetString();
          System.out.println("\n"+word+": "+WordList[getIndex(word)].findEntry(word));
     }

     //The method for displaying the correct words for a letter
     public void displayWordTree() throws java.io.IOException
     {
          char letter;
          System.out.print("Enter Letter : ");
          letter=read.GetChar();
          if (letter>=65&&letter<=90)
          {
               System.out.println("The words starting with "+letter+" are as follows:");
               WordList[letter-65].displayTree();
          }
          else if (letter>=97&&letter<=122)
          {
               System.out.println("The words starting with "+letter+" are as follows:");
               WordList[letter-97].displayTree();
          }
          else
          {
               System.out.println("Not a valid input");
          }
     }

     //displays the entire dictionary
     public void displayWordList()
     {
        System.out.println("The contents of the Dictionary are: ");
        for (int index=0;index<=25;index++)
        {
            if (ListSize[index]>0)
            {
                WordList[index].displayTree();    
            }
        }
     }

     //method for saving the dictionary
     public void saveWordMeaning() throws java.io.IOException
     {
          for (int index=0;index<=25;index++)
          {
              if (ListSize[index]>0)
              {
                  System.out.println(ListSize[index]+": "+index);//WordList[index].saveTree(ListSize[index]);
              }
          }
          System.out.println("Dictionary has been written to files."); 
     }

     //method for loading a file into the dictionary
     public void loadWordMeaning() throws java.io.IOException
     {
          for (int index=0;index<=25;index++)
          {
               String filename=WordList[index].Name;
               filename=filename.concat(".txt");
               File checkfile=new File(filename);
               if (checkfile.exists())
               {
                     WordList[index].loadTree();    
               }
          }
          System.out.println("Dictionary has been loaded");
     }

     //method of getting the number of entries in the dictionary
     public void getNodeCount() throws java.io.IOException
     {
          System.out.println();
          System.out.print("Enter a letter: ");
          char letter=read.GetChar();
          if (letter>=65&&letter<=90)
          {
                System.out.println("Entries for "+letter+": "+ListSize[letter-65]);   
          }
          else if (letter>=97&&letter<=122)
          {
                System.out.println("Entries for "+letter+": "+ListSize[letter-97]);   
          }
          else
          {
              System.out.println("Invalid input, try again");   
          }
      }

     //method of getting index of word
     public int getIndex(String word)
     {
          int firstchar=word.charAt(0);
          if (firstchar>=65&&firstchar<=90)
          {
                return (firstchar-65);   
          }
          else if (firstchar>=97&&firstchar<=122)
          {
            return (firstchar-97);    
          }
          else
          {
               System.out.println("Not a valid input");
               return -1;
          }
     }
}


/*
The Driver class file which contains the interface for the dictionary
*/
public class Driver
{
     public static void main(String args[]) throws Exception
     {
          Dictionary dict=new Dictionary();
          char option;

          System.out.print("             DICTIONARY       ");

          System.out.print("\nChoose an Option");
          System.out.print("\n");
          
          do
          {
               System.out.println();
               System.out.println("Press 'I' or 'i', for inserting new word-meaning");
               System.out.println("Press 'D' or 'd', for deleting a word-meaning");
               System.out.println("Press 'F' or 'f', for finding a meaning");
               System.out.println("Press 'T' or 't', to view a word tree");
               System.out.println("Press 'E' or 'e', to view the entire dictionary");
               System.out.println("Press 'S' or 's', to save the dictionary");
               System.out.println("Press 'L' or 'l', to load a dictionary");
               System.out.println("Press 'N' or 'n', to view the enties in word tree");
               System.out.println("Press 'X' or 'x', to exit");
               System.out.print("Press Enter to start");
               read.FlushInput();
               System.out.println();
               System.out.print("Enter an option: ");
               option=read.GetChar();
               read.FlushInput();

               switch(option)
               {
                    case 'I': case 'i': dict.getWordMeaning(); break;
                    case 'D': case 'd': dict.deleteWordMeaning(); break;
                    case 'F': case 'f': dict.findMeaning(); break;
                    case 'T': case 't': dict.displayWordTree(); break;
                    case 'E': case 'e': dict.displayWordList(); break;
                    case 'S': case 's': dict.saveWordMeaning(); break;
                    case 'L': case 'l': dict.loadWordMeaning(); break;
                    case 'N': case 'n': dict.getNodeCount(); break;
                    case 'X': case 'x': System.out.println("Thank you for using The Dictionary, good-bye for now."); System.exit(0);
                    default: System.out.println("Incorrect input, try again.");
               }
            }while (true);
     } 
}

