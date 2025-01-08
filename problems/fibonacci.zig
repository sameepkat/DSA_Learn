const std = @import("std");
const print = std.debug.print;
const stdout = std.io.getStdOut().writer();
const stdin = std.io.getStdIn();

fn Fibonacci(n: usize) usize {
    if (n == 1 or n == 2) {
        return 1;
    } else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

pub fn main() !void {
    var n: usize = 0;
    try stdout.writeAll("Enter number of terms you want: \n");
    try stdin.read(&n);
    print("You entered {}\n ", .{n});
}
