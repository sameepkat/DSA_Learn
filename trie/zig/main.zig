const std = @import("std");
const fmt = std.fmt;
const heap = std.heap;
const mem = std.mem;
const print = std.debug.print;
const time = std.time;

const Trie = @import("root.zig");

pub fn main() !void {
    var gpa = heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    const corpus = @embedFile("test.txt");

    var iter = mem.tokenizeScalar(u8, corpus, ' ');

    var trie = Trie.init(allocator);
    defer trie.deinit();

    try trie.insert("Lorem");
    try trie.insert("Ipsum");
    print("Lorem: {} | ", .{trie.lookup("Lorem")});
    print("Ipsum: {} | ", .{trie.lookup("Ipsum")});
    print("dor: {} | ", .{trie.lookup("dor")});

    const words: usize = 0;
    var found: usize = 0;

    var timer = try std.time.Timer.start();

    while (iter.next()) |word| {
        if (trie.lookup(word)) found += 1;
    }

    print(
        \\words: {}
        \\found: {}
        \\took: {}
        \\
    , .{
        words,
        found,
        fmt.fmtDuration(timer.lap()),
    });
}
