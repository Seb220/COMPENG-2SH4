package SLL;
public class SLLSet {
    
    private int size;
    private SLLNode head;
    
    public SLLSet()
    {
        head = null;
        size = 0;
    }
    public SLLSet(int[] sortedArray)
    {
        size = sortedArray.length;
        head = new SLLNode(sortedArray[0], null);
        SLLNode currentNode = head;
        
        for(int i = 1; i<size; i++)
        {
            currentNode.next = new SLLNode(sortedArray[i], null);
            currentNode = currentNode.next;
        }
    }
    
    public int getSize()
    {
        return size;
    }
    
    public SLLSet copy()
    {
        SLLSet Copy = new SLLSet();
        
        SLLNode currentNode = head;
        while(currentNode != null)
        {
            Copy.add(currentNode.value);
            currentNode = currentNode.next;
        }
        return Copy;
    }
    
    public boolean isIn(int v)
    {
        SLLNode currentNode = head;
        
        while(currentNode != null)
        {
            if(currentNode.value == v)
            {
                return true;
            }
            currentNode = currentNode.next;
        }
        return false;
    }
    
    public void add(int v)
    {
       if(head == null)
       {
           head = new SLLNode(v, null);
           size = 1;
       }
       if(v<head.value)
       {
           head = new SLLNode(v, head);
           size++;
       }
       else  
       {
           SLLNode currentNode = head;
           SLLNode prevNode = null;
           
           while(currentNode != null && v>currentNode.value)
           {
               prevNode = currentNode;
               currentNode = currentNode.next;
           }
           if(currentNode == null)                             // if v is the largest value in the list
           {
               prevNode.next = new SLLNode(v, currentNode);
               size++;
           }
           else if(currentNode.value != v)                     // if the last value=v
           {
               prevNode.next = new SLLNode(v, currentNode);
               size++;
           }                  
       }    
    }        
    
    public void remove(int v)
    {
        if(head == null)
            return;     //to end method
        if(head.value == v)
        {
            head = head.next;
            size--;
            return;
        }
        
        SLLNode currentNode = head;
        SLLNode prevNode = null;
        
        while(currentNode != null && currentNode.value != v)
        {
            prevNode = currentNode;
            currentNode = currentNode.next;    // finds node with value=v and references it with currentNode
        }
        if(currentNode != null)
        {
            prevNode.next = currentNode.next;
            size--;
        }
    }
    
    public SLLSet union(SLLSet s)
    {
       if(s.head == null)
           return this;
       if(this.head == null)
           return s;
       
       SLLSet union = new SLLSet();
       SLLNode thisCurrentNode = this.head;
       SLLNode sCurrentNode = s.head;
       
       if(thisCurrentNode.value < sCurrentNode.value)
       {
           union.head = new SLLNode(thisCurrentNode.value, null);
           union.size = 1;
           thisCurrentNode = thisCurrentNode.next;
       }
       else if(thisCurrentNode.value > sCurrentNode.value)
       {
           union.head = new SLLNode(sCurrentNode.value, null);
           union.size = 1;
           sCurrentNode = sCurrentNode.next;
       }
       
       else if(thisCurrentNode.value == sCurrentNode.value)
       {
           union.head = new SLLNode(thisCurrentNode.value, null);
           union.size = 1;
           thisCurrentNode = thisCurrentNode.next;
           sCurrentNode = sCurrentNode.next;
       }
       
       SLLNode unionCurrentNode = union.head;
       while(thisCurrentNode != null && sCurrentNode != null)
       {
           if(thisCurrentNode.value < sCurrentNode.value)
           {
               unionCurrentNode.next = new SLLNode(thisCurrentNode.value, null);
               union.size++;
               unionCurrentNode = unionCurrentNode.next;
               thisCurrentNode = thisCurrentNode.next;
           }
           else if(thisCurrentNode.value > sCurrentNode.value)
           {
               unionCurrentNode.next = new SLLNode(sCurrentNode.value, null);
               union.size++;
               unionCurrentNode = unionCurrentNode.next;
               sCurrentNode = sCurrentNode.next;
           }
           else if(thisCurrentNode.value == sCurrentNode.value)
           {
               unionCurrentNode.next = new SLLNode(sCurrentNode.value, null);
               union.size++;
               unionCurrentNode = unionCurrentNode.next;
               thisCurrentNode = thisCurrentNode.next;
               sCurrentNode = sCurrentNode.next;
           }
       }
       if(sCurrentNode == null)
       {
           while(thisCurrentNode != null)
           {
               unionCurrentNode.next = new SLLNode(thisCurrentNode.value, null);
               union.size++;
               unionCurrentNode = unionCurrentNode.next;
               thisCurrentNode = thisCurrentNode.next;
           }   
       }
       else if(thisCurrentNode == null)
       {
           while(sCurrentNode != null)
           {
               unionCurrentNode.next = new SLLNode(sCurrentNode.value, null);
               union.size++;
               unionCurrentNode = unionCurrentNode.next;
               sCurrentNode = sCurrentNode.next;
           }
       }
       return union; 
    }
    
