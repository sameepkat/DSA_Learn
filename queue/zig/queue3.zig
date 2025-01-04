const std = @import("std");
const print = std.debug.print;
const stdout = std.io.getStdOut().writer();

pub fn Queue(comptime SIZE: usize) type {
    return struct {
        const Self = @This();
        allocator: std.mem.Allocator,
        items: []isize,
        rear: isize,
        front: isize,

        pub fn init(allocator: std.mem.Allocator) !Self {
            const items = try allocator.alloc(isize, SIZE);
            return Self{
                .allocator = allocator,
                .items = items,
                .rear = -1,
                .front = -1,
            };
        }

        pub fn deinit(self: Self) void {
            self.allocator.free(self.items);
        }

        pub fn enqueue(self: *Self, num: isize) !void {
            if (self.front == -1) {
                self.front = 0;
            }
            if (self.rear == @as(isize, SIZE) - 1) {
                try stdout.print("Queue is full\n", .{});
                return;
            }
            self.rear += 1;
            self.items[@intCast(self.rear)] = num;
        }

        pub fn dequeue(self: *Self) !isize {
            if (self.front == -1 or self.front > self.rear) {
                try stdout.print("Empty queue\n", .{});
                return error.EmptyQueue;
            }
            const item = self.items[@intCast(self.front)];
            self.front += 1;
            return item;
        }

        pub fn display(self: Self) !void {
            if (self.front == -1 or self.front > self.rear) {
                try stdout.print("Nothing to display\n", .{});
            } else {
                var i: isize = self.front;
                while (i <= self.rear) : (i += 1) {
                    print("{} ", .{self.items[@intCast(i)]});
                }
                print("\n", .{});
            }
        }
    };
}

pub fn main() !void {
    const allocator = std.heap.page_allocator;
    var q = try Queue(10).init(allocator);
    defer q.deinit();

    try q.enqueue(10);
    try q.enqueue(100);
    try q.enqueue(1000);
    try q.enqueue(1001);
    try q.enqueue(1002);
    _ = try q.dequeue();
    try q.enqueue(1003);
    _ = try q.dequeue();
    _ = try q.dequeue();
    try q.enqueue(1004);
    try q.display();
}
