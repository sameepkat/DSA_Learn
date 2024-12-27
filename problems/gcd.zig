const std = @import("std");

fn GCD(a: u32, b: u32) u32{
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

pub fn main() !void{
    const a: u32 = 48;
    const b: u32 = 18;
    std.debug.print("GCD({}, {}) = {}\n", .{a,b,GCD(a,b)});
}