    public SLLSet intersection(SLLSet s)
    {
       SLLSet intersect = new SLLSet();
       if(s.head == null || this.head == null)
           return intersect;
       
       SLLNode thisCurrentNode = this.head;
       SLLNode sCurrentNode = s.head;
       
       while(thisCurrentNode != null && sCurrentNode != null)
       {
           if(thisCurrentNode.value < sCurrentNode.value)
           {
               thisCurrentNode = thisCurrentNode.next;
           }
           else if(thisCurrentNode.value > sCurrentNode.value)
           {
               sCurrentNode = sCurrentNode.next;
           }
           else if(thisCurrentNode.value == sCurrentNode.value)
           {
               intersect.head = new SLLNode(thisCurrentNode.value, null);
               thisCurrentNode = thisCurrentNode.next;
               sCurrentNode = sCurrentNode.next;
               intersect.size = 1;
               break;
           }
       }
       
       SLLNode intersectCurrentNode = intersect.head;
       while(thisCurrentNode != null & sCurrentNode != null)
       {
           if(thisCurrentNode.value < sCurrentNode.value)
           {
               thisCurrentNode = thisCurrentNode.next;
           }
           else if(sCurrentNode.value < thisCurrentNode.value)
           {
               sCurrentNode = sCurrentNode.next;
           }
           else if(thisCurrentNode.value == sCurrentNode.value)
           {
               intersectCurrentNode.next = new SLLNode(thisCurrentNode.value, null);
               intersect.size++;
               intersectCurrentNode = intersectCurrentNode.next;
               thisCurrentNode = thisCurrentNode.next;
               sCurrentNode = sCurrentNode.next;
           }
       }
       return intersect;
    }
    
    public SLLSet difference(SLLSet s)
    {
        SLLSet diff = new SLLSet();
        
        SLLNode thisCurrentNode = this.head;
        while(thisCurrentNode != null)
        {
            diff.add(thisCurrentNode.value);
            thisCurrentNode = thisCurrentNode.next;
        }
        
        SLLNode sCurrentNode = s.head;
        while(sCurrentNode != null)
        {
            diff.remove(sCurrentNode.value);
            sCurrentNode = sCurrentNode.next;
        }
        return diff;
    }
    
    public static SLLSet union(SLLSet[] sArray)
    {
        SLLSet union = sArray[0];
        for(int i = 1; i<sArray.length-1; i++)
                {
                    union = union.union(sArray[i]);
                }
        return union;
    }
    
    public String toString()
    {
        String string = "{";
        SLLNode currentNode = head;
        
        while(currentNode != null)
        {
            string = string + currentNode.value;
            if(currentNode.next != null)
                string += ", ";
            
            currentNode = currentNode.next;  
        }
        string += "}";
        
        return string;
    }  
    
}
