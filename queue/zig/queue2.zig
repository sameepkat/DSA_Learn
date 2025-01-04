const std = @import("std");
const mem = std.mem;
const print = std.debug.print;
const stdout = std.io.getStdOut();

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

        pub fn deinit(self: Self) !void {
            try self.allocator.free(self.items);
        }

        pub fn enqueue(self: *Self, num: isize) !void {
            if (self.front == -1)
                self.front = 0;
            if (self.rear == @as(isize, SIZE) - 1) {
                try stdout.writeAll("Queue is full\n");
                return;
            }
            self.rear += 1;
            self.items[self.rear] = num;
        }

        pub fn dequeue(self: *Self) !isize {
            if (self.rear == -1) {
                try stdout.writeAll("Empty queue\n");
                return;
            } else {
                const item = self.items[self.front];
                for (self.items) |i| {
                    self.items[i] = self.items[i + 1];
                }
                self.rear -= 1;
                return item;
            }
        }

        pub fn display(self: Self) void {
            if (self.front == -1 or self.rear == -1 or self.front > self.rear) {
                try stdout.writeAll("Nothing to display\n");
            } else {
                for (self.front..self.rear) |i| {
                    std.debug.print("{} ", .{self.items[i]});
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
    _ = q.dequeue();
    try q.enqueue(1003);
    _ = q.dequeue();
    _ = q.dequeue();
    try q.enqueue(1004);

    q.display();
}
