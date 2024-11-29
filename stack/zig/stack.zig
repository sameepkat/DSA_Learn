const std = @import("std");

const Stack = struct {
   size: usize,
   top: isize,
   STACK: []i32,
   
   pub fn init(SIZE: usize) !Stack {
       const allocator = std.heap.page_allocator;
       const stack_memory = try allocator.alloc(i32, SIZE);
       
       return Stack{
           .size = SIZE,
           .top = -1,
           .STACK = stack_memory,
       };
   }
   
   pub fn push(self: *Stack, item: i32) void {
       if (self.top >= @intCast(isize, self.size) - 1) {
           std.debug.print("Stack overflow\n", .{});
           return;
       }
       self.top += 1;
       self.STACK[@intCast(usize, self.top)] = item;
   }
   
   pub fn pop(self: *Stack) ?i32 {
       if (self.top == -1) {
           std.debug.print("Stack underflow\n", .{});
           return null;
       }
       const item = self.STACK[@intCast(usize, self.top)];
       self.top -= 1;
       return item;
   }
   
   pub fn display(self: *Stack) void {
       std.debug.print("Items in the stack: ", .{});
       var i: usize = 0;
       while (i <= @intCast(usize, self.top)) : (i += 1) {
           std.debug.print("{d} ", .{self.STACK[i]});
       }
       std.debug.print("\n", .{});
   }
};

pub fn main() !void {
   var s = try Stack.init(5);
   std.debug.print("The size of stack is {d}\n", .{s.size});
   s.push(5);
   s.push(2);
   s.push(1);
   s.display();
}
