const std = @import("std");

const Node = struct {
    value: isize,
    next: ?*Node,
};

fn printLinkedList(head: ?*Node) void {
    var current: ?*Node = head;
    while (current) |node| {
        std.debug.print("{}\n", .{node.value});
        current = node.next;
    }
    std.debug.print("\n", .{});
}

fn insertBeginning(allocator: std.mem.Allocator, head: ?*Node, data: isize) !?*Node {
    const newNode = try allocator.create(Node);
    newNode.* = Node{
        .value = data,
        .next = head,
    };
    return newNode;
}

fn insertEnd(allocator: std.mem.Allocator, head: ?*Node, data: isize) !?*Node {
    const newNode = try allocator.create(Node);
    newNode.value = data;
    newNode.next = null;
    if (head == null) return newNode;
    var current = head.?;
    while (current.next) |nextNode| {
        current = nextNode;
    }
    current.next = newNode;
    return head;
}

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    const node1 = try allocator.create(Node);
    defer {
        std.debug.print("Destroying node1\n", .{});
        allocator.destroy(node1);
    }
    const node2 = try allocator.create(Node);
    defer {
        std.debug.print("Destroying node2\n", .{});
        allocator.destroy(node2);
    }
    const node3 = try allocator.create(Node);
    defer {
        std.debug.print("Destroying node3\n", .{});
        allocator.destroy(node3);
    }

    node1.* = Node{ .value = 11, .next = node2 };
    node2.* = Node{ .value = 22, .next = node3 };
    node3.* = Node{ .value = 33, .next = null };

    try std.io.getStdOut().writeAll("Original list\n");
    printLinkedList(node1);

    const someNode = try insertBeginning(allocator, node1, 1);
    defer allocator.destroy(someNode.?);
    try std.io.getStdOut().writeAll("Added at the beginning of list\n");
    printLinkedList(someNode);

    const someOtherNode = try insertEnd(allocator, node1, 44);
    defer allocator.destroy(someOtherNode.?);
    try std.io.getStdOut().writeAll("Added at the end  of list\n");
    printLinkedList(someOtherNode);
}
