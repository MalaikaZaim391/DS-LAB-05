# DS-LAB-05 TASKS
Task 1: A text editor stores the last 8 editing operations in a stack. Each operation is represented by an
integer code. The editor receives the following operations:
12, 25, 17, 31, 44, 19
The user then presses Undo three times, performs a new operation 52, and presses Undo twice again.
Implement the system using an array-based stack. After every operation, display the current top
operation. At the end, display the operations that remain in the stack from top to bottom.
Your program should also handle an Undo request when the stack is empty.

Task 2: You are building a very small text editor that only supports appending words to a document, but
it still has to feel like a real editor when the user makes a mistake. Every time the user calls type(word),
that word is appended to the end of the document. The user can call undo() at any time to reverse the
most recent typing action, and redo() to bring back an action that was just undone. The catch is that once
the user types something new after an undo, every action that could have been redone is permanently
lost exactly like undo/redo works in a real editor such as Word or VS Code, you cannot redo into a
history branch that no longer exists once new history has been written over it. For example, calling
type(&quot;Hello&quot;) and then type(&quot;World&quot;) leaves the document as &quot;Hello World&quot;; calling undo() removes
&quot;World&quot;, leaving &quot;Hello&quot;; calling redo() restores it to &quot;Hello World&quot;; calling undo() again returns to
&quot;Hello&quot;; but if the user now calls type(&quot;There&quot;), the document becomes &quot;Hello There&quot; and any further
call to redo() must do nothing, because the &quot;World&quot; branch of history has been erased by the new action.
Your Task (C++): Implement this as a C++ class with type(string), undo(), redo(), and print() methods,
using two stacks to manage the undo and redo history. Write a main() that reproduces the exact sequence
of calls above and prints the document state after each call.
Tasks 3: An office printer serves jobs strictly in the order they were submitted. One afternoon, IT support
discovers that the first K jobs currently waiting were accidentally submitted in the wrong order by a faulty
scanner app, and need to be reversed but every job after the first K was submitted correctly and must be
left exactly where it is, in its original order. For example, if the print queue currently holds, from front to
back, J1, J2, J3, J4, J5, J6, J7, and K = 3, the queue must become J3, J2, J1, J4, J5, J6, J7 only the first
three jobs are reversed, and the remaining four are untouched, still in their original relative order at the
back of the queue. Write a function void reverseFirstK(Queue &amp;q, int k) that reverses just the first k
elements of the queue in place, leaving the rest exactly as they were, using one stack as your only extra
storage. Test your function on the example above with K = 3.

Task 5 : An airport boarding gate has limited space for passengers waiting to board an aircraft. The
passengers are managed according to their arrival order, where the passenger who arrives first is boarded
first. The gate has a capacity of six passengers and uses a circular queue to efficiently reuse the positions
that become available after passengers are boarded. Initially, passengers with IDs 101, 102, 103, 104,
105, and 106 enter the boarding queue. The first three passengers are then boarded, after which
passengers 107, 108, and 109 arrive at the gate. The boarding process continues with two more
passengers being boarded, followed by the arrival of passenger 110. One more passenger is then
boarded, after which passengers 111 and 112 arrive. Implement this scenario using an array-based
circular queue and display the final passengers in their actual boarding order along with the final front
and rear positions.
Task 6: A shipping company&#39;s only available storage equipment is a set of stack-style bins, crates can
only be added or removed from the top. Management now wants shipments processed strictly in the
order they were received (first in, first out), but nobody is willing to buy new equipment. You are asked
to prove this is possible by building a queue that is internally made of nothing but two stack bins
working together, exposing only enqueue(item) and dequeue() to the rest of the system, which must
never know that stacks are involved underneath. For example, if items A, B, and C are enqueued in that
order, calling dequeue() three times in a row must return A, then B, then C true, FIFO behaviour even
though every underlying operation is a stack push or pop.
Logical Hint: Use one stack purely for incoming items and a second stack purely for outgoing items.
Whenever the outgoing stack is empty and a dequeue() is requested, pour the entire incoming stack into
the outgoing stack one item at a time (which reverses their order back to arrival order), then pop from
the outgoing stack. If the outgoing stack already has items, just pop from it directly, don&#39;t touch the
incoming stack at all in that case.
Your Task (C++): Implement a class MyQueue with enqueue(int) and dequeue() methods, using two
stacks. Test it with the sequence enqueue(A), enqueue(B), dequeue(), enqueue(C), dequeue(), dequeue()
and confirm the dequeues return A, B, C in that order
