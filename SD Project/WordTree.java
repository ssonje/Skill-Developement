 /* 
    The WordTree file contains the construtors for the functionality
    of the dictionary. It displays, finds,adds,and deletes tree nodes.
 */
import java.io.*;

class TreeNode
{
     String Word;
     String Meaning;
     TreeNode Left;
     TreeNode Right;

     // constructor of tree node taking two parameters
     public TreeNode(String Word,String Meaning)
     {
          this.Word=Word;
          this.Meaning=Meaning;
          this.Left=null;
          this.Right=null;
     }
}

    //class of WordTree
public class WordTree
{
     TreeNode Root;
     String Name;
     static int index;

     static
     {
         index=0;
     }

     public WordTree(String Name)
     {
         this.Name=Name;
     }

     //method for adding an item into the tree
     public void addEntry(String Word,String Meaning)
     {
         Root=addNewNode(Root,Word,Meaning);
     }

     private TreeNode addNewNode(TreeNode node,String word,String meaning)
     {
          if (node==null)
          {
              return new TreeNode(word,meaning);
          }
          else if (node.Word.compareTo(word)<=0)
          {
               node.Left=addNewNode(node.Left,word,meaning);
               return node;
          }
          else
          {
               node.Right=addNewNode(node.Right,word,meaning);
               return node;
          }
     }

     //construtor for finding an element in a tree
     public String findEntry(String word) throws NullPointerException
     {
          TreeNode tempnode=new TreeNode("","");
          find(Root,word,tempnode);
          return tempnode.Meaning;
     }

     private void find(TreeNode node,String word,TreeNode temp) throws NullPointerException
     {
          try
          {
               if (node.Word.compareTo(word)==0)
               {
                    temp.Word=node.Word;
                    temp.Meaning=node.Meaning;       
                    temp.Left=node.Left;
                    temp.Right=node.Right;    
               }
               else if (node.Word.compareTo(word)>0)
               {
                    find(node.Right,word,temp);
               }

               else if (node.Word.compareTo(word)<0)
               {
                    find(node.Left,word,temp);   
               }

          }
          catch(Exception e)
          {
               temp.Word=temp.Meaning="No match found";
               temp.Right=temp.Left=null;
          }
     }

     //constructor for deleting an item in the tree
     public void deleteEntry(String word) throws NullPointerException
     {
          delete(Root,word);
          System.gc();
     }

     private void delete(TreeNode node,String word) throws NullPointerException
     {
          try
          {
               if (node.Word.compareTo(word)==0)
               {
                    node.Word=node.Meaning="";   
               }
               else if (node.Word.compareTo(word)>0)
               {
                   delete(node.Right,word);
               }
               else if (node.Word.compareTo(word)<0)
               {
                   delete(node.Left,word);
               }
          }
          catch(Exception e)
          {
                System.out.println("No match found");
          }
     }

     //constructor for displaying all the items in the tree
     public void displayTree()
     {
        display(Root);
     }

     private void display(TreeNode node)
     {
          if (node==null)
          {
                return;   
          }
          else
          {
               display(node.Right);
              
               if (node.Word!=""||node.Meaning!="")
               {
                    System.out.println(node.Word+": "+node.Meaning);   
               }
               display(node.Left);
          }
     }

     //methods for saving a tree to a file
     public void saveTree(int ListSize) throws java.io.IOException
     {
          String List[][]=new String[ListSize][2];
          save(Root,List);
          saveToFile(List,ListSize);
     }

     void save(TreeNode node, String List[][]) throws java.io.IOException
     {
          if (node==null)
          {
                return;   
          }
          else
          {
               save(node.Left,List);
              
               if (node.Word!=""&&node.Meaning!="")  
               {
                    List[index][0]=node.Word;
                    List[index][1]=node.Meaning;
                    index++;
               }
              
               save(node.Right,List);
          }
     }

     void saveToFile(String List[][],int ListSize) throws java.io.IOException
     {
          String filename=this.Name;
          filename=filename.concat(".txt");
          PrintWriter outfile=new PrintWriter(new FileWriter(filename));
          
          for (int i=0;i<ListSize;i++)
          {
               outfile.println(List[i][0]);
               outfile.println(List[i][1]);
          }
          outfile.close();
     }


     //methods for loading a file that contains a tree
     public void loadTree() throws java.io.IOException, NullPointerException
     {
          String filename=this.Name;
          filename=filename.concat(".txt");
          BufferedReader infile=new BufferedReader(new FileReader(filename));

          String meaning,word;

          do
          {
               word=infile.readLine();
               meaning=infile.readLine();   
               Root=addNewNode(Root,word,meaning);
          }while (!(word.compareTo("null")==0));

          infile.close();                      
 }

}


 //sample test runs done over here while making this file
 /*
 public static void main(String args[]) throws NullPointerException, java.io.IOException
 {
  WordTree WordList[] = new WordTree[26];

  String name;
  char tempchar;
  for (char namecount=0;namecount<=25;namecount++)
  {
   tempchar=(char)(namecount+97);
   name=""+tempchar;
   WordList[namecount]=new WordTree(name);
   System.out.println(name+": "+name.length());
  }   

  String word,meaning;
  System.out.println("Enter a word: ");
  word=read.GetString();
  System.out.println("Enter its meaning: ");
  meaning=read.GetString();
  tempchar=word.charAt(0);
  if (tempchar>=65&&tempchar<=90)
  {
   tempchar=(int)(tempchar-65);
   WordList[tempchar].addEntry(word,meaning);
  }
  else if (tempchar>=97&&tempchar<=122)
  {
   tempchar=(int)(tempchar-97);
   WordList[tempchar].addEntry(word,meaning);
  }
  else
   System.out.println("Enter a valid input please!!!");
 }
*/

