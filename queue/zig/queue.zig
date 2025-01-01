const std = @import("std");

pub fn Queue(comptime T: type) type {
    return struct {
        const Self = @This();

        items: []T,
        front: usize,
        rear: usize,
        allocator: std.mem.Allocator,

        pub fn init(allocator: std.mem.Allocator, capacity: usize) !Self {
            const items = try allocator.alloc(T, capacity);
            return Self{
                .items = items,
                .front = 0,
                .rear = 0,
                .allocator = allocator,
            };
        }

        pub fn deinit(self: *Self) void {
            self.allocator.free(self.items);
        }

        pub fn enqueue(self: *Self, item: T) !void {
            if (self.isFull()) {
                return error.QueueFull;
            }
            self.items[self.rear] = item;
            self.rear += 1;
        }

        pub fn dequeue(self: *Self) !T {
            if (self.isEmpty()) {
                return error.QueueEmprt;
            }
            const item = self.items[self.front];
            self.front += 1;
            return item;
        }

        pub fn isEmpty(self: Self) bool {
            return self.front == self.rear;
        }

        pub fn isFull(self: Self) bool {
            return self.rear == self.items.len;
        }
    };
}

test "queue operations" {
    const allocator = std.testing.allocator;
    var queue = try Queue(i32).init(allocator, 3);
    defer queue.deinit();

    try queue.enqueue(1);
    try queue.enqueue(2);

    const first = try queue.dequeue();
    try std.testing.expectEqual(first, 1);
}
